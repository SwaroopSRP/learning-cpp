#include <iostream>
#include <cmath>

using namespace std;

class Coord {
    int x {}, y {}, z {};

    friend class CoordMath;

    public:
        Coord() {
            cout << "Values not provided, set to (0, 0, 0)!" << endl;
        }

        Coord(const int x, const int y) {
            this->x = x;
            this->y = y;
        }

        Coord(const int x, const int y, const int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Coord(const Coord& obj) {
            cout << "Copy-constructor called!" << endl;
            this->x = obj.x;
            this->y = obj.y;
        }

        void show() const {
            cout << "(" << x << ", " << y << ", " << z << ")" << endl;
        }
};

class CoordMath {
    public:
        static double dist(const Coord& pt_1, const Coord& pt_2) {
            return sqrt(pow(pt_1.x - pt_2.x, 2) + pow(pt_1.y - pt_2.y, 2));
        }
};

// int main() {
//     const Coord p(1, 1), q(3, 3), r(-1, 5, 3), s;
//     p.show();
//     q.show();
//     r.show();
//     s.show();
//     cout << CoordMath::dist(p, q) << endl;
//
//     return 0;
// }
