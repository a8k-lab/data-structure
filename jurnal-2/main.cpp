#include <iostream>

using namespace std;
typedef float arrFloat[100];

float hitungKekuatan(int fisik, int sihir, int pertahanan) {
    return (2 * fisik) + (3 * sihir) - (0.5 * pertahanan);
}

int main() {
    int totalPetualang, i;
    int inputFisik, inputSihir, inputPertahanan;
    arrFloat arrPetualang;

    cin >> totalPetualang;
    for (i = 0; i < totalPetualang; i++) {
        cin >> inputFisik;
        cin >> inputSihir;
        cin >> inputPertahanan;
        arrPetualang[i] = hitungKekuatan(
            inputFisik, inputSihir, inputPertahanan
        );
    }
    for (i = 0; i < totalPetualang; i++) {
        cout 
            << "Total kekuatan petualang " 
            << i+1 
            << ": " 
            << arrPetualang[i] 
            << endl;
    }
    return 0;
}