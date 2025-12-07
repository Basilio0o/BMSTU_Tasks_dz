#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	double length;
	void displayInfo(){
		cout << "Длина: " << length << endl;
	}
};

class Rectangle  : public Shape {
public:
	double width;
	Rectangle (double l, double w){
		length = l;
		width = w;
	}
	double calculateArea(){
		return length*width;
	}
	double calculatePerimeter(){
		return 2*(length + width);
	}
	void displayInfo(){
		cout << "Длина: " << length << ", Ширина: " << width
				<< ", Площадь: " << calculateArea()
				<< ", Периметр: " << calculatePerimeter() << endl;
	}
};

int main()
{
	double l = 5.4;
	double w = 7.6;
	Rectangle rectangle(l, w);
	rectangle.displayInfo();
	return 0;
}
