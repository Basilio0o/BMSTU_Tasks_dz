#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee{
	string name;
	int age;
	string job_title;
	int salary;
};

void AddEmployee(vector<Employee>& employees){
	Employee newemployee;
	cout << "Введите имя сотрудника: ";
	cin >> newemployee.name;
	cout << "Введите возраст сотрудника: ";
	cin >> newemployee.age;
	cout << "Введите должность сотрудника: ";
	cin >> newemployee.job_title;
	cout << "Введите зарплату сотрудника: ";
	cin >> newemployee.salary;
	employees.push_back(newemployee);
}

int main()
{
	int n;
	cout << "Введите количество сотрудников: ";
	cin >> n;
	vector<Employee> employees;
	for(int i = 0; i < n; i++){
		AddEmployee(employees);
	}

	int mx = 0;
	int mn = employees[0].age;
	int total_salary = 0;
	Employee young_em, old_em;
	for(size_t i = 0; i < employees.size(); i++){
		if(mn > employees[i].age){
			mn = employees[i].age;
			young_em = employees[i];
		}
		if(mx < employees[i].age){
			mx = employees[i].age;
			old_em = employees[i];
		}
		total_salary += employees[i].salary;
	}

	cout << "Самый молодой сотрудник: " << young_em.name << ", возраст: " << young_em.age <<
			", должность: " << young_em.job_title << ", зарплата: " << young_em.salary << endl;
	cout << "Самый старший сотрудник: " << old_em.name << ", возраст: " << old_em.age <<
			", должность: " << old_em.job_title << ", зарплата: " << old_em.salary << endl;
	cout << "Средняя зарплата всех сотрудников: " << (double)total_salary / n;

	return 0;
}
