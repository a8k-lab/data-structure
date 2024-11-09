#include <iostream>

using namespace std;

int main() {
    int totalGenap = 0, genapTerbesar, bilangan;

    cin >> bilangan;
    while (bilangan != 0) {
        if (bilangan % 2 == 0) {
            if (totalGenap > 0) {
                if (bilangan > genapTerbesar) {
                    genapTerbesar = bilangan;
                }
            } else {
                genapTerbesar = bilangan;
            }
            totalGenap++;
        }
        cin >> bilangan;
    }

    cout << totalGenap << " " << genapTerbesar << endl;
    return 0;
}