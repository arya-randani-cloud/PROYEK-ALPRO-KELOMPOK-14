#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

using namespace std;

// ==========================================
//              STRUKTUR DATA
// ==========================================
struct Produk {
    int id;
    string nama;
    string kategori;
    double harga;
    int stok;
};

struct Toko {
    int idToko;
    string namaToko;
    string kategoriDijual; 
    double ratingToko;
    int jumlahUlasan;
    vector<Produk> daftarProduk;
};

struct KeranjangItem {
    string dariToko;
    Produk produk;
    int jumlah;
};

struct User {
    string username;
    string password;
    string alamat;
    bool isAdmin;
};

// ==========================================
//         DATABASE SIMULASI GLOBAL
// ==========================================
vector<User> databaseUser;
vector<Toko> daftarTokoMarketplace;
vector<KeranjangItem> keranjangBelanja;

User userLogin; 
bool isLoggedIn = false;
bool sudahRegistrasi = false; 

// ==========================================
//            PROTOTIPE FUNGSI
// ==========================================
void inisialisasiMarketplace();
void bersihkanLayar();
void tungguEnter();
void cetakGaris(int panjang, char simbol);

void menuAutentikasi();
void registrasiAkun();
void loginAkun();

void menuUtama();
void tampilkanKatalogToko();
void cariProduk();
void tambahKeKeranjang();
void lihatKeranjangDanCheckout();
void berikanUlasanToko();

void menuManajemenTokoAdmin();
void hitungTotalAset();
void tambahTokoBaru();
void hapusToko();
void tambahProdukKeToko();
void updateStokMasuk();
void updateStokKeluar();
void hapusProduk();

// ==========================================
//               MAIN FUNCTION
// ==========================================
int main() {
    inisialisasiMarketplace();
    while (true) {
        if (!isLoggedIn) menuAutentikasi();
        else menuUtama();
    }
    return 0;
}

// ==========================================
//          SISTEM UTILITY & TAMPILAN
// ==========================================
void bersihkanLayar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void tungguEnter() {
    cout << "\nTekan [ENTER] untuk melanjutkan...";
    cin.ignore(1000, '\n');
    cin.get();
}

void cetakGaris(int panjang, char simbol) {
    for (int i = 0; i < panjang; i++) cout << simbol;
    cout << endl;
}

void inisialisasiMarketplace() {
    databaseUser.push_back({"admin", "admin123", "Kantor Pusat", true});
    databaseUser.push_back({"budi", "budi123", "Jl. Merdeka No. 45", false});
    sudahRegistrasi = true;

    Toko uniqlo = {101, "uniqlo", "pakaian", 4.8, 10, {
        {101, "celana jeans", "pakaian", 120000, 40},
        {106, "Kemeja Polos", "pakaian", 125000, 50}
    }};
    
    Toko holland = {102, "holland bakery", "makanan", 4.5, 5, {
        {102, "Roti Cokelat", "makanan", 12000, 25},
        {103, "Susu Kotak UHT", "minuman", 6500, 100}
    }};

    Toko matahari = {103, "matahari", "pakaian", 4.2, 4, {
        {104, "Jaket Denim", "pakaian", 250000, 20}
    }};

    daftarTokoMarketplace.push_back(uniqlo);
    daftarTokoMarketplace.push_back(holland);
    daftarTokoMarketplace.push_back(matahari);
}

// ==========================================
//          SISTEM AUTENTIKASI
// ==========================================
void menuAutentikasi() {
    bersihkanLayar();
    int pilihan;
    cetakGaris(45, '=');
    cout << "     SELAMAT DATANG DI MARKETPLACE\n";
    cetakGaris(45, '=');
    cout << "1. Registrasi Akun Baru\n2. Login ke Aplikasi\n3. Keluar Aplikasi\n";
    cetakGaris(45, '-');
    cout << "Pilih Opsi (1-3): "; cin >> pilihan;

    if (cin.fail()) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "[!] Input harus angka!\n"; tungguEnter(); return;
    }

    switch (pilihan) {
        case 1: registrasiAkun(); break;
        case 2: loginAkun(); break;
        case 3: cout << "\nTerima kasih!\n"; exit(0);
        default: cout << "[!] Opsi salah!\n"; tungguEnter();
    }
}

