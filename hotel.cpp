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

void daftarHotel(){
    int pil;
    do {
        system("cls");
        cout << "Anda Ingin Melihat Kamar Berdasarkan Apa?\n";
        cout << "1. Berdasarkan Harga\n";
        cout << "2. Berdasarkan Bintang(rating)\n";
        cout << "3. Kembali\n";
        cout << "Pilih Menu : "; cin >> pil;
        switch (pil)
        {
        case 1:
            bacaKamardariFile();
            sortHarga();
            break;
        case 2:
            bacaKamardariFile();
            sortBintang();
            break;
        case 3: 
            loginUser();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            system("pause");
            break;
        }

    } while (pil !=3);
    
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

void sortBintang() {
    Kamar* arrayHotel[9999]; 
    int count = 0;
    Kamar* current = head;

    //Masukkan semua node ke array
    while (current != nullptr) {
        arrayHotel[count++] = current;
        current = current->next;
    }

    //Bubble sort berdasarkan bintang
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arrayHotel[j]->bintang < arrayHotel[j + 1]->bintang) {
                swap(arrayHotel[j], arrayHotel[j + 1]);
            }
        }
    }

    cout << "Data telah diurutkan berdasarkan Bintang Tertinggi:\n";
    cout << left << setw(81) << setfill ('=') << "" << endl;
    cout << left 
        << setw(5) << setfill(' ') << "| No"
        << setw(20) << setfill(' ') << "| Nama Kamar"
        << setw(20) << setfill(' ') << "| Rating"
        << setw(20) << setfill(' ') << "| Harga"
        << setw(15) << setfill(' ') << "| status" << "|" << endl;
    cout << left << setw(81) << setfill ('=') << "" << endl; 
    for (int i = 0; i < count; i++) {
        string status = (arrayHotel[i]->tersedia == true) ? "Tersedia" : "Terisi";
        cout << left
            << setw(2) << setfill(' ') << "|"
            << setw(3) << setfill(' ') << i+1 << "| "
            << setw(18) << setfill(' ') << arrayHotel[i]->nama << "| "
            << setw(18) << setfill(' ') << arrayHotel[i]->bintang << "| "
            << setw(18) << setfill(' ') << arrayHotel[i]->harga << "| "
            << setw(13) << setfill(' ') << status << "|" << endl;
    }
    cout << left << setw(81) << setfill ('=') << "" << endl; 

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
                bacaKamardariFile();
                cariHotel();
                system("pause");
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

void cariHotel(){
    int mpilih;
    do{
        system("cls");
        cout << setw(12) << setfill('-') << "" << endl;
        cout << "MENU PILIHAN" << endl;
        cout << setw(12) << setfill('-') << "" << endl;
        cout << "1. Berdasarkan Nama" << endl;
        cout << "2. Berdasarkan Tipe" << endl;
        cout << "3. Kembali" << endl;
        cout << "Pilih menu: "; cin >> mpilih;

        switch (mpilih) {
            case 1 : 
                berdasarnama();
                break;
            case 2 :
                berdasarkanTipe();
                break;
            case 3 :
                loginUser();
                break;
            default :
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                break;
        }
    } while(mpilih!=3);
}

void berdasarnama() {
    system("cls");
    string target;
    cout << "Masukkan nama hotel yang ingin dicari: ";
    cin.ignore();
    getline(cin, target);

    Kamar* current = head;
    bool found = false;

    while (current != nullptr) {
        if (target == current->nama) {
            string status = current->tersedia ? "Tersedia" : "Terisi";
            cout << "\nDaftar Kamar:\n";
            cout << left << setw(91) << setfill('=') << "" << endl;
            cout<< setw(20) << setfill(' ')<< "| Nama Kamar"
                << setw(15) << setfill(' ')<< "| Nomor Kamar"
                << setw(10) << setfill(' ')<< "| Rating"
                << setw(15) << setfill(' ')<< "| Tipe Kamar"
                << setw(15) << setfill(' ')<< "| Harga"
                << setw(15) << setfill(' ')<< "| Status" << "|" << endl;
            cout << left << setw(91) << setfill('=') << "" << endl;
                
                cout << left 
                << setw(2) << setfill (' ')<< "|"
                << setw(18) << setfill(' ') << current->nama << "| "
                << setw(13) << setfill(' ') << current->nomor << "| "
                << setw(8) << setfill(' ') << current->bintang << "| "
                << setw(13) << setfill(' ') << current->tipe << "| "
                << setw(13) << setfill(' ') << current->harga << "| "
                << setw(13) << setfill(' ') << status << "| " << endl;
            cout << left << setw(91) << setfill('=') << "" << endl;
            found = true;
            break; //Hentikan pencarian setelah ditemukan
        }
        current = current->next;
    }

    if (!found) {
        cout << "Kamar tidak ditemukan.\n";
    }

    system("pause");
}

