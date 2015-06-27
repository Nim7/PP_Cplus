#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"
#include "Punto.h"
#include "Color.h"
#include "Lienzo.h"

class Triangulo: public Figura{
public:
	Triangulo(int id, Punto p1, Punto p2, Punto p3, Color c);

	Punto getP1()const;
	Punto getP2()const;
	Punto getP3()const;
        Color getColor()const;

	void setP1(Punto p);
	void setP2(Punto p);
	void setP3(Punto p);
        void setColor(Color c);
        
        void dibujar(Lienzo &l);
	void moverFig (int x,int y);
        double distanciaCentroide(Punto p);
        bool enCuadradoSelec(Punto p);

	Punto centroide();
	Punto areaArribaIzq();
	Punto areaArribaDer();
	Punto areaAbajoIzq();
	Punto areaAbajoDer();

private:
    Color  _c;  
    Punto _p1,_p2,_p3;
};

#endif /* TRIANGULO_H_ */
