#include "Segmento.h"

#include <math.h>

using namespace std;

Segmento::Segmento(int id, Punto p1, Punto p2, Color c):Figura(id){
	setP1(p1);
	setP2(p2);
        setColor(c);
}

Punto Segmento::getP1()const{
	return _p1;
}
Punto Segmento::getP2()const{
	return _p2;
}
Color Segmento::getColor()const{
	return _c;
}
void Segmento::setP1(Punto p){
	_p1=p;
}
void Segmento::setP2(Punto p){
	_p2=p;
}
void Segmento::setColor(Color c){
	_c=c;
}

void Segmento::dibujar(Lienzo &l){
    l.pintarLinea(_p1,_p2,this->getColor());
};
void Segmento::moverFig (int x,int y){
	Punto p;
	int auxx, auxy;
	p= getP1();
	auxx= p.getX()+x;
	auxy= p.getY()+y;
	setP1(Punto(auxx,auxy));
	p= getP2();
	auxx= p.getX()+x;
	auxy= p.getY()+y;
	setP2(Punto(auxx,auxy));
}
double Segmento::distanciaCentroide(Punto p){
    Punto centr = centroide();
    int auxx,auxy;
    auxx = pow((p.getX() - centr.getX()),2);
    auxy = pow((p.getY() - centr.getY()),2);
    return sqrt(auxx+auxy);
}
bool Segmento::enCuadradoSelec(Punto p){
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
Punto Segmento::centroide(){
	Punto p1,p2;
	double auxx, auxy;
	p1=getP1();
	p2=getP2();
	auxx = (p1.getX()+p2.getX())/2;
	auxy = (p1.getY()+p2.getY())/2;
	return Punto(int(auxx),int(auxy));
}
Punto Segmento::areaArribaIzq(){
	int auxx,auxy,x1,x2,y1,y2;
	x1=getP1().getX();
	x2=getP2().getX();
	if (x1<=x2){
		auxx=x1;
	}else{
		auxx=x2;
	}
	y1=getP1().getY();
	y2=getP2().getY();
	if (y1<=y2){
		auxy=y1;
	}else{
		auxy=y2;
	}
	return Punto(auxx,auxy);
}
Punto Segmento::areaArribaDer(){
	int auxx,auxy,x1,x2,y1,y2;
	x1=getP1().getX();
	x2=getP2().getX();
	if (x1>=x2){
		auxx=x1;
	}else{
		auxx=x2;
	}
	y1=getP1().getY();
	y2=getP2().getY();
	if (y1<=y2){
		auxy=y1;
	}else{
		auxy=y2;
	}
	return Punto(auxx,auxy);
}
Punto Segmento::areaAbajoIzq(){ // y si hay coordenadas iguales???
	int auxx,auxy,x1,x2,y1,y2;
	x1=getP1().getX();
	x2=getP2().getX();
	if (x1<=x2){
		auxx=x1;
	}else{
		auxx=x2;
	}
	y1=getP1().getY();
	y2=getP2().getY();
	if (y1>=y2){
		auxy=y1;
	}else{
		auxy=y2;
	}
	return Punto(auxx,auxy);
}
Punto Segmento::areaAbajoDer(){
	int auxx,auxy,x1,x2,y1,y2;
	x1=getP1().getX();
	x2=getP2().getX();
	if (x1>=x2){
		auxx=x1;
	}else{
		auxx=x2;
	}
	y1=getP1().getY();
	y2=getP2().getY();
	if (y1>=y2){
		auxy=y1;
	}else{
		auxy=y2;
	}
	return Punto(auxx,auxy);
}