void berdasarkanTipe() {
    system("cls");
    string target;
    cout << "Masukkan tipe kamar yang ingin dicari: ";
    cin.ignore();
    getline(cin, target);

    Kamar* current = head;
    bool found = false;

    cout << "\nDaftar Kamar:\n";
            cout << left << setw(91) << setfill('=') << "" << endl;
            cout<< setw(20) << setfill(' ')<< "| Nama Kamar"
                << setw(15) << setfill(' ')<< "| Nomor Kamar"
                << setw(10) << setfill(' ')<< "| Rating"
                << setw(15) << setfill(' ')<< "| Tipe Kamar"
                << setw(15) << setfill(' ')<< "| Harga"
                << setw(15) << setfill(' ')<< "| Status" << "|" << endl;
            cout << left << setw(91) << setfill('=') << "" << endl;
    while (current != nullptr) {
        if (target == current->tipe) {
            string status = current->tersedia ? "Tersedia" : "Terisi";
                cout << left 
                << setw(2) << setfill (' ')<< "|"
                << setw(18) << setfill(' ') << current->nama << "| "
                << setw(13) << setfill(' ') << current->nomor << "| "
                << setw(8) << setfill(' ') << current->bintang << "| "
                << setw(13) << setfill(' ') << current->tipe << "| "
                << setw(13) << setfill(' ') << current->harga << "| "
                << setw(13) << setfill(' ') << status << "| " << endl;
            
            found = true;
        }
        current = current->next;
    }
    cout << left << setw(91) << setfill('=') << "" << endl;

    if (!found) {
        cout << "Kota tidak ditemukan.\n";
    }

    system("pause");
}

void tambahHotel() {
    int jml;
    cout << "Input Data Kamar" << endl;
    cout << setw(15) << setfill('-') << "" << endl;

    cout << "Jumlah kamar yang ingin ditambahkan: ";
    cin >> jml;
    cin.ignore();

    for (int i = 0; i < jml; i++) {
        Kamar* baru = new Kamar;
        baru->next = nullptr;

        cout << "\nData ke-" << i + 1 << ":" << endl;
        cout << "Masukkan Nomor Kamar\t: ";
        cin >> baru->nomor;
        cin.ignore();
        cout << "Masukkan Nama Kamar\t: ";
        cin.getline(baru->nama, 50);
        cout << "Masukkan Rating Kamar\t: ";
        cin >> baru->bintang;
        cout << "Masukkan Tipe Kamar\t: ";
        cin >> baru->tipe;
        cout << "Masukkan Harga Kamar\t: ";
        cin >> baru->harga;
        baru->tersedia = true;
        cin.ignore();

        //Tambahkan ke linked list
        if (head == nullptr) {
            head = baru;
        } else {
            Kamar* bantu = head;
            while (bantu->next != nullptr) {
                bantu = bantu->next;
            }
            bantu->next = baru;
        }

        //Simpan ke file
        file = fopen("dataKamar.dat", "ab");
        if (file != NULL) {
            fwrite(baru, sizeof(Kamar),1, file);
            fclose(file);
        } else {
            cout << "Gagal menyimpan ke file!" << endl;
        }
    }

    cout << "\nData berhasil ditambahkan dan disimpan.\n";
}

void bacaKamardariFile() {

    bersihkanLinkedListKamar();
    file = fopen("dataKamar.dat", "rb");
    if (file == NULL) {
        cout << "File dataKamar.dat tidak ditemukan.\n";
        return;
    }

    Kamar temp;
    while (fread(&temp, sizeof(Kamar), 1, file)) {
        Kamar* baru = new Kamar;

        //Salin isi struct ke node baru
        strcpy(baru->nama, temp.nama);
        baru->nomor =  temp.nomor;
        strcpy(baru->tipe, temp.tipe);
        baru->bintang = temp.bintang;
        baru->harga = temp.harga;
        baru->tersedia = temp.tersedia;
        baru->next = nullptr;

        //Masukkan ke linked list
        if (head == nullptr) {
            head = baru;
        } else {
            Kamar* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = baru;
        }
    }

    fclose(file);
    cout << "Data hotel berhasil dibaca dari file ke linked list.\n";
}


