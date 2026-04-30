#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include "Point.h"
#include "Bubble.h"

using namespace std;

Point::Point(int x,int y,int z)
    :x{x},y{y},z{z} {

}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}
int Point::getZ() const {
    return z;
}
void Point::setX(int x) {
    this->x = x;
}
void Point::setY(int y) {
    this->y = y;
}
void Point::setZ(int z) {
    this->z = z;
}

string Point::toString() const {
    stringstream ss;
    ss << "bubble (" << x << ", " << y << ", " << z << ") ";
    return ss.str();
}


Bubble::Bubble(int x, int y, int z, int r) :Point(x,y,z){
    radius = r;
    volume = (4.0/3.0)*3.14*radius*radius*radius;
}

int Bubble::getRadius() const {
    return radius;
}
void Bubble::setRadius(int r) {
    this->radius = r;
    volume = (4.0/3.0)*3.14*radius*radius*radius;
}
double Bubble::getVolume() const {
    return volume;
}

void Bubble::setVolume(int v) {
    radius = v;
    volume = (4.0/3.0)*3.14*radius*radius*radius;
}

string Bubble::toString() const {
    stringstream ss;
    ss  << "bubble (" << getX() << ", " << getY() << ", " << getZ() << ") R=" << getRadius();
    return ss.str();
}

int main() {
    cout << fixed << setprecision(2);
    int T;
    cin >> T;
    for (int i =0; i < T; i++) {
        int a1,b1,c1,d1,a2,b2,c2,d2;
        cin>>a1>>b1>>c1 >> d1;
        cin>>a2>>b2>>c2 >> d2;

        double d = sqrt(pow(a1-a2,2) + pow(b1-b2,2) + pow(c1-c2,2));

        Bubble bubble[2] = {Bubble(a1,b1,c1,d1), Bubble(a2,b2,c2,d2)};

        if (d1+d2 <= d) {
            cout << bubble[0].toString() << " and " << bubble[1].toString()
            << " are disjoint\n";


        }
        else if (d1+d2 > d) {
            if (d1 + d <= d2) {
                cout << bubble[0].toString() << " includes " << bubble[1].toString()
                << "\n";
            }
            else if (d2 + d <= d1) {
                cout << bubble[1].toString() << " includes " << bubble[0].toString()
                << "\n";
            }
            else {
                cout << bubble[0].toString() << " and " << bubble[1].toString()
                << " partially overlap\n";
            }
        }

        if (d1 > d2) {
            cout << "bubble with the larger volume: " << bubble[0].toString() << " , V=" << bubble[0].getVolume() << endl;
        }
        else if (d1 == d2) {
            cout << bubble[0].toString() << " and " << bubble[1].toString()
        <<" have the same volume, V=" << bubble[0].getVolume();
        }else {
            cout << "bubble with the larger volume: " << bubble[1].toString() << " , V=" << bubble[1].getVolume() << endl;
        }


    }
    
}
