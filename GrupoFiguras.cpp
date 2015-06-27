#include "GrupoFiguras.h"

#include <iostream>

using namespace std;

GrupoFiguras::GrupoFiguras(int id, std::vector<Figura*> vecF):Figura(id){
    _gfiguras = vecF;
}
GrupoFiguras::~GrupoFiguras(){
    vector<Figura*>::iterator it;
    for (it = _gfiguras.begin(); it!=_gfiguras.end(); it++){
        delete (*it);
    }
}
vector<Figura*> GrupoFiguras::desAgrupar(){
    vector<Figura*> aux = _gfiguras;
    _gfiguras.clear();
    return aux;
}

void GrupoFiguras::dibujar(Lienzo &l){
    vector<Figura*>::iterator it;
    for (it = _gfiguras.begin(); it!=_gfiguras.end(); it++){
        (*it)->dibujar(l);
    }
}
void GrupoFiguras::moverFig (int x, int y){
    vector<Figura*>::iterator it;
    for (it = _gfiguras.begin(); it!=_gfiguras.end(); it++){
        (*it)->moverFig(x,y);
    }
}
double GrupoFiguras::distanciaCentroide(Punto p){
    double aux = 9999;
    vector<Figura*>::iterator it;
    for (it = _gfiguras.begin(); it!=_gfiguras.end(); it++){
        aux = min(aux,(*it)->distanciaCentroide(p));
    }
    return aux;
}
bool GrupoFiguras::enCuadradoSelec(Punto p){
    bool enCuadrado = false;
    vector<Figura*>::iterator it;
    for (it = _gfiguras.begin(); it!=_gfiguras.end(); it++){
        if((*it)->enCuadradoSelec(p)){
            enCuadrado = true;
        }
    }
    return enCuadrado;
}
