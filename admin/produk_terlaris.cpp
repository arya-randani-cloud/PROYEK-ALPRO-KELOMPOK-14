#include <iostream>
#include <iomanip>

using namespace std;
class ProdukTerlaris{

private:

    //==================== SEMBAKO ====================

    string sembako[5]={
       "Beras Ramos 5 Kg", "Minyak Goreng", "Gula Pasir", "Telur Ayam", "Tepung Terigu"
    };

    int terjualSembako[5]={
       320,285,250,210,180
    };

    //==================== GAMING ====================

    string gaming[5]={
        "Mouse Logitech", "Keyboard Gaming", "Headset Gaming", "Mousepad XL", "Joystick"
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

int main(){

    ProdukTerlaris admin;

    admin.menu();

    return 0;

}