void bersihkanLinkedListKamar() {
    Kamar* bantu = head;
    while (bantu != nullptr) {
        Kamar* hapus = bantu;
        bantu = bantu->next;
        head = head->next;
        delete hapus;
    }
    head = nullptr;
}

void hapusHotel(){
    if (head == nullptr) {
        cout << "Tidak ada data hotel untuk dihapus.\n";
        return;
    }
    char namaHapus[50];
    cin.ignore();  // Membersihkan buffer newline
    cout << "Masukkan nama hotel yang ingin dihapus: ";
    cin.getline(namaHapus, 50);

    // Kasus khusus: node pertama (head)
    if (strcmp(head->nama, namaHapus) == 0) {
        Kamar* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Kamar berhasil dihapus dari linked list (sebagai head).\n";
    } else {
        Kamar* current = head;
        bool found = false;
        while (current->next != nullptr) {
            if (strcmp(current->next->nama, namaHapus) == 0) {
                Kamar* hapus = current->next;
                current->next = hapus->next;
                delete hapus;
                cout << "Kamar berhasil dihapus dari linked list.\n";
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Kamar dengan nama tersebut tidak ditemukan.\n";
            return;
        }
    }
    // Perbarui isi file
    file = fopen("dataKamar.dat", "wb");
    if (file != NULL) {
        Kamar* temp = head;
        while (temp != nullptr) {
            fwrite(temp, sizeof(Kamar), 1, file);
            temp = temp->next;
        }
        fclose(file);
        cout << "File dataKamar.dat berhasil diperbarui.\n";
    } else {
        cout << "Gagal membuka file untuk update!\n";
    }
}

void tampilkanHotel() {
    Kamar* current = head;
    int no = 1;

    if (current == nullptr) {
        cout << "Tidak ada data hotel.\n";
        return;
    }

    cout << "\nDaftar Kamar:\n";
     cout << left << setw(96) << setfill('=') << "" << endl;
    cout << left << setw(5) << setfill(' ') << "| No"
         << setw(20) << setfill(' ')<< "| Nama Kamar"
         << setw(15) << setfill(' ')<< "| Nomor Kamar"
         << setw(10) << setfill(' ')<< "| Rating"
         << setw(15) << setfill(' ')<< "| Tipe Kamar"
         << setw(15) << setfill(' ')<< "| Harga"
         << setw(15) << setfill(' ')<< "| Status" << "|" << endl;
    cout << left << setw(96) << setfill('=') << "" << endl;
    while (current != nullptr) { 

        string status = current->tersedia ? "Tersedia" : "Terisi";
        
        cout << left 
        << setw(2) << setfill (' ')<< "|"
        << setw(3) << setfill(' ') << no++ << "| "
        << setw(18) << setfill(' ') << current->nama << "| "
        << setw(13) << setfill(' ') << current->nomor << "| "
        << setw(8) << setfill(' ') << current->bintang << "| "
        << setw(13) << setfill(' ') << current->tipe << "| "
        << setw(13) << setfill(' ') << current->harga << "| "
        << setw(13) << setfill(' ') << status << "| " << endl;
        current = current->next;
    }
    cout << left << setw(96) << setfill('=') << "" << endl;
}

void bacaPelanggandariFile() {
    bersihkanLinkedListPelanggan();
    file = fopen("dataPelanggan.dat", "rb");
    if (file == NULL) {
        cout << "File dataPelanggan.dat tidak ditemukan.\n";
        return;
    }

    pelanggan temp;
    while (fread(&temp, sizeof(pelanggan), 1, file)) {
        pelanggan* baru = new pelanggan;

        //Salin isi struct ke node baru
        strcpy(baru->nama, temp.nama);
        strcpy(baru->noTelp, temp.noTelp);
        strcpy(baru->gmail, temp.gmail);
        strcpy(baru->alamat, temp.alamat);
        strcpy(baru->namakamar, temp.namakamar);
        baru->next = nullptr;

        //Masukkan ke linked list
        if (kepala == nullptr) {
            kepala = baru;
        } else {
            pelanggan* current = kepala;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = baru;
        }
    }

    fclose(file);
    cout << "Data hotel berhasil dibaca dari file ke linked list.\n";
}

void bersihkanLinkedListPelanggan(){
    pelanggan* bantu = kepala;
    while (bantu != nullptr) {
        pelanggan* hapus = bantu;
        bantu = bantu->next;
        kepala = kepala->next;
        delete hapus;
    }
    kepala = nullptr;
}

void editKamar() {
    if (head == nullptr) {
        cout << "Tidak ada data hotel untuk diedit.\n";
        return;
    }

    char namaEdit[50];
    cin.ignore();  // Bersihkan buffer newline
    cout << "Masukkan nama kamar yang ingin diedit: ";
    cin.getline(namaEdit, 50);

    Kamar* current = head;
    while (current != nullptr) {
        if (strcmp(current->nama, namaEdit) == 0) {
            cout << "Data ditemukan. Masukkan data baru:\n";
            
            cout << "Nama Kamar Baru\t\t: ";
            cin.getline(current->nama, 50);
            
            cout << "Nomor Kamar Baru\t: ";
            cin >> current->nomor;
            cin.ignore();

            cout << "Jenis Kamar Baru\t: ";
            cin.getline(current->tipe, 50);

            cout << "Harga Baru\t\t: ";
            cin >> current->harga;

            cout << "Jumlah Bintang Baru\t: ";
            cin >> current->bintang;

            // Simpan ulang semua data ke file
            FILE* file = fopen("dataKamar.dat", "wb");
            Kamar* temp = head;
            while (temp != nullptr) {
                fwrite(temp, sizeof(Kamar), 1, file);
                temp = temp->next;
            }
            fclose(file);

            cout << "Data kamar berhasil diedit.\n";
            return;
        }
        current = current->next;
    }

    cout << "Data kamar tidak ditemukan.\n";
}


void pesanKamar() {
    int i = 0;
    char pesanLagi;
    string pesan;
    do
    {
        cin.ignore();
    cout << "Selamat datang di Menu Pemesanan Kamar" << endl;
    cout << setw(38) << setfill('-') << endl;
    cout << "Masukkan Nama Kamar yang ingin dipesan :"; getline(cin, pesan);
    Kamar* current = head;
    bool found = false;
    while (current != nullptr) {
        if (pesan == current->nama) {
            found = true;
            if (!current->tersedia) {
                    cout << "Maaf, kamar sudah terisi.\n";
                    break;
                }

            string status = current->tersedia ? "Tersedia" : "Terisi";
            cout << "\nDeskripsi Kamar:\n";
            cout << left << setw(91) << setfill('=') << "" << endl;
            cout<< setw(20) << setfill(' ')<< "| Nama Kamar"
                << setw(15) << setfill(' ')<< "| Nomor Kamar"
                << setw(10) << setfill(' ')<< "| Rating"
                << setw(15) << setfill(' ')<< "| Tipe Kamar"
                << setw(15) << setfill(' ')<< "| Harga"
                << setw(15) << setfill(' ')<< "| Status" << "|" << endl;
            cout << left << setw(91) << setfill('=') << "" << endl;
                
                cout << left 
                << setw(2) << setfill (' ')<< "|"
                << setw(18) << setfill(' ') << current->nama << "| "
                << setw(13) << setfill(' ') << current->nomor << "| "
                << setw(8) << setfill(' ') << current->bintang << "| "
                << setw(13) << setfill(' ') << current->tipe << "| "
                << setw(13) << setfill(' ') << current->harga << "| "
                << setw(13) << setfill(' ') << status << "| " << endl;
            cout << left << setw(91) << setfill('=') << "" << endl;

            string lanjut;
            cout << "Apakah anda ingin melanjutkan pemesanan (y/n) : "; cin >> lanjut;
            if (lanjut == "Y" || lanjut == "y")
            {
                current->tersedia = false;
                FILE* file = fopen("dataKamar.dat", "wb");
                if (file != NULL) {
                    Kamar* current = head;
                    while (current != nullptr) {
                        fwrite(current, sizeof(Kamar), 1, file);
                        current = current->next;
                    }
                    fclose(file);
                } else {
                    cout << "Gagal menyimpan data kamar ke file.\n";
                }
                pelanggan* baru = new pelanggan();
                baru->next = nullptr;
                cin.ignore();
                cout << "Masukkan Nama Anda\t: "; cin.getline(baru->nama, 100);
                cout << "Masukkan No. Telepon Anda\t: "; cin.getline(baru->noTelp, 100);
                cout << "Masukkan Email Anda\t: "; cin.getline(baru->gmail, 100);
                cout << "Masukkan Alamat Anda\t: "; cin.getline(baru->alamat, 100);
                strcpy(baru->namakamar, current->nama);
                if (kepala == nullptr)
                {
                    kepala = baru;
                }else{
                    pelanggan* bantu = kepala;
                    while (bantu->next != nullptr)
                    {
                        bantu = bantu->next;
                    }
                    bantu->next = baru;
                }
                
                file = fopen("dataPelanggan.dat", "ab");
                if (file != NULL)
                {
                    fwrite(baru, sizeof(pelanggan), 1, file);
                    fclose(file);
                }else{
                    cout << "gagal" << endl;
                }
                cout<< "berhasil" << endl;
            }
            
            
            break; //Hentikan pencarian setelah ditemukan
        }
        current = current->next;
    }
    if (!found) {
        cout << "Kamar tidak ditemukan.\n";
        break;
    }
    
    cout << "Ingin pesan lagi?(y/n)"; cin >> pesanLagi;
    } while (pesanLagi == 'Y' || pesanLagi == 'y');
}

void ubahStatusKamar(){
    if (head == nullptr) {
        cout << "Tidak ada data hotel untuk diedit.\n";
        return;
    }
    char namaUpdate[50];
    cin.ignore();  // Bersihkan buffer newline
    cout << "Masukkan nama kamar yang ingin diupdate: ";
    cin.getline(namaUpdate, 50);

    Kamar* current = head;
    while (current != nullptr) {
        if (strcmp(current->nama, namaUpdate) == 0) {
            cout << "Data ditemukan. Masukkan Status baru:\n";
            string updateStatus;
            while (updateStatus != "Y" && updateStatus != "y" &&
            updateStatus != "N" && updateStatus != "n")
            {
                cout << "Apakah Kamar tersebut tersedia (y/n) : ";
                cin >> updateStatus;
                if (updateStatus == "Y" || updateStatus == "y")
                {
                    current->tersedia = true;
                }else if(updateStatus == "N" || updateStatus == "n"){
                    current->tersedia = false;
                }else {
                    cout << "pilihan tidak valid\n";
                    system("pause");
                }
            }
            
            
            // Simpan ulang semua data ke file
            FILE* file = fopen("dataKamar.dat", "wb");
            Kamar* temp = head;
            while (temp != nullptr) {
                fwrite(temp, sizeof(Kamar), 1, file);
                temp = temp->next;
            }
            fclose(file);

            cout << "Data kamar berhasil diedit.\n";
            system("pause");
            return;
        }
        current = current->next;
    }

    cout << "Data kamar tidak ditemukan.\n";
}

void tampilkanPelanggan() {
    pelanggan* bantu = kepala;
    int no = 1;

    if (bantu == nullptr) {
        cout << "Tidak ada data Pelanggan.\n";
        return;
    }

    cout << "\nDaftar Pelanggan:\n";
     cout << left << setw(96) << setfill('=') << "" << endl;
    cout << left << setw(5) << setfill(' ') << "| No"
         << setw(20) << setfill(' ')<< "| Nama"
         << setw(15) << setfill(' ')<< "| Nomor Telp"
         << setw(10) << setfill(' ')<< "| Email"
         << setw(15) << setfill(' ')<< "| Alamat"
         << setw(30) << setfill(' ')<< "| Nama Kamar yang dipesan" << "|" << endl;
    cout << left << setw(96) << setfill('=') << "" << endl;
    while (bantu != nullptr) { 
        cout << left 
        << setw(2) << setfill (' ')<< "|"
        << setw(3) << setfill(' ') << no++ << "| "
        << setw(18) << setfill(' ') << bantu->nama << "| "
        << setw(13) << setfill(' ') << bantu->noTelp << "| "
        << setw(8) << setfill(' ') << bantu->gmail << "| "
        << setw(13) << setfill(' ') << bantu->alamat << "| "
        << setw(28) << setfill(' ') << bantu->namakamar << "| " << endl;
        bantu = bantu->next;
    }
    cout << left << setw(96) << setfill('=') << "" << endl;
}
