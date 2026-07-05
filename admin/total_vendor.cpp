#include <iostream>
#include <iomanip>
using namespace std;

class Dashboard {
private:
    int totalVendor;
    int totalPelanggan;
    int totalProduk;
    int totalTransaksi;
    double totalPendapatan;

public:

    Dashboard() {
        totalVendor = 25;
        totalPelanggan = 350;
        totalProduk = 1280;
        totalTransaksi = 756;
        totalPendapatan = 152500000;
    }

    void tampilDashboard() {

        cout << "\n=============================================================\n";
        cout << "                 DASHBOARD ADMIN CERANMALL\n";
        cout << "=============================================================\n";

        cout << left << setw(30) << "Total Vendor"
             << ": " << totalVendor << endl;

        cout << left << setw(30) << "Total Pelanggan"
             << ": " << totalPelanggan << endl;

        cout << left << setw(30) << "Total Produk"
             << ": " << totalProduk << endl;

        cout << left << setw(30) << "Total Transaksi"
             << ": " << totalTransaksi << endl;

        cout << left << setw(30) << "Pendapatan Mall"
             << ": Rp " << fixed << setprecision(0)
             << totalPendapatan << endl;

        cout << "=============================================================\n";
    }

    void detailVendor() {

        cout << "\n========== INFORMASI VENDOR ==========\n";

        cout << "Vendor Aktif        : 22\n";
        cout << "Vendor Nonaktif     : 2\n";
        cout << "Vendor Baru         : 1\n";

        cout << "======================================\n";
    }

    void menuDashboard() {

        int pilih;

        do {

            cout << "\n============== DASHBOARD ==============\n";
            cout << "1. Lihat Ringkasan Dashboard\n";
            cout << "2. Detail Total Vendor\n";
            cout << "0. Kembali\n";
            cout << "=======================================\n";
            cout << "Pilih Menu : ";
            cin >> pilih;

            switch(pilih){

            case 1:
                tampilDashboard();
                break;

            case 2:
                detailVendor();
                break;

            case 0:
                cout << "\nKembali ke Menu Admin...\n";
                break;

            default:
                cout << "\nMenu tidak tersedia!\n";
            }

        } while(pilih != 0);

    }

};

int main() {

    Dashboard admin;

    admin.menuDashboard();

    return 0;
}