#ifndef FIGURA_H_
#define FIGURA_H_

#include "Punto.h"
#include "Lienzo.h"

#include <vector>

class Figura {
public:
	Figura(int id);
	virtual ~Figura();

	int getId()const;
	void setId(int id);

        virtual std::vector<Figura*> desAgrupar();
        
        virtual void dibujar(Lienzo &l);
	virtual void moverFig (int x, int y);
        virtual double distanciaCentroide(Punto p);
        virtual bool enCuadradoSelec(Punto p);
        
private:
	int _idFig;
};

#endif /* FIGURA_H_ */
