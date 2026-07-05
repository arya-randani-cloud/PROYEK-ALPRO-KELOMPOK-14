#include <iostream>
#include <iomanip>
using namespace std;
class CariVendor{

        private:
            string idVendor[10]={
                "V001","V002","V003","V004","V005",
                "V006","V007","V008","V009","V010"
    };

        string namaToko[10]={
            "Toko Makmur","Game Store","Tech Store","FashionKu","Healthy Shop","ATK Jaya","Pet House","Baby Mart","Sport Center", "Otomotif Jaya"
    };

    string pemilik[10]={
        "Andi","Budi","Citra","Dewi","Eko","Farhan","Gilang","Hasan","Indra","Joko"
    };

    string kategori[10]={
        "Sembako","Gaming","Elektronik","Fashion","Kesehatan","ATK","Pet Shop","Bayi","Olahraga","Otomotif"
    };

    string status[10]={
        "Aktif","Aktif","Aktif","Aktif","Aktif","Aktif","Nonaktif","Aktif","Nonaktif","Aktif"
    };

public:

    void cariID(){

        string cari;
        bool ketemu=false;

        cout<<"\nMasukkan ID Vendor : ";
        cin>>cari;

        for(int i=0;i<10;i++){

            if(cari==idVendor[i]){

                ketemu=true;

                cout<<"\n========== DATA VENDOR ==========\n";
                cout<<"ID Vendor      : "<<idVendor[i]<<endl;
                cout<<"Nama Toko      : "<<namaToko[i]<<endl;
                cout<<"Pemilik        : "<<pemilik[i]<<endl;
                cout<<"Kategori       : "<<kategori[i]<<endl;
                cout<<"Status         : "<<status[i]<<endl;

            }

        }

        if(!ketemu){

            cout<<"\nVendor tidak ditemukan.\n";

        }

    }

    void cariNamaToko(){

        string cari;
        bool ketemu=false;

        cin.ignore();

        cout<<"\nMasukkan Nama Toko : ";
        getline(cin,cari);

        for(int i=0;i<10;i++){

            if(cari==namaToko[i]){

                ketemu=true;

                cout<<"\n========== DATA VENDOR ==========\n";
                cout<<"ID Vendor      : "<<idVendor[i]<<endl;
                cout<<"Nama Toko      : "<<namaToko[i]<<endl;
                cout<<"Pemilik        : "<<pemilik[i]<<endl;
                cout<<"Kategori       : "<<kategori[i]<<endl;
                cout<<"Status         : "<<status[i]<<endl;

            }

        }

        if(!ketemu){

            cout<<"\nVendor tidak ditemukan.\n";

        }

    }

    void cariPemilik(){

        string cari;
        bool ketemu=false;

        cin.ignore();

        cout<<"\nMasukkan Nama Pemilik : ";
        getline(cin,cari);

        for(int i=0;i<10;i++){

            if(cari==pemilik[i]){

                ketemu=true;

                cout<<"\n========== DATA VENDOR ==========\n";
                cout<<"ID Vendor      : "<<idVendor[i]<<endl;
                cout<<"Nama Toko      : "<<namaToko[i]<<endl;
                cout<<"Pemilik        : "<<pemilik[i]<<endl;
                cout<<"Kategori       : "<<kategori[i]<<endl;
                cout<<"Status         : "<<status[i]<<endl;

            }

        }

        if(!ketemu){

            cout<<"\nVendor tidak ditemukan.\n";

        }

    }

    void menu(){

        int pilih;

        do{

            cout<<"\n=====================================\n";
            cout<<"          CARI VENDOR\n";
            cout<<"=====================================\n";
            cout<<"1. Cari berdasarkan ID\n";
            cout<<"2. Cari berdasarkan Nama Toko\n";
            cout<<"3. Cari berdasarkan Nama Pemilik\n";
            cout<<"0. Kembali\n";
            cout<<"=====================================\n";

            cout<<"Pilih Menu : ";
            cin>>pilih;

            switch(pilih){

            case 1:

                cariID();
                break;

            case 2:

                cariNamaToko();
                break;

            case 3:

                cariPemilik();
                break;

            case 0:

                cout<<"\nKembali...\n";
                break;

            default:

                cout<<"\nPilihan tidak tersedia.\n";

            }

        }while(pilih!=0);

    }

};

int main(){

    CariVendor admin;

    admin.menu();

    return 0;

}
