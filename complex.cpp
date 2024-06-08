#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Complex { // Form of a +jb
    T a {}, b {}, r {}, ang {};
    public:
        enum Form_ {arith, polar, euler};
        T& real = a, & imag = b;

        explicit Complex(T real=0, T imag=0) {
            a = real, b = imag;
            r = sqrt(pow(a, 2) + pow(b, 2));
            ang = atan2(b, a);

        }

        void show(const Form_ type=arith) {
            switch (type) {
                case polar:
                    cout << r << "(cos(" << ang << ") + j sin(" << ang << "))" << endl;
                    break;
                case euler:
                    cout << r << " e ^ (i " << ang << ")" << endl;
                    break;
                default:
                    cout << "(" << a << " + j" << b << ")" << endl;
            }
        }

        void setBySum(const Complex c1, const Complex c2) {
            a = c1.real + c2.real;
            b = c1.imag + c2.imag;
            r = sqrt(pow(a, 2) + pow(b, 2));
            ang = atan2(b, a);
        }
};

int main() {
    auto c1 = Complex<float>(1, 3);
    cout << "Real: " << c1.real << " Imag: " << c1.imag << endl;
    c1.show();
    c1.show(Complex<float> :: polar);
    c1.show(Complex<float> :: euler);
    auto const c2 = Complex<float>(2, 4);
    auto c3 = Complex<float>();
    c3.setBySum(c1, c2);
    c3.show();

    return 0;
}
