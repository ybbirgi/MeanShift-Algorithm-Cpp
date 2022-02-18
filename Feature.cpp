#include "Feature.h"
///Constructor
Feature::Feature(int catVal,int Idn)
{
	setCat(catVal);
	setID(Idn);
	setX(generateRand());
	setY(generateRand());
}
///Set function for x
void Feature::setX(double xVal)
{
	x=xVal;
}
///Set function for y
void Feature::setY(double yVal)
{
	y=yVal;
}
///Set function for cat
void Feature::setCat(int catVal)
{
	cat=catVal;
}
///Set function for id
void Feature::setID(int idVal)
{
	id=idVal;
}
///Get function for x
double Feature::getX(void) const
{
	return x;
}
///Get function for y
double Feature::getY(void) const
{
	return y;
}
///Get function for cat
int Feature::getCat(void) const
{
	return cat;
}
///Get function for id
int Feature::getID(void) const
{
	return id;
}
///A function that generates random numbers for features(x,y) between -5,5 scaled on 0.00
double Feature::generateRand(void)
{
	double temp;
	temp=((double)(rand()%1001)-500)/100;
	return temp;
}
///ostream operator overloading
ostream &operator<<(ostream &output,const Feature &temp)
{
	output << "Category:" << temp.getCat() << "\t" << temp.getID() << "(" << temp.getX() << "," << temp.getY() << ")"; 
	return output;
}
///destructor
Feature::~Feature()
{
}
