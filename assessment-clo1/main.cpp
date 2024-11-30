#include <iostream>

using namespace std;
#include "driver.h"

int main() {
    List drivers;
    infotype driver;
    address elmDriver;

    createList(drivers);
    // 1. Menambah 4 data sekaligus (wajib menggunakan Looping)
    for (int i = 1; i <= 4; i++) {
        cout << "Masukkan nama driver ke-" << i << ": ";
        cin >> driver.name;
        cout << "Masukkan rating driver ke-" << i << ": ";
        cin >> driver.rating;
        elmDriver = allocate(driver);
        insertLast(drivers, elmDriver);
    }

    // 2. Menampilkan 4 data yang sudah masuk di dalam struktur data
    showList(drivers);

    // 3. Menghapus 1 data
    deleteLast(drivers, elmDriver);

    // 4. Menampilkan data setelah proses penghapusan 1 data
    showList(drivers);

    // 5. Mengeluarkan data dari struktur data satu persatu. Setiap kali data di keluarkan, info data tersebut ditampilkan ke layar. Setelah itu Struktur Data menjadi empty, dan di layar tampil rata-rata rating.
    resetList(drivers);

    // 6. Menambah 4 data baru lagi secara sekaligus (wajib menggunakan Looping)
    for (int i = 1; i <= 4; i++) {
        cout << "Masukkan nama driver ke-" << i << ": ";
        cin >> driver.name;
        cout << "Masukkan rating driver ke-" << i << ": ";
        cin >> driver.rating;
        elmDriver = allocate(driver);
        insertLast(drivers, elmDriver);
    }

    // 7. Menampilkan 4 data yang sudah masuk di dalam struktur data
    showList(drivers);

    // 8. Meminta inputan nilai N dari user (N berada pada range nilai 0.00 s/d 5.00)
    float inputN;
    cout << "Masukkan nilai N: ";
    cin >> inputN;

    // 9. Melakukan split sesuai value N dari user
    List A, B;
    createList(A);
    createList(B);
    splitList(drivers, A, B, inputN);

    // 10. Tampilkan isi data pada masing-masing struktur data yang baru hasil dari proses split.
    cout << "List awal:" << endl;
    showList(drivers);

    cout << "List A(kurang dari N):" << endl;
    showList(A);

    cout << "List B (lebih dari N):" << endl;
    showList(B);

    return 0;
}