void registrasiAkun() {
    bersihkanLayar();
    User userBaru;
    cout << "=== REGISTRASI AKUN ===\n";
    cout << "Username Baru : "; cin >> userBaru.username;
    cout << "Password Baru : "; cin >> userBaru.password;
    cin.ignore(1000, '\n');
    cout << "Alamat Lengkap: "; getline(cin, userBaru.alamat);
    userBaru.isAdmin = false;

    for(const auto& u : databaseUser) {
        if(u.username == userBaru.username) {
            cout << "\n[!] Username sudah ada!\n"; tungguEnter(); return;
        }
    }
    databaseUser.push_back(userBaru);
    cout << "\n[Sukses] Registrasi Berhasil!\n"; tungguEnter();
}

void loginAkun() {
    bersihkanLayar();
    string uname, pword;
    cout << "=== HALAMAN LOGIN ===\n";
    cout << "Username : "; cin >> uname;
    cout << "Password : "; cin >> pword;

    for (auto& u : databaseUser) {
        if (u.username == uname && u.password == pword) {
            userLogin = u; isLoggedIn = true;
            cout << "\n[Sukses] Selamat datang, " << userLogin.username << ".\n";
            tungguEnter(); return;
        }
    }
    cout << "\n[!] Username/Password salah!"; tungguEnter();
}

// ==========================================
//             FITUR MENU UTAMA
// ==========================================
void menuUtama() {
    bersihkanLayar();
    int pilihan;
    cetakGaris(40, '=');
    cout << "               MENU UTAMA\n";
    cetakGaris(40, '=');
    cout << "1. Tampilkan Katalog Toko\n2. Cari Produk\n3. Tambah ke Keranjang\n4. Lihat Keranjang & Checkout\n5. Berikan Ulasan Toko\n";
    if (userLogin.isAdmin) cout << "6. Panel Admin\n";
    cout << "7. Logout\n";
    cetakGaris(40, '-');
    cout << "Pilih menu: "; cin >> pilihan;

    if (cin.fail()) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "[!] Masukkan angka!\n"; tungguEnter(); return;
    }

    switch (pilihan) {
        case 1: tampilkanKatalogToko(); break;
        case 2: cariProduk(); break;
        case 3: tambahKeKeranjang(); break;
        case 4: lihatKeranjangDanCheckout(); break;
        case 5: berikanUlasanToko(); break;
        case 6: 
            if (userLogin.isAdmin) menuManajemenTokoAdmin();
            else cout << "[!] Menu tidak valid!\n"; break;
        case 7:
            isLoggedIn = false; keranjangBelanja.clear();
            cout << "\n[Sukses] Berhasil logout.\n"; tungguEnter(); break;
        default: cout << "[!] Pilihan salah!\n"; tungguEnter();
    }
}

void tampilkanKatalogToko() {
    bersihkanLayar();
    if (daftarTokoMarketplace.empty()) {
        cout << "\n[!] Belum ada toko aktif.\n"; tungguEnter(); return;
    }

    cetakGaris(75, '=');
    cout << left << setw(10) << "ID Toko" << setw(20) << "Nama Toko" << setw(15) << "Rating" << "Kategori" << endl;
    cetakGaris(75, '-');
    for (const auto& t : daftarTokoMarketplace) {
        string rat = to_string(t.ratingToko).substr(0,3) + " (" + to_string(t.jumlahUlasan) + ")";
        cout << left << setw(10) << t.idToko << setw(20) << t.namaToko << setw(15) << rat << t.kategoriDijual << endl;
    }
    cetakGaris(75, '=');

    string namaPilihan;
    cout << "\nKetik Nama Toko untuk melihat produknya: ";
    cin.ignore(1000, '\n'); getline(cin, namaPilihan);
    for (char &c : namaPilihan) c = tolower(c);

    for (const auto& t : daftarTokoMarketplace) {
        string tLow = t.namaToko;
        for (char &c : tLow) c = tolower(c);

        if (tLow == namaPilihan) {
            bersihkanLayar();
            cetakGaris(70, '=');
            cout << "               PRODUK TOKO: " << t.namaToko << "\n";
            cetakGaris(70, '=');
            cout << left << setw(8) << "ID" << setw(25) << "Nama" << setw(15) << "Harga" << "Stok" << endl;
            cetakGaris(70, '-');
            for (const auto& p : t.daftarProduk) {
                cout << left << setw(8) << p.id << setw(25) << p.nama << "Rp " << setw(11) << fixed << setprecision(0) << p.harga << p.stok << endl;
            }
            tungguEnter(); return;
        }
    }
    cout << "[!] Toko tidak ditemukan.\n"; tungguEnter();
}

void cariProduk() {
    bersihkanLayar();
    string namaCari; cin.ignore(1000, '\n');
    cout << "Masukkan nama produk: "; getline(cin, namaCari);
    for(char &c : namaCari) c = tolower(c);
    bool ditemukan = false;
    
    for (const auto& t : daftarTokoMarketplace) {
        for (const auto& p : t.daftarProduk) {
            string pLow = p.nama;
            for(char &c : pLow) c = tolower(c);
            if (pLow.find(namaCari) != string::npos) {
                if (!ditemukan) {
                    cetakGaris(60, '-');
                    cout << left << setw(8) << "ID" << setw(25) << "Nama" << setw(15) << "Toko" << "Harga" << endl;
                    cetakGaris(60, '-');
                }
                cout << left << setw(8) << p.id << setw(25) << p.nama << setw(15) << t.namaToko << "Rp " << p.harga << endl;
                ditemukan = true;
            }
        }
    }
    if (!ditemukan) cout << "\n[!] Produk tidak ditemukan.\n";
    tungguEnter();
}

void tambahKeKeranjang() {
    bersihkanLayar();
    int idCari, jml;
    cout << "Masukkan ID barang: "; cin >> idCari;
    cout << "Masukkan Jumlah   : "; cin >> jml;
    
    if(cin.fail() || jml <= 0){
        cin.clear(); cin.ignore(1000,'\n');
        cout << "[!] Input tidak valid.\n"; tungguEnter(); return;
    }

    for (auto& t : daftarTokoMarketplace) {
        for (auto& p : t.daftarProduk) {
            if (p.id == idCari) {
                if (p.stok >= jml) {
                    keranjangBelanja.push_back({t.namaToko, p, jml});
                    p.stok -= jml; 
                    cout << "\n[Sukses] Berhasil masuk keranjang!\n";
                    tungguEnter(); return;
                } else {
                    cout << "\n[!] Stok kurang! Sisa: " << p.stok << endl;
                    tungguEnter(); return;
                }
            }
        }
    }
    cout << "\n[!] ID Salah.\n"; tungguEnter();
}

void lihatKeranjangDanCheckout() {
    bersihkanLayar();
    if (keranjangBelanja.empty()) { cout << "\n[!] Keranjang kosong.\n"; tungguEnter(); return; }

    cetakGaris(60, '=');
    cout << "                    KERANJANG BELANJA\n";
    cetakGaris(60, '=');
    double total = 0;
    for (size_t i = 0; i < keranjangBelanja.size(); ++i) {
        double sub = keranjangBelanja[i].produk.harga * keranjangBelanja[i].jumlah;
        total += sub;
        cout << i + 1 << ". [" << keranjangBelanja[i].dariToko << "] " << left << setw(20) << keranjangBelanja[i].produk.nama << " x" << keranjangBelanja[i].jumlah << " = Rp " << sub << endl;
    }
    cetakGaris(60, '-');
    cout << " Total Tagihan : Rp " << fixed << setprecision(0) << total << endl;
    char konf; cout << "\nCheckout sekarang? (y/n): "; cin >> konf;

    if (konf == 'y' || konf == 'Y') {
        cout << "\n[Sukses] Checkout berhasil! Dikirim ke: " << userLogin.alamat << endl;
        keranjangBelanja.clear(); 
    } else cout << "\nCheckout dibatalkan.\n";
    tungguEnter();
}

void berikanUlasanToko() {
    bersihkanLayar();
    int idT; double rat;
    cout << "Masukkan ID Toko: "; cin >> idT;

    for(auto& t : daftarTokoMarketplace) {
        if(t.idToko == idT) {
            cout << "Rating Toko (1.0 - 5.0): "; cin >> rat;
            if(rat < 1.0 || rat > 5.0 || cin.fail()) {
                cin.clear(); cin.ignore(1000, '\n');
                cout << "[!] Rating salah.\n"; tungguEnter(); return;
            }
            t.ratingToko = ((t.ratingToko * t.jumlahUlasan) + rat) / (t.jumlahUlasan + 1);
            t.jumlahUlasan++;
            cout << "[Sukses] Ulasan disimpan!\n"; tungguEnter(); return;
        }
    }
    cout << "[!] Toko tidak ada.\n"; tungguEnter();
}

// ==========================================
//          SISTEM PANEL ADMIN
// ==========================================
void menuManajemenTokoAdmin() {
    int pil;
    do {
        bersihkanLayar();
        cout << "=== PANEL MANAJEMEN ADMIN ===\n";
        cout << "1. Cek Total Aset\n2. Tambah Toko\n3. Hapus Toko\n4. Tambah Produk\n5. Restock Stok\n6. Kurang Stok\n7. Hapus Produk\n8. Keluar Panel\nPilih: "; cin >> pil;

        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); continue; }
        switch (pil) {
            case 1: hitungTotalAset(); break;
            case 2: tambahTokoBaru(); break;
            case 3: hapusToko(); break;
            case 4: tambahProdukKeToko(); break;
            case 5: updateStokMasuk(); break;
            case 6: updateStokKeluar(); break;
            case 7: hapusProduk(); break;
        }
    } while (pil != 8);
}

void hitungTotalAset() {
    bersihkanLayar();
    double totalAset = 0; int totalBarang = 0;
    cout << "=== LAPORAN ASET GLOBAL ===\n\n";
    for (const auto& t : daftarTokoMarketplace) {
        cout << " * Toko: " << t.namaToko << "\n";
        for (const auto& p : t.daftarProduk) {
            totalAset += (p.harga * p.stok); totalBarang += p.stok;
            cout << "   - " << left << setw(20) << p.nama << " Stok: " << p.stok << endl;
        }
    }
    cout << "\n Total Toko  : " << daftarTokoMarketplace.size() << endl;
    cout << " Total Stok  : " << totalBarang << " pcs\n";
    cout << " Nilai Aset  : Rp " << fixed << setprecision(0) << totalAset << endl;
    tungguEnter();
}

void tambahTokoBaru() {
    bersihkanLayar(); Toko t;
    cout << "ID Toko (Angka): "; cin >> t.idToko;
    cin.ignore(1000, '\n');
    cout << "Nama Toko      : "; getline(cin, t.namaToko);
    cout << "Kategori Toko  : "; getline(cin, t.kategoriDijual);
    t.ratingToko = 0.0; t.jumlahUlasan = 0;
    daftarTokoMarketplace.push_back(t);
    cout << "\nToko berhasil terdaftar.\n"; tungguEnter();
}

void hapusToko() {
    bersihkanLayar(); int id;
    cout << "Masukkan ID Toko: "; cin >> id;
    for (auto it = daftarTokoMarketplace.begin(); it != daftarTokoMarketplace.end(); ++it) {
        if (it->idToko == id) {
            daftarTokoMarketplace.erase(it);
            cout << "[Sukses] Toko dihapus.\n"; tungguEnter(); return;
        }
    }
    cout << "[!] Gagal.\n"; tungguEnter();
}

void tambahProdukKeToko() {
    bersihkanLayar(); int idT;
    cout << "Masukkan ID Toko: "; cin >> idT;
    for (auto& t : daftarTokoMarketplace) {
        if (t.idToko == idT) {
            Produk p;
            cout << "ID Produk: "; cin >> p.id;
            cin.ignore(1000, '\n');
            cout << "Nama     : "; getline(cin, p.nama);
            cout << "Kategori : "; getline(cin, p.kategori);
            cout << "Harga    : "; cin >> p.harga;
            cout << "Stok     : "; cin >> p.stok;
            t.daftarProduk.push_back(p);
            cout << "\nProduk ditambahkan.\n"; tungguEnter(); return;
        }
    }
    cout << "[!] ID Toko salah.\n"; tungguEnter();
}

void updateStokMasuk() {
    bersihkanLayar(); int idP, jml;
    cout << "Masukkan ID Produk: "; cin >> idP;
    for (auto& t : daftarTokoMarketplace) {
        for (auto& p : t.daftarProduk) {
            if (p.id == idP) {
                cout << "Jumlah Stok Masuk: "; cin >> jml;
                if(jml > 0) p.stok += jml;
                cout << "[Sukses] Stok bertambah.\n"; tungguEnter(); return;
            }
        }
    }
    cout << "[!] ID salah.\n"; tungguEnter();
}

void updateStokKeluar() {
    bersihkanLayar(); int idP, jml;
    cout << "Masukkan ID Produk: "; cin >> idP;
    for (auto& t : daftarTokoMarketplace) {
        for (auto& p : t.daftarProduk) {
            if (p.id == idP) {
                cout << "Jumlah Buang Stok: "; cin >> jml;
                if (p.stok >= jml && jml > 0) p.stok -= jml;
                cout << "[Sukses] Stok dikurangi.\n"; tungguEnter(); return;
            }
        }
    }
    cout << "[!] ID salah.\n"; tungguEnter();
}

void hapusProduk() {
    bersihkanLayar(); int idP;
    cout << "Masukkan ID Produk: "; cin >> idP;
    for (auto& t : daftarTokoMarketplace) {
        for (auto it = t.daftarProduk.begin(); it != t.daftarProduk.end(); ++it) {
            if (it->id == idP) {
                t.daftarProduk.erase(it);
                cout << "[Sukses] Produk terhapus.\n"; tungguEnter(); return;
            }
        }
    }
    cout << "[!] ID salah.\n"; tungguEnter();
}
