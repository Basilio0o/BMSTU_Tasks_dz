#include <iostream>

using namespace std;

union Variant {
	int i;
	double d;
	char c;
};

int main()
{
	Variant var;
	char choice;
	cout << "Выберите тип данных (i - целое число, d - число с плавающей запятой, c - символ): ";
	cin >> choice;
	if(choice == 'i'){
		cout << "Введите целое число: ";
		cin >> var.i;
		cout << "Вы ввели: " << var.i;
	}else if(choice == 'd'){
		cout << "Введите число с плавающей запятой: ";
		cin >> var.d;
		cout << "Вы ввели: " << var.d;
	}else if(choice == 'c'){
		cout << "Введите символ: ";
		cin >> var.c;
		cout << "Вы ввели: " << var.c;
	}else{
		cout << "Ошибка. Неверный выбор типа данных" << endl;
	}
	return 0;
}
