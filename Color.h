#ifndef COLOR_H_
#define COLOR_H_

#include <string>

class Color {
public:
	Color(int r=255,int g=255,int b=255);

	int getR()const;
	int getG()const;
	int getB()const;

	void setR(int r);
	void setG(int g);
	void setB(int b);

	friend std::ostream& operator<<(std::ostream& os,const Color& c);
        friend std::istream& operator>>(std::istream& in, Color& c);

private:
	int _r,_g,_b;
};

#endif /* COLOR_H_ */
