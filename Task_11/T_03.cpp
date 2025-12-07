#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BankAccount{
	int number;
	string name;
	double balance;
};

void NewAccount(vector<BankAccount>& bankAccounts){
	BankAccount newacc;
	cout << "Введите номер счёта: ";
	cin >> newacc.number;
	cin.ignore();
	cout << "Введите имя владельца счёта: ";
	getline(cin, newacc.name);
	newacc.balance = 0.0;
	cout << "Банковский счет создан." << endl;
	bankAccounts.push_back(newacc);
}

void UpBalance(vector<BankAccount>& bankAccounts){
	int num;
	double summa;
	cout << "Введите номер счета для пополнения: ";
	cin >> num;
	cout << "Введите сумму для пополнения: ";
	cin >> summa;
	bool f = true;
	for(BankAccount& i : bankAccounts){
		if(i.number == num){
			i.balance += summa;
			cout << "Счёт пополнен на " << summa << " рублей." << endl;
			f = false;
			break;
		}
	}
	if(f) cout << "Счёт не найден" << endl;
}

void DownBalance(vector<BankAccount>& bankAccounts){
	int num;
	double summa;
	char ch;
	cout << "Введите номер счета для снятия: ";
	cin >> num;
	cout << "Введите сумму для снятия: ";
	cin >> summa;
	bool f = true;
	for(BankAccount& i : bankAccounts){
		if(i.number == num){
			if(i.balance < summa){
				cout << "На счёте меньше денег, чем требуется для снятия." << endl;
				cout << "Снять все имеющиеся деньги?(y/n)" << endl;
				cin >> ch;
				if(ch == 'y'){
					cout << "Со счёта снято " << i.balance << " рублей." <<endl;
					i.balance = 0;
				}else if(ch == 'n'){
					cout << "Операция отменена" << endl;
				}else{
					cout << "Ошибка. Операция отклонена" << endl;
				}
			}else{
				cout << "Со счёта снято " << summa << " рублей." << endl;
				cout << "Осталось " << i.balance - summa << " рублей." << endl;
				i.balance -= summa;
 			}
			f = false;
			break;
		}
	}
	if(f) cout << "Счёт не найден" << endl;
}

void ShowInfo(vector<BankAccount>& bankAccounts){
	int num;
	cout << "Введите номер счета: ";
	cin >> num;
	bool f = true;
	for(BankAccount& i : bankAccounts){
		if(i.number == num){
			cout << "Номер счёта " << i.number << ", имя владельца " << i.name
					<< ", баланс " << i.balance << " рублей." << endl;
			f = false;
		}
	}
	if(f) cout << "Счёт не найден" << endl;
}

void Menu(){
	cout << "Выберите действие:" << endl;
	cout << "1. Создать новый банковский счет" << endl;
	cout << "2. Пополнить счет" << endl;
	cout << "3. Снять деньги со счета" << endl;
	cout << "4. Показать информацию о счете" << endl;
	cout << "5. Выйти" << endl;
	cout << "Ваш выбор: ";
}

int main()
{
	int choice;
	vector<BankAccount> bankAccounts;
	do {
		Menu();
		cin >> choice;
		switch (choice) {
			case 1 : {
				NewAccount(bankAccounts);
				break;
			}
			case 2 : {
				UpBalance(bankAccounts);
				break;
			}
			case 3 : {
				DownBalance(bankAccounts);
				break;
			}
			case 4 : {
				ShowInfo(bankAccounts);
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
