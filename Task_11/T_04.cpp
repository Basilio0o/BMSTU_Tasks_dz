#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
	string title;
	string author;
	string year;
	string genre;
};

struct Library {
	vector<Book> books;
	int count;
};

void AddBook(Library& library){
    Book newBook;
    cin.ignore();
    cout << "Введите название книги: ";
    getline(cin, newBook.title);
    cout << "Введите автора книги: ";
    getline(cin, newBook.author);
    cout << "Введите год издания: ";
    cin >> newBook.year;
    cin.ignore();
    cout << "Введите жанр книги: ";
    getline(cin, newBook.genre);

    library.books.push_back(newBook);
    library.count = library.books.size();
    cout << "Книга добавлена в библиотеку." << endl;
}

void RemoveBook(Library& library){
    string title;
    cin.ignore();
    cout << "Введите название книги для удаления: ";
    getline(cin, title);
    bool f = true;
    for(auto it = library.books.begin(); it != library.books.end(); ++it){
        if (it->title == title) {
            library.books.erase(it);
            library.count = library.books.size();
            cout << "Книга \"" << title << "\" удалена из библиотеки." << endl;
            f = false;
            break;
        }
    }

    if(f){
        cout << "Книга с названием \"" << title << "\" не найдена." << endl;
    }
}

void SearchByAuthor(Library& library){
    string author;
    cin.ignore();
    cout << "Введите автора для поиска: ";
    getline(cin, author);

    bool f = true;
    cout << "\nНайденные книги автора " << author << ":" << endl;

    for (const Book& book : library.books) {
        if (book.author == author) {
            cout << "Название: " << book.title
            << ", год издания: " << book.year << ", жанр: " << book.genre << endl;
            f = false;
        }
    }

    if (f){
        cout << "Книги автора " << author << " не найдены." << endl;
    }
}

void ShowAllBooks(Library& library) {
    if (library.books.empty()) {
        cout << "Библиотека пуста" << endl;
        return;
    }

    cout << "\n=== ВСЕ КНИГИ В БИБЛИОТЕКЕ ===" << endl;
    cout << "Всего книг: " << library.count << endl;
    cout << endl;

    for(const Book& book : library.books){
        cout << "Название: " << book.title
        << ", год издания: " << book.year << ", жанр: " << book.genre << endl;
    }
}

void Menu(){
	cout << "Выберите действие:" << endl;
	cout << "1. Добавить книгу" << endl;
	cout << "2. Удалить книгу" << endl;
	cout << "3. Найти книгу по автору" << endl;
	cout << "4. Вывести список книг" << endl;
	cout << "5. Выйти" << endl;
	cout << "Ваш выбор: ";
}

int main()
{
	int choice;
	Library library;
	library.count = 0;
	do {
		Menu();
		cin >> choice;
		switch (choice) {
			case 1 : {
				AddBook(library);
				break;
			}
			case 2 : {
				RemoveBook(library);
				break;
			}
			case 3 : {
				SearchByAuthor(library);
				break;
			}
			case 4 : {
				ShowAllBooks(library);
				break;
			}
			case 5 : {
				cout << "Выход из программы" << endl;
				break;
			}
			default : {
				cout << "Программа завершена." << endl;
				return 1;
			}

		}
	} while(choice != 5);
	return 0;
}
