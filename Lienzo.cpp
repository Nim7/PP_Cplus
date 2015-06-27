#include "Lienzo.h"

#include <iostream>
#include <cstdlib>

#define defecto 10 //Por defecto creara un lienzo de 10x10
using namespace std;

Lienzo::Lienzo(int an, int al, Color c) {
    setAncho(an); //eje X
    setAlto(al);  //eje y
    _contenido= new Color*[_ancho];
    for (unsigned int i = 0; i < _ancho; i++){
            _contenido[i]= new Color[_alto];
    }
    pintarFondo(c); //inicializar la estructura, pintarla
}
Lienzo::~Lienzo() {
//	borrar lo dinamico, lo demas se borra "solo"
    for(unsigned int i=0; i<_ancho; i++){
        delete [] _contenido[i];
        _contenido[i]=0; //poner a "NULL"
    }
    delete [] _contenido;
    _contenido = 0; //poner a "NULL"
//        deleteStructure();
}

void Lienzo::pintarFondo (Color c){
    setColorFondo(c);
    for (unsigned int col=0;col<_ancho;col++){
        for (unsigned int fila=0; fila<_alto;fila++){
            _contenido[col][fila]= c;
        }
    }
}
void Lienzo::pintarPunto (Punto p, Color c){
    //Comprobar si lo puede pintar, si ese punto existe en el lienzo
    if ( (p.getX()>=0)&&(p.getX()<(static_cast<int>(_ancho)))&&(p.getY()>=0)
        &&(p.getY()<(static_cast<int>(_alto))) ){
        _contenido[p.getX()][p.getY()]=c;
    }
}
void Lienzo::pintarLinea (Punto p1, Punto p2, Color c){
    bresenham(p1.getX(),p1.getY(),p2.getX(),p2.getY(),c);
}

Lienzo::Lienzo(const Lienzo& l){
    (*this)= l;
}
Color** Lienzo::getCont()const{
    return _contenido;
}
unsigned int Lienzo::getAlto()const{
    return _alto;
}
unsigned int Lienzo::getAncho()const{
    return _ancho;
}
Color Lienzo::getColorFondo()const{
    return _colorFondo;
}

void Lienzo::setAlto(int al){
    if (al<=0){
        _alto= defecto;
    }else{
        _alto=al;
    }
}
void Lienzo::setAncho(int an){
    if (an<=0){
        _ancho= defecto;
    }else{
        _ancho=an;
    }
}
void Lienzo::setColorFondo(Color c){
    _colorFondo = c;
}

//Sobrecarga OPERADORES

ostream& operator<<(ostream& os, const Lienzo& l){
    Color ** contenido = l.getCont();
    Color c;
    //cabecera de fichero ppm
    os << "P3" << "\n"; //Numero Magico archivo
    os << l.getAncho()<< " " << l.getAlto()<< "\n";
    os << "255" << "\n"; //MaxValue
    for (unsigned int fila=0; fila<l.getAlto();fila++){
        for (unsigned int col=0;col<l.getAncho();col++){
            c= contenido[col][fila];
            os << c << " ";
        }
        os << "\n";
    }
    return os;
}

//ALGORITMO BRESENHAM
void Lienzo::bresenham (int x1, int y1, int x2, int y2, Color c){
  // ----------------- Bresenham algorithm -----------------------
  int delta_x = (x2 - x1);

  // if x1 == x2, then it does not matter what we set here
  int const ix = ((delta_x > 0) - (delta_x < 0));
  delta_x = (abs(delta_x)) << 1; //modificado

  int delta_y = (y2 - y1);

  // if y1 == y2, then it does not matter what we set here
  int const iy = ((delta_y > 0) - (delta_y < 0));
  delta_y = (abs(delta_y)) << 1; //modificado

  // Draw the pixel
  //Plot(x1, y1, r, g, b);
  pintarPunto(Punto(x1,y1),c);

  if (delta_x >= delta_y)
  {
    // error may go below zero
    int error = (delta_y - (delta_x >> 1));

    while (x1 != x2)
    {
      if ((error >= 0) && (error || (ix > 0)))
      {
        error -= delta_x;
        y1 += iy;
      }
      // else do nothing

      error += delta_y;
      x1 += ix;

      // Draw the pixel
      //Plot(x1, y1, r, g, b);
      pintarPunto(Punto(x1,y1),c);
    }
  }
  else
  {
    // error may go below zero
    int error = (delta_x - (delta_y >> 1));

    while (y1 != y2)
    {
      if ((error >= 0) && (error || (iy > 0)))
      {
        error -= delta_y;
        x1 += ix;
      }
      // else do nothing

      error += delta_x;
      y1 += iy;

      // Draw the pixel.
      //Plot(x1, y1, r, g, b);
      pintarPunto(Punto(x1,y1),c);
    }
  }
  // ------------ End of Bresenham algorithm -----------------------
}

