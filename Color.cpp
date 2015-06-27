#include "Color.h"

#include <iostream>

using namespace std;

Color::Color(int r,int g,int b){
    setR(r);
    setG(g);
    setB(b);
}

int Color::getR()const{
    return _r;
}
int Color::getG()const{
    return _g;
}
int Color::getB()const{
    return _b;
}

void Color::setR(int r){
    if (r>255){
            _r=255;
    }else if (r<0){
            _r=0;
    }else{
            _r=r;
    }
}
void Color::setG(int g){
    if (g>255){
            _g=255;
    }else if (g<0){
            _g=0;
    }else{
            _g=g;
    }
}
void Color::setB(int b){
    if (b>255){
            _b=255;
    }else if (b<0){
            _b=0;
    }else{
            _b=b;
    }
}

ostream& operator<<(ostream& os, const Color& c){
    os << c.getR() << " " << c.getG() << " " << c.getB();
    return os;
}
istream& operator>>(istream& in, Color& c){
    int r, g, b;
    in >> r >> g >> b;
    c.setR(r);
    c.setG(g);
    c.setB(b);
    return in;
}