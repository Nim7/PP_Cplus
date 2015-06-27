#include "Rectangulo.h"

#include <math.h>

using namespace std;

Rectangulo::Rectangulo(int id,Punto p1, int ancho, int alto, Color c):Figura(id){
	setP1(p1);
	setAncho(ancho);
        setAlto(alto);
        setColor(c);
}

Punto Rectangulo::getP1()const{
    return _p1;
}
int Rectangulo::getAncho()const{
    return _ancho;
}
int Rectangulo::getAlto()const{
    return _alto;
}
Color Rectangulo::getColor()const{
	return _c;
}
void Rectangulo::setP1(Punto p){
    _p1=p;
}
void Rectangulo::setAncho(int ancho){
    if(ancho<1){
        _ancho=1;
    }else{
        _ancho=ancho;
    }
}
void Rectangulo::setAlto(int alto){
    if(alto<1){
        _alto=1;
    }else{
        _alto=alto;
    }
}
void Rectangulo::setColor(Color c){
	_c=c;
}

void Rectangulo::dibujar(Lienzo &l){
    l.pintarLinea(areaArribaIzq(),areaArribaDer(),this->getColor());
    l.pintarLinea(areaArribaDer(),areaAbajoDer(),this->getColor());
    l.pintarLinea(areaArribaIzq(),areaAbajoIzq(),this->getColor());
    l.pintarLinea(areaAbajoIzq(),areaAbajoDer(),this->getColor());
}
//	std::vector<Punto> devolverPuntos();
void Rectangulo::moverFig (int x,int y){
    Punto p;
    int auxx, auxy;
    p= getP1();
    auxx= p.getX()+x;
    auxy= p.getY()+y;
    setP1(Punto(auxx,auxy));
}
double Rectangulo::distanciaCentroide(Punto p){
    Punto centr = centroide();
    int auxx,auxy;
    auxx = pow((p.getX() - centr.getX()),2);
    auxy = pow((p.getY() - centr.getY()),2);
    return sqrt(auxx+auxy);
}
bool Rectangulo::enCuadradoSelec(Punto p){
    Punto arrIzq,arrDer,abaIzq,abaDer;
    arrIzq = areaArribaIzq();
    arrDer = areaArribaDer();
    abaDer = areaAbajoDer();
    abaIzq = areaAbajoIzq();
    bool dentro = (arrIzq.getX()<=p.getX()) && (arrIzq.getY()<=p.getY()) && 
                (arrDer.getX()>=p.getX()) && (arrDer.getY()<=p.getY()) &&
                (abaIzq.getX()<=p.getX()) && (abaIzq).getY()>=p.getY() &&
                (abaDer.getX()>=p.getX()) && (abaDer.getY()>=p.getY());            
    return dentro;
}
Punto Rectangulo::centroide(){
    Punto p1,p2,p3,p4;
    double auxx, auxy;
    p1=getP1();
    p2=areaArribaDer();
    p3=areaAbajoIzq();
    p4=areaAbajoDer();
    auxx = (p1.getX()+p2.getX()+p3.getX()+p4.getX())/4;
    auxy = (p1.getY()+p2.getY()+p3.getY()+p3.getY())/4;
    return Punto(int(auxx),int(auxy));
}
Punto Rectangulo::areaArribaIzq(){
    return getP1();
}
Punto Rectangulo::areaArribaDer(){
    Punto p= getP1();
    int auxx,auxy;
    auxx = p.getX() + getAncho() -1;
    auxy = p.getY();
    return Punto(auxx,auxy);
}
Punto Rectangulo::areaAbajoIzq(){
    Punto p= getP1();
    int auxx,auxy;
    auxx = p.getX();
    auxy = p.getY() + getAlto() -1;
    return Punto(auxx,auxy);
}
Punto Rectangulo::areaAbajoDer(){
    Punto p= getP1();
    int auxx,auxy;
    auxx = p.getX() + getAncho() -1;
    auxy = p.getY() + getAlto() -1;
    return Punto(auxx,auxy);
}
