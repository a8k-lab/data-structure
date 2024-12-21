#include "flight.h"

int main() {
  listJadwal L;
  infotype P;
  adrJadwalP elmJadwal;
  int n;

  createListJadwal_103042310065(L);

  // minta inputan jadwal Penerbangan sebanyak n kali
  cout << "Inputkan banyaknya jadwal penerbangan: ";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    // insert jadwal penerbangan
    cout << "====== Input jadwal penerbangan ke-" << i << " ======" << endl;
    cout << "Masukkan kode jalan penerbangan: ";
    cin >> P.kode;
    cout << "Masukkan jenis jalan penerbangan: ";
    cin >> P.jenis;
    cout << "Masukkan tanggal penerbangan: ";
    cin >> P.tanggal;
    cout << "Masukkan waktu penerbangan: ";
    cin >> P.waktu;
    cout << "Masukkan asal penerbangan: ";
    cin >> P.asal;
    cout << "Masukkan tujuan penerbangan: ";
    cin >> P.tujuan;
    cout << "Masukkan kapasitas penerbangan: ";
    cin >> P.kapasitas;
    elmJadwal = createElemenJadwal_103042310065(P);
    insertLastJ_103042310065(L, elmJadwal);
  }
  
  cout << "\n====== List Jadwal Penerbangan setelah diinput ======" << endl;
  showJadwal_103042310065(L);

  // delete Jadwal penerbangan
  deleteFirstJ_103042310065(L, elmJadwal);

  cout << "\n====== List Jadwal Penerbangan setelah dihapus yang pertama ======" << endl;
  showJadwal_103042310065(L);

  // Cari jadwal penerbangan dari surabaya ke malang tanggal 9 Desember 2022
  adrJadwalP searchP = searchJ_103042310065(L, "Surabaya", "Malang", "9-Desember-2022");
  if (searchP != nil) {
    cout << "Jadwal penerbangan ditemukan." << endl;
  } else {
    cout << "Jadwal penerbangan tidak ditemukan." << endl;
  }
  return 0;
}
