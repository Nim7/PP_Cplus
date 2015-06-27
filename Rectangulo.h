#ifndef RECTANGULO_H
#define	RECTANGULO_H

#include "Figura.h"
#include "Punto.h"
#include "Color.h"
#include "Lienzo.h"

class Rectangulo: public Figura {
public:
	Rectangulo(int id, Punto p1, int ancho, int alto, Color c);

	Punto getP1()const;
	int getAncho()const;
        int getAlto()const;
        Color getColor()const;
        
	void setP1(Punto p);
	void setAncho(int ancho);
        void setAlto(int alto);
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
	Punto _p1;
        int _ancho,_alto;
};


#endif	/* RECTANGULO_H */

