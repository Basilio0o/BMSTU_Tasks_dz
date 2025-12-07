#include <iostream>
#include <string>

using namespace std;

class Publication {
public:
	string title;

};

class Book : public Publication {
private:
	string author;
	int year;
public:
	Book (string t, string a, int y){
		title = t;
		author = a;
		year = y;
	}
	void displayInfo(){
		cout << "Название: " << title << ", Автор: " << author << ", Год выпуска: " << year << endl;
	}
};

int main()
{
	string title = "Евгений Онегин";
	string author = "A. C. Пушкин";
	int year = 1833;
	Book book(title, author, year);
	book.displayInfo();

	return 0;
}
