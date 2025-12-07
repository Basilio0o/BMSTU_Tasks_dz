#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Circle{
	double r;
	double area(){
        return M_PI * r * r;
    }
};

struct Rectangle{
	double h;
	double w;
	double area(){
		return h*w;
	}
};

union Shape{
	Circle shape1;
	Rectangle shape2;
};

int main()
{
	Shape shape;
	int choice;
	cout << "Выберите фигуру (1 - круг, 2 - прямоугольник): ";
	cin >> choice;
	if(choice == 1){
		cout << "Введите радиус круга: ";
		cin >> shape.shape1.r;
		cout << "Площадь круга: " << fixed << setprecision(2) << shape.shape1.area() << endl;
	}else if(choice == 2){
		cout << "Введите длину прямоугольника: ";
		cin >> shape.shape2.h;
		cout << "Введите ширину прямоугольника: ";
		cin >> shape.shape2.w;
		cout << "Площадь прямоугольника: " << fixed << setprecision(2) << shape.shape2.area() << endl;
	}
	return 0;
}
