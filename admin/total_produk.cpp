#include <iostream>
#include <iomanip>
using namespace std;

class TotalProduk {

private:

    // SEMBAKO
    string sembako[5] = {
        "Beras Ramos 5 Kg",
        "Minyak Goreng",
        "Gula Pasir",
        "Telur Ayam",
        "Tepung Terigu"
    };

    int hargaSembako[5] = {
        75000,18000,16000,30000,14000
    };

    string tokoSembako[5] = {
        "Toko Makmur",
        "Sembako Jaya",
        "Berkah Store",
        "Toko Rizki",
        "Maju Jaya"
    };

    // GAMING
    string gaming[5] = {
        "Mouse Logitech",
        "Keyboard Gaming",
        "Headset Gaming",
        "Mousepad XL",
        "Joystick"
    };

    int hargaGaming[5] = {
        250000,650000,350000,120000,450000
    };

    string tokoGaming[5] = {
        "Game Store",
        "GG Shop",
        "Arena Gaming",
        "Pro Gamer",
        "Zona Game"
    };

    // ELEKTRONIK
    string elektronik[5] = {
        "Laptop ASUS",
        "Printer Epson",
        "SSD 512 GB",
        "Flashdisk 32 GB",
        "Monitor LG"
    };

    int hargaElektronik[5] = {
        8500000,2100000,850000,75000,1800000
    };

    string tokoElektronik[5] = {
        "Tech Store",
        "Elektronik Jaya",
        "Digital Shop",
        "KomputerKu",
        "Smart Tech"
    };

    // ALAT TULIS
    string alatTulis[5] = {
        "Buku Tulis",
        "Pulpen",
        "Pensil",
        "Penghapus",
        "Penggaris"
    };

    int hargaATK[5] = {
        5000,3000,2000,1500,4000
    };

    string tokoATK[5] = {
        "ATK Jaya",
        "Toko Pena",
        "Sekolah Store",
        "Mitra ATK",
        "Pelajar Shop"
    };

    // FASHION
    string fashion[5] = {
        "Kaos Polos",
        "Hoodie Oversize",
        "Celana Jeans",
        "Jaket Varsity",
        "Topi"
    };

    int hargafashion[5] = {
        85000,175000,220000,310000,65000
    };

    string tokofashion[5] = {
        "Zidan Fashion",
        "Urban Wear",
        "Denim Store",
        "Style Shop",
        "Trean Fashion"
    };

    // KESEHATAN
    string kesehatan[5] = {
        "Vitamin C",
        "Masker Medis",
        "Hand Sanitizer",
        "Termometer Digital",
        "Tensimeter"
    };

    int hargakesehatan[5] = {
        35000,25000,18000,95000,250000
    };

    string tokokesehatan[5] = {
        "Budi Sehat",
        "Sutopo Langgeng",
        "K24",
        "Sido Mari",
        "Sami Sehat"
    };

      // OTOMOTIF
    string otomotif[5] = {
        "Oli Mesin",
        "Helm ",
        "Ban Motor",
        "Lampu Biled",
        "Cover Motor"
    };

    int hargaotomotif[5] = {
        75000,450000,280000,90000,120000
    };

    string tokootomotif[5] = {
        "Cahyo Garage",
        "Sultan Helmet",
        "88 Ban",
        "Parno Garage",
        "Custom Otomotif"
    };

      // OLAHRAGA
    string olahraga[5] = {
        "Bola Lapangan",
        "Raket Badminton",
        "Matras",
        "Sepatu",
        "Treadmil"
    };

    int hargaolahraga[5] = {
        150000,200000,50000,950000,50000000
    };

    string tokoolahraga[5] = {
        "Jempol",
        "Mitra10",
        "Speed",
        "Rukun",
        "Generik"
    };

      // PERLENGKAPAN BAYI
    string perlengkapanBayi[5] = {
        "Popok",
        "Susu",
        "Bedak",
        "Kereta Bayi",
        "Pakaian Bayi"
    };

    int hargaperlengkapanBayi[5] = {
        35000,25000,18000,1195000,150000
    };

    string tokoperlengkapanBayi[5] = {
        "Baby Zania",
        "Wijaya Store",
        "Vinolla Baby And Kids",
        "Baby Word",
        "Clandy Baby Shop"
    };

      // PERLENGKAPAN HEWAN
    string perlengkapanHewan[5] = {
        "Makanan Kucing",
        "Pasir Kucing",
        "Kalung Kucing",
        "Shampoo Hewan",
        "Kandang Hewan"
    };

    int hargaperlengkapanHewan[5] = {
        50000,25000,18000,95000,200000
    };

    string tokoperlengkapanHewan[5] = {
        "Saffron Petshop",
        "Pet Gallery",
        "Petshop Indonesia 28",
        "Usro Petshop",
        "Barokah Petshop"
    };

      // BUKU
    string buku[5] = {
        "Novel",
        "Buku psikotes",
        "Kamus 3 Bahasa",
        "Komik",
        "Buku Pelajaran"
    };

    int hargabuku[5] = {
        50000,50000,38000,15000,25000
    };

    string tokobuku[5] = {
        "Social Agency Baru",
        "Buku Akik",
        "Solusi Buku",
        "Shira Media",
        "Kedai Jual Buku Sastra"
    };

    // KECANTIKAN
    string kecantikan[5] = {
        "Facial Wash",
        "Sunscreen",
        "Lip Tint",
        "Serum Wajah",
        "Moisturizer"
    };

    int hargakecantikan[5] = {
        150000,68000,55000,250000,90000
    };

    string tokokecantikan[5] = {
        "Mutiara Pusat Kosmetik",
        "ELS Beauty",
        "CF Beauty",
        "Toko Puspa Indah",
        "Rea Beauty"
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

int main(){

    TotalProduk admin;

    admin.menu();

    return 0;

}