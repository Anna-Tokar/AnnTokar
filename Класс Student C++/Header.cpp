#include "Header.h"

// êîíñòðóêòîðû
Student::Student()
{
	fio = "none";
	kyrs = 0;
	grup = 0;
	for (int i = 0; i < 3; ++i) points[i] = 0;
}

Student::Student(std::string name, int k, int gr, int* p) {
	this->fio = name;
	this->kyrs = k;
	this->grup = gr;
	for (int i = 0; i < 3; ++i) {
		if (p[i] > 100) {
			this->points[i] = 100;
		}
		else if (p[i] < 0) {
			this->points[i] = 0;
		}
		else {
			this->points[i] = p[i];
		}
	};
}

Student::Student(const Student& other) {
	this->fio = other.fio;
	this->kyrs = other.kyrs;
	this->grup = other.grup;
	for (int i = 0; i < 3; i++) {
		this->points[i] = other.points[i];
	}
}

// cin, cout
std::ostream& operator<<(std::ostream& out, const Student& st)
{
	out << st.fio << '\n';
	out << "Êóðñ: " << st.kyrs << "\n";
	out << "Ãðóïïà: " << st.grup << "\n";
	std::cout << "Áàëëû: \n";
	for (int i = 0; i < 3; ++i) out << i + 1 << "-ûé ïðåäìåò - " << st.points[i] << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Student& st)
{
	std::string f;
	int b;
	std::cout << "Ââåäèòå ÔÈÎ: ";
	getline(in, f);
	st.fio = f;

	std::cout << "Ââåäèòå êóðñ: ";
	in >> b;
	st.kyrs = b;

	std::cout << "Ââåäèòå íîìåð ãðóïïû: ";
	in >> b;
	st.grup = b;

	for (int i = 0; i < 3; ++i) {
		std::cout << "Ââåäèòå áàëëû ïî " << i + 1 << "-îìó ïðåäìåòó: ";
		in >> b;
		if (b > 100) {
			st.points[i] = 100;
		}
		else if (b < 0) {
			st.points[i] = 0;
		}
		else {
			st.points[i] = b;
		}
	}
	return in;
}

//ìåòîäû
std::string Student::get_fio() {
	return this->fio;
}
int Student::get_kyrs() {
	return this->kyrs;
}
int Student::get_grup() {
	return this->grup;
}
int* Student::get_points() {
	return this->points;
}

void Student::set_fio(std::string f) {
	this->fio = f;
}
void Student::set_kyrs(int k) {
	this->kyrs = k;
}
void Student::set_grup(int gr) {
	this->grup = gr;
}
void Student::set_points(int* p) {
	for (int i = 0; i < 3; ++i) {
		if (p[i] > 100) {
			this->points[i] = 100;
		}
		else if (p[i] < 0) {
			this->points[i] = 0;
		}
		else {
			this->points[i] = p[i];
		}
	}
}

void Student::rating() {
	int r[3];
	for (int i = 0; i < 3; i++) {
		if (this->points[i] < 60) r[i] = 2;
		else {
			if (this->points[i] < 71) r[i] = 3;
			else {
				if (this->points[i] < 85) r[i] = 4;
				else r[i] = 5;
			}
		}
	}
	std::cout << "Îöåíêè: \n";
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << "-é ïðåäìåò: " << r[i] << "\n";
	}
}

bool Student::check_exam(int n) {
	if (this->points[n] >= 60) return true;
	return false;
}

Student& Student::operator = (const Student& stud) {
	this->fio = stud.fio;
	this->kyrs = stud.kyrs;
	this->grup = stud.grup;
	for (int i = 0; i < 3; i++) {
		this->points[i] = stud.points[i];
	}

	return *this;
}

bool Student::operator == (const Student& stud) {
	return (this->points[0] + this->points[1] + this->points[2]) == (stud.points[0] + stud.points[1] + stud.points[2]);
}

bool Student::operator < (const Student& stud) {
	return (this->points[0] + this->points[1] + this->points[2]) < (stud.points[0] + stud.points[1] + stud.points[2]);
}

void list(Student* array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i]; // âûâîä êóðñà ãðóïïû è áàëëîâ
		array[i].rating();  // âûâîä îöåíîê
		std::cout << "\n";
	}
}

Student* commission(Student* array, int& size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		// ïðîâåðÿåì ýêçàìåíû - åñëè âñå 3 íå ñäàíû - ïëþñóåì
		if (!array[i].check_exam(0) && !array[i].check_exam(1) && !array[i].check_exam(2)) count++;
	}

	if (count == 0) return nullptr;

	Student* commission_students = new Student[count];
	count = 0;
	for (int i = 0; i < size; i++) {
		if (!array[i].check_exam(0) && !array[i].check_exam(1) && !array[i].check_exam(2)) {
			commission_students[count] = array[i];
			count++;
		}
	}
	size = count;
	return commission_students;
}
