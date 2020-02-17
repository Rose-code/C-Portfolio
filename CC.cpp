#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

ofstream outFile;

class Circle
{
private:
	double radius, pi;

public:
	void setRadius();
	double getRadius(double val);
	double getArea();
	double getDiameter();
	double getCircumference();
};

void Circle::setRadius()
{
	radius = 0;
	pi = 3.14159;
	return;
}

double Circle::getRadius(double val)
{
	radius = val;
	return radius;
}

double Circle::getArea()
{
	return pi * radius * radius;
}

double Circle::getDiameter()
{
	return radius * 2;
}

double Circle::getCircumference()
{
	return 2 * pi * radius;
}

int main()
{
	outFile.open("Circlesss.txt");

	Circle c1, c2, c3;
	double circle1, circle2, circle3;

	cout << "What is the radius of circle one? ";
	cin >> circle1;
	c1.setRadius();
	outFile << setprecision(2) << fixed;
	outFile << "Circle One" << endl;
	outFile << "Radius - " << c1.getRadius(circle1) << endl;
	outFile << "Area - " << c1.getArea() << endl;
	outFile << "Diameter - " << c1.getDiameter() << endl;
	outFile << "Circumference - " << c1.getCircumference() << endl << endl;

	cout << "What is the radius of circle two? ";
	cin >> circle2;
	c2.setRadius();
	outFile << "Circle Two" << endl;
	outFile << "Radius - " << c2.getRadius(circle2) << endl;
	outFile << "Area - " << c2.getArea() << endl;
	outFile << "Diameter - " << c2.getDiameter() << endl;
	outFile << "Circumference - " << c2.getCircumference() << endl << endl;

	cout << "What is the radius of circle three? ";
	cin >> circle3;
	c3.setRadius();
	outFile << "Circle Three" << endl;
	outFile << "Radius - " << c3.getRadius(circle3) << endl;
	outFile << "Area - " << c3.getArea() << endl;
	outFile << "Diameter - " << c3.getDiameter() << endl;
	outFile << "Circumference - " << c3.getCircumference() << endl;

	outFile.close();

	return 0;
}
