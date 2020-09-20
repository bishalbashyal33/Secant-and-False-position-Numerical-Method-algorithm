/* Write algorithm / pseudocode and program code in C / C++
to determine a real root of anon - linear equation using:
a) Secant method.
b) False Position methodCheck your program for the following
equationsand show the corresponding outputs :
•x3−3x2 + 2x−2 = 0•xsin(x) + cos(x) = 0•x2 + 4x + 5 = 015*/

#include <iostream>
#include<cmath>
#define maxIterations 1000
using namespace std;
bool checker(double, double);
double rootCalc(double, double, double);
double rootCalc2(double, double, double);
double f(double);

int main() {
	double a = 0, b = 0, e;
	cout << "Enter tolerance: ";
	cin >> e;
	while (!checker(a,b))
	{

		cout << "Re/Enter a and b interval limits for the equation: ";
		cin >> a;
		cin >> b;
	}
	try
	{
		cout << "The root using secant method is" << rootCalc(a, b, e)<<endl;
		cout << "The root using false position method is" << rootCalc2(a, b, e)<<endl;
	}
	catch (const char err)
	{
		cout << err;
	}
	
}

bool checker(double a, double b) {
	return ((f(a) * f(b)) < 0);
}

double f(double x) {
	return(pow(x, 3) - (3 * pow(x, 2)) + (2 * x) - 2);
}

double rootCalc(double a, double b, double e) {
	double root;
	int n = 0;
	do
	{
		root = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
		a = b;
		b = root;
		n++;

		if (n > maxIterations) {
			throw "Solution did not converge in " + maxIterations;
		}

	} while (fabs(f(root)) >= e);
	return root;

}

double rootCalc2(double a, double b, double e) {
	double root;
	int n = 0;
	do
	{
		root = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
		if (checker(root, a))
			a = root;
		else
			b = root;
		n++;

		if (n > maxIterations) {
			throw "Solution did not converge in " + maxIterations;
		}

	} while (fabs(f(root)) >= e);
	return root;

}