#pragma once
#include <iostream>
#include <string>

class Student {
private:
	std::string fio;
	int kyrs;
	int grup;
	int points[3];  // ������

public:
	//������������, �������������
	Student();
	Student(std::string name, int k, int gr, int* p);  
	// p ����� 3 ��������
	// ���� ������ >100 - ������� 100
	// ���� < 0 - ������� 0
	Student(const Student& other);
	~Student() {};

	//cin, cout
	friend std::ostream& operator << (std::ostream& out, const Student& st);
	friend std::istream& operator >> (std::istream& in, Student& st);

	//������
	std::string get_fio();
	int get_kyrs();
	int get_grup();
	int* get_points();

	void set_fio(std::string f);
	void set_kyrs(int k);
	void set_grup(int gr);
	void set_points(int* p);

	void rating();  // ����� ��������� � ������
	bool check_exam(int n);  // ���� �� �������?

	//���������
	Student& operator = (const Student& stud);
	bool operator == (const Student& stud);
	bool operator < (const Student& stud);
};

void list(Student* array, int size);
Student * commission(Student * array, int& size);
