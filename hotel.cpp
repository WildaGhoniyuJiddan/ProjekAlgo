#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Kamar{
    char nama[50];
    int nomor;
    char tipe[50];
    float bintang;
    int harga;
    bool tersedia;
    Kamar* next;
};

struct pelanggan{
    char nama[100];
    char noTelp[100];
    char gmail[100];
    char alamat[100];
    char namakamar[100];
    pelanggan* next;
};

Kamar* head=NULL;
pelanggan* kepala = nullptr;

FILE *file;

void menuLogin();
void loginAdmin();
void loginUser();
void daftarHotel();
void cariHotel();
void berdasarnama();
void berdasarkanTipe();
void pesanKamar();
void tambahHotel();
void hapusHotel();
void editHotel();
void bacaKamardariFile();
void tampilkanHotel();
void bersihkanLinkedListKamar();
void sortHarga();
void sortBintang();
void editKamar();
void ubahStatusKamar();
void tampilkanHotelyangTerisi();
void bacaPelanggandariFile();
void bersihkanLinkedListPelanggan();
void tampilkanPelanggan();
void checkoutKamar();


int main() {
    menuLogin();
    return 0;
}

void menuLogin() {
    int pilih;

    do {
        system("cls");
        cout << "Pilih menu login" << endl;
        cout << setw(16) << setfill('-') << "" << endl;
        cout << "1. Login sebagai admin" << endl;
        cout << "2. Login sebagai pelanggan" << endl;
        cout << "3. Batal" << endl;
        cout << "Pilih menu: "; cin >> pilih;

        switch (pilih) {
            case 1 : 
                loginAdmin();
                system("pause");
                break;
                
            case 2 :
                loginUser();
                system("pause");
                break;
            case 3 :
                exit(0);
                break;
            default :
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                break;
        }
    } while(pilih!=3);
}

void sortHarga() {
    Kamar* arrayHotel[9999]; 
    int count = 0;
    Kamar* current = head;

    while (current != nullptr) {
    arrayHotel[count++] = current;
    current = current->next;
    }

for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count - i - 1; j++) {
        if (arrayHotel[j]->harga > arrayHotel[j + 1]->harga){
            swap(arrayHotel[j], arrayHotel[j + 1]); //tukar pointer
        }
    }
}

cout << "Data telah diurutkan berdasarkan Harga Termurah:\n";
    cout << left << setw(56) << setfill ('=') << "" << endl;
    cout << left 
        << setw(5) << setfill(' ') << "| No"
        << setw(20) << setfill(' ') << "| Nama Kamar"
        << setw(15) << setfill(' ') << "| Harga"
        << setw(15) << setfill(' ') << "| Status" << "|" << endl;
    cout << left << setw(56) << setfill ('=') << "" << endl;    
for (int i = 0; i < count; i++) {
    string status = (arrayHotel[i]->tersedia == true) ? "Tersedia" : "Terisi";
    cout << left
            << setw(2) << setfill(' ') << "|"
            << setw(3) << setfill(' ') << i+1 << "| "
            << setw(18) << setfill(' ') << arrayHotel[i]->nama << "| "
            << setw(13) << setfill(' ') << arrayHotel[i]->harga << "| "
            << setw(13) << setfill(' ') << status << "|" << endl;
    }
    cout << left << setw(56) << setfill ('=') << "" << endl; 
    system("pause");
}

void loginAdmin(){
    system("cls");
    int menu;
    string username, password;
    cout << "Login Sebagai Admin" << endl;
    cout << "Masukkan Username : "; cin >> username;
    cout << "Masukkan Password : "; cin >> password;
    if (username == "admin" && password == "admin123")
    {
        do {
        system("cls");
        cout << setw(12) << setfill('-') << "" << endl;
        cout << "MENU PILIHAN" << endl;
        cout << setw(12) << setfill('-') << "" << endl;
        cout << "1. Tambah Kamar" << endl;
        cout << "2. Hapus Kamar" << endl;
        cout << "3. Edit Kamar" << endl;
        cout << "4. Lihat Data Kamar" << endl;
        cout << "5. Lihat Data Kamar yang terisi" << endl;
        cout << "6. Lihat Data Pelanggan" << endl;
        cout << "7. Ubah Status Kamar" << endl;
        cout << "8. Kembali" << endl;
        cout << "Pilih menu: "; cin >> menu;

        switch (menu) {
            case 1 : 
                tambahHotel();
                system("pause");
                break;
                
            case 2 :
                bacaKamardariFile();
                hapusHotel();
                system("pause");
                break;
            case 3:
                bacaKamardariFile();
                editKamar();
                break;
            case 4 :
                bacaKamardariFile();
                tampilkanHotel();
                system("pause");
                break;
            case 5:
                bacaKamardariFile();
                bacaPelanggandariFile();
                tampilkanHotelyangTerisi();
                system("pause");
                break;
            case 6:
                bacaPelanggandariFile();
                tampilkanPelanggan();
                system("pause");
                break;
            case 7:
                bacaKamardariFile();
                ubahStatusKamar();
                break;
            case 8:
                menuLogin();
                break;
            default :
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                break;
        }
        } while(menu!=8);
    }else {
        cout << "Login gagal, Username atau Password salah" << endl;
        system("pause");
        menuLogin();
    }
}

void loginUser() {
    int menu;
    do {
        system("cls");
        cout << setw(12) << setfill('-') << "" << endl;
        cout << "MENU PILIHAN" << endl;
        cout << setw(12) << setfill('-') << "" << endl;
        cout << "1. Lihat Daftar Kamar" << endl;
        cout << "2. Cari Kamar" << endl;
        cout << "3. Pesan Langsung" << endl;
        cout << "4. Checkout kamar" << endl;
        cout << "5. Kembali" << endl;
        cout << "Pilih menu: "; cin >> menu;

        switch (menu) {
            case 1 : 
                //bacaKamardariFile();
                //daftarHotel();
                // system("pause");
                break;
                
            case 2 :
                //bacaKamardariFile();
                //cariHotel();
                //system("pause");
                break;
            case 3:
                //bacaKamardariFile();
                //pesanKamar();
                break;
            case 4:
                //bacaKamardariFile();
                //bacaPelanggandariFile();
                //checkoutKamar();
                break;
            case 5:
                menuLogin();
                break;
            default :
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                break;
        }
    } while(menu!=5);
}