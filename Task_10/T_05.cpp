#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Student{
	int id;
	char name[50];
	int age;
	double average_grade;
};

void OutputIntoFile(const vector<Student>& Students, const string& FileName){

	ofstream outFile(FileName, ios::binary);

	if(outFile.is_open()){

		size_t size = Students.size();
		outFile.write(reinterpret_cast<char* >(&size), sizeof(size));
		outFile.write(reinterpret_cast<const char*>(Students.data()), size * sizeof(Student));
		outFile.close();

	}else{
		cerr << "Ошибка! Не удалось открыть файл для записи" << endl;
	}
}

vector<Student> InputFromFile(const string& FileName){
	vector<Student> Stud;

	ifstream inFile(FileName, ios::binary);

	if(inFile.is_open()){

		inFile.seekg(0, ios::end);
        size_t size = inFile.tellg();
        inFile.seekg(0, ios::beg);
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
		Stud.resize(size);
		inFile.read(reinterpret_cast<char*>(Stud.data()), size * sizeof(Student));

		inFile.close();
	}else{
		cerr << "Ошибка! Не удалось открыть файл для чтения" << endl;
	}
	return Stud;
}

int main()
{
	double mx_mark = 0.0;
	Student std;
	string FileName = "students.dat";
	vector<Student> Students = {{1, "Иван Петров", 20, 4.5}, {2, "Мария Сидорова", 19, 4.8},
			{3, "Алексей Иванов", 21, 4.2}};
	OutputIntoFile(Students, FileName);
	vector<Student> Stud = InputFromFile(FileName);
	for(Student i : Stud){
		if(mx_mark < i.average_grade){
			mx_mark = i.average_grade;
			std = i;
		}
		cout << i.id << " " <<
				i.name << " " <<
				i.age << " " <<
				i.average_grade << endl;
	}
	cout << "Студент с самым высоким средним баллом: " << std.name << " (" <<
			std.average_grade << ")" << endl;
	cout << "Общее количество студентов в файле: " << Stud.size() << endl;

	return 0;
}
