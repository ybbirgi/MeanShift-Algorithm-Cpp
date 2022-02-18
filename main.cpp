#include <iostream>
#include "Feature.h"
#include "KNN.h"
#include <vector>
#include <algorithm>
#define TRAINSIZE 30
#define TESTSIZE 10
using namespace std;
Feature gTraining(void);
Feature gTest(void);
void printVector(vector<Feature> &, const string &);
main() {
	vector <Feature> training_samples(TRAINSIZE);
	generate(training_samples.begin(),training_samples.end(), gTraining);
	printVector(training_samples,"Training Samples:");
	vector <Feature> test_samples(TESTSIZE);
	generate(test_samples.begin(),test_samples.end(), gTest);
	printVector(test_samples,"Test Samples:");
	KNN a(training_samples,test_samples);
	a.findKNN();
}
///Generate function for training samples
Feature gTraining(void)
{
	static int i=0;
	int hold;
	if (i<10)
		hold=0;
	else if (i>19)
		hold=2;
	else 
		hold=1;
	Feature temp(hold,i);
  	i++;
  	
	return temp; 
}
///Generate function for test samples
Feature gTest(void)
{
	static int j=30;
	int hold=0;
	Feature temp(hold,j);
  	j++;
  	
	return temp; 
}
///print function for vectors
void printVector(vector<Feature> &a, const string &name) 
{
	cout << name << " contains: " << endl;
	for(int j=0;j<a.size();j++)
		cout << a[j] << "\n";
}
