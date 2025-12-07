#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

struct Product{
	int id;
	string name;
	string category;
	int price;
	int quantity;
};

vector<Product> ReadCSV(string FileName){
	vector<Product> products;
	ifstream inFile(FileName);
	if(!inFile.is_open()){
	cerr << "Не удалось открыть файл" << endl;
	return products;
	}
	Product prod;
	string line;
	string word;
	getline(inFile, line);
	while(getline(inFile, line)){
		istringstream ss(line);
		getline(ss, word, ',');
		prod.id = stoi(word);
		getline(ss, word, ',');
		prod.name = word;
		getline(ss, word, ',');
		prod.category = word;
		getline(ss, word, ',');
		prod.price = stoi(word);
		getline(ss, word, ',');
		prod.quantity = stoi(word);
		products.push_back(prod);
	}
	inFile.close();
	return products;
}

void WriteCSV(const vector<Product>& products, string FileName){
	ofstream outFile(FileName);
	if(!outFile.is_open()){
		cerr << "Не удалось открыть файл" << endl;
	}
	outFile << "id,name,category,price,quantity" << endl;
	for(Product i : products){
		outFile << i.id << "," << i.name << "," << i.category << "," << i.price << "," << i.quantity << endl;
	}
}

void Menu(){
	cout << "ВЫБЕРИТЕ ТИП ФИЛЬТРА" << endl;
	cout << "1. По цене (дороже указанной)" << endl;
	cout << "2. По цене (дешевле указанной)" << endl;
	cout << "3. По категории" << endl;
	cout << "4. По количеству (больше указанного)" << endl;
	cout << "5. По количеству (меньше указанного)" << endl;
}

int main()
{
	string FileName = "products.csv";
	string FileName2 = "filtered_products.csv";
	vector<Product> products = ReadCSV(FileName);
	vector<Product> filteredProducts;
	Menu();
	int choice;
	cout << "Ваш выбор: ";
	cin >> choice;

	switch(choice){
		case 1: {
			int minPrice;
			cout << "Введите минимальную цену: ";
			cin >> minPrice;
			auto filter = [minPrice](const Product& p){return p.price > minPrice;};
			copy_if(products.begin(), products.end(),back_inserter(filteredProducts), filter);
			cout << "Найдено товаров дороже " << minPrice << " руб.: " << filteredProducts.size() << endl;
			break;
		}

		case 2: {
			int maxPrice;
			cout << "Введите максимальную цену: ";
			cin >> maxPrice;
			auto filter = [maxPrice](const Product& p){return p.price < maxPrice;};
			copy_if(products.begin(), products.end(),back_inserter(filteredProducts), filter);
			cout << "Найдено товаров дешевле " << maxPrice << " руб.: " << filteredProducts.size() << endl;
			break;
		}

		case 3: {
			string category;
			cout << "Введите категорию: ";
			cin.ignore();
			getline(cin, category);
			auto filter = [category](const Product& p){return p.category == category;};
			copy_if(products.begin(), products.end(),back_inserter(filteredProducts), filter);
			cout << "Найдено товаров в категории " << category << ": " << filteredProducts.size() << endl;
			break;
		}

		case 4: {
			int minQuantity;
			cout << "Введите минимальное количество: ";
			cin >> minQuantity;
			auto filter = [minQuantity](const Product& p){return p.quantity > minQuantity;};
			copy_if(products.begin(), products.end(),back_inserter(filteredProducts), filter);
			cout << "Найдено товаров больше " << minQuantity << ": " << filteredProducts.size() << endl;
			break;
		}

		case 5: {
			int maxQuantity;
			cout << "Введите максимальное количество: ";
			cin >> maxQuantity;
			auto filter = [maxQuantity](const Product& p){return p.quantity < maxQuantity;};
			copy_if(products.begin(), products.end(),back_inserter(filteredProducts), filter);
			cout << "Найдено товаров меньше " << maxQuantity << ": " << filteredProducts.size() << endl;
			break;
		}

		default: {
			cout << "Неверный выбор. Используется фильтр по умолчанию (все товары)." << endl;
			auto filter = [](const Product&){return true;};
			copy_if(products.begin(), products.end(),back_inserter(filteredProducts), filter);
		}
	}
	WriteCSV(filteredProducts,FileName2);
	return 0;
}

