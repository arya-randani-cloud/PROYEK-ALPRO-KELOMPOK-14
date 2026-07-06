#include <iostream>
#include <iomanip>

using namespace std;
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
int main(){

    int pilih;

    do{

        cout<<"\n====================================\n";
        cout<<"   SELAMAT DATANG DI CERANMALL\n";
        cout<<"====================================\n";
        cout<<"1. Pelanggan\n";
        cout<<"2. Vendor / Pemilik Toko\n";
        cout<<"3. Admin Mall\n";
        cout<<"4. Keluar\n";
        cout<<"====================================\n";

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
