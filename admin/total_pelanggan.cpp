#include <iostream>
using namespace std;1

class DashboardPelanggan {
private:
    int totalPelanggan;
    int pelangganAktif;
    int pelangganNonAktif;

public:
    // Constructor
    DashboardPelanggan() {
        totalPelanggan = 120;
        pelangganAktif = 110;
        pelangganNonAktif = 10;
    }

    void tampilDataPelanggan() {

        cout << "\n=========================================\n";
        cout << "      DASHBOARD TOTAL PELANGGAN\n";
        cout << "=========================================\n";
        cout << "Total Pelanggan      : " << totalPelanggan << endl;
        cout << "Pelanggan Aktif      : " << pelangganAktif << endl;
        cout << "Pelanggan Nonaktif   : " << pelangganNonAktif << endl;
        cout << "=========================================\n";

    }

    void menu() {

        int pilih;

        do {

            cout << "\n========== MENU PELANGGAN ==========\n";
            cout << "1. Lihat Total Pelanggan\n";
            cout << "0. Kembali\n";
            cout << "====================================\n";
            cout << "Pilih Menu : ";
            cin >> pilih;

            switch (pilih) {

            case 1:
                tampilDataPelanggan();
                break;

            case 0:
                cout << "\nKembali ke Dashboard Admin...\n";
                break;

            default :
                cout << "\nPilihan tidak tersedia!\n";
            }

        } while (pilih != 0);

    }

};

int main() {

    DashboardPelanggan pelanggan;

    pelanggan.menu();

    return 0;

}