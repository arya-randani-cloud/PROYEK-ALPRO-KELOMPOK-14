/* ============================================================
   CERAN_HUB - PROYEK ALPRO KELOMPOK 14
   Versi gabungan untuk demo presentasi.
   Modul: Manajemen Vendor Admin, Pelanggan/Mall, Admin Toko
          (registrasi & dashboard lengkap), Sistem Pemesanan.
   ============================================================ */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

namespace modVendor {


class DashboardPelanggan {
                private:
                    int totalPelanggan;
                    int pelangganAktif;
                    int pelangganNonAktif;

                public:

                    DashboardPelanggan() {
                        totalPelanggan = 120;
                        pelangganAktif = 110;
                        pelangganNonAktif = 10;
}

    void tampilDataPelanggan() {

        cout << "\n=========================================\n";
        cout << "      DASHBOARD TOTAL PELANGGAN\n";
        cout << "=========================================\n";
        cout << "Total Pelanggan      : " << totalPelanggan << endl;
        cout << "Pelanggan Aktif      : " << pelangganAktif << endl;
        cout << "Pelanggan Nonaktif   : " << pelangganNonAktif << endl;
        cout << "=========================================\n";

    }

    void menu() {

        int pilih;

        do {

            cout << "\n========== MENU PELANGGAN ==========\n";
            cout << "1. Lihat Total Pelanggan\n";
            cout << "0. Kembali\n";
            cout << "====================================\n";
            cout << "Pilih Menu : ";
            cin >> pilih;

            switch (pilih) {

            case 1:
                tampilDataPelanggan();
                break;

            case 0:
                cout << "\nKembali ke Dashboard Admin...\n";
                break;

            default :
                cout << "\nPilihan tidak tersedia!\n";
            }

        } while (pilih != 0);

    }

};
class InfoTotalVendor {
                    private:
                        int totalVendor;
                        int totalPelanggan;
                        int totalProduk;
                        int totalTransaksi;
                        double totalPendapatan;

                    public:

                        InfoTotalVendor() {
                        totalVendor = 25;
                        totalPelanggan = 350;
                        totalProduk = 1280;
                        totalTransaksi = 756;
                        totalPendapatan = 152500000;
    }

    void tampilDashboard() {

        cout << "\n=============================================================\n";
        cout << "                 RINGKASAN TOTAL VENDOR\n";
        cout << "=============================================================\n";

        cout << left << setw(30) << "Total Vendor"
             << ": " << totalVendor << endl;

        cout << left << setw(30) << "Total Pelanggan"
             << ": " << totalPelanggan << endl;

        cout << left << setw(30) << "Total Produk"
             << ": " << totalProduk << endl;

        cout << left << setw(30) << "Total Transaksi"
             << ": " << totalTransaksi << endl;

        cout << left << setw(30) << "Pendapatan Mall"
             << ": Rp " << fixed << setprecision(0)
             << totalPendapatan << endl;

        cout << "=============================================================\n";
    }

    void detailVendor() {

        cout << "\n========== INFORMASI VENDOR ==========\n";

        cout << "Vendor Aktif        : 22\n";
        cout << "Vendor Nonaktif     : 2\n";
        cout << "Vendor Baru         : 1\n";

        cout << "======================================\n";
    }

    void menuDashboard() {

        int pilih;

        do {

            cout << "\n============== TOTAL VENDOR ==============\n";
            cout << "1. Lihat Ringkasan Dashboard\n";
            cout << "2. Detail Total Vendor\n";
            cout << "0. Kembali\n";
            cout << "=======================================\n";
            cout << "Pilih Menu : ";
            cin >> pilih;

            switch(pilih){

            case 1:
                tampilDashboard();
                break;

            case 2:
                detailVendor();
                break;

            case 0:
                cout << "\nKembali ke Dashboard Admin...\n";
                break;

            default:
                cout << "\nMenu tidak tersedia!\n";
            }

        } while(pilih != 0);

    }

};
// TOTAL PRODUK

class TotalProduk {

                private:

                        // SEMBAKO
                        string sembako[5] = {
                                "Beras Ramos 5 Kg","Minyak Goreng", "Gula Pasir", "Telur Ayam", "Tepung Terigu"
    };

                        int hargaSembako[5] = {
                                 75000,18000,16000,30000,14000
    };

                        string tokoSembako[5] = {
                                 "Toko Makmur", "Sembako Jaya", "Berkah Store", "Toko Rizki", "Maju Jaya"
    };

                        // GAMING
                        string gaming[5] = {
                               "Mouse Logitech", "Keyboard Gaming", "Headset Gaming", "Mousepad XL", "Joystick"
    };

                        int hargaGaming[5] = {
                                250000,650000,350000,120000,450000
    };

                         string tokoGaming[5] = {
                                "Game Store", "GG Shop", "Arena Gaming", "Pro Gamer", "Zona Game"
    };

                        // ELEKTRONIK
                        string elektronik[5] = {
                              "Laptop ASUS", "Printer Epson", "SSD 512 GB", "Flashdisk 32 GB", "Monitor LG"
    };

                        int hargaElektronik[5] = {
                                8500000,2100000,850000,75000,1800000
    };

                        string tokoElektronik[5] = {
                              "Tech Store", "Elektronik Jaya", "Digital Shop", "KomputerKu", "Smart Tech"
    };

                        // ALAT TULIS
                        string alatTulis[5] = {
                              "Buku Tulis", "Pulpen", "Pensil", "Penghapus", "Penggaris"
    };

                        int hargaATK[5] = {
                                5000,3000,2000,1500,4000
    };

                        string tokoATK[5] = {
                              "ATK Jaya", "Toko Pena", "Sekolah Store", "Mitra ATK", "Pelajar Shop"
    };

                        // FASHION
                        string fashion[5] = {
                               "Kaos Polos", "Hoodie Oversize", "Celana Jeans", "Jaket Varsity", "Topi"
    };

                        int hargafashion[5] = {
                                85000,175000,220000,310000,65000
    };

                        string tokofashion[5] = {
                                "Zidan Fashion", "Urban Wear", "Denim Store", "Style Shop", "Trean Fashion"
    };

                        // KESEHATAN
                        string kesehatan[5] = {
                                "Vitamin C", "Masker Medis", "Hand Sanitizer", "Termometer Digital", "Tensimeter"
    };

                        int hargakesehatan[5] = {
                                35000,25000,18000,95000,250000
    };

                        string tokokesehatan[5] = {
                                "Budi Sehat", "Sutopo Langgeng", "K24", "Sido Mari", "Sami Sehat"
    };

                        // OTOMOTIF
                        string otomotif[5] = {
                                  "Oli Mesin", "Helm ", "Ban Motor", "Lampu Biled", "Cover Motor"
    };

                        int hargaotomotif[5] = {
                                    75000,450000,280000,90000,120000
    };

                         string tokootomotif[5] = {
                                    "Cahyo Garage", "Sultan Helmet", "88 Ban", "Parno Garage", "Custom Otomotif"
    };

                        // OLAHRAGA
                        string olahraga[5] = {
                                   "Bola Lapangan", "Raket Badminton", "Matras", "Sepatu", "Treadmil"
    };

                        int hargaolahraga[5] = {
                                    150000,200000,50000,950000,50000000
    };

                        string tokoolahraga[5] = {
                                    "Jempol","Mitra10","Speed","Rukun","Generik"
    };

                        // PERLENGKAPAN BAYI
                        string perlengkapanBayi[5] = {
                                    "Popok", "Susu", "Bedak", "Kereta Bayi", "Pakaian Bayi"
    };

                        int hargaperlengkapanBayi[5] = {
                                    35000,25000,18000,1195000,150000
    };

                        string tokoperlengkapanBayi[5] = {
                                   "Baby Zania", "Wijaya Store", "Vinolla Baby And Kids", "Baby Word", "Clandy Baby Shop"
    };

                        // PERLENGKAPAN HEWAN
                        string perlengkapanHewan[5] = {
                                    "Makanan Kucing", "Pasir Kucing", "Kalung Kucing", "Shampoo Hewan", "Kandang Hewan"
    };

                        int hargaperlengkapanHewan[5] = {
                                    50000,25000,18000,95000,200000
    };

                        string tokoperlengkapanHewan[5] = {
                                    "Saffron Petshop", "Pet Gallery", "Petshop Indonesia 28", "Usro Petshop", "Barokah Petshop"
    };

                        // BUKU
                        string buku[5] = {
                                   "Novel", "Buku psikotes", "Kamus 3 Bahasa", "Komik", "Buku Pelajaran"
    };

                        int hargabuku[5] = {
                                    50000,50000,38000,15000,25000
    };

                        string tokobuku[5] = {
                                     "Social Agency Baru", "Buku Akik", "Solusi Buku", "Shira Media", "Kedai Jual Buku Sastra"
    };

                        // KECANTIKAN
                        string kecantikan[5] = {
                                    "Facial Wash", "Sunscreen", "Lip Tint", "Serum Wajah", "Moisturizer"
    };

