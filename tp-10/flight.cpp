#include "flight.h"

void createListJadwal_103042310065(listJadwal &L) {
  first(L) = nil;
}

adrJadwalP createElemenJadwal_103042310065(infotype X) {
  adrJadwalP newElm = new elemenJadwal;
  info(newElm) = X;
  next(newElm) = nil;
  return newElm;
}

void insertLastJ_103042310065(listJadwal &L, adrJadwalP P) {
  if (first(L) == nil) {
    first(L) = P;
  } else {
    adrJadwalP current = first(L);
    while (next(current) != nil) {
      current = next(current);
    }
    next(current) = P;
  }
}

void showJadwal_103042310065(listJadwal L) {
  adrJadwalP current = first(L);
  cout << "List Jadwal Penerbangan:" << endl;
  while (current != nil) {
    cout << info(current).kode << " " << info(current).jenis << " "
        << info(current).tanggal << " " << info(current).waktu << " "
        << info(current).asal << " " << info(current).tujuan << " "
        << info(current).kapasitas << endl;
    current = next(current);
  }
}

void deleteFirstJ_103042310065(listJadwal &L, adrJadwalP &P) {
  if (first(L) == nil) {
    cout << "List kosong!" << endl;
    return;
  }
  if (next(first(L)) == nil) {
    P = first(L);
    first(L) = nil;
  } else {
    P = first(L);
    first(L) = next(P);
  }
}

adrJadwalP searchJ_103042310065(listJadwal L, string dari, string ke, string tanggal) {
  adrJadwalP current = first(L);
  while (current != nil) {
    if (info(current).asal == dari
      && info(current).tujuan == ke
      && info(current).tanggal == tanggal) {
      return current;
    }
    current = next(current);
  }
  return nil;
}
