#include "Dibujo.h"
#include "Segmento.h"
#include "Triangulo.h"
#include "Rectangulo.h"
#include "GrupoFiguras.h"

#include <cstring>
#include <iostream>
#include <algorithm>
#include <typeinfo>

using namespace std;

Dibujo::Dibujo(int an, int al, Color c){
    _l = new Lienzo(an,al,c);
    _id = 1;
}
Dibujo::~Dibujo(){
    delete _l;
    _l = 0;
    vector<Figura*>::iterator it;
    for (it = _figuras.begin(); it!=_figuras.end(); it++){
        delete (*it);
    }
    _figuras.clear();
    borrarSel();
}
void Dibujo::nuevoLienzo(int an, int al, Color c){
    delete _l;
    _l = new Lienzo(an,al,c);
    
}
Lienzo* Dibujo::getLienzo()const{
    return _l;
}
vector<Figura*> Dibujo::getFiguras()const{
    return _figuras;
}
vector<Figura*> Dibujo::getSelec()const{
    return _selecion;
}
int Dibujo::getId()const{
    return _id;
}
void Dibujo::increaseId(){
    _id = getId() + 1;
}
void Dibujo::addFigura(Figura* f){
    _figuras.push_back(f);
}
void Dibujo::addSeleccion(Figura* f){
    _selecion.push_back(f);
}
void Dibujo::borrarFigFigura(Figura* f){
    vector<Figura*>::iterator it;
    it = find(_figuras.begin(), _figuras.end(), f);
    if (it != _figuras.end())
      _figuras.erase(it);
}

void Dibujo::dibujarFiguras(){
//    _l->pintarFondo(_l->getColorFondo());
    vector<Figura*>::iterator it;
    for (it = _figuras.begin(); it!=_figuras.end(); it++){
        (*it)->dibujar((*_l));
    }
}

void Dibujo::seleccionar(Punto p){
    Figura* aux; 
    double dist = 9999; //inicializado a un valor alto para obtener el menor
    vector<Figura*> posibles;
    vector<Figura*>::iterator it;
    deseleccionar();
    for (it = _figuras.begin(); it!=_figuras.end(); it++){
        if((*it)->enCuadradoSelec(p)){
            posibles.push_back(*it);
        }
    }
    if (posibles.size() == 1){
        aux = posibles.front();
        borrarFigFigura(aux);
        addSeleccion(aux);
    }else if (posibles.size() > 1){
        for(it = posibles.begin(); it!=posibles.end();it++){
            if ((*it)->distanciaCentroide(p) < dist){
                aux = (*it);
                dist = (*it)->distanciaCentroide(p);
            }
        }
        borrarFigFigura(aux);
        addSeleccion(aux);
    }
}
void Dibujo::agregarSel(Punto p){
    Figura* aux; 
    double dist = 9999; //inicializado a un valor alto para obtener el menor
    vector<Figura*> posibles;
    vector<Figura*>::iterator it;
    for (it = _figuras.begin(); it!=_figuras.end(); it++){
        if((*it)->enCuadradoSelec(p)){
            posibles.push_back(*it);
        }
    }if (posibles.size() == 0){
        deseleccionar();
    }else if(posibles.size() == 1){
        aux = posibles.front();
        borrarFigFigura(aux);
        addSeleccion(aux);
    }else{
        for(it = posibles.begin(); it!=posibles.end();it++){
            if ((*it)->distanciaCentroide(p) < dist){
                aux = (*it);
                dist = (*it)->distanciaCentroide(p);
            }
        }
        borrarFigFigura(aux);
        addSeleccion(aux);
    }
}
void Dibujo::deseleccionar(){ //mover de _selecc a _figuras
    vector<Figura*>::iterator it;
    for (it = _selecion.begin(); it!=_selecion.end(); it++){
        addFigura(*it);
    }
    _selecion.clear();
}
void Dibujo::moverSel(int x, int y){
    vector<Figura*>::iterator it;
    for (it = _selecion.begin(); it!=_selecion.end(); it++){
        (*it)->moverFig(x,y);
    }
}
void Dibujo::borrarSel(){
    // liberar memoria
    vector<Figura*>::iterator it;
    for (it = _selecion.begin(); it!=_selecion.end(); it++){
        delete (*it);
    }
    _selecion.clear();
}
void Dibujo::agruparSel(){
    GrupoFiguras* aux = new GrupoFiguras(getId(),_selecion);
    increaseId();
    _selecion.clear();
    addSeleccion(aux);
}
void Dibujo::desagruparSel(){
    if (_selecion.size()==1){
        //solo si es "GrupoFiguras"
        Figura* f = _selecion.at(0);
	if( GrupoFiguras* g = dynamic_cast<GrupoFiguras*> (f)){
            vector<Figura*> aux;
            aux = f->desAgrupar();
            _selecion.clear();
            _selecion = aux;
        }
    }
    //no hacer nada
}
ostream& operator<<(ostream& os, const Dibujo& d){
    os << (*d.getLienzo());
    return os;
}
istream& operator>>(istream& in, Dibujo& d){
    int an, al;
    in >> an >> al;
    Color c;
    in >> c;
    
    //Reinizializar lienzo
    d.nuevoLienzo(an, al, c);
    
    int nFig, nOp;
    in >> nFig;
    string tipo,op;
    for(int i = 0; i < nFig; i++){
        tipo=""; 
        in >> tipo; //hasta el 1 espacio, tipo
        Color c1;
        if (strcmp(tipo.c_str(), "Seg")==0){//Segmento    
            Punto p1,p2;
            in >> p1 >> p2 >> c1;
            Figura* f = new Segmento(d.getId(),p1,p2,c1);
            d.increaseId();
            d.addFigura(f);
        }
        else if (strcmp(tipo.c_str(), "Tri")==0){ //Triangulo
            Punto p1,p2,p3;
            in >> p1 >> p2 >> p3 >> c1;
            Figura* f = new Triangulo(d.getId(),p1,p2,p3,c1);
            d.increaseId();
            d.addFigura(f);
        }
        else if (strcmp(tipo.c_str(), "Rec")==0){//Rectangulo
            Punto p1;
            int alto,ancho;
            in >> p1 >> ancho >> alto >> c1;
            Figura* f = new Rectangulo(d.getId(),p1,ancho,alto,c1);
            d.increaseId();
            d.addFigura(f);
        }
    }
    in >> nOp;
    for (int i = 0; i < nOp; i++){
        op = "";
        in >> op;
        if (strcmp(op.c_str(), "Seleccionar")==0){
            int x, y;
            in >> x >> y;
            Punto p(x, y);
            d.seleccionar(p);
        }
        else if (strcmp(op.c_str(), "AgregarSel") == 0){
            int x, y;
            in >> x >> y;
            Punto p(x, y);
            d.agregarSel(p);
        }
        else if (strcmp(op.c_str(), "Deseleccionar") ==0){
            d.deseleccionar();
        }
        else if (strcmp(op.c_str(), "MoverSel")==0){
            int x, y; 
            in >> x >> y;
            d.moverSel(x,y);
        }
        else if (strcmp(op.c_str(), "BorrarSel")==0){
            d.borrarSel();
        }
        else if (strcmp(op.c_str(), "AgruparSel")==0){
            d.agruparSel();
        }
        else if (strcmp(op.c_str(), "DesagruparSel")==0){
            d.desagruparSel();
        }
    }
    d.deseleccionar();
    d.dibujarFiguras();
    return in;
}