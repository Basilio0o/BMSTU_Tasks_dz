#include <iostream>
#include <cstring>

using namespace std;

void SortStr(char **words, int n)
{
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(strcmp(words[j], words[j+1]) > 0){
				char *tpptr = words[j];
				words[j] = words[j+1];
				words[j+1] = tpptr;
			}
		}
	}
}

int main()
{
	int n, w;
	cout << "Введите кол-во слов: ";
	cin >> n;
	char **words = new char*[n];
	cout << "Введите максимальный размер слова: ";
	cin >> w;
	char str[1000];
	for(int i = 0; i < n; i++) words[i] = new char[w+1];
	cout << "Вводите слова через пробел:" << endl;
	cin.ignore();
	cin.getline(str, 1000);
	const char delimiters[] = " ";
	char* token = strtok(str, delimiters);
	int count = 0;
	for(int i = 0; i < n && token != nullptr; i++)
	{
		words[i] = new char[w+1];
		strcpy(words[i], token);
		token = strtok(nullptr, delimiters);
		count++;
	}
	SortStr(words, count);
	for(int i = 0; i < count; i++)
		cout << words[i] << " ";
	for(int i = 0; i < count; i++) delete[] words[i];
	delete[] words;
	return 0;
}
