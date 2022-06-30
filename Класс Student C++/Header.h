#pragma once
#include <iostream>
#include <string>

class Student {
private:
	std::string fio;
	int kyrs;
	int grup;
	int points[3];  // îöåíêè

public:
	//êîíñòðóêòîðû, äåêîíñòðóêòîð
	Student();
	Student(std::string name, int k, int gr, int* p);  
	// p áåðåò 3 çíà÷åíèÿ
	// åñëè áàëëîâ >100 - îñòàâèò 100
	// åëñè < 0 - âûâåäåò 0
	Student(const Student& other);
	~Student() {};

	//cin, cout
	friend std::ostream& operator << (std::ostream& out, const Student& st);
	friend std::istream& operator >> (std::istream& in, Student& st);

	//ìåòîäû
	std::string get_fio();
	int get_kyrs();
	int get_grup();
	int* get_points();

	void set_fio(std::string f);
	void set_kyrs(int k);
	void set_grup(int gr);
	void set_points(int* p);

	void rating();  // áàëëû ïåðåâîäèò â îöåíêè
	bool check_exam(int n);  // ñäàë ëè ýêçàìåí?

	//îïåðàòîðû
	Student& operator = (const Student& stud);
	bool operator == (const Student& stud);
	bool operator < (const Student& stud);
};

void list(Student* array, int size);
Student * commission(Student * array, int& size);
