#ifndef PUNTO_H_
#define PUNTO_H_

#include <string>

class Punto {
public:
	Punto(int x=0,int y=0);

	int getX()const;
	int getY()const;

	void setX(int x);
	void setY(int y);
        
        friend std::ostream& operator<<(std::ostream& os,const Punto& p);
        friend std::istream& operator>>(std::istream& in, Punto& p);
private:
	int _x,_y;

};

#endif /* PUNTO_H_ */
