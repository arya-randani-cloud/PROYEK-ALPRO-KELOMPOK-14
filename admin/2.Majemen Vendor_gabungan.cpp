#include <iostream>
#include <iomanip>

using namespace std;
class ManajemenVendor{

                private:
                
                    string idVendor[100];
                    string namaToko[100];
                    string namaPemilik[100];
                    string kategori[100];
                    string email[100];
                    string noHP[100];
                    string status[100];
                    int jumlahProduk[100];
                    float rating[100];
                
                    int jumlahVendor;
                
                    // variabel sementara untuk menyimpan data lama sebelum diedit
                    string namaTokoLama;
                    string pemilikLama;
                    string kategoriLama;
                    string emailLama;
                    string hpLama;
                    string statusLama;
                
                public:
                    ManajemenVendor(){
                
                        jumlahVendor=10;
                
                        string idAwal[10]={
                            "V001","V002","V003","V004","V005", "V006","V007","V008","V009","V010"
                        };
                
                        string tokoAwal[10]={
                            "Toko Makmur", "Game Store", "Tech Store", "FashionKu", "Healthy Shop", "ATK Jaya", "Pet House", "Baby Mart", "Sport Center", "Otomotif Jaya"
                        };
                
                        string pemilikAwal[10]={
                            "Andi","Budi","Citra","Dewi","Eko","Farhan","Gilang","Hasan","Indra","Joko"
                        };
                
                        string kategoriAwal[10]={
                            "Sembako","Gaming","Elektronik","Fashion","Kesehatan", "Alat Tulis","Hewan","Bayi","Olahraga","Otomotif"
                        };
                
                        string emailAwal[10]={
                           "andi@gmail.com","budi@gmail.com","citra@gmail.com","dewi@gmail.com","eko@gmail.com","farhan@gmail.com","gilang@gmail.com","hasan@gmail.com","indra@gmail.com","joko@gmail.com"
                        };
                
                        string hpAwal[10]={
                            "081234567801","08123456789","081234567803","081234567804","081234567805","081234567806","081234567807","081234567808","081234567809","081234567810"
                        };
                
                        string statusAwal[10]={
                            "Aktif","Aktif","Nonaktif","Aktif","Nonaktif","Aktif","Aktif","Nonaktif","Aktif","Nonaktif"
                            
                        };
                
                        int produkAwal[10]={
                            35,28,40,25,18, 20,15,16,22,19
                           
                        };
                
                        float ratingAwal[10]={
                            4.9,4.8,4.7,4.8,4.6,4.5,4.3,4.4,4.2,4.6
                            
                        };
                
                        for(int i=0;i<10;i++){
                
                            idVendor[i]=idAwal[i];
                            namaToko[i]=tokoAwal[i];
                            namaPemilik[i]=pemilikAwal[i];
                            kategori[i]=kategoriAwal[i];
                            email[i]=emailAwal[i];
                            noHP[i]=hpAwal[i];
                            status[i]=statusAwal[i];
                            jumlahProduk[i]=produkAwal[i];
                            rating[i]=ratingAwal[i];
                
                        }
                         }
    // FUNGSI BANTU (dipakai bersama oleh beberapa fitur)
    // Cari indeks vendor berdasarkan ID, kembalikan -1 jika tidak ada
    int cariVendorByID(string id){

        int indeks=-1;

        for(int i=0;i<jumlahVendor;i++){

            if(idVendor[i]==id){

                indeks=i;

            }

        }

        return indeks;

    }

    // Tampilan ringkas 3 kolom (ID, Nama Toko, Pemilik)
    void tampilRingkasanVendor(){

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
                <<namaPemilik[i]<<endl;

        }

