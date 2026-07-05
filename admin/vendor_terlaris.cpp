#include <iostream>
#include <iomanip>

using namespace std;

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

int main(){

    VendorTerlaris admin;

    admin.menu();

    return 0;

}