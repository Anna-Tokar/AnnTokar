#pragma once
#include <iostream>
using namespace std;

static int c = rand() % (20)+1;

struct Node {
	double data; //элемент данных
	Node* next; //указатель на следующий узел
	Node* prev; //указатель на предыдущий узел

	Node() : data(0), next(nullptr), prev(nullptr) { } //конструктор
	Node(int data, Node* next, Node* prev) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}


	friend	ostream& operator << (ostream& out, const Node& x) {
		out << x.data;
		return out;
	}
};

class DoubleList {
protected:
	Node* first; //указатель на начало списка
	Node* last; //указатель на конец списка
public:
	DoubleList() : first(nullptr), last(nullptr) {	}
	~DoubleList();

	void addFirst(double x); //добавление элемента в начало
	void addLast(double val); //добавление элемента в конец
	long getFirst()const; //получение первого элемента
	double getLast()const; //получение последнего элемента
	void delFirst(); //удаление первого элемента
	void delLast(); //удаление последнего элемента
	double operator [] (long ix) const; //доступ к элементам
	void forfunc(long ix, double y);

	friend ostream& operator << (ostream& out, const DoubleList& l); //вывод
};

typedef double (*func)(double);
class SparseArray : public DoubleList {
private:
	long size_arr; //размер массива
	double x = 0; //значение по умолчанию
	DoubleList* arr;
public:
	SparseArray(long s = INT_MAX); //конструктор
	~SparseArray() { delete[] arr; }
	
	long size(); //размер массива
	long notEmpty(); //количество непустых элементов
	void showElem(); //вывод непустых элементов
	double operator [] (long ix) const; //доступ к элементам
	//void operator [] (long ix);

	void foreach(func f);

	friend ostream& operator << (ostream& out, const SparseArray& arr); //вывод
	friend istream& operator >> (istream& in, SparseArray& arr); //ввод
};

inline double pos(double x) { return abs(x); } //все числа положительные
inline double neg(double x) { if (x < 0) return x; else return -x; } //все числа отрицательные
inline double st(double x) { return x * x; } //возведение в квадрат