# PROYEK-ALPRO-KELOMPOK-14

 PEMBAGIAN TUGAS : 
          
          Menu Awal 
          1.Pelanggan/User : L.M Arya
          2.Toko/Vendor    : Muh Yazid
          3.Admin Mall     : Haidan Hammam 
    
1. Akun Pelanggan (Database User)
Terdapat 2 akun pelanggan yang diinisialisasi secara manual pada baris daftarUser[2]:

Akun 1

Username: arya123

Password: jogja2026

Nama Pemilik: Arya Randani

Saldo Awal: Rp5.000.000

Akun 2

Username: user2

Password: pass2

Nama Pemilik: Budi Santoso

Saldo Awal: Rp100.000

2. Akun Admin (Otorisasi Fitur Audit)
Untuk mengakses Menu 5 (Menu Admin / Audit Keuangan), sistem tidak meminta username melainkan Kunci Keamanan yang diinisialisasi pada baris adminUtama:

ID Admin: ADM01

# 🛒 Sistem Manajemen E-Commerce & Multi-Vendor

Repositori ini berisi implementasi sistem e-commerce multi-vendor berbasis modular. Sistem ini dirancang untuk memisahkan hak akses dan alur kerja antara **Pelanggan (Customer)**, **Pemilik Toko (Vendor/Admin Toko)**, dan **Pengelola Pusat (Super Admin/Admin Mall)**.

---

## 🔐 Kredensial Akun & Hak Akses (Demo)

Untuk keperluan pengujian dan demonstrasi fitur, berikut adalah modul dan tampilan yang akan muncul berdasarkan akun yang digunakan saat login.

> 🔑 **Kunci Keamanan Sistem (Password Utama):** `CERAN2026`

| Peran (Role) | Username | Password | Tampilan / Modul yang Muncul |
| :--- | :--- | :--- | :--- |
| **Pelanggan** | `arya123`<br>`user2` | `jogja2026`<br>`pass2` | Halaman utama belanja pelanggan (`modPelanggan`) & Fitur sistem pemesanan cepat (`modPemesanan`). |
| **Admin Mall** | `admin01` | `ceran2026admin` | Langsung diarahkan ke Dashboard Utama Admin Mall (`modVendor::menuAdminMall`). |
| **Toko (Vendor)** | `tokoadmin`<br>`toko01` | `admin123`<br>`toko2026` | Menu registrasi toko baru (`modAddAdmin`) & Dashboard pengelolaan toko lengkap (`modAdminFinal`). |

---

## 🛠️ Arsitektur Modul

Proyek ini dibangun menggunakan pendekatan modular untuk memastikan kode tetap bersih dan mudah dikembangkan:

*   **`modPelanggan`**: Menangani antarmuka pengguna, katalog produk, dan pengalaman belanja pelanggan.
*   **`modPemesanan`**: Mengelola sistem *fast-checkout* dan pemrosesan pesanan secara instan.
*   **`modVendor`**: Modul inti untuk manajemen multi-vendor, termasuk fungsi khusus `menuAdminMall` untuk pengelola pusat.
*   **`modAddAdmin`**: Alur khusus untuk pendaftaran toko baru dan verifikasi data vendor.
*   **`modAdminFinal`**: Dashboard komprehensif bagi pemilik toko untuk memantau produk, stok, dan laporan penjualan.

---

## 🚀 Cara Memulai

1. Clone repositori ini:
   ```bash
   git clone [https://github.com/username/repository-name.git](https://github.com/username/repository-name.git)
