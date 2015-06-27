#ifndef SEGMENTO_H_
#define SEGMENTO_H_

#include "Figura.h"
#include "Punto.h"
#include "Color.h"
#include "Lienzo.h"

class Segmento: public Figura {
public:
	Segmento(int id,Punto p1, Punto p2, Color c);

	Punto getP1()const;
	Punto getP2()const;
        Color getColor()const;

	void setP1(Punto p);
	void setP2(Punto p);
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
    Punto _p1, _p2;
};

#endif /* SEGMENTO_H_ */
