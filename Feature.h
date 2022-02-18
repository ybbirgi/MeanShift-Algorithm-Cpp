#ifndef FEATURE_H
#define FEATURE_H
#include <iostream>
using namespace std;

class Feature
{
	friend ostream &operator<<(ostream&,const Feature&);
	public:
		Feature(int catVal=0,int idVal=0);
		void setX(double);
		void setY(double);
		void setCat(int);
		void setID(int);
		double getX(void) const;
		double getY(void) const;
		int getCat(void) const;
		int getID(void) const;
		double generateRand(void);
		~Feature();
	private:
		///x coordinate
		double x;
		///y coordinate
		double y;
		///category of feature
		int cat;
		///id of feature
		int id;
};

#endif
