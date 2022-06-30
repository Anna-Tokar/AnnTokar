#pragma once
#include <iostream>
#include <string>

class Student {
private:
	std::string fio;
	int kyrs;
	int grup;
	int points[3];  // оценки

public:
	//конструкторы, деконструктор
	Student();
	Student(std::string name, int k, int gr, int* p);  
	// p берет 3 значения
	// если баллов >100 - оставит 100
	// елси < 0 - выведет 0
	Student(const Student& other);
	~Student() {};

	//cin, cout
	friend std::ostream& operator << (std::ostream& out, const Student& st);
	friend std::istream& operator >> (std::istream& in, Student& st);

	//методы
	std::string get_fio();
	int get_kyrs();
	int get_grup();
	int* get_points();

	void set_fio(std::string f);
	void set_kyrs(int k);
	void set_grup(int gr);
	void set_points(int* p);

	void rating();  // баллы переводит в оценки
	bool check_exam(int n);  // сдал ли экзамен?

	//операторы
	Student& operator = (const Student& stud);
	bool operator == (const Student& stud);
	bool operator < (const Student& stud);
};

void list(Student* array, int size);
Student * commission(Student * array, int& size);
