#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int n = 0;
	cout << "Enter the length of the string\n";
	cin >> n;

	cin.ignore();

	cout << "Enter the string\n";
	char* pld = new char[n+1];
	cin.getline(pld, n+1);
	cout << "Your string is " << pld << endl;
	for(int i = 0; i < n+1; i++) if(pld[i] >= 'A' and pld[i] <= 'Z') pld[i] = tolower(pld[i]);
	int l = 0, r = n-1;
	while(l <= r)
	{
		while(l <= r && isspace(pld[l])) l++;
		while(l <= r && isspace(pld[r])) r--;
		char a = pld[l];
		char b = pld[r];
		if(a != b)
		{
			cout << "\nNot palindrom";
			delete[] pld;
			return 0;
		}
		l++;
		r--;
	}
	cout << "\nPalindrom";
	delete[] pld;
	return 0;
}
