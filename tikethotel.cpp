#include <iostream>
#include <iomanip>
using namespace std;

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
                //loginAdmin();
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