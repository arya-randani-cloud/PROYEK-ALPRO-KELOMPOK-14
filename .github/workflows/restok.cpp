#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Produk {
public:
    int id;
    string nama;
    string kategori;
    double harga;
    int stok;

    Produk(int i, string n, string k, double h, int s) {
        id = i;
        nama = n;
        kategori = k;
        harga = h;
        stok = s;
    }
};

class RestockBarang {
private:
    vector<Produk> katalog;

public:

    // Constructor
    RestockBarang() {
        katalog.push_back(Produk(101, "Beras", "Sembako", 12000, 20));
        katalog.push_back(Produk(102, "Gula", "Sembako", 14000, 15));
        katalog.push_back(Produk(103, "Minyak", "Sembako", 18000, 18));
        katalog.push_back(Produk(104, "Buku", "Sekolah", 5000, 30));
        katalog.push_back(Produk(105, "Pulpen", "Sekolah", 3000, 50));
    }

    void tampilBarang() {

        cout << "\n==============================================================\n";
        cout << "                     DAFTAR STOK BARANG\n";
        cout << "==============================================================\n";

        cout << left
             << setw(6) << "ID"
             << setw(20) << "Nama"
             << setw(18) << "Kategori"
             << setw(12) << "Harga"
             << setw(8) << "Stok" << endl;

        cout << "--------------------------------------------------------------\n";

        for (int i = 0; i < katalog.size(); i++) {

            cout << left
                 << setw(6) << katalog[i].id
                 << setw(20) << katalog[i].nama
                 << setw(18) << katalog[i].kategori
                 << setw(12) << katalog[i].harga
                 << setw(8) << katalog[i].stok
                 << endl;
        }
    }

    void restock() {

        int idCari;
        int jumlah;
        bool ditemukan = false;

        tampilBarang();

        cout << "\nMasukkan ID Barang yang ingin direstock : ";
        cin >> idCari;

        for (int i = 0; i < katalog.size(); i++) {

            if (katalog[i].id == idCari) {

                ditemukan = true;

                cout << "\nNama Barang  : " << katalog[i].nama << endl;
                cout << "Stok Lama    : " << katalog[i].stok << endl;

                cout << "Jumlah Restock : ";
                cin >> jumlah;

                if (jumlah <= 0) {
                    cout << "\nJumlah restock harus lebih dari 0!\n";
                } else {

                    katalog[i].stok += jumlah;

                    cout << "\n=========== RESTOCK BERHASIL ===========\n";
                    cout << "ID Barang      : " << katalog[i].id << endl;
                    cout << "Nama Barang    : " << katalog[i].nama << endl;
                    cout << "Stok Lama      : " << katalog[i].stok - jumlah << endl;
                    cout << "Restock        : +" << jumlah << endl;
                    cout << "Stok Sekarang  : " << katalog[i].stok << endl;
                    cout << "========================================\n";
                }

                break;
            }
        }

        if (!ditemukan) {
            cout << "\nID Barang tidak ditemukan!\n";
        }
    }

    void menu() {

        int pilih;

        do {

            cout << "\n===================================\n";
            cout << "       MENU RESTOCK BARANG\n";
            cout << "===================================\n";
            cout << "1. Lihat Daftar Barang\n";
            cout << "2. Restock Barang\n";
            cout << "0. Keluar\n";
            cout << "===================================\n";
            cout << "Pilih Menu : ";
            cin >> pilih;

            switch (pilih) {

            case 1:
                tampilBarang();
                break;

            case 2:
                restock();
                break;

            case 0:
                cout << "\nTerima kasih...\n";
                break;

            default:
                cout << "\nMenu tidak tersedia!\n";
            }

        } while (pilih != 0);
    }
};

int main() {

    RestockBarang toko;

    toko.menu();

    return 0;
}
