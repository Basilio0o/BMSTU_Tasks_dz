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
	cout << "ВЫБЕРИТЕ СОРТИРОВКУ" << endl;
	cout << "1. По цене (от дешевых к дорогим)" << endl;
	cout << "2. По цене (от дорогих к дешевым)" << endl;
	cout << "3. По названию (алфавитный порядок)" << endl;
	cout << "4. По количеству (от большего к меньшему)" << endl;
	cout << "5. По количеству (от меньшего к большему)" << endl;
}

int main()
{
	string FileName = "products.csv";
	string FileName2 = "sorted_products.csv";
	vector<Product> products = ReadCSV(FileName);
	vector<Product> filteredProducts;
	Menu();
	int choice;
	cout << "Ваш выбор: ";
	cin >> choice;

	switch(choice){
		case 1: {
			auto condition = [](const Product& a, const Product& b){return a.price < b.price;};
			sort(products.begin(), products.end(), condition);
			cout << "Сортировка завершилась успешно" << endl;
			break;
		}

		case 2: {
			auto condition = [](const Product& a, const Product& b){return a.price > b.price;};
			sort(products.begin(), products.end(), condition);
			cout << "Сортировка завершилась успешно" << endl;
			break;
		}

		case 3: {
			auto condition = [](const Product& a, const Product& b){return a.name < b.name;};
			sort(products.begin(), products.end(), condition);
			cout << "Сортировка завершилась успешно" << endl;
			break;
		}

		case 4: {
			auto condition = [](const Product& a, const Product& b){return a.quantity > b.quantity;};
			sort(products.begin(), products.end(), condition);
			cout << "Сортировка завершилась успешно" << endl;
			break;
		}

		case 5: {
			auto condition = [](const Product& a, const Product& b){return a.quantity < b.quantity;};
			sort(products.begin(), products.end(), condition);
			cout << "Сортировка завершилась успешно" << endl;
			break;
		}

		default: {
			cout << "Неверный выбор. Сортировка не производится." << endl;
		}
	}
	WriteCSV(products,FileName2);
	return 0;
}

