#include "Punto.h"

#include <iostream>

using namespace std;

Punto::Punto(int x, int y) {
    setX(x);
    setY(y);
}

int Punto::getX()const{
    return _x;
}
int Punto::getY()const{
    return _y;
}

void Punto::setX(int x){
    _x=x;
}
void Punto::setY(int y){
    _y=y;
}

ostream& operator<<(ostream& os, const Punto& p){
    os << "Punto -> x = " << p.getX() << " / y = " << p.getY() << endl;
    return os;
}
istream& operator>>(istream& in, Punto& p){
    int x, y;
    in >> x >> y;
    p.setX(x);
    p.setY(y);
    return in;
}