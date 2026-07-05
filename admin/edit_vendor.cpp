#include <iostream>
#include <iomanip>

using namespace std;

//====================================================================
// CLASS EDIT VENDOR
//====================================================================
class EditVendor{

private:

    string idVendor[10]={
        "V001","V002","V003","V004","V005",
        "V006","V007","V008","V009","V010"
    };

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

    string pemilik[10]={
        "Andi","Budi","Citra","Dewi","Eko",
        "Farhan","Gilang","Hasan","Indra","Joko"
    };

    string kategori[10]={
        "Sembako","Gaming","Elektronik","Fashion","Kesehatan",
        "Alat Tulis","Hewan","Bayi","Olahraga","Otomotif"
    };

    string email[10]={
        "andi@gmail.com",
        "budi@gmail.com",
        "citra@gmail.com",
        "dewi@gmail.com",
        "eko@gmail.com",
        "farhan@gmail.com",
        "gilang@gmail.com",
        "hasan@gmail.com",
        "indra@gmail.com",
        "joko@gmail.com"
    };

    string noHp[10]={
        "081234567801",
        "08123456789",
        "081234567803",
        "081234567804",
        "081234567805",
        "081234567806",
        "081234567807",
        "081234567808",
        "081234567809",
        "081234567810"
    };

    string status[10]={
        "Aktif","Aktif","Nonaktif","Aktif","Nonaktif",
        "Aktif","Aktif","Nonaktif","Aktif","Nonaktif"
    };

    // variabel sementara untuk menyimpan data lama sebelum diedit
    string namaTokoLama;
    string pemilikLama;
    string kategoriLama;
    string emailLama;
    string hpLama;
    string statusLama;

public:

    void tampilSemuaVendor(){

        cout<<"\n========================================================\n";
        cout<<left
            <<setw(10)<<"ID"
            <<setw(24)<<"Nama Toko"
            <<"Pemilik"<<endl;
        cout<<"========================================================\n";

        for(int i=0;i<10;i++){

            cout<<left
                <<setw(10)<<idVendor[i]
                <<setw(24)<<namaToko[i]
                <<pemilik[i]<<endl;

        }

        cout<<"========================================================\n";

    }

    int cariVendor(string id){

        int indeks=-1;

        for(int i=0;i<10;i++){

            if(idVendor[i]==id){

                indeks=i;

            }

        }

        return indeks;

    }

    void tampilDetailVendor(int idx){

        cout<<"\n========================================================\n";
        cout<<"                 DETAIL DATA VENDOR\n";
        cout<<"========================================================\n";
        cout<<"ID Vendor      : "<<idVendor[idx]<<endl;
        cout<<"Nama Toko      : "<<namaToko[idx]<<endl;
        cout<<"Nama Pemilik   : "<<pemilik[idx]<<endl;
        cout<<"Kategori       : "<<kategori[idx]<<endl;
        cout<<"Email          : "<<email[idx]<<endl;
        cout<<"Nomor HP       : "<<noHp[idx]<<endl;
        cout<<"Status         : "<<status[idx]<<endl;
        cout<<"========================================================\n";

    }

    void simpanDataLama(int idx){

        namaTokoLama=namaToko[idx];
        pemilikLama=pemilik[idx];
        kategoriLama=kategori[idx];
        emailLama=email[idx];
        hpLama=noHp[idx];
        statusLama=status[idx];

    }

    void tampilHasilPerubahan(int idx){

        cout<<"\n========================================================\n";
        cout<<"              HASIL PERUBAHAN DATA\n";
        cout<<"========================================================\n";

        cout<<left
            <<setw(15)<<"Field"
            <<setw(20)<<"Sebelum"
            <<"Sesudah"<<endl;

        cout<<"--------------------------------------------------------\n";

        cout<<left<<setw(15)<<"Nama Toko"<<setw(20)<<namaTokoLama<<namaToko[idx]<<endl;
        cout<<left<<setw(15)<<"Pemilik"<<setw(20)<<pemilikLama<<pemilik[idx]<<endl;
        cout<<left<<setw(15)<<"Kategori"<<setw(20)<<kategoriLama<<kategori[idx]<<endl;
        cout<<left<<setw(15)<<"Email"<<setw(20)<<emailLama<<email[idx]<<endl;
        cout<<left<<setw(15)<<"Nomor HP"<<setw(20)<<hpLama<<noHp[idx]<<endl;
        cout<<left<<setw(15)<<"Status"<<setw(20)<<statusLama<<status[idx]<<endl;

        cout<<"========================================================\n";

        cout<<"\nData Vendor berhasil diperbarui.\n";

    }

    void tampilLogAktivitas(int idx){

        cout<<"\n========================================================\n";
        cout<<"                LOG AKTIVITAS ADMIN\n";
        cout<<"========================================================\n";
        cout<<"Admin        : Admin Mall"<<endl;
        cout<<"Aksi         : Edit Vendor"<<endl;
        cout<<"ID Vendor    : "<<idVendor[idx]<<endl;
        cout<<"Status       : Berhasil"<<endl;
        cout<<"Tanggal      : 05 Juli 2026"<<endl;
        cout<<"========================================================\n";

    }

    void menuEditData(int idx){

        int pilih;

        do{

            cout<<"\n========================================================\n";
            cout<<"                  MENU EDIT VENDOR\n";
            cout<<"========================================================\n";
            cout<<"1. Edit Nama Toko\n";
            cout<<"2. Edit Nama Pemilik\n";
            cout<<"3. Edit Kategori\n";
            cout<<"4. Edit Email\n";
            cout<<"5. Edit Nomor HP\n";
            cout<<"6. Edit Status Vendor\n";
            cout<<"7. Edit Semua Data\n";
            cout<<"0. Batal\n";
            cout<<"========================================================\n";

            cout<<"Pilih Menu : ";
            cin>>pilih;
            cin.ignore(1000,'\n');

            string inputBaru;

            switch(pilih){

            case 1:
                simpanDataLama(idx);
                cout<<"Masukkan Nama Toko baru : ";
                getline(cin,inputBaru);
                namaToko[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitas(idx);
                tampilSemuaVendor();
                break;

            case 2:
                simpanDataLama(idx);
                cout<<"Masukkan Nama Pemilik baru : ";
                getline(cin,inputBaru);
                pemilik[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitas(idx);
                tampilSemuaVendor();
                break;

            case 3:
                simpanDataLama(idx);
                cout<<"Masukkan Kategori baru : ";
                getline(cin,inputBaru);
                kategori[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitas(idx);
                tampilSemuaVendor();
                break;

            case 4:
                simpanDataLama(idx);
                cout<<"Masukkan Email baru : ";
                getline(cin,inputBaru);
                email[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitas(idx);
                tampilSemuaVendor();
                break;

            case 5:
                simpanDataLama(idx);
                cout<<"Masukkan Nomor HP baru : ";
                getline(cin,inputBaru);
                noHp[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitas(idx);
                tampilSemuaVendor();
                break;

            case 6:
                simpanDataLama(idx);
                cout<<"Masukkan Status baru (Aktif/Nonaktif) : ";
                getline(cin,inputBaru);
                status[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitas(idx);
                tampilSemuaVendor();
                break;

            case 7:
                simpanDataLama(idx);

                cout<<"Masukkan Nama Toko baru    : ";
                getline(cin,inputBaru);
                namaToko[idx]=inputBaru;

                cout<<"Masukkan Nama Pemilik baru : ";
                getline(cin,inputBaru);
                pemilik[idx]=inputBaru;

                cout<<"Masukkan Kategori baru     : ";
                getline(cin,inputBaru);
                kategori[idx]=inputBaru;

                cout<<"Masukkan Email baru        : ";
                getline(cin,inputBaru);
                email[idx]=inputBaru;

                cout<<"Masukkan Nomor HP baru     : ";
                getline(cin,inputBaru);
                noHp[idx]=inputBaru;

                cout<<"Masukkan Status baru       : ";
                getline(cin,inputBaru);
                status[idx]=inputBaru;

                tampilHasilPerubahan(idx);
                tampilLogAktivitas(idx);
                tampilSemuaVendor();
                break;

            case 0:
                cout<<"\nEdit dibatalkan.\n";
                break;

            default:
                cout<<"\nPilihan tidak tersedia!\n";

            }

        }while(pilih!=0 && pilih!=1 && pilih!=2 && pilih!=3 && pilih!=4 && pilih!=5 && pilih!=6 && pilih!=7);

    }

    void menu(){

        string inputId;
        int idx;

        do{

            tampilSemuaVendor();

            cout<<"\nMasukkan ID Vendor yang akan diedit (0 untuk keluar) : ";
            cin>>inputId;

            if(inputId=="0"){

                cout<<"\nKeluar dari Edit Vendor...\n";
                break;

            }

            idx=cariVendor(inputId);

            if(idx==-1){

                cout<<"\nID Vendor tidak ditemukan!\n";

            }else{

                tampilDetailVendor(idx);
                menuEditData(idx);

            }

        }while(true);

    }

};

int main(){

    EditVendor admin;

    admin.menu();

    return 0;

}