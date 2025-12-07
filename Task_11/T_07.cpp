#include <iostream>
#include <string>
using namespace std;

union DateTime {
    struct {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    };

    int values[6];

    void input() {
    	cout << "Введите год: ";
		cin >> values[0];
		cout << "Введите месяц: ";
		cin >> values[1];
		cout << "Введите день: ";
		cin >> values[2];
		cout << "Введите час: ";
		cin >> values[3];
		cout << "Введите минуту: ";
		cin >> values[4];
		cout << "Введите секунду: ";
		cin >> values[5];
    }

    void print() {
        cout << year << "-" << month << "-" << day << " "
             << hour << ":" << minute << ":" << second;
    }
};

int main()
{
	DateTime dt;
	dt.input();
	dt.print();
	return 0;
}
