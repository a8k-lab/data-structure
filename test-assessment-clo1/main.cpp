#include <iostream>
#include "driver.h"

int main() {
    List drivers;
    infotype driver;
    address driverElm;

    createList(drivers);

    // 1. Menambah 4 data sekaligus (wajib menggunakan Looping)
    for (int i = 1; i <= 4; i++) {
        cout << "Masukkan nama driver ke-" << i << ": ";
        cin >> driver.name;
        cout << "Masukkan rating driver ke-" << i << ": ";
        cin >> driver.rating;
        driverElm = allocate(driver);
        insertLast(drivers, driverElm);
    }

    // 2. Menampilkan 4 data yang sudah masuk di dalam struktur data
    showList(drivers);

    // 3. Menghapus 1 data
    deleteLast(drivers, driverElm);

    // 4. Menampilkan data setelah proses penghapusan 1 data
    cout << "Setelah menghapus data terakhir" << endl;
    showList(drivers);

    // 5. Mengeluarkan data dari struktur data satu persatu. Setiap kali data di keluarkan, info data tersebut ditampilkan ke layar. Setelah itu Struktur Data menjadi empty, dan di layar tampil rata-rata rating. 
    cout << "Sebelum reset" << endl;
    resetList(drivers);
    cout << "Selesai reset" << endl;

    // 6. Menambah 4 data baru lagi secara sekaligus (wajib menggunakan Looping)
    for (int i = 1; i <= 4; i++) {
        cout << "Masukkan nama driver ke-" << i << ": ";
        cin >> driver.name;
        cout << "Masukkan rating driver ke-" << i << ": ";
        cin >> driver.rating;
        driverElm = allocate(driver);
        insertLast(drivers, driverElm);
    }

    // 7. Menampilkan 4 data yang sudah masuk di dalam struktur data
    showList(drivers);

    // 8. Meminta inputan nilai N dari user (N berada pada range nilai 0.00 s/d 5.00)
    float inputN;
    cout << "Masukkan nilai N: ";
    cin >> inputN;

    // 9. Melakukan split sesuai value N dari user
    List A, B;
    splitList(drivers, A, B, inputN);

    // 10. Tampilkan isi data pada masing-masing struktur data yang baru hasil dari proses split.
    showList(A);
    showList(B);

    return 0;
}
