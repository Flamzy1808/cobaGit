#include <iostream>
#include <iomanip>
using namespace std;

void listDriver();
void buatPesanan();
void selesaiPesanan();
float rataRataRating(float rating[], int n);

bool sudahInput = false;
string namaDriver[7]={"Rizky Salim", "Nisa Putri", "Fajar Pratama", "Dhea Maharani", "Aldi Nugroho", "Sinta Ramadhani", "Yoga Handoko" };
string platNomor[7]={"AB 5678 ZQ", "AB 9012 ZX", "AB 1124 AA", "AB 6712 BK", "AB 7890 OP", "AB 2345 QR", "AB 1095 HG"};
float rating[7]={0, 0, 0, 0, 0, 0, 0}, inputRating[7], semuaRating[50];
int idPesanan[50], jarak[50], noDriver[50], tarif[50], totalBayar[50], slsIdPesanan, poin = 0;
string namaCus[50], lokJem[50], lokTuj[50];

int main(){
    bool pesanan = true;
    int pilihMenu;
    do{
    cout << setfill('=') << setw(50) << "=" << endl;
    cout << left << setfill(' ') << setw(13) << "|" << setw(36) << "SELAMAT DATANG DI NGABRIDE" << "|" << endl;
    cout << setfill('=') << setw(50) << "=" << endl;
    cout << endl << "MENU NGABRIDE" << endl << endl <<
    "1. List Driver" << endl << "2. Buat Pesanan" << endl << "3. Selesaikan Pesanan" << endl << "4. Keluar" << endl;
    cout << "pilih menu : ";cin >> pilihMenu;

    switch (pilihMenu){
        case 1 : {
            listDriver();
            break;
        }
        case 2 : {
            buatPesanan();
            break;
        }
        case 3 : {
            selesaiPesanan();
            break;
        }
        case 4 : {
            return 0;
        }
        default : {
            cout << "Input tidak valid! Silahkan masukkan pilihan dengan benar" << endl << endl;
            break;
        }
    }
    }while(pesanan == true);
return 0;
}

void listDriver(){
    cout << setfill('=') << setw(50) << "=" << endl;
    cout << left << setfill(' ') << setw(13) << "|" << setw(36) << "List Driver Ngabride" << "|" << endl;
    cout << setfill('=') << setw(50) << "=" << endl;
    cout << setfill(' ') << setw(7) << "No" << setw(19) << "Nama Driver" << setw(17) << "Plat Nomor" << "Rating" << endl;
    cout << setfill('-') << setw(50) << "-" << endl;
    for(int i=0; i < 7; i++){
       cout << setfill(' ') << setw(7) << i + 1 << setw(19) << namaDriver[i] << setw(19) << platNomor[i] << rating[i] << endl;
    }
    cout << setfill('=') << setw(50) << "=" << endl;
}

void buatPesanan(){
    bool inputDriver = false;
    cout << "=============== BUAT PESANAN ===============" << endl;
    cout << "Masukkan ID Pesanan     : "; cin >> idPesanan[poin]; cin.ignore();
    cout << "Nama Customer           : "; getline(cin,namaCus[poin]);
    cout << "Lokasi Jemput           : "; getline(cin,lokJem[poin]);
    cout << "Lokasi Tujuan           : "; getline(cin, lokTuj[poin]);
    cout << "Jarak(Km)               : "; cin >> jarak[poin];
    do{
        cout << "Nomor Urut Driver (1-7) : "; cin >> noDriver[poin];
        if(noDriver[poin]>=1 && noDriver[poin]<=7){
            inputDriver = true;
        }else{
            cout << "Nomor driver tidak tersedia! Silahkan input ulang" << endl;
            inputDriver = false;
        }
    }while(inputDriver == false);
    cout << endl << "Pesanan Berhasil Dibuat!" << endl;
    cout << "Driver                 : " << namaDriver[noDriver[poin]-1] << endl;
    tarif[poin] = jarak[poin] * 9000;
    totalBayar[poin] = tarif[poin] * 0.12 + tarif[poin];
    cout << "Tarif (termasuk pajak) : " << totalBayar[poin] << endl << endl;
    poin++;
    sudahInput = true;
}

void selesaiPesanan(){
    bool cekPesanan = false;
    int bayar;
    if(sudahInput == false){
        cout << "Belum ada pesanan yang dibuat!" << endl << "Silahkan buat pesanan terlebih dahulu di menu 2" << endl << endl;
    }else{
        cout << "===== SELESAIKAN PESANAN =====" << endl;
        cout << "Masukkan ID Pesanan : "; cin >> slsIdPesanan;
        for(int i=0; i<poin; i++){
            if(slsIdPesanan == idPesanan[i]){
                cout << "=============== DETAIL PESANAN ===============" << endl;
                cout << "Nama Customer       : " << namaCus[i] << endl;
                cout << "Driver              : " << namaDriver[noDriver[i]-1] << endl;
                cout << "Tarif sebelum pajak : " << tarif[i] << endl;
                cout << "Tarif setelah pajak : " << totalBayar[i] << endl << endl;
                do{
                    cout << "Masukkan rating untuk driver (1-5) : "; cin >> inputRating[i];
                    if(inputRating[i] > 5 || inputRating[i] < 1){
                        cout << "Rating yang diinput harus diantara 1 - 5" << endl;
                    }
                }while(inputRating[i] > 5 || inputRating[i] < 1);
                int jumlah = 0;
                for(int j = 0; j<=i; j++){
                    if(noDriver[j] == noDriver[i]){
                        semuaRating[jumlah] = inputRating[j];
                        jumlah++;
                    }
                }
                rating[noDriver[i]-1] = rataRataRating(semuaRating, jumlah);
                do{
                    cout << "Masukkan jumlah yang dibayar : Rp."; cin >> bayar;
                    if(bayar < totalBayar[i]){
                        cout << "Uang anda kurang! Silahkan bayar sesuai total pesanan" << endl << endl;
                    }else{
                        cout << "Kembalian : Rp." << bayar - totalBayar[i] << endl << endl;
                    }
                }while(bayar < totalBayar[i]);
                cekPesanan = true;
                break;
            }else{
                cekPesanan = false;
            }
        }if(cekPesanan == false){
            cout << "ID pesanan tidak tersedia!" << endl << endl;
        }
    }
}

float rataRataRating(float rating[], int n){
    if(n==1){
        return rating[0];
    }else{
        return ((n-1) * rataRataRating(rating, n-1) + rating[n-1]) / n;
    }
}
