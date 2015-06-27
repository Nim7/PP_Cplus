#ifndef LIENZO_H_
#define LIENZO_H_

#include "Color.h"
#include "Punto.h"

class Lienzo {

public:
    Lienzo(int an = 10, int al = 10, Color c = Color());
    ~Lienzo();

    Lienzo (const Lienzo& l); //Constructor de copia
        
    void pintarLinea (Punto p1, Punto p2, Color c);
	
    Color** getCont()const;
    unsigned int getAlto()const;
    unsigned int getAncho()const;
    Color getColorFondo()const;

    void setAlto(int al);
    void setAncho(int an);
    void setColorFondo(Color c);

    friend std::ostream& operator<<(std::ostream& o,const Lienzo& l);

private:
    unsigned int _alto,_ancho;
    Color _colorFondo; //guardar color fondo para repintar
    Color ** _contenido;
    void bresenham (int x1, int y1, int x2, int y2, Color c);
    void pintarFondo (Color c);
    void pintarPunto (Punto p, Color c);
    
};

#endif /* LIENZO_H_ */
