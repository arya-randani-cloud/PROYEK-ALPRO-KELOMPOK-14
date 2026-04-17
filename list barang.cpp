#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class untuk merepresentasikan Barang
class Barang {
public:
    string nama;
    int harga;

    Barang(string n, int h) : nama(n), harga(h) {}
};

// Class untuk mengelola Sistem Pemesanan
class SistemPemesanan {
private:
    vector<Barang> daftarPesanan; // List untuk menyimpan pesanan

public:
    // Fungsi untuk menambah pesanan ke dalam list
    void tambahPesanan(string nama, int harga) {
        Barang barangBaru(nama, harga);
        daftarPesanan.push_back(barangBaru);
        cout << "Berhasil memesan: " << nama << endl;
    }

    // Fungsi untuk menampilkan semua list pesanan
    void tampilkanStruk() {
        cout << "\n========== DAFTAR PESANAN ANDA ==========" << endl;
        if (daftarPesanan.empty()) {
            cout << "Belum ada pesanan." << endl;
        } else {
            int total = 0;
            for (size_t i = 0; i < daftarPesanan.size(); i++) {
                cout << i + 1 << ". " << daftarPesanan[i].nama 
                     << " \t- Rp" << daftarPesanan[i].harga << endl;
                total += daftarPesanan[i].harga;
            }
            cout << "-----------------------------------------" << endl;
            cout << "Total Biaya: \tRp" << total << endl;
        }
        cout << "=========================================\n" << endl;
    }
};

int main() {
    SistemPemesanan pesan;
    int pilihan;
    string namaBarang;
    int hargaBarang;

    cout << "--- Selamat Datang di Program Pemesanan ---" << endl;

    do {
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Lihat Daftar Pesanan (Checkout)" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama barang: ";
                cin.ignore(); // Membersihkan buffer input
                getline(cin, namaBarang);
                cout << "Masukkan harga barang: ";
                cin >> hargaBarang;
                pesan.tambahPesanan(namaBarang, hargaBarang);
                break;
            case 2:
                pesan.tampilkanStruk();
                break;
            case 3:
                cout << "Terima kasih telah memesan!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 3);

    return 0;
}
