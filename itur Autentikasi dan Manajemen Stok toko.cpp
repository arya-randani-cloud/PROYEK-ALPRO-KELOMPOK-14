#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// --- STRUKTUR DATA ---
struct Produk {
    int id;
    string nama;
    string kategori;
    double harga;
    int stok;
};

struct KeranjangItem {
    Produk produk;
    int jumlah;
};

struct User {
    string username;
    string password;
    string alamat;
};

// --- DATA SIMULASI (DATABASE UTAMA) ---
vector<User> databaseUser;
vector<Produk> katalogProduk;
vector<KeranjangItem> keranjangBelanja;
User userLogin; 
bool isLoggedIn = false;
int counterId = 101; // ID produk otomatis dimulai dari 101

// --- PROTOTIPE FUNGSI ---
void inisialisasiDataAwal();
void menuAutentikasi();
void registrasi();
void login();
void menuUtama();
void tampilkanKatalog();
void cariProduk();
void tambahKeKeranjang();
void lihatKeranjangDanCheckout();
void menuManajemenToko();
void tambahProdukBaru();
void updateStokMasuk();
void updateStokKeluar();
void hapusProduk();
void hitungTotalAset();
void cekAlamatUser();

// --- MAIN FUNCTION ---
int main() {
    inisialisasiDataAwal();
    cout << "===========================================" << endl;
    cout << "   SELAMAT DATANG DI SISTEM MANAJEMEN TOKO " << endl;
    cout << "===========================================" << endl;
    
    while (true) {
        if (!isLoggedIn) {
            menuAutentikasi();
        } else {
            menuUtama();
        }
    }
    return 0;
}

// Inisialisasi Data Awal (Termasuk 3 barang tambahan dari kamu)
void inisialisasiDataAwal() {
    katalogProduk.push_back({counterId++, "Kopi Kenangan", "Minuman", 18000, 40});
    katalogProduk.push_back({counterId++, "Roti Cokelat", "Makanan", 12000, 25});
    katalogProduk.push_back({counterId++, "Susu Kotak UHT", "Minuman", 6500, 100});
    // 3 List Barang Tambahan Baru
    katalogProduk.push_back({counterId++, "Laptop Asus", "Elektronik", 8500000, 10});
    katalogProduk.push_back({counterId++, "Mouse Logitech", "Elektronik", 150000, 25});
    katalogProduk.push_back({counterId++, "Kemeja Polos", "Pakaian", 125000, 50});
}

// --- 1. FITUR AUTENTIKASI ---
void menuAutentikasi() {
    int pilihan;
    cout << "\n[ MENU AKSES ]" << endl;
    cout << "1. Registrasi Akun" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar Aplikasi" << endl;
    cout << "Pilih opsi (1-3): ";
    cin >> pilihan;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[!] Input salah! Masukkan angka menu.\n";
        return;
    }

    switch (pilihan) {
        case 1: registrasi(); break;
        case 2: login(); break;
        case 3: 
            cout << "\nTerima kasih telah menggunakan aplikasi ini!" << endl;
            exit(0);
        default: cout << "[!] Pilihan tidak valid!" << endl;
    }
}

void registrasi() {
    User userBaru;
    cout << "\n--- REGISTRASI AKUN ---" << endl;
    cout << "Masukkan Username: ";
    cin >> userBaru.username;
    cout << "Masukkan Password: ";
    cin >> userBaru.password;
    cin.ignore(); 
    cout << "Masukkan Alamat Lengkap: ";
    getline(cin, userBaru.alamat);

    databaseUser.push_back(userBaru);
    cout << "[Sukses] Registrasi Berhasil! Silakan Login." << endl;
}

void login() {
    string uname, pword;
    cout << "\n--- LOGIN USER ---" << endl;
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pword;

    for (const auto& u : databaseUser) {
        if (u.username == uname && u.password == pword) {
            userLogin = u;
            isLoggedIn = true;
            cout << "[Sukses] Login Berhasil! Selamat datang, " << userLogin.username << "." << endl;
            return;
        }
    }
    cout << "[!] Username atau Password salah! Coba lagi atau registrasi terlebih dahulu." << endl;
}

// --- 2. FITUR KATALOG & TAMPILAN UTAMA ---
void menuUtama() {
    int pilihan;
    cout << "\n=========================================" << endl;
    cout << "               MENU UTAMA                " << endl;
    cout << "=========================================" << endl;
    cout << "1. Tampilkan Katalog Produk\n";
    cout << "2. Cari Produk Berdasarkan Nama\n";
    cout << "3. Tambah Barang ke Keranjang\n";
    cout << "4. Lihat Keranjang & Checkout\n";
    cout << "5. Panel Dashboard Admin (Manajemen Toko)\n";
    cout << "6. Logout\n";
    cout << "-----------------------------------------" << endl;
    cout << "Pilih menu (1-6): ";
    cin >> pilihan;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[!] Input salah! Masukkan angka menu.\n";
        return;
    }

    switch (pilihan) {
        case 1: tampilkanKatalog(); break;
        case 2: cariProduk(); break;
        case 3: tambahKeKeranjang(); break;
        case 4: lihatKeranjangDanCheckout(); break;
        case 5: menuManajemenToko(); break;
        case 6: 
            isLoggedIn = false;
            keranjangBelanja.clear();
            cout << "[Sukses] Berhasil logout." << endl;
            break;
        default: cout << "[!] Pilihan tidak valid!" << endl;
    }
}

void tampilkanKatalog() {
    if (katalogProduk.empty()) {
        cout << "\n[!] Katalog toko masih kosong!\n";
        return;
    }

    cout << "\n======================================================================\n";
    cout << "                          DAFTAR BARANG TOKO                          \n";
    cout << "======================================================================\n";
    cout << left << setw(6) << "ID" 
         << setw(22) << "Nama Produk" 
         << setw(15) << "Kategori" 
         << setw(15) << "Harga" 
         << setw(10) << "Stok" << endl;
    cout << "----------------------------------------------------------------------\n";

    for (const auto& p : katalogProduk) {
        cout << left << setw(6) << p.id 
             << setw(22) << p.nama 
             << setw(15) << p.kategori 
             << "Rp " << setw(12) << fixed << setprecision(0) << p.harga 
             << setw(10) << p.stok << endl;
    }
    cout << "======================================================================\n";
}

void cariProduk() {
    string namaCari;
    cin.ignore();
    cout << "\nMasukkan nama produk yang dicari: ";
    getline(cin, namaCari);

    bool ditemukan = false;
    cout << "\nHasil pencarian untuk '" << namaCari << "':\n";
    
    for (const auto& p : katalogProduk) {
        if (p.nama.find(namaCari) != string::npos) {
            if (!ditemukan) {
                cout << "----------------------------------------------------------------------\n";
                cout << left << setw(6) << "ID" << setw(22) << "Nama" << setw(15) << "Kategori" << setw(15) << "Harga" << endl;
                cout << "----------------------------------------------------------------------\n";
            }
            cout << left << setw(6) << p.id << setw(22) << p.nama << setw(15) << p.kategori << "Rp " << p.harga << endl;
            ditemukan = true;
        }
    }
    
    if (!ditemukan) cout << "[!] Produk '" << namaCari << "' tidak ditemukan.\n";
    else cout << "----------------------------------------------------------------------\n";
}

// --- 3. FITUR KERANJANG, CHECKOUT, & PENGECEKAN BARANG ---
void tambahKeKeranjang() {
    int idCari, jumlahBeli;
    tampilkanKatalog();
    cout << "\nMasukkan ID Produk yang ingin dibeli: ";
    cin >> idCari;
    cout << "Masukkan Jumlah: ";
    cin >> jumlahBeli;

    for (auto& p : katalogProduk) {
        if (p.id == idCari) {
            if (p.stok >= jumlahBeli) {
                keranjangBelanja.push_back({p, jumlahBeli});
                p.stok -= jumlahBeli; // Otomatis mengurangi stok berjalan
                cout << "[Sukses] Barang berhasil dimasukkan ke keranjang!" << endl;
                return;
            } else {
                cout << "[!] Stok tidak mencukupi! Stok tersisa: " << p.stok << endl;
                return;
            }
        }
    }
    cout << "[!] Produk dengan ID tersebut tidak ditemukan." << endl;
}

void lihatKeranjangDanCheckout() {
    if (keranjangBelanja.empty()) {
        cout << "\n[!] Keranjang belanja Anda masih kosong." << endl;
        return;
    }

    cout << "\n===================================================\n";
    cout << "          PENGECEKAN BARANG DI KERANJANG           \n";
    cout << "===================================================\n";
    double totalBayar = 0;
    for (size_t i = 0; i < keranjangBelanja.size(); ++i) {
        double subtotal = keranjangBelanja[i].produk.harga * keranjangBelanja[i].jumlah;
        totalBayar += subtotal;
        cout << i + 1 << ". " << left << setw(20) << keranjangBelanja[i].produk.nama 
             << " x" << setw(4) << keranjangBelanja[i].jumlah 
             << " | Subtotal: Rp " << fixed << setprecision(0) << subtotal << endl;
    }
    cout << "---------------------------------------------------\n";
    cout << " Total Yang Harus Dibayar : Rp " << totalBayar << endl;
    cout << "===================================================\n";

    char konfirmasi;
    cout << "Apakah Anda ingin melakukan Checkout? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        cout << "\n[Sukses] Checkout Berhasil! Pengiriman akan ditujukan ke alamat Anda.\n";
        cekAlamatUser();
        keranjangBelanja.clear(); 
    } else {
        cout << "Checkout dibatalkan." << endl;
    }
}

// --- 4. FITUR KHUSUS DASHBOARD ADMIN / MANAJEMEN TOKO ---
void menuManajemenToko() {
    int pilihan;
    do {
        cout << "\n========== DASHBOARD ADMIN TOKO ==========\n";
        cout << "1. Lihat Semua Stok Barang\n";
        cout << "2. Tambah Produk Baru\n";
        cout << "3. Update Stok Pemasukan (Restock)\n";
        cout << "4. Update Stok Pengeluaran Manual\n";
        cout << "5. Hapus Produk dari Toko\n";
        cout << "6. Lihat Laporan Aset Toko\n";
        cout << "7. Pengecekan Alamat User Pemesan\n";
        cout << "8. Kembali ke Menu Utama\n";
        cout << "------------------------------------------\n";
        cout << "Pilih Opsi (1-8): ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[!] Input salah! Masukkan angka menu.\n";
            continue;
        }

        switch (pilihan) {
            case 1: tampilkanKatalog(); break;
            case 2: tambahProdukBaru(); break;
            case 3: updateStokMasuk(); break;
            case 4: updateStokKeluar(); break;
            case 5: hapusProduk(); break;
            case 6: hitungTotalAset(); break;
            case 7: cekAlamatUser(); break;
            case 8: return;
            default: cout << "[!] Opsi menu tidak tersedia.\n";
        }
    } while (pilihan != 8);
}

void tambahProdukBaru() {
    Produk pBaru;
    pBaru.id = counterId++;
    cin.ignore();
    cout << "\n--- Tambah Produk Baru ---\n";
    cout << "Nama Produk : "; getline(cin, pBaru.nama);
    cout << "Kategori    : "; getline(cin, pBaru.kategori);
    cout << "Harga Jual  : Rp "; cin >> pBaru.harga;
    cout << "Stok Awal   : "; cin >> pBaru.stok;

    katalogProduk.push_back(pBaru);
    cout << "\n[Sukses] Produk '" << pBaru.nama << "' berhasil didaftarkan dengan ID " << pBaru.id << "!\n";
}

void updateStokMasuk() {
    int idCari, tambahStok;
    tampilkanKatalog();
    cout << "\nMasukkan ID Produk untuk UPDATE PEMASUKAN (Restock): ";
    cin >> idCari;

    for (auto& p : katalogProduk) {
        if (p.id == idCari) {
            cout << "Produk Ditemukan: " << p.nama << " (Stok Saat Ini: " << p.stok << ")\n";
            cout << "Masukkan Jumlah Stok yang Masuk: ";
            cin >> tambahStok;
            p.stok += tambahStok;
            cout << "[Sukses] Stok " << p.nama << " ditambah. Stok sekarang: " << p.stok << " pcs.\n";
            return;
        }
    }
    cout << "[!] Produk tidak ditemukan.\n";
}

void updateStokKeluar() {
    int idCari, kurangStok;
    tampilkanKatalog();
    cout << "\nMasukkan ID Produk untuk UPDATE PENGELUARAN manual: ";
    cin >> idCari;

    for (auto& p : katalogProduk) {
        if (p.id == idCari) {
            cout << "Produk Ditemukan: " << p.nama << " (Stok Saat Ini: " << p.stok << ")\n";
            cout << "Masukkan Jumlah Stok yang Keluar: ";
            cin >> kurangStok;
            if (p.stok >= kurangStok) {
                p.stok -= kurangStok;
                cout << "[Sukses] Stok " << p.nama << " dikurangi. Stok sekarang: " << p.stok << " pcs.\n";
            } else {
                cout << "[!] Gagal! Jumlah pengeluaran melebihi stok yang ada.\n";
            }
            return;
        }
    }
    cout << "[!] Produk tidak ditemukan.\n";
}

void hapusProduk() {
    int idHapus;
    bool ditemukan = false;
    tampilkanKatalog();
    cout << "\nMasukkan ID Produk yang ingin dihapus dari Toko: ";
    cin >> idHapus;

    for (auto it = katalogProduk.begin(); it != katalogProduk.end(); ++it) {
        if (it->id == idHapus) {
            cout << "[Peringatan] Menghapus '" << it->nama << "' dari sistem...\n";
            katalogProduk.erase(it);
            cout << "[Sukses] Produk telah berhasil dihapus.\n";
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) cout << "[!] Produk dengan ID " << idHapus << " tidak ditemukan.\n";
}

void hitungTotalAset() {
    double totalAset = 0;
    int totalBarang = 0;

    for (const auto& p : katalogProduk) {
        totalAset += (p.harga * p.stok);
        totalBarang += p.stok;
    }

    cout << "\n=========================================\n";
    cout << "         LAPORAN RINGKASAN TOKO          \n";
    cout << "=========================================\n";
    cout << " Total Jenis Produk : " << katalogProduk.size() << " jenis\n";
    cout << " Total Stok Barang  : " << totalBarang << " pcs\n";
    cout << " Total Nilai Aset   : Rp " << fixed << setprecision(0) << totalAset << endl;
    cout << "=========================================\n";
}

void cekAlamatUser() {
    cout << "\n--- PENGECEKAN ALAMAT USER AKTIF ---" << endl;
    cout << "User yang memesan  : " << userLogin.username << endl;
    cout << "Alamat Pengiriman  : " << userLogin.alamat << endl;
    cout << "------------------------------------" << endl;
}
