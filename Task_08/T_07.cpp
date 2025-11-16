#include <iostream>
#include <memory>
#include <cctype>

using namespace std;

bool isVowel(char c, const char* vowels){
    for(int j = 0; vowels[j] != '\0'; j++){
        if(vowels[j] == c) return true;
    }
    return false;
}

int main(){
	int n = 100;
	cout << "Введите строку: ";
	unique_ptr<char[]> str = make_unique<char[]>(n);
	cin.getline(str.get(), n);
	const char* vowels = "AEIOUYaeiouy";
	int count_vowels = 0;
	int count_consonants = 0;

	for(int i = 0; str[i] != '\0'; i++){
		if(isalpha(str[i])){
			if(isVowel(str[i], vowels)) count_vowels++;
			else count_consonants++;
		}
	}
	int k = 0;
	unique_ptr<char[]> str_vowels = make_unique<char[]>(count_vowels+1);
	for(int i = 0; str[i] != '\0'; i++){
		if(isalpha(str[i])){
			if(isVowel(str[i], vowels)) str_vowels[k++] = str[i];
		}
	}
	str_vowels[k] = '\0';
	cout << "Количество гласных букв: " << count_vowels << endl;
	cout << "Количество согласных букв: " << count_consonants << endl;
	cout << str_vowels.get() << endl;
	return 0;
}
