#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Barang {
public:
    string nama;
    int harga;
    Barang(string n, int h) : nama(n), harga(h) {}
};

class SistemPemesanan {
private:
    vector<Barang> daftarPesanan;

public:
    void tambahPesanan(string nama, int harga) {
        daftarPesanan.push_back(Barang(nama, harga));
        cout << "--- [OK] " << nama << " ditambahkan ke keranjang ---\n" << endl;
    }

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
    int pilihanUtama, pilihanBarang;

    cout << "--- Selamat Datang di Toko Perabotan ---" << endl;

    do {
        cout << "Menu Utama:" << endl;
        cout << "1. Lihat List Peralatan Rumah Tangga" << endl;
        cout << "2. Lihat list peralatan mobil"<<endl;
        cout << "3. Lihat Keranjang & Total" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihanUtama;

        if (pilihanUtama == 1) {
            // Sub-menu List Barang
            cout << "\n--- Daftar Peralatan Rumah Tangga ---" << endl;
            cout << "1. Sapu (Rp25000)" << endl;
            cout << "2. Pel   (Rp45000)" << endl;
            cout << "3. Ember (Rp15000)" << endl;
            cout << "4. Kembali" << endl;
            cout << "Pilih barang yang ingin dipesan (1-4): ";
            cin >> pilihanBarang;

            if (pilihanBarang == 1) pesan.tambahPesanan("Sapu", 25000);
            else if (pilihanBarang == 2) pesan.tambahPesanan("Pel", 45000);
            else if (pilihanBarang == 3) pesan.tambahPesanan("Ember", 15000);
           
        } else if (pilihanUtama == 2) {
            
        }
        
         if (pilihanUtama == 2) {
            // Sub-menu List Barang
            cout << "\n--- Daftar Peralatan Rumah Tangga ---" << endl;
            cout << "1. Ban (Rp25000)" << endl;
            cout << "2. Knalpot   (Rp45000)" << endl;
            cout << "3. Spion (Rp15000)" << endl;
            cout << "4. Kembali" << endl;
            cout << "Pilih barang yang ingin dipesan (1-4): ";
            cin >> pilihanBarang;

            if (pilihanBarang == 1) pesan.tambahPesanan("Ban", 25000);
            else if (pilihanBarang == 2) pesan.tambahPesanan("knalpot", 45000);
            else if (pilihanBarang == 3) pesan.tambahPesanan("spion", 15000);
           
        } else if (pilihanUtama == 2) {
            pesan.tampilkanStruk();
        }
		
		
    } while (pilihanUtama != 11);

    cout << "Terima kasih!" << endl;
    return 0;
}


