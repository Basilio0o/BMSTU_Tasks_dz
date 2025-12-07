#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Product{
	int id;
	string name;
	string category;
	int price;
	int quantity;
};

vector<Product> Generation(int n){
	vector<string> Names = {
		"Ноутбук", "Смартфон", "Планшет", "Наушники", "Клавиатура",
		"Монитор", "Принтер", "Сканер", "Роутер", "Флешка",
		"Мышь", "Коврик", "Колонки", "Микрофон", "Веб-камера",
		"Чехол", "Зарядка", "Кабель", "Адаптер", "Док-станция"
	};
	vector<string> Categories = {
			"Электроника", "Аксессуары", "Геймерские дивайсы", "Умные устройства"
	};
	srand(time(0));
	vector<Product> Products(n);
	for(int i = 0; i < n; i++){
		Products[i].id = i + 1;
		Products[i].name = Names[rand() % Names.size()];
		Products[i].category = Categories[rand() % Categories.size()];
		Products[i].price = 100 + (rand() % 9901);
		Products[i].quantity = 1 + (rand() % 100);
	}
	return Products;
}

int main()
{
	int count = 0;
	vector<Product> products = Generation(20);
	string FileName = "products.csv";
	ofstream outFile(FileName);
	if(!outFile.is_open()){
		cerr << "Не удалось открыть файл" << endl;
		return 1;
	}
	outFile << "id,name,category,price,quantity" << endl;
	for(Product i : products){
		outFile << i.id << "," << i.name << "," << i.category << "," << i.price << "," << i.quantity << endl;
	}
	cout << "Данные успешно записаны" << endl;
	outFile.close();
	ifstream inFile(FileName);
	if(!inFile.is_open()){
		cerr << "Не удалось открыть файл" << endl;
		return 1;
	}
	string line;
	while(getline(inFile, line)) count++;
	if(count == 21){
		cout << "Всё в порядке" << endl;
	}
	inFile.close();
	return 0;
}