        cout<<"========================================================\n";

    }

    // Tampilan detail 7 field, dipakai oleh Edit Vendor dan Hapus Vendor
    void tampilInfoVendor(int idx){

        cout<<"\n========================================================\n";
        cout<<"                 DETAIL DATA VENDOR\n";
        cout<<"========================================================\n";
        cout<<"ID Vendor      : "<<idVendor[idx]<<endl;
        cout<<"Nama Toko      : "<<namaToko[idx]<<endl;
        cout<<"Nama Pemilik   : "<<namaPemilik[idx]<<endl;
        cout<<"Kategori       : "<<kategori[idx]<<endl;
        cout<<"Email          : "<<email[idx]<<endl;
        cout<<"Nomor HP       : "<<noHP[idx]<<endl;
        cout<<"Status         : "<<status[idx]<<endl;
        cout<<"========================================================\n";

    }

    //================================================================
    // FITUR 1 : LIHAT VENDOR
    //================================================================

    void semuaVendor(){

        cout<<"\n================ DAFTAR SEMUA VENDOR ================\n\n";

        cout<<left
        <<setw(8)<<"ID"
        <<setw(20)<<"Nama Toko"
        <<setw(15)<<"Pemilik"
        <<setw(18)<<"Kategori"
        <<setw(12)<<"Status"<<endl;

        cout<<"---------------------------------------------------------------"<<endl;

        for(int i=0;i<jumlahVendor;i++){

            cout<<left
            <<setw(8)<<idVendor[i]
            <<setw(20)<<namaToko[i]
            <<setw(15)<<namaPemilik[i]
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

        for(int i=0;i<jumlahVendor;i++){

            if(status[i]=="Aktif"){

                cout<<left
                <<setw(8)<<idVendor[i]
                <<setw(20)<<namaToko[i]
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

        for(int i=0;i<jumlahVendor;i++){

            if(status[i]=="Nonaktif"){

                cout<<left
                <<setw(8)<<idVendor[i]
                <<setw(20)<<namaToko[i]
                <<setw(15)<<kategori[i]<<endl;

            }

        }

    }

    void detailVendor(){

        string cari;

        cout<<"\nMasukkan ID Vendor : ";
        cin>>cari;

        int idx=cariVendorByID(cari);

        if(idx!=-1){

            cout<<"\n=============== DETAIL VENDOR ===============\n";
            cout<<"ID Vendor        : "<<idVendor[idx]<<endl;
            cout<<"Nama Toko        : "<<namaToko[idx]<<endl;
            cout<<"Nama Pemilik     : "<<namaPemilik[idx]<<endl;
            cout<<"Kategori         : "<<kategori[idx]<<endl;
            cout<<"Status           : "<<status[idx]<<endl;
            cout<<"Jumlah Produk    : "<<jumlahProduk[idx]<<endl;
            cout<<"Rating           : "<<rating[idx]<<endl;

        }else{

            cout<<"\nVendor tidak ditemukan.\n";

        }

    }

    void menuLihatVendor(){

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

    //================================================================
    // FITUR 2 : TAMBAH VENDOR
    //================================================================

    void tambahVendor(){

        if(jumlahVendor>=100){

            cout<<"\nData vendor sudah penuh, tidak bisa menambah lagi.\n";
            return;

        }

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
        jumlahProduk[jumlahVendor]=0;
        rating[jumlahVendor]=0.0;

        jumlahVendor++;

        cout<<"\n=====================================\n";
        cout<<"Vendor berhasil ditambahkan.\n";
        cout<<"Status Vendor : Aktif\n";
        cout<<"Total Vendor : "<<jumlahVendor<<endl;
        cout<<"=====================================\n";

        semuaVendor();

    }

    //================================================================
    // FITUR 3 : CARI VENDOR
    //================================================================

    void cariID(){

        string cari;

        cout<<"\nMasukkan ID Vendor : ";
        cin>>cari;

        int idx=cariVendorByID(cari);

        if(idx!=-1){

            cout<<"\n========== DATA VENDOR ==========\n";
            cout<<"ID Vendor      : "<<idVendor[idx]<<endl;
            cout<<"Nama Toko      : "<<namaToko[idx]<<endl;
            cout<<"Pemilik        : "<<namaPemilik[idx]<<endl;
            cout<<"Kategori       : "<<kategori[idx]<<endl;
            cout<<"Status         : "<<status[idx]<<endl;

        }else{

            cout<<"\nVendor tidak ditemukan.\n";

        }

    }

    void cariNamaToko(){

        string cari;
        bool ketemu=false;

        cin.ignore();

        cout<<"\nMasukkan Nama Toko : ";
        getline(cin,cari);

        for(int i=0;i<jumlahVendor;i++){

            if(cari==namaToko[i]){

                ketemu=true;

                cout<<"\n========== DATA VENDOR ==========\n";
                cout<<"ID Vendor      : "<<idVendor[i]<<endl;
                cout<<"Nama Toko      : "<<namaToko[i]<<endl;
                cout<<"Pemilik        : "<<namaPemilik[i]<<endl;
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

        for(int i=0;i<jumlahVendor;i++){

            if(cari==namaPemilik[i]){

                ketemu=true;

                cout<<"\n========== DATA VENDOR ==========\n";
                cout<<"ID Vendor      : "<<idVendor[i]<<endl;
                cout<<"Nama Toko      : "<<namaToko[i]<<endl;
                cout<<"Pemilik        : "<<namaPemilik[i]<<endl;
                cout<<"Kategori       : "<<kategori[i]<<endl;
                cout<<"Status         : "<<status[i]<<endl;

            }

        }

        if(!ketemu){

            cout<<"\nVendor tidak ditemukan.\n";

        }

    }

    void menuCariVendor(){

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

    //================================================================
    // FITUR 4 : EDIT VENDOR
    //================================================================

    void simpanDataLama(int idx){

        namaTokoLama=namaToko[idx];
        pemilikLama=namaPemilik[idx];
        kategoriLama=kategori[idx];
        emailLama=email[idx];
        hpLama=noHP[idx];
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
        cout<<left<<setw(15)<<"Pemilik"<<setw(20)<<pemilikLama<<namaPemilik[idx]<<endl;
        cout<<left<<setw(15)<<"Kategori"<<setw(20)<<kategoriLama<<kategori[idx]<<endl;
        cout<<left<<setw(15)<<"Email"<<setw(20)<<emailLama<<email[idx]<<endl;
        cout<<left<<setw(15)<<"Nomor HP"<<setw(20)<<hpLama<<noHP[idx]<<endl;
        cout<<left<<setw(15)<<"Status"<<setw(20)<<statusLama<<status[idx]<<endl;

        cout<<"========================================================\n";

        cout<<"\nData Vendor berhasil diperbarui.\n";

    }

    void tampilLogAktivitasEdit(int idx){

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
                tampilLogAktivitasEdit(idx);
                tampilRingkasanVendor();
                break;

            case 2:
                simpanDataLama(idx);
                cout<<"Masukkan Nama Pemilik baru : ";
                getline(cin,inputBaru);
                namaPemilik[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitasEdit(idx);
                tampilRingkasanVendor();
                break;

            case 3:
                simpanDataLama(idx);
                cout<<"Masukkan Kategori baru : ";
                getline(cin,inputBaru);
                kategori[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitasEdit(idx);
                tampilRingkasanVendor();
                break;

            case 4:
                simpanDataLama(idx);
                cout<<"Masukkan Email baru : ";
                getline(cin,inputBaru);
                email[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitasEdit(idx);
                tampilRingkasanVendor();
                break;

            case 5:
                simpanDataLama(idx);
                cout<<"Masukkan Nomor HP baru : ";
                getline(cin,inputBaru);
                noHP[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitasEdit(idx);
                tampilRingkasanVendor();
                break;

            case 6:
                simpanDataLama(idx);
                cout<<"Masukkan Status baru (Aktif/Nonaktif) : ";
                getline(cin,inputBaru);
                status[idx]=inputBaru;
                tampilHasilPerubahan(idx);
                tampilLogAktivitasEdit(idx);
                tampilRingkasanVendor();
                break;

            case 7:
                simpanDataLama(idx);

                cout<<"Masukkan Nama Toko baru    : ";
                getline(cin,inputBaru);
                namaToko[idx]=inputBaru;

                cout<<"Masukkan Nama Pemilik baru : ";
                getline(cin,inputBaru);
                namaPemilik[idx]=inputBaru;

                cout<<"Masukkan Kategori baru     : ";
                getline(cin,inputBaru);
                kategori[idx]=inputBaru;

                cout<<"Masukkan Email baru        : ";
                getline(cin,inputBaru);
                email[idx]=inputBaru;

                cout<<"Masukkan Nomor HP baru     : ";
                getline(cin,inputBaru);
                noHP[idx]=inputBaru;

                cout<<"Masukkan Status baru       : ";
                getline(cin,inputBaru);
                status[idx]=inputBaru;

                tampilHasilPerubahan(idx);
                tampilLogAktivitasEdit(idx);
                tampilRingkasanVendor();
                break;

            case 0:
                cout<<"\nEdit dibatalkan.\n";
                break;

            default:
                cout<<"\nPilihan tidak tersedia!\n";

            }

        }while(pilih!=0 && pilih!=1 && pilih!=2 && pilih!=3 && pilih!=4 && pilih!=5 && pilih!=6 && pilih!=7);

    }

    void menuEditVendor(){

        string inputId;
        int idx;

        do{

            tampilRingkasanVendor();

            cout<<"\nMasukkan ID Vendor yang akan diedit (0 untuk keluar) : ";
            cin>>inputId;

            if(inputId=="0"){

                cout<<"\nKeluar dari Edit Vendor...\n";
                break;

            }

            idx=cariVendorByID(inputId);

            if(idx==-1){

                cout<<"\nID Vendor tidak ditemukan!\n";

            }else{

                tampilInfoVendor(idx);
                menuEditData(idx);

            }

        }while(true);

    }

    //================================================================
    // FITUR 5 : HAPUS VENDOR
    //================================================================

    void tampilLogAktivitasHapus(string idHapus,string namaHapus){

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
            namaPemilik[i]=namaPemilik[i+1];
            kategori[i]=kategori[i+1];
            email[i]=email[i+1];
            noHP[i]=noHP[i+1];
            status[i]=status[i+1];
            jumlahProduk[i]=jumlahProduk[i+1];
            rating[i]=rating[i+1];

        }

        // kurangi jumlah vendor sebanyak satu
        jumlahVendor=jumlahVendor-1;

        cout<<"\n=====================================\n";
        cout<<"    VENDOR BERHASIL DIHAPUS\n";
        cout<<"=====================================\n";

        tampilLogAktivitasHapus(idHapus,namaHapus);

        cout<<"\nDAFTAR VENDOR TERBARU\n";
        tampilRingkasanVendor();

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

    void menuHapusVendor(){

        string inputId;
        int idx;

        do{

            tampilRingkasanVendor();

            cout<<"\nMasukkan ID Vendor yang akan dihapus (0 untuk keluar) : ";
            cin>>inputId;

            if(inputId=="0"){

                cout<<"\nKeluar dari Hapus Vendor...\n";
                break;

            }

            idx=cariVendorByID(inputId);

            if(idx==-1){

                cout<<"\nID Vendor tidak ditemukan!\n";

            }else{

                tampilInfoVendor(idx);
                prosesHapus(idx);

            }

        }while(jumlahVendor>0);

        if(jumlahVendor==0){

            cout<<"\nSemua vendor sudah dihapus.\n";

        }

    }

    //================================================================
    // MENU UTAMA MANAJEMEN VENDOR
    //================================================================

    void menu(){

        int pilih;

        do{

            cout<<"\n=====================================\n";
            cout<<"         MENU MANAJEMEN VENDOR\n";
            cout<<"=====================================\n";
            cout<<"1. Lihat Vendor\n";
            cout<<"2. Tambah Vendor\n";
            cout<<"3. Cari Vendor\n";
            cout<<"4. Edit Vendor\n";
            cout<<"5. Hapus Vendor\n";
            cout<<"0. Kembali\n";
            cout<<"=====================================\n";

            cout<<"Pilih Menu : ";
            cin>>pilih;

            switch(pilih){

            case 1:
                menuLihatVendor();
                break;

            case 2:
                tambahVendor();
                break;

            case 3:
                menuCariVendor();
                break;

            case 4:
                menuEditVendor();
                break;

            case 5:
                menuHapusVendor();
                break;

            case 0:
                cout<<"\nKembali ke Menu Admin Mall...\n";
                break;

            default:
                cout<<"\nMenu tidak tersedia.\n";

            }

        }while(pilih!=0);

    }

};

int main(){

    ManajemenVendor admin;

    admin.menu();

    return 0;

}
