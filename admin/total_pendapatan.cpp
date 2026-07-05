#include <iostream>
#include <iomanip>

using namespace std;

class PendapatanMall{

private:

    string bulan[12]={
        "Januari","Februari","Maret","April",
        "Mei","Juni","Juli","Agustus",
        "September","Oktober","November","Desember"
    };

    int transaksi[12]={
        1250,1380,1525,1460,
        1700,1850,1940,1810,
        1680,1750,2100,2500
    };

    long pendapatan[12]={
        25000000,27000000,30000000,28000000,
        32000000,35000000,36000000,34000000,
        31000000,33000000,38000000,42000000
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

int main(){

    PendapatanMall admin;

    admin.menu();

    return 0;

}