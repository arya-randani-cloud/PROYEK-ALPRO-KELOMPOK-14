#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;

// Struct untuk menangani Tanggal dan Waktu (Sesuai Note)
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
    vector<Produk> daftarBarang;

    Toko(string id, string nama, string kat) : idToko(id), namaToko(nama), kategori(kat) {}

    void tambahProdukBaru(Produk p) {
        daftarBarang.push_back(p);
    }

    void cetakKatalog() {
        cout << "\n=== KATALOG TOKO: " << namaToko << " (" << kategori << ") ===\n";
        for (size_t i = 0; i < daftarBarang.size(); ++i) {
            cout << i + 1 << ". [" << daftarBarang[i].idProduk << "] " 
                 << daftarBarang[i].namaProduk << " | Harga: Rp" << daftarBarang[i].harga 
                 << " | Stok: " << daftarBarang[i].stok << "\n";
        }
    }
};

// Class 3: Pelanggan
class Pelanggan {
public:
    string nik;
    string nama;
    string alamat;
    double saldoWallet;
    vector<pair<Produk, int>> keranjang; // Menyimpan produk dan kuantitas belanja

    Pelanggan(string n, string nm, string al, double saldo) 
        : nik(n), nama(nm), alamat(al), saldoWallet(saldo) {}

    void tampilkanProfil() {
        cout << "\n=== PROFIL PELANGGAN ===\n";
        cout << "NIK          : " << nik << "\n";
        cout << "Nama         : " << nama << "\n";
        cout << "Alamat       : " << alamat << "\n";
        cout << "Saldo Wallet : Rp" << saldoWallet << "\n";
    }

    void tambahKeranjang(Produk p, int qty) {
        keranjang.push_back(make_pair(p, qty));
        cout << "? " << p.namaProduk << " (" << qty << " pcs) dimasukkan ke keranjang.\n";
    }

    void kurangiSaldo(double jumlah) {
        saldoWallet -= jumlah;
    }

    // Perbaikan: Menambahkan fungsi kosongkan keranjang yang sebelumnya terlewat
    void kosongkanKeranjang() {
        keranjang.clear();
    }
};

// Class 4: Admin
class Admin {
public:
    string idAdmin;
    string kunciKeamanan;

    Admin(string id, string kunci) : idAdmin(id), kunciKeamanan(kunci) {}

    void pantauKeuangan(double totalSirkulasi) {
        cout << "\n[AUDIT ADMIN] Total sirkulasi keuangan saat ini: Rp" << totalSirkulasi << endl;
    }
};

int main() {
    double totalSirkulasiFinansial = 0;
    Admin adminUtama("ADM01", "CERAN2026");
    
    // Inisialisasi Data Pelanggan Default
    Pelanggan userSekarang("3404123456789", "Arya Randani", "Sleman, Yogyakarta", 5000000); // Saldo disesuaikan agar cukup belanja

    // Inisialisasi Kategori dan Toko Mall
    vector<Toko> daftarTokoMall;

    // 1. Fashion
    Toko t1("T01", "Uniqlo", "Fashion, Pakaian & Department Store");
    t1.tambahProdukBaru(Produk("P01", "Kemeja Flanel Kotak", 20, 399000));
    t1.tambahProdukBaru(Produk("P02", "AIRism T-Shirt", 50, 199000));
    daftarTokoMall.push_back(t1);

    Toko t2("T02", "H&M", "Fashion, Pakaian & Department Store");
    t2.tambahProdukBaru(Produk("P03", "Hoodie Regular Fit", 15, 449000));
    daftarTokoMall.push_back(t2);

    Toko t3("T03", "Matahari Department Store", "Fashion, Pakaian & Department Store");
    t3.tambahProdukBaru(Produk("P04", "Sepatu Casual Keluarga", 30, 299000));
    daftarTokoMall.push_back(t3);

    // 2. Sepatu & Aksesoris Olahraga
    Toko t4("T04", "Adidas", "Sports & Footwear");
    t4.tambahProdukBaru(Produk("P05", "Sepatu Running Ultraboost", 10, 2200000));
    daftarTokoMall.push_back(t4);

    // 3. Gadget & Elektronik
    Toko t5("T05", "Samsung Store", "Gadget, Elektronik & Kamera");
    t5.tambahProdukBaru(Produk("P06", "Galaxy S26 Ultra", 5, 18999000));
    daftarTokoMall.push_back(t5);

    // 4. Perangkat Rumah Tangga
    Toko t6("T06", "Ace Hardware", "Home Living & Hobbies");
    t6.tambahProdukBaru(Produk("P07", "Set Obeng Serbaguna", 25, 145000));
    daftarTokoMall.push_back(t6);

    Toko t7("T07", "Gramedia", "Home Living & Hobbies");
    t7.tambahProdukBaru(Produk("P08", "Buku Pemrograman C++", 40, 95000));
    daftarTokoMall.push_back(t7);

    // 5. Kesehatan & Kecantikan
    Toko t8("T08", "Watsons", "Kesehatan, Kecantikan & Perawatan Tubuh");
    t8.tambahProdukBaru(Produk("P09", "Sunscreen SPF 50", 100, 75000));
    daftarTokoMall.push_back(t8);

    // 6. Hiburan
    Toko t9("T09", "CGV Cinemas", "Entertainment");
    t9.tambahProdukBaru(Produk("P10", "Tiket Studio Reguler", 200, 45000));
    daftarTokoMall.push_back(t9);

    // 7. Supermarket
    Toko t10("T10", "Hypermart", "Supermarket & Kebutuhan Harian");
    t10.tambahProdukBaru(Produk("P11", "Minyak Goreng 2L", 60, 36000));
    t10.tambahProdukBaru(Produk("P12", "Mie Instan Cup", 500, 5000));
    daftarTokoMall.push_back(t10);

    // 8. Kuliner
    Toko t11("T11", "Marugame Udon", "Food & Beverages");
    t11.tambahProdukBaru(Produk("P13", "Niku Udon", 80, 62000));
    daftarTokoMall.push_back(t11);

    Toko t12("T12", "Starbucks", "Food & Beverages");
    t12.tambahProdukBaru(Produk("P14", "Caffe Latte Venti", 50, 58000));
    daftarTokoMall.push_back(t12);

    Toko t13("T13", "Bakpia Kukus Tugu Jogja", "Oleh-oleh / Kuliner Lokal");
    t13.tambahProdukBaru(Produk("P15", "Bakpia Kukus Kotak Isi 10", 150, 45000));
    daftarTokoMall.push_back(t13);

    // LOOP MENU UTAMA INTERAKTIF
    int pilihanMenu;
    do {
        cout << "\n=========================================\n";
        cout << "       WELCOME TO CERAN_HUB MALL        \n";
        cout << "=========================================\n";
        cout << "1. Lihat Profil & Dompet Digital\n";
        cout << "2. Cari Toko Berdasarkan Kata Kunci (Keyword Search)\n";
        cout << "3. Pilih Toko & Belanja\n";
        cout << "4. Checkout & Cetak Struk Belanja\n";
        cout << "5. Menu Admin (Audit Keuangan)\n";
        cout << "6. Keluar Aplikasi\n";
        cout << "Pilihan Anda: ";
        cin >> pilihanMenu;

        if (pilihanMenu == 1) {
            userSekarang.tampilkanProfil();
        } 
        else if (pilihanMenu == 2) {
            string kataKunci;
            cout << "\nMasukkan kata kunci pencarian toko/kategori (contoh: 'Pakaian', 'Udon', 'Ace'): ";
            cin.ignore();
            getline(cin, kataKunci);

            transform(kataKunci.begin(), kataKunci.end(), kataKunci.begin(), ::tolower);

            cout << "\n--- HASIL PENCARIAN KATA KUNCI '" << kataKunci << "' ---\n";
            bool ditemukan = false;
            for (size_t i = 0; i < daftarTokoMall.size(); ++i) {
                string namaTokoLower = daftarTokoMall[i].namaToko;
                string kategoriLower = daftarTokoMall[i].kategori;
                transform(namaTokoLower.begin(), namaTokoLower.end(), namaTokoLower.begin(), ::tolower);
                transform(kategoriLower.begin(), kategoriLower.end(), kategoriLower.begin(), ::tolower);

                if (namaTokoLower.find(kataKunci) != string::npos || kategoriLower.find(kataKunci) != string::npos) {
                    cout << "- [" << daftarTokoMall[i].idToko << "] " << daftarTokoMall[i].namaToko 
                         << " (" << daftarTokoMall[i].kategori << ")\n";
                    ditemukan = true;
                }
            }
            if (!ditemukan) cout << "Toko atau kategori tidak ditemukan.\n";
        } 
        else if (pilihanMenu == 3) {
            cout << "\n--- DAFTAR SELURUH GERAI MERCHANT DI MALL ---\n";
            for (size_t i = 0; i < daftarTokoMall.size(); ++i) {
                cout << i + 1 << ". " << daftarTokoMall[i].namaToko << " [" << daftarTokoMall[i].kategori << "]\n";
            }
            cout << "Pilih nomor toko: ";
            int indeksToko;
            cin >> indeksToko;

            if (indeksToko > 0 && indeksToko <= (int)daftarTokoMall.size()) {
                Toko& tokoTerpilih = daftarTokoMall[indeksToko - 1];
                tokoTerpilih.cetakKatalog();

                cout << "\nPilih nomor barang yang ingin dibeli: ";
                int indeksBarang;
                cin >> indeksBarang;

                if (indeksBarang > 0 && indeksBarang <= (int)tokoTerpilih.daftarBarang.size()) {
                    Produk& produkTerpilih = tokoTerpilih.daftarBarang[indeksBarang - 1];
                    cout << "Masukkan Kuantitas/Jumlah: ";
                    int qty;
                    cin >> qty;

                    if (qty <= produkTerpilih.stok) {
                        produkTerpilih.kurangiStok(qty);
                        userSekarang.tambahKeranjang(produkTerpilih, qty);
                    } else {
                        cout << "? Stok tidak mencukupi! Sisa stok: " << produkTerpilih.stok << endl;
                    }
                }
            }
        } 
        else if (pilihanMenu == 4) {
            if (userSekarang.keranjang.empty()) {
                cout << "? Keranjang belanja Anda masih kosong!\n";
                continue;
            }

            // Perbaikan Logika Perhitungan Total Belanja di Keranjang
            double totalBelanja = 0;
            for (size_t i = 0; i < userSekarang.keranjang.size(); ++i) {
                totalBelanja += userSekarang.keranjang[i].first.harga * userSekarang.keranjang[i].second;
            }

            double pajak = totalBelanja * 0.11; 
            double totalAkhir = totalBelanja + pajak;

            if (userSekarang.saldoWallet >= totalAkhir) {
                userSekarang.kurangiSaldo(totalAkhir);
                totalSirkulasiFinansial += totalAkhir;

                WaktuTransaksi waktuStruk;
                waktuStruk.setWaktuSekarang();

                // CETAK STRUK RESMI CERAN_HUB
                cout << "\n=========================================\n";
                cout << "             MS SWALAYAN UNY             \n";
                cout << "         Jln. Gejayan, Plaza UNY         \n";
                cout << "=========================================\n";
                cout << "Pelanggan : " << userSekarang.nama << "\n";
                cout << "Alamat    : " << userSekarang.alamat << "\n";
                cout << "Waktu     : "; waktuStruk.cetakWaktu();
                cout << "-----------------------------------------\n";
                cout << "QTY   ITEM                SUBTOTAL\n";
                
                // Perbaikan akses nama dan perkalian subtotal item di dalam struktur loop
                for (size_t i = 0; i < userSekarang.keranjang.size(); ++i) {
                    cout << userSekarang.keranjang[i].second << " x   " 
                         << userSekarang.keranjang[i].first.namaProduk << "\t  Rp" 
                         << userSekarang.keranjang[i].first.harga * userSekarang.keranjang[i].second << "\n";
                }
                cout << "-----------------------------------------\n";
                cout << "TOTAL BELANJA         : Rp" << totalBelanja << "\n";
                cout << "PAJAK (PPN 11%)       : Rp" << pajak << "\n";
                cout << "TOTAL AKHIR           : Rp" << totalAkhir << "\n";
                cout << "METODE PEMBAYARAN     : QRIS CERAN-WALLET\n";
                cout << "SISA SALDO WALLET     : Rp" << userSekarang.saldoWallet << "\n";
                cout << "=========================================\n";
                cout << "   TERIMAKASIH ATAS KUNJUNGAN ANDA       \n";
                cout << "=========================================\n";

                // Perbaikan pemanggilan fungsi kosongkan keranjang belanjaan
                userSekarang.kosongkanKeranjang();
            } else {
                cout << "? Transaksi Gagal! Saldo dompet digital Anda tidak mencukupi.\n";
                cout << "Total tagihan (+Pajak 11%): Rp" << totalAkhir << " | Saldo Anda: Rp" << userSekarang.saldoWallet << endl;
            }
        } 
        else if (pilihanMenu == 5) {
            string pass;
            cout << "Masukkan Kunci Keamanan Admin: ";
            cin >> pass;
            if (pass == adminUtama.kunciKeamanan) {
                adminUtama.pantauKeuangan(totalSirkulasiFinansial);
            } else {
                cout << "? Akses Ditolak! Kunci keamanan salah.\n";
            }
        }
    } while (pilihanMenu != 6);

    cout << "\nTerima kasih telah menggunakan sistem CERAN_HUB!\n";
    return 0;
}