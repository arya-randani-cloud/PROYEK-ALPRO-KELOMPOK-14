#include <iostream>
#include <iomanip>

using namespace std;

class Vendor{

private:

    string id[10]={
        "V001","V002","V003","V004","V005",
        "V006","V007","V008","V009","V010"
    };

    string toko[10]={
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

    string pemilik[10]={
        "Andi","Budi","Citra","Dewi","Eko",
        "Farhan","Gilang","Hasan","Indra","Joko"
    };

    string kategori[10]={
        "Sembako",
        "Gaming",
        "Elektronik",
        "Fashion",
        "Kesehatan",
        "ATK",
        "Pet Shop",
        "Bayi",
        "Olahraga",
        "Otomotif"
    };

    string status[10]={
        "Aktif",
        "Aktif",
        "Aktif",
        "Aktif",
        "Aktif",
        "Aktif",
        "Nonaktif",
        "Aktif",
        "Nonaktif",
        "Aktif"
    };

    int produk[10]={
        35,28,40,25,18,
        20,15,16,22,19
    };

    float rating[10]={
        4.9,4.8,4.7,4.8,4.6,
        4.5,4.3,4.4,4.2,4.6
    };

public:

    void semuaVendor(){

        cout<<"\n================ DAFTAR SEMUA VENDOR ================\n\n";

        cout<<left
        <<setw(8)<<"ID"
        <<setw(20)<<"Nama Toko"
        <<setw(15)<<"Pemilik"
        <<setw(18)<<"Kategori"
        <<setw(12)<<"Status"<<endl;

        cout<<"---------------------------------------------------------------"<<endl;

        for(int i=0;i<10;i++){

            cout<<left
            <<setw(8)<<id[i]
            <<setw(20)<<toko[i]
            <<setw(15)<<pemilik[i]
            <<setw(18)<<kategori[i]
            <<setw(12)<<status[i]<<endl;

        }

    }

    void vendorAktif(){

        cout<<"\n================ VENDOR AKTIF ================\n\n";

        cout<<left
        <<setw(8)<<"ID"
        <<setw(20)<<"Nama Toko"
        <<setw(15)<<"Kategori"<<endl;

        cout<<"----------------------------------------------"<<endl;

        for(int i=0;i<10;i++){

            if(status[i]=="Aktif"){

                cout<<left
                <<setw(8)<<id[i]
                <<setw(20)<<toko[i]
                <<setw(15)<<kategori[i]<<endl;

            }

        }

    }

    void vendorNonaktif(){

        cout<<"\n============== VENDOR NONAKTIF ==============\n\n";

        cout<<left
        <<setw(8)<<"ID"
        <<setw(20)<<"Nama Toko"
        <<setw(15)<<"Kategori"<<endl;

        cout<<"----------------------------------------------"<<endl;

        for(int i=0;i<10;i++){

            if(status[i]=="Nonaktif"){

                cout<<left
                <<setw(8)<<id[i]
                <<setw(20)<<toko[i]
                <<setw(15)<<kategori[i]<<endl;

            }

        }

    }

    void detailVendor(){

        string cari;
        bool ketemu=false;

        cout<<"\nMasukkan ID Vendor : ";
        cin>>cari;

        for(int i=0;i<10;i++){

            if(cari==id[i]){

                ketemu=true;

                cout<<"\n=============== DETAIL VENDOR ===============\n";
                cout<<"ID Vendor        : "<<id[i]<<endl;
                cout<<"Nama Toko        : "<<toko[i]<<endl;
                cout<<"Nama Pemilik     : "<<pemilik[i]<<endl;
                cout<<"Kategori         : "<<kategori[i]<<endl;
                cout<<"Status           : "<<status[i]<<endl;
                cout<<"Jumlah Produk    : "<<produk[i]<<endl;
                cout<<"Rating           : "<<rating[i]<<endl;

            }

        }

        if(!ketemu){

            cout<<"\nVendor tidak ditemukan.\n";

        }

    }

    void menu(){

        int pilih;

        do{

            cout<<"\n======================================"<<endl;
            cout<<"         MENU LIHAT VENDOR"<<endl;
            cout<<"======================================"<<endl;
            cout<<"1. Semua Vendor"<<endl;
            cout<<"2. Vendor Aktif"<<endl;
            cout<<"3. Vendor Nonaktif"<<endl;
            cout<<"4. Detail Vendor"<<endl;
            cout<<"0. Kembali"<<endl;

            cout<<"\nPilih : ";
            cin>>pilih;

            switch(pilih){

            case 1:
                semuaVendor();
                break;

            case 2:
                vendorAktif();
                break;

            case 3:
                vendorNonaktif();
                break;

            case 4:
                detailVendor();
                break;

            case 0:
                cout<<"\nKembali..."<<endl;
                break;

            default:
                cout<<"\nMenu tidak tersedia."<<endl;

            }

        }while(pilih!=0);

    }

};

int main(){

    Vendor admin;

    admin.menu();

    return 0;

}