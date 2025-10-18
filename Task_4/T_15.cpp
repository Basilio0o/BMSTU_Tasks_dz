#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <math.h>

using namespace std;
int main()
{
	srand(time(0));
	vector<vector<double>> temp(5, vector<double>(30));
	vector<vector<double>> pressure(5, vector<double>(100));

	vector<double> tempsr(5);
	vector<vector<double>> mnmxpres(5, vector<double>(2));

	vector<vector<double>> dtemp(5, vector<double>(29));
	vector<vector<double>> dpressure(5, vector<double>(99));

	vector<vector<double>> normalpressure(5, vector<double>(100));

	double mxd = 0;
	int channelmx = 0;

	for(int i = 0; i < 5; i++) generate(temp[i].begin(), temp[i].end(), [](){return (rand() % 57 - 20 + (double)(rand() % 41)/10.0);});
	for(int i = 0; i < 5; i++) generate(pressure[i].begin(), pressure[i].end(), [](){return (rand() % 11 + 1 + (double)(rand() % 11)/10.0);});

	for(int i = 0; i < 5; i++)
	{
		cout << i+1 << "\npressure ";
		for_each(pressure[i].begin(), pressure[i].end(), [](double x){cout << x << " ";});
		cout << "\ntemperature ";
		for_each(temp[i].begin(), temp[i].end(), [](double x){cout << x << " ";});
		cout << "\n";
	}

	transform(temp.begin(), temp.end(), tempsr.begin(), [](const vector<double>& channel){return accumulate(channel.begin(), channel.end(), 0.0)/30.0;});

	for(int i = 0; i < 5; i++)
	{
		auto mn = min_element(pressure[i].begin(), pressure[i].end());
		auto mx = max_element(pressure[i].begin(), pressure[i].end());
		mnmxpres[i][0] = *mn;
		mnmxpres[i][1] = *mx;
	}

	for(int i = 0; i < 5; i++)
	{
		transform(temp[i].begin()+1, temp[i].end(), temp[i].begin(), dtemp[i].begin(), [](double a, double b){return b - a;});
		transform(pressure[i].begin()+1, pressure[i].end(), pressure[i].begin(), dpressure[i].begin(), [](double a, double b){return b - a;});
	}
	for(int i = 0; i < 5; i++)
	{
		if(mxd < dtemp[i][1] - dtemp[i][0]) mxd = dtemp[i][1] - dtemp[i][0];
		channelmx = i + 1;
	}
	cout << "\nThe number of the channel with max range of temperature is " << channelmx << endl;
	for(int i = 0; i < 5; i++) transform(pressure[i].begin(), pressure[i].end(), normalpressure[i].begin(), [&mnmxpres, i](double x){return (x - mnmxpres[i][0]) / (mnmxpres[i][1] - mnmxpres[i][0]);});
	cout << "Normalized pressure values ​​above 0.9:\n";
	for(int i = 0; i < 5; i++) for_each(normalpressure[i].begin(), normalpressure[i].end(), [](double x){if(x > 0.9) cout << setprecision(2) << x << " ";});


	auto mxtp = max_element(tempsr.begin(), tempsr.end());
	sort(tempsr.begin(), tempsr.end());
	cout << "\nSorted average temperatures: ";
	for_each(tempsr.begin(), tempsr.end(), [](double x){cout << setprecision(3) << x << " ";});

	cout << "\nThe number of the channel with max temperature is " << mxtp - tempsr.begin() + 1;

	return 0;
}
