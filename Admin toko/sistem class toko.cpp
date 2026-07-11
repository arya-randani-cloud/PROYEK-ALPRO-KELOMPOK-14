
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

using namespace std;

namespace CeranHub {

// ==========================================
//            BATAS KAPASITAS DATA
// ==========================================
const int MAX_TOKO       = 100;
const int MAX_PRODUK     = 100;
const int MAX_USER       = 50;
const int MAX_PESANAN    = 500;
const int MAX_KATEGORI   = 100;
const int MAX_CUSTOMER   = 200;
const int MAX_PENGIRIMAN = 500;
const int MAX_RETUR      = 100;
const int MAX_SUPLIER    = 50;
const int MAX_KARYAWAN   = 100;
const int MAX_VOUCHER    = 50;
const int MAX_KOMPLAIN   = 100;

// ==========================================
//   CLASS UTIL (kumpulan fungsi bantu statis)
// ==========================================
class Util {
public:
    static void bersihkanLayar() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    static void tungguEnter() {
        cout << "\nTekan [ENTER] untuk melanjutkan...";
        cin.ignore(1000, '\n');
        cin.get();
    }

    static void cetakGaris(int panjang, char simbol) {
        for (int i = 0; i < panjang; i++) cout << simbol;
        cout << endl;
    }

    static string toLowerStr(string s) {
        for (size_t i = 0; i < s.size(); i++) s[i] = tolower((unsigned char)s[i]);
        return s;
    }

    static bool mengandung(const string& teks, const string& keyword) {
        return toLowerStr(teks).find(toLowerStr(keyword)) != string::npos;
    }
};

// ==========================================
//               CLASS PRODUK
// ==========================================
class Produk {
private:
    int id;
    string nama;
    string kategori;
    double hargaBeli;
    double hargaJual;
    int stok;

public:
    Produk() : id(0), hargaBeli(0), hargaJual(0), stok(0) {}

    Produk(int id_, string nama_, string kategori_, double hargaBeli_, double hargaJual_, int stok_)
        : id(id_), nama(nama_), kategori(kategori_), hargaBeli(hargaBeli_), hargaJual(hargaJual_), stok(stok_) {}

    // ---- Getter ----
    int getId() const { return id; }
    string getNama() const { return nama; }
    string getKategori() const { return kategori; }
    double getHargaBeli() const { return hargaBeli; }
    double getHargaJual() const { return hargaJual; }
    int getStok() const { return stok; }
    double getMargin() const { return hargaJual - hargaBeli; }

    // ---- Setter ----
    void setId(int v) { id = v; }
    void setNama(const string& v) { nama = v; }
    void setKategori(const string& v) { kategori = v; }
    void setHargaBeli(double v) { hargaBeli = v; }
    void setHargaJual(double v) { hargaJual = v; }
    void setStok(int v) { stok = v; }

    // ---- Perilaku ----
    void tambahStok(int jml) { if (jml > 0) stok += jml; }

    bool kurangiStok(int jml) {
        if (jml > 0 && stok >= jml) { stok -= jml; return true; }
        return false;
    }

    bool isStokKritis() const { return stok <= 10; }
    string getStatusStok() const { return stok > 0 ? "Tersedia" : "Habis"; }

    void tampilkanRingkas(const string& namaToko) const {
        cout << left << setw(18) << namaToko
             << setw(22) << nama
             << setw(15) << kategori
             << "Rp " << setw(11) << fixed << setprecision(0) << hargaJual
             << setw(10) << (to_string(stok) + " pcs")
             << getStatusStok() << endl;
    }

    void tampilkanBarisTabel() const {
        cout << left << setw(8) << id
             << setw(25) << nama
             << setw(15) << kategori
             << "Rp " << setw(12) << fixed << setprecision(0) << hargaBeli
             << "Rp " << setw(9) << hargaJual
             << stok << " pcs" << endl;
    }

    void tampilkanDetail(const string& namaToko, int idToko) const {
        Util::cetakGaris(50, '=');
        cout << "         DETAIL PRODUK\n";
        Util::cetakGaris(50, '=');
        cout << " ID Produk    : " << id << "\n";
        cout << " Nama         : " << nama << "\n";
        cout << " Kategori     : " << kategori << "\n";
        cout << " Toko Pemilik : " << namaToko << " (ID " << idToko << ")\n";
        cout << " Harga Beli   : Rp " << fixed << setprecision(0) << hargaBeli << "\n";
        cout << " Harga Jual   : Rp " << hargaJual << "\n";
        cout << " Stok         : " << stok << " pcs\n";
        cout << " Estimasi Margin per Unit : Rp " << getMargin() << "\n";
        Util::cetakGaris(50, '=');
    }
};

// ==========================================
//            CLASS KEUANGAN TOKO
// ==========================================
class KeuanganToko {
private:
    double saldoKas;
    double totalPemasukan;
    double totalPengeluaran;
    double totalPajak;

public:
    KeuanganToko() : saldoKas(0), totalPemasukan(0), totalPengeluaran(0), totalPajak(0) {}

    KeuanganToko(double saldo, double pemasukan, double pengeluaran, double pajak)
        : saldoKas(saldo), totalPemasukan(pemasukan), totalPengeluaran(pengeluaran), totalPajak(pajak) {}

    double getSaldoKas() const { return saldoKas; }
    double getTotalPemasukan() const { return totalPemasukan; }
    double getTotalPengeluaran() const { return totalPengeluaran; }
    double getTotalPajak() const { return totalPajak; }

    void tambahKas(double nominal) { if (nominal > 0) saldoKas += nominal; }

    bool tarikKas(double nominal) {
        if (nominal > 0 && nominal <= saldoKas) { saldoKas -= nominal; return true; }
        return false;
    }

    // Dipakai saat restock (pengeluaran modal)
    bool catatPengeluaran(double nominal) {
        if (nominal <= saldoKas) {
            saldoKas -= nominal;
            totalPengeluaran += nominal;
            return true;
        }
        return false;
    }

    // Dipakai saat produk terjual (pemasukan kena pajak 11%)
    double catatPemasukanKotor(double bruto, double persenPajak = 0.11) {
        double pajak = bruto * persenPajak;
        double neto = bruto - pajak;
        saldoKas += neto;
        totalPemasukan += neto;
        totalPajak += pajak;
        return neto;
    }

    void tambahBebanGaji(double gaji) {
        saldoKas -= gaji;
        totalPengeluaran += gaji;
    }

    void tampilkan(const string& namaToko) const {
        Util::cetakGaris(50, '=');
        cout << "      LAPORAN KEUANGAN TOKO: " << namaToko << "\n";
        Util::cetakGaris(50, '=');
        cout << " Saldo Kas Toko Saat Ini : Rp " << fixed << setprecision(0) << saldoKas << endl;
        cout << " Total Pemasukan Bersih  : Rp " << totalPemasukan << endl;
        cout << " Total Pengeluaran       : Rp " << totalPengeluaran << endl;
        cout << " Alokasi Pajak (11%)     : Rp " << totalPajak << endl;
        Util::cetakGaris(50, '-');
    }
};

// ==========================================
//                CLASS TOKO
// ==========================================
class Toko {
private:
    int idToko;
    string namaToko;
    string kategoriDijual;
    double ratingToko;
    int jumlahUlasan;
    KeuanganToko keuangan;
    Produk daftarProduk[MAX_PRODUK];
    int jumlahProduk;

public:
    Toko() : idToko(0), ratingToko(5.0), jumlahUlasan(0), jumlahProduk(0) {}

    Toko(int id, string nama, string kategori)
        : idToko(id), namaToko(nama), kategoriDijual(kategori),
          ratingToko(5.0), jumlahUlasan(0), jumlahProduk(0) {}

    int getId() const { return idToko; }
    string getNama() const { return namaToko; }
    string getKategori() const { return kategoriDijual; }
    int getJumlahProduk() const { return jumlahProduk; }
    KeuanganToko& getKeuangan() { return keuangan; }
    void setKeuangan(const KeuanganToko& k) { keuangan = k; }

    Produk* getProdukByIndex(int idx) {
        if (idx < 0 || idx >= jumlahProduk) return nullptr;
        return &daftarProduk[idx];
    }

    Produk* cariProdukById(int id) {
        for (int j = 0; j < jumlahProduk; j++)
            if (daftarProduk[j].getId() == id) return &daftarProduk[j];
        return nullptr;
    }

    bool isPenuh() const { return jumlahProduk >= MAX_PRODUK; }
    bool idProdukSudahAda(int id) { return cariProdukById(id) != nullptr; }

    bool tambahProduk(const Produk& p) {
        if (isPenuh() || idProdukSudahAda(p.getId())) return false;
        daftarProduk[jumlahProduk++] = p;
        return true;
    }

    bool hapusProdukById(int id) {
        for (int j = 0; j < jumlahProduk; j++) {
            if (daftarProduk[j].getId() == id) {
                for (int k = j; k < jumlahProduk - 1; k++) daftarProduk[k] = daftarProduk[k + 1];
                jumlahProduk--;
                return true;
            }
        }
        return false;
    }

    void tampilkanListProduk() const {
        cout << left << setw(8) << "ID" << setw(25) << "Nama Barang" << setw(15) << "Kategori"
             << setw(15) << "Harga Beli" << setw(12) << "Harga Jual" << "Stok" << endl;
        Util::cetakGaris(80, '-');
        if (jumlahProduk == 0) { cout << "(Toko ini belum memiliki produk)\n"; return; }
        for (int j = 0; j < jumlahProduk; j++) daftarProduk[j].tampilkanBarisTabel();
    }

    void tampilkanKatalog() const {
        for (int j = 0; j < jumlahProduk; j++) daftarProduk[j].tampilkanRingkas(namaToko);
    }
};

// ==========================================
//                CLASS USER
// ==========================================
class User {
private:
    string username;
    string password;
    string alamat;
    bool isAdmin;

public:
    User() : isAdmin(false) {}
    User(string u, string p, string a, bool admin) : username(u), password(p), alamat(a), isAdmin(admin) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getAlamat() const { return alamat; }
    bool getIsAdmin() const { return isAdmin; }

    void setUsername(const string& u) { username = u; }
    void setPassword(const string& p) { password = p; }
    void setAlamat(const string& a) { alamat = a; }
    void setIsAdmin(bool a) { isAdmin = a; }

    bool cekLogin(const string& u, const string& p) const { return username == u && password == p; }
};

// ==========================================
//            CLASS PESANAN MASUK
// ==========================================
class PesananMasuk {
private:
    string namaPembeli, alamatPembeli, namaToko, namaProduk;
    int jumlah;
    double totalBayar;

public:
    PesananMasuk() : jumlah(0), totalBayar(0) {}
    PesananMasuk(string pembeli, string alamat, string toko, string produk, int jml, double total)
        : namaPembeli(pembeli), alamatPembeli(alamat), namaToko(toko), namaProduk(produk),
          jumlah(jml), totalBayar(total) {}

    string getNamaPembeli() const { return namaPembeli; }
    string getAlamatPembeli() const { return alamatPembeli; }
    string getNamaToko() const { return namaToko; }
    string getNamaProduk() const { return namaProduk; }
    int getJumlah() const { return jumlah; }
    double getTotalBayar() const { return totalBayar; }

    void tampilkanBaris() const {
        cout << left << setw(15) << namaPembeli
             << setw(18) << namaToko
             << setw(20) << namaProduk
             << setw(8) << (to_string(jumlah) + " pcs")
             << "Rp " << fixed << setprecision(0) << totalBayar << endl;
    }
};

// ==========================================
//              CLASS PENGIRIMAN
// ==========================================
class Pengiriman {
private:
    string noResi, namaPembeli, namaEkspedisi, status;

public:
    Pengiriman() {}
    Pengiriman(string resi, string pembeli, string ekspedisi, string stat)
        : noResi(resi), namaPembeli(pembeli), namaEkspedisi(ekspedisi), status(stat) {}

    string getNoResi() const { return noResi; }
    string getNamaPembeli() const { return namaPembeli; }
    string getNamaEkspedisi() const { return namaEkspedisi; }
    string getStatus() const { return status; }
    void setStatus(const string& s) { status = s; }

    void tampilkanBaris() const {
        cout << left << setw(15) << noResi << setw(20) << namaPembeli << setw(15) << namaEkspedisi << status << "\n";
    }
};

// ==========================================
//                 CLASS RETUR
// ==========================================
class Retur {
private:
    int idRetur;
    string namaPembeli, namaProduk, alasan, status;

public:
    Retur() : idRetur(0) {}
    Retur(int id, string pembeli, string produk, string alsn, string stat)
        : idRetur(id), namaPembeli(pembeli), namaProduk(produk), alasan(alsn), status(stat) {}

    int getId() const { return idRetur; }
    string getNamaPembeli() const { return namaPembeli; }
    string getNamaProduk() const { return namaProduk; }
    string getAlasan() const { return alasan; }
    string getStatus() const { return status; }
    void setStatus(const string& s) { status = s; }

    void tampilkanBaris() const {
        cout << left << setw(8) << idRetur << setw(18) << namaPembeli
             << setw(20) << namaProduk << setw(25) << alasan << status << "\n";
    }
};

// ==========================================
//                CLASS SUPLIER
// ==========================================
class Suplier {
private:
    int id;
    string nama, kontak, alamat, kategoriSupply;

public:
    Suplier() : id(0) {}
    Suplier(int id_, string nama_, string kontak_, string alamat_, string kategori_)
        : id(id_), nama(nama_), kontak(kontak_), alamat(alamat_), kategoriSupply(kategori_) {}

    int getId() const { return id; }
    string getNama() const { return nama; }
    string getKontak() const { return kontak; }
    string getAlamat() const { return alamat; }
    string getKategoriSupply() const { return kategoriSupply; }

    void tampilkanBaris() const {
        cout << left << setw(5) << id << setw(25) << nama << setw(15) << kategoriSupply
             << setw(15) << kontak << alamat << "\n";
    }
};

// ==========================================
//                CLASS KARYAWAN
// ==========================================
class Karyawan {
private:
    int id;
    string nama, jabatan, status;
    double gajiBulan;

public:
    Karyawan() : id(0), gajiBulan(0) {}
    Karyawan(int id_, string nama_, string jabatan_, double gaji_, string status_)
        : id(id_), nama(nama_), jabatan(jabatan_), status(status_), gajiBulan(gaji_) {}

    int getId() const { return id; }
    string getNama() const { return nama; }
    string getJabatan() const { return jabatan; }
    double getGaji() const { return gajiBulan; }
    string getStatus() const { return status; }

    void tampilkanBaris() const {
        cout << left << setw(5) << id << setw(20) << nama << setw(20) << jabatan
             << "Rp " << setw(12) << fixed << setprecision(0) << gajiBulan << status << "\n";
    }
};

// ==========================================
//                CLASS VOUCHER
// ==========================================
class Voucher {
private:
    string kode;
    double persenDiskon;
    int kuota;
    bool aktif;

public:
    Voucher() : persenDiskon(0), kuota(0), aktif(false) {}
    Voucher(string kode_, double persen_, int kuota_, bool aktif_)
        : kode(kode_), persenDiskon(persen_), kuota(kuota_), aktif(aktif_) {}

    string getKode() const { return kode; }
    double getPersenDiskon() const { return persenDiskon; }
    int getKuota() const { return kuota; }
    bool getAktif() const { return aktif; }

    void tampilkanBaris() const {
        cout << left << setw(20) << kode << setw(15) << persenDiskon
             << setw(10) << kuota << (aktif ? "Aktif" : "Nonaktif") << "\n";
    }
};

// ==========================================
//               CLASS KOMPLAIN
// ==========================================
class Komplain {
private:
    int idKomplain;
    string namaCustomer, perihal, pesan, balasanAdmin, status;

public:
    Komplain() : idKomplain(0) {}
    Komplain(int id, string cust, string perihal_, string pesan_, string balasan, string status_)
        : idKomplain(id), namaCustomer(cust), perihal(perihal_), pesan(pesan_),
          balasanAdmin(balasan), status(status_) {}

    int getId() const { return idKomplain; }
    string getNamaCustomer() const { return namaCustomer; }
    string getPerihal() const { return perihal; }
    string getPesan() const { return pesan; }
    string getBalasan() const { return balasanAdmin; }
    string getStatus() const { return status; }
    void setBalasan(const string& b) { balasanAdmin = b; }
    void setStatus(const string& s) { status = s; }

    void tampilkanDetail() const {
        cout << "ID Tiket : " << idKomplain << " [" << status << "]\n";
        cout << "Customer : " << namaCustomer << "\n";
        cout << "Perihal  : " << perihal << "\n";
        cout << "Pesan    : " << pesan << "\n";
        cout << "Balasan  : " << balasanAdmin << "\n";
    }
};

// ==========================================
//   CLASS UTAMA: MARKETPLACE SYSTEM (ADMIN)
//   Menggantikan seluruh variabel global & fungsi bebas
// ==========================================
class MarketplaceSystem {
private:
    User databaseUser[MAX_USER];
    int jumlahUser;

    Toko daftarToko[MAX_TOKO];
    int jumlahToko;

    PesananMasuk riwayatPesanan[MAX_PESANAN];
    int jumlahPesanan;

    Pengiriman daftarPengiriman[MAX_PENGIRIMAN];
    int jumlahPengiriman;

    Retur daftarRetur[MAX_RETUR];
    int jumlahRetur;

    Suplier daftarSuplier[MAX_SUPLIER];
    int jumlahSuplier;

    Karyawan daftarKaryawan[MAX_KARYAWAN];
    int jumlahKaryawan;

    Voucher daftarVoucher[MAX_VOUCHER];
    int jumlahVoucher;

    Komplain daftarKomplain[MAX_KOMPLAIN];
    int jumlahKomplain;

    User userLogin;
    bool isLoggedIn;
    bool sudahRegistrasi;

    // ---------- Helper privat ----------
    Toko* cariTokoById(int id) {
        for (int i = 0; i < jumlahToko; i++)
            if (daftarToko[i].getId() == id) return &daftarToko[i];
        return nullptr;
    }

    void inisialisasiData() {
        // --- Toko 1: uniqlo ---
        Toko uniqlo(101, "uniqlo", "pakaian");
        uniqlo.setKeuangan(KeuanganToko(5000000, 1500000, 500000, 165000));
        uniqlo.tambahProduk(Produk(101, "Celana Jeans", "pakaian", 80000, 120000, 40));
        uniqlo.tambahProduk(Produk(106, "Kemeja Polos", "pakaian", 70000, 125000, 5));
        daftarToko[jumlahToko++] = uniqlo;

        // --- Toko 2: holland bakery ---
        Toko holland(102, "holland bakery", "makanan");
        holland.setKeuangan(KeuanganToko(3000000, 800000, 300000, 88000));
        holland.tambahProduk(Produk(102, "Roti Cokelat", "makanan", 7000, 12000, 25));
        holland.tambahProduk(Produk(103, "Susu Kotak UHT", "minuman", 4000, 6500, 100));
        daftarToko[jumlahToko++] = holland;

        // --- Riwayat Pesanan ---
        riwayatPesanan[jumlahPesanan++] = PesananMasuk("Budi Santoso", "Jl. Merdeka No. 45, Jakarta", "uniqlo", "Kemeja Polos", 2, 250000);
        riwayatPesanan[jumlahPesanan++] = PesananMasuk("Budi Santoso", "Jl. Merdeka No. 45, Jakarta", "uniqlo", "Celana Jeans", 1, 120000);
        riwayatPesanan[jumlahPesanan++] = PesananMasuk("Siti Aminah", "Jl. Anggrek Raya No. 12, Bandung", "holland bakery", "Roti Cokelat", 5, 60000);

        // --- Suplier ---
        daftarSuplier[jumlahSuplier++] = Suplier(1, "PT Sandang Nusantara", "08123456789", "Bandung", "pakaian");
        daftarSuplier[jumlahSuplier++] = Suplier(2, "CV Pangan Makmur", "08987654321", "Jakarta", "makanan");

        // --- Karyawan ---
        daftarKaryawan[jumlahKaryawan++] = Karyawan(101, "Ahmad Subarjo", "Admin Gudang", 3500000, "Aktif");
        daftarKaryawan[jumlahKaryawan++] = Karyawan(102, "Siti Nurhaliza", "Customer Service", 3200000, "Aktif");

        // --- Voucher ---
        daftarVoucher[jumlahVoucher++] = Voucher("GRATISONGKIR", 10.0, 50, true);
        daftarVoucher[jumlahVoucher++] = Voucher("DISKON50", 50.0, 5, true);

        // --- Pengiriman ---
        daftarPengiriman[jumlahPengiriman++] = Pengiriman("JNT123456", "Budi Santoso", "J&T Express", "Dikirim");
        daftarPengiriman[jumlahPengiriman++] = Pengiriman("JNE987654", "Siti Aminah", "JNE", "Diproses");

        // --- Komplain ---
        daftarKomplain[jumlahKomplain++] = Komplain(1, "Budi Santoso", "Barang Cacat", "Kemeja ada sobekan sedikit di lengan.", "Belum ada balasan.", "Open");

        // --- Retur ---
        daftarRetur[jumlahRetur++] = Retur(1, "Budi Santoso", "Kemeja Polos", "Barang Sobek di Lengan", "Menunggu");
    }

    // ---------- Autentikasi ----------
    void registrasiAkunToko() {
        Util::bersihkanLayar();
        cout << "=== REGISTRASI AKUN ADMIN ===\n";
        if (jumlahUser >= MAX_USER) {
            cout << "[!] Kapasitas database akun admin sudah penuh.\n"; Util::tungguEnter(); return;
        }
        string uname, pword, alamat;
        cout << "Username Baru : "; cin >> uname;
        cout << "Password Baru : "; cin >> pword;
        cin.ignore(1000, '\n');
        cout << "Alamat Kantor : "; getline(cin, alamat);

        databaseUser[jumlahUser++] = User(uname, pword, alamat, true);
        sudahRegistrasi = true;
        cout << "\n[Sukses] Akun admin berhasil dibuat! Menu registrasi sekarang ditutup.\n";
        Util::tungguEnter();
    }

    void loginAkunToko() {
        Util::bersihkanLayar();
        string uname, pword;
        cout << "=== HALAMAN LOGIN ADMIN ===\n";
        cout << "Username : "; cin >> uname;
        cout << "Password : "; cin >> pword;

        if (uname == "admin" && pword == "admin123") {
            userLogin = User("admin", "admin123", "Kantor Pusat", true);
            isLoggedIn = true;
            cout << "\n[Sukses] Selamat datang, Admin.\n";
            Util::tungguEnter(); return;
        }

        for (int i = 0; i < jumlahUser; i++) {
            if (databaseUser[i].cekLogin(uname, pword)) {
                userLogin = databaseUser[i];
                isLoggedIn = true;
                cout << "\n[Login Sukses] Selamat datang Admin, " << userLogin.getUsername() << ".\n";
                Util::tungguEnter(); return;
            }
        }
        cout << "\n[!] Username/Password salah atau belum terdaftar!"; Util::tungguEnter();
    }

    // ---------- List Barang per Toko ----------
    void tampilkanListBarangToko() {
        Util::bersihkanLayar();
        if (jumlahToko == 0) { cout << "\n[!] Belum ada toko terdaftar.\n"; Util::tungguEnter(); return; }

        cout << "=== DAFTAR TOKO ===\n";
        for (int i = 0; i < jumlahToko; i++)
            cout << "- [" << daftarToko[i].getId() << "] " << daftarToko[i].getNama()
                 << " (" << daftarToko[i].getKategori() << ")\n";

        int idCari;
        cout << "\nMasukkan ID Toko untuk melihat detail aset barang: "; cin >> idCari;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        Toko* t = cariTokoById(idCari);
        if (t) {
            Util::bersihkanLayar();
            Util::cetakGaris(80, '=');
            cout << "LIST BARANG TOKO: " << t->getNama() << "\n";
            Util::cetakGaris(80, '=');
            t->tampilkanListProduk();
            Util::tungguEnter(); return;
        }
        cout << "[!] ID Toko tidak ditemukan.\n"; Util::tungguEnter();
    }

    // ---------- Katalog Marketplace ----------
    void tampilkanSemuaProdukKatalog() {
        Util::bersihkanLayar();
        Util::cetakGaris(95, '=');
        cout << "                         ETALASE PRODUK - SEMUA TOKO\n";
        Util::cetakGaris(95, '=');
        if (jumlahToko == 0) { cout << "[!] Belum ada toko/produk yang tersedia di marketplace.\n"; Util::tungguEnter(); return; }

        cout << left << setw(18) << "Toko" << setw(22) << "Nama Produk" << setw(15) << "Kategori"
             << setw(14) << "Harga Jual" << setw(10) << "Stok" << "Status" << endl;
        Util::cetakGaris(95, '-');

        bool adaProduk = false;
        for (int i = 0; i < jumlahToko; i++) {
            if (daftarToko[i].getJumlahProduk() > 0) adaProduk = true;
            daftarToko[i].tampilkanKatalog();
        }
        if (!adaProduk) cout << "[!] Belum ada produk yang didaftarkan di toko manapun.\n";
        Util::cetakGaris(95, '=');
        Util::tungguEnter();
    }

    void cariProdukKatalog() {
        Util::bersihkanLayar();
        string keyword;
        cout << "=== CARI PRODUK (KATALOG MARKETPLACE) ===\n";
        cout << "Masukkan kata kunci nama produk: ";
        cin.ignore(1000, '\n');
        getline(cin, keyword);

        Util::bersihkanLayar();
        Util::cetakGaris(95, '=');
        cout << "HASIL PENCARIAN UNTUK: \"" << keyword << "\"\n";
        Util::cetakGaris(95, '=');
        cout << left << setw(18) << "Toko" << setw(22) << "Nama Produk" << setw(15) << "Kategori"
             << setw(14) << "Harga Jual" << setw(10) << "Stok" << "Status" << endl;
        Util::cetakGaris(95, '-');

        bool ditemukan = false;
        for (int i = 0; i < jumlahToko; i++) {
            for (int j = 0; j < daftarToko[i].getJumlahProduk(); j++) {
                Produk* p = daftarToko[i].getProdukByIndex(j);
                if (p && Util::mengandung(p->getNama(), keyword)) {
                    ditemukan = true;
                    p->tampilkanRingkas(daftarToko[i].getNama());
                }
            }
        }
        if (!ditemukan) cout << "[!] Tidak ada produk yang cocok dengan kata kunci tersebut.\n";
        Util::cetakGaris(95, '=');
        Util::tungguEnter();
    }

    void filterProdukPerKategori() {
        Util::bersihkanLayar();
        string kategoriUnik[MAX_KATEGORI];
        int jumlahKategoriUnik = 0;

        for (int i = 0; i < jumlahToko; i++) {
            for (int j = 0; j < daftarToko[i].getJumlahProduk(); j++) {
                Produk* p = daftarToko[i].getProdukByIndex(j);
                bool sudahAda = false;
                for (int k = 0; k < jumlahKategoriUnik; k++)
                    if (Util::toLowerStr(kategoriUnik[k]) == Util::toLowerStr(p->getKategori())) { sudahAda = true; break; }
                if (!sudahAda && jumlahKategoriUnik < MAX_KATEGORI) kategoriUnik[jumlahKategoriUnik++] = p->getKategori();
            }
        }

        cout << "=== FILTER PRODUK BERDASARKAN KATEGORI ===\n";
        if (jumlahKategoriUnik == 0) { cout << "[!] Belum ada kategori produk yang tersedia.\n"; Util::tungguEnter(); return; }
        cout << "Kategori yang tersedia saat ini:\n";
        for (int k = 0; k < jumlahKategoriUnik; k++) cout << " - " << kategoriUnik[k] << "\n";
        Util::cetakGaris(50, '-');

        string kategori;
        cout << "Masukkan nama kategori: ";
        cin.ignore(1000, '\n');
        getline(cin, kategori);

        Util::bersihkanLayar();
        Util::cetakGaris(95, '=');
        cout << "PRODUK DALAM KATEGORI: " << kategori << "\n";
        Util::cetakGaris(95, '=');
        cout << left << setw(18) << "Toko" << setw(22) << "Nama Produk" << setw(15) << "Kategori"
             << setw(14) << "Harga Jual" << setw(10) << "Stok" << "Status" << endl;
        Util::cetakGaris(95, '-');

        bool ditemukan = false;
        for (int i = 0; i < jumlahToko; i++) {
            for (int j = 0; j < daftarToko[i].getJumlahProduk(); j++) {
                Produk* p = daftarToko[i].getProdukByIndex(j);
                if (Util::toLowerStr(p->getKategori()) == Util::toLowerStr(kategori)) {
                    ditemukan = true;
                    p->tampilkanRingkas(daftarToko[i].getNama());
                }
            }
        }
        if (!ditemukan) cout << "[!] Tidak ada produk dalam kategori tersebut.\n";
        Util::cetakGaris(95, '=');
        Util::tungguEnter();
    }

    void katalogUtamaMarketplace() {
        int pil;
        do {
            Util::bersihkanLayar();
            cout << "\033[1;35m";
            Util::cetakGaris(73, '=');
            cout << "         KATALOG & TAMPILAN UTAMA MARKETPLACE CERAN_HUB\n";
            Util::cetakGaris(73, '=');
            cout << "\033[0m";

            int totalProduk = 0;
            for (int i = 0; i < jumlahToko; i++) totalProduk += daftarToko[i].getJumlahProduk();
            cout << "Total Toko Terdaftar : " << jumlahToko << " toko\n";
            cout << "Total Produk Beredar : " << totalProduk << " item\n";
            Util::cetakGaris(73, '-');

            cout << "1. Tampilkan Semua Produk (Semua Toko)\n";
            cout << "2. Cari Produk Berdasarkan Nama\n";
            cout << "3. Filter Produk Berdasarkan Kategori\n";
            cout << "4. Kembali ke Menu Utama\n";
            Util::cetakGaris(73, '-');
            cout << "Pilih menu (1-4): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: tampilkanSemuaProdukKatalog(); break;
                case 2: cariProdukKatalog(); break;
                case 3: filterProdukPerKategori(); break;
                case 4: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 4);
    }

    // ---------- Keuangan Toko ----------
    void manajemenKeuanganToko() {
        Util::bersihkanLayar();
        int idT;
        cout << "=== MANAJEMEN KEUANGAN TOKO ===\n";
        cout << "Masukkan ID Toko: "; cin >> idT;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        Toko* t = cariTokoById(idT);
        if (!t) { cout << "[!] ID Toko salah.\n"; Util::tungguEnter(); return; }

        Util::bersihkanLayar();
        t->getKeuangan().tampilkan(t->getNama());

        cout << "\n[PILIHAN MANAJEMEN KAS]\n";
        cout << "1. Suntik Modal / Tambah Kas Toko\n";
        cout << "2. Tarik Tunai Kas / Profit Toko\n";
        cout << "3. Kembali ke Menu\n";
        cout << "Pilih tindakan (1-3): ";
        int aksi; cin >> aksi;

        double nominal;
        if (aksi == 1) {
            cout << "Masukkan jumlah Dana Suntikan: Rp "; cin >> nominal;
            t->getKeuangan().tambahKas(nominal);
            cout << "[Sukses] Kas toko berhasil bertambah.\n";
        } else if (aksi == 2) {
            cout << "Masukkan jumlah Penarikan Dana: Rp "; cin >> nominal;
            if (t->getKeuangan().tarikKas(nominal)) cout << "[Sukses] Penarikan kas berhasil dilakukan.\n";
            else cout << "[!] Saldo kas toko tidak mencukupi.\n";
        }
        Util::tungguEnter();
    }

    // ---------- Data Customer ----------
    void cetakProfilCustomer(const string& nama, const string& alamat, int nomor) {
        double totalBelanja = 0;
        cout << nomor << ". Nama Customer : " << nama << "\n";
        cout << "   Alamat        : " << alamat << "\n";
        cout << "   Barang yang Dibeli:\n";
        cout << "   " << left << setw(18) << "Toko" << setw(22) << "Produk" << setw(8) << "Qty" << "Subtotal" << "\n";
        cout << "   " << string(64, '-') << "\n";

        for (int i = 0; i < jumlahPesanan; i++) {
            if (riwayatPesanan[i].getNamaPembeli() == nama && riwayatPesanan[i].getAlamatPembeli() == alamat) {
                const PesananMasuk& b = riwayatPesanan[i];
                cout << "   " << left << setw(18) << b.getNamaToko()
                     << setw(22) << b.getNamaProduk()
                     << setw(8) << (to_string(b.getJumlah()) + " pcs")
                     << "Rp " << fixed << setprecision(0) << b.getTotalBayar() << "\n";
                totalBelanja += b.getTotalBayar();
            }
        }
        cout << "   " << string(64, '-') << "\n";
        cout << "   Total Belanja Customer Ini : Rp " << fixed << setprecision(0) << totalBelanja << "\n";
        Util::cetakGaris(80, '=');
    }

    void kumpulkanCustomerUnik(const string& keyword, bool pakaiFilter,
                                string namaUnik[], string alamatUnik[], int& jumlahUnik) {
        jumlahUnik = 0;
        for (int i = 0; i < jumlahPesanan; i++) {
            if (pakaiFilter && !Util::mengandung(riwayatPesanan[i].getNamaPembeli(), keyword)) continue;
            bool sudahAda = false;
            for (int k = 0; k < jumlahUnik; k++)
                if (namaUnik[k] == riwayatPesanan[i].getNamaPembeli() && alamatUnik[k] == riwayatPesanan[i].getAlamatPembeli()) { sudahAda = true; break; }
            if (!sudahAda && jumlahUnik < MAX_CUSTOMER) {
                namaUnik[jumlahUnik] = riwayatPesanan[i].getNamaPembeli();
                alamatUnik[jumlahUnik] = riwayatPesanan[i].getAlamatPembeli();
                jumlahUnik++;
            }
        }
    }

    void tampilkanSemuaDataCustomer() {
        Util::bersihkanLayar();
        Util::cetakGaris(80, '=');
        cout << "                    PROFIL LENGKAP SEMUA CUSTOMER\n";
        Util::cetakGaris(80, '=');
        if (jumlahPesanan == 0) { cout << "[!] Belum ada data customer / transaksi tercatat.\n"; Util::tungguEnter(); return; }

        string namaUnik[MAX_CUSTOMER], alamatUnik[MAX_CUSTOMER]; int jumlahUnik;
        kumpulkanCustomerUnik("", false, namaUnik, alamatUnik, jumlahUnik);
        for (int k = 0; k < jumlahUnik; k++) cetakProfilCustomer(namaUnik[k], alamatUnik[k], k + 1);
        Util::tungguEnter();
    }

    void cariCustomerPerNama() {
        Util::bersihkanLayar();
        string keyword;
        cout << "=== CARI CUSTOMER BERDASARKAN NAMA ===\n";
        cout << "Masukkan nama customer yang dicari: ";
        cin.ignore(1000, '\n');
        getline(cin, keyword);

        string namaUnik[MAX_CUSTOMER], alamatUnik[MAX_CUSTOMER]; int jumlahUnik;
        kumpulkanCustomerUnik(keyword, true, namaUnik, alamatUnik, jumlahUnik);

        Util::bersihkanLayar();
        Util::cetakGaris(80, '=');
        cout << "HASIL PENCARIAN CUSTOMER UNTUK: \"" << keyword << "\"\n";
        Util::cetakGaris(80, '=');
        if (jumlahUnik == 0) { cout << "[!] Tidak ditemukan customer dengan nama tersebut.\n"; Util::tungguEnter(); return; }
        for (int k = 0; k < jumlahUnik; k++) cetakProfilCustomer(namaUnik[k], alamatUnik[k], k + 1);
        Util::tungguEnter();
    }

    void menuDataCustomer() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(73, '=');
            cout << "               DATA CUSTOMER / PEMBELI (LENGKAP)\n";
            Util::cetakGaris(73, '=');
            cout << "Total Transaksi Tercatat : " << jumlahPesanan << " transaksi\n";
            Util::cetakGaris(73, '-');
            cout << "1. Tampilkan Semua Data Customer (Profil Lengkap)\n";
            cout << "2. Cari Customer Berdasarkan Nama\n";
            cout << "3. Kembali ke Menu Utama\n";
            Util::cetakGaris(73, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: tampilkanSemuaDataCustomer(); break;
                case 2: cariCustomerPerNama(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 3);
    }

    // ---------- Riwayat & Rekap Barang Terjual ----------
    void tampilkanSemuaRiwayatBeli() {
        Util::bersihkanLayar();
        Util::cetakGaris(100, '=');
        cout << "                              RIWAYAT SEMUA TRANSAKSI\n";
        Util::cetakGaris(100, '=');
        cout << left << setw(15) << "Pembeli" << setw(18) << "Toko" << setw(20) << "Produk Dibeli"
             << setw(8) << "Qty" << "Total Bayar" << endl;
        Util::cetakGaris(100, '-');

        if (jumlahPesanan == 0) {
            cout << "[!] Belum ada barang yang dibeli / transaksi tercatat.\n";
        } else {
            double grandTotal = 0;
            for (int i = 0; i < jumlahPesanan; i++) {
                riwayatPesanan[i].tampilkanBaris();
                grandTotal += riwayatPesanan[i].getTotalBayar();
            }
            Util::cetakGaris(100, '-');
            cout << "Total Keseluruhan Transaksi Pembelian : Rp " << fixed << setprecision(0) << grandTotal << endl;
        }
        Util::cetakGaris(100, '=');
        Util::tungguEnter();
    }

    void cariBarangDibeliPerNama() {
        Util::bersihkanLayar();
        string keyword;
        cout << "=== CARI TRANSAKSI BERDASARKAN NAMA PRODUK ===\n";
        cout << "Masukkan nama produk yang dicari: ";
        cin.ignore(1000, '\n');
        getline(cin, keyword);

        Util::bersihkanLayar();
        Util::cetakGaris(100, '=');
        cout << "HASIL PENCARIAN TRANSAKSI UNTUK: \"" << keyword << "\"\n";
        Util::cetakGaris(100, '=');
        cout << left << setw(15) << "Pembeli" << setw(18) << "Toko" << setw(20) << "Produk Dibeli"
             << setw(8) << "Qty" << "Total Bayar" << endl;
        Util::cetakGaris(100, '-');

        bool ditemukan = false;
        for (int i = 0; i < jumlahPesanan; i++) {
            if (Util::mengandung(riwayatPesanan[i].getNamaProduk(), keyword)) {
                ditemukan = true;
                riwayatPesanan[i].tampilkanBaris();
            }
        }
        if (!ditemukan) cout << "[!] Tidak ditemukan riwayat pembelian untuk produk tersebut.\n";
        Util::cetakGaris(100, '=');
        Util::tungguEnter();
    }

    void rekapTotalBarangTerjual() {
        Util::bersihkanLayar();
        Util::cetakGaris(80, '=');
        cout << "               REKAP TOTAL BARANG TERJUAL PER PRODUK\n";
        Util::cetakGaris(80, '=');
        if (jumlahPesanan == 0) { cout << "[!] Belum ada data transaksi untuk direkap.\n"; Util::tungguEnter(); return; }

        string namaProdukRekap[MAX_PESANAN];
        int totalQtyRekap[MAX_PESANAN];
        double totalOmzetRekap[MAX_PESANAN];
        int jumlahRekap = 0;

        for (int i = 0; i < jumlahPesanan; i++) {
            int idx = -1;
            for (int k = 0; k < jumlahRekap; k++)
                if (namaProdukRekap[k] == riwayatPesanan[i].getNamaProduk()) { idx = k; break; }
            if (idx == -1) {
                namaProdukRekap[jumlahRekap] = riwayatPesanan[i].getNamaProduk();
                totalQtyRekap[jumlahRekap] = riwayatPesanan[i].getJumlah();
                totalOmzetRekap[jumlahRekap] = riwayatPesanan[i].getTotalBayar();
                jumlahRekap++;
            } else {
                totalQtyRekap[idx] += riwayatPesanan[i].getJumlah();
                totalOmzetRekap[idx] += riwayatPesanan[i].getTotalBayar();
            }
        }

        for (int a = 0; a < jumlahRekap - 1; a++)
            for (int b = 0; b < jumlahRekap - 1 - a; b++)
                if (Util::toLowerStr(namaProdukRekap[b]) > Util::toLowerStr(namaProdukRekap[b + 1])) {
                    swap(namaProdukRekap[b], namaProdukRekap[b + 1]);
                    swap(totalQtyRekap[b], totalQtyRekap[b + 1]);
                    swap(totalOmzetRekap[b], totalOmzetRekap[b + 1]);
                }

        cout << left << setw(25) << "Nama Produk" << setw(20) << "Total Terjual" << "Total Omzet" << endl;
        Util::cetakGaris(80, '-');
        for (int k = 0; k < jumlahRekap; k++)
            cout << left << setw(25) << namaProdukRekap[k]
                 << setw(20) << (to_string(totalQtyRekap[k]) + " pcs")
                 << "Rp " << fixed << setprecision(0) << totalOmzetRekap[k] << endl;
        Util::cetakGaris(80, '=');
        Util::tungguEnter();
    }

    void cekBarangDibeli() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(73, '=');
            cout << "            RIWAYAT & REKAP BARANG YANG DIBELI (TRANSAKSI)\n";
            Util::cetakGaris(73, '=');
            cout << "Total Transaksi Tercatat : " << jumlahPesanan << " transaksi\n";
            Util::cetakGaris(73, '-');
            cout << "1. Tampilkan Semua Riwayat Transaksi\n";
            cout << "2. Cari Transaksi Berdasarkan Nama Produk\n";
            cout << "3. Rekap Total Barang Terjual per Produk\n";
            cout << "4. Kembali ke Menu Utama\n";
            Util::cetakGaris(73, '-');
            cout << "Pilih menu (1-4): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: tampilkanSemuaRiwayatBeli(); break;
                case 2: cariBarangDibeliPerNama(); break;
                case 3: rekapTotalBarangTerjual(); break;
                case 4: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 4);
    }

    // ---------- Manajemen Stok ----------
    void updateStokPemasukan() {
        Util::bersihkanLayar();
        int idP, jml;
        cout << "=== UPDATE STOK PEMASUKAN (RESTOCK) ===\n";
        cout << "Masukkan ID Produk: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Produk* p = daftarToko[i].cariProdukById(idP);
            if (p) {
                cout << "Produk Ditemukan: " << p->getNama() << " (Stok saat ini: " << p->getStok() << ")\n";
                cout << "Jumlah Stok Masuk Baru: "; cin >> jml;
                if (jml > 0) {
                    double totalBiaya = p->getHargaBeli() * jml;
                    if (daftarToko[i].getKeuangan().catatPengeluaran(totalBiaya)) {
                        p->tambahStok(jml);
                        cout << "\n[Sukses] Restock berhasil!\n";
                        cout << "Kas toko berkurang sebesar Rp " << fixed << setprecision(0) << totalBiaya << " untuk biaya beli barang.\n";
                    } else {
                        cout << "\n[!] Gagal! Saldo kas toko tidak cukup untuk membeli stok baru.\n";
                        cout << "Dibutuhkan: Rp " << totalBiaya << " | Kas Toko: Rp " << daftarToko[i].getKeuangan().getSaldoKas() << endl;
                    }
                }
                Util::tungguEnter(); return;
            }
        }
        cout << "[!] ID Produk tidak valid.\n"; Util::tungguEnter();
    }

    void updateStokPengeluaran() {
        Util::bersihkanLayar();
        int idP, jml;
        cout << "=== UPDATE STOK PENGELUARAN (PENGURANGAN) ===\n";
        cout << "Masukkan ID Produk: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Produk* p = daftarToko[i].cariProdukById(idP);
            if (p) {
                cout << "Produk Ditemukan: " << p->getNama() << " (Stok saat ini: " << p->getStok() << ")\n";
                cout << "1. Pengurangan karena Terjual (Menghasilkan Uang)\n";
                cout << "2. Pengurangan karena Rusak/Retur/Kedaluwarsa (Rugi)\n";
                cout << "Pilih Alasan Pengeluaran (1-2): ";
                int alasan; cin >> alasan;
                cout << "Jumlah Stok Keluar: "; cin >> jml;

                if (p->kurangiStok(jml)) {
                    if (alasan == 1) {
                        double bruto = p->getHargaJual() * jml;
                        double neto = daftarToko[i].getKeuangan().catatPemasukanKotor(bruto);
                        cout << "\n[Sukses] Stok dikurangi karena penjualan.\n";
                        cout << "Kas masuk (bersih setelah pajak 11%): +Rp " << fixed << setprecision(0) << neto << endl;
                    } else {
                        cout << "\n[Sukses] Stok dikurangi tanpa pemasukan (Kategori kerugian/rusak).\n";
                    }
                } else {
                    cout << "\n[!] Jumlah pengeluaran tidak valid atau stok tidak cukup.\n";
                }
                Util::tungguEnter(); return;
            }
        }
        cout << "[!] ID Produk tidak valid.\n"; Util::tungguEnter();
    }

    // ---------- Manajemen Toko ----------
    void tambahTokoBaru() {
        Util::bersihkanLayar();
        cout << "=== TAMBAH TOKO BARU ===\n";
        if (jumlahToko >= MAX_TOKO) { cout << "[!] Kapasitas jaringan toko sudah penuh.\n"; Util::tungguEnter(); return; }

        int id; string nama, kategori;
        cout << "ID Toko Baru (Angka): "; cin >> id;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }
        cin.ignore(1000, '\n');
        cout << "Nama Toko Baru      : "; getline(cin, nama);
        cout << "Kategori Utama Jual : "; getline(cin, kategori);

        daftarToko[jumlahToko++] = Toko(id, nama, kategori);
        cout << "\n[Sukses] Toko baru berhasil didaftarkan ke jaringan.\n"; Util::tungguEnter();
    }

    void hapusToko() {
        Util::bersihkanLayar();
        int id;
        cout << "=== HAPUS TOKO ===\n";
        cout << "Masukkan ID Toko yang mau dihapus: "; cin >> id;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            if (daftarToko[i].getId() == id) {
                for (int k = i; k < jumlahToko - 1; k++) daftarToko[k] = daftarToko[k + 1];
                jumlahToko--;
                cout << "[Sukses] Jaringan toko berhasil dihapus dari sistem.\n"; Util::tungguEnter(); return;
            }
        }
        cout << "[!] Gagal menghapus. ID Toko tidak valid.\n"; Util::tungguEnter();
    }

    void menuManajemenToko() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "           MANAJEMEN TOKO (STRUKTUR TOKO)\n";
            Util::cetakGaris(60, '=');
            cout << "1. Tambah Toko Baru\n";
            cout << "2. Hapus Toko Lama\n";
            cout << "3. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih tindakan (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: tambahTokoBaru(); break;
                case 2: hapusToko(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 3);
    }

    // ---------- Manajemen Produk ----------
    void tambahProdukKeToko() {
        Util::bersihkanLayar();
        cout << "=== TAMBAH PRODUK BARU ===\n";
        if (jumlahToko == 0) { cout << "[!] Belum ada toko. Tambahkan toko terlebih dahulu.\n"; Util::tungguEnter(); return; }

        cout << "Daftar Toko Tersedia:\n";
        for (int i = 0; i < jumlahToko; i++)
            cout << " - [" << daftarToko[i].getId() << "] " << daftarToko[i].getNama() << "\n";
        Util::cetakGaris(40, '-');

        int idT;
        cout << "Masukkan ID Toko tujuan: "; cin >> idT;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        Toko* t = cariTokoById(idT);
        if (!t) { cout << "[!] ID Toko salah.\n"; Util::tungguEnter(); return; }

        if (t->isPenuh()) { cout << "\n[!] Kapasitas produk pada toko ini sudah penuh.\n"; Util::tungguEnter(); return; }

        int id; string nama, kategori; double hargaBeli, hargaJual; int stok;
        cout << "ID Produk Baru (Angka): "; cin >> id;
        if (t->idProdukSudahAda(id)) { cout << "\n[!] ID Produk sudah digunakan di toko ini. Gunakan ID lain.\n"; Util::tungguEnter(); return; }

        cin.ignore(1000, '\n');
        cout << "Nama Barang           : "; getline(cin, nama);
        cout << "Kategori Barang       : "; getline(cin, kategori);
        cout << "Harga Modal (Beli)    : Rp "; cin >> hargaBeli;
        cout << "Harga Jual Konsumen   : Rp "; cin >> hargaJual;
        cout << "Stok Awal             : "; cin >> stok;

        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "\n[!] Input angka tidak valid. Produk dibatalkan.\n"; Util::tungguEnter(); return; }

        t->tambahProduk(Produk(id, nama, kategori, hargaBeli, hargaJual, stok));
        cout << "\n[Sukses] Produk terintegrasi ke dalam toko " << t->getNama() << ".\n"; Util::tungguEnter();
    }

    void lihatDetailProduk() {
        Util::bersihkanLayar();
        cout << "=== LIHAT DETAIL PRODUK ===\n";
        int idP;
        cout << "Masukkan ID Produk: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Produk* p = daftarToko[i].cariProdukById(idP);
            if (p) {
                Util::bersihkanLayar();
                p->tampilkanDetail(daftarToko[i].getNama(), daftarToko[i].getId());
                Util::tungguEnter(); return;
            }
        }
        cout << "[!] ID Produk tidak ditemukan.\n"; Util::tungguEnter();
    }

    void editProdukToko() {
        Util::bersihkanLayar();
        cout << "=== EDIT DATA PRODUK ===\n";
        int idP;
        cout << "Masukkan ID Produk yang mau diedit: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Produk* p = daftarToko[i].cariProdukById(idP);
            if (p) {
                Util::bersihkanLayar();
                cout << "Mengedit Produk: " << p->getNama() << " (Toko: " << daftarToko[i].getNama() << ")\n";
                Util::cetakGaris(50, '-');
                cout << "Kosongkan input (langsung ENTER) jika tidak ingin mengubah field tersebut.\n\n";

                cin.ignore(1000, '\n');
                string inputStr;

                cout << "Nama Baru [" << p->getNama() << "]: ";
                getline(cin, inputStr); if (!inputStr.empty()) p->setNama(inputStr);

                cout << "Kategori Baru [" << p->getKategori() << "]: ";
                getline(cin, inputStr); if (!inputStr.empty()) p->setKategori(inputStr);

                cout << "Harga Beli Baru [" << fixed << setprecision(0) << p->getHargaBeli() << "] (0 = tidak diubah): ";
                getline(cin, inputStr);
                if (!inputStr.empty()) { double val = atof(inputStr.c_str()); if (val > 0) p->setHargaBeli(val); }

                cout << "Harga Jual Baru [" << fixed << setprecision(0) << p->getHargaJual() << "] (0 = tidak diubah): ";
                getline(cin, inputStr);
                if (!inputStr.empty()) { double val = atof(inputStr.c_str()); if (val > 0) p->setHargaJual(val); }

                cout << "Stok Baru [" << p->getStok() << "] (-1 = tidak diubah): ";
                getline(cin, inputStr);
                if (!inputStr.empty()) { int val = atoi(inputStr.c_str()); if (val >= 0) p->setStok(val); }

                cout << "\n[Sukses] Data produk berhasil diperbarui.\n"; Util::tungguEnter(); return;
            }
        }
        cout << "[!] ID Produk tidak ditemukan.\n"; Util::tungguEnter();
    }

    void hapusProduk() {
        Util::bersihkanLayar();
        cout << "=== HAPUS PRODUK ===\n";
        int idP;
        cout << "Masukkan ID Produk yang mau dihapus: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Produk* p = daftarToko[i].cariProdukById(idP);
            if (p) {
                cout << "Yakin hapus produk \"" << p->getNama() << "\" dari toko " << daftarToko[i].getNama() << "? (y/n): ";
                char konfirmasi; cin >> konfirmasi;
                if (tolower(konfirmasi) == 'y') {
                    daftarToko[i].hapusProdukById(idP);
                    cout << "\n[Sukses] SKU Produk berhasil ditiadakan.\n";
                } else {
                    cout << "\n[Info] Penghapusan dibatalkan.\n";
                }
                Util::tungguEnter(); return;
            }
        }
        cout << "[!] ID Produk tidak ditemukan.\n"; Util::tungguEnter();
    }

    void menuManajemenProduk() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "               MANAJEMEN PRODUK\n";
            Util::cetakGaris(60, '=');
            cout << "1. Tambah Produk Baru ke Toko\n";
            cout << "2. Lihat Detail Produk (Berdasarkan ID)\n";
            cout << "3. Edit Data Produk\n";
            cout << "4. Hapus Produk\n";
            cout << "5. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih tindakan (1-5): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: tambahProdukKeToko(); break;
                case 2: lihatDetailProduk(); break;
                case 3: editProdukToko(); break;
                case 4: hapusProduk(); break;
                case 5: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 5);
    }

    // ---------- Logistik & Pengiriman ----------
    void lihatPengiriman() {
        Util::bersihkanLayar();
        Util::cetakGaris(75, '=');
        cout << "                  DATA PENGIRIMAN BARANG\n";
        Util::cetakGaris(75, '=');
        if (jumlahPengiriman == 0) {
            cout << "[!] Belum ada data pengiriman.\n";
        } else {
            cout << left << setw(15) << "No Resi" << setw(20) << "Pembeli" << setw(15) << "Kurir" << "Status\n";
            Util::cetakGaris(75, '-');
            for (int i = 0; i < jumlahPengiriman; i++) daftarPengiriman[i].tampilkanBaris();
        }
        Util::cetakGaris(75, '=');
        Util::tungguEnter();
    }

    void updateStatusPengiriman() {
        Util::bersihkanLayar();
        string resi;
        cout << "=== UPDATE STATUS RESI ===\n";
        cout << "Masukkan Nomor Resi: "; cin >> resi;

        for (int i = 0; i < jumlahPengiriman; i++) {
            if (daftarPengiriman[i].getNoResi() == resi) {
                cout << "Resi ditemukan! Status saat ini: " << daftarPengiriman[i].getStatus() << "\n";
                cout << "Masukkan Status Baru (Diproses/Dikirim/Selesai/Gagal): ";
                string s; cin >> s;
                daftarPengiriman[i].setStatus(s);
                cout << "\n[Sukses] Status pengiriman diperbarui.\n";
                Util::tungguEnter(); return;
            }
        }
        cout << "[!] Resi tidak ditemukan.\n"; Util::tungguEnter();
    }

    void menuLogistik() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "           SISTEM LOGISTIK & PENGIRIMAN\n";
            Util::cetakGaris(60, '=');
            cout << "1. Lacak Semua Pengiriman\n";
            cout << "2. Update Status Resi\n";
            cout << "3. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: lihatPengiriman(); break;
                case 2: updateStatusPengiriman(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 3);
    }

    // ---------- Suplier ----------
    void lihatSuplier() {
        Util::bersihkanLayar();
        Util::cetakGaris(85, '=');
        cout << "                        DAFTAR MITRA SUPLIER\n";
        Util::cetakGaris(85, '=');
        if (jumlahSuplier == 0) {
            cout << "[!] Belum ada suplier terdaftar.\n";
        } else {
            cout << left << setw(5) << "ID" << setw(25) << "Nama Suplier" << setw(15) << "Kategori" << setw(15) << "Kontak" << "Alamat\n";
            Util::cetakGaris(85, '-');
            for (int i = 0; i < jumlahSuplier; i++) daftarSuplier[i].tampilkanBaris();
        }
        Util::cetakGaris(85, '=');
        Util::tungguEnter();
    }

    void tambahSuplier() {
        Util::bersihkanLayar();
        if (jumlahSuplier >= MAX_SUPLIER) { cout << "[!] Kapasitas data suplier penuh.\n"; Util::tungguEnter(); return; }
        cout << "=== TAMBAH SUPLIER BARU ===\n";
        int id; string nama, kontak, alamat, kategori;
        cout << "ID Suplier (Angka): "; cin >> id;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Harus angka.\n"; Util::tungguEnter(); return; }
        cin.ignore(1000, '\n');
        cout << "Nama Suplier : "; getline(cin, nama);
        cout << "Kontak (No)  : "; getline(cin, kontak);
        cout << "Alamat       : "; getline(cin, alamat);
        cout << "Kategori Brg : "; getline(cin, kategori);

        daftarSuplier[jumlahSuplier++] = Suplier(id, nama, kontak, alamat, kategori);
        cout << "\n[Sukses] Data suplier berhasil disimpan.\n"; Util::tungguEnter();
    }

    void menuSuplier() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "           MANAJEMEN SUPLIER (PEMASOK)\n";
            Util::cetakGaris(60, '=');
            cout << "1. Lihat Daftar Suplier\n";
            cout << "2. Tambah Suplier Baru\n";
            cout << "3. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: lihatSuplier(); break;
                case 2: tambahSuplier(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 3);
    }

    // ---------- SDM & Karyawan ----------
    void lihatKaryawan() {
        Util::bersihkanLayar();
        Util::cetakGaris(80, '=');
        cout << "                        DATA KARYAWAN PERUSAHAAN\n";
        Util::cetakGaris(80, '=');
        if (jumlahKaryawan == 0) {
            cout << "[!] Belum ada data karyawan.\n";
        } else {
            cout << left << setw(5) << "ID" << setw(20) << "Nama" << setw(20) << "Jabatan" << setw(15) << "Gaji Bulanan" << "Status\n";
            Util::cetakGaris(80, '-');
            for (int i = 0; i < jumlahKaryawan; i++) daftarKaryawan[i].tampilkanBaris();
        }
        Util::cetakGaris(80, '=');
        Util::tungguEnter();
    }

    void tambahKaryawan() {
        Util::bersihkanLayar();
        if (jumlahKaryawan >= MAX_KARYAWAN) { cout << "[!] Kapasitas pegawai penuh.\n"; Util::tungguEnter(); return; }
        cout << "=== REKRUT KARYAWAN BARU ===\n";
        int id; string nama, jabatan; double gaji;
        cout << "ID Karyawan  : "; cin >> id;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Harus angka.\n"; Util::tungguEnter(); return; }
        cin.ignore(1000, '\n');
        cout << "Nama         : "; getline(cin, nama);
        cout << "Jabatan      : "; getline(cin, jabatan);
        cout << "Gaji Bulanan : Rp "; cin >> gaji;

        daftarKaryawan[jumlahKaryawan++] = Karyawan(id, nama, jabatan, gaji, "Aktif");
        cout << "\n[Sukses] Karyawan baru berhasil diregistrasi.\n"; Util::tungguEnter();
    }

    void bayarGajiKaryawan() {
        Util::bersihkanLayar();
        cout << "=== PEMBAYARAN GAJI KARYAWAN ===\n";
        int idK, idT;

        cout << "Daftar Toko sebagai Sumber Dana:\n";
        for (int i = 0; i < jumlahToko; i++)
            cout << "- ID: " << daftarToko[i].getId() << " | Nama: " << daftarToko[i].getNama() << "\n";

        cout << "\nMasukkan ID Toko (Sumber Dana): "; cin >> idT;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); return; }

        Toko* t = cariTokoById(idT);
        if (!t) { cout << "[!] ID Toko tidak valid.\n"; Util::tungguEnter(); return; }

        cout << "Masukkan ID Karyawan yang akan dibayar: "; cin >> idK;
        for (int i = 0; i < jumlahKaryawan; i++) {
            if (daftarKaryawan[i].getId() == idK) {
                double gaji = daftarKaryawan[i].getGaji();
                if (t->getKeuangan().getSaldoKas() >= gaji) {
                    t->getKeuangan().tambahBebanGaji(gaji);
                    cout << "\n[Sukses] Gaji senilai Rp " << fixed << setprecision(0) << gaji
                         << " berhasil dibayarkan kepada " << daftarKaryawan[i].getNama() << ".\n";
                    cout << "Sisa Kas Toko " << t->getNama() << ": Rp " << t->getKeuangan().getSaldoKas() << "\n";
                } else {
                    cout << "\n[!] Gagal. Saldo Kas Toko tidak mencukupi!\n";
                }
                Util::tungguEnter(); return;
            }
        }
        cout << "[!] ID Karyawan tidak ditemukan.\n"; Util::tungguEnter();
    }

    void menuSDM() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "           SDM & MANAJEMEN KARYAWAN\n";
            Util::cetakGaris(60, '=');
            cout << "1. Lihat Data Karyawan\n";
            cout << "2. Tambah Karyawan Baru\n";
            cout << "3. Bayar Gaji (Potong Kas Toko)\n";
            cout << "4. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih menu (1-4): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: lihatKaryawan(); break;
                case 2: tambahKaryawan(); break;
                case 3: bayarGajiKaryawan(); break;
                case 4: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 4);
    }

    // ---------- Retur ----------
    void lihatRetur() {
        Util::bersihkanLayar();
        Util::cetakGaris(85, '=');
        cout << "                    DAFTAR PENGAJUAN RETUR BARANG\n";
        Util::cetakGaris(85, '=');
        if (jumlahRetur == 0) {
            cout << "[!] Belum ada pengajuan retur.\n";
        } else {
            cout << left << setw(8) << "ID Rtr" << setw(18) << "Pembeli" << setw(20) << "Produk" << setw(25) << "Alasan" << "Status\n";
            Util::cetakGaris(85, '-');
            for (int i = 0; i < jumlahRetur; i++) daftarRetur[i].tampilkanBaris();
        }
        Util::cetakGaris(85, '=');
        Util::tungguEnter();
    }

    void prosesRetur() {
        Util::bersihkanLayar();
        int idR;
        cout << "=== PROSES KEPUTUSAN RETUR ===\n";
        cout << "Masukkan ID Retur: "; cin >> idR;

        for (int i = 0; i < jumlahRetur; i++) {
            if (daftarRetur[i].getId() == idR) {
                if (daftarRetur[i].getStatus() != "Menunggu") {
                    cout << "[!] Retur ini sudah berstatus: " << daftarRetur[i].getStatus() << ".\n";
                    Util::tungguEnter(); return;
                }
                cout << "\nDetail Alasan Customer: " << daftarRetur[i].getAlasan() << "\n";
                cout << "Terima ajuan retur ini? (y/n): ";
                char c; cin >> c;
                if (c == 'y' || c == 'Y') {
                    daftarRetur[i].setStatus("Disetujui");
                    cout << "\n[Sukses] Retur Disetujui.\n";
                    cout << "!! WARNING: Pastikan Admin melakukan penyesuaian Stok (Tambah Inbound) di Menu Manajemen Produk !!\n";
                } else {
                    daftarRetur[i].setStatus("Ditolak");
                    cout << "\n[Info] Retur Ditolak.\n";
                }
                Util::tungguEnter(); return;
            }
        }
        cout << "[!] ID Retur tidak ditemukan.\n"; Util::tungguEnter();
    }

    void menuRetur() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "           SISTEM RETUR BARANG (RMA)\n";
            Util::cetakGaris(60, '=');
            cout << "1. Lihat Daftar Pengajuan Retur\n";
            cout << "2. Proses Keputusan Retur\n";
            cout << "3. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: lihatRetur(); break;
                case 2: prosesRetur(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 3);
    }

    // ---------- Customer Service / Komplain ----------
    void lihatKomplain() {
        Util::bersihkanLayar();
        Util::cetakGaris(80, '=');
        cout << "                     TIKET KOMPLAIN PELANGGAN\n";
        Util::cetakGaris(80, '=');
        if (jumlahKomplain == 0) {
            cout << "[!] Belum ada tiket komplain.\n";
        } else {
            for (int i = 0; i < jumlahKomplain; i++) {
                daftarKomplain[i].tampilkanDetail();
                Util::cetakGaris(80, '-');
            }
        }
        Util::tungguEnter();
    }

    void balasKomplain() {
        Util::bersihkanLayar();
        int idK;
        cout << "=== BALAS TIKET KOMPLAIN ===\n";
        cout << "Masukkan ID Tiket: "; cin >> idK;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); return; }
        cin.ignore(1000, '\n');

        for (int i = 0; i < jumlahKomplain; i++) {
            if (daftarKomplain[i].getId() == idK) {
                cout << "Pesan Customer : " << daftarKomplain[i].getPesan() << "\n";
                cout << "Ketik Balasan Admin : ";
                string balasan; getline(cin, balasan);
                daftarKomplain[i].setBalasan(balasan);

                cout << "Tutup tiket ini (Ubah status ke Closed)? (y/n): ";
                char c; cin >> c;
                if (c == 'y' || c == 'Y') daftarKomplain[i].setStatus("Closed");

                cout << "\n[Sukses] Tiket komplain berhasil direspon.\n";
                Util::tungguEnter(); return;
            }
        }
        cout << "[!] ID Tiket tidak valid.\n"; Util::tungguEnter();
    }

    void menuCS() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "           CUSTOMER SERVICE & TIKET KOMPLAIN\n";
            Util::cetakGaris(60, '=');
            cout << "1. Lihat Tiket Komplain Masuk\n";
            cout << "2. Balas Komplain Pelanggan\n";
            cout << "3. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: lihatKomplain(); break;
                case 2: balasKomplain(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 3);
    }

    // ---------- Promosi & Voucher ----------
    void lihatVoucher() {
        Util::bersihkanLayar();
        Util::cetakGaris(60, '=');
        cout << "                 DAFTAR KODE VOUCHER\n";
        Util::cetakGaris(60, '=');
        if (jumlahVoucher == 0) {
            cout << "[!] Belum ada voucher yang dibuat.\n";
        } else {
            cout << left << setw(20) << "Kode Voucher" << setw(15) << "Diskon (%)" << setw(10) << "Kuota" << "Status\n";
            Util::cetakGaris(60, '-');
            for (int i = 0; i < jumlahVoucher; i++) daftarVoucher[i].tampilkanBaris();
        }
        Util::cetakGaris(60, '=');
        Util::tungguEnter();
    }

    void tambahVoucher() {
        Util::bersihkanLayar();
        if (jumlahVoucher >= MAX_VOUCHER) { cout << "[!] Kapasitas database voucher penuh.\n"; Util::tungguEnter(); return; }
        cout << "=== BUAT VOUCHER BARU ===\n";
        string kode; double persen; int kuota;
        cout << "Kode Promo (Cth: MERDEKA) : "; cin >> kode;
        cout << "Persentase Diskon (%)     : "; cin >> persen;
        cout << "Batas Kuota Pemakaian     : "; cin >> kuota;

        daftarVoucher[jumlahVoucher++] = Voucher(kode, persen, kuota, true);
        cout << "\n[Sukses] Voucher baru berhasil diaktifkan.\n"; Util::tungguEnter();
    }

    void menuPromosi() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "           SISTEM PROMOSI & VOUCHER\n";
            Util::cetakGaris(60, '=');
            cout << "1. Lihat Daftar Voucher Aktif\n";
            cout << "2. Buat Voucher Baru\n";
            cout << "3. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: lihatVoucher(); break;
                case 2: tambahVoucher(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 3);
    }

    // ---------- Analitik & Laporan Lanjut ----------
    void laporanStokMenipis() {
        Util::bersihkanLayar();
        Util::cetakGaris(75, '=');
        cout << "           PERINGATAN STOK KRITIS / MENIPIS (<= 10 pcs)\n";
        Util::cetakGaris(75, '=');

        bool adaKritis = false;
        cout << left << setw(18) << "Toko" << setw(25) << "Nama Produk" << setw(15) << "Kategori" << "Sisa Stok\n";
        Util::cetakGaris(75, '-');

        for (int i = 0; i < jumlahToko; i++) {
            for (int j = 0; j < daftarToko[i].getJumlahProduk(); j++) {
                Produk* p = daftarToko[i].getProdukByIndex(j);
                if (p->isStokKritis()) {
                    cout << left << setw(18) << daftarToko[i].getNama()
                         << setw(25) << p->getNama()
                         << setw(15) << p->getKategori()
                         << p->getStok() << " pcs\n";
                    adaKritis = true;
                }
            }
        }
        if (!adaKritis) cout << "\n[Info] Semua stok produk pada seluruh toko dalam kondisi aman (> 10).\n";
        else cout << "\n[!] Segera lakukan Restock via Modul Update Stok Pemasukan!\n";
        Util::cetakGaris(75, '=');
        Util::tungguEnter();
    }

    void laporanPajakGabungan() {
        Util::bersihkanLayar();
        Util::cetakGaris(70, '=');
        cout << "        LAPORAN KEWAJIBAN PAJAK KESELURUHAN (PPN 11%)\n";
        Util::cetakGaris(70, '=');

        double totalPajakGlobal = 0;
        cout << left << setw(20) << "Nama Toko" << "Akumulasi Pajak Terhutang\n";
        Util::cetakGaris(70, '-');

        for (int i = 0; i < jumlahToko; i++) {
            cout << left << setw(20) << daftarToko[i].getNama()
                 << "Rp " << fixed << setprecision(0) << daftarToko[i].getKeuangan().getTotalPajak() << "\n";
            totalPajakGlobal += daftarToko[i].getKeuangan().getTotalPajak();
        }
        Util::cetakGaris(70, '-');
        cout << "TOTAL PAJAK YANG HARUS DISETORKAN KE NEGARA : Rp " << fixed << setprecision(0) << totalPajakGlobal << "\n";
        Util::cetakGaris(70, '=');
        Util::tungguEnter();
    }

    void menuAnalitik() {
        int pil;
        do {
            Util::bersihkanLayar();
            Util::cetakGaris(60, '=');
            cout << "           ANALITIK & LAPORAN LANJUT\n";
            Util::cetakGaris(60, '=');
            cout << "1. Laporan Deteksi Stok Kritis (Menipis)\n";
            cout << "2. Laporan Kewajiban Pajak Global\n";
            cout << "3. Kembali ke Menu Utama\n";
            Util::cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: laporanStokMenipis(); break;
                case 2: laporanPajakGabungan(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
            }
        } while (pil != 3);
    }

    // ---------- Menu Utama Admin ----------
    void menuUtamaAdmin() {
        Util::bersihkanLayar();
        int pilihan;
        Util::cetakGaris(65, '=');
        cout << "               ADMIN TOKO CERAN_HUB\n";
        Util::cetakGaris(65, '=');
        cout << " 1. List Barang per Toko\n";
        cout << " 2. Manajemen Produk (Edit)\n";
        cout << " 3. Manajemen Toko (Edit)\n";
        cout << " 4. Katalog & Tampilan Utama Marketplace\n";
        cout << " 5. Laporan & Manajemen Keuangan Toko\n";
        cout << " 6. Data Customer / Pembeli (Lengkap)\n";
        cout << " 7. Riwayat & Rekap Barang Terjual\n";
        cout << " 8. Update Stok Pemasukan (Restock Toko)\n";
        cout << " 9. Update Stok Pengeluaran (Jual/Retur Barang)\n";
        cout << "10. Sistem Logistik & Pengiriman\n";
        cout << "11. Manajemen Suplier / Pemasok\n";
        cout << "12. SDM & Manajemen Karyawan\n";
        cout << "13. Sistem Retur Barang (RMA)\n";
        cout << "14. Customer Service / Komplain\n";
        cout << "15. Sistem Promosi & Voucher\n";
        cout << "16. Analitik & Laporan Lanjut\n";
        cout << "17. Logout Kendali\n";
        Util::cetakGaris(65, '-');
        cout << "Pilih menu: "; cin >> pilihan;

        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Masukkan angka!\n"; Util::tungguEnter(); return; }

        switch (pilihan) {
            case 1: tampilkanListBarangToko(); break;
            case 2: menuManajemenProduk(); break;
            case 3: menuManajemenToko(); break;
            case 4: katalogUtamaMarketplace(); break;
            case 5: manajemenKeuanganToko(); break;
            case 6: menuDataCustomer(); break;
            case 7: cekBarangDibeli(); break;
            case 8: updateStokPemasukan(); break;
            case 9: updateStokPengeluaran(); break;
            case 10: menuLogistik(); break;
            case 11: menuSuplier(); break;
            case 12: menuSDM(); break;
            case 13: menuRetur(); break;
            case 14: menuCS(); break;
            case 15: menuPromosi(); break;
            case 16: menuAnalitik(); break;
            case 17:
                isLoggedIn = false;
                cout << "\n[Sukses] Berhasil keluar dari panel admin.\n"; Util::tungguEnter(); break;
            default: cout << "[!] Pilihan salah!\n"; Util::tungguEnter();
        }
    }

    void menuAutentikasi() {
        Util::bersihkanLayar();
        int pilihan;

        cout << "\033[1;36m";
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

        if (!sudahRegistrasi) {
            cout << "1. Registrasi Akun Utama Admin\n";
            cout << "2. Login Admin\n";
            cout << "3. Keluar Aplikasi\n";
            Util::cetakGaris(73, '-');
            cout << "Pilih Opsi (1-3): "; cin >> pilihan;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }
            switch (pilihan) {
                case 1: registrasiAkunToko(); break;
                case 2: loginAkunToko(); break;
                case 3: cout << "\nTerima kasih!\n"; exit(0);
                default: cout << "[!] Opsi salah!\n"; Util::tungguEnter();
            }
        } else {
            cout << "1. Login Admin\n";
            cout << "2. Keluar Aplikasi\n";
            Util::cetakGaris(73, '-');
            cout << "Pilih Opsi (1-2): "; cin >> pilihan;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; Util::tungguEnter(); return; }
            switch (pilihan) {
                case 1: loginAkunToko(); break;
                case 2: cout << "\nTerima kasih!\n"; exit(0);
                default: cout << "[!] Opsi salah!\n"; Util::tungguEnter();
            }
        }
    }

public:
    MarketplaceSystem()
        : jumlahUser(0), jumlahToko(0), jumlahPesanan(0), jumlahPengiriman(0),
          jumlahRetur(0), jumlahSuplier(0), jumlahKaryawan(0), jumlahVoucher(0),
          jumlahKomplain(0), isLoggedIn(false), sudahRegistrasi(false) {
        inisialisasiData();
    }

    void run() {
        while (true) {
            if (!isLoggedIn) menuAutentikasi();
            else menuUtamaAdmin();
        }
    }
};

} // namespace CeranHub

// ==========================================
//                 MAIN FUNCTION
// ==========================================
int main() {
    CeranHub::MarketplaceSystem sistem;
    sistem.run();
    return 0;
}
