#include <iostream>
#include "Province.h"

using namespace std;

int main()
{
    // a.
    Provinsi sumBar, jaBar, jambi, yogakarta;
    buatProvinsi(&sumBar);
    buatProvinsi(&jaBar);
    buatProvinsi(&jambi);
    buatProvinsi(&yogakarta);

    // b.
    // Jawa Barat
    tambahDaerah(&jaBar, true);
    tambahDaerah(&jaBar, false);
    tambahDaerah(&jaBar, true);
    tambahDaerah(&jaBar, false);
    // Jambi
    tambahDaerah(&jambi, true);
    tambahDaerah(&jambi, false);
    // Sumatera Barat
    tambahDaerah(&sumBar, true);
    tambahDaerah(&sumBar, false);
    tambahDaerah(&sumBar, false);
    tambahDaerah(&sumBar, false);
    tambahDaerah(&sumBar, true);
    // Yogakarta
    tambahDaerah(&yogakarta, false);
    tambahDaerah(&yogakarta, false);
    tambahDaerah(&yogakarta, false);

    // c.
    // Apakah Bandung adalah salah satu kota di Jambi?
    cout << "Apakah Bandung adalah salah satu kota di Jambi? ";
    cout << terdaftar(jambi, "Bandung", true) << endl;
    // Apakah Bandung adalah salah satu kabupaten di Jawa Barat?
    cout << "Apakah Bandung adalah salah satu kabupaten di Jawa Barat? ";
    cout << terdaftar(jaBar, "Bandung", false) << endl;
    // Apakah Bandung adalah salah satu kota di Yogakarta?
    cout << "Apakah Bandung adalah salah satu kota di Yogakarta? ";
    cout << terdaftar(yogakarta, "Bandung", true) << endl;
    // Apakah Bandung adalah salah satu kota di Jawa Barat?
    cout << "Apakah Bandung adalah salah satu kota di Jawa Barat? ";
    cout << terdaftar(jaBar, "Bandung", true) << endl;

    // d.
    tampilProvinsi(jaBar);
    cout << endl;
    tampilProvinsi(jambi);
    cout << endl;
    tampilProvinsi(sumBar);
    cout << endl;
    tampilProvinsi(yogakarta);

    return 0;
}
