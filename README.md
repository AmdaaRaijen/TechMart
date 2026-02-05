# TechMart Inventory Management System 🚀

**Ujian Akhir Semester (UAS) - Algoritma dan Pemrograman (IF107)**

Program ini adalah sistem manajemen inventaris berbasis _Command Line Interface_ (CLI) yang dirancang untuk toko elektronik **TechMart**. Program dibangun menggunakan bahasa C++ dengan menerapkan konsep Object-Oriented Programming (OOP), struktur data Array, Pointer, dan algoritma Rekursif.

---

## 👤 Identitas Mahasiswa

- **Nama** : Bintang Triadmaja
- **NIM** : 250401010075
- **Kelas** : IF107
- **Program Studi** : PJJ Informatika S1
- **Universitas** : Universitas Siber Asia

---

## 🛠️ Fitur Utama

Sistem ini mencakup fungsi-fungsi krusial untuk manajemen gudang:

1.  **Manajemen Data**: Tambah, Edit, dan Hapus produk elektronik.
2.  **Pencarian Efisien**: Mencari produk menggunakan kode unik berbasis _Pointer_.
3.  **Laporan Keuangan**: Menghitung total nilai aset gudang menggunakan _Fungsi Rekursif_.
4.  **Analisis Stok**: Menampilkan produk dengan stok kritis (< 5 unit).
5.  **Pengurutan (Sorting)**: Mengurutkan daftar produk berdasarkan jumlah stok (Ascending).

---

## 💻 Spesifikasi Teknis & Implementasi

Program ini memenuhi poin-poin penilaian teknis sebagai berikut:

### 1. Struktur Data & OOP

- **Struct `Product`**: Digunakan untuk representasi entitas data produk.
- **Class `Inventory`**: Mengimplementasikan _Encapsulation_ (data private, method public) untuk manajemen data.
- **Array Statis**: Menyimpan data hingga 50 produk tanpa menggunakan library STL (`std::vector`).

### 2. Pointer & Memori

- Akses data dalam array dilakukan melalui aritmatika pointer.
- Pencarian produk mengembalikan alamat memori (`Product*`) untuk efisiensi.

### 3. Fungsi Rekursif

Implementasi penghitungan total nilai inventaris (Harga × Stok) menggunakan rumus:
$$totalNilai(n) = (harga[n] \times stok[n]) + totalNilai(n-1)$$

### 4. Manipulasi String

- Validasi input nama produk agar tidak kosong.
- Konversi otomatis input kode produk menjadi _Uppercase_.
- Pencarian berbasis kode yang sensitif terhadap format teks.

---

## 🚀 Cara Menjalankan Program

1.  Pastikan Anda memiliki compiler C++ (seperti G++ atau MinGW).
2.  Simpan file kode sumber sebagai `main.cpp`.
3.  Buka terminal/CMD, lalu kompilasi program:
    ```bash
     g++ src/main.cpp -o build/TechMart
    ```
4.  Jalankan program:
    ```bash
    ./TechMart
    ```

---

## 📝 Catatan Tambahan

- Program ini telah diuji untuk memastikan tidak ada _memory leak_.
- Input harga dan stok telah dilengkapi dengan _input validation_ untuk mencegah error jika user memasukkan karakter non-numerik.

---

© 2026 Bintang Triadmaja - Universitas Siber Asia
