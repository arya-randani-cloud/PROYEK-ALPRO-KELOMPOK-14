#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

// ==========================================
//                 STRUKTUR DATA
// ==========================================
struct Produk {
    int id;
    string nama;
    string kategori;
    double hargaBeli; // Untuk keperluan laporan pengeluaran restock
    double hargaJual; // Untuk keperluan laporan pemasukan
    int stok;
};

struct KeuanganToko {
    double saldoKas;
    double totalPemasukan;
    double totalPengeluaran;
    double totalPajak;
};

struct Toko {
    int idToko;
    string namaToko;
    string kategoriDijual; 
    double ratingToko;
    int jumlahUlasan;
    KeuanganToko keuangan;
    vector<Produk> daftarProduk;
};

struct User {
    string username;
    string password;
    string alamat;
    bool isAdmin;
};

struct PesananMasuk {
    string namaPembeli;
    string alamatPembeli;
    string namaToko;
    string namaProduk;
    int jumlah;
    double totalBayar;
};

// ==========================================
//         DATABASE SIMULASI GLOBAL
// ==========================================
vector<User> databaseUser;
vector<Toko> daftarTokoMarketplace;
vector<PesananMasuk> riwayatPesanan; // Untuk pengecekan alamat pemesan & barang dibeli

User userLogin; 
bool isLoggedIn = false;
bool sudahRegistrasi = false; // Flag untuk membatasi registrasi cukup sekali

// ==========================================
//             PROTOTIPE FUNGSI
// ==========================================
void inisialisasiMarketplace();
void bersihkanLayar();
void tungguEnter();
void cetakGaris(int panjang, char simbol);
string toLowerStr(string s);
bool mengandung(const string& teks, const string& keyword);

void menuAutentikasi();
void registrasiAkunToko();
void loginAkunToko();

void menuUtamaAdmin();
void tampilkanListBarangToko();
void manajemenKeuanganToko();
void cekAlamatPemesan();
void updateStokPemasukan();
void updateStokPengeluaran();

// FITUR KATALOG & TAMPILAN UTAMA
void katalogUtamaMarketplace();
void tampilkanSemuaProdukKatalog();
void cariProdukKatalog();
void filterProdukPerKategori();

// FITUR PENGECEKAN BARANG YANG DIBELI
void cekBarangDibeli();
void tampilkanSemuaRiwayatBeli();
void cariBarangDibeliPerNama();
void rekapTotalBarangTerjual();

// PANEL MANAJEMEN STRUKTUR TOKO
void panelManajemenToko();
void tambahTokoBaru();
void hapusToko();
void tambahProdukKeToko();
void hapusProduk();

// ==========================================
//                 MAIN FUNCTION
// ==========================================
int main() {
    inisialisasiMarketplace();
    while (true) {
        if (!isLoggedIn) menuAutentikasi();
        else menuUtamaAdmin();
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

// Ubah string menjadi huruf kecil semua (untuk pencarian case-insensitive)
string toLowerStr(string s) {
    for (auto &c : s) c = tolower((unsigned char)c);
    return s;
}

// Cek apakah "teks" mengandung "keyword" (case-insensitive)
bool mengandung(const string& teks, const string& keyword) {
    return toLowerStr(teks).find(toLowerStr(keyword)) != string::npos;
}

void inisialisasiMarketplace() {
    // Data Default Toko & Keuangan Awal
    Toko uniqlo = {101, "uniqlo", "pakaian", 4.8, 1, {5000000, 1500000, 500000, 165000}, {
        {101, "Celana Jeans", "pakaian", 80000, 120000, 40},
        {106, "Kemeja Polos", "pakaian", 70000, 125000, 50}
    }};
    
    Toko holland = {102, "holland bakery", "makanan", 4.5, 1, {3000000, 800000, 300000, 88000}, {
        {102, "Roti Cokelat", "makanan", 7000, 12000, 25},
        {103, "Susu Kotak UHT", "minuman", 4000, 6500, 100}
    }};

    daftarTokoMarketplace.push_back(uniqlo);
    daftarTokoMarketplace.push_back(holland);

    // Simulasi Pesanan Masuk (untuk cek alamat pemesan & barang dibeli)
    riwayatPesanan.push_back({"Budi Santoso", "Jl. Merdeka No. 45, Jakarta", "uniqlo", "Kemeja Polos", 2, 250000});
    riwayatPesanan.push_back({"Siti Aminah", "Jl. Anggrek Raya No. 12, Bandung", "holland bakery", "Roti Cokelat", 5, 60000});
}

// ==========================================
//          SISTEM AUTENTIKASI
// ==========================================
void menuAutentikasi() {
    bersihkanLayar();
    int pilihan;

    cout << "\033[1;36m";//warna kode ascii
    cout << "=========================================================================\n";
    cout << "  ____ _____ ____    _    _   _       _   _ _   _ ____  \n";
    cout << " / ___| ____|  _ \\  / \\  | \\ | |     | | | | | | | __ ) \n";
    cout << "| |   |  _| | |_) |/ _ \\ |  \\| |_____| |_| | | | |  _ \\ \n";
    cout << "| |___| |___|  _ </ ___ \\| |\\  |_____|  _  | |_| | |_) |\n";
    cout << " \\____|_____|_|\\_/_/   \\_\\_| \\_|     |_| |_|\\___/|____/ \n";
    cout << "                                                        \n";
    cout << "=========================================================================\n";
    cout << "             Welcome to CERAN_HUB Admin Store                     \n";
    cout << "=========================================================================\n";
    cout << "\033[0m";

    // Pilihan registrasi hanya muncul jika belum pernah registrasi
    if (!sudahRegistrasi) {
        cout << "1. Registrasi Akun Utama Admin \n";
        cout << "2. Login Admin\n";
        cout << "3. Keluar Aplikasi\n";
        cetakGaris(73, '-');
        cout << "Pilih Opsi (1-3): "; cin >> pilihan;

        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "[!] Input harus angka!\n"; tungguEnter(); return;
        }

        switch (pilihan) {
            case 1: registrasiAkunToko(); break;
            case 2: loginAkunToko(); break;
            case 3: cout << "\nTerima kasih!\n"; exit(0);
            default: cout << "[!] Opsi salah!\n"; tungguEnter();
        }
    } else {
        // Setelah registrasi selesai, pilihan registrasi disembunyikan sepenuhnya.
        // Hanya tersisa 2 pilihan: Login dan Keluar Aplikasi.
        cout << "1. Login Admin\n";
        cout << "2. Keluar Aplikasi\n";
        cetakGaris(73, '-');
        cout << "Pilih Opsi (1-2): "; cin >> pilihan;

        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "[!] Input harus angka!\n"; tungguEnter(); return;
        }

        switch (pilihan) {
            case 1: loginAkunToko(); break;
            case 2: cout << "\nTerima kasih!\n"; exit(0);
            default: cout << "[!] Opsi salah!\n"; tungguEnter();
        }
    }
}

void registrasiAkunToko() {
    bersihkanLayar();
    User userBaru;
    cout << "=== REGISTRASI AKUN ADMIN (Satu Kali) ===\n";
    cout << "Username Baru : "; cin >> userBaru.username;
    cout << "Password Baru : "; cin >> userBaru.password;
    cin.ignore(1000, '\n');
    cout << "Alamat Kantor : "; getline(cin, userBaru.alamat);
    userBaru.isAdmin = true;

    databaseUser.push_back(userBaru);
    sudahRegistrasi = true; // Kunci registrasi agar tidak bisa dipakai lagi
    cout << "\n[Sukses] Akun admin berhasil dibuat! Menu registrasi sekarang ditutup.\n"; 
    tungguEnter();
}

void loginAkunToko() {
    bersihkanLayar();
    string uname, pword;
    cout << "=== HALAMAN LOGIN ADMIN ===\n";
    cout << "Username : "; cin >> uname;
    cout << "Password : "; cin >> pword;

    // Cek database buatan atau default admin
    if((uname == "admin" && pword == "admin123")) {
        userLogin = {"admin", "admin123", "Kantor Pusat", true};
        isLoggedIn = true;
        cout << "\n[Sukses] Selamat datang, Super Admin.\n";
        tungguEnter(); return;
    }

    for (auto& u : databaseUser) {
        if (u.username == uname && u.password == pword) {
            userLogin = u; isLoggedIn = true;
            cout << "\n[Sukses] Selamat datang Admin, " << userLogin.username << ".\n";
            tungguEnter(); return;
        }
    }
    cout << "\n[!] Username/Password salah atau belum terdaftar!"; tungguEnter();
}

// ==========================================
//              MENU UTAMA ADMIN
// ==========================================
void menuUtamaAdmin() {
    bersihkanLayar();
    int pilihan;
    cetakGaris(50, '=');
    cout << "          ADMIN TOKO CERAN_HUB\n";
    cetakGaris(50, '=');
    cout << "1. List Barang per Toko\n";
    cout << "2. Katalog & Tampilan Utama Marketplace\n";
    cout << "3. Laporan & Manajemen Keuangan Toko\n";
    cout << "4. Pengecekan Alamat User (Pemesan)\n";
    cout << "5. Pengecekan Barang yang Dibeli\n";
    cout << "6. Update Stok Pemasukan (Restock Toko)\n";
    cout << "7. Update Stok Pengeluaran (Buang/Retur Barang)\n";
    cout << "8. Pengaturan Struktur Toko & Produk (Tambah/Hapus)\n";
    cout << "9. Logout Kendali\n";
    cetakGaris(50, '-');
    cout << "Pilih menu: "; cin >> pilihan;

    if (cin.fail()) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "[!] Masukkan angka!\n"; tungguEnter(); return;
    }

    switch (pilihan) {
        case 1: tampilkanListBarangToko(); break;
        case 2: katalogUtamaMarketplace(); break;
        case 3: manajemenKeuanganToko(); break;
        case 4: cekAlamatPemesan(); break;
        case 5: cekBarangDibeli(); break;
        case 6: updateStokPemasukan(); break;
        case 7: updateStokPengeluaran(); break;
        case 8: panelManajemenToko(); break;
        case 9:
            isLoggedIn = false;
            cout << "\n[Sukses] Berhasil keluar dari panel admin.\n"; tungguEnter(); break;
        default: cout << "[!] Pilihan salah!\n"; tungguEnter();
    }
}

// 1. List Barang Toko
void tampilkanListBarangToko() {
    bersihkanLayar();
    if (daftarTokoMarketplace.empty()) {
        cout << "\n[!] Belum ada toko terdaftar.\n"; tungguEnter(); return;
    }

    cout << "=== DAFTAR TOKO AKTIF ===\n";
    for (const auto& t : daftarTokoMarketplace) {
        cout << "- [" << t.idToko << "] " << t.namaToko << " (" << t.kategoriDijual << ")\n";
    }

    int idCari;
    cout << "\nMasukkan ID Toko untuk melihat detail aset barang: "; cin >> idCari;

    for (const auto& t : daftarTokoMarketplace) {
        if (t.idToko == idCari) {
            bersihkanLayar();
            cetakGaris(80, '=');
            cout << "LIST BARANG TOKO: " << t.namaToko << "\n";
            cetakGaris(80, '=');
            cout << left << setw(8) << "ID" << setw(25) << "Nama Barang" << setw(15) << "Kategori" << setw(15) << "Harga Beli" << setw(12) << "Harga Jual" << "Stok" << endl;
            cetakGaris(80, '-');
            for (const auto& p : t.daftarProduk) {
                cout << left << setw(8) << p.id 
                     << setw(25) << p.nama 
                     << setw(15) << p.kategori 
                     << "Rp " << setw(12) << fixed << setprecision(0) << p.hargaBeli
                     << "Rp " << setw(9) << p.hargaJual 
                     << p.stok << " pcs" << endl;
            }
            tungguEnter(); return;
        }
    }
    cout << "[!] ID Toko tidak ditemukan.\n"; tungguEnter();
}

// ==========================================
//     FITUR KATALOG & TAMPILAN UTAMA
// ==========================================

// Menu utama fitur katalog
void katalogUtamaMarketplace() {
    int pil;
    do {
        bersihkanLayar();
        cout << "\033[1;35m";
        cetakGaris(73, '=');
        cout << "         KATALOG & TAMPILAN UTAMA MARKETPLACE CERAN_HUB\n";
        cetakGaris(73, '=');
        cout << "\033[0m";

        // Ringkasan singkat: total toko & total produk se-marketplace
        int totalProduk = 0;
        for (const auto& t : daftarTokoMarketplace) totalProduk += (int)t.daftarProduk.size();
        cout << "Total Toko Terdaftar : " << daftarTokoMarketplace.size() << " toko\n";
        cout << "Total Produk Beredar : " << totalProduk << " item\n";
        cetakGaris(73, '-');

        cout << "1. Tampilkan Semua Produk (Semua Toko)\n";
        cout << "2. Cari Produk Berdasarkan Nama\n";
        cout << "3. Filter Produk Berdasarkan Kategori\n";
        cout << "4. Kembali ke Menu Utama\n";
        cetakGaris(73, '-');
        cout << "Pilih menu (1-4): "; cin >> pil;

        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

        switch (pil) {
            case 1: tampilkanSemuaProdukKatalog(); break;
            case 2: cariProdukKatalog(); break;
            case 3: filterProdukPerKategori(); break;
            case 4: break;
            default: cout << "[!] Pilihan salah!\n"; tungguEnter();
        }
    } while (pil != 4);
}

// 2.1 Tampilkan seluruh produk dari seluruh toko sebagai "halaman utama" marketplace
void tampilkanSemuaProdukKatalog() {
    bersihkanLayar();
    cetakGaris(95, '=');
    cout << "                         ETALASE PRODUK - SEMUA TOKO\n";
    cetakGaris(95, '=');

    if (daftarTokoMarketplace.empty()) {
        cout << "[!] Belum ada toko/produk yang tersedia di marketplace.\n"; tungguEnter(); return;
    }

    cout << left << setw(18) << "Toko" << setw(22) << "Nama Produk" << setw(15) << "Kategori" 
         << setw(14) << "Harga Jual" << setw(10) << "Stok" << "Status" << endl;
    cetakGaris(95, '-');

    bool adaProduk = false;
    for (const auto& t : daftarTokoMarketplace) {
        for (const auto& p : t.daftarProduk) {
            adaProduk = true;
            string status = (p.stok > 0) ? "Tersedia" : "Habis";
            cout << left << setw(18) << t.namaToko 
                 << setw(22) << p.nama 
                 << setw(15) << p.kategori 
                 << "Rp " << setw(11) << fixed << setprecision(0) << p.hargaJual 
                 << setw(10) << (to_string(p.stok) + " pcs")
                 << status << endl;
        }
    }
    if (!adaProduk) cout << "[!] Belum ada produk yang didaftarkan di toko manapun.\n";
    cetakGaris(95, '=');
    tungguEnter();
}

// 2.2 Cari produk berdasarkan nama (keyword, case-insensitive, lintas toko)
void cariProdukKatalog() {
    bersihkanLayar();
    string keyword;
    cout << "=== CARI PRODUK (KATALOG MARKETPLACE) ===\n";
    cout << "Masukkan kata kunci nama produk: ";
    cin.ignore(1000, '\n');
    getline(cin, keyword);

    bersihkanLayar();
    cetakGaris(95, '=');
    cout << "HASIL PENCARIAN UNTUK: \"" << keyword << "\"\n";
    cetakGaris(95, '=');
    cout << left << setw(18) << "Toko" << setw(22) << "Nama Produk" << setw(15) << "Kategori" 
         << setw(14) << "Harga Jual" << setw(10) << "Stok" << "Status" << endl;
    cetakGaris(95, '-');

    bool ditemukan = false;
    for (const auto& t : daftarTokoMarketplace) {
        for (const auto& p : t.daftarProduk) {
            if (mengandung(p.nama, keyword)) {
                ditemukan = true;
                string status = (p.stok > 0) ? "Tersedia" : "Habis";
                cout << left << setw(18) << t.namaToko 
                     << setw(22) << p.nama 
                     << setw(15) << p.kategori 
                     << "Rp " << setw(11) << fixed << setprecision(0) << p.hargaJual 
                     << setw(10) << (to_string(p.stok) + " pcs")
                     << status << endl;
            }
        }
    }
    if (!ditemukan) cout << "[!] Tidak ada produk yang cocok dengan kata kunci tersebut.\n";
    cetakGaris(95, '=');
    tungguEnter();
}

// 2.3 Filter produk berdasarkan kategori
void filterProdukPerKategori() {
    bersihkanLayar();

    // Kumpulkan daftar kategori unik yang tersedia agar admin tahu pilihan apa saja
    vector<string> kategoriUnik;
    for (const auto& t : daftarTokoMarketplace) {
        for (const auto& p : t.daftarProduk) {
            bool sudahAda = false;
            for (const auto& k : kategoriUnik) {
                if (toLowerStr(k) == toLowerStr(p.kategori)) { sudahAda = true; break; }
            }
            if (!sudahAda) kategoriUnik.push_back(p.kategori);
        }
    }

    cout << "=== FILTER PRODUK BERDASARKAN KATEGORI ===\n";
    if (kategoriUnik.empty()) {
        cout << "[!] Belum ada kategori produk yang tersedia.\n"; tungguEnter(); return;
    }
    cout << "Kategori yang tersedia saat ini:\n";
    for (const auto& k : kategoriUnik) cout << " - " << k << "\n";
    cetakGaris(50, '-');

    string kategori;
    cout << "Masukkan nama kategori: ";
    cin.ignore(1000, '\n');
    getline(cin, kategori);

    bersihkanLayar();
    cetakGaris(95, '=');
    cout << "PRODUK DALAM KATEGORI: " << kategori << "\n";
    cetakGaris(95, '=');
    cout << left << setw(18) << "Toko" << setw(22) << "Nama Produk" << setw(15) << "Kategori" 
         << setw(14) << "Harga Jual" << setw(10) << "Stok" << "Status" << endl;
    cetakGaris(95, '-');

    bool ditemukan = false;
    for (const auto& t : daftarTokoMarketplace) {
        for (const auto& p : t.daftarProduk) {
            if (toLowerStr(p.kategori) == toLowerStr(kategori)) {
                ditemukan = true;
                string status = (p.stok > 0) ? "Tersedia" : "Habis";
                cout << left << setw(18) << t.namaToko 
                     << setw(22) << p.nama 
                     << setw(15) << p.kategori 
                     << "Rp " << setw(11) << fixed << setprecision(0) << p.hargaJual 
                     << setw(10) << (to_string(p.stok) + " pcs")
                     << status << endl;
            }
        }
    }
    if (!ditemukan) cout << "[!] Tidak ada produk dalam kategori tersebut.\n";
    cetakGaris(95, '=');
    tungguEnter();
}

// 2. Laporan & Manajemen Keuangan (Pemasukan, Pengeluaran, Pajak)
void manajemenKeuanganToko() {
    bersihkanLayar();
    int idT;
    cout << "=== MANAJEMEN KEUANGAN TOKO ===\n";
    cout << "Masukkan ID Toko: "; cin >> idT;

    for (auto& t : daftarTokoMarketplace) {
        if (t.idToko == idT) {
            bersihkanLayar();
            cetakGaris(50, '=');
            cout << "      LAPORAN KEUANGAN TOKO: " << t.namaToko << "\n";
            cetakGaris(50, '=');
            cout << " Saldo Kas Toko Saat Ini : Rp " << fixed << setprecision(0) << t.keuangan.saldoKas << endl;
            cout << " Total Pemasukan Bersih  : Rp " << t.keuangan.totalPemasukan << endl;
            cout << " Total Pengeluaran       : Rp " << t.keuangan.totalPengeluaran << endl;
            cout << " Alokasi Pajak (11%)     : Rp " << t.keuangan.totalPajak << endl;
            cetakGaris(50, '-');
            
            cout << "\n[PILIHAN MANAJEMEN KAS]\n";
            cout << "1. Suntik Modal / Tambah Kas Toko\n";
            cout << "2. Tarik Tunai Kas / Profit Toko\n";
            cout << "3. Kembali ke Menu\n";
            cout << "Pilih tindakan (1-3): ";
            int aksi; cin >> aksi;

            double nominal;
            if (aksi == 1) {
                cout << "Masukkan jumlah Dana Suntikan: Rp "; cin >> nominal;
                if(nominal > 0) {
                    t.keuangan.saldoKas += nominal;
                    cout << "[Sukses] Kas toko berhasil bertambah.\n";
                }
            } else if (aksi == 2) {
                cout << "Masukkan jumlah Penarikan Dana: Rp "; cin >> nominal;
                if(nominal <= t.keuangan.saldoKas && nominal > 0) {
                    t.keuangan.saldoKas -= nominal;
                    cout << "[Sukses] Penarikan kas berhasil dilakukan.\n";
                } else {
                    cout << "[!] Saldo kas toko tidak mencukupi.\n";
                }
            }
            tungguEnter(); return;
        }
    }
    cout << "[!] ID Toko salah.\n"; tungguEnter();
}

// 4. Pengecekan Alamat User yang Memesan
void cekAlamatPemesan() {
    bersihkanLayar();
    cout << "=== DAFTAR ALAMAT USER YANG MEMESAN ===\n";
    cetakGaris(85, '=');
    cout << left << setw(15) << "Nama User" << setw(35) << "Alamat Pengiriman" << setw(20) << "Produk Terpesan" << "Qty" << endl;
    cetakGaris(85, '-');
    
    if(riwayatPesanan.empty()) {
        cout << "                 Belum ada data pesanan masuk ke toko.\n";
    } else {
        for(const auto& rp : riwayatPesanan) {
            cout << left << setw(15) << rp.namaPembeli 
                 << setw(35) << rp.alamatPembeli 
                 << setw(20) << rp.namaProduk 
                 << rp.jumlah << " pcs" << endl;
        }
    }
    cetakGaris(85, '=');
    tungguEnter();
}

// ==========================================
//   FITUR PENGECEKAN BARANG YANG DIBELI
// ==========================================

// Menu utama fitur pengecekan barang dibeli
void cekBarangDibeli() {
    int pil;
    do {
        bersihkanLayar();
        cetakGaris(73, '=');
        cout << "            PENGECEKAN BARANG YANG DIBELI (RIWAYAT TRANSAKSI)\n";
        cetakGaris(73, '=');
        cout << "Total Transaksi Tercatat : " << riwayatPesanan.size() << " transaksi\n";
        cetakGaris(73, '-');
        cout << "1. Tampilkan Semua Riwayat Barang Dibeli\n";
        cout << "2. Cari Barang Dibeli Berdasarkan Nama Produk\n";
        cout << "3. Rekap Total Barang Terjual per Produk\n";
        cout << "4. Kembali ke Menu Utama\n";
        cetakGaris(73, '-');
        cout << "Pilih menu (1-4): "; cin >> pil;

        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

        switch (pil) {
            case 1: tampilkanSemuaRiwayatBeli(); break;
            case 2: cariBarangDibeliPerNama(); break;
            case 3: rekapTotalBarangTerjual(); break;
            case 4: break;
            default: cout << "[!] Pilihan salah!\n"; tungguEnter();
        }
    } while (pil != 4);
}

// 5.1 Tampilkan seluruh riwayat barang yang sudah dibeli
void tampilkanSemuaRiwayatBeli() {
    bersihkanLayar();
    cetakGaris(100, '=');
    cout << "                              RIWAYAT BARANG YANG DIBELI\n";
    cetakGaris(100, '=');
    cout << left << setw(15) << "Pembeli" << setw(18) << "Toko" << setw(20) << "Produk Dibeli" 
         << setw(8) << "Qty" << "Total Bayar" << endl;
    cetakGaris(100, '-');

    if (riwayatPesanan.empty()) {
        cout << "[!] Belum ada barang yang dibeli / transaksi tercatat.\n";
    } else {
        double grandTotal = 0;
        for (const auto& rp : riwayatPesanan) {
            cout << left << setw(15) << rp.namaPembeli 
                 << setw(18) << rp.namaToko 
                 << setw(20) << rp.namaProduk 
                 << setw(8) << (to_string(rp.jumlah) + " pcs")
                 << "Rp " << fixed << setprecision(0) << rp.totalBayar << endl;
            grandTotal += rp.totalBayar;
        }
        cetakGaris(100, '-');
        cout << "Total Keseluruhan Transaksi Pembelian : Rp " << fixed << setprecision(0) << grandTotal << endl;
    }
    cetakGaris(100, '=');
    tungguEnter();
}

// 5.2 Cari riwayat pembelian berdasarkan nama produk (keyword, case-insensitive)
void cariBarangDibeliPerNama() {
    bersihkanLayar();
    string keyword;
    cout << "=== CARI BARANG DIBELI BERDASARKAN NAMA PRODUK ===\n";
    cout << "Masukkan nama produk yang dicari: ";
    cin.ignore(1000, '\n');
    getline(cin, keyword);

    bersihkanLayar();
    cetakGaris(100, '=');
    cout << "HASIL PENCARIAN BARANG DIBELI UNTUK: \"" << keyword << "\"\n";
    cetakGaris(100, '=');
    cout << left << setw(15) << "Pembeli" << setw(18) << "Toko" << setw(20) << "Produk Dibeli" 
         << setw(8) << "Qty" << "Total Bayar" << endl;
    cetakGaris(100, '-');

    bool ditemukan = false;
    for (const auto& rp : riwayatPesanan) {
        if (mengandung(rp.namaProduk, keyword)) {
            ditemukan = true;
            cout << left << setw(15) << rp.namaPembeli 
                 << setw(18) << rp.namaToko 
                 << setw(20) << rp.namaProduk 
                 << setw(8) << (to_string(rp.jumlah) + " pcs")
                 << "Rp " << fixed << setprecision(0) << rp.totalBayar << endl;
        }
    }
    if (!ditemukan) cout << "[!] Tidak ditemukan riwayat pembelian untuk produk tersebut.\n";
    cetakGaris(100, '=');
    tungguEnter();
}

// 5.3 Rekap total barang terjual per produk (agregasi qty & total omzet)
void rekapTotalBarangTerjual() {
    bersihkanLayar();
    cetakGaris(80, '=');
    cout << "               REKAP TOTAL BARANG TERJUAL PER PRODUK\n";
    cetakGaris(80, '=');

    if (riwayatPesanan.empty()) {
        cout << "[!] Belum ada data transaksi untuk direkap.\n"; tungguEnter(); return;
    }

    // Agregasi jumlah & omzet per nama produk menggunakan map
    map<string, int> totalQty;
    map<string, double> totalOmzet;
    for (const auto& rp : riwayatPesanan) {
        totalQty[rp.namaProduk] += rp.jumlah;
        totalOmzet[rp.namaProduk] += rp.totalBayar;
    }

    cout << left << setw(25) << "Nama Produk" << setw(20) << "Total Terjual" << "Total Omzet" << endl;
    cetakGaris(80, '-');
    for (const auto& item : totalQty) {
        cout << left << setw(25) << item.first 
             << setw(20) << (to_string(item.second) + " pcs")
             << "Rp " << fixed << setprecision(0) << totalOmzet[item.first] << endl;
    }
    cetakGaris(80, '=');
    tungguEnter();
}

// 6. Update Stok Pemasukan per Toko (Restock Dagangan)
void updateStokPemasukan() {
    bersihkanLayar(); 
    int idP, jml;
    cout << "=== UPDATE STOK PEMASUKAN (RESTOCK) ===\n";
    cout << "Masukkan ID Produk: "; cin >> idP;
    
    for (auto& t : daftarTokoMarketplace) {
        for (auto& p : t.daftarProduk) {
            if (p.id == idP) {
                cout << "Produk Ditemukan: " << p.nama << " (Stok saat ini: " << p.stok << ")\n";
                cout << "Jumlah Stok Masuk Baru: "; cin >> jml;
                
                if(jml > 0) {
                    double totalBiaya = p.hargaBeli * jml;
                    if(t.keuangan.saldoKas >= totalBiaya) {
                        p.stok += jml;
                        t.keuangan.saldoKas -= totalBiaya; 
                        t.keuangan.totalPengeluaran += totalBiaya; 
                        
                        cout << "\n[Sukses] Restock berhasil!\n";
                        cout << "Kas toko berkurang sebesar Rp " << fixed << setprecision(0) << totalBiaya << " untuk biaya beli barang.\n";
                    } else {
                        cout << "\n[!] Gagal! Saldo kas toko tidak cukup untuk membeli stok baru.\n";
                        cout << "Dibutuhkan: Rp " << totalBiaya << " | Kas Toko: Rp " << t.keuangan.saldoKas << endl;
                    }
                }
                tungguEnter(); return;
            }
        }
    }
    cout << "[!] ID Produk tidak valid.\n"; tungguEnter();
}

// 7. Update Stok Pengeluaran per Toko (Retur / Barang Rusak / Terjual)
void updateStokPengeluaran() {
    bersihkanLayar(); 
    int idP, jml;
    cout << "=== UPDATE STOK PENGELUARAN (PENGURANGAN) ===\n";
    cout << "Masukkan ID Produk: "; cin >> idP;
    
    for (auto& t : daftarTokoMarketplace) {
        for (auto& p : t.daftarProduk) {
            if (p.id == idP) {
                cout << "Produk Ditemukan: " << p.nama << " (Stok saat ini: " << p.stok << ")\n";
                cout << "1. Pengurangan karena Terjual (Menghasilkan Uang)\n";
                cout << "2. Pengurangan karena Rusak/Retur/Kedaluwarsa (Rugi)\n";
                cout << "Pilih Alasan Pengeluaran (1-2): "; 
                int alasan; cin >> alasan;
                
                cout << "Jumlah Stok Keluar: "; cin >> jml;
                
                if (p.stok >= jml && jml > 0) {
                    p.stok -= jml;
                    if (alasan == 1) {
                        double pendapatan_bruto = p.hargaJual * jml;
                        double pajak = pendapatan_bruto * 0.11; // Simulasi Pajak 11%
                        double neto = pendapatan_bruto - pajak;
                        
                        t.keuangan.saldoKas += neto;
                        t.keuangan.totalPemasukan += neto;
                        t.keuangan.totalPajak += pajak;
                        
                        cout << "\n[Sukses] Stok dikurangi karena penjualan.\n";
                        cout << "Kas masuk (bersih setelah pajak 11%): +Rp " << fixed << setprecision(0) << neto << endl;
                    } else {
                        cout << "\n[Sukses] Stok dikurangi tanpa pemasukan (Kategori kerugian/rusak).\n";
                    }
                } else {
                    cout << "\n[!] Jumlah pengeluaran tidak valid atau stok tidak cukup.\n";
                }
                tungguEnter(); return;
            }
        }
    }
    cout << "[!] ID Produk tidak valid.\n"; tungguEnter();
}

// ==========================================
//          SISTEM STRUKTUR TOKO
// ==========================================
void panelManajemenToko() {
    int pil;
    do {
        bersihkanLayar();
        cout << "=== PANEL REGISTRASI STRUKTUR TOKO ===\n";
        cout << "1. Tambah Toko Baru\n2. Hapus Toko Lama\n3. Daftarkan Produk Baru Ke Toko\n4. Hapus Produk Dari Toko\n5. Kembali ke Panel Utama\nPilih tindakan: "; cin >> pil;

        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); continue; }
        switch (pil) {
            case 1: tambahTokoBaru(); break;
            case 2: hapusToko(); break;
            case 3: tambahProdukKeToko(); break;
            case 4: hapusProduk(); break;
        }
    } while (pil != 5);
}

void tambahTokoBaru() {
    bersihkanLayar(); Toko t;
    cout << "ID Toko Baru (Angka): "; cin >> t.idToko;
    cin.ignore(1000, '\n');
    cout << "Nama Toko Baru      : "; getline(cin, t.namaToko);
    cout << "Kategori Utama Jual : "; getline(cin, t.kategoriDijual);
    
    // Set keuangan dasar toko baru
    t.ratingToko = 5.0; t.jumlahUlasan = 0;
    t.keuangan = {0, 0, 0, 0}; // Kas mula-mula kosong
    
    daftarTokoMarketplace.push_back(t);
    cout << "\n[Sukses] Toko baru berhasil didaftarkan ke jaringan.\n"; tungguEnter();
}

void hapusToko() {
    bersihkanLayar(); int id;
    cout << "Masukkan ID Toko yang mau dihapus: "; cin >> id;
    for (auto it = daftarTokoMarketplace.begin(); it != daftarTokoMarketplace.end(); ++it) {
        if (it->idToko == id) {
            daftarTokoMarketplace.erase(it);
            cout << "[Sukses] Jaringan toko berhasil dihapus dari sistem.\n"; tungguEnter(); return;
        }
    }
    cout << "[!] Gagal menghapus. ID Toko tidak valid.\n"; tungguEnter();
}

void tambahProdukKeToko() {
    bersihkanLayar(); int idT;
    cout << "Masukkan ID Toko tujuan: "; cin >> idT;
    for (auto& t : daftarTokoMarketplace) {
        if (t.idToko == idT) {
            Produk p;
            cout << "ID Produk Baru (Angka): "; cin >> p.id;
            cin.ignore(1000, '\n');
            cout << "Nama Barang           : "; getline(cin, p.nama);
            cout << "Kategori Barang       : "; getline(cin, p.kategori);
            cout << "Harga Modal (Beli)    : Rp "; cin >> p.hargaBeli;
            cout << "Harga Jual Konsumen   : Rp "; cin >> p.hargaJual;
            cout << "Stok Awal             : "; cin >> p.stok;
            t.daftarProduk.push_back(p);
            cout << "\n[Sukses] Produk terintegrasi ke dalam toko.\n"; tungguEnter(); return;
        }
    }
    cout << "[!] ID Toko salah.\n"; tungguEnter();
}

void hapusProduk() {
    bersihkanLayar(); int idP;
    cout << "Masukkan ID Produk yang mau dihapus: "; cin >> idP;
    for (auto& t : daftarTokoMarketplace) {
        for (auto it = t.daftarProduk.begin(); it != t.daftarProduk.end(); ++it) {
            if (it->id == idP) {
                t.daftarProduk.erase(it);
                cout << "[Sukses] SKU Produk berhasil ditiadakan.\n"; tungguEnter(); return;
            }
        }
    }
    cout << "[!] ID Produk tidak ditemukan.\n"; tungguEnter();
}
