#include "Figura.h"

using namespace std;

Figura::Figura(int id) {
	setId(id);
}
Figura::~Figura(){}

int Figura::getId()const{
	return _idFig;
}
void Figura::setId(int id){
	_idFig=id;
}

vector<Figura*> Figura::desAgrupar(){}
void Figura::dibujar(Lienzo &l){}
void Figura::moverFig (int x, int y){}
double Figura::distanciaCentroide(Punto p){}
bool Figura::enCuadradoSelec(Punto p){}
