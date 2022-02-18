#include "KNN.h"
#include <iostream>
#include <algorithm>
#include <vector>
#define KNEAREST 5
using namespace std;
///Constructor
KNN::KNN(vector <Feature> a,vector <Feature> b):
	training(a),test(b)
{

}
///This function finds the euclideandistance between two features and creates a pair along with training sample's id
void KNN::euclideanDistance(Feature &a,Feature &b)
{
	pair<double,int> pairs;
	pairs.first=sqrt((pow((a.getX()-b.getX()),2))+(pow((a.getY()-b.getY()),2)));
	pairs.second=b.getID();
	distances.push_back(pairs);
}
///This function is to predict which category is test data belongs to
int KNN::prediction()
{
	vector <int> predict(3);
	int maxElementIndex;
	for(auto it=distances.begin();it!=distances.end();it++){
		predict[training[(*it).second].getCat()]++;
	}
	for(int i=0;i<3;i++){
		cout << "Prediction[" << i << "]=" << predict[i] << endl;
	}
	maxElementIndex=(max_element(predict.begin(),predict.end()))-predict.begin();
	cout << "Prediction of Category:" << maxElementIndex << endl;
	return maxElementIndex;
}
/**
*In this function each test feature sends into euclideanDistance function along with every training sample.
*distances vector is sorted based on euclideandistance between test samples and training samples.
*since distance vector stores pairs of distance,id the nearest training sample's id is not lost in sorting process.
*@param KNEAREST is used to determine how many nearest points are required.
*/
void KNN::helperFunction(Feature f1)
{
	for(auto it=training.begin();it!=training.end();it++){
		euclideanDistance(f1,*it);
	}
	sort(distances.begin(),distances.end());
	distances.resize(KNEAREST);
	printDistances();
	f1.setCat(prediction());
	result.push_back(f1);
	distances.clear();
}
///In this function each test sample is used on helperFunction
void KNN::findKNN(void)
{
	for_each(test.begin(), test.end(), bind1st(mem_fun(&KNN::helperFunction), this));
	cout << "\n----Predicted Test Samples----\n" << endl;
	for(auto it=result.begin();it!=result.end();it++){
		cout << *it << endl;
	}
}
///Print function for distances vector
void KNN::printDistances(void)
{
	cout << "\n-----------------\n" << endl;
	for(auto it=distances.begin();it!=distances.end();it++){
		cout << training[(*it).second] << "\tDistance:" << (*it).first << endl; 
	}
}
///Destructor
KNN::~KNN()
{
	
}
