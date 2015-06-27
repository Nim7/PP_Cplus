#ifndef GRUPOFIGURAS_H
#define	GRUPOFIGURAS_H

#include "Figura.h"
#include "Lienzo.h"
#include "Punto.h"
#include <vector>

class GrupoFiguras: public Figura{
public:
    GrupoFiguras(int id,std::vector<Figura*> vecF);
    ~GrupoFiguras();
    
    std::vector<Figura*> desAgrupar();
    

    void dibujar(Lienzo &l);
    void moverFig (int x, int y);
    double distanciaCentroide(Punto p);
    bool enCuadradoSelec(Punto p);

private:
	std::vector<Figura*> _gfiguras;;
};


#endif	/* GRUPOFIGURAS_H */

