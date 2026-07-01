#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// Batasan ukuran array manual karena tidak boleh pakai vector
const int MAKS_PRODUK = 5;
const int MAKS_TOKO = 40;
const int MAKS_KERANJANG = 20;

// Fungsi pembantu untuk mengubah string menjadi lowercase (Pengganti std::transform)
string keBawah(string teks) {
    string hasil = "";
    for (size_t i = 0; i < teks.length(); i++) {
        char c = teks[i];
        if (c >= 'A' && c <= 'Z') {
            hasil += (c + 32);
        } else {
            hasil += c;
        }
    }
    return hasil;
}

// Fungsi pembantu untuk mencari substring (Pengganti string::find manual agar lebih aman)
bool mengandungKata(string teksUtama, string kataKunci) {
    string utama = keBawah(teksUtama);
    string kunci = keBawah(kataKunci);
    if (kunci.length() > utama.length()) return false;
    
    for (size_t i = 0; i <= utama.length() - kunci.length(); i++) {
        size_t j;
        for (j = 0; j < kunci.length(); j++) {
            if (utama[i + j] != kunci[j]) break;
        }
        if (j == kunci.length()) return true;
    }
    return false;
}

// Struct untuk menangani Tanggal dan Waktu
struct WaktuTransaksi {
    int tanggal;
    int bulan;
    int tahun;
    int jam;
    int menit;
    int detik;

    void setWaktuSekarang() {
        time_t t = time(0);
        tm* now = localtime(&t);
        tanggal = now->tm_mday;
        bulan = now->tm_mon + 1;
        tahun = now->tm_year + 1900;
        jam = now->tm_hour;
        menit = now->tm_min;
        detik = now->tm_sec;
    }

    void cetakWaktu() const {
        cout << setfill('0') << setw(4) << tahun << "-" 
             << setw(2) << bulan << "-" << setw(2) << tanggal << " "
             << setw(2) << jam << ":" << setw(2) << menit << ":" << setw(2) << detik << endl;
    }
};

// Class 1: Produk
class Produk {
public:
    string idProduk;
    string namaProduk;
    int stok;
    double harga;

    // Default constructor untuk array
    Produk() : idProduk(""), namaProduk(""), stok(0), harga(0.0) {}

    Produk(string id, string nama, int s, double h) 
        : idProduk(id), namaProduk(nama), stok(s), harga(h) {}

    void tambahStok(int jumlah) { stok += jumlah; }
    void kurangiStok(int jumlah) { if (stok >= jumlah) stok -= jumlah; }
};

// Class 2: Toko
class Toko {
public:
    string idToko;
    string namaToko;
    string kategori;
    Produk daftarBarang[MAKS_PRODUK];
    int jumlahProduk;

    Toko() : idToko(""), namaToko(""), kategori(""), jumlahProduk(0) {}

    Toko(string id, string nama, string kat) : idToko(id), namaToko(nama), kategori(kat), jumlahProduk(0) {}

    void tambahProdukBaru(Produk p) {
        if (jumlahProduk < MAKS_PRODUK) {
            daftarBarang[jumlahProduk] = p;
            jumlahProduk++;
        }
    }

    void cetakKatalog() {
        cout << "\n=== KATALOG TOKO: " << namaToko << " ===\n";
        cout << "Kategori: " << kategori << "\n";
        for (int i = 0; i < jumlahProduk; ++i) {
            cout << i + 1 << ". [" << daftarBarang[i].idProduk << "] " 
                 << daftarBarang[i].namaProduk << " | Harga: Rp" << daftarBarang[i].harga 
                 << " | Stok: " << daftarBarang[i].stok << "\n";
        }
    }
};

// Struct ItemKeranjang untuk menggantikan std::pair
struct ItemKeranjang {
    Produk produk;
    int kuantitas;
};

// Class 3: Pelanggan
class Pelanggan {
private:
    string username;
    string password;
public:
    string nik;
    string nama;
    string alamat;
    double saldoWallet;
    ItemKeranjang keranjang[MAKS_KERANJANG];
    int jumlahItemKeranjang;

    Pelanggan() : username(""), password(""), nik(""), nama(""), alamat(""), saldoWallet(0), jumlahItemKeranjang(0) {}

    Pelanggan(string user, string pass, string n, string nm, string al, double saldo) 
        : username(user), password(pass), nik(n), nama(nm), alamat(al), saldoWallet(saldo), jumlahItemKeranjang(0) {}

    bool otentikasi(string user, string pass) {
        return (username == user && password == pass);
    }

    void tampilkanProfil() {
        cout << "\n=== PROFIL PELANGGAN & DIGITAL WALLET ===\n";
        cout << "NIK          : " << nik << "\n";
        cout << "Nama         : " << nama << "\n";
        cout << "Alamat       : " << alamat << "\n";
        cout << "Saldo Wallet : Rp" << fixed << setprecision(0) << saldoWallet << "\n";
    }

    void isiSaldo(double jumlah) {
        if (jumlah > 0) {
            saldoWallet += jumlah;
            cout << "Berhasil Top Up! Saldo Anda sekarang: Rp" << fixed << setprecision(0) << saldoWallet << "\n";
        }
    }

    void kurangiSaldo(double jumlah) {
        saldoWallet -= jumlah;
    }

    void kosongkanKeranjang() {
        jumlahItemKeranjang = 0;
    }
};

// Class 4: Admin
class Admin {
public:
    string idAdmin;
    string kunciKeamanan;

    Admin(string id, string kunci) : idAdmin(id), kunciKeamanan(kunci) {}

    void pantauKeuangan(double totalSirkulasi) {
        cout << "\n[AUDIT ADMIN] Total sirkulasi keuangan mall saat ini: Rp" << fixed << setprecision(0) << totalSirkulasi << endl;
    }
};

int main() {
    double totalSirkulasiFinansial = 0;
    Admin adminUtama("ADM01", "CERAN2026");
    
    // Inisialisasi Database User (Sistem Autentikasi)
    Pelanggan daftarUser[2] = {
        Pelanggan("arya123", "jogja2026", "3404123456789", "Arya Randani", "Sleman, Yogyakarta", 5000000),
        Pelanggan("user2", "pass2", "3404987654321", "Budi Santoso", "Bantul, Yogyakarta", 100000)
    };
    
    Pelanggan userSekarang;
    bool sedangLogin = false;

    // Inisialisasi Database Merchant Mall secara Manual (Array Statis)
    Toko daftarTokoMall[MAKS_TOKO];
    int totalToko = 0;

    // 1. Fashion, Pakaian & Department Store
    daftarTokoMall[totalToko++] = Toko("T01", "Uniqlo", "Fashion, Pakaian & Department Store (Kasual & Lifewear)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P01", "Kemeja Flanel", 20, 399000));
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P02", "AIRism T-Shirt", 50, 199000));

    // Kode ditambahkan di sini, sisa inisialisasi awal tetap dipertahankan
    daftarTokoMall[totalToko++] = Toko("T02", "H&M", "Fashion, Pakaian & Department Store (Trendi & Aksesoris)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P03", "Hoodie Regular", 15, 449000));

    daftarTokoMall[totalToko++] = Toko("T03", "Matahari Department Store", "Fashion, Pakaian & Department Store (Kebutuhan Keluarga)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P04", "Sepatu Casual", 30, 299000));

    daftarTokoMall[totalToko++] = Toko("T04", "The Executive", "Fashion, Pakaian & Department Store (Formal & Kerja)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P05", "Blazer Formal", 10, 799000));

    daftarTokoMall[totalToko++] = Toko("T05", "Baleno", "Fashion, Pakaian & Department Store (Kasual Pria/Wanita)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P06", "Kaos Polo Baleno", 25, 249000));

    daftarTokoMall[totalToko++] = Toko("T06", "Batik Keris", "Fashion, Pakaian & Department Store (Batik & Kerajinan)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P07", "Kemeja Batik Sutra", 12, 550000));

    daftarTokoMall[totalToko++] = Toko("T07", "Aigner & Armani", "Fashion, Pakaian & Department Store (High-End Mewah)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P08", "Leather Bag Luxury", 3, 15000000));

    // 2. Sepatu, Tas & Aksesoris Olahraga
    daftarTokoMall[totalToko++] = Toko("T08", "Adidas", "Sports & Footwear");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P09", "Ultraboost Running", 8, 2200000));

    daftarTokoMall[totalToko++] = Toko("T09", "Asics", "Sports & Footwear");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P10", "Asics Gel-Kayano", 10, 2400000));

    daftarTokoMall[totalToko++] = Toko("T10", "Arena", "Sports & Footwear (Perlengkapan Renang)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P11", "Kacamata Renang Pro", 15, 350000));

    daftarTokoMall[totalToko++] = Toko("T11", "Aldo & Bellagio", "Sports & Footwear (Tas & Sepatu Wanita)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P12", "High Heels Bellagio", 14, 459000));

    daftarTokoMall[totalToko++] = Toko("T12", "Bags City", "Sports & Footwear (Koper & Ransel)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P13", "Koper Kabin 20 Inch", 7, 1200000));

    // 3. Gadget, Elektronik & Kamera
    daftarTokoMall[totalToko++] = Toko("T13", "Erafone", "Gadget, Elektronik & Kamera");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P14", "Smartphone Flagship", 6, 12499000));

    daftarTokoMall[totalToko++] = Toko("T14", "Samsung Store / Xiaomi Store", "Gadget, Elektronik & Kamera");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P15", "Smart Ecosystem TV", 5, 4500000));

    // Metode pembayaran e-wallet seperti gopay dana paypal shopeepay qris indomaret alfamart bank va
    daftarTokoMall[totalToko++] = Toko("T15", "Bli-Bli Tukar Tambah", "Gadget, Elektronik & Kamera (Layanan TT)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P16", "Voucher Tukar Tambah", 100, 500000));

    // 4. Perangkat Rumah Tangga & Gaya Hidup
    daftarTokoMall[totalToko++] = Toko("T16", "Ace Hardware", "Home Living & Hobbies");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P17", "Set Obeng Serbaguna", 20, 145000));

    daftarTokoMall[totalToko++] = Toko("T17", "Informa", "Home Living & Hobbies (Furnitur & Interior)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P18", "Kursi Kerja Ergonomis", 8, 1100000));

    daftarTokoMall[totalToko++] = Toko("T18", "Gramedia", "Home Living & Hobbies (Buku & Alat Tulis)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P19", "Buku Struktur Data C++", 25, 95000));

    // 5. Kesehatan, Kecantikan & Perawatan Tubuh
    daftarTokoMall[totalToko++] = Toko("T19", "Bath & Body Works", "Kesehatan, Kecantikan & Perawatan Tubuh");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P20", "Lilin Aromaterapi", 30, 280000));

    daftarTokoMall[totalToko++] = Toko("T20", "Watsons / Guardian", "Kesehatan, Kecantikan & Perawatan Tubuh");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P21", "Sunscreen SPF 50", 50, 85000));

    daftarTokoMall[totalToko++] = Toko("T21", "Sociolla / Sephora", "Kesehatan, Kecantikan & Perawatan Tubuh");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P22", "Skincare Serum", 20, 195000));

    // 6. Hiburan & Area Bermain
    daftarTokoMall[totalToko++] = Toko("T22", "CGV Cinemas", "Entertainment");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P23", "Tiket Studio Reguler", 100, 45000));

    daftarTokoMall[totalToko++] = Toko("T23", "Timezone / Funworld", "Entertainment (Arcade)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P24", "Powercard Top Up 200k", 200, 200000));

    // 7. Supermarket & Kebutuhan Harian
    daftarTokoMall[totalToko++] = Toko("T24", "Hypermart", "Supermarket & Kebutuhan Harian");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P25", "Minyak Goreng 2L", 40, 36000));

    // 8. Kuliner
    daftarTokoMall[totalToko++] = Toko("T25", "Marugame Udon", "Food & Beverages (Restoran Besar)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P26", "Niku Udon", 40, 62000));

    daftarTokoMall[totalToko++] = Toko("T26", "Burger King / KFC", "Food & Beverages (Cepat Saji)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P27", "Paket Ayam + Nasi", 80, 35000));

    daftarTokoMall[totalToko++] = Toko("T27", "Starbucks", "Food & Beverages (Kafe)");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P28", "Caffe Latte Venti", 30, 58000));

    daftarTokoMall[totalToko++] = Toko("T28", "Bakpia Kukus Tugu Jogja", "Oleh-oleh / Kuliner Lokal");
    daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P29", "Bakpia Kukus Kotak 10", 60, 45000));

    // --- SISTEM LOGIN/AUTENTIKASI AWAL ---
    cout << "=========================================\n";
    cout << "         LOGIN SYSTEM CERAN_HUB MALL       \n";
    cout << "=========================================\n";
    while (!sedangLogin) {
        string inpUser, inpPass;
        cout << "Masukkan Username: ";
        cin >> inpUser;
        cout << "Masukkan Password: ";
        cin >> inpPass;

        for (int i = 0; i < 2; i++) {
            if (daftarUser[i].otentikasi(inpUser, inpPass)) {
                userSekarang = daftarUser[i];
                sedangLogin = true;
                break;
            }
        }
        if (!sedangLogin) {
            cout << "Username atau Password salah! Silakan coba lagi.\n\n";
        }
    }

    // --- LOOP MENU UTAMA INTERAKTIF ---
    int pilihanMenu;
    do {
        cout << "\n=========================================\n";
        cout << "         WELCOME TO CERAN_HUB MALL        \n";
        cout << "=========================================\n";
        cout << "Loged in as: " << userSekarang.nama << "\n";
        cout << "1. Lihat Profil & Fitur Dompet Digital (Wallet)\n";
        cout << "2. Cari Toko (Keyword Search Manual)\n";
        cout << "3. Pilih Toko & Masukkan Keranjang Belanja\n";
        cout << "4. Fitur Pembayaran / Checkout & Cetak Struk\n";
        cout << "5. Menu Admin (Audit Keuangan)\n";
        cout << "6. Keluar Aplikasi\n";
        cout << "Pilihan Anda: ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                userSekarang.tampilkanProfil();
                cout << "\nApakah ingin Top Up Saldo Wallet? (y/n): ";
                char opsi;
                cin >> opsi;
                if (opsi == 'y' || opsi == 'Y') {
                    double nominal;
                    cout << "Masukkan nominal Top Up: Rp";
                    cin >> nominal;
                    
                    cout << "\n=== PILIH METODE TOP UP SALDO ===\n";
                    cout << "1. Bank Virtual Account (VA)\n";
                    cout << "2. Indomaret\n";
                    cout << "3. Alfamart\n";
                    cout << "4. GoPay\n";
                    cout << "5. DANA\n";
                    cout << "6. PayPal\n";
                    cout << "7. ShopeePay\n";
                    cout << "8. QRIS (Scan dan Bayar)\n";
                    cout << "Pilihan Metode: ";
                    int mTopUp;
                    cin >> mTopUp;
                    
                    int statusProses = 1; 
                    switch (mTopUp) {
                        case 1:
                            cout << "\n[BANK VIRTUAL ACCOUNT]\n";
                            cout << "Pilih Bank:\n1. BRI\n2. BCA\n3. Mandiri\n4. BNI\nPilihan Bank: ";
                            int subBank;
                            cin >> subBank;
                            switch (subBank) {
                                case 1: cout << "Nomor VA BRI Anda: 88810" << userSekarang.nik.substr(0, 5) << "\n"; break;
                                case 2: cout << "Nomor VA BCA Anda: 39010" << userSekarang.nik.substr(0, 5) << "\n"; break;
                                case 3: cout << "Nomor VA Mandiri Anda: 89608" << userSekarang.nik.substr(0, 5) << "\n"; break;
                                case 4: cout << "Nomor VA BNI Anda: 82410" << userSekarang.nik.substr(0, 5) << "\n"; break;
                                default: cout << "Bank tidak tersedia.\n"; statusProses = 0; break;
                            }
                            break;
                        case 2:
                            cout << "\n[GERAI INDOMARET]\n";
                            cout << "Kode Pembayaran Indomaret: IDM" << userSekarang.nik.substr(2, 6) << "\n";
                            cout << "Silakan tunjukkan kode ini ke kasir Indomaret terdekat.\n";
                            break;
                        case 3:
                            cout << "\n[GERAI ALFAMART]\n";
                            cout << "Kode Pembayaran Alfamart: ALFA" << userSekarang.nik.substr(1, 6) << "\n";
                            cout << "Silakan tunjukkan kode ini ke kasir Alfamart terdekat.\n";
                            break;
                        case 4:
                            cout << "\n[E-WALLET GOPAY]\n";
                            cout << "Menghubungkan ke aplikasi Gojek...\n";
                            cout << "Masukkan Nomor HP GoPay Anda: ";
                            char noGopay[20]; cin >> noGopay;
                            cout << "Permintaan bayar dikirim ke aplikasi Anda.\n";
                            break;
                        case 5:
                            cout << "\n[E-WALLET DANA]\n";
                            cout << "Membuka gerbang pembayaran DANA...\n";
                            cout << "Masukkan Nomor ID DANA Anda: ";
                            char noDana[20]; cin >> noDana;
                            cout << "Silakan konfirmasi PIN pada pop-up smartphone Anda.\n";
                            break;
                        case 6:
                            cout << "\n[PAYPAL GLOBAL PAYMENT]\n";
                            cout << "Kurs konversi otomatis diterapkan ke USD.\n";
                            cout << "Masukkan Email PayPal Anda: ";
                            char emailPaypal[40]; cin >> emailPaypal;
                            cout << "Otentikasi tagihan internasional berhasil.\n";
                            break;
                        case 7:
                            cout << "\n[E-WALLET SHOPEEPAY]\n";
                            cout << "Membuka Aplikasi Shopee...\n";
                            cout << "Masukkan Username Shopee: ";
                            char userShopee[30]; cin >> userShopee;
                            cout << "Notifikasi tagihan telah dikirim ke akun ShopeePay Anda.\n";
                            break;
                        case 8:
                            cout << "\n[QRIS - AUTOMATIC SCANNER]\n";
                            cout << "###########################\n";
                            cout << "##   [QRIS BARCODE SCAN] ##\n";
                            cout << "##    CERAN_HUB DYNAMIC  ##\n";
                            cout << "###########################\n";
                            cout << "Silakan scan kode QR di atas menggunakan aplikasi finansial Anda.\n";
                            break;
                        default:
                            cout << "Pilihan metode top up tidak valid!\n";
                            statusProses = 0;
                            break;
                    }
                    
                    switch (statusProses) {
                        case 1:
                            cout << "Tekan 1 untuk menyelesaikan proses verifikasi pembayaran: ";
                            int verif; cin >> verif;
                            switch (verif) {
                                case 1:
                                    userSekarang.isiSaldo(nominal);
                                    break;
                                default:
                                    cout << "Verifikasi gagal! Top up dibatalkan.\n";
                                    break;
                            }
                            break;
                        case 0:
                        default:
                            break;
                    }
                }
                break;
            }
            case 2: {
                string kataKunci;
                cout << "\nMasukkan kata kunci pencarian toko/kategori (contoh: 'Batik', 'Udon', 'Gadget'): ";
                cin.ignore();
                getline(cin, kataKunci);

                cout << "\n--- HASIL PENCARIAN KATA KUNCI '" << kataKunci << "' ---\n";
                bool ditemukan = false;
                for (int i = 0; i < totalToko; ++i) {
                    if (mengandungKata(daftarTokoMall[i].namaToko, kataKunci) || 
                        mengandungKata(daftarTokoMall[i].kategori, kataKunci)) {
                        cout << "- [" << daftarTokoMall[i].idToko << "] " << daftarTokoMall[i].namaToko 
                             << " | " << daftarTokoMall[i].kategori << "\n";
                        ditemukan = true;
                    }
                }
                if (!ditemukan) cout << "Toko atau kategori tidak ditemukan.\n";
                break;
            }
            case 3: {
                cout << "\n--- DAFTAR GERAI MERCHANT DI MALL ---\n";
                for (int i = 0; i < totalToko; ++i) {
                    cout << i + 1 << ". " << daftarTokoMall[i].namaToko << "\n";
                }
                cout << "Pilih nomor toko: ";
                int indeksToko;
                cin >> indeksToko;

                if (indeksToko > 0 && indeksToko <= totalToko) {
                    Toko& tokoTerpilih = daftarTokoMall[indeksToko - 1];
                    tokoTerpilih.cetakKatalog();

                    cout << "\nPilih nomor barang yang ingin dimasukkan keranjang: ";
                    int indeksBarang;
                    cin >> indeksBarang;

                    if (indeksBarang > 0 && indeksBarang <= tokoTerpilih.jumlahProduk) {
                        Produk& produkTerpilih = tokoTerpilih.daftarBarang[indeksBarang - 1];
                        cout << "Masukkan Jumlah (Qty): ";
                        int qty;
                        cin >> qty;

                        if (qty <= produkTerpilih.stok) {
                            produkTerpilih.kurangiStok(qty);
                            userSekarang.tambahKeranjang(produkTerpilih, qty);
                        } else {
                            cout << "X Stok tidak mencukupi! Sisa stok: " << produkTerpilih.stok << endl;
                        }
                    }
                }
                break;
            }
            case 4: {
                if (userSekarang.jumlahItemKeranjang == 0) {
                    cout << "X Keranjang belanja Anda masih kosong!\n";
                    break;
                }

                double totalBelanja = 0;
                for (int i = 0; i < userSekarang.jumlahItemKeranjang; ++i) {
                    totalBelanja += userSekarang.keranjang[i].produk.harga * userSekarang.keranjang[i].kuantitas;
                }

                double pajak = totalBelanja * 0.11; 
                double totalAkhir = totalBelanja + pajak;

                cout << "\n--- KONFIRMASI PEMBAYARAN ---\n";
                cout << "Total Belanja : Rp" << fixed << setprecision(0) << totalBelanja << "\n";
                cout << "Pajak (PPN 11%): Rp" << pajak << "\n";
                cout << "Total Tagihan : Rp" << totalAkhir << "\n";
                
                cout << "\nPILIK METODE PEMBAYARAN TRANSAKSI:\n";
                cout << "1. Bayar Menggunakan Saldo Digital Wallet Terintegrasi\n";
                cout << "2. Direct Bank Virtual Account (VA)\n";
                cout << "3. Direct Over-The-Counter Indomaret\n";
                cout << "4. Direct Over-The-Counter Alfamart\n";
                cout << "5. Direct E-Wallet GoPay\n";
                cout << "6. Direct E-Wallet DANA\n";
                cout << "7. Direct PayPal Account Gateway\n";
                cout << "8. Direct E-Wallet ShopeePay\n";
                cout << "9. Direct QRIS Universal Scan\n";
                cout << "Pilihan Anda: ";
                int metodeBayar;
                cin >> metodeBayar;

                int pembayaranSukses = 0;
                string labelMetode = "";

                switch (metodeBayar) {
                    case 1:
                        labelMetode = "Digital Wallet (Internal)";
                        if (userSekarang.saldoWallet >= totalAkhir) {
                            userSekarang.kurangiSaldo(totalAkhir);
                            pembayaranSukses = 1;
                        } else {
                            cout << "X Saldo Wallet internal Anda tidak mencukupi! Silakan isi saldo dulu.\n";
                        }
                        break;
                    case 2:
                        labelMetode = "Direct Bank VA";
                        cout << "[DIRECT BANK VA] Masukkan nomor rekening VA tujuan transfer Anda untuk validasi otomatis: ";
                        char inputVA[30]; cin >> inputVA;
                        pembayaranSukses = 1;
                        break;
                    case 3:
                        labelMetode = "Direct Indomaret";
                        cout << "[DIRECT INDOMARET] Harap selesaikan pembayaran di kasir dengan Kode: TRM" << userSekarang.nik.substr(4, 5) << "\n";
                        pembayaranSukses = 1;
                        break;
                    case 4:
                        labelMetode = "Direct Alfamart";
                        cout << "[DIRECT ALFAMART] Harap selesaikan pembayaran di kasir dengan Kode: TRMA" << userSekarang.nik.substr(5, 5) << "\n";
                        pembayaranSukses = 1;
                        break;
                    case 5:
                        labelMetode = "Direct GoPay";
                        cout << "[DIRECT GOPAY] Masukkan PIN Keamanan GoPay Anda untuk menyetujui transaksi: ";
                        char pinGopay[10]; cin >> pinGopay;
                        pembayaranSukses = 1;
                        break;
                    case 6:
                        labelMetode = "Direct DANA";
                        cout << "[DIRECT DANA] Masukkan OTP yang dikirim ke nomor handphone terdaftar Anda: ";
                        char otpDana[10]; cin >> otpDana;
                        pembayaranSukses = 1;
                        break;
                    case 7:
                        labelMetode = "Direct PayPal Account";
                        cout << "[DIRECT PAYPAL] Memproses pemotongan dana internasional terotentikasi aman...\n";
                        pembayaranSukses = 1;
                        break;
                    case 8:
                        labelMetode = "Direct ShopeePay";
                        cout << "[DIRECT SHOPEEPAY] Scan wajah / sidik jari pada perangkat seluler Anda...\n";
                        pembayaranSukses = 1;
                        break;
                    case 9:
                        labelMetode = "Direct QRIS Scanner";
                        cout << "[DIRECT QRIS] Sistem mendeteksi pemindaian sukses dari mobile banking.\n";
                        pembayaranSukses = 1;
                        break;
                    default:
                        cout << "Metode pembayaran tidak dikenal!\n";
                        break;
                }

                switch (pembayaranSukses) {
                    case 1: {
                        totalSirkulasiFinansial += totalAkhir;
                        
                        // Cetak Struk Belanja Resmi
                        cout << "\n=========================================\n";
                        cout << "             STRUK PEMBAYARAN            \n";
                        cout << "=========================================\n";
                        WaktuTransaksi waktu;
                        waktu.setWaktuSekarang();
                        cout << "Waktu Transaksi : "; waktu.cetakWaktu();
                        cout << "Nama Pelanggan  : " << userSekarang.nama << "\n";
                        cout << "Metode Bayar    : " << labelMetode << "\n";
                        cout << "-----------------------------------------\n";
                        for (int i = 0; i < userSekarang.jumlahItemKeranjang; ++i) {
                            cout << userSekarang.keranjang[i].produk.namaProduk << " x" 
                                 << userSekarang.keranjang[i].kuantitas << " : Rp" 
                                 << fixed << setprecision(0) << userSekarang.keranjang[i].produk.harga * userSekarang.keranjang[i].kuantitas << "\n";
                        }
                        cout << "-----------------------------------------\n";
                        cout << "Subtotal        : Rp" << totalBelanja << "\n";
                        cout << "PPN (11%)       : Rp" << pajak << "\n";
                        cout << "Total Bayar     : Rp" << totalAkhir << "\n";
                        
                        switch (metodeBayar) {
                            case 1:
                                cout << "Sisa Saldo Wallet: Rp" << userSekarang.saldoWallet << "\n";
                                break;
                            default:
                                cout << "Sisa Saldo Wallet: Rp" << userSekarang.saldoWallet << " (Tidak Berubah)\n";
                                break;
                        }
                        
                        cout << "=========================================\n";
                        cout << "      Terima Kasih Telah Berbelanja!     \n";
                        
                        userSekarang.kosongkanKeranjang();
                        break;
                    }
                    case 0:
                    default:
                        cout << "X Pembayaran Gagal Diproses!\n";
                        break;
                }
                break;
            }
            case 5: {
                string kunci;
                cout << "\nMasukkan Kunci Keamanan Admin: ";
                cin >> kunci;
                if (kunci == adminUtama.kunciKeamanan) {
                    adminUtama.pantauKeuangan(totalSirkulasiFinansial);
                } else {
                    cout << "X Kunci Keamanan Salah! Akses Ditolak.\n";
                }
                break;
            }
            case 6: {
                cout << "\nTerima kasih telah berkunjung ke CERAN_HUB MALL!\n";
                break;
            }
            default: {
                cout << "X Pilihan menu tidak valid!\n";
                break;
            }
        }
    } while (pilihanMenu != 6);

    return 0;
}
