#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

int main(){
	int n, m;
	cout << "Ввведите размеры массива: ";
	cin >> n >> m;
	unique_ptr<int[]> array = make_unique<int[]>(n*m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			array[i*m + j] = i*j;
			cout << setw(4) << array[i*m + j];
		}
		cout << endl;
	}
	return 0;
}
