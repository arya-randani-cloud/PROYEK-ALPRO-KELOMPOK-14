#include <iostream>
#include <iomanip>

using namespace std;

class Vendor{

private:

    string idVendor[100];
    string namaToko[100];
    string namaPemilik[100];
    string kategori[100];
    string email[100];
    string noHP[100];
    string status[100];

    int jumlahVendor;

public:

    Vendor(){

        jumlahVendor=3;

        idVendor[0]="V001";
        namaToko[0]="Toko Makmur";
        namaPemilik[0]="Andi";
        kategori[0]="Sembako";
        email[0]="makmur@gmail.com";
        noHP[0]="081234567890";
        status[0]="Aktif";

        idVendor[1]="V002";
        namaToko[1]="Game Store";
        namaPemilik[1]="Budi";
        kategori[1]="Gaming";
        email[1]="gamestore@gmail.com";
        noHP[1]="081222222222";
        status[1]="Aktif";

        idVendor[2]="V003";
        namaToko[2]="Tech Store";
        namaPemilik[2]="Citra";
        kategori[2]="Elektronik";
        email[2]="tech@gmail.com";
        noHP[2]="081333333333";
        status[2]="Aktif";

    }

    void tampilVendor(){

        cout<<"\n=============================================================\n";
        cout<<"                    DAFTAR VENDOR\n";
        cout<<"=============================================================\n";

        cout<<left
        <<setw(8)<<"ID"
        <<setw(20)<<"Nama Toko"
        <<setw(18)<<"Pemilik"
        <<setw(18)<<"Kategori"
        <<"Status"<<endl;

        cout<<"-------------------------------------------------------------\n";

        for(int i=0;i<jumlahVendor;i++){

            cout<<left
            <<setw(8)<<idVendor[i]
            <<setw(20)<<namaToko[i]
            <<setw(18)<<namaPemilik[i]
            <<setw(18)<<kategori[i]
            <<status[i]<<endl;

        }

    }

    void tambahVendor(){

        cout<<"\n=========== TAMBAH VENDOR BARU ===========\n";

        cin.ignore();

        cout<<"ID Vendor        : ";
        getline(cin,idVendor[jumlahVendor]);

        cout<<"Nama Toko        : ";
        getline(cin,namaToko[jumlahVendor]);

        cout<<"Nama Pemilik     : ";
        getline(cin,namaPemilik[jumlahVendor]);

        cout<<"Kategori         : ";
        getline(cin,kategori[jumlahVendor]);

        cout<<"Email            : ";
        getline(cin,email[jumlahVendor]);

        cout<<"No HP            : ";
        getline(cin,noHP[jumlahVendor]);

        status[jumlahVendor]="Aktif";

        jumlahVendor++;

        cout<<"\n=====================================\n";
        cout<<"Vendor berhasil ditambahkan.\n";
        cout<<"Status Vendor : Aktif\n";
        cout<<"Total Vendor : "<<jumlahVendor<<endl;
        cout<<"=====================================\n";

    }

    void menu(){

        int pilih;

        do{

            cout<<"\n====================================\n";
            cout<<"     MENU TAMBAH VENDOR\n";
            cout<<"====================================\n";
            cout<<"1. Lihat Vendor\n";
            cout<<"2. Tambah Vendor\n";
            cout<<"0. Kembali\n";
            cout<<"====================================\n";

            cout<<"Pilih : ";
            cin>>pilih;

            switch(pilih){

            case 1:

                tampilVendor();
                break;

            case 2:

                tambahVendor();
                break;

            case 0:

                cout<<"\nKembali...\n";
                break;

            default:

                cout<<"\nMenu tidak tersedia.\n";

            }

        }while(pilih!=0);

    }

};

int main(){

    Vendor admin;

    admin.menu();

    return 0;

}