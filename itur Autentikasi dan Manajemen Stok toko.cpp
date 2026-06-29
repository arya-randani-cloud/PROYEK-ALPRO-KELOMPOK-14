#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- STRUKTUR DATA ---
struct Produk {
    int id;
    string nama;
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

// --- DATA SIMULASI (DATABASE SEDERHANA) ---
vector<User> databaseUser;
vector<Produk> katalogProduk = {
    {1, "Laptop ASUS", 8500000, 10},
    {2, "Mouse Logitech", 150000, 50},
    {3, "Keyboard Mechanical", 450000, 25}
};
vector<KeranjangItem> keranjangBelanja;
User userLogin; // Menyimpan data user yang sedang login
bool isLoggedIn = false;

// --- PROTOTIPE FUNGSI ---
void menuAutentikasi();
void registrasi();
void login();
void menuUtama();
void tampilkanKatalog();
void tambahKeKeranjang();
void lihatKeranjangDanCheckout();
void menuManajemenToko();
void updateStokMasuk();
void updateStokKeluar();
void cekAlamatUser();

// --- MAIN FUNCTION ---
int main() {
    cout << "=== SELAMAT DATANG DI SISTEM TOKO C++ ===" << endl;
    while (true) {
        if (!isLoggedIn) {
            menuAutentikasi();
        } else {
            menuUtama();
        }
    }
    return 0;
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

    switch (pilihan) {
        case 1: registrasi(); break;
        case 2: login(); break;
        case 3: 
            cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
            exit(0);
        default: cout << "Pilihan tidak valid!" << endl;
    }
}

void registrasi() {
    User userBaru;
    cout << "\n--- REGISTRASI AKUN ---" << endl;
    cout << "Masukkan Username: ";
    cin >> userBaru.username;
    cout << "Masukkan Password: ";
    cin >> userBaru.password;
    cin.ignore(); // Membersihkan buffer input
    cout << "Masukkan Alamat Lengkap: ";
    getline(cin, userBaru.alamat);

    databaseUser.push_back(userBaru);
    cout << "Registrasi Berhasil! Silakan Login." << endl;
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
            cout << "Login Berhasil! Selamat datang, " << userLogin.username << "." << endl;
            return;
        }
    }
    cout << "Username atau Password salah! Silakan coba lagi atau registrasi." << endl;
}

// --- 2. FITUR KATALOG & TAMPILAN UTAMA ---
void menuUtama() {
    int pilihan;
    cout << "\n===============================" << endl;
    cout << "           MENU UTAMA          " << endl;
    cout << "===============================" << endl;
    cout << "1. Tampilkan Katalog Produk" << endl;
    cout << "2. Tambah Barang ke Keranjang" << endl;
    cout << "3. Lihat Keranjang & Checkout (Pengecekan Barang)" << endl;
    cout << "4. Menu Manajemen Toko (Admin/Stok/Alamat)" << endl;
    cout << "5. Logout" << endl;
    cout << "Pilih menu (1-5): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: tampilkanKatalog(); break;
        case 2: tambahKeKeranjang(); break;
        case 3: lihatKeranjangDanCheckout(); break;
        case 4: menuManajemenToko(); break;
        case 5: 
            isLoggedIn = false;
            keranjangBelanja.clear();
            cout << "Berhasil logout." << endl;
            break;
        default: cout << "Pilihan tidak valid!" << endl;
    }
}

void tampilkanKatalog() {
    cout << "\n--- KATALOG PRODUK ---" << endl;
    cout << "ID\tNama Produk\t\tHarga\t\tStok" << endl;
    cout << "---------------------------------------------------" << endl;
    for (const auto& p : katalogProduk) {
        cout << p.id << "\t" << p.nama << "\t\tRp" << p.harga << "\t" << p.stok << endl;
    }
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
                p.stok -= jumlahBeli; // Pengeluaran stok otomatis saat masuk keranjang
                cout << "Barang berhasil dimasukkan ke keranjang!" << endl;
                return;
            } else {
                cout << "Stok tidak mencukupi! Stok tersisa: " << p.stok << endl;
                return;
            }
        }
    }
    cout << "Produk dengan ID tersebut tidak ditemukan." << endl;
}

void lihatKeranjangDanCheckout() {
    if (keranjangBelanja.empty()) {
        cout << "\nKeranjang belanja Anda masih kosong." << endl;
        return;
    }

    // Pengecekan barang yang dibeli
    cout << "\n--- PENGECEKAN BARANG DI KERANJANG ---" << endl;
    double totalBayar = 0;
    for (size_t i = 0; i < keranjangBelanja.size(); ++i) {
        double subtotal = keranjangBelanja[i].produk.harga * keranjangBelanja[i].jumlah;
        totalBayar += subtotal;
        cout << i + 1 << ". " << keranjangBelanja[i].produk.nama 
             << " x" << keranjangBelanja[i].jumlah 
             << " | Subtotal: Rp" << subtotal << endl;
    }
    cout << "---------------------------------------" << endl;
    cout << "Total Yang Harus Dibayar: Rp" << totalBayar << endl;

    char konfirmasi;
    cout << "Apakah Anda ingin melakukan Checkout? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        cout << "Checkout Berhasil! Terima kasih sudah berbelanja." << endl;
        keranjangBelanja.clear(); // Kosongkan keranjang setelah checkout
    } else {
        cout << "Checkout dibatalkan." << endl;
    }
}

// --- 4. FITUR KHUSUS MANAJEMEN TOKO (ADMIN) ---
void menuManajemenToko() {
    int pilihan;
    cout << "\n--- PANEL MANAJEMEN TOKO ---" << endl;
    cout << "1. Update Stok Pemasukan (Tambah Stok)" << endl;
    cout << "2. Update Stok Pengeluaran (Kurangi Stok)" << endl;
    cout << "3. Pengecekan Alamat User yang Memesan" << endl;
    cout << "4. Kembali ke Menu Utama" << endl;
    cout << "Pilih opsi (1-4): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: updateStokMasuk(); break;
        case 2: updateStokKeluar(); break;
        case 3: cekAlamatUser(); break;
        case 4: return;
        default: cout << "Pilihan tidak valid!" << endl;
    }
}

void updateStokMasuk() {
    int idCari, tambahStok;
    tampilkanKatalog();
    cout << "\nMasukkan ID Produk untuk UPDATE PEMASUKAN: ";
    cin >> idCari;
    cout << "Masukkan Jumlah Stok yang Masuk: ";
    cin >> tambahStok;

    for (auto& p : katalogProduk) {
        if (p.id == idCari) {
            p.stok += tambahStok;
            cout << "Stok " << p.nama << " berhasil ditambah. Stok sekarang: " << p.stok << endl;
            return;
        }
    }
    cout << "Produk tidak ditemukan." << endl;
}

void updateStokKeluar() {
    int idCari, kurangStok;
    tampilkanKatalog();
    cout << "\nMasukkan ID Produk untuk UPDATE PENGELUARAN manual: ";
    cin >> idCari;
    cout << "Masukkan Jumlah Stok yang Keluar: ";
    cin >> kurangStok;

    for (auto& p : katalogProduk) {
        if (p.id == idCari) {
            if (p.stok >= kurangStok) {
                p.stok -= kurangStok;
                cout << "Stok " << p.nama << " berhasil dikurangi. Stok sekarang: " << p.stok << endl;
            } else {
                cout << "Gagal! Jumlah pengeluaran melebihi stok yang ada." << endl;
            }
            return;
        }
    }
    cout << "Produk tidak ditemukan." << endl;
}

void cekAlamatUser() {
    cout << "\n--- PENGECEKAN ALAMAT USER AKTIF ---" << endl;
    cout << "User yang sedang login: " << userLogin.username << endl;
    cout << "Alamat Pengiriman     : " << userLogin.alamat << endl;
}
