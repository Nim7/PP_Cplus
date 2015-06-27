#include "Triangulo.h"

#include <math.h>

using namespace std;

Triangulo::Triangulo(int id, Punto p1, Punto p2, Punto p3, Color c):Figura(id){
	setP1(p1);
	setP2(p2);
	setP3(p3);
        setColor(c);
}

Punto Triangulo::getP1()const{
	return _p1;
}
Punto Triangulo::getP2()const{
	return _p2;
}
Punto Triangulo::getP3()const{
	return _p3;
}
Color Triangulo::getColor()const{
	return _c;
}
void Triangulo::setP1(Punto p){
	_p1=p;
}
void Triangulo::setP2(Punto p){
	_p2=p;
}
void Triangulo::setP3(Punto p){
	_p3=p;
}
void Triangulo::setColor(Color c){
	_c=c;
}
void Triangulo::dibujar(Lienzo &l){
    l.pintarLinea(_p1,_p2,this->getColor());
    l.pintarLinea(_p2,_p3,this->getColor());
    l.pintarLinea(_p1,_p3,this->getColor());
};
void Triangulo::moverFig (int x,int y){
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
	p= getP3();
	auxx= p.getX()+x;
	auxy= p.getY()+y;
	setP3(Punto(auxx,auxy));
}
double Triangulo::distanciaCentroide(Punto p){
    Punto centr = centroide();
    int auxx,auxy;
    auxx = pow((p.getX() - centr.getX()),2);
    auxy = pow((p.getY() - centr.getY()),2);
    return sqrt(auxx+auxy);
}
bool Triangulo::enCuadradoSelec(Punto p){
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
Punto Triangulo::centroide(){
	Punto p1,p2,p3;
	double auxx, auxy;
	p1=getP1();
	p2=getP2();
	p3=getP3();
	auxx = (p1.getX()+p2.getX()+p3.getX())/3;
	auxy = (p1.getY()+p2.getY()+p3.getY())/3;
	return Punto(int(auxx),int(auxy));
;
}
Punto Triangulo::areaArribaIzq(){
	int auxx,auxy,x1,x2,x3,y1,y2,y3;
		x1=getP1().getX();
		x2=getP2().getX();
		if (x1<=x2){
			if (x1<=x3){
				auxx=x1;
			}else{
				auxx=x3;
			}
		}else{
			if (x2<=x3){
				auxx=x2;
			}else{
				auxx=x3;
			}
		}
		y1=getP1().getY();
		y2=getP2().getY();
		y3=getP3().getY();
		if (y1<=y2){
			if (y1<=y3){
				auxy=y1;
			}else{
				auxy=y3;
			}

		}else{
			if (y2<=y3){
				auxy=y2;
			}else{
				auxy=y3;
			}
		}
		return Punto(auxx,auxy);
}
Punto Triangulo::areaArribaDer(){
	int auxx,auxy,x1,x2,x3,y1,y2,y3;
		x1=getP1().getX();
		x2=getP2().getX();
                x3=getP3().getX();
		if (x1>=x2){
			if (x1>=x3){
				auxx=x1;
			}else{
				auxx=x3;
			}
		}else{
			if (x2>=x3){
				auxx=x2;
			}else{
				auxx=x3;
			}
		}
		y1=getP1().getY();
		y2=getP2().getY();
		y3=getP3().getY();
		if (y1<=y2){
			if (y1<=y3){
				auxy=y1;
			}else{
				auxy=y3;
			}

		}else{
			if (y2<=y3){
				auxy=y2;
			}else{
				auxy=y3;
			}
		}
		return Punto(auxx,auxy);
}
Punto Triangulo::areaAbajoIzq(){
	int auxx,auxy,x1,x2,x3,y1,y2,y3;
	x1=getP1().getX();
	x2=getP2().getX();
	if (x1<=x2){
		if (x1<=x3){
			auxx=x1;
		}else{
			auxx=x3;
		}
	}else{
		if (x2<=x3){
			auxx=x2;
		}else{
			auxx=x3;
		}
	}
	y1=getP1().getY();
	y2=getP2().getY();
	y3=getP3().getY();
	if (y1>=y2){
		if (y1>=y3){
			auxy=y1;
		}else{
			auxy=y3;
		}

	}else{
		if (y2>=y3){
			auxy=y2;
		}else{
			auxy=y3;
		}
	}
	return Punto(auxx,auxy);
}
Punto Triangulo::areaAbajoDer(){
	int auxx,auxy,x1,x2,x3,y1,y2,y3;
		x1=getP1().getX();
		x2=getP2().getX();
                x3=getP3().getX();
		if (x1>=x2){
			if (x1>=x3){
				auxx=x1;
			}else{
				auxx=x3;
			}
		}else{
			if (x2>=x3){
				auxx=x2;
			}else{
				auxx=x3;
			}
		}
		y1=getP1().getY();
		y2=getP2().getY();
		y3=getP3().getY();
		if (y1>=y2){
			if (y1>=y3){
				auxy=y1;
			}else{
				auxy=y3;
			}

		}else{
			if (y2>=y3){
				auxy=y2;
			}else{
				auxy=y3;
			}
		}
		return Punto(auxx,auxy);
}
