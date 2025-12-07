#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

struct Product{
	int id;
	string name;
	string category;
	int price;
	int quantity;
};

int main()
{
	int count = 0;
	int cost = 0;
	int mx = 0;
	int mn = 10001;
	string FileName = "products.csv";
	vector<Product> products;
	ifstream inFile(FileName);
	if(!inFile.is_open()){
		cerr << "Не удалось открыть файл" << endl;
		return 1;
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
		count += prod.quantity;
		cost += prod.price * prod.quantity;
		if(mn > prod.price) mn = prod.price;
		if(mx < prod.price) mx = prod.price;
	}
	inFile.close();
	for(Product i : products){
        cout << setw(2) << i.id << " | " << i.name << " | " << i.category << " | " << i.price << " | "
        		<< i.quantity << endl;
	}
	cout << "\n\n";
	cout << "Общее количество товаров на складе: " << count << endl;
	cout << "Cуммарную стоимость всех товаров: " << cost << endl;
	cout << "Cамый дорогой товар: " << mx << endl;
	cout << "Самый дешёвый товар: " << mn << endl;
	return 0;
}
