#include <iostream>
#include "Header.h"
using namespace std;

//Деструктор
DoubleList::~DoubleList() {
	Node* p, * p1;
	// удаление всех элементов списка:
	p = first;
	while (p)
	{
		p1 = p->next;
		delete p;
		p = p1;
	}
}

//Добавление узла в начало
void DoubleList::addFirst(double x) {
	Node* buf = new Node;
	buf->data = x;  // элемент данных = x
	if (!first) {  // нет первого элемента - указатель на следующий - последний
		buf->next = last;
		last = buf;  // а последний указывает на новый массив
	}
	else { // нужно сдвинуть указатель
		buf->next = first; // следующий - начало массива
		first->prev = buf; // начало предыдущего - новый массив
	}
	first = buf;
	first->prev = NULL;
}

//Добавление узла в конец
void DoubleList::addLast(double x) {
	Node* buf = new Node;
	buf->data = x;
	if (!first) {
		buf->next = last;
		first = buf;
		buf->prev = NULL;
	}
	else {
		buf->next = last->next;
		buf->prev = last;
		last->next = buf;
	}
	last = buf;
}

//Получение первого
long DoubleList::getFirst() const {
	if (first)
		return first->data;
	throw 100;
}

//Получение последнего
double DoubleList::getLast()const {
	if (first)
		return last->data;
	throw 100;
}


//Доступ к элементам
double DoubleList::operator [] (long ix) const {
	Node* current = first;
	for (int i = 0; i <= ix; i++) {
		if (i != ix)
			current = current->next;
		else
			return current->data;
	}
}

void DoubleList::forfunc (long ix, double y) {
	Node* current = first;
	for (int i = 0; i <= ix; i++) {
		if (i != ix)
			current = current->next;
		else
			current->data = y;
	}
}

//Вывести все элементы
ostream& operator << (ostream& os, const DoubleList& l) {
	Node* p = l.first;  // указатель на начало списка 
	while (p) {
		os << *p << " ";
		p = p->next;
	}
	os << endl;
	return os;
}

//-------------------------------------------------------------------------

//Конструктор
SparseArray::SparseArray(long s) {
	size_arr = s;
	arr = new DoubleList[c * 2];
}

//Размер массива
long SparseArray::size() {
	return size_arr;
}

//Количество непустых элементов
long SparseArray::notEmpty() {
	return c;
}

//Вывод непустых элементов
void SparseArray::showElem() {
	int i = 1;
	while (i < c * 2) {
		cout << arr->operator[](i) << " ";
		i = i + 2;
	}
	cout << endl;
}

double SparseArray::operator [] (long ix) const { //доступ к элементам
	return arr->operator[](ix);
}

//Вывод массива
ostream& operator << (ostream& out, const SparseArray& array) {
	int* ind = new int[c];
	for(int i = 0; i < c; i++)
		ind[i] = array.arr->operator[](i*2);
	int temp;
	for (int i = 1; i < c; i++)
	{
		for (int j = 0; j < c - 1; j++)
		{
			if (ind[j] > ind[j + 1])
			{
				temp = ind[j];
				ind[j] = ind[j + 1];
				ind[j + 1] = temp;
			}
		}
	}
	int i = 0, k = 0;
	while (i <= ind[c-1]) {
		if (k == 0) 
			for (int j = 0; j < ind[k]; j++) {
				out << "0 " << endl;
				i++;
			}
		else
			for (int j = 0; j < (ind[k]-ind[k-1]-1); j++) {
				out << "0 " << endl;
				i++;
			}
		// цикл для поиска в исходном массиве значения по индексу (который мы сортировали выше)
		int m = 0; // для записи значения
		while (array.arr->operator[](m) != ind[k])
			m = m + 2;
		out << "{" << ind[k] << "->" << array.arr->operator[](m+1) << " } " << endl;
		k++;
		i++;
	}
	for (int j = ind[c - 1] + 1; j < array.size_arr; j++)
		out << "0 " << endl;
	out << endl;
	return out;
}

//Ввод массива
istream& operator >> (istream& in, SparseArray& array) {
	// i - проходим по ненулевым числам
	// j - индекс ненулевых чисел которые мы записываем
	// y - число которое вводим
	// k - индекс для проверки на случай совпадения индексов
	// kol - количество введеных индексов и значений 
	double i = 0, j, y; 
	int k = 0, kol = 0; 
	bool flag;
	cout << "Введите элементы (" << c << "), отличные от 0:" << endl;
	j = rand() % (array.size_arr - 1);
	while (i < c) {
		//j = rand() % (array.size_arr - 1);
		// проверка на совпадение индекса
		while (k < kol * 2) {
			if (array.arr->operator[](k) == j) {
				j = rand() % (array.size_arr - 1);
				k = -2;
			}
			k = k + 2;
		}
		in >> y;
		if (y == 0)  // если пользователь ввел 0
			i--;
		if (y != array.x) {
			cout << "j = " << j << " " << "y = " << y << endl;
			array.arr->addLast(j); 
			array.arr->addLast(y);
			kol++;
		}
		i++;
	}
	return in;
}

//Метод применимый к непустым элементам
void SparseArray::foreach(func f) {
	int i = 1;
	while (i < c * 2) {
		double y = arr->operator[](i);
		y = f(y);
		arr->forfunc(i, y);
		i = i + 2;
	}
}
