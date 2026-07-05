#include <iostream>
#include <iomanip>

using namespace std;

//====================================================================
// CLASS HAPUS VENDOR
//====================================================================
class HapusVendor{

private:

    string idVendor[10]={
        "V001","V002","V003","V004","V005","V006","V007","V008","V009","V010"
        
    };

    string namaToko[10]={
       "Toko Makmur", "Game Store", "Tech Store", "FashionKu", "Healthy Shop", "ATK Jaya", "Pet House", "Baby Mart", "Sport Center", "Otomotif Jaya"
    };

    string pemilik[10]={
        "Andi","Budi","Citra","Dewi","Eko","Farhan","Gilang","Hasan","Indra","Joko"
        
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

    int jumlahVendor;

public:

    // Constructor
    HapusVendor(){

        jumlahVendor=10;

    }

    void tampilSemuaVendor(){

        cout<<"\n========================================================\n";
        cout<<left
            <<setw(10)<<"ID"
            <<setw(24)<<"Nama Toko"
            <<"Pemilik"<<endl;
        cout<<"========================================================\n";

        for(int i=0;i<jumlahVendor;i++){

            cout<<left
                <<setw(10)<<idVendor[i]
                <<setw(24)<<namaToko[i]
                <<pemilik[i]<<endl;

        }

        cout<<"========================================================\n";

    }

    int cariVendor(string id){

        int indeks=-1;

        for(int i=0;i<jumlahVendor;i++){

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

    void tampilLogAktivitas(string idHapus,string namaHapus){

        cout<<"\n=====================================\n";
        cout<<"        LOG AKTIVITAS ADMIN\n";
        cout<<"=====================================\n";
        cout<<"Admin        : Admin Mall"<<endl;
        cout<<"Aksi         : Hapus Vendor"<<endl;
        cout<<"ID Vendor    : "<<idHapus<<endl;
        cout<<"Nama Vendor  : "<<namaHapus<<endl;
        cout<<"Status       : Berhasil"<<endl;
        cout<<"Tanggal      : 05 Juli 2026"<<endl;
        cout<<"=====================================\n";

    }

    void hapusVendor(int idx){

        // simpan data vendor yang akan dihapus untuk log aktivitas
        string idHapus=idVendor[idx];
        string namaHapus=namaToko[idx];

        // geser seluruh data array ke atas
        for(int i=idx;i<jumlahVendor-1;i++){

            idVendor[i]=idVendor[i+1];
            namaToko[i]=namaToko[i+1];
            pemilik[i]=pemilik[i+1];
            kategori[i]=kategori[i+1];
            email[i]=email[i+1];
            noHp[i]=noHp[i+1];
            status[i]=status[i+1];

        }

        // kurangi jumlah vendor sebanyak satu
        jumlahVendor=jumlahVendor-1;

        cout<<"\n=====================================\n";
        cout<<"    VENDOR BERHASIL DIHAPUS\n";
        cout<<"=====================================\n";

        tampilLogAktivitas(idHapus,namaHapus);

        cout<<"\nDAFTAR VENDOR TERBARU\n";
        tampilSemuaVendor();

    }

    void prosesHapus(int idx){

        int pilih;

        cout<<"\n=====================================\n";
        cout<<"Yakin ingin menghapus vendor ini?\n";
        cout<<"1. Ya\n";
        cout<<"2. Tidak\n";
        cout<<"=====================================\n";
        cout<<"Pilih Menu : ";
        cin>>pilih;

        switch(pilih){

        case 1:
            hapusVendor(idx);
            break;

        case 2:
            cout<<"\nPenghapusan dibatalkan.\n";
            break;

        default:
            cout<<"\nPilihan tidak tersedia, penghapusan dibatalkan.\n";

        }

    }

    void menu(){

        string inputId;
        int idx;

        do{

            tampilSemuaVendor();

            cout<<"\nMasukkan ID Vendor yang akan dihapus (0 untuk keluar) : ";
            cin>>inputId;

            if(inputId=="0"){

                cout<<"\nKeluar dari Hapus Vendor...\n";
                break;

            }

            idx=cariVendor(inputId);

            if(idx==-1){

                cout<<"\nID Vendor tidak ditemukan!\n";

            }else{

                tampilDetailVendor(idx);
                prosesHapus(idx);

            }

        }while(jumlahVendor>0);

        if(jumlahVendor==0){

            cout<<"\nSemua vendor sudah dihapus.\n";

        }

    }

};

int main(){

    HapusVendor admin;

    admin.menu();

    return 0;

}
