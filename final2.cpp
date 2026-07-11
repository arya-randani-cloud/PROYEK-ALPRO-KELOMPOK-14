// ==========================================
//      CLASS UTAMA: SISTEM E-COMMERCE MALL
// ==========================================
class TampilanAdmin{
private:
    // ==========================================
    //          DATABASE SIMULASI STATIS (ARRAY)
    // ==========================================
    User databaseUser[MAX_USER];
    int jumlahUser = 0;

    Toko daftarTokoMarketplace[MAX_TOKO];
    int jumlahToko = 0;

    PesananMasuk riwayatPesanan[MAX_PESANAN];
    int jumlahPesanan = 0;

    Pengiriman daftarPengiriman[MAX_PENGIRIMAN];
    int jumlahPengiriman = 0;

    Retur daftarRetur[MAX_RETUR];
    int jumlahRetur = 0;

    Suplier daftarSuplier[MAX_SUPLIER];
    int jumlahSuplier = 0;

    Karyawan daftarKaryawan[MAX_KARYAWAN];
    int jumlahKaryawan = 0;

    Voucher daftarVoucher[MAX_VOUCHER];
    int jumlahVoucher = 0;

    Komplain daftarKomplain[MAX_KOMPLAIN];
    int jumlahKomplain = 0;

    User userLogin;
    bool isLoggedIn = false;
    bool sudahRegistrasi = false;

    // ==========================================
    //         METODE UTILITY & TAMPILAN internal
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

    string toLowerStr(string s) {
        for (size_t i = 0; i < s.size(); i++) s[i] = tolower((unsigned char)s[i]);
        return s;
    }

    bool mengandung(const string& teks, const string& keyword) {
        return toLowerStr(teks).find(toLowerStr(keyword)) != string::npos;
    }

    // ==========================================
    //             METODE AUTENTIKASI
    // ==========================================
    void registrasiAkunToko() {
        bersihkanLayar();
        cout << "=== REGISTRASI AKUN ADMIN ===\n";

        if (jumlahUser >= MAX_USER) {
            cout << "[!] Kapasitas database akun admin sudah penuh.\n"; tungguEnter(); return;
        }

        User userBaru;
        cout << "Username Baru : "; cin >> userBaru.username;
        cout << "Password Baru : "; cin >> userBaru.password;
        cin.ignore(1000, '\n');
        cout << "Alamat Kantor : "; getline(cin, userBaru.alamat);
        userBaru.isAdmin = true;

        databaseUser[jumlahUser] = userBaru;
        jumlahUser++;

        sudahRegistrasi = true;
        cout << "\n[Sukses] Akun admin berhasil dibuat! Menu registrasi sekarang ditutup.\n";
        tungguEnter();
    }

    void loginAkunToko() {
        bersihkanLayar();
        string uname, pword;
        cout << "=== HALAMAN LOGIN ADMIN ===\n";
        cout << "Username : "; cin >> uname;
        cout << "Password : "; cin >> pword;

        if ((uname == "admin" && pword == "admin123")) {
            userLogin.username = "admin";
            userLogin.password = "admin123";
            userLogin.alamat = "Kantor Pusat";
            userLogin.isAdmin = true;
            isLoggedIn = true;
            cout << "\n[Sukses] Selamat datang, Admin.\n";
            tungguEnter(); return;
        }

        for (int i = 0; i < jumlahUser; i++) {
            if (databaseUser[i].username == uname && databaseUser[i].password == pword) {
                userLogin = databaseUser[i];
                isLoggedIn = true;
                cout << "\n[Login Sukses] Selamat datang Admin, " << userLogin.username << ".\n";
                tungguEnter(); return;
            }
        }
        cout << "\n[!] Username/Password salah atau belum terdaftar!"; tungguEnter();
    }

    // ==========================================
    //           METODE INTI SUBSISTEM
    // ==========================================
    void tampilkanListBarangToko() {
        bersihkanLayar();
        if (jumlahToko == 0) {
            cout << "\n[!] Belum ada toko terdaftar.\n"; tungguEnter(); return;
        }

        cout << "=== DAFTAR TOKO ===\n";
        for (int i = 0; i < jumlahToko; i++) {
            cout << "- [" << daftarTokoMarketplace[i].idToko << "] " << daftarTokoMarketplace[i].namaToko
                 << " (" << daftarTokoMarketplace[i].kategoriDijual << ")\n";
        }

        int idCari;
        cout << "\nMasukkan ID Toko untuk melihat detail aset barang: "; cin >> idCari;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            if (daftarTokoMarketplace[i].idToko == idCari) {
                Toko& t = daftarTokoMarketplace[i];
                bersihkanLayar();
                cetakGaris(80, '=');
                cout << "LIST BARANG TOKO: " << t.namaToko << "\n";
                cetakGaris(80, '=');
                cout << left << setw(8) << "ID" << setw(25) << "Nama Barang" << setw(15) << "Kategori" << setw(15) << "Harga Beli" << setw(12) << "Harga Jual" << "Stok" << endl;
                cetakGaris(80, '-');
                if (t.jumlahProduk == 0) {
                    cout << "(Toko ini belum memiliki produk)\n";
                } else {
                    for (int j = 0; j < t.jumlahProduk; j++) {
                        Produk& p = t.daftarProduk[j];
                        cout << left << setw(8) << p.id
                             << setw(25) << p.nama
                             << setw(15) << p.kategori
                             << "Rp " << setw(12) << fixed << setprecision(0) << p.hargaBeli
                             << "Rp " << setw(9) << p.hargaJual
                             << p.stok << " pcs" << endl;
                    }
                }
                tungguEnter(); return;
            }
        }
        cout << "[!] ID Toko tidak ditemukan.\n"; tungguEnter();
    }

    void tampilkanSemuaProdukKatalog() {
        bersihkanLayar();
        cetakGaris(95, '=');
        cout << "                                         ETALASE PRODUK - SEMUA TOKO\n";
        cetakGaris(95, '=');

        if (jumlahToko == 0) {
            cout << "[!] Belum ada toko/produk yang tersedia di marketplace.\n"; tungguEnter(); return;
        }

        cout << left << setw(18) << "Toko" << setw(22) << "Nama Produk" << setw(15) << "Kategori"
             << setw(14) << "Harga Jual" << setw(10) << "Stok" << "Status" << endl;
        cetakGaris(95, '-');

        bool adaProduk = false;
        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                Produk& p = t.daftarProduk[j];
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
        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                Produk& p = t.daftarProduk[j];
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

    void filterProdukPerKategori() {
        bersihkanLayar();
        string kategoriUnik[MAX_KATEGORI];
        int jumlahKategoriUnik = 0;

        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                Produk& p = t.daftarProduk[j];
                bool sudahAda = false;
                for (int k = 0; k < jumlahKategoriUnik; k++) {
                    if (toLowerStr(kategoriUnik[k]) == toLowerStr(p.kategori)) { sudahAda = true; break; }
                }
                if (!sudahAda && jumlahKategoriUnik < MAX_KATEGORI) {
                    kategoriUnik[jumlahKategoriUnik] = p.kategori;
                    jumlahKategoriUnik++;
                }
            }
        }

        cout << "=== FILTER PRODUK BERDASARKAN KATEGORI ===\n";
        if (jumlahKategoriUnik == 0) {
            cout << "[!] Belum ada kategori produk yang tersedia.\n"; tungguEnter(); return;
        }
        cout << "Kategori yang tersedia saat ini:\n";
        for (int k = 0; k < jumlahKategoriUnik; k++) cout << " - " << kategoriUnik[k] << "\n";
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
        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                Produk& p = t.daftarProduk[j];
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

    void katalogUtamaMarketplace() {
        int pil;
        do {
            bersihkanLayar();
            cout << "\033[1;35m";
            cetakGaris(73, '=');
            cout << "         KATALOG & TAMPILAN UTAMA MARKETPLACE CERAN_HUB\n";
            cetakGaris(73, '=');
            cout << "\033[0m";

            int totalProduk = 0;
            for (int i = 0; i < jumlahToko; i++) totalProduk += daftarTokoMarketplace[i].jumlahProduk;
            cout << "Total Toko Terdaftar : " << jumlahToko << " toko\n";
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

    void manajemenKeuanganToko() {
        bersihkanLayar();
        int idT;
        cout << "=== MANAJEMEN KEUANGAN TOKO ===\n";
        cout << "Masukkan ID Toko: "; cin >> idT;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            if (daftarTokoMarketplace[i].idToko == idT) {
                Toko& t = daftarTokoMarketplace[i];
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
                    if (nominal > 0) {
                        t.keuangan.saldoKas += nominal;
                        cout << "[Sukses] Kas toko berhasil bertambah.\n";
                    }
                } else if (aksi == 2) {
                    cout << "Masukkan jumlah Penarikan Dana: Rp "; cin >> nominal;
                    if (nominal <= t.keuangan.saldoKas && nominal > 0) {
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

    void cetakProfilCustomer(const string& nama, const string& alamat, int nomor) {
        double totalBelanja = 0;
        cout << nomor << ". Nama Customer : " << nama << "\n";
        cout << "   Alamat        : " << alamat << "\n";
        cout << "   Barang yang Dibeli:\n";
        cout << "   " << left << setw(18) << "Toko" << setw(22) << "Produk" << setw(8) << "Qty" << "Subtotal" << "\n";
        cout << "   " << string(64, '-') << "\n";

        for (int i = 0; i < jumlahPesanan; i++) {
            if (riwayatPesanan[i].namaPembeli == nama && riwayatPesanan[i].alamatPembeli == alamat) {
                PesananMasuk& b = riwayatPesanan[i];
                cout << "   " << left << setw(18) << b.namaToko
                     << setw(22) << b.namaProduk
                     << setw(8) << (to_string(b.jumlah) + " pcs")
                     << "Rp " << fixed << setprecision(0) << b.totalBayar << "\n";
                totalBelanja += b.totalBayar;
            }
        }
        cout << "   " << string(64, '-') << "\n";
        cout << "   Total Belanja Customer Ini : Rp " << fixed << setprecision(0) << totalBelanja << "\n";
        cetakGaris(80, '=');
    }

    void tampilkanSemuaDataCustomer() {
        bersihkanLayar();
        cetakGaris(80, '=');
        cout << "                    PROFIL LENGKAP SEMUA CUSTOMER\n";
        cetakGaris(80, '=');

        if (jumlahPesanan == 0) {
            cout << "[!] Belum ada data customer / transaksi tercatat.\n"; tungguEnter(); return;
        }

        string namaUnik[MAX_CUSTOMER];
        string alamatUnik[MAX_CUSTOMER];
        int jumlahUnik = 0;

        for (int i = 0; i < jumlahPesanan; i++) {
            bool sudahAda = false;
            for (int k = 0; k < jumlahUnik; k++) {
                if (namaUnik[k] == riwayatPesanan[i].namaPembeli && alamatUnik[k] == riwayatPesanan[i].alamatPembeli) {
                    sudahAda = true; break;
                }
            }
            if (!sudahAda && jumlahUnik < MAX_CUSTOMER) {
                namaUnik[jumlahUnik] = riwayatPesanan[i].namaPembeli;
                alamatUnik[jumlahUnik] = riwayatPesanan[i].alamatPembeli;
                jumlahUnik++;
            }
        }

        for (int k = 0; k < jumlahUnik; k++) {
            cetakProfilCustomer(namaUnik[k], alamatUnik[k], k + 1);
        }
        tungguEnter();
    }

    void cariCustomerPerNama() {
        bersihkanLayar();
        string keyword;
        cout << "=== CARI CUSTOMER BERDASARKAN NAMA ===\n";
        cout << "Masukkan nama customer yang dicari: ";
        cin.ignore(1000, '\n');
        getline(cin, keyword);

        string namaUnik[MAX_CUSTOMER];
        string alamatUnik[MAX_CUSTOMER];
        int jumlahUnik = 0;

        for (int i = 0; i < jumlahPesanan; i++) {
            if (mengandung(riwayatPesanan[i].namaPembeli, keyword)) {
                bool sudahAda = false;
                for (int k = 0; k < jumlahUnik; k++) {
                    if (namaUnik[k] == riwayatPesanan[i].namaPembeli && alamatUnik[k] == riwayatPesanan[i].alamatPembeli) {
                        sudahAda = true; break;
                    }
                }
                if (!sudahAda && jumlahUnik < MAX_CUSTOMER) {
                    namaUnik[jumlahUnik] = riwayatPesanan[i].namaPembeli;
                    alamatUnik[jumlahUnik] = riwayatPesanan[i].alamatPembeli;
                    jumlahUnik++;
                }
            }
        }

        bersihkanLayar();
        cetakGaris(80, '=');
        cout << "HASIL PENCARIAN CUSTOMER UNTUK: \"" << keyword << "\"\n";
        cetakGaris(80, '=');

        if (jumlahUnik == 0) {
            cout << "[!] Tidak ditemukan customer dengan nama tersebut.\n"; tungguEnter(); return;
        }

        for (int k = 0; k < jumlahUnik; k++) {
            cetakProfilCustomer(namaUnik[k], alamatUnik[k], k + 1);
        }
        tungguEnter();
    }

    void menuDataCustomer() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(73, '=');
            cout << "                DATA CUSTOMER / PEMBELI (LENGKAP)\n";
            cetakGaris(73, '=');
            cout << "Total Transaksi Tercatat : " << jumlahPesanan << " transaksi\n";
            cetakGaris(73, '-');
            cout << "1. Tampilkan Semua Data Customer (Profil Lengkap)\n";
            cout << "2. Cari Customer Berdasarkan Nama\n";
            cout << "3. Kembali ke Menu Utama\n";
            cetakGaris(73, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

            switch (pil) {
                case 1: tampilkanSemuaDataCustomer(); break;
                case 2: cariCustomerPerNama(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 3);
    }

    void tampilkanSemuaRiwayatBeli() {
        bersihkanLayar();
        cetakGaris(100, '=');
        cout << "                               RIWAYAT SEMUA TRANSAKSI\n";
        cetakGaris(100, '=');
        cout << left << setw(15) << "Pembeli" << setw(18) << "Toko" << setw(20) << "Produk Dibeli"
             << setw(8) << "Qty" << "Total Bayar" << endl;
        cetakGaris(100, '-');

        if (jumlahPesanan == 0) {
            cout << "[!] Belum ada barang yang dibeli / transaksi tercatat.\n";
        } else {
            double grandTotal = 0;
            for (int i = 0; i < jumlahPesanan; i++) {
                PesananMasuk& rp = riwayatPesanan[i];
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

    void cariBarangDibeliPerNama() {
        bersihkanLayar();
        string keyword;
        cout << "=== CARI TRANSAKSI BERDASARKAN NAMA PRODUK ===\n";
        cout << "Masukkan nama produk yang dicari: ";
        cin.ignore(1000, '\n');
        getline(cin, keyword);

        bersihkanLayar();
        cetakGaris(100, '=');
        cout << "HASIL PENCARIAN TRANSAKSI UNTUK: \"" << keyword << "\"\n";
        cetakGaris(100, '=');
        cout << left << setw(15) << "Pembeli" << setw(18) << "Toko" << setw(20) << "Produk Dibeli"
             << setw(8) << "Qty" << "Total Bayar" << endl;
        cetakGaris(100, '-');

        bool ditemukan = false;
        for (int i = 0; i < jumlahPesanan; i++) {
            PesananMasuk& rp = riwayatPesanan[i];
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

    void rekapTotalBarangTerjual() {
        bersihkanLayar();
        cetakGaris(80, '=');
        cout << "                REKAP TOTAL BARANG TERJUAL PER PRODUK\n";
        cetakGaris(80, '=');

        if (jumlahPesanan == 0) {
            cout << "[!] Belum ada data transaksi untuk direkap.\n"; tungguEnter(); return;
        }

        string namaProdukRekap[MAX_PESANAN];
        int totalQtyRekap[MAX_PESANAN];
        double totalOmzetRekap[MAX_PESANAN];
        int jumlahRekap = 0;

        for (int i = 0; i < jumlahPesanan; i++) {
            PesananMasuk& rp = riwayatPesanan[i];
            int idx = -1;
            for (int k = 0; k < jumlahRekap; k++) {
                if (namaProdukRekap[k] == rp.namaProduk) { idx = k; break; }
            }
            if (idx == -1) {
                namaProdukRekap[jumlahRekap] = rp.namaProduk;
                totalQtyRekap[jumlahRekap] = rp.jumlah;
                totalOmzetRekap[jumlahRekap] = rp.totalBayar;
                jumlahRekap++;
            } else {
                totalQtyRekap[idx] += rp.jumlah;
                totalOmzetRekap[idx] += rp.totalBayar;
            }
        }

        for (int a = 0; a < jumlahRekap - 1; a++) {
            for (int b = 0; b < jumlahRekap - 1 - a; b++) {
                if (toLowerStr(namaProdukRekap[b]) > toLowerStr(namaProdukRekap[b + 1])) {
                    string tmpNama = namaProdukRekap[b];
                    namaProdukRekap[b] = namaProdukRekap[b + 1];
                    namaProdukRekap[b + 1] = tmpNama;

                    int tmpQty = totalQtyRekap[b];
                    totalQtyRekap[b] = totalQtyRekap[b + 1];
                    totalQtyRekap[b + 1] = tmpQty;

                    double tmpOmzet = totalOmzetRekap[b];
                    totalOmzetRekap[b] = totalOmzetRekap[b + 1];
                    totalOmzetRekap[b + 1] = tmpOmzet;
                }
            }
        }

        cout << left << setw(25) << "Nama Produk" << setw(20) << "Total Terjual" << "Total Omzet" << endl;
        cetakGaris(80, '-');
        for (int k = 0; k < jumlahRekap; k++) {
            cout << left << setw(25) << namaProdukRekap[k]
                 << setw(20) << (to_string(totalQtyRekap[k]) + " pcs")
                 << "Rp " << fixed << setprecision(0) << totalOmzetRekap[k] << endl;
        }
        cetakGaris(80, '=');
        tungguEnter();
    }

    void cekBarangDibeli() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(73, '=');
            cout << "             RIWAYAT & REKAP BARANG YANG DIBELI (TRANSAKSI)\n";
            cetakGaris(73, '=');
            cout << "Total Transaksi Tercatat : " << jumlahPesanan << " transaksi\n";
            cetakGaris(73, '-');
            cout << "1. Tampilkan Semua Riwayat Transaksi\n";
            cout << "2. Cari Transaksi Berdasarkan Nama Produk\n";
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

    void updateStokPemasukan() {
        bersihkanLayar();
        int idP, jml;
        cout << "=== UPDATE STOK PEMASUKAN (RESTOCK) ===\n";
        cout << "Masukkan ID Produk: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                Produk& p = t.daftarProduk[j];
                if (p.id == idP) {
                    cout << "Produk Ditemukan: " << p.nama << " (Stok saat ini: " << p.stok << ")\n";
                    cout << "Jumlah Stok Masuk Baru: "; cin >> jml;

                    if (jml > 0) {
                        double totalBiaya = p.hargaBeli * jml;
                        if (t.keuangan.saldoKas >= totalBiaya) {
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

    void updateStokPengeluaran() {
        bersihkanLayar();
        int idP, jml;
        cout << "=== UPDATE STOK PENGELUARAN (PENGURANGAN) ===\n";
        cout << "Masukkan ID Produk: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                Produk& p = t.daftarProduk[j];
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
                            double pajak = pendapatan_bruto * 0.11;
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

    void tambahTokoBaru() {
        bersihkanLayar();
        cout << "=== TAMBAH TOKO BARU ===\n";

        if (jumlahToko >= MAX_TOKO) {
            cout << "[!] Kapasitas jaringan toko sudah penuh.\n"; tungguEnter(); return;
        }

        Toko t;
        cout << "ID Toko Baru (Angka): "; cin >> t.idToko;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }
        cin.ignore(1000, '\n');
        cout << "Nama Toko Baru      : "; getline(cin, t.namaToko);
        cout << "Kategori Utama Jual : "; getline(cin, t.kategoriDijual);

        t.ratingToko = 5.0;
        t.jumlahUlasan = 0;
        t.keuangan.saldoKas = 0;
        t.keuangan.totalPemasukan = 0;
        t.keuangan.totalPengeluaran = 0;
        t.keuangan.totalPajak = 0;
        t.jumlahProduk = 0;

        daftarTokoMarketplace[jumlahToko] = t;
        jumlahToko++;

        cout << "\n[Sukses] Toko baru berhasil didaftarkan ke jaringan.\n"; tungguEnter();
    }

    void hapusToko() {
        bersihkanLayar();
        int id;
        cout << "=== HAPUS TOKO ===\n";
        cout << "Masukkan ID Toko yang mau dihapus: "; cin >> id;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            if (daftarTokoMarketplace[i].idToko == id) {
                for (int k = i; k < jumlahToko - 1; k++) {
                    daftarTokoMarketplace[k] = daftarTokoMarketplace[k + 1];
                }
                jumlahToko--;
                cout << "[Sukses] Jaringan toko berhasil dihapus dari sistem.\n"; tungguEnter(); return;
            }
        }
        cout << "[!] Gagal menghapus. ID Toko tidak valid.\n"; tungguEnter();
    }

    void menuManajemenToko() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "           MANAJEMEN TOKO (STRUKTUR TOKO)\n";
            cetakGaris(60, '=');
            cout << "1. Tambah Toko Baru\n";
            cout << "2. Hapus Toko Lama\n";
            cout << "3. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih tindakan (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: tambahTokoBaru(); break;
                case 2: hapusToko(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 3);
    }

    void tambahProdukKeToko() {
        bersihkanLayar();
        cout << "=== TAMBAH PRODUK BARU ===\n";
        if (jumlahToko == 0) {
            cout << "[!] Belum ada toko. Tambahkan toko terlebih dahulu.\n"; tungguEnter(); return;
        }
        cout << "Daftar Toko Tersedia:\n";
        for (int i = 0; i < jumlahToko; i++) {
            cout << " - [" << daftarTokoMarketplace[i].idToko << "] " << daftarTokoMarketplace[i].namaToko << "\n";
        }
        cetakGaris(40, '-');

        int idT;
        cout << "Masukkan ID Toko tujuan: "; cin >> idT;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            if (daftarTokoMarketplace[i].idToko == idT) {
                Toko& t = daftarTokoMarketplace[i];

                if (t.jumlahProduk >= MAX_PRODUK) {
                    cout << "\n[!] Kapasitas produk pada toko ini sudah penuh.\n"; tungguEnter(); return;
                }

                Produk p;
                cout << "ID Produk Baru (Angka): "; cin >> p.id;

                for (int j = 0; j < t.jumlahProduk; j++) {
                    if (t.daftarProduk[j].id == p.id) {
                        cout << "\n[!] ID Produk sudah digunakan di toko ini. Gunakan ID lain.\n"; tungguEnter(); return;
                    }
                }

                cin.ignore(1000, '\n');
                cout << "Nama Barang           : "; getline(cin, p.nama);
                cout << "Kategori Barang       : "; getline(cin, p.kategori);
                cout << "Harga Modal (Beli)    : Rp "; cin >> p.hargaBeli;
                cout << "Harga Jual Konsumen   : Rp "; cin >> p.hargaJual;
                cout << "Stok Awal             : "; cin >> p.stok;

                if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "\n[!] Input angka tidak valid. Produk dibatalkan.\n"; tungguEnter(); return; }

                t.daftarProduk[t.jumlahProduk] = p;
                t.jumlahProduk++;

                cout << "\n[Sukses] Produk terintegrasi ke dalam toko " << t.namaToko << ".\n"; tungguEnter(); return;
            }
        }
        cout << "[!] ID Toko salah.\n"; tungguEnter();
    }

    void lihatDetailProduk() {
        bersihkanLayar();
        cout << "=== LIHAT DETAIL PRODUK ===\n";
        int idP;
        cout << "Masukkan ID Produk: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                Produk& p = t.daftarProduk[j];
                if (p.id == idP) {
                    bersihkanLayar();
                    cetakGaris(50, '=');
                    cout << "          DETAIL PRODUK\n";
                    cetakGaris(50, '=');
                    cout << " ID Produk    : " << p.id << "\n";
                    cout << " Nama         : " << p.nama << "\n";
                    cout << " Kategori     : " << p.kategori << "\n";
                    cout << " Toko Pemilik : " << t.namaToko << " (ID " << t.idToko << ")\n";
                    cout << " Harga Beli   : Rp " << fixed << setprecision(0) << p.hargaBeli << "\n";
                    cout << " Harga Jual   : Rp " << p.hargaJual << "\n";
                    cout << " Stok         : " << p.stok << " pcs\n";
                    cout << " Estimasi Margin per Unit : Rp " << (p.hargaJual - p.hargaBeli) << "\n";
                    cetakGaris(50, '=');
                    tungguEnter(); return;
                }
            }
        }
        cout << "[!] ID Produk tidak ditemukan.\n"; tungguEnter();
    }

    void editProdukToko() {
        bersihkanLayar();
        cout << "=== EDIT DATA PRODUK ===\n";
        int idP;
        cout << "Masukkan ID Produk yang mau diedit: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                Produk& p = t.daftarProduk[j];
                if (p.id == idP) {
                    bersihkanLayar();
                    cout << "Mengedit Produk: " << p.nama << " (Toko: " << t.namaToko << ")\n";
                    cetakGaris(50, '-');
                    cout << "Kosongkan input (langsung ENTER) jika tidak ingin mengubah field tersebut.\n\n";

                    cin.ignore(1000, '\n');
                    string inputStr;

                    cout << "Nama Baru [" << p.nama << "]: ";
                    getline(cin, inputStr);
                    if (!inputStr.empty()) p.nama = inputStr;

                    cout << "Kategori Baru [" << p.kategori << "]: ";
                    getline(cin, inputStr);
                    if (!inputStr.empty()) p.kategori = inputStr;

                    cout << "Harga Beli Baru [" << fixed << setprecision(0) << p.hargaBeli << "] (0 = tidak diubah): ";
                    getline(cin, inputStr);
                    if (!inputStr.empty()) {
                        double val = atof(inputStr.c_str());
                        if (val > 0) p.hargaBeli = val;
                    }

                    cout << "Harga Jual Baru [" << fixed << setprecision(0) << p.hargaJual << "] (0 = tidak diubah): ";
                    getline(cin, inputStr);
                    if (!inputStr.empty()) {
                        double val = atof(inputStr.c_str());
                        if (val > 0) p.hargaJual = val;
                    }

                    cout << "Stok Baru [" << p.stok << "] (-1 = tidak diubah): ";
                    getline(cin, inputStr);
                    if (!inputStr.empty()) {
                        int val = atoi(inputStr.c_str());
                        if (val >= 0) p.stok = val;
                    }

                    cout << "\n[Sukses] Data produk berhasil diperbarui.\n"; tungguEnter(); return;
                }
            }
        }
        cout << "[!] ID Produk tidak ditemukan.\n"; tungguEnter();
    }

    void hapusProduk() {
        bersihkanLayar();
        cout << "=== HAPUS PRODUK ===\n";
        int idP;
        cout << "Masukkan ID Produk yang mau dihapus: "; cin >> idP;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Input harus angka!\n"; tungguEnter(); return; }

        for (int i = 0; i < jumlahToko; i++) {
            Toko& t = daftarTokoMarketplace[i];
            for (int j = 0; j < t.jumlahProduk; j++) {
                if (t.daftarProduk[j].id == idP) {
                    cout << "Yakin hapus produk \"" << t.daftarProduk[j].nama << "\" dari toko " << t.namaToko << "? (y/n): ";
                    char konfirmasi; cin >> konfirmasi;
                    if (tolower(konfirmasi) == 'y') {
                        for (int k = j; k < t.jumlahProduk - 1; k++) {
                            t.daftarProduk[k] = t.daftarProduk[k + 1];
                        }
                        t.jumlahProduk--;
                        cout << "\n[Sukses] SKU Produk berhasil ditiadaan.\n";
                    } else {
                        cout << "\n[Info] Penghapusan dibatalkan.\n";
                    }
                    tungguEnter(); return;
                }
            }
        }
        cout << "[!] ID Produk tidak ditemukan.\n"; tungguEnter();
    }

    void menuManajemenProduk() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "               MANAJEMEN PRODUK\n";
            cetakGaris(60, '=');
            cout << "1. Tambah Produk Baru ke Toko\n";
            cout << "2. Lihat Detail Produk (Berdasarkan ID)\n";
            cout << "3. Edit Data Produk\n";
            cout << "4. Hapus Produk\n";
            cout << "5. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih tindakan (1-5): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }
            switch (pil) {
                case 1: tambahProdukKeToko(); break;
                case 2: lihatDetailProduk(); break;
                case 3: editProdukToko(); break;
                case 4: hapusProduk(); break;
                case 5: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 5);
    }

    // ==========================================
    //          IMPLEMENTASI SUBSISTEM BARU
    // ==========================================
    void lihatPengiriman() {
        bersihkanLayar();
        cetakGaris(75, '=');
        cout << "                  DATA PENGIRIMAN BARANG\n";
        cetakGaris(75, '=');
        
        if (jumlahPengiriman == 0) {
            cout << "[!] Belum ada data pengiriman.\n";
        } else {
            cout << left << setw(15) << "No Resi" << setw(20) << "Pembeli" << setw(15) << "Kurir" << "Status\n";
            cetakGaris(75, '-');
            for(int i=0; i<jumlahPengiriman; i++) {
                cout << left << setw(15) << daftarPengiriman[i].noResi
                     << setw(20) << daftarPengiriman[i].namaPembeli
                     << setw(15) << daftarPengiriman[i].namaEkspedisi
                     << daftarPengiriman[i].status << "\n";
            }
        }
        cetakGaris(75, '=');
        tungguEnter();
    }

    void updateStatusPengiriman() {
        bersihkanLayar();
        string resi;
        cout << "=== UPDATE STATUS RESI ===\n";
        cout << "Masukkan Nomor Resi: "; cin >> resi;

        for(int i=0; i<jumlahPengiriman; i++) {
            if(daftarPengiriman[i].noResi == resi) {
                cout << "Resi ditemukan! Status saat ini: " << daftarPengiriman[i].status << "\n";
                cout << "Masukkan Status Baru (Diproses/Dikirim/Selesai/Gagal): ";
                cin >> daftarPengiriman[i].status;
                cout << "\n[Sukses] Status pengiriman diperbarui.\n";
                tungguEnter(); return;
            }
        }
        cout << "[!] Resi tidak ditemukan.\n"; tungguEnter();
    }

    void menuLogistik() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "           SISTEM LOGISTIK & PENGIRIMAN\n";
            cetakGaris(60, '=');
            cout << "1. Lacak Semua Pengiriman\n";
            cout << "2. Update Status Resi\n";
            cout << "3. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

            switch (pil) {
                case 1: lihatPengiriman(); break;
                case 2: updateStatusPengiriman(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 3);
    }

    void lihatSuplier() {
        bersihkanLayar();
        cetakGaris(85, '=');
        cout << "                                 DAFTAR MITRA SUPLIER\n";
        cetakGaris(85, '=');
        if (jumlahSuplier == 0) {
            cout << "[!] Belum ada suplier terdaftar.\n";
        } else {
            cout << left << setw(5) << "ID" << setw(25) << "Nama Suplier" << setw(15) << "Kategori" << setw(15) << "Kontak" << "Alamat\n";
            cetakGaris(85, '-');
            for(int i=0; i<jumlahSuplier; i++) {
                cout << left << setw(5) << daftarSuplier[i].id 
                     << setw(25) << daftarSuplier[i].nama
                     << setw(15) << daftarSuplier[i].kategoriSupply 
                     << setw(15) << daftarSuplier[i].kontak
                     << daftarSuplier[i].alamat << "\n";
            }
        }
        cetakGaris(85, '=');
        tungguEnter();
    }

    void tambahSuplier() {
        bersihkanLayar();
        if (jumlahSuplier >= MAX_SUPLIER) {
            cout << "[!] Kapasitas data suplier penuh.\n"; tungguEnter(); return;
        }
        cout << "=== TAMBAH SUPLIER BARU ===\n";
        Suplier s;
        cout << "ID Suplier (Angka): "; cin >> s.id;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Harus angka.\n"; tungguEnter(); return; }
        cin.ignore(1000, '\n');
        
        cout << "Nama Suplier : "; getline(cin, s.nama);
        cout << "Kontak (No)  : "; getline(cin, s.kontak);
        cout << "Alamat       : "; getline(cin, s.alamat);
        cout << "Kategori Brg : "; getline(cin, s.kategoriSupply);
        
        daftarSuplier[jumlahSuplier] = s;
        jumlahSuplier++;
        cout << "\n[Sukses] Data suplier berhasil disimpan.\n";
        tungguEnter();
    }

    void menuSuplier() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "           MANAJEMEN SUPLIER (PEMASOK)\n";
            cetakGaris(60, '=');
            cout << "1. Lihat Daftar Suplier\n";
            cout << "2. Tambah Suplier Baru\n";
            cout << "3. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

            switch (pil) {
                case 1: lihatSuplier(); break;
                case 2: tambahSuplier(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 3);
    }

    void lihatKaryawan() {
        bersihkanLayar();
        cetakGaris(80, '=');
        cout << "                         DATA KARYAWAN PERUSAHAAN\n";
        cetakGaris(80, '=');
        if (jumlahKaryawan == 0) {
            cout << "[!] Belum ada data karyawan.\n";
        } else {
            cout << left << setw(5) << "ID" << setw(20) << "Nama" << setw(20) << "Jabatan" << setw(15) << "Gaji Bulanan" << "Status\n";
            cetakGaris(80, '-');
            for (int i=0; i<jumlahKaryawan; i++) {
                cout << left << setw(5) << daftarKaryawan[i].id 
                     << setw(20) << daftarKaryawan[i].nama
                     << setw(20) << daftarKaryawan[i].jabatan 
                     << "Rp " << setw(12) << fixed << setprecision(0) << daftarKaryawan[i].gajiBulan
                     << daftarKaryawan[i].status << "\n";
            }
        }
        cetakGaris(80, '=');
        tungguEnter();
    }

    void tambahKaryawan() {
        bersihkanLayar();
        if (jumlahKaryawan >= MAX_KARYAWAN) {
            cout << "[!] Kapasitas pegawai penuh.\n"; tungguEnter(); return;
        }
        cout << "=== REKRUT KARYAWAN BARU ===\n";
        Karyawan k;
        cout << "ID Karyawan  : "; cin >> k.id;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "[!] Harus angka.\n"; tungguEnter(); return; }
        cin.ignore(1000, '\n');
        
        cout << "Nama         : "; getline(cin, k.nama);
        cout << "Jabatan      : "; getline(cin, k.jabatan);
        cout << "Gaji Bulanan : Rp "; cin >> k.gajiBulan;
        k.status = "Aktif";
        
        daftarKaryawan[jumlahKaryawan] = k;
        jumlahKaryawan++;
        cout << "\n[Sukses] Karyawan baru berhasil diregistrasi.\n";
        tungguEnter();
    }

    void bayarGajiKaryawan() {
        bersihkanLayar();
        cout << "=== PEMBAYARAN GAJI KARYAWAN ===\n";
        int idK, idT;
        
        cout << "Daftar Toko sebagai Sumber Dana:\n";
        for(int i=0; i<jumlahToko; i++) cout << "- ID: " << daftarTokoMarketplace[i].idToko << " | Nama: " << daftarTokoMarketplace[i].namaToko << "\n";
        
        cout << "\nMasukkan ID Toko (Sumber Dana): "; cin >> idT;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); return; }
        
        Toko* tokoPembayar = nullptr;
        for(int i=0; i<jumlahToko; i++) {
            if(daftarTokoMarketplace[i].idToko == idT) tokoPembayar = &daftarTokoMarketplace[i];
        }
        
        if(!tokoPembayar) {
            cout << "[!] ID Toko tidak valid.\n"; tungguEnter(); return;
        }
        
        cout << "Masukkan ID Karyawan yang akan dibayar: "; cin >> idK;
        for(int i=0; i<jumlahKaryawan; i++) {
            if(daftarKaryawan[i].id == idK) {
                if(tokoPembayar->keuangan.saldoKas >= daftarKaryawan[i].gajiBulan) {
                    tokoPembayar->keuangan.saldoKas -= daftarKaryawan[i].gajiBulan;
                    tokoPembayar->keuangan.totalPengeluaran += daftarKaryawan[i].gajiBulan;
                    cout << "\n[Sukses] Gaji senilai Rp " << fixed << setprecision(0) << daftarKaryawan[i].gajiBulan 
                         << " berhasil dibayarkan kepada " << daftarKaryawan[i].nama << ".\n";
                    cout << "Sisa Kas Toko " << tokoPembayar->namaToko << ": Rp " << tokoPembayar->keuangan.saldoKas << "\n";
                } else {
                    cout << "\n[!] Gagal. Saldo Kas Toko tidak mencukupi!\n";
                }
                tungguEnter(); return;
            }
        }
        cout << "[!] ID Karyawan tidak ditemukan.\n"; tungguEnter();
    }

    void menuSDM() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "           SDM & MANAJEMEN KARYAWAN\n";
            cetakGaris(60, '=');
            cout << "1. Lihat Data Karyawan\n";
            cout << "2. Tambah Karyawan Baru\n";
            cout << "3. Bayar Gaji (Potong Kas Toko)\n";
            cout << "4. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih menu (1-4): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

            switch (pil) {
                case 1: lihatKaryawan(); break;
                case 2: tambahKaryawan(); break;
                case 3: bayarGajiKaryawan(); break;
                case 4: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 4);
    }

    void lihatRetur() {
        bersihkanLayar();
        cetakGaris(85, '=');
        cout << "                     DAFTAR PENGAJUAN RETUR BARANG\n";
        cetakGaris(85, '=');
        if (jumlahRetur == 0) {
            cout << "[!] Belum ada pengajuan retur.\n";
        } else {
            cout << left << setw(8) << "ID Rtr" << setw(18) << "Pembeli" << setw(20) << "Produk" << setw(25) << "Alasan" << "Status\n";
            cetakGaris(85, '-');
            for(int i=0; i<jumlahRetur; i++) {
                cout << left << setw(8) << daftarRetur[i].idRetur 
                     << setw(18) << daftarRetur[i].namaPembeli
                     << setw(20) << daftarRetur[i].namaProduk 
                     << setw(25) << daftarRetur[i].alasan 
                     << daftarRetur[i].status << "\n";
            }
        }
        cetakGaris(85, '=');
        tungguEnter();
    }

    void prosesRetur() {
        bersihkanLayar();
        int idR; 
        cout << "=== PROSES KEPUTUSAN RETUR ===\n";
        cout << "Masukkan ID Retur: "; cin >> idR;
        
        for(int i=0; i<jumlahRetur; i++) {
            if(daftarRetur[i].idRetur == idR) {
                if (daftarRetur[i].status != "Menunggu") {
                    cout << "[!] Retur ini sudah berstatus: " << daftarRetur[i].status << ".\n";
                    tungguEnter(); return;
                }
                cout << "\nDetail Alasan Customer: " << daftarRetur[i].alasan << "\n";
                cout << "Terima ajuan retur ini? (y/n): ";
                char c; cin >> c;
                if(c == 'y' || c == 'Y') {
                    daftarRetur[i].status = "Disetujui";
                    cout << "\n[Sukses] Retur Disetujui.\n";
                    cout << "!! WARNING: Pastikan Admin melakukan penyesuaian Stok (Tambah Inbound) di Menu Manajemen Produk !!\n";
                } else {
                    daftarRetur[i].status = "Ditolak";
                    cout << "\n[Info] Retur Ditolak.\n";
                }
                tungguEnter(); return;
            }
        }
        cout << "[!] ID Retur tidak ditemukan.\n"; tungguEnter();
    }

    void menuRetur() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "           SISTEM RETUR BARANG (RMA)\n";
            cetakGaris(60, '=');
            cout << "1. Lihat Daftar Pengajuan Retur\n";
            cout << "2. Proses Keputusan Retur\n";
            cout << "3. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

            switch (pil) {
                case 1: lihatRetur(); break;
                case 2: prosesRetur(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 3);
    }

    void lihatKomplain() {
        bersihkanLayar();
        cetakGaris(80, '=');
        cout << "                      TIKET KOMPLAIN PELANGGAN\n";
        cetakGaris(80, '=');
        if (jumlahKomplain == 0) {
            cout << "[!] Belum ada tiket komplain.\n";
        } else {
            for(int i=0; i<jumlahKomplain; i++) {
                cout << "ID Tiket : " << daftarKomplain[i].idKomplain << " [" << daftarKomplain[i].status << "]\n";
                cout << "Customer : " << daftarKomplain[i].namaCustomer << "\n";
                cout << "Perihal  : " << daftarKomplain[i].perihal << "\n";
                cout << "Pesan    : " << daftarKomplain[i].pesan << "\n";
                cout << "Balasan  : " << daftarKomplain[i].balasanAdmin << "\n";
                cetakGaris(80, '-');
            }
        }
        tungguEnter();
    }

    void balasKomplain() {
        bersihkanLayar();
        int idK; 
        cout << "=== BALAS TIKET KOMPLAIN ===\n";
        cout << "Masukkan ID Tiket: "; cin >> idK; 
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); return; }
        cin.ignore(1000, '\n');
        
        for(int i=0; i<jumlahKomplain; i++) {
            if(daftarKomplain[i].idKomplain == idK) {
                cout << "Pesan Customer : " << daftarKomplain[i].pesan << "\n";
                cout << "Ketik Balasan Admin : "; 
                getline(cin, daftarKomplain[i].balasanAdmin);
                
                cout << "Tutup tiket ini (Ubah status ke Closed)? (y/n): "; 
                char c; cin >> c;
                if(c == 'y' || c == 'Y') {
                    daftarKomplain[i].status = "Closed";
                }
                cout << "\n[Sukses] Tiket komplain berhasil direspon.\n";
                tungguEnter(); return;
            }
        }
        cout << "[!] ID Tiket tidak valid.\n"; tungguEnter();
    }

    void menuCS() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "           CUSTOMER SERVICE & TIKET KOMPLAIN\n";
            cetakGaris(60, '=');
            cout << "1. Lihat Tiket Komplain Masuk\n";
            cout << "2. Balas Komplain Pelanggan\n";
            cout << "3. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

            switch (pil) {
                case 1: lihatKomplain(); break;
                case 2: balasKomplain(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 3);
    }

    void lihatVoucher() {
        bersihkanLayar();
        cetakGaris(60, '=');
        cout << "                 DAFTAR KODE VOUCHER\n";
        cetakGaris(60, '=');
        if (jumlahVoucher == 0) {
            cout << "[!] Belum ada voucher yang dibuat.\n";
        } else {
            cout << left << setw(20) << "Kode Voucher" << setw(15) << "Diskon (%)" << setw(10) << "Kuota" << "Status\n";
            cetakGaris(60, '-');
            for(int i=0; i<jumlahVoucher; i++) {
                cout << left << setw(20) << daftarVoucher[i].kode 
                     << setw(15) << daftarVoucher[i].persenDiskon
                     << setw(10) << daftarVoucher[i].kuota 
                     << (daftarVoucher[i].aktif ? "Aktif" : "Nonaktif") << "\n";
            }
        }
        cetakGaris(60, '=');
        tungguEnter();
    }

    void tambahVoucher() {
        bersihkanLayar();
        if (jumlahVoucher >= MAX_VOUCHER) {
            cout << "[!] Kapasitas database voucher penuh.\n"; tungguEnter(); return;
        }
        Voucher v;
        cout << "=== BUAT VOUCHER BARU ===\n";
        cout << "Kode Promo (Cth: MERDEKA) : "; cin >> v.kode;
        cout << "Persentase Diskon (%)     : "; cin >> v.persenDiskon;
        cout << "Batas Kuota Pemakaian     : "; cin >> v.kuota;
        v.aktif = true;
        
        daftarVoucher[jumlahVoucher] = v;
        jumlahVoucher++;
        cout << "\n[Sukses] Voucher baru berhasil diaktifkan.\n";
        tungguEnter();
    }

    void menuPromosi() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "           SISTEM PROMOSI & VOUCHER\n";
            cetakGaris(60, '=');
            cout << "1. Lihat Daftar Voucher Aktif\n";
            cout << "2. Buat Voucher Baru\n";
            cout << "3. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

            switch (pil) {
                case 1: lihatVoucher(); break;
                case 2: tambahVoucher(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 3);
    }

    void laporanStokMenipis() {
        bersihkanLayar();
        cetakGaris(75, '=');
        cout << "            PERINGATAN STOK KRITIS / MENIPIS (<= 10 pcs)\n";
        cetakGaris(75, '=');
        
        bool adaKritis = false;
        cout << left << setw(18) << "Toko" << setw(25) << "Nama Produk" << setw(15) << "Kategori" << "Sisa Stok\n";
        cetakGaris(75, '-');
        
        for (int i = 0; i < jumlahToko; i++) {
            for (int j = 0; j < daftarTokoMarketplace[i].jumlahProduk; j++) {
                Produk& p = daftarTokoMarketplace[i].daftarProduk[j];
                if (p.stok <= 10) {
                    cout << left << setw(18) << daftarTokoMarketplace[i].namaToko 
                         << setw(25) << p.nama 
                         << setw(15) << p.kategori 
                         << p.stok << " pcs\n";
                    adaKritis = true;
                }
            }
        }
        
        if(!adaKritis) {
            cout << "\n[Info] Semua stok produk pada seluruh toko dalam kondisi aman (> 10).\n";
        } else {
            cout << "\n[!] Segera lakukan Restock via Modul Update Stok Pemasukan!\n";
        }
        cetakGaris(75, '=');
        tungguEnter();
    }

    void laporanPajakGabungan() {
        bersihkanLayar();
        cetakGaris(70, '=');
        cout << "         LAPORAN KEWAJIBAN PAJAK KESELURUHAN (PPN 11%)\n";
        cetakGaris(70, '=');
        
        double totalPajakGlobal = 0;
        cout << left << setw(20) << "Nama Toko" << "Akumulasi Pajak Terhutang\n";
        cetakGaris(70, '-');
        
        for (int i = 0; i < jumlahToko; i++) {
            cout << left << setw(20) << daftarTokoMarketplace[i].namaToko 
                 << "Rp " << fixed << setprecision(0) << daftarTokoMarketplace[i].keuangan.totalPajak << "\n";
            totalPajakGlobal += daftarTokoMarketplace[i].keuangan.totalPajak;
        }
        cetakGaris(70, '-');
        cout << "TOTAL PAJAK YANG HARUS DISETORKAN KE NEGARA : Rp " << fixed << setprecision(0) << totalPajakGlobal << "\n";
        cetakGaris(70, '=');
        tungguEnter();
    }

    void menuAnalitik() {
        int pil;
        do {
            bersihkanLayar();
            cetakGaris(60, '=');
            cout << "           ANALITIK & LAPORAN LANJUT\n";
            cetakGaris(60, '=');
            cout << "1. Laporan Deteksi Stok Kritis (Menipis)\n";
            cout << "2. Laporan Kewajiban Pajak Global\n";
            cout << "3. Kembali ke Menu Utama\n";
            cetakGaris(60, '-');
            cout << "Pilih menu (1-3): "; cin >> pil;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); pil = 0; continue; }

            switch (pil) {
                case 1: laporanStokMenipis(); break;
                case 2: laporanPajakGabungan(); break;
                case 3: break;
                default: cout << "[!] Pilihan salah!\n"; tungguEnter();
            }
        } while (pil != 3);
    }

    void menuUtamaAdmin() {
        bersihkanLayar();
        int pilihan;
        cetakGaris(65, '=');
        cout << "                ADMIN TOKO CERAN_HUB\n";
        cetakGaris(65, '=');
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
        cetakGaris(65, '-');
        cout << "Pilih menu: "; cin >> pilihan;

        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "[!] Masukkan angka!\n"; tungguEnter(); return;
        }

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
                cout << "\n[Sukses] Berhasil keluar dari panel admin.\n"; tungguEnter(); break;
            default: cout << "[!] Pilihan salah!\n"; tungguEnter();
        }
    }

