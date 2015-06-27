#ifndef DIBUJO_H
#define	DIBUJO_H

#include "Lienzo.h"
#include "Figura.h"
#include "Color.h"
#include "Punto.h"

#include <vector>

class Dibujo{
public:
    Dibujo(int an = 10, int al = 5, Color c = Color());
    ~Dibujo();
    
    Lienzo* getLienzo()const;
    std::vector<Figura*> getFiguras()const;
    std::vector<Figura*> getSelec()const;
    int getId()const;
    void addFigura(Figura* f);
    void addSeleccion(Figura* f);
    void borrarFigFigura(Figura* f);
    
    void dibujarFiguras();

    void seleccionar(Punto p);
    void agregarSel(Punto p);
    void deseleccionar();
    void moverSel(int x, int y);
    void borrarSel();
    void agruparSel();
    void desagruparSel();
    
    friend std::ostream& operator<<(std::ostream& os,const Dibujo& d);
    friend std::istream& operator>>(std::istream& in, Dibujo& d);
    
private:
    int _id;
    Lienzo* _l;
    std::vector<Figura*> _figuras;
    std::vector<Figura*> _selecion;
    void increaseId();
    void nuevoLienzo(int an, int al, Color c);
};

#endif	/* DIBUJO_H */

