#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream> // Pustaka untuk menulis data ke file .txt

using namespace std;

// Batasan ukuran array manual karena tidak boleh pakai vector (Aturan Tugas Alpro)
const int MAKS_PRODUK = 5;
const int MAKS_TOKO = 40;
const int MAKS_KERANJANG = 20;
const int MAKS_LOG = 100;

// Variabel Global untuk Pengaturan Kosmetik UI Tampilan
int TEMA_WARNA_SEKARANG = 0; // 0: Default, 1: Cyber, 2: Hacker, 3: Classic, 4: Sakura, 5: Cyan
int GAYA_BORDER_SEKARANG = 1; // 1: Karakter biasa (=), 2: Garis Tunggal Unicode, 3: Garis Tebal

// Struktur penyimpanan log aktivitas transaksi (Sistem Audit Log)
struct LogAktivitas
{
    string deskripsi;
    int jam;
    int menit;
    int detik;
};

LogAktivitas DATABASE_LOG[MAKS_LOG];
int TOTAL_LOG_SEKARANG = 0;

// Fungsi pembantu untuk mencatat log ke dalam sistem database statis
void catatAktivitasLog(string pesan)
{
    if (TOTAL_LOG_SEKARANG < MAKS_LOG)
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        DATABASE_LOG[TOTAL_LOG_SEKARANG].deskripsi = pesan;
        DATABASE_LOG[TOTAL_LOG_SEKARANG].jam = now->tm_hour;
        DATABASE_LOG[TOTAL_LOG_SEKARANG].menit = now->tm_min;
        DATABASE_LOG[TOTAL_LOG_SEKARANG].detik = now->tm_sec;
        TOTAL_LOG_SEKARANG++;
    }
}

// Fungsi pembantu untuk mengubah string menjadi lowercase (Pengganti std::transform)
string keBawah(string teks)
{
    string hasil = "";
    for (size_t i = 0; i < teks.length(); i++)
    {
        char c = teks[i];
        if (c >= 'A' && c <= 'Z')
        {
            hasil += (c + 32);
        }
        else
        {
            hasil += c;
        }
    }
    return hasil;
}

// Fungsi pembantu untuk mencari substring (Pengganti string::find manual agar lebih aman)
bool mengandungKata(string teksUtama, string kataKunci)
{
    string utama = keBawah(teksUtama);
    string kunci = keBawah(kataKunci);
    if (kunci.length() > utama.length())
    {
        return false;
    }
    
    for (size_t i = 0; i <= utama.length() - kunci.length(); i++)
    {
        size_t j;
        for (j = 0; j < kunci.length(); j++)
        {
            if (utama[i + j] != kunci[j])
            {
                break;
            }
        }
        if (j == kunci.length())
        {
            return true;
        }
    }
    return false;
}

// Fungsi penanganan warna teks di konsol CLI secara manual menggunakan ANSI Escape Code
void terapkanWarnaTampilan(int kodeWarna)
{
    switch(kodeWarna)
    {
        case 1:
        {
            cout << "\033[1;31m"; // Merah (Cyber Tema)
            break;
        }
        case 2:
        {
            cout << "\033[1;32m"; // Hijau (Hacker Tema)
            break;
        }
        case 3:
        {
            cout << "\033[1;34m"; // Biru (Classic Tema)
            break;
        }
        case 4:
        {
            cout << "\033[1;35m"; // Ungu (Sakura Tema)
            break;
        }
        case 5:
        {
            cout << "\033[1;36m"; // Cyan (Modern Tema)
            break;
        }
        default:
        {
            cout << "\033[0m"; // Reset ke Default
            break;
        }
    }
}

// Fungsi untuk mencetak pembatas garis dinamis berdasarkan tema border pilihan user
void cetakGarisPembatasUI()
{
    terapkanWarnaTampilan(TEMA_WARNA_SEKARANG);
    switch(GAYA_BORDER_SEKARANG)
    {
        case 2:
        {
            cout << "────────────────────────────────────────────────═══════════\n";
            break;
        }
        case 3:
        {
            cout << "===========================================================\n";
            break;
        }
        case 4:
        {
            cout << "###########################################################\n";
            break;
        }
        default:
        {
            cout << "=========================================\n";
            break;
        }
    }
    terapkanWarnaTampilan(0);
}

// Fungsi mencetak Header Atas Box UI
void cetakHeaderBoxUI(string judul)
{
    terapkanWarnaTampilan(TEMA_WARNA_SEKARANG);
    switch(GAYA_BORDER_SEKARANG)
    {
        case 2:
        {
            cout << "┌─────────────────────────────────────────────────────────┐\n";
            cout << "  " << judul << "\n";
            cout << "└─────────────────────────────────────────────────────────┘\n";
            break;
        }
        case 3:
        {
            cout << "╔═════════════════════════════════════════════════════════╗\n";
            cout << "  " << judul << "\n";
            cout << "╚═════════════════════════════════════════════════════════╝\n";
            break;
        }
        default:
        {
            cout << "=========================================\n";
            cout << "  " << judul << "\n";
            cout << "=========================================\n";
            break;
        }
    }
    terapkanWarnaTampilan(0);
}

// Fungsi simulasi loading screen prapembuka program mall
void jalankanAnimasiLoading()
{
    terapkanWarnaTampilan(TEMA_WARNA_SEKARANG);
    cout << "\n[MEMPROSES LOGIKA SYSTEM ENVIRONMENT CERAN_HUB]\n";
    cout << "Loading: [";
    for(int i = 0; i < 20; i++)
    {
        cout << "■";
        cout.flush();
        // Simulasi delay prapembacaan
        for(volatile long long j=0; j<8000000; j++);
    }
    cout << "] 100% KONDISI STABIL!\n\n";
    terapkanWarnaTampilan(0);
}

// Fungsi mencetak Logo Besar CERAN_HUB
void cetakLogoMallBesar()
{
    terapkanWarnaTampilan(TEMA_WARNA_SEKARANG);
    std::cout << "   ____ _____ ____    _    _   _     _   _ _   _ ____   \n";
    std::cout << "  / ___| ____|  _ \\  / \\  | \\ | |   | | | | | | | __ )  \n";
    std::cout << " | |   |  _| | |_) |/ _ \\ |  \\| |   | |_| | | | |  _ \\  \n";
    std::cout << " | |___| |___|  _ </ ___ \\| |\\  |   |  _  | |_| | |_) | \n";
    std::cout << "  \\____|_____|_| \\_/_/   \\_\\_| \\_|   |_| |_|\\___/|____/  \n";
    cetakGarisPembatasUI();
    cetakGarisPembatasUI();
    terapkanWarnaTampilan(0);
}

// Struct untuk menangani Tanggal dan Waktu
struct WaktuTransaksi
{
    int tanggal;
    int bulan;
    int tahun;
    int jam;
    int menit;
    int detik;

    void setWaktuSekarang()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        tanggal = now->tm_mday;
        bulan = now->tm_mon + 1;
        tahun = now->tm_year + 1900;
        jam = now->tm_hour;
        menit = now->tm_min;
        detik = now->tm_sec;
    }

    void cetakWaktu() const
    {
        cout << setfill('0') << setw(4) << tahun << "-" 
             << setw(2) << bulan << "-" << setw(2) << tanggal << " "
             << setw(2) << jam << ":" << setw(2) << menit << ":" << setw(2) << detik << endl;
    }
};

// Class 1: Produk
class Produk
{
public:
    string idProduk;
    string namaProduk;
    int stok;
    double harga;

    Produk() : idProduk(""), namaProduk(""), stok(0), harga(0.0) {}

    Produk(string id, string nama, int s, double h) 
        : idProduk(id), namaProduk(nama), stok(s), harga(h) {}

    void tambahStok(int jumlah)
    {
        stok += jumlah;
    }
    
    void kurangiStok(int jumlah)
    {
        if (stok >= jumlah)
        {
            stok -= jumlah;
        }
    }
};

// Class 2: Toko
class Toko
{
public:
    string idToko;
    string namaToko;
    string kategori;
    Produk daftarBarang[MAKS_PRODUK];
    int jumlahProduk;

    Toko() : idToko(""), namaToko(""), kategori(""), jumlahProduk(0) {}

    Toko(string id, string nama, string kat) : idToko(id), namaToko(nama), kategori(kat), jumlahProduk(0) {}

    void tambahProdukBaru(Produk p)
    {
        if (jumlahProduk < MAKS_PRODUK)
        {
            daftarBarang[jumlahProduk] = p;
            jumlahProduk++;
        }
    }

    void cetakKatalog()
    {
        cetakHeaderBoxUI("KATALOG GERAI MERCHANT: " + namaToko);
        cout << "Kategori Bisnis Utama : " << kategori << "\n";
        cetakGarisPembatasUI();
        for (int i = 0; i < jumlahProduk; ++i)
        {
            cout << i + 1 << ". [" << daftarBarang[i].idProduk << "] " 
                 << daftarBarang[i].namaProduk << " \n"
                 << "   Harga Jual Barang : Rp" << fixed << setprecision(0) << daftarBarang[i].harga << "\n"
                 << "   Jumlah Sisa Stok  : " << daftarBarang[i].stok << " Unit Tersedia\n";
            cetakGarisPembatasUI();
        }
    }
};

// Struct ItemKeranjang untuk menggantikan std::pair
struct ItemKeranjang
{
    Produk produk;
    int kuantitas;
};

// Class 3: Pelanggan (Menggunakan Enkapsulasi Private & Public)
class Pelanggan
{
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

    bool otentikasi(string user, string pass)
    {
        return (username == user && password == pass);
    }

    void tampilkanProfil()
    {
        cetakHeaderBoxUI("PROFIL KARTU IDENTITAS PELANGGAN & WALLET");
        cout << "Nomor Induk Kependudukan (NIK)  : " << nik << "\n";
        cout << "Nama Lengkap Sesuai KTP          : " << nama << "\n";
        cout << "Alamat Domisili Pengiriman       : " << alamat << "\n";
        cout << "Total Saldo Akun Digital Wallet  : Rp" << fixed << setprecision(0) << saldoWallet << "\n";
        cetakGarisPembatasUI();
    }

    void isiSaldo(double jumlah)
    {
        if (jumlah > 0)
        {
            saldoWallet += jumlah;
            cout << "Berhasil Top Up Dana! Saldo Akun Anda Sekarang: Rp" << fixed << setprecision(0) << saldoWallet << "\n";
        }
    }

    void tambahKeranjang(Produk p, int qty)
    {
        if (jumlahItemKeranjang < MAKS_KERANJANG)
        {
            keranjang[jumlahItemKeranjang].produk = p;
            keranjang[jumlahItemKeranjang].kuantitas = qty;
            jumlahItemKeranjang++;
            cout << "-> Sukses: " << p.namaProduk << " (" << qty << " pcs) Dimasukkan Ke Keranjang Belanja.\n";
        }
        else
        {
            cout << "X Maaf, Kapasitas Tampung Keranjang Belanja Penuh!\n";
        }
    }

    void kurangiSaldo(double jumlah)
    {
        saldoWallet -= jumlah;
    }

    void kosongkanKeranjang()
    {
        jumlahItemKeranjang = 0;
    }
};

// Class 4: Admin
class Admin
{
public:
    string idAdmin;
    string kunciKeamanan;

    Admin(string id, string kunci) : idAdmin(id), kunciKeamanan(kunci) {}

    void pantauKeuangan(double totalSirkulasi)
    {
        cetakHeaderBoxUI("SYSTEM LOG AUDIT INTERNAL FINANSIAL MALL");
        cout << "[AUDIT REALTIME] Total Sirkulasi Kas Arus Finansial Saat Ini: Rp" << fixed << setprecision(0) << totalSirkulasi << endl;
        cetakGarisPembatasUI();
    }
};

// Class Utama 5: SistemManajemenMall (Pusat Logika dengan switch-case melimpah)
class SistemManajemenMall
{
private:
    double totalSirkulasiFinansial;
    int totalToko;
    Toko daftarTokoMall[MAKS_TOKO];
    Pelanggan daftarUser[2];
    Pelanggan userSekarang;
    Admin adminUtama;
    bool sedangLogin;

public:
    SistemManajemenMall() : adminUtama("ADM01", "CERAN2026")
    {
        totalSirkulasiFinansial = 0;
        totalToko = 0;
        sedangLogin = false;
        
        // Inisialisasi Database User (Sistem Autentikasi)
        daftarUser[0] = Pelanggan("arya123", "jogja2026", "3404123456789", "Arya Randani", "Sleman, Yogyakarta", 5000000);
        daftarUser[1] = Pelanggan("user2", "pass2", "3404987654321", "Budi Santoso", "Bantul, Yogyakarta", 100000);
    }

    void inisialisasiDataMerchant()
    {
        // 1. Fashion, Pakaian & Department Store
        daftarTokoMall[totalToko++] = Toko("T01", "Uniqlo", "Fashion, Pakaian & Department Store (Kasual & Lifewear)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P01", "Kemeja Flanel", 20, 399000));
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P02", "AIRism T-Shirt", 50, 199000));

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

        daftarTokoMall[totalToko++] = Toko("T15", "Bli-Bli Tukar Tambah", "Gadget, Elektronik & Kamera (Layanan TT)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P16", "Voucher Tukar Tambah", 100, 500000));

        // 4. Perangkat Rumah Tangga & Gaya Hidup
        daftarTokoMall[totalToko++] = Toko("T16", "Ace Hardware", "Home Living & Hobbies");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P17", "Set Obeng Serbaguna", 20, 145000));

        daftarTokoMall[totalToko++] = Toko("T17", "Informa", "Home Living & Hobbies (Furnitur & Interior)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P18", "Kursi Kerja Ergonomis", 8, 1100000));

        daftarTokoMall[totalToko++] = Toko("T18", "Gramedia", "Home Living & Hobbies (Buku & Alat Tulis)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P19", "Buku Structure Data C++", 25, 95000));

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
    }

    double hitungDiskonKupon(string kode)
    {
        string kuponBawah = keBawah(kode);
        double potongan = 0.0;
        
        if (kuponBawah == "ceranalpro")
        {
            cout << "\n[PROMO] Kupon 'CERANALPRO' Berhasil Dipasang! Diskon 15% Diterapkan.\n";
            potongan = 0.15;
        } 
        else if (kuponBawah == "diskonmall")
        {
            cout << "\n[PROMO] Kupon 'DISKONMALL' Berhasil Dipasang! Diskon 10% Diterapkan.\n";
            potongan = 0.10;
        }
        else if (kuponBawah == "mallsukses")
        {
            cout << "\n[PROMO] Kupon 'MALLSUKSES' Berhasil Dipasang! Diskon 25% Diterapkan.\n";
            potongan = 0.25;
        }
        else if (kuponBawah == "kelompok14")
        {
            cout << "\n[PROMO] Kupon Khusus Anggota Kelompok 14 Terdeteksi! Diskon Spesial 40%.\n";
            potongan = 0.40;
        }
        else
        {
            cout << "\n[INFO] Kode Voucher Tidak Valid atau Sudah Kedaluwarsa.\n";
        }
        return potongan;
    }

    void jalankanSistemLogin()
    {
        cout << "=========================================\n";
        cout << "         LOGIN SYSTEM CERAN_HUB MALL       \n";
        cout << "=========================================\n";
        while (!sedangLogin)
        {
            string inpUser, inpPass;
            cout << "Masukkan Username: ";
            cin >> inpUser;
            cout << "Masukkan Password: ";
            cin >> inpPass;

            for (int i = 0; i < 2; i++)
            {
                if (daftarUser[i].otentikasi(inpUser, inpPass))
                {
                    userSekarang = daftarUser[i];
                    sedangLogin = true;
                    catatAktivitasLog("User " + userSekarang.nama + " berhasil login ke sistem.");
                    break;
                }
            }
            if (!sedangLogin)
            {
                cout << "Username atau Password salah! Silakan coba lagi.\n\n";
                catatAktivitasLog("Percobaan login gagal dengan username inputan.");
            }
        }
    }

    void jalankanMenuUtama()
    {
        int pilihanMenu;
        do
        {
            cout << "\n";
            cetakHeaderBoxUI("WELCOME TO CERAN_HUB METROPOLIS SMART MALL");
            cout << "Logged in as: " << userSekarang.nama << "\n";
            cout << "1. Lihat Profil & Fitur Dompet Digital (Wallet)\n";
            cout << "2. Cari Toko (Keyword Search Manual)\n";
            cout << "3. Pilih Toko & Masukkan Keranjang Belanja\n";
            cout << "4. Fitur Pembayaran / Checkout & Cetak Struk (.txt)\n";
            cout << "5. Menu Admin (Audit Keuangan & Log Sistem)\n";
            cout << "6. Pengaturan Kosmetik Tampilan (Kustomisasi Tema UI)\n";
            cout << "7. Keluar Aplikasi\n";
            cout << "Pilihan Anda: ";
            cin >> pilihanMenu;

            switch (pilihanMenu)
            {
                case 1:
                {
                    userSekarang.tampilkanProfil();
                    cout << "\nApakah ingin Top Up Saldo Wallet? (y/n): ";
                    char opsi;
                    cin >> opsi;
                    if (opsi == 'y' || opsi == 'Y')
                    {
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
                        switch (mTopUp)
                        {
                            case 1:
                            {
                                cout << "\n[BANK VIRTUAL ACCOUNT]\n";
                                cout << "Pilih Bank:\n1. BRI\n2. BCA\n3. Mandiri\n4. BNI\nPilihan Bank: ";
                                int subBank;
                                cin >> subBank;
                                switch (subBank)
                                {
                                    case 1: cout << "Nomor VA BRI Anda: 88810" << userSekarang.nik.substr(0, 5) << "\n"; break;
                                    case 2: cout << "Nomor VA BCA Anda: 39010" << userSekarang.nik.substr(0, 5) << "\n"; break;
                                    case 3: cout << "Nomor VA Mandiri Anda: 89608" << userSekarang.nik.substr(0, 5) << "\n"; break;
                                    case 4: cout << "Nomor VA BNI Anda: 82410" << userSekarang.nik.substr(0, 5) << "\n"; break;
                                    default: cout << "Bank tidak tersedia.\n"; statusProses = 0; break;
                                }
                                break;
                            }
                            case 2: cout << "\n[GERAI INDOMARET]\nKode Pembayaran Indomaret: IDM" << userSekarang.nik.substr(2, 6) << "\nSilakan tunjukkan kode ini ke kasir Indomaret terdekat.\n"; break;
                            case 3: cout << "\n[GERAI ALFAMART]\nKode Pembayaran Alfamart: ALFA" << userSekarang.nik.substr(1, 6) << "\nSilakan tunjukkan kode ini ke kasir Alfamart terdekat.\n"; break;
                            case 4:
                            {
                                cout << "\n[E-WALLET GOPAY]\nMenghubungkan ke aplikasi Gojek...\nMasukkan Nomor HP GoPay Anda: ";
                                string noGopay; cin >> noGopay;
                                cout << "Permintaan bayar dikirim ke aplikasi Anda.\n";
                                break;
                            }
                            case 5:
                            {
                                cout << "\n[E-WALLET DANA]\nMembuka gerbang pembayaran DANA...\nMasukkan Nomor ID DANA Anda: ";
                                string noDana; cin >> noDana;
                                cout << "Silakan konfirmasi PIN pada pop-up smartphone Anda.\n";
                                break;
                            }
                            case 6:
                            {
                                cout << "\n[PAYPAL GLOBAL PAYMENT]\nKurs konversi otomatis diterapkan ke USD.\nMasukkan Email PayPal Anda: ";
                                string emailPaypal; cin >> emailPaypal;
                                cout << "Otentikasi tagihan internasional berhasil.\n";
                                break;
                            }
                            case 7:
                            {
                                cout << "\n[E-WALLET SHOPEEPAY]\nMembuka Aplikasi Shopee...\nMasukkan Username Shopee: ";
                                string userShopee; cin >> userShopee;
                                cout << "Notifikasi tagihan telah dikirim ke akun ShopeePay Anda.\n";
                                break;
                            }
                            case 8:
                                cout << "\n[QRIS - AUTOMATIC SCANNER]\n###########################\n##   [QRIS BARCODE SCAN] ##\n##    CERAN_HUB DYNAMIC  ##\n###########################\nSilakan scan kode QR di atas menggunakan aplikasi finansial Anda.\n";
                                break;
                            default:
                                cout << "Pilihan metode top up tidak valid!\n";
                                statusProses = 0;
                                break;
                        }
                        
                        switch (statusProses)
                        {
                            case 1:
                            {
                                cout << "Tekan 1 untuk menyelesaikan proses verifikasi pembayaran: ";
                                int verif; cin >> verif;
                                switch (verif)
                                {
                                    case 1:
                                        userSekarang.isiSaldo(nominal);
                                        catatAktivitasLog("User melakukan Top-Up sebesar Rp" + to_string(nominal));
                                        break;
                                    default:
                                        cout << "Verifikasi gagal! Top up dibatalkan.\n";
                                        break;
                                }
                                break;
                            }
                            default: break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    string kataKunci;
                    cout << "\nMasukkan kata kunci pencarian toko/kategori (contoh: 'Batik', 'Udon', 'Gadget'): ";
                    cin.ignore();
                    getline(cin, kataKunci);

                    cout << "\n--- HASIL PENCARIAN KATA KUNCI '" << kataKunci << "' ---\n";
                    bool ditemukan = false;
                    for (int i = 0; i < totalToko; ++i)
                    {
                        if (mengandungKata(daftarTokoMall[i].namaToko, kataKunci) || 
                            mengandungKata(daftarTokoMall[i].kategori, kataKunci))
                        {
                            cout << "- [" << daftarTokoMall[i].idToko << "] " << daftarTokoMall[i].namaToko 
                                 << " | " << daftarTokoMall[i].kategori << "\n";
                            ditemukan = true;
                        }
                    }
                    if (!ditemukan)
                    {
                        cout << "Toko atau kategori tidak ditemukan.\n";
                    }
                    break;
                }
                case 3:
                {
                    cout << "\n--- DAFTAR GERAI MERCHANT DI MALL ---\n";
                    for (int i = 0; i < totalToko; ++i)
                    {
                        cout << i + 1 << ". " << daftarTokoMall[i].namaToko << "\n";
                    }
                    cout << "Pilih nomor toko: ";
                    int indeksToko;
                    cin >> indeksToko;

                    if (indeksToko > 0 && indeksToko <= totalToko)
                    {
                        Toko& tokoTerpilih = daftarTokoMall[indeksToko - 1];
                        tokoTerpilih.cetakKatalog();

                        cout << "\nPilih nomor barang yang ingin dimasukkan keranjang: ";
                        int indeksBarang;
                        cin >> indeksBarang;

                        if (indeksBarang > 0 && indeksBarang <= tokoTerpilih.jumlahProduk)
                        {
                            Produk& produkTerpilih = tokoTerpilih.daftarBarang[indeksBarang - 1];
                            cout << "Masukkan Jumlah (Qty): ";
                            int qty;
                            cin >> qty;

                            if (qty <= produkTerpilih.stok)
                            {
                                produkTerpilih.kurangiStok(qty);
                                userSekarang.tambahKeranjang(produkTerpilih, qty);
                                catatAktivitasLog("Menambah barang: " + produkTerpilih.namaProduk + " ke keranjang.");
                            }
                            else
                            {
                                cout << "X Stok tidak mencukupi! Sisa stok: " << produkTerpilih.stok << endl;
                            }
                        }
                    }
                    break;
                }
                case 4:
                {
                    if (userSekarang.jumlahItemKeranjang == 0)
                    {
                        cout << "X Keranjang belanja Anda masih kosong!\n";
                        break;
                    }

                    double totalBelanja = 0;
                    for (int i = 0; i < userSekarang.jumlahItemKeranjang; ++i)
                    {
                        totalBelanja += userSekarang.keranjang[i].produk.harga * userSekarang.keranjang[i].kuantitas;
                    }

                    cout << "Apakah Anda memiliki kode voucher kupon belanja? (y/n): ";
                    char opsiKupon;
                    cin >> opsiKupon;
                    double diskonPersen = 0.0;
                    if (opsiKupon == 'y' || opsiKupon == 'Y')
                    {
                        string kodeInput;
                        cout << "Masukkan Kode Kupon Anda: ";
                        cin >> kodeInput;
                        diskonPersen = hitungDiskonKupon(kodeInput);
                    }

                    double nilaiDiskon = totalBelanja * diskonPersen;
                    double subTotalSetelahDiskon = totalBelanja - nilaiDiskon;
                    double pajak = subTotalSetelahDiskon * 0.11; 
                    double totalAkhir = subTotalSetelahDiskon + pajak;

                    cout << "\n--- KONFIRMASI PEMBAYARAN ---\n";
                    cout << "Total Belanja Awal : Rp" << fixed << setprecision(0) << totalBelanja << "\n";
                    cout << "Potongan Diskon   : Rp" << nilaiDiskon << "\n";
                    cout << "Pajak (PPN 11%)    : Rp" << pajak << "\n";
                    cout << "Total Tagihan Net  : Rp" << totalAkhir << "\n";
                    
                    cout << "\nPILIH METODE PEMBAYARAN TRANSAKSI:\n";
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
                    double biayaPenanganan = 0.0;
                    string labelMetode = "";

                    switch (metodeBayar)
                    {
                        case 1:
                            labelMetode = "Digital Wallet (Internal)";
                            biayaPenanganan = 0;
                            if (userSekarang.saldoWallet >= totalAkhir)
                            {
                                userSekarang.kurangiSaldo(totalAkhir);
                                pembayaranSukses = 1;
                            }
                            else cout << "X Saldo Wallet internal Anda tidak mencukupi! Silakan isi saldo dulu.\n";
                            break;
                        case 2:
                            labelMetode = "Direct Bank VA"; biayaPenanganan = 2500;
                            cout << "[DIRECT BANK VA] Dikenakan tambahan biaya admin VA Rp" << biayaPenanganan << "\nMasukkan nomor VA tujuan transfer: ";
                            { string inputVA; cin >> inputVA; } pembayaranSukses = 1; break;
                        case 3:
                            labelMetode = "Direct Indomaret"; biayaPenanganan = 2500;
                            cout << "[DIRECT INDOMARET] Harap selesaikan pembayaran di kasir dengan Kode: TRM" << userSekarang.nik.substr(4, 5) << "\n";
                            pembayaranSukses = 1; break;
                        case 4:
                            labelMetode = "Direct Alfamart"; biayaPenanganan = 2500;
                            cout << "[DIRECT ALFAMART] Harap selesaikan pembayaran di kasir dengan Kode: TRMA" << userSekarang.nik.substr(5, 5) << "\n";
                            pembayaranSukses = 1; break;
                        case 5:
                            labelMetode = "Direct GoPay"; biayaPenanganan = 1000;
                            cout << "[DIRECT GOPAY] Masukkan PIN Keamanan GoPay Anda: ";
                            { string pinGopay; cin >> pinGopay; } pembayaranSukses = 1; break;
                        case 6:
                            labelMetode = "Direct DANA"; biayaPenanganan = 1000;
                            cout << "[DIRECT DANA] Masukkan OTP Handphone: ";
                            { string otpDana; cin >> otpDana; } pembayaranSukses = 1; break;
                        case 7:
                            labelMetode = "Direct PayPal Account"; biayaPenanganan = 5000;
                            cout << "[DIRECT PAYPAL] Memproses pemotongan dana internasional...\n";
                            pembayaranSukses = 1; break;
                        case 8:
                            labelMetode = "Direct ShopeePay"; biayaPenanganan = 1000;
                            cout << "[DIRECT SHOPEEPAY] Scan wajah / sidik jari perangkat seluler...\n";
                            pembayaranSukses = 1; break;
                        case 9:
                            labelMetode = "Direct QRIS Scanner"; biayaPenanganan = 0;
                            cout << "[DIRECT QRIS] Sistem mendeteksi pemindaian sukses dari mobile banking (Bebas Biaya).\n";
                            pembayaranSukses = 1; break;
                        default:
                            cout << "Metode pembayaran tidak dikenal!\n";
                            break;
                    }

                    totalAkhir += biayaPenanganan;

                    switch (pembayaranSukses)
                    {
                        case 1:
                        {
                            totalSirkulasiFinansial += totalAkhir;
                            catatAktivitasLog("Checkout berhasil dilakukan via " + labelMetode + " senilai Rp" + to_string(totalAkhir));
                            
                            WaktuTransaksi waktu;
                            waktu.setWaktuSekarang();

                            // 1. Tampilkan Struk ke Layar Konsol UI
                            cout << "\n=========================================\n";
                            cout << "             STRUK PEMBAYARAN            \n";
                            cout << "=========================================\n";
                            cout << "Waktu Transaksi : "; waktu.cetakWaktu();
                            cout << "Nama Pelanggan  : " << userSekarang.nama << "\n";
                            cout << "Metode Bayar    : " << labelMetode << "\n";
                            cout << "-----------------------------------------\n";
                            for (int i = 0; i < userSekarang.jumlahItemKeranjang; ++i)
                            {
                                cout << userSekarang.keranjang[i].produk.namaProduk << " x" 
                                     << userSekarang.keranjang[i].kuantitas << " : Rp" 
                                     << fixed << setprecision(0) << userSekarang.keranjang[i].produk.harga * userSekarang.keranjang[i].kuantitas << "\n";
                            }
                            cout << "-----------------------------------------\n";
                            cout << "Subtotal Barang : Rp" << totalBelanja << "\n";
                            cout << "Diskon Potongan : Rp" << nilaiDiskon << "\n";
                            cout << "PPN (11%)       : Rp" << pajak << "\n";
                            cout << "Biaya Penanganan: Rp" << biayaPenanganan << "\n";
                            cout << "Total Bayar     : Rp" << totalAkhir << "\n";
                            
                            switch (metodeBayar)
                            {
                                case 1: cout << "Sisa Saldo Wallet: Rp" << userSekarang.saldoWallet << "\n"; break;
                                default: cout << "Sisa Saldo Wallet: Rp" << userSekarang.saldoWallet << " (Tidak Berubah)\n"; break;
                            }
                            cout << "=========================================\n";
                            cout << "      Terima Kasih Telah Berbelanja!     \n";

                            // 2. LOGIKA UTAMA EKSPOR FILE .TXT (Menyimpan Struk Belanja ke Harddisk)
                            ofstream fileStruk;
                            fileStruk.open("struk_belanja.txt"); // Membuat file bernama struk_belanja.txt
                            if (fileStruk.is_open())
                            {
                                fileStruk << "=========================================\n";
                                fileStruk << "        CERAN_HUB OFFICIAL MALL          \n";
                                fileStruk << "             STRUK BELANJA EMALL         \n";
                                fileStruk << "=========================================\n";
                                fileStruk << "Nama Pelanggan  : " << userSekarang.nama << "\n";
                                fileStruk << "Metode Bayar    : " << labelMetode << "\n";
                                fileStruk << "-----------------------------------------\n";
                                for (int i = 0; i < userSekarang.jumlahItemKeranjang; ++i)
                                {
                                    fileStruk << userSekarang.keranjang[i].produk.namaProduk << " x" 
                                              << userSekarang.keranjang[i].kuantitas << " : Rp" 
                                              << fixed << setprecision(0) << userSekarang.keranjang[i].produk.harga * userSekarang.keranjang[i].kuantitas << "\n";
                                }
                                fileStruk << "-----------------------------------------\n";
                                fileStruk << "Subtotal Awal   : Rp" << totalBelanja << "\n";
                                fileStruk << "Diskon Potongan : Rp" << nilaiDiskon << "\n";
                                fileStruk << "PPN (11%)       : Rp" << pajak << "\n";
                                fileStruk << "Biaya Admin     : Rp" << biayaPenanganan << "\n";
                                fileStruk << "Total Akhir     : Rp" << totalAkhir << "\n";
                                fileStruk << "=========================================\n";
                                fileStruk << "   TERIMA KASIH ATAS KUNJUNGAN ANDA!     \n";
                                fileStruk.close();
                                cout << "\n[INFO] Struk belanja fisik sukses dicetak ke dalam file 'struk_belanja.txt'!\n";
                            }
                            else
                            {
                                cout << "\n[ERROR] Gagal mencetak file struk belanja digital.\n";
                            }
                            
                            userSekarang.kosongkanKeranjang();
                            break;
                        }
                        default:
                            cout << "X Pembayaran Gagal Diproses!\n";
                            break;
                    }
                    break;
                }
                case 5:
                {
                    string kunci;
                    cout << "\nMasukkan Kunci Keamanan Admin: ";
                    cin >> kunci;
                    if (kunci == adminUtama.kunciKeamanan)
                    {
                        adminUtama.pantauKeuangan(totalSirkulasiFinansial);
                        
                        cout << "\n Apakah Anda ingin melihat seluruh Log Aktivitas Sistem? (y/n): ";
                        char opsiLog;
                        cin >> opsiLog; 
                        if (opsiLog == 'y' || opsiLog == 'Y')
                        {
                            cout << "\n=== HISTORI LOG AUDITING REALTIME ===\n";
                            for(int k = 0; k < TOTAL_LOG_SEKARANG; k++)
                            {
                                cout << "[" << setfill('0') << setw(2) << DATABASE_LOG[k].jam << ":" 
                                     << setw(2) << DATABASE_LOG[k].menit << ":" 
                                     << setw(2) << DATABASE_LOG[k].detik << "] " 
                                     << DATABASE_LOG[k].deskripsi << "\n";
                            }
                            cout << "=====================================\n";
                        }
                    }
                    else cout << "X Kunci Keamanan Salah! Akses Ditolak.\n";
                    break;
                }
                case 6:
                {
                    cout << "\n=== PENGATURAN KOSMETIK TAMPILAN (UI) ===\n";
                    cout << "1. Ubah Tema Warna Teks Aplikasi\n";
                    cout << "2. Ubah Model Garis Pembatas (Border Style)\n";
                    cout << "Pilihan Sub-Menu Kosmetik: ";
                    int subKosmetik;
                    cin >> subKosmetik;
                    
                    switch(subKosmetik)
                    {
                        case 1:
                            cout << "\nPILIH TEMA WARNA:\n0. Default Putih\n1. Cyber Red\n2. Hacker Green\n3. Classic Blue\n4. Sakura Pink\n5. Modern Cyan\nPilihan Warna Anda: ";
                            cin >> TEMA_WARNA_SEKARANG;
                            cout << "Tema warna teks berhasil disesuaikan!\n";
                            break;
                        case 2:
                            cout << "\nPILIH MODEL BORDER BARIS:\n1. Garis Sederhana Standar (=)\n2. Garis Tunggal Tipis Unicode (─)\n3. Garis Tebal Double Unicode (═)\n4. Pembatas Tanda Pagar (#)\nPilihan Model Garis Anda: ";
                            cin >> GAYA_BORDER_SEKARANG;
                            cout << "Model pembatas garis berhasil dikustomisasi!\n";
                            break;
                        default:
                            cout << "Opsi kustomisasi tidak valid.\n";
                            break;
                    }
                    break;
                }
                case 7:
                    cout << "\nTerima kasih telah berkunjung ke CERAN_HUB MALL!\n";
                    break;
                default:
                    cout << "X Pilihan menu tidak valid!\n";
                    break;
            }
        } while (pilihanMenu != 7);
    }
};

// Fungsi Main Utuh Ringkas Sesuai Aturan OOP Profesional Tugas Proyek
int main()
{
    // Instansiasi Object Class Manajemen Sistem Utama Mall
    SistemManajemenMall ceranHubApp;

    // Membaca Database Toko Statis
    ceranHubApp.inisialisasiDataMerchant();

    // Animasi Dekoratif Pembuka
    jalankanAnimasiLoading();
    cetakLogoMallBesar();

    // Membuka Alur Autentikasi User Login
    ceranHubApp.jalankanSistemLogin();

    // Navigasi Dasbor Dashboard Berulang
    ceranHubApp.jalankanMenuUtama();

    return 0;
}
