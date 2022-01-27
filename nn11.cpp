#include "mat.h"
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double f(double x) { return (tanh(x)); };

int main()
{
	int nrows=1, ncols=16;
	double input_matrix[nrows * ncols];
    for(int i = 0; i < nrows * ncols; i++)
	{
		cin >> input_matrix[i];
	}

	Matrix xb(1, 16, input_matrix);
    Matrix weights(16, 4);
    initRand();
    weights.rand(-5.0, 5.0);


	int epochs = 100;
	Matrix y, delta;
	double eta = 0.1;


 	for(int i = 0; i < epochs; i++)
	{
		y = xb.dot(weights);
		y.map(f);
		delta = xb.transpose().dot(y).scalarMul(eta);
		weights = weights.sub(delta);
	}


	double printer;
	for(int i = 0; i < 4; i++)
	{
        printer = y.get(0, i);
        cout<<printer<<" ";
		cout<<endl;
	}
	return 0;
}
