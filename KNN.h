#ifndef KNN_H
#define KNN_H
#include "Feature.h"
#include <vector>
class KNN
{
	public:
		KNN(vector <Feature>,vector <Feature>);
		void euclideanDistance(Feature &,Feature &);
		void helperFunction(Feature );
		void findKNN(void);
		void printDistances(void);
		int prediction(void);
		~KNN();
	private:
		///Vector that stores training samples
		vector <Feature> training;
		///Vector that stores test samples
		vector <Feature> test;
		///Vector that stores predicted category of test samples
		vector <Feature> result;
		///Vector that stores pairs(euclideandistance,id of training sample)
		vector <pair<double,int>> distances;
};

#endif