                        int hargakecantikan[5] = {
                                    150000,68000,55000,250000,90000
    };

                        string tokokecantikan[5] = {
                                    "Mutiara Pusat Kosmetik", "ELS Beauty", "CF Beauty", "Toko Puspa Indah", "Rea Beauty"
    };

                    public:
                
                    void tampilSembako(){
                
                        cout<<"\n=========== SEMBAKO ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<sembako[i]
                                <<"Rp"<<setw(10)<<hargaSembako[i]
                                <<tokoSembako[i]<<endl;
                
                        }
                
                    }
                
                    void tampilGaming(){
                
                        cout<<"\n=========== GAMING ===========\n";
                
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<gaming[i]
                                <<"Rp"<<setw(10)<<hargaGaming[i]
                                <<tokoGaming[i]<<endl;
                
                        }
                
                    }
                
                    void tampilElektronik(){
                
                        cout<<"\n=========== ELEKTRONIK ===========\n";
                
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<elektronik[i]
                                <<"Rp"<<setw(10)<<hargaElektronik[i]
                                <<tokoElektronik[i]<<endl;
                
                        }
                
                    }
                
                    void tampilATK(){
                
                        cout<<"\n======= ALAT TULIS =======\n";
                
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<alatTulis[i]
                                <<"Rp"<<setw(10)<<hargaATK[i]
                                <<tokoATK[i]<<endl;
                
                        }
                
                    }
                
                    void tampilfashion(){
                
                        cout<<"\n=========== FASHION ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<fashion[i]
                                <<"Rp"<<setw(10)<<hargafashion[i]
                                <<tokofashion[i]<<endl;
                
                        }
                
                    }
                
                     void tampilkesehatan(){
                
                        cout<<"\n=========== KESEHATAN ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<kesehatan[i]
                                <<"Rp"<<setw(10)<<hargakesehatan[i]
                                <<tokokesehatan[i]<<endl;
                
                        }
                
                    }
                
                     void tampilotomotif(){
                
                        cout<<"\n=========== OTOMOTIF ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<otomotif[i]
                                <<"Rp"<<setw(10)<<hargaotomotif[i]
                                <<tokootomotif[i]<<endl;
                
                        }
                
                    }
                
                     void tampilolahraga(){
                
                        cout<<"\n=========== OLAHRAGA ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<olahraga[i]
                                <<"Rp"<<setw(10)<<hargaolahraga[i]
                                <<tokoolahraga[i]<<endl;
                
                        }
                
                    }
                
                     void tampilperlengkapanBayi(){
                
                        cout<<"\n=========== PERLENGKAPAN BAYI ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<perlengkapanBayi[i]
                                <<"Rp"<<setw(10)<<hargaperlengkapanBayi[i]
                                <<tokoperlengkapanBayi[i]<<endl;
                
                        }
                
                    }
                
                     void tampilperlengkapanHewan(){
                
                        cout<<"\n=========== PERLENGKAPAN HEWAN ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<perlengkapanHewan[i]
                                <<"Rp"<<setw(10)<<hargaperlengkapanHewan[i]
                                <<tokoperlengkapanHewan[i]<<endl;
                
                        }
                
                    }
                
                     void tampilbuku(){
                
                        cout<<"\n=========== BUKU ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<buku[i]
                                <<"Rp"<<setw(10)<<hargabuku[i]
                                <<tokobuku[i]<<endl;
                
                        }
                
                    }
                
                     void tampilkecantikan(){
                
                        cout<<"\n=========== KECANTIKAN ===========\n";
                        cout<<left<<setw(5)<<"No"
                            <<setw(22)<<"Nama Barang"
                            <<setw(12)<<"Harga"
                            <<"Toko\n";
                
                        for(int i=0;i<5;i++){
                
                            cout<<left
                                <<setw(5)<<i+1
                                <<setw(22)<<kecantikan[i]
                                <<"Rp"<<setw(10)<<hargakecantikan[i]
                                <<tokokecantikan[i]<<endl;
                
                        }
                
                    }
                
                    void totalMall(){
                
                        cout<<"\n========== TOTAL PRODUK MALL ==========\n";
                        cout<<"Sembako                 : 5 Produk"<<endl;
                        cout<<"Gaming                  : 5 Produk"<<endl;
                        cout<<"Elektronik              : 5 Produk"<<endl;
                        cout<<"Alat Tulis              : 5 Produk"<<endl;
                        cout<<"Fashion                 : 5 Produk"<<endl;
                        cout<<"Kesehatan               : 5 Produk"<<endl;
                        cout<<"Otomotif                : 5 Produk"<<endl;
                        cout<<"Peralatan Olahraga      : 5 Produk"<<endl;
                        cout<<"Perlengkapan Bayi       : 5 Produk"<<endl;
                        cout<<"Perlengkapan Hewan      : 5 Produk"<<endl;
                        cout<<"Buku                    : 5 Produk"<<endl;
                        cout<<"Kecantikan              : 5 Produk"<<endl;
                        cout<<"---------------------------------------"<<endl;
                        cout<<"TOTAL PRODUK            : 65 Produk"<<endl;
                    }
                
                    void menu(){
                
                        int pilih;
                
                        do{
                
                            cout<<"\n========== TOTAL PRODUK ==========\n";
                            cout<<"1. Sembako"<<endl;
                            cout<<"2. Gaming"<<endl;
                            cout<<"3. Elektronik"<<endl;
                            cout<<"4. Alat Tulis"<<endl;
                            cout<<"5. Fashion"<<endl;
                            cout<<"6. Kesehatan"<<endl;
                            cout<<"7. Otomotif"<<endl;
                            cout<<"8. Peralatan Olahraga"<<endl;
                            cout<<"9. Perlengkapan Bayi"<<endl;
                            cout<<"10. Perlengkapan Hewan"<<endl;
                            cout<<"11. Buku"<<endl;
                            cout<<"12. Kecantikan"<<endl;
                            cout<<"13. Total Produk Mall"<<endl;
                            cout<<"0. Kembali"<<endl;
                
                            cout<<"Pilih Menu : ";
                            cin>>pilih;
                
                            switch(pilih){
                
                            case 1:
                                tampilSembako();
                                break;
                
                            case 2:
                                tampilGaming();
                                break;
                
                            case 3:
                                tampilElektronik();
                                break;
                
                            case 4:
                                tampilATK();
                                break;
                
                            case 5:
                                tampilfashion();
                                break;
                
                            case 6:
                                tampilkesehatan();
                                break;
                            
                            case 7:
                                tampilotomotif();
                                break;
                
                            case 8:
                                tampilolahraga();
                                break;
                
                            case 9:
                                tampilperlengkapanBayi();
                                break;
                
                            case 10:
                                tampilperlengkapanHewan();
                                break;
                
                            case 11:
                                tampilbuku();
                                break;
                
                            case 12:
                                tampilkecantikan();
                                break;
                
                            case 13:
                                totalMall();
                                break;
                
                            case 0:
                                cout<<"\nKembali ke Dashboard...\n";
                                break;
                
                            default:
                                cout<<"\nPilihan tidak tersedia!\n";
                
                            }
                
                        }while(pilih!=0);
                
                    }
                
                };

                    // CLASS PENDAPATAN MALL
                    class PendapatanMall{
                    
                    private:
                    
                        string bulan[12]={
                            "Januari","Februari","Maret","April","Mei","Juni","Juli","Agustus","September","Oktober","November","Desember"
                        };
                    
                        int transaksi[12]={
                           1250,1380,1525,1460,1700,1850,1940,1810,1680,1750,2100,2500
                        };
                    
                        long pendapatan[12]={
                            25000000,27000000,30000000,28000000,32000000,35000000,36000000,34000000,31000000,33000000,38000000,42000000
                        };
                    
                    public:
                    
                        void laporanBulanan(){
                    
                            cout<<"\n==============================================================\n";
                            cout<<"              LAPORAN PENDAPATAN CERANMALL\n";
                            cout<<"==============================================================\n";
                    
                            cout<<left
                                <<setw(5)<<"No"
                                <<setw(15)<<"Bulan"
                                <<setw(20)<<"Transaksi"
                                <<"Pendapatan"<<endl;
                    
                            cout<<"--------------------------------------------------------------\n";
                    
                            for(int i=0;i<12;i++){
                    
                                cout<<left
                                    <<setw(5)<<i+1
                                    <<setw(15)<<bulan[i]
                                    <<setw(20)<<transaksi[i]
                                    <<"Rp "<<pendapatan[i]<<endl;
                    
                            }
                    
                        }
                    
                        void totalPendapatan(){
                    
                            long total=0;
                    
                            for(int i=0;i<12;i++){
                    
                                total+=pendapatan[i];
                    
                            }
                    
                            cout<<"\n====================================\n";
                            cout<<"TOTAL PENDAPATAN CERANMALL\n";
                            cout<<"====================================\n";
                            cout<<"Rp "<<total<<endl;
                    
                        }
                    
                        void totalTransaksi(){
                    
                            int total=0;
                    
                            for(int i=0;i<12;i++){
                    
                                total+=transaksi[i];
                    
                            }
                    
                            cout<<"\n====================================\n";
                            cout<<"TOTAL TRANSAKSI CERANMALL\n";
                            cout<<"====================================\n";
                            cout<<total<<" Transaksi"<<endl;
                    
                        }
                    
                        void pendapatanTertinggi(){
                    
                            int indeks=0;
                    
                            for(int i=1;i<12;i++){
                    
                                if(pendapatan[i]>pendapatan[indeks]){
                    
                                    indeks=i;
                    
                                }
                    
                            }
                    
                            cout<<"\n====================================\n";
                            cout<<"PENDAPATAN TERTINGGI\n";
                            cout<<"====================================\n";
                            cout<<"Bulan        : "<<bulan[indeks]<<endl;
                            cout<<"Transaksi    : "<<transaksi[indeks]<<endl;
                            cout<<"Pendapatan   : Rp "<<pendapatan[indeks]<<endl;
                    
                        }
                    
                        void pendapatanTerendah(){
                    
                            int indeks=0;
                    
                            for(int i=1;i<12;i++){
                    
                                if(pendapatan[i]<pendapatan[indeks]){
                    
                                    indeks=i;
                    
                                }
                    
                            }
                    
                            cout<<"\n====================================\n";
                            cout<<"PENDAPATAN TERENDAH\n";
                            cout<<"====================================\n";
                            cout<<"Bulan        : "<<bulan[indeks]<<endl;
                            cout<<"Transaksi    : "<<transaksi[indeks]<<endl;
                            cout<<"Pendapatan   : Rp "<<pendapatan[indeks]<<endl;
                    
                        }
                    
                        void statistik(){
                    
                            long totalPend=0;
                            int totalTrans=0;
                    
                            for(int i=0;i<12;i++){
                    
                                totalPend+=pendapatan[i];
                                totalTrans+=transaksi[i];
                    
                            }
                    
                            cout<<"\n====================================\n";
                            cout<<"STATISTIK CERANMALL\n";
                            cout<<"====================================\n";
                    
                            cout<<"Total Pendapatan      : Rp "<<totalPend<<endl;
                            cout<<"Total Transaksi       : "<<totalTrans<<endl;
                            cout<<"Rata-rata Pendapatan  : Rp "<<totalPend/12<<endl;
                            cout<<"Rata-rata Transaksi   : "<<totalTrans/12<<endl;
                    
                        }
                    
                        void menu(){
                    
                            int pilih;
                    
                            do{
                    
                                cout<<"\n=========================================\n";
                                cout<<"      MENU PENDAPATAN CERANMALL\n";
                                cout<<"=========================================\n";
                                cout<<"1. Laporan Pendapatan Bulanan\n";
                                cout<<"2. Pendapatan Tertinggi\n";
                                cout<<"3. Pendapatan Terendah\n";
                                cout<<"4. Total Pendapatan Mall\n";
                                cout<<"5. Total Transaksi Mall\n";
                                cout<<"6. Statistik Tahunan\n";
                                cout<<"0. Kembali\n";
                                cout<<"=========================================\n";
                    
                                cout<<"Pilih Menu : ";
                                cin>>pilih;
                    
                                switch(pilih){
                    
                                case 1:
                                    laporanBulanan();
                                    break;
                    
                                case 2:
                                    pendapatanTertinggi();
                                    break;
                    
                                case 3:
                                    pendapatanTerendah();
                                    break;
                    
                                case 4:
                                    totalPendapatan();
                                    break;
                    
                                case 5:
                                    totalTransaksi();
                                    break;
                    
                                case 6:
                                    statistik();
                                    break;
                    
                                case 0:
                                    cout<<"\nKembali ke Dashboard...\n";
                                    break;
                    
                                default:
                                    cout<<"\nPilihan tidak tersedia!\n";
                    
                                }
                    
                            }while(pilih!=0);
                    
                        }
                    
                    };


//  PRODUK TERLARIS
class ProdukTerlaris{

private:

    //==================== SEMBAKO ====================

    string sembako[5]={
        "Beras Ramos 5 Kg",
        "Minyak Goreng",
        "Gula Pasir",
        "Telur Ayam",
        "Tepung Terigu"
    };

    int terjualSembako[5]={
        320,
        285,
        250,
        210,
        180
    };

    //==================== GAMING ====================

    string gaming[5]={
        "Mouse Logitech",
        "Keyboard Gaming",
        "Headset Gaming",
        "Mousepad XL",
        "Joystick"
    };

    int terjualGaming[5]={
        160,
        140,
        120,
        90,
        80
    };

    //==================== ELEKTRONIK ====================

    string elektronik[5]={
        "Laptop ASUS",
        "Printer Epson",
        "SSD 512 GB",
        "Flashdisk 32 GB",
        "Monitor LG"
    };

    int terjualElektronik[5]={
        75,
        62,
        58,
        110,
        48
    };

public:

    void tampilSembako(){

        cout<<"\n=========== SEMBAKO TERLARIS ===========\n\n";

        cout<<left
        <<setw(5)<<"No"
        <<setw(25)<<"Nama Barang"
        <<"Jumlah Terjual"<<endl;

        for(int i=0;i<5;i++){

            cout<<left
            <<setw(5)<<i+1
            <<setw(25)<<sembako[i]
            <<terjualSembako[i]<<" Kali"<<endl;

        }

    }

    void tampilGaming(){

        cout<<"\n=========== GAMING TERLARIS ===========\n\n";

        cout<<left
        <<setw(5)<<"No"
        <<setw(25)<<"Nama Barang"
        <<"Jumlah Terjual"<<endl;

        for(int i=0;i<5;i++){

            cout<<left
            <<setw(5)<<i+1
            <<setw(25)<<gaming[i]
            <<terjualGaming[i]<<" Kali"<<endl;

        }

    }

    void tampilElektronik(){

        cout<<"\n=========== ELEKTRONIK TERLARIS ===========\n\n";

        cout<<left
        <<setw(5)<<"No"
        <<setw(25)<<"Nama Barang"
        <<"Jumlah Terjual"<<endl;

        for(int i=0;i<5;i++){

            cout<<left
            <<setw(5)<<i+1
            <<setw(25)<<elektronik[i]
            <<terjualElektronik[i]<<" Kali"<<endl;

        }

    }

    void top10(){

        cout<<"\n================ TOP PRODUK CERANMALL ================\n\n";

        cout<<left
        <<setw(5)<<"No"
        <<setw(25)<<"Produk"
        <<setw(20)<<"Kategori"
        <<"Terjual"<<endl;

        cout<<"------------------------------------------------------"<<endl;

        cout<<left<<setw(5)<<"1"<<setw(25)<<"Beras Ramos"<<setw(20)<<"Sembako"<<320<<endl;
        cout<<left<<setw(5)<<"2"<<setw(25)<<"Minyak Goreng"<<setw(20)<<"Sembako"<<285<<endl;
        cout<<left<<setw(5)<<"3"<<setw(25)<<"Gula Pasir"<<setw(20)<<"Sembako"<<250<<endl;
        cout<<left<<setw(5)<<"4"<<setw(25)<<"Telur Ayam"<<setw(20)<<"Sembako"<<210<<endl;
        cout<<left<<setw(5)<<"5"<<setw(25)<<"Tepung Terigu"<<setw(20)<<"Sembako"<<180<<endl;
        cout<<left<<setw(5)<<"6"<<setw(25)<<"Mouse Logitech"<<setw(20)<<"Gaming"<<160<<endl;
        cout<<left<<setw(5)<<"7"<<setw(25)<<"Keyboard Gaming"<<setw(20)<<"Gaming"<<140<<endl;
        cout<<left<<setw(5)<<"8"<<setw(25)<<"Headset Gaming"<<setw(20)<<"Gaming"<<120<<endl;
        cout<<left<<setw(5)<<"9"<<setw(25)<<"Flashdisk 32 GB"<<setw(20)<<"Elektronik"<<110<<endl;
        cout<<left<<setw(5)<<"10"<<setw(25)<<"Mousepad XL"<<setw(20)<<"Gaming"<<90<<endl;

    }

    void menu(){

        int pilih;

        do{

            cout<<"\n========================================"<<endl;
            cout<<"         MENU PRODUK TERLARIS"<<endl;
            cout<<"========================================"<<endl;
            cout<<"1. Top 10 Produk CeranMall"<<endl;
            cout<<"2. Produk Terlaris Sembako"<<endl;
            cout<<"3. Produk Terlaris Gaming"<<endl;
            cout<<"4. Produk Terlaris Elektronik"<<endl;
            cout<<"5. Produk Terlaris Fashion"<<endl;
            cout<<"6. Produk Terlaris Kesehatan"<<endl;
            cout<<"7. Produk Terlaris Otomotif"<<endl;
            cout<<"8. Produk Terlaris Olahraga"<<endl;
            cout<<"9. Produk Terlaris Bayi"<<endl;
            cout<<"10. Produk Terlaris Hewan"<<endl;
            cout<<"11. Produk Terlaris Buku"<<endl;
            cout<<"12. Produk Terlaris Kecantikan"<<endl;
            cout<<"0. Kembali"<<endl;

            cout<<"\nPilih : ";
            cin>>pilih;

            switch(pilih){

            case 1:
                top10();
                break;

            case 2:
                tampilSembako();
                break;

            case 3:
                tampilGaming();
                break;

            case 4:
                tampilElektronik();
                break;

            case 5:
                cout<<"\nProduk Terlaris Fashion (buat seperti contoh di atas)\n";
                break;

            case 6:
                cout<<"\nProduk Terlaris Kesehatan (buat seperti contoh di atas)\n";
                break;

            case 7:
                cout<<"\nProduk Terlaris Otomotif (buat seperti contoh di atas)\n";
                break;

            case 8:
                cout<<"\nProduk Terlaris Olahraga (buat seperti contoh di atas)\n";
                break;

            case 9:
                cout<<"\nProduk Terlaris Bayi (buat seperti contoh di atas)\n";
                break;

            case 10:
                cout<<"\nProduk Terlaris Hewan (buat seperti contoh di atas)\n";
                break;

            case 11:
                cout<<"\nProduk Terlaris Buku (buat seperti contoh di atas)\n";
                break;

            case 12:
                cout<<"\nProduk Terlaris Kecantikan (buat seperti contoh di atas)\n";
                break;

            case 0:
                cout<<"\nKembali ke Dashboard...\n";
                break;

            default:
                cout<<"\nPilihan tidak tersedia.\n";

            }

        }while(pilih!=0);

    }

};

//====================================================================
// CLASS VENDOR TERLARIS
//====================================================================
class VendorTerlaris{

private:

    string namaToko[10]={
        "Toko Makmur",
        "Game Store",
        "Tech Store",
        "FashionKu",
        "Healthy Shop",
        "ATK Jaya",
        "Pet House",
        "Baby Mart",
        "Sport Center",
        "Otomotif Jaya"
    };

    int transaksi[10]={
        950,
        880,
        760,
        730,
        650,
        580,
        540,
        500,
        470,
        430
    };

    long pendapatan[10]={
        85000000,
        79000000,
        72000000,
        68000000,
        61000000,
        52000000,
        48000000,
        45000000,
        43000000,
        40000000
    };

    float rating[10]={
        4.9,
        4.8,
        4.8,
        4.7,
        4.7,
        4.6,
        4.6,
        4.5,
        4.5,
        4.4
    };

public:

    void semuaVendor(){

        cout<<"\n===================== DAFTAR VENDOR CERANMALL =====================\n\n";

        cout<<left
            <<setw(5)<<"No"
            <<setw(22)<<"Nama Toko"
            <<setw(15)<<"Transaksi"
            <<setw(18)<<"Pendapatan"
            <<"Rating"<<endl;

        cout<<"-------------------------------------------------------------------"<<endl;

        for(int i=0;i<10;i++){

            cout<<left
                <<setw(5)<<i+1
                <<setw(22)<<namaToko[i]
                <<setw(15)<<transaksi[i]
                <<setw(18)<<pendapatan[i]
                <<rating[i]<<endl;

        }

    }

    void top5(){

        cout<<"\n=============== TOP 5 VENDOR TERLARIS ===============\n\n";

        cout<<left
            <<setw(5)<<"No"
            <<setw(22)<<"Nama Toko"
            <<setw(15)<<"Transaksi"
            <<"Pendapatan"<<endl;

        cout<<"-----------------------------------------------------"<<endl;

        for(int i=0;i<5;i++){

            cout<<left
                <<setw(5)<<i+1
                <<setw(22)<<namaToko[i]
                <<setw(15)<<transaksi[i]
                <<pendapatan[i]<<endl;

        }

    }

    void vendorTerbaik(){

        cout<<"\n=========== VENDOR TERBAIK BULAN INI ===========\n";

        cout<<"Nama Toko     : "<<namaToko[0]<<endl;
        cout<<"Transaksi     : "<<transaksi[0]<<endl;
        cout<<"Pendapatan    : Rp "<<pendapatan[0]<<endl;
        cout<<"Rating        : "<<rating[0]<<endl;

    }

    void statistik(){

        int totalTransaksi=0;
        long totalPendapatan=0;

        for(int i=0;i<10;i++){

            totalTransaksi+=transaksi[i];
            totalPendapatan+=pendapatan[i];

        }

        cout<<"\n=============== STATISTIK VENDOR ===============\n";

        cout<<"Jumlah Vendor        : 10"<<endl;
        cout<<"Total Transaksi      : "<<totalTransaksi<<endl;
        cout<<"Total Pendapatan     : Rp "<<totalPendapatan<<endl;
        cout<<"Rata-rata Transaksi  : "<<totalTransaksi/10<<endl;
        cout<<"Rata-rata Pendapatan : Rp "<<totalPendapatan/10<<endl;

    }

    void menu(){

        int pilih;

        do{

            cout<<"\n========================================"<<endl;
            cout<<"        MENU VENDOR TERLARIS"<<endl;
            cout<<"========================================"<<endl;
            cout<<"1. Semua Vendor"<<endl;
            cout<<"2. Top 5 Vendor"<<endl;
            cout<<"3. Vendor Terbaik Bulan Ini"<<endl;
            cout<<"4. Statistik Vendor"<<endl;
            cout<<"0. Kembali"<<endl;

            cout<<"\nPilih Menu : ";
            cin>>pilih;

            switch(pilih){

            case 1:
                semuaVendor();
                break;

            case 2:
                top5();
                break;

            case 3:
                vendorTerbaik();
                break;

            case 4:
                statistik();
                break;

            case 0:
                cout<<"\nKembali ke Dashboard...\n";
                break;

            default:
                cout<<"\nPilihan tidak tersedia!\n";

            }

        }while(pilih!=0);

    }

};

void menuDashboardAdmin(){

    int pilih;

    InfoTotalVendor objVendorInfo;
    DashboardPelanggan objPelanggan;
    TotalProduk objProduk;
    PendapatanMall objPendapatan;
    ProdukTerlaris objTerlaris;
    VendorTerlaris objVendorTerlaris;

    do{

        cout<<"\n====================================\n";
        cout<<"        DASHBOARD CERANMALL\n";
        cout<<"====================================\n";
        cout<<"1. Total Vendor\n";
        cout<<"2. Total Pelanggan\n";
        cout<<"3. Total Produk\n";
        cout<<"4. Pendapatan Mall\n";
        cout<<"5. Produk Terlaris\n";
        cout<<"6. Vendor Terlaris\n";
        cout<<"0. Kembali\n";
        cout<<"====================================\n";

        cout<<"Pilih Menu : ";
        cin>>pilih;

        switch(pilih){

        case 1:
            objVendorInfo.menuDashboard();
            break;

        case 2:
            objPelanggan.menu();
            break;

        case 3:
            objProduk.menu();
            break;

        case 4:
            objPendapatan.menu();
            break;

        case 5:
            objTerlaris.menu();
            break;

        case 6:
            objVendorTerlaris.menu();
            break;

        case 0:
            cout<<"\nKembali ke Menu Admin...\n";
            break;

        default:
            cout<<"\nPilihan tidak tersedia!\n";

        }

    }while(pilih!=0);

}


// MENU ADMIN MALL

void menuAdminMall(){

    int pilih;

    do{
        cout<<"\033[32m"<<endl;
        cout<<"\n====================================\n";
        cout<<"            ADMIN MALL\n";
        cout<<"====================================\n";
        cout<<"1. Dashboard\n";
        cout<<"2. Manajemen Vendor\n";
        cout<<"3. Manajemen Pelanggan\n";
        cout<<"4. Manajemen Produk\n";
        cout<<"5. Manajemen Kategori\n";
        cout<<"6. Manajemen Promo & Voucher\n";
        cout<<"7. Manajemen Transaksi\n";
        cout<<"8. Laporan\n";
        cout<<"9. Pengaturan Sistem\n";
        cout<<"0. Logout\n";
        cout<<"====================================\n";
        cout<<"\033[0m";

        cout<<"Pilih Menu : ";
        cin>>pilih;

        switch(pilih){

        case 1:
            menuDashboardAdmin();
            break;

        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            cout<<"\nMenu ini masih dalam tahap pengembangan.\n";
            break;

        case 0:
            cout<<"\nLogout dari Admin Mall...\n";
            break;

        default:
            cout<<"\nPilihan tidak tersedia!\n";

        }

    }while(pilih!=0);

}

//====================================================================
// MENU UTAMA CERANMALL
//====================================================================
int jalankanVendor(){

    int pilih;

    do{
        cout<<"\033[31m"<<endl;
        cout<<"\n====================================\n";
        cout<<"   SELAMAT DATANG DI CERANMALL\n";
        cout<<"====================================\n";
        cout<<"1. Pelanggan\n";
        cout<<"2. Vendor / Pemilik Toko\n";
        cout<<"3. Admin Mall\n";
        cout<<"4. Keluar\n";
        cout<<"====================================\n";
        cout<<"\033[0m"<<endl;

        cout<<"Pilih Menu : ";
        cin>>pilih;

        switch(pilih){

        case 1:
            cout<<"\nMenu Pelanggan akan dibuat oleh anggota lain.\n";
            break;

        case 2:
            cout<<"\nMenu Vendor akan dibuat oleh anggota lain.\n";
            break;

        case 3:
            menuAdminMall();
            break;

        case 4:
            cout<<"\nTerima kasih telah menggunakan CeranMall!\n";
            break;

        default:
            cout<<"\nPilihan tidak tersedia!\n";

        }

    }while(pilih!=4);

    return 0;

}

} // end modVendor
namespace modPelanggan {


// Batasan ukuran array manual karena tidak boleh pakai vector
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
    std::cout << "  ____ _____ ____    _    _   _     _   _ _   _ ____   \n";
    std::cout << " / ___| ____|  _ \\  / \\  | \\ | |   | | | | | | | __ )  \n";
    std::cout << "| |   |  _| | |_) |/ _ \\ |  \\| |   | |_| | | | |  _ \\  \n";
    std::cout << "| |___| |___|  _ </ ___ \\| |\\  |   |  _  | |_| | |_) | \n";
    std::cout << " \\____|_____|_| \\_/_/   \\_\\_| \\_|   |_| |_|\\___/|____/  \n";
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
    string namaTokoAsal; // Menyimpan info asal toko penyuplai produk

    Produk() : idProduk(""), namaProduk(""), stok(0), harga(0.0), namaTokoAsal("")
    {
    }

    Produk(string id, string nama, int s, double h) 
        : idProduk(id), namaProduk(nama), stok(s), harga(h), namaTokoAsal("")
    {
    }

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

    Toko() : idToko(""), namaToko(""), kategori(""), jumlahProduk(0)
    {
    }

    Toko(string id, string nama, string kat) : idToko(id), namaToko(nama), kategori(kat), jumlahProduk(0)
    {
    }

    void tambahProdukBaru(Produk p)
    {
        if (jumlahProduk < MAKS_PRODUK)
        {
            p.namaTokoAsal = namaToko; // Set nama toko asal secara otomatis
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

// Class 3: Pelanggan
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

    Pelanggan() : username(""), password(""), nik(""), nama(""), alamat(""), saldoWallet(0), jumlahItemKeranjang(0)
    {
    }

    Pelanggan(string user, string pass, string n, string nm, string al, double saldo) 
        : username(user), password(pass), nik(n), nama(nm), alamat(al), saldoWallet(saldo), jumlahItemKeranjang(0)
    {
    }

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

    Admin(string id, string kunci) : idAdmin(id), kunciKeamanan(kunci)
    {
    }

    void pantauKeuangan(double totalSirkulasi)
    {
        cetakHeaderBoxUI("SYSTEM LOG AUDIT INTERNAL FINANSIAL MALL");
        cout << "[AUDIT REALTIME] Total Sirkulasi Kas Arus Finansial Saat Ini: Rp" << fixed << setprecision(0) << totalSirkulasi << endl;
        cetakGarisPembatasUI();
    }
};

// Fungsi penanganan filter diskon kupon belanja terperinci (Menggunakan switch-case)
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

// =========================================================================
// CLASS BARU: PencetakStrukHub (DIINTEGRASIKAN SECARA SEMPURNA)
// Berfungsi khusus mengelola ekspor eksternal file struk_belanja.txt
// Sesuai Notulen: Tanpa waktu cetak, ada alamat, nama toko, dan kode acak tanggal.
// =========================================================================
class PencetakStrukHub
{
private:
    string kodeUnikTransaksi;
    int baseRandomNumber;

    int generateTokenAcakBerdasarkanMetode(int kodeMetodeBayar, int detik)
    {
        int hasilToken = 1000;
        switch (kodeMetodeBayar)
        {
            case 1:
                switch (detik % 2) {
                    case 0: hasilToken = 1100 + (detik * 3); break;
                    case 1: hasilToken = 1150 + (detik * 4); break;
                }
                break;
            case 2:
                switch (detik % 2) {
                    case 0: hasilToken = 2200 + (detik * 5); break;
                    case 1: hasilToken = 2250 + (detik * 2); break;
                }
                break;
            case 3:
                switch (detik % 2) {
                    case 0: hasilToken = 3300 + (detik * 2); break;
                    case 1: hasilToken = 3350 + (detik * 6); break;
                }
                break;
            case 4:
                switch (detik % 2) {
                    case 0: hasilToken = 4400 + (detik * 4); break;
                    case 1: hasilToken = 4450 + (detik * 3); break;
                }
                break;
            case 5:
                switch (detik % 2) {
                    case 0: hasilToken = 5500 + (detik * 7); break;
                    case 1: hasilToken = 5550 + (detik * 1); break;
                }
                break;
            case 6:
                switch (detik % 2) {
                    case 0: hasilToken = 6600 + (detik * 1); break;
                    case 1: hasilToken = 6650 + (detik * 9); break;
                }
                break;
            case 7:
                switch (detik % 2) {
                    case 0: hasilToken = 7700 + (detik * 6); break;
                    case 1: hasilToken = 7750 + (detik * 8); break;
                }
                break;
            case 8:
                switch (detik % 2) {
                    case 0: hasilToken = 8800 + (detik * 9); break;
                    case 1: hasilToken = 8850 + (detik * 5); break;
                }
                break;
            case 9:
                switch (detik % 2) {
                    case 0: hasilToken = 9900 + (detik * 8); break;
                    case 1: hasilToken = 9950 + (detik * 7); break;
                }
                break;
            default:
                switch (detik % 2) {
                    case 0: hasilToken = 5000 + detik; break;
                    case 1: hasilToken = 5050 - detik; break;
                }
                break;
        }
        return hasilToken;
    }

public:
    PencetakStrukHub()
    {
        kodeUnikTransaksi = "";
        baseRandomNumber = 0;
    }

    void buatBerkasStrukTxt(Pelanggan user, double totalBelanja, double nilaiDiskon, double pajak, double biayaPenanganan, double totalAkhir, string labelMetode, int kodeMetodeBayar)
    {
        WaktuTransaksi notulenWaktu;
        notulenWaktu.setWaktuSekarang();

        baseRandomNumber = generateTokenAcakBerdasarkanMetode(kodeMetodeBayar, notulenWaktu.detik);

        kodeUnikTransaksi = to_string(notulenWaktu.tanggal) + "-" + 
                             to_string(notulenWaktu.bulan) + "-" + 
                             to_string(notulenWaktu.tahun) + "-" + 
                             to_string(baseRandomNumber);

        ofstream fileNotaBelanja;
        fileNotaBelanja.open("struk_belanja.txt");

        if (fileNotaBelanja.is_open())
        {
            fileNotaBelanja << "=========================================\n";
            fileNotaBelanja << "        CERAN_HUB OFFICIAL MALL          \n";
            fileNotaBelanja << "             STRUK BELANJA EMALL         \n";
            fileNotaBelanja << "=========================================\n";
            fileNotaBelanja << "Kode Transaksi  : " << kodeUnikTransaksi << "\n";
            fileNotaBelanja << "Tanggal Cetak   : " << setfill('0') << setw(4) << notulenWaktu.tahun << "-"
                            << setw(2) << notulenWaktu.bulan << "-" << setw(2) << notulenWaktu.tanggal << "\n";
            fileNotaBelanja << "Nama Pelanggan  : " << user.nama << "\n";
            fileNotaBelanja << "Alamat Pelanggan: " << user.alamat << "\n"; 
            fileNotaBelanja << "Metode Bayar    : " << labelMetode << "\n";
            fileNotaBelanja << "-----------------------------------------\n";

            for (int i = 0; i < user.jumlahItemKeranjang; ++i)
            {
                fileNotaBelanja << user.keranjang[i].produk.namaTokoAsal << " " 
                                << user.keranjang[i].produk.namaProduk << " x" 
                                << user.keranjang[i].kuantitas << " : Rp" 
                                << fixed << setprecision(0) << user.keranjang[i].produk.harga * user.keranjang[i].kuantitas << "\n";
            }

            fileNotaBelanja << "-----------------------------------------\n";
            fileNotaBelanja << "Subtotal Awal   : Rp" << fixed << setprecision(0) << totalBelanja << "\n";
            fileNotaBelanja << "Diskon Potongan : Rp" << fixed << setprecision(0) << nilaiDiskon << "\n";
            fileNotaBelanja << "PPN (11%)       : Rp" << fixed << setprecision(0) << pajak << "\n";
            fileNotaBelanja << "Biaya Admin     : Rp" << fixed << setprecision(0) << biayaPenanganan << "\n";
            fileNotaBelanja << "Total Akhir     : Rp" << fixed << setprecision(0) << totalAkhir << "\n";
            fileNotaBelanja << "=========================================\n";
            fileNotaBelanja << "   TERIMA KASIH ATAS KUNJUNGAN ANDA!     \n";

            fileNotaBelanja.close();
            cout << "\n[SISTEM] Struk digital belanja sukses diekspor ke file 'struk_belanja.txt'!\n";
        }
        else
        {
            cout << "\n[ERROR] Saluran pembuatan file struk_belanja.txt gagal dimuat.\n";
        }
    }
};

int jalankanPelanggan()
{
    double totalSirkulasiFinansial = 0;
    Admin adminUtama("ADM01", "CERAN2026");

    // Inisialisasi Database User (Sistem Autentikasi)
    Pelanggan daftarUser[2] = {
        Pelanggan("arya123", "jogja2026", "3404123456789", "Arya Randani", "Sleman, Yogyakarta", 5000000),
        Pelanggan("user2", "pass2", "3404987654321", "Budi Santoso", "Bantul, Yogyakarta", 500000)
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

    // --- PEMBUKA MULTI TERMINAL SCREEN ---
    jalankanAnimasiLoading();
    cetakLogoMallBesar();

    // --- SISTEM LOGIN/AUTENTIKASI AWAL ---
    cout << "=========================================\n";
    cout << "          LOGIN SYSTEM CERAN_HUB MALL       \n";
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

    // --- LOOP MENU UTAMA INTERAKTIF ---
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
                            
                            // Ambil nama toko asal agar tercatat di struk belanja
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

                // Sistem Klaim Kupon Tambahan Sebelum Pajak
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
                        string pinShopee;
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

                        // Tampilkan Struk Ringkas Di Layar Konsol Utama
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

                        // =========================================================================
                        // AKTIVITAS UTAMA: Memanggil Class PencetakStrukHub untuk Ekspor Notepad .txt
                        // =========================================================================
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

    return 0;
}

} // end modPelanggan
namespace modAddAdmin {



// ==========================================
//            BATAS KAPASITAS DATA (ARRAY)
// ==========================================
const int MAX_TOKO         = 100;   // Maksimal jumlah toko
const int MAX_PRODUK       = 100;   // Maksimal produk per toko
const int MAX_USER         = 50;    // Maksimal akun admin
const int MAX_PESANAN      = 500;   // Maksimal transaksi tercatat
const int MAX_KATEGORI     = 100;   // Maksimal kategori unik
const int MAX_CUSTOMER     = 200;   // Maksimal customer unik

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
    Produk daftarProduk[MAX_PRODUK]; // Array pengganti vector<Produk>
    int jumlahProduk;                // Jumlah produk yang benar-benar terisi
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
//         DATABASE SIMULASI GLOBAL (ARRAY)
// ==========================================
User databaseUser[MAX_USER];
int jumlahUser = 0;

Toko daftarTokoMarketplace[MAX_TOKO];
int jumlahToko = 0;

PesananMasuk riwayatPesanan[MAX_PESANAN]; // Riwayat transaksi -> dasar data customer
int jumlahPesanan = 0;

User userLogin;
bool isLoggedIn = false;
bool sudahRegistrasi = false; // Flag untuk membatasi registrasi cukup sekali

// ==========================================
//             PROTOTIPE FUNGSI
// ==========================================
// --- Utility & Tampilan ---
void inisialisasiMarketplace();
void bersihkanLayar();
void tungguEnter();
void cetakGaris(int panjang, char simbol);
string toLowerStr(string s);
bool mengandung(const string& teks, const string& keyword);

// --- Autentikasi ---
void menuAutentikasi();
void registrasiAkunToko();
void loginAkunToko();

// --- Menu Utama Admin ---
void menuUtamaAdmin();
void tampilkanListBarangToko();

// --- Katalog & Tampilan Marketplace ---
void katalogUtamaMarketplace();
void tampilkanSemuaProdukKatalog();
void cariProdukKatalog();
void filterProdukPerKategori();

// --- Keuangan Toko ---
void manajemenKeuanganToko();

// --- Data Customer / Pembeli (Lengkap) ---
void menuDataCustomer();
void tampilkanSemuaDataCustomer();
void cariCustomerPerNama();
void cetakProfilCustomer(const string& nama, const string& alamat, int nomor);

// --- Riwayat & Rekap Barang Terjual ---
void cekBarangDibeli();
void tampilkanSemuaRiwayatBeli();
void cariBarangDibeliPerNama();
void rekapTotalBarangTerjual();

// --- Stok ---
void updateStokPemasukan();
void updateStokPengeluaran();

// --- Manajemen Toko (struktur toko) ---
void menuManajemenToko();
void tambahTokoBaru();
void hapusToko();

// --- Manajemen Produk ---
void menuManajemenProduk();
void tambahProdukKeToko();
void lihatDetailProduk();
void editProdukToko();
void hapusProduk();

// ==========================================
//                 MAIN FUNCTION
// ==========================================
int jalankanAddAdminToko() {
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
    for (size_t i = 0; i < s.size(); i++) s[i] = tolower((unsigned char)s[i]);
    return s;
}

// Cek apakah "teks" mengandung "keyword" (case-insensitive)
bool mengandung(const string& teks, const string& keyword) {
    return toLowerStr(teks).find(toLowerStr(keyword)) != string::npos;
}

void inisialisasiMarketplace() {
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
    uniqlo.daftarProduk[uniqlo.jumlahProduk].stok = 50;
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

    // --- Simulasi Pesanan Masuk (dasar data customer) ---
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
}

// ==========================================
//          SISTEM AUTENTIKASI
// ==========================================
void menuAutentikasi() {
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
    cout << "             Welcome to CERAN_HUB Admin Store                     \n";
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
            cout << "[!] Input harus angka!\n"; tungguEnter(); return;
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
//              MENU UTAMA ADMIN
// ==========================================
void menuUtamaAdmin() {
    bersihkanLayar();
    int pilihan;
    cetakGaris(55, '=');
    cout << "               ADMIN TOKO CERAN_HUB\n";
    cetakGaris(55, '=');
    cout << " 1. List Barang per Toko\n";
    cout << " 2. Manajemen Produk (Edit)\n";
    cout << " 3. Manajemen Toko (Edit)\n";
    cout << " 4. Katalog & Tampilan Utama Marketplace\n";
    cout << " 5. Laporan & Manajemen Keuangan Toko\n";
    cout << " 6. Data Customer / Pembeli (Lengkap)\n";
    cout << " 7. Riwayat & Rekap Barang Terjual\n";
    cout << " 8. Update Stok Pemasukan (Restock Toko)\n";
    cout << " 9. Update Stok Pengeluaran (Jual/Retur Barang)\n";
    cout << "10. Logout Kendali\n";
    cetakGaris(55, '-');
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
        case 10:
            isLoggedIn = false;
            cout << "\n[Sukses] Berhasil keluar dari panel admin.\n"; tungguEnter(); break;
        default: cout << "[!] Pilihan salah!\n"; tungguEnter();
    }
}

// 1. List Barang Toko
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

// ==========================================
//     FITUR KATALOG & TAMPILAN UTAMA
// ==========================================
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

void tampilkanSemuaProdukKatalog() {
    bersihkanLayar();
    cetakGaris(95, '=');
    cout << "                         ETALASE PRODUK - SEMUA TOKO\n";
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

    // Kumpulkan kategori unik memakai array biasa (pengganti vector<string>)
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

// ==========================================
//          MANAJEMEN KEUANGAN TOKO
// ==========================================
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

// ==========================================
//     DATA CUSTOMER / PEMBELI (LENGKAP)
// ==========================================
// Fitur ini mengelompokkan riwayatPesanan berdasarkan (nama + alamat) customer
// secara manual dengan array, tanpa map ataupun vector.

void menuDataCustomer() {
    int pil;
    do {
        bersihkanLayar();
        cetakGaris(73, '=');
        cout << "               DATA CUSTOMER / PEMBELI (LENGKAP)\n";
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

// Helper internal: cetak satu blok profil customer beserta seluruh barang yang dibeli.
// Menyusuri langsung array riwayatPesanan (tanpa perlu vector penampung sementara).
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

    // Kumpulkan pasangan (nama, alamat) unik memakai array paralel, sambil
    // menjaga urutan kemunculan customer pertama kali (pengganti map+vector).
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

// ==========================================
//   RIWAYAT & REKAP BARANG TERJUAL
// ==========================================
void cekBarangDibeli() {
    int pil;
    do {
        bersihkanLayar();
        cetakGaris(73, '=');
        cout << "            RIWAYAT & REKAP BARANG YANG DIBELI (TRANSAKSI)\n";
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

void tampilkanSemuaRiwayatBeli() {
    bersihkanLayar();
    cetakGaris(100, '=');
    cout << "                              RIWAYAT SEMUA TRANSAKSI\n";
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
    cout << "               REKAP TOTAL BARANG TERJUAL PER PRODUK\n";
    cetakGaris(80, '=');

    if (jumlahPesanan == 0) {
        cout << "[!] Belum ada data transaksi untuk direkap.\n"; tungguEnter(); return;
    }

    // Pengganti map<string,int> & map<string,double>: array paralel manual
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

    // Urutkan alfabetis secara manual (bubble sort sederhana, tanpa <algorithm>)
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

// ==========================================
//          MANAJEMEN STOK
// ==========================================
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
//        MANAJEMEN TOKO (STRUKTUR TOKO)
// ==========================================
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
            // Geser semua elemen setelahnya ke kiri (pengganti vector::erase)
            for (int k = i; k < jumlahToko - 1; k++) {
                daftarTokoMarketplace[k] = daftarTokoMarketplace[k + 1];
            }
            jumlahToko--;
            cout << "[Sukses] Jaringan toko berhasil dihapus dari sistem.\n"; tungguEnter(); return;
        }
    }
    cout << "[!] Gagal menghapus. ID Toko tidak valid.\n"; tungguEnter();
}

// ==========================================
//    MANAJEMEN PRODUK
// ==========================================
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

            // Validasi agar ID produk tidak duplikat di toko yang sama
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
                cout << "         DETAIL PRODUK\n";
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
                    // Geser elemen setelahnya ke kiri (pengganti vector::erase)
                    for (int k = j; k < t.jumlahProduk - 1; k++) {
                        t.daftarProduk[k] = t.daftarProduk[k + 1];
                    }
                    t.jumlahProduk--;
                    cout << "\n[Sukses] SKU Produk berhasil ditiadakan.\n";
                } else {
                    cout << "\n[Info] Penghapusan dibatalkan.\n";
                }
                tungguEnter(); return;
            }
        }
    }
    cout << "[!] ID Produk tidak ditemukan.\n"; tungguEnter();
}

} // end modAddAdmin
namespace modAdminFinal {



// ==========================================
//            BATAS KAPASITAS DATA (ARRAY)
// ==========================================
const int MAX_TOKO         = 100;   // Maksimal jumlah toko
const int MAX_PRODUK       = 100;   // Maksimal produk per toko
const int MAX_USER         = 50;    // Maksimal akun admin
const int MAX_PESANAN      = 500;   // Maksimal transaksi tercatat
const int MAX_KATEGORI     = 100;   // Maksimal kategori unik
const int MAX_CUSTOMER     = 200;   // Maksimal customer unik
// --- KAPASITAS TAMBAHAN BARU ---
const int MAX_PENGIRIMAN   = 500;
const int MAX_RETUR        = 100;
const int MAX_SUPLIER      = 50;
const int MAX_KARYAWAN     = 100;
const int MAX_VOUCHER      = 50;
const int MAX_KOMPLAIN     = 100;

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
    Produk daftarProduk[MAX_PRODUK]; // Array pengganti vector<Produk>
    int jumlahProduk;                // Jumlah produk yang benar-benar terisi
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

// --- STRUKTUR DATA TAMBAHAN BARU ---
struct Pengiriman {
    string noResi;
    string namaPembeli;
    string namaEkspedisi;
    string status; // "Diproses", "Dikirim", "Selesai", "Gagal"
};

struct Retur {
    int idRetur;
    string namaPembeli;
    string namaProduk;
    string alasan;
    string status; // "Menunggu", "Disetujui", "Ditolak"
};

struct Suplier {
    int id;
    string nama;
    string kontak;
    string alamat;
    string kategoriSupply;
};

struct Karyawan {
    int id;
    string nama;
    string jabatan;
    double gajiBulan;
    string status; // "Aktif", "Cuti", "Resign"
};

struct Voucher {
    string kode;
    double persenDiskon;
    int kuota;
    bool aktif;
};

struct Komplain {
    int idKomplain;
    string namaCustomer;
    string perihal;
    string pesan;
    string balasanAdmin;
    string status; // "Open", "Closed"
};

// ==========================================
//         DATABASE SIMULASI GLOBAL (ARRAY)
// ==========================================
User databaseUser[MAX_USER];
int jumlahUser = 0;

Toko daftarTokoMarketplace[MAX_TOKO];
int jumlahToko = 0;

PesananMasuk riwayatPesanan[MAX_PESANAN]; // Riwayat transaksi -> dasar data customer
int jumlahPesanan = 0;

// --- DATABASE TAMBAHAN BARU ---
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
bool sudahRegistrasi = false; // Flag untuk membatasi registrasi cukup sekali

// ==========================================
//             PROTOTIPE FUNGSI
// ==========================================
// --- Utility & Tampilan ---
void inisialisasiMarketplace();
void bersihkanLayar();
void tungguEnter();
void cetakGaris(int panjang, char simbol);
string toLowerStr(string s);
bool mengandung(const string& teks, const string& keyword);

// --- Autentikasi ---
void menuAutentikasi();
void registrasiAkunToko();
void loginAkunToko();

// --- Menu Utama Admin ---
void menuUtamaAdmin();
void tampilkanListBarangToko();

// --- Katalog & Tampilan Marketplace ---
void katalogUtamaMarketplace();
void tampilkanSemuaProdukKatalog();
void cariProdukKatalog();
void filterProdukPerKategori();

// --- Keuangan Toko ---
void manajemenKeuanganToko();

// --- Data Customer / Pembeli (Lengkap) ---
void menuDataCustomer();
void tampilkanSemuaDataCustomer();
void cariCustomerPerNama();
void cetakProfilCustomer(const string& nama, const string& alamat, int nomor);

// --- Riwayat & Rekap Barang Terjual ---
void cekBarangDibeli();
void tampilkanSemuaRiwayatBeli();
void cariBarangDibeliPerNama();
void rekapTotalBarangTerjual();

// --- Stok ---
void updateStokPemasukan();
void updateStokPengeluaran();

// --- Manajemen Toko (struktur toko) ---
void menuManajemenToko();
void tambahTokoBaru();
void hapusToko();

// --- Manajemen Produk ---
void menuManajemenProduk();
void tambahProdukKeToko();
void lihatDetailProduk();
void editProdukToko();
void hapusProduk();

// --- FITUR TAMBAHAN BARU ---
// Logistik & Pengiriman
void menuLogistik();
void lihatPengiriman();
void updateStatusPengiriman();

// Retur Barang
void menuRetur();
void lihatRetur();
void prosesRetur();

// Suplier
void menuSuplier();
void tambahSuplier();
void lihatSuplier();

// SDM & Karyawan
void menuSDM();
void tambahKaryawan();
void lihatKaryawan();
void bayarGajiKaryawan();

// Promosi & Voucher
void menuPromosi();
void tambahVoucher();
void lihatVoucher();

// Komplain & CS
void menuCS();
void lihatKomplain();
void balasKomplain();

// Analitik Lanjut
void menuAnalitik();
void laporanStokMenipis();
void laporanPajakGabungan();

// ==========================================
//                 MAIN FUNCTION
// ==========================================
int jalankanAdminTokoFinal() {
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
    for (size_t i = 0; i < s.size(); i++) s[i] = tolower((unsigned char)s[i]);
    return s;
}

// Cek apakah "teks" mengandung "keyword" (case-insensitive)
bool mengandung(const string& teks, const string& keyword) {
    return toLowerStr(teks).find(toLowerStr(keyword)) != string::npos;
}

void inisialisasiMarketplace() {
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
    uniqlo.daftarProduk[uniqlo.jumlahProduk].stok = 5; // Dibuat 5 agar terdeteksi stok menipis di fitur analitik
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

    // --- Simulasi Pesanan Masuk (dasar data customer) ---
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

    // --- DATA INISIALISASI TAMBAHAN BARU ---
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

// ==========================================
//          SISTEM AUTENTIKASI
// ==========================================
void menuAutentikasi() {
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
    cout << "             Welcome to CERAN_HUB Admin Store                     \n";
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
            cout << "[!] Input harus angka!\n"; tungguEnter(); return;
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
//              MENU UTAMA ADMIN
// ==========================================
void menuUtamaAdmin() {
    bersihkanLayar();
    int pilihan;
    cetakGaris(65, '=');
    cout << "               ADMIN TOKO CERAN_HUB\n";
    cetakGaris(65, '=');
    // --- FITUR LAMA (TIDAK ADA YANG DIUBAH/DIHAPUS) ---
    cout << " 1. List Barang per Toko\n";
    cout << " 2. Manajemen Produk (Edit)\n";
    cout << " 3. Manajemen Toko (Edit)\n";
    cout << " 4. Katalog & Tampilan Utama Marketplace\n";
    cout << " 5. Laporan & Manajemen Keuangan Toko\n";
    cout << " 6. Data Customer / Pembeli (Lengkap)\n";
    cout << " 7. Riwayat & Rekap Barang Terjual\n";
    cout << " 8. Update Stok Pemasukan (Restock Toko)\n";
    cout << " 9. Update Stok Pengeluaran (Jual/Retur Barang)\n";
    // --- FITUR BARU ---
    cout << "10. Sistem Logistik & Pengiriman \033[1;32m(NEW)\033[0m\n";
    cout << "11. Manajemen Suplier / Pemasok \033[1;32m(NEW)\033[0m\n";
    cout << "12. SDM & Manajemen Karyawan \033[1;32m(NEW)\033[0m\n";
    cout << "13. Sistem Retur Barang (RMA) \033[1;32m(NEW)\033[0m\n";
    cout << "14. Customer Service / Komplain \033[1;32m(NEW)\033[0m\n";
    cout << "15. Sistem Promosi & Voucher \033[1;32m(NEW)\033[0m\n";
    cout << "16. Analitik & Laporan Lanjut \033[1;32m(NEW)\033[0m\n";
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
        
        // Pemanggilan Menu Tambahan Baru
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

// 1. List Barang Toko (KODE ASLI)
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

// ==========================================
//     FITUR KATALOG & TAMPILAN UTAMA (KODE ASLI)
// ==========================================
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

void tampilkanSemuaProdukKatalog() {
    bersihkanLayar();
    cetakGaris(95, '=');
    cout << "                         ETALASE PRODUK - SEMUA TOKO\n";
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

    // Kumpulkan kategori unik memakai array biasa (pengganti vector<string>)
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

// ==========================================
//          MANAJEMEN KEUANGAN TOKO (KODE ASLI)
// ==========================================
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

// ==========================================
//     DATA CUSTOMER / PEMBELI (KODE ASLI)
// ==========================================
void menuDataCustomer() {
    int pil;
    do {
        bersihkanLayar();
        cetakGaris(73, '=');
        cout << "               DATA CUSTOMER / PEMBELI (LENGKAP)\n";
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

// ==========================================
//   RIWAYAT & REKAP BARANG TERJUAL (KODE ASLI)
// ==========================================
void cekBarangDibeli() {
    int pil;
    do {
        bersihkanLayar();
        cetakGaris(73, '=');
        cout << "            RIWAYAT & REKAP BARANG YANG DIBELI (TRANSAKSI)\n";
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

void tampilkanSemuaRiwayatBeli() {
    bersihkanLayar();
    cetakGaris(100, '=');
    cout << "                              RIWAYAT SEMUA TRANSAKSI\n";
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
    cout << "               REKAP TOTAL BARANG TERJUAL PER PRODUK\n";
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

// ==========================================
//          MANAJEMEN STOK (KODE ASLI)
// ==========================================
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
//        MANAJEMEN TOKO (KODE ASLI)
// ==========================================
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

// ==========================================
//    MANAJEMEN PRODUK (KODE ASLI)
// ==========================================
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
                cout << "         DETAIL PRODUK\n";
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
                    cout << "\n[Sukses] SKU Produk berhasil ditiadakan.\n";
                } else {
                    cout << "\n[Info] Penghapusan dibatalkan.\n";
                }
                tungguEnter(); return;
            }
        }
    }
    cout << "[!] ID Produk tidak ditemukan.\n"; tungguEnter();
}


// ==========================================
//   IMPLEMENTASI FITUR TAMBAHAN BARU 
// ==========================================

// --- 10. Sistem Logistik & Pengiriman ---
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

// --- 11. Manajemen Suplier ---
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

void lihatSuplier() {
    bersihkanLayar();
    cetakGaris(85, '=');
    cout << "                        DAFTAR MITRA SUPLIER\n";
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

// --- 12. SDM & Manajemen Karyawan ---
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

void lihatKaryawan() {
    bersihkanLayar();
    cetakGaris(80, '=');
    cout << "                        DATA KARYAWAN PERUSAHAAN\n";
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

// --- 13. Sistem Retur Barang (RMA) ---
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

void lihatRetur() {
    bersihkanLayar();
    cetakGaris(85, '=');
    cout << "                    DAFTAR PENGAJUAN RETUR BARANG\n";
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

// --- 14. Customer Service / Komplain ---
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

void lihatKomplain() {
    bersihkanLayar();
    cetakGaris(80, '=');
    cout << "                     TIKET KOMPLAIN PELANGGAN\n";
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

// --- 15. Sistem Promosi & Voucher ---
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

// --- 16. Analitik & Laporan Lanjut ---
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

void laporanStokMenipis() {
    bersihkanLayar();
    cetakGaris(75, '=');
    cout << "           PERINGATAN STOK KRITIS / MENIPIS (<= 10 pcs)\n";
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
    cout << "        LAPORAN KEWAJIBAN PAJAK KESELURUHAN (PPN 11%)\n";
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

} // end modAdminFinal
namespace modPemesanan {


class Barang {
public:
    string nama;
    int harga;
    Barang(string n, int h) : nama(n), harga(h) {}
};

class SistemPemesanan {
private:
    vector<Barang> daftarPesanan;

public:
    void tambahPesanan(string nama, int harga) {
        daftarPesanan.push_back(Barang(nama, harga));
        cout << "--- [OK] " << nama << " ditambahkan ke keranjang ---\n" << endl;
    }

    void tampilkanStruk() {
        cout << "\n========== DAFTAR PESANAN ANDA ==========" << endl;
        if (daftarPesanan.empty()) {
            cout << "Belum ada pesanan." << endl;
        } else {
            int total = 0;
            for (size_t i = 0; i < daftarPesanan.size(); i++) {
                cout << i + 1 << ". " << daftarPesanan[i].nama 
                     << " \t- Rp" << daftarPesanan[i].harga << endl;
                total += daftarPesanan[i].harga;
            }
            cout << "-----------------------------------------" << endl;
            cout << "Total Biaya: \tRp" << total << endl;
        }
        cout << "=========================================\n" << endl;
    }
};

int jalankanPemesanan() {
    SistemPemesanan pesan;
    int pilihanUtama, pilihanBarang;

    cout << "--- Selamat Datang di Toko Perabotan ---" << endl;

    do {
        cout << "Menu Utama:" << endl;
        cout << "1. Lihat List Peralatan Rumah Tangga" << endl;
        cout << "2. Lihat list peralatan mobil"<<endl;
        cout << "3. Lihat Keranjang & Total" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihanUtama;

        if (pilihanUtama == 1) {
            // Sub-menu List Barang
            cout << "\n--- Daftar Peralatan Rumah Tangga ---" << endl;
            cout << "1. Sapu (Rp25000)" << endl;
            cout << "2. Pel   (Rp45000)" << endl;
            cout << "3. Ember (Rp15000)" << endl;
            cout << "4. Kembali" << endl;
            cout << "Pilih barang yang ingin dipesan (1-4): ";
            cin >> pilihanBarang;

            if (pilihanBarang == 1) pesan.tambahPesanan("Sapu", 25000);
            else if (pilihanBarang == 2) pesan.tambahPesanan("Pel", 45000);
            else if (pilihanBarang == 3) pesan.tambahPesanan("Ember", 15000);
           
        } else if (pilihanUtama == 2) {
            
        }
        
         if (pilihanUtama == 2) {
            // Sub-menu List Barang
            cout << "\n--- Daftar Peralatan Rumah Tangga ---" << endl;
            cout << "1. Ban (Rp25000)" << endl;
            cout << "2. Knalpot   (Rp45000)" << endl;
            cout << "3. Spion (Rp15000)" << endl;
            cout << "4. Kembali" << endl;
            cout << "Pilih barang yang ingin dipesan (1-4): ";
            cin >> pilihanBarang;

            if (pilihanBarang == 1) pesan.tambahPesanan("Ban", 25000);
            else if (pilihanBarang == 2) pesan.tambahPesanan("knalpot", 45000);
            else if (pilihanBarang == 3) pesan.tambahPesanan("spion", 15000);
           
        } else if (pilihanUtama == 2) {
            pesan.tampilkanStruk();
        }
		
		
    } while (pilihanUtama != 4);

    cout << "Terima kasih!" << endl;
    return 0;
}





} // end modPemesanan

// ============================================================
//   MENU UTAMA DEMO CERAN_HUB (menghubungkan seluruh modul)
// ============================================================
int main() {
    int pilihan;
    do {
        cout << "\n=========================================\n";
        cout << "   CERAN_HUB - DEMO PROYEK ALPRO KEL. 14  \n";
        cout << "=========================================\n";
        cout << "1. Modul Admin - Manajemen Vendor & Laporan Mall\n";
        cout << "2. Modul Pelanggan - Belanja di CeranMall\n";
        cout << "3. Modul Admin Toko - Registrasi Toko Baru\n";
        cout << "4. Modul Admin Toko - Dashboard Lengkap (Final)\n";
        cout << "5. Modul Sistem Pemesanan Barang\n";
        cout << "0. Keluar\n";
        cout << "=========================================\n";
        cout << "Pilih modul: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: modVendor::jalankanVendor(); break;
            case 2: modPelanggan::jalankanPelanggan(); break;
            case 3: modAddAdmin::jalankanAddAdminToko(); break;
            case 4: modAdminFinal::jalankanAdminTokoFinal(); break;
            case 5: modPemesanan::jalankanPemesanan(); break;
            case 0: cout << "\nTerima kasih telah menggunakan CERAN_HUB!\n"; break;
            default: cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihan != 0);
    return 0;
}
