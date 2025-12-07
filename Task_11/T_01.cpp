#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student{
	string name;
	int age;
	double average_grade;
	int number;
};

vector<Student> AddStudent(vector<Student> students, Student stud){
	vector<Student> students_update = students;
	students_update.push_back(stud);
	return students_update;
}

void Output(vector<Student> students){
	for(Student i : students){
		cout << i.name << ", " << i.age << ", " << i.average_grade << ", " << i.number << endl;
	}
}

Student FindStudent(vector<Student> students, int num){
	Student stud = {"-", 0, 0, 0};
	bool f = true;
	for(Student i : students){
		if(i.number == num){
			stud = i;
			f = false;
			break;
		}
	}
	if(f){
		cout << "Студент не найден" << endl;
	}
	return stud;
}

void FindStudents(vector<Student> students, double mark){
	for(Student i : students){
		if(i.average_grade > mark){
			cout << i.name << ", " << i.age << ", " << i.average_grade << ", " << i.number << endl;
		}
	}
}

int main()
{
	vector<Student> students = {{"Петров Иван Дмитриевич", 20, 4.5, 153225},
			{"Сидорова Мария Олеговна", 19, 4.8, 463254}, {"Иванов Алексей Романович", 21, 4.2, 912354}};
	vector<Student> students_new = AddStudent(students, {"Грубый Максим Полуэктович", 21, 3.9, 261422});
	Output(students_new);

	cout << endl;
	int num = 463255;
	double mark = 4.3;
	Student fd = FindStudent(students_new, num);
	if(fd.name != "-"){
		cout << fd.name << ", " << fd.age << ", " << fd.average_grade << ", " << fd.number << endl;
	}
	cout << endl;
	FindStudents(students_new,mark);
	return 0;
}
