#include <iostream>
#include <iomanip>
using namespace std;

class Viisari {
private:
    int arvo;

public:
    Viisari(int alkuarvo) : arvo(alkuarvo) {}

    void etene() {
        arvo = (arvo + 1) % 60;
    }

    int Arvo() const {
        return arvo;
    }

    void nayta() const {
        cout << setw(2) << setfill('0') << arvo;
    }
};

class Kello {
private:
    Viisari* tunnit;
    Viisari* minuutit;
    Viisari* sekunnit;

public:
    Kello(int h, int m, int s) {
        tunnit = new Viisari(h);
        minuutit = new Viisari(m);
        sekunnit = new Viisari(s);
    }

    ~Kello() {
        delete tunnit;
        delete minuutit;
        delete sekunnit;
    }

    void nayta() const {
        tunnit->nayta();
        cout << ":";
        minuutit->nayta();
        cout << ":";
        sekunnit->nayta();
        cout << std::endl;
    }

    void kay() {
        sekunnit->etene();

        if (sekunnit->Arvo() == 0) {
            minuutit->etene();

            if (minuutit->Arvo() == 0) {
                tunnit->etene();
            }
        }
    }
};

int main() {
    Kello k(12, 50, 45);

    for (int i = 0; i < 1000; ++i) {
        k.nayta();
        cout << "\n";
        k.kay();
    }

    return 0;
}
