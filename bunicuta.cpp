#include <fstream>
#include <cmath>
using namespace std;
ifstream f("bunicuta.in");
ofstream g("bunicuta.out");
class Total{

public:
    long long friscatot = 0;
    long long gemtot = 0;
};

class Shape: Total {
    protected:
        int ord;
        long long frisca, gem, h;
        void display() {
            g<<gem<<' '<<frisca<<'\n';
            gemtot += gem;
            friscatot += frisca;
        }
        void setFrisca(long long newfrisca, int h) {
            frisca = newfrisca;
            gem = 2 * frisca *h;
            display();
         }
};
class Circle : Shape {
public:
    Circle(int raza, int h) : Shape() {
        setFrisca(static_cast<long long>(2 * raza * M_PI * M_PI), h);
    }
};
class Rectangular : Shape {
public:
    Rectangular(int lat, int lung, int h) : Shape() {
        setFrisca(static_cast<long long>(lat * lung), h);
    }
};
class Square : Shape {
public:
    Square(int patrat, int h) : Shape() {
        setFrisca(static_cast<long long>(patrat * patrat), h);
    }
};
class Triangle : Shape  {
public:
    Triangle(int cat1, int cat2, int h) : Shape() {
        setFrisca(static_cast<long long>(cat1 * cat2) /2, h);
    }
};

int main()
{
    int i, j, n, op;
    Total tot;
    f>>n;
    for (i = 0; i < n; i++) {
        f>>op;
        int tip;
        if (op==0) { //ADD
            f>>tip;
            if (tip==0) {
                int raza,h;
                f>>raza>>h;
                Circle(raza, h);
            }
            if (tip==1) {
                int lat,lung,h;
                f>>lat>>lung>>h;
                Rectangular(lat,lung, h);
            }
            if (tip==2) {
                int patrat, h;
                f>>patrat>>h;
                Square(patrat, h);
            }
            if (tip==3) {
                int cat1, cat2, h;
                f>>cat1>>cat2>>h;
                Triangle(cat1, cat2, h);
            }
        }
        if (op==1)
            g<<tot.gemtot<<' '<<tot.friscatot<<'\n';
        if (op==2) {



        }
    }


    return 0;
}