#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cout << "Введите размеры матрицы: ";
	cin >> n >> m;

	unique_ptr<double[]> matrix(new double[n*m]);


	cout << "Заполните матрицу:" << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> matrix[i*m + j];
	}

	auto sumColumns = [](const unique_ptr<double[]>& matrix, int n, int m){
		vector<double> sum(m);
		for(int j = 0; j < m; j++){
			double sm = 0.0;
			for(int i = 0; i < n; i++) sm += matrix[i*m + j];
			sum[j] = sm;
		}
		return sum;
	};

	auto maxIndex = [](const vector<double>& sum, int m){
		int mxidx = 0;
		double mx = sum[0];
		for(int i = 1; i < m; i++){
			if(sum[i] > mx){
				mx = sum[i];
				mxidx = i;
			}
		}
		return mxidx;
	};

	vector<double> sum = sumColumns(matrix, n, m);

	int index_max = maxIndex(sum, m);

	double mx = sum[index_max];

	cout << "Суммы столбцов: [" << sum[0];
	for(int i = 1; i < m; i++) cout << ", " << sum[i];
	cout << "]" << endl;
	cout << "Столбец с максимальной суммой: " << index_max+1 << " (" << mx << ")";

	return 0;
}
