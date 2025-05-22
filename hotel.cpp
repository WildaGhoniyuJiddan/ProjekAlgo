#include <iostream>
#include <iomanip>
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

void menuLogin();
void loginAdmin();
void loginUser();
void daftarHotel();
void cariHotel();
void pesanKamar();

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
void loginUser() {
    int menu;
    do {
        system("cls");
        cout << "MENU PILIHAN" << endl;
        cout << setw(12) << setfill('-') << "" << endl;
        cout << "1. Lihat Dafar Hotel" << endl;
        cout << "2. Cari Hotel" << endl;
        cout << "3. Pemesanan Kamar" << endl;
        cout << "4. Kembali" << endl;
        cout << "Pilih menu: "; cin >> menu;

        switch (menu) {
            case 1 : 
                //daftarHotel();
                system("pause");
                break;
                
            case 2 :
                //cariHotel();
                system("pause");
                break;
            case 3 :
                //pesanKamar();
                system("pause");
                break;
            case 4:
                menuLogin();
                exit(0);
                break;
            default :
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                break;
        }
    } while(menu!=4);
}

void loginAdmin(){
    int menu;
    do {
        system("cls");
        cout << "MENU PILIHAN" << endl;
        cout << setw(12) << setfill('-') << "" << endl;
        cout << "1. Tambah Hotel" << endl;
        cout << "2. Hapus Hotel" << endl;
        cout << "3. Edit Hotel" << endl;
        cout << "4. Kembali" << endl;
        cout << "Pilih menu: "; cin >> menu;

        switch (menu) {
            case 1 : 
                //tambahHotel();
                system("pause");
                break;
                
            case 2 :
                //hapusHotel();
                system("pause");
                break;
            case 3 :
                //editHotel();
                system("pause");
                break;
            case 4:
                break;
            default :
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                break;
        }
    } while(menu!=4);
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
