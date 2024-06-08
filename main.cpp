#include <iostream>

using namespace std;

int count {};

class Num {
    public:
        Num() {
            cout << "Object created! Net: " << ++count << endl;
        }

        ~Num() {
            cout << "Object destroyed! Rem: " << --count << endl;
        }
};

int main() {
    Num a, b;
    {
        cout << "Scope changed!" << endl;
        Num c, d;
    }
    cout << "Scope resetted!" << endl;

    return 0;
    // exit(0);
}