public:
    // Constructor untuk inisialisasi awal database data marketplace statis
    SistemECommerceMall() {
        // --- Toko 1: uniqlo ---
        Toko& uniqlo = daftarTokoMarketplace[jumlahToko++];
        uniqlo.idToko = 101;
        uniqlo.namaToko = "uniqlo";
        uniqlo.kategoriDijual = "pakaian";
        uniqlo.ratingToko = 4.8;
        uniqlo.jumlahUlasan = 1;
        uniqlo.keuangan.saldoKas = 5000000;
        uniqlo.keuangan.totalPemasukan = 1500000;
        uniqlo.keuangan.totalPengeluaran = 500000;
        uniqlo.keuangan.totalPajak = 165000;
        uniqlo.jumlahProduk = 0;

        uniqlo.daftarProduk[uniqlo.jumlahProduk].id = 101;
        uniqlo.daftarProduk[uniqlo.jumlahProduk].nama = "Celana Jeans";
        uniqlo.daftarProduk[uniqlo.jumlahProduk].kategori = "pakaian";
        uniqlo.daftarProduk[uniqlo.jumlahProduk].hargaBeli = 80000;
        uniqlo.daftarProduk[uniqlo.jumlahProduk].hargaJual = 120000;
        uniqlo.daftarProduk[uniqlo.jumlahProduk].stok = 40;
        uniqlo.jumlahProduk++;

        uniqlo.daftarProduk[uniqlo.jumlahProduk].id = 106;
        uniqlo.daftarProduk[uniqlo.jumlahProduk].nama = "Kemeja Polos";
        uniqlo.daftarProduk[uniqlo.jumlahProduk].kategori = "pakaian";
        uniqlo.daftarProduk[uniqlo.jumlahProduk].hargaBeli = 70000;
        uniqlo.daftarProduk[uniqlo.jumlahProduk].hargaJual = 125000;
        uniqlo.daftarProduk[uniqlo.jumlahProduk].stok = 5;
        uniqlo.jumlahProduk++;

        // --- Toko 2: holland bakery ---
        Toko& holland = daftarTokoMarketplace[jumlahToko++];
        holland.idToko = 102;
        holland.namaToko = "holland bakery";
        holland.kategoriDijual = "makanan";
        holland.ratingToko = 4.5;
        holland.jumlahUlasan = 1;
        holland.keuangan.saldoKas = 3000000;
        holland.keuangan.totalPemasukan = 800000;
        holland.keuangan.totalPengeluaran = 300000;
        holland.keuangan.totalPajak = 88000;
        holland.jumlahProduk = 0;

        holland.daftarProduk[holland.jumlahProduk].id = 102;
        holland.daftarProduk[holland.jumlahProduk].nama = "Roti Cokelat";
        holland.daftarProduk[holland.jumlahProduk].kategori = "makanan";
        holland.daftarProduk[holland.jumlahProduk].hargaBeli = 7000;
        holland.daftarProduk[holland.jumlahProduk].hargaJual = 12000;
        holland.daftarProduk[holland.jumlahProduk].stok = 25;
        holland.jumlahProduk++;

        holland.daftarProduk[holland.jumlahProduk].id = 103;
        holland.daftarProduk[holland.jumlahProduk].nama = "Susu Kotak UHT";
        holland.daftarProduk[holland.jumlahProduk].kategori = "minuman";
        holland.daftarProduk[holland.jumlahProduk].hargaBeli = 4000;
        holland.daftarProduk[holland.jumlahProduk].hargaJual = 6500;
        holland.daftarProduk[holland.jumlahProduk].stok = 100;
        holland.jumlahProduk++;

        // --- Transaksi Awal ---
        riwayatPesanan[jumlahPesanan].namaPembeli = "Budi Santoso";
        riwayatPesanan[jumlahPesanan].alamatPembeli = "Jl. Merdeka No. 45, Jakarta";
        riwayatPesanan[jumlahPesanan].namaToko = "uniqlo";
        riwayatPesanan[jumlahPesanan].namaProduk = "Kemeja Polos";
        riwayatPesanan[jumlahPesanan].jumlah = 2;
        riwayatPesanan[jumlahPesanan].totalBayar = 250000;
        jumlahPesanan++;

        riwayatPesanan[jumlahPesanan].namaPembeli = "Budi Santoso";
        riwayatPesanan[jumlahPesanan].alamatPembeli = "Jl. Merdeka No. 45, Jakarta";
        riwayatPesanan[jumlahPesanan].namaToko = "uniqlo";
        riwayatPesanan[jumlahPesanan].namaProduk = "Celana Jeans";
        riwayatPesanan[jumlahPesanan].jumlah = 1;
        riwayatPesanan[jumlahPesanan].totalBayar = 120000;
        jumlahPesanan++;

        riwayatPesanan[jumlahPesanan].namaPembeli = "Siti Aminah";
        riwayatPesanan[jumlahPesanan].alamatPembeli = "Jl. Anggrek Raya No. 12, Bandung";
        riwayatPesanan[jumlahPesanan].namaToko = "holland bakery";
        riwayatPesanan[jumlahPesanan].namaProduk = "Roti Cokelat";
        riwayatPesanan[jumlahPesanan].jumlah = 5;
        riwayatPesanan[jumlahPesanan].totalBayar = 60000;
        jumlahPesanan++;

        // Suplier
        daftarSuplier[jumlahSuplier].id = 1;
        daftarSuplier[jumlahSuplier].nama = "PT Sandang Nusantara";
        daftarSuplier[jumlahSuplier].kontak = "08123456789";
        daftarSuplier[jumlahSuplier].alamat = "Bandung";
        daftarSuplier[jumlahSuplier].kategoriSupply = "pakaian";
        jumlahSuplier++;

        daftarSuplier[jumlahSuplier].id = 2;
        daftarSuplier[jumlahSuplier].nama = "CV Pangan Makmur";
        daftarSuplier[jumlahSuplier].kontak = "08987654321";
        daftarSuplier[jumlahSuplier].alamat = "Jakarta";
        daftarSuplier[jumlahSuplier].kategoriSupply = "makanan";
        jumlahSuplier++;

        // Karyawan
        daftarKaryawan[jumlahKaryawan].id = 101;
        daftarKaryawan[jumlahKaryawan].nama = "Ahmad Subarjo";
        daftarKaryawan[jumlahKaryawan].jabatan = "Admin Gudang";
        daftarKaryawan[jumlahKaryawan].gajiBulan = 3500000;
        daftarKaryawan[jumlahKaryawan].status = "Aktif";
        jumlahKaryawan++;

        daftarKaryawan[jumlahKaryawan].id = 102;
        daftarKaryawan[jumlahKaryawan].nama = "Siti Nurhaliza";
        daftarKaryawan[jumlahKaryawan].jabatan = "Customer Service";
        daftarKaryawan[jumlahKaryawan].gajiBulan = 3200000;
        daftarKaryawan[jumlahKaryawan].status = "Aktif";
        jumlahKaryawan++;

        // Voucher
        daftarVoucher[jumlahVoucher].kode = "GRATISONGKIR";
        daftarVoucher[jumlahVoucher].persenDiskon = 10.0;
        daftarVoucher[jumlahVoucher].kuota = 50;
        daftarVoucher[jumlahVoucher].aktif = true;
        jumlahVoucher++;

        daftarVoucher[jumlahVoucher].kode = "DISKON50";
        daftarVoucher[jumlahVoucher].persenDiskon = 50.0;
        daftarVoucher[jumlahVoucher].kuota = 5;
        daftarVoucher[jumlahVoucher].aktif = true;
        jumlahVoucher++;

        // Pengiriman
        daftarPengiriman[jumlahPengiriman].noResi = "JNT123456";
        daftarPengiriman[jumlahPengiriman].namaPembeli = "Budi Santoso";
        daftarPengiriman[jumlahPengiriman].namaEkspedisi = "J&T Express";
        daftarPengiriman[jumlahPengiriman].status = "Dikirim";
        jumlahPengiriman++;

        daftarPengiriman[jumlahPengiriman].noResi = "JNE987654";
        daftarPengiriman[jumlahPengiriman].namaPembeli = "Siti Aminah";
        daftarPengiriman[jumlahPengiriman].namaEkspedisi = "JNE";
        daftarPengiriman[jumlahPengiriman].status = "Diproses";
        jumlahPengiriman++;

        // Komplain
        daftarKomplain[jumlahKomplain].idKomplain = 1;
        daftarKomplain[jumlahKomplain].namaCustomer = "Budi Santoso";
        daftarKomplain[jumlahKomplain].perihal = "Barang Cacat";
        daftarKomplain[jumlahKomplain].pesan = "Kemeja ada sobekan sedikit di lengan.";
        daftarKomplain[jumlahKomplain].balasanAdmin = "Belum ada balasan.";
        daftarKomplain[jumlahKomplain].status = "Open";
        jumlahKomplain++;
        
        // Retur
        daftarRetur[jumlahRetur].idRetur = 1;
        daftarRetur[jumlahRetur].namaPembeli = "Budi Santoso";
        daftarRetur[jumlahRetur].namaProduk = "Kemeja Polos";
        daftarRetur[jumlahRetur].alasan = "Barang Sobek di Lengan";
        daftarRetur[jumlahRetur].status = "Menunggu";
        jumlahRetur++;
    }

    // Metode utama untuk memicu runtime loop aplikasi
    void jalankanSistem() {
        while (true) {
            if (!isLoggedIn) {
                bersihkanLayar();
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
                cout << "               Welcome to CERAN_HUB Admin Store                      \n";
                cout << "=========================================================================\n";
                cout << "\033[0m";

                if (!sudahRegistrasi) {
                    cout << "1. Registrasi Akun Utama Admin\n";
                    cout << "2. Login Admin\n";
                    cout << "3. Keluar Aplikasi\n";
                    cetakGaris(73, '-');
                    cout << "Pilih Opsi (1-3): "; cin >> pilihan;

                    if (cin.fail()) {
                        cin.clear(); cin.ignore(1000, '\n');
                        cout << "[!] Input harus angka!\n"; tungguEnter(); continue;
                    }
                    switch (pilihan) {
                        case 1: registrasiAkunToko(); break;
                        case 2: loginAkunToko(); break;
                        case 3: cout << "\nTerima kasih!\n"; exit(0);
                        default: cout << "[!] Opsi salah!\n"; tungguEnter();
                    }
                } else {
                    cout << "1. Login Admin\n";
                    cout << "2. Keluar Aplikasi\n";
                    cetakGaris(73, '-');
                    cout << "Pilih Opsi (1-2): "; cin >> pilihan;

                    if (cin.fail()) {
                        cin.clear(); cin.ignore(1000, '\n');
                        cout << "[!] Input harus angka!\n"; tungguEnter(); continue;
                    }
                    switch (pilihan) {
                        case 1: loginAkunToko(); break;
                        case 2: cout << "\nTerima kasih!\n"; exit(0);
                        default: cout << "[!] Opsi salah!\n"; tungguEnter();
                    }
                }
            } else {
                menuUtamaAdmin();
            }
        }
    }
};
// ==========================================
//      CLASS UTAMA: SISTEM MALL METROPOLIS
// ==========================================
class SistemMallMetropolis {
private:
    // ==========================================
    //       VARIABEL & LOG SUBSISTEM KOSMETIK
    // ==========================================
    int TEMA_WARNA_SEKARANG = 0; 
    int GAYA_BORDER_SEKARANG = 1; 

    LogAktivitas DATABASE_LOG[MAKS_LOG];
    int TOTAL_LOG_SEKARANG = 0;

    double totalSirkulasiFinansial = 0;
    Admin adminUtama;

    // Database Statis User & Merchant Mall
    Pelanggan daftarUser[2];
    Pelanggan userSekarang;
    bool sedangLogin = false;

    Toko daftarTokoMall[MAKS_TOKO];
    int totalToko = 0;

    // ==========================================
    //         METODE UTILITY & TAMPILAN
    // ==========================================
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

    void jalankanAnimasiLoading()
    {
        terapkanWarnaTampilan(TEMA_WARNA_SEKARANG);
        cout << "\n[MEMPROSES LOGIKA SYSTEM ENVIRONMENT CERAN_HUB]\n";
        cout << "Loading: [";
        for(int i = 0; i < 20; i++)
        {
            cout << "■";
            cout.flush();
            for(volatile long long j=0; j<8000000; j++);
        }
        cout << "] 100% KONDISI STABIL!\n\n";
        terapkanWarnaTampilan(0);
    }

    void cetakLogoMallBesar()
    {
        terapkanWarnaTampilan(TEMA_WARNA_SEKARANG);
        std::cout << "  ____ _____ ____    _    _   _     _   _ _   _ ____   \n";
        std::cout << " / ___| ____|  _ \\  / \\  | \\ | |   | | | | | | | __ )  \n";
        std::cout << "| |   |  _| | |_) |/ _ \\ |  \\| |   | |_| | | | |  _ \\  \n";
        std::cout << "| |___| |___|  _ </ ___ \\| |\\  |   |  _  | |_| | |_) | \n";
        std::cout << " \\____|_____|_| \\_/_/   \\_\\_| \\_|   |_| |_|\\___/|____/  \n";
        cetakGarisPembatasUI();
        cetakGarisPembatasUI();
        terapkanWarnaTampilan(0);
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

public:
    // Constructor untuk Inisialisasi Database User & Seluruh Merchant Mall Terperinci
    SistemMallMetropolis() : adminUtama("ADM01", "CERAN2026")
    {
        daftarUser[0] = Pelanggan("arya123", "jogja2026", "3404123456789", "Arya Randani", "Sleman, Yogyakarta", 5000000);
        daftarUser[1] = Pelanggan("user2", "pass2", "3404987654321", "Budi Santoso", "Bantul, Yogyakarta", 500000);

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

        // 3. Gadget, Elektronik & Kamera
        daftarTokoMall[totalToko++] = Toko("T11", "Aldo & Bellagio", "Sports & Footwear (Tas & Sepatu Wanita)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P12", "High Heels Bellagio", 14, 459000));

        daftarTokoMall[totalToko++] = Toko("T12", "Bags City", "Sports & Footwear (Koper & Ransel)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P13", "Koper Kabin 20 Inch", 7, 1200000));

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

        // 8. Kuliner & Oleh-oleh
        daftarTokoMall[totalToko++] = Toko("T25", "Marugame Udon", "Food & Beverages (Restoran Besar)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P26", "Niku Udon", 40, 62000));

        daftarTokoMall[totalToko++] = Toko("T26", "Burger King / KFC", "Food & Beverages (Cepat Saji)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P27", "Paket Ayam + Nasi", 80, 35000));

        daftarTokoMall[totalToko++] = Toko("T27", "Starbucks", "Food & Beverages (Kafe)");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P28", "Caffe Latte Venti", 30, 58000));

        daftarTokoMall[totalToko++] = Toko("T28", "Bakpia Kukus Tugu Jogja", "Oleh-oleh / Kuliner Lokal");
        daftarTokoMall[totalToko-1].tambahProdukBaru(Produk("P29", "Bakpia Kukus Kotak 10", 60, 45000));
    }

    // Prosedur Runtime Utama Aplikasi (Memuat Alur Menu Interaktif)
    void jalankanSistem()
    {
        jalankanAnimasiLoading();
        cetakLogoMallBesar();

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

        int pilihanMenu;
        do
        {
            cout << "\n";
            cetakHeaderBoxUI("WELCOME TO CERAN_HUB METROPOLIS SMART MALL");
            cout << "Logged in as: " << userSekarang.nama << "\n";
            cout << "1. Lihat Profil & Fitur Dompet Digital (Wallet)\n";
            cout << "2. Cari Toko (Keyword Search Manual)\n";
            cout << "3. Pilih Toko & Masukkan Keranjang Belanja\n";
            cout << "4. Fitur Pembayaran / Checkout & Cetak Struk\n";
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
                                    case 1:
                                    {
                                        cout << "Nomor VA BRI Anda: 88810" << userSekarang.nik.substr(0, 5) << "\n";
                                        break;
                                    }
                                    case 2:
                                    {
                                        cout << "Nomor VA BCA Anda: 39010" << userSekarang.nik.substr(0, 5) << "\n";
                                        break;
                                    }
                                    case 3:
                                    {
                                        cout << "Nomor VA Mandiri Anda: 89608" << userSekarang.nik.substr(0, 5) << "\n";
                                        break;
                                    }
                                    case 4:
                                    {
                                        cout << "Nomor VA BNI Anda: 82410" << userSekarang.nik.substr(0, 5) << "\n";
                                        break;
                                    }
                                    default:
                                    {
                                        cout << "Bank tidak tersedia.\n";
                                        statusProses = 0;
                                        break;
                                    }
                                }
                                break;
                            }
                            case 2:
                            {
                                cout << "\n[GERAI INDOMARET]\n";
                                cout << "Kode Pembayaran Indomaret: IDM" << userSekarang.nik.substr(2, 6) << "\n";
                                cout << "Silakan tunjukkan kode ini ke kasir Indomaret terdekat.\n";
                                break;
                            }
                            case 3:
                            {
                                cout << "\n[GERAI ALFAMART]\n";
                                cout << "Kode Pembayaran Alfamart: ALFA" << userSekarang.nik.substr(1, 6) << "\n";
                                cout << "Silakan tunjukkan kode ini ke kasir Alfamart terdekat.\n";
                                break;
                            }
                            case 4:
                            {
                                cout << "\n[E-WALLET GOPAY]\n";
                                cout << "Menghubungkan ke aplikasi Gojek...\n";
                                cout << "Masukkan Nomor HP GoPay Anda: ";
                                string noGopay; cin >> noGopay;
                                cout << "Permintaan bayar dikirim ke aplikasi Anda.\n";
                                break;
                            }
                            case 5:
                            {
                                cout << "\n[E-WALLET DANA]\n";
                                cout << "Membuka gerbang pembayaran DANA...\n";
                                cout << "Masukkan Nomor ID DANA Anda: ";
                                string noDana; cin >> noDana;
                                cout << "Silakan konfirmasi PIN pada pop-up smartphone Anda.\n";
                                break;
                            }
                            case 6:
                            {
                                cout << "\n[PAYPAL GLOBAL PAYMENT]\n";
                                cout << "Kurs konversi otomatis diterapkan ke USD.\n";
                                cout << "Masukkan Email PayPal Anda: ";
                                string emailPaypal; cin >> emailPaypal;
                                cout << "Otentikasi tagihan internasional berhasil.\n";
                                break;
                            }
                            case 7:
                            {
                                cout << "\n[E-WALLET SHOPEEPAY]\n";
                                cout << "Membuka Aplikasi Shopee...\n";
                                cout << "Masukkan Username Shopee: ";
                                string userShopee; cin >> userShopee;
                                cout << "Notifikasi tagihan telah dikirim ke akun ShopeePay Anda.\n";
                                break;
                            }
                            case 8:
                            {
                                cout << "\n[QRIS - AUTOMATIC SCANNER]\n";
                                cout << "###########################\n";
                                cout << "##   [QRIS BARCODE SCAN] ##\n";
                                cout << "##    CERAN_HUB DYNAMIC  ##\n";
                                cout << "###########################\n";
                                cout << "Silakan scan kode QR di atas menggunakan aplikasi finansial Anda.\n";
                                break;
                            }
                            default:
                            {
                                cout << "Pilihan metode top up tidak valid!\n";
                                statusProses = 0;
                                break;
                            }
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
                                    {
                                        userSekarang.isiSaldo(nominal);
                                        catatAktivitasLog("User melakukan Top-Up sebesar Rp" + to_string(nominal));
                                        break;
                                    }
                                    default:
                                    {
                                        cout << "Verifikasi gagal! Top up dibatalkan.\n";
                                        break;
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                break;
                            }
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
                                produkTerpilih.namaTokoAsal = tokoTerpilih.namaToko; 
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
                        {
                            labelMetode = "Digital Wallet (Internal)";
                            biayaPenanganan = 0;
                            if (userSekarang.saldoWallet >= totalAkhir)
                            {
                                userSekarang.kurangiSaldo(totalAkhir);
                                pembayaranSukses = 1;
                            }
                            else
                            {
                                cout << "X Saldo Wallet internal Anda tidak mencukupi! Silakan isi saldo dulu.\n";
                            }
                            break;
                        }
                        case 2:
                        {
                            labelMetode = "Direct Bank VA";
                            biayaPenanganan = 2500;
                            cout << "[DIRECT BANK VA] Dikenakan tambahan biaya admin VA Rp" << biayaPenanganan << "\n";
                            cout << "Masukkan nomor VA tujuan transfer untuk validasi otomatis: ";
                            string inputVA; cin >> inputVA;
                            pembayaranSukses = 1;
                            break;
                        }
                        case 3:
                        {
                            labelMetode = "Direct Indomaret";
                            biayaPenanganan = 2500;
                            cout << "[DIRECT INDOMARET] Harap selesaikan pembayaran di kasir dengan Kode: TRM" << userSekarang.nik.substr(4, 5) << "\n";
                            pembayaranSukses = 1;
                            break;
                        }
                        case 4:
                        {
                            labelMetode = "Direct Alfamart";
                            biayaPenanganan = 2500;
                            cout << "[DIRECT ALFAMART] Harap selesaikan pembayaran di kasir dengan Kode: TRMA" << userSekarang.nik.substr(5, 5) << "\n";
                            pembayaranSukses = 1;
                            break;
                        }
                        case 5:
                        {
                            labelMetode = "Direct GoPay";
                            biayaPenanganan = 1000;
                            cout << "[DIRECT GOPAY] Masukkan PIN Keamanan GoPay Anda untuk menyetujui transaksi: ";
                            string pinGopay; cin >> pinGopay;
                            pembayaranSukses = 1;
                            break;
                        }
                        case 6:
                        {
                            labelMetode = "Direct DANA";
                            biayaPenanganan = 1000;
                            cout << "[DIRECT DANA] Masukkan OTP yang dikirim ke nomor handphone terdaftar Anda: ";
                            string otpDana; cin >> otpDana;
                            pembayaranSukses = 1;
                            break;
                        }
                        case 7:
                        {
                            labelMetode = "Direct PayPal Account";
                            biayaPenanganan = 5000;
                            cout << "[DIRECT PAYPAL] Memproses pemotongan dana internasional terotentikasi aman...\n";
                            pembayaranSukses = 1;
                            break;
                        }
                        case 8:
                        {
                            labelMetode = "Direct ShopeePay";
                            biayaPenanganan = 1000;
                            cout << "[DIRECT SHOPEEPAY] Scan wajah / sidik jari pada perangkat seluler Anda...\n";
                            pembayaranSukses = 1;
                            break;
                        }
                        case 9:
                        {
                            labelMetode = "Direct QRIS Scanner";
                            biayaPenanganan = 0;
                            cout << "[DIRECT QRIS] Sistem mendeteksi pemindaian sukses dari mobile banking (Bebas Biaya).\n";
                            pembayaranSukses = 1;
                            break;
                        }
                        default:
                        {
                            cout << "Metode pembayaran tidak dikenal!\n";
                            break;
                        }
                    }

                    totalAkhir += biayaPenanganan;

                    switch (pembayaranSukses)
                    {
                        case 1:
                        {
                            totalSirkulasiFinansial += totalAkhir;
                            catatAktivitasLog("Checkout berhasil dilakukan via " + labelMetode + " senilai Rp" + to_string(totalAkhir));

                            cout << "\n=========================================\n";
                            cout << "              STRUK PEMBAYARAN            \n";
                            cout << "=========================================\n";
                            cout << "Nama Pelanggan  : " << userSekarang.nama << "\n";
                            cout << "Metode Bayar    : " << labelMetode << "\n";
                            cout << "-----------------------------------------\n";
                            for (int i = 0; i < userSekarang.jumlahItemKeranjang; ++i)
                            {
                                cout << "[" << userSekarang.keranjang[i].produk.namaTokoAsal << "] " 
                                     << userSekarang.keranjang[i].produk.namaProduk << " x" 
                                     << userSekarang.keranjang[i].kuantitas << " : Rp" 
                                     << fixed << setprecision(0) << userSekarang.keranjang[i].produk.harga * userSekarang.keranjang[i].kuantitas << "\n";
                            }
                            cout << "-----------------------------------------\n";
                            cout << "Total Bayar     : Rp" << totalAkhir << "\n";
                            cout << "=========================================\n";

                            PencetakStrukHub mesinCetakHub;
                            mesinCetakHub.buatBerkasStrukTxt(userSekarang, totalBelanja, nilaiDiskon, pajak, biayaPenanganan, totalAkhir, labelMetode, metodeBayar);

                            userSekarang.kosongkanKeranjang();
                            break;
                        }
                        default:
                        {
                            cout << "X Pembayaran Gagal Diproses!\n";
                            break;
                        }
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
                    else
                    {
                        cout << "X Kunci Keamanan Salah! Akses Ditolak.\n";
                    }
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
                        {
                            cout << "\nPILIH TEMA WARNA:\n";
                            cout << "0. Default Putih\n";
                            cout << "1. Cyber Red\n";
                            cout << "2. Hacker Green\n";
                            cout << "3. Classic Blue\n";
                            cout << "4. Sakura Pink\n";
                            cout << "5. Modern Cyan\n";
                            cout << "Pilihan Warna Anda: ";
                            cin >> TEMA_WARNA_SEKARANG;
                            cout << "Tema warna teks berhasil disesuaikan!\n";
                            break;
                        }
                        case 2:
                        {
                            cout << "\nPILIH MODEL BORDER BARIS:\n";
                            cout << "1. Garis Sederhana Standar (=)\n";
                            cout << "2. Garis Tunggal Tipis Unicode (─)\n";
                            cout << "3. Garis Tebal Double Unicode (═)\n";
                            cout << "4. Pembatas Tanda Pagar (#)\n";
                            cout << "Pilihan Model Garis Anda: ";
                            cin >> GAYA_BORDER_SEKARANG;
                            cout << "Model pembatas garis berhasil dikustomisasi!\n";
                            break;
                        }
                        default:
                        {
                            cout << "Opsi kustomisasi tidak valid.\n";
                            break;
                        }
                    }
                    break;
                }
                case 7:
                {
                    cout << "\nTerima kasih telah berkunjung ke CERAN_HUB MALL!\n";
                    break;
                }
                default:
                {
                    cout << "X Pilihan menu tidak valid!\n";
                    break;
                }
            }
        } while (pilihanMenu != 7);
    }
};
