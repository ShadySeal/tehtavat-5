#include <iostream>
#include <iomanip>
using namespace std;

class Viisari {
private:
    int arvo;
    Viisari* seuraaja;

public:
    Viisari(int alkuarvo, Viisari* seuraava = nullptr) : arvo(alkuarvo), seuraaja(seuraava) {}

    void etene() {
        arvo = (arvo + 1) % 60;
        if (arvo == 0 && seuraaja != nullptr) {
            seuraaja->etene();
        }
    }

    int Arvo() const {
        return arvo;
    }

    void Seuraaja(Viisari* seuraava) {
        seuraaja = seuraava;
    }

    void nayta() const {
        cout << setw(2) << setfill('0') << arvo;
    }
};

int main() {
    Viisari sekunnit(45);
    Viisari minuutit(50, &sekunnit);
    Viisari tunnit(12, &minuutit);

    sekunnit.Seuraaja(&minuutit);
    minuutit.Seuraaja(&tunnit);

    for (int i = 0; i < 1000; ++i) {
        tunnit.nayta();
        cout << ":";
        minuutit.nayta();
        cout << ":";
        sekunnit.nayta();
        cout << "\n";

        sekunnit.etene();
    }

    return 0;
}
