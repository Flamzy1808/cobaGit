#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main(){
	string usm, buah[50], cari, nama, buahBeli, buahIngin, tambahBuah;
	int pass, pilih, list = 10, tambah, jmlHuruf = 0, jmlKata = 0, tambahHarga;
	bool login = true, menutama = true, cariBuah = true, jualBuah = true, kata = false, cekBuahBeli = true, cekBayar = true, cekKembali = true, cekTambahBuah = true, cekBuahIngin = true;
    char kembali, buahLain;
    float harga[50], jumlahBuah = 0, total = 0, akhir = 0, diskon = 0, bayar, uangKurang = 0;

    buah[0] = "Apel";
    buah[1] = "Jeruk";
    buah[2] = "Anggur";
    buah[3] = "Durian";
    buah[4] = "Alpukat";
    buah[5] = "Nanas";
    buah[6] = "Nangka";
    buah[7] = "Melon";
    buah[8] = "Semangka";
    buah[9] = "Manggis";

    harga[0] = 35000;
    harga[1] = 28000;
    harga[2] = 62000;
    harga[3] = 83000;
    harga[4] = 35000;
    harga[5] = 27000;
    harga[6] = 25000;
    harga[7] = 28000;
    harga[8] = 55000;
    harga[9] = 73000;

	while(login == true){
		cout << "===== LOGIN SISTEM TOKO BUAH MAKMUR =====" << endl;
		cout << "Username : "; cin >> usm;
		cout << "Password : "; cin >> pass;
		if(usm == "tokobuah" && pass == 113)
			login = false;
		else
			cout << "Login gagal! Silahkan coba lagi." << endl << endl;
	}
	
    while (menutama == true){
	cout << setfill('=') << setw(50) << "=" << endl;
	cout << "Selamat Datang di Sistem Manajemen Toko Buah Makmur" << endl;
	cout << setfill('=') << setw(50) << "=" << endl;
	cout << "Hello World" << endl;
	cout << "Menu" << endl <<
	"1. List Buah" << endl <<
	"2. Tambah Buah" << endl <<
	"3. Cari Buah" << endl <<
	"4. Jual Buah" << endl <<
	"5. Keluar" << endl <<
	"Pilih menu : "; cin >> pilih;
	
	switch (pilih) {
		case 1 : {
			cout << setfill('=') << setw(35) << "=" << endl;
			cout << left << setfill(' ') << setw(13) << "|" << setw(21) << "List Buah" << "|" << endl;
			cout << setfill('=') << setw(35) << "=" << endl;
			cout << "| " << setfill(' ') << setw(8) << "No" << setw(13) << "Nama Buah" << setw(11) << "Harga/kg" << "|" << endl;
			cout << setfill('-') << setw(35) << "-" << endl;
            for(int i=0; i < list; i++){
                cout << "| " << setfill(' ') << setw(8) << i + 1 << setw(13) << buah[i] << "Rp. " << setw(7) << harga[i] << "|" << endl;
            }
            cout << setfill('=') << setw(35) << "=" << endl << endl;
            break;
        }
        case 2 : {
            cout << "Mau menambahkan berapa buah? : "; cin >> tambah;
            for(int j=0; j<tambah; j++){
            do{
                cout << "Nama buah ke-" << j + 1 << ": "; cin >> tambahBuah;
                for(int n=0; n < list; n++){
                if(tambahBuah == buah[n]){ //untuk cek buah yang ingin ditambahkan apakah duplikat atau tidak
                    cout << "Buah sudah ada didalam list, silahkan masukkan  buah lain" << endl;
                    cekTambahBuah = true;
                    break;
                }else
                    cekTambahBuah = false;
            }
            if (cekTambahBuah == false){
                cout << "Harga/kg      : "; cin >> tambahHarga;
            }
            }while(cekTambahBuah == true);
            buah[list] = tambahBuah;
            harga[list] = tambahHarga;
            list++;
            }
            cout << "Data buah berhasil ditambahkan!" << endl << endl;
			break;
        }
        case 3 : {
            cout << "Masukkan nama buah yang dicari: "; cin >> cari;
            for(int k=0; k<list; k++){
                if(buah[k] == cari){
                    cout << "Nama buah : " << buah[k] << endl;
                    cout << "Harga/kg  : Rp " << harga[k] << endl;
                    cariBuah = true;
                    break;
                }else 
                    cariBuah = false;
            }
            if (cariBuah == false) {
                    cout << "Buah tidak ditemukan!" << endl;
                }
            break;
        }
        case 4 : {
            cout << "Masukkan nama lengkap pembeli : "; cin.ignore(); getline(cin, nama);
            while(jualBuah == true){
            cout << "Nama buah yang dibeli         : "; cin >> buahBeli;
            cout << "Jumlah (Kg)                   : "; cin >> jumlahBuah;
            for(int l=0; l < list; l++){
                if(buah[l] == buahBeli){ 
                    total += harga[l] * jumlahBuah;
                    cekBuahBeli = true; //cek buah yang akan dibeli
                    break;
                }else 
                    cekBuahBeli = false;
            }if (cekBuahBeli == false){
                cout << "Buah tidak ditemukan" << endl;
            }
            do{
            cout << "Tambah beli buah lain? (y/n)  : "; cin >> buahLain;
            if (buahLain != 'y' && buahLain != 'n'){ //cek input
                cout << "Input tidak valid!" << endl;
                cekBuahBeli = true;
            }else {
                cekBuahBeli = false;
            }
            }while(cekBuahBeli == true);
                if(buahLain == 'n'){
                    jualBuah = false;
                }
            }
            if(total > 150000 && total <= 450000){
                diskon = total * 0.17;
                cout << "Selamat!! Anda mendapat diskon" << endl;
                cout << "Diskon yang anda dapat sebesar Rp. " << diskon << endl;
            }else if(total > 450000){
                diskon = total * 0.17;
                cout << "Selamat!! Anda mendapatkan diskon dan memperoleh 5 buah pilihan gratis" << endl;
                cout << "Diskon yang anda peroleh sebesar Rp. " << diskon << endl;
                do{
                cout << "Silahkan pilih buah yang diinginkan : "; cin >> buahIngin;
                for(int m=0; m < list; m++){ //cek buah yang diinginkan
                    if(buahIngin == buah[m]){
                        cekBuahIngin = false;
                        break;
                    }else {
                        cekBuahIngin = true;
                    }
                }if(cekBuahIngin == true)
                    cout << "Buah yang diinginkan tidak tersedia, silahkan input buah lain " << endl;
                }while(cekBuahIngin == true);
            }
		    cout << setfill('=') << setw(50) << "=" << endl;
	    	cout << left << setfill(' ') << setw(18) << "|" << setw(31) << "Resi Beli Buah" << "|" << endl;
	    	cout << setfill('=') << setw(50) << "=" << endl;
            cout << "Nama pembeli  : " << nama << endl;
            cout << "Total belanja : " << total << endl;
            akhir = total - diskon;
            cout << "Total bayar   : " << akhir << endl;
            if(total > 450000)
               cout << "Bonus         : " << buahIngin << endl;
            cout << "Analisis nama pembeli : " << endl;
            for (char c : nama){
                if(isalpha(c)){
                    jmlHuruf++;
                }
                if(isspace(c)){
                    kata = false;
                }else if(!kata){
                    kata = true;
                    jmlKata++;
                }
            }
            cout << "Jumlah Huruf  : " << jmlHuruf << endl;
            cout << "Jumlah Kata   : " << jmlKata << endl;
		    cout << setfill('-') << setw(50) << "-" << endl << endl;
            while(cekBayar == true){
            cout << "Masukkan uang dibayarkan : Rp."; cin >> bayar;
            if (akhir > bayar){
                uangKurang = bayar - akhir;
                cout << "Mohon maaf uang anda kurang, mohon input kembali" << endl;
                cout << "Uang anda kurang : Rp." << uangKurang << endl << endl;
                akhir -= bayar;
            }else{
                cekBayar = false;
                break;
            }
            }
            if (cekBayar == false){
                cout << "Kembalian : Rp." << bayar - akhir;
            }
            return 0;
        }
        case 5 : {
            cout << endl << "Sampai jumpa kembali...";
            return 0;
        }
        default : {
            cout << endl << "Menu tidak valid! " << endl;
        }
	    }
        do{
        cout << "Kembali ke menu utama? (y/n) : "; cin >> kembali;
        if (kembali != 'y' && kembali != 'n'){ //cek input
            cout << "Input tidak valid!" << endl;
            cekKembali = true;
        }else 
            cekKembali = false;
        }while (cekKembali == true);
        if (kembali == 'n')
            menutama = false;
        }

return 0;
}
