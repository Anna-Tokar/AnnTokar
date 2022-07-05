#include <iostream>
#include "Header.h"
using namespace std;

////Êîíñòðóêòîð ñ ïàðàìåòðîì
//DoubleList::DoubleList(int val) {
//	Node* temp = new Node;
//	temp->data = val;
//	temp->next = NULL;
//	temp->prev = NULL;
//	first = temp;
//	last = temp;
//}

//Äåñòðóêòîð
DoubleList::~DoubleList() {
	Node* p, * p1;
	// óäàëåíèå âñåõ ýëåìåíòîâ ñïèñêà:
	p = first;
	while (p)
	{
		p1 = p->next;
		delete p;
		p = p1;
	}
}

//Äîáàâëåíèå óçëà â íà÷àëî
void DoubleList::addFirst(double x) {
	Node* buf = new Node;
	buf->data = x;  // ýëåìåíò äàííûõ = x
	if (!first) {  // íåò ïåðâîãî ýëåìåíòà - óêàçàòåëü íà ñëåäóþùèé - ïîñëåäíèé
		buf->next = last;
		last = buf;  // à ïîñëåäíèé óêàçûâàåò íà íîâûé ìàññèâ
	}
	else { // íóæíî ñäâèíóòü óêàçàòåëü
		buf->next = first; // ñëåäóþùèé - íà÷àëî ìàññèâà
		first->prev = buf; // íà÷àëî ïðåäûäóùåãî - íîâûé ìàññèâ
	}
	first = buf;
	first->prev = NULL;
}

//Äîáàâëåíèå óçëà â êîíåö
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

//Ïîëó÷åíèå ïåðâîãî
long DoubleList::getFirst() const {
	if (first)
		return first->data;
	throw 100;
}

//Ïîëó÷åíèå ïîñëåäíåãî
double DoubleList::getLast()const {
	if (first)
		return last->data;
	throw 100;
}

//Óäàëåíèå ãîëîâû
void DoubleList::delFirst() {
	if (first) {
		Node* buf = first;
		first = first->next;
		first->prev = NULL;
		delete buf;
	}
	throw 100;
}

//Óäàëåíèå õâîñòà
void DoubleList::delLast() {
	if (first) {
		Node* buf = last;
		last = last->prev;
		last->next = NULL;
		delete buf;
	}
	throw 100;
}


//Äîñòóï ê ýëåìåíòàì
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

//Âûâåñòè âñå ýëåìåíòû
ostream& operator << (ostream& os, const DoubleList& l) {
	Node* p = l.first;  // óêàçàòåëü íà íà÷àëî ñïèñêà 
	while (p) {
		os << *p << " ";
		p = p->next;
	}
	os << endl;
	return os;
}

//-------------------------------------------------------------------------

//Êîíñòðóêòîð
SparseArray::SparseArray(long s) {
	size_arr = s;
	arr = new DoubleList[c * 2];
}

//Ðàçìåð ìàññèâà
long SparseArray::size() {
	return size_arr;
}

//Êîëè÷åñòâî íåïóñòûõ ýëåìåíòîâ
long SparseArray::notEmpty() {
	return c;
}

//Âûâîä íåïóñòûõ ýëåìåíòîâ
void SparseArray::showElem() {
	int i = 1;
	while (i < c * 2) {
		cout << arr->operator[](i) << " ";
		i = i + 2;
	}
	cout << endl;
}

double SparseArray::operator [] (long ix) const { //äîñòóï ê ýëåìåíòàì
	return arr->operator[](ix);
}

//Âûâîä ìàññèâà
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
		// öèêë äëÿ ïîèñêà â èñõîäíîì ìàññèâå çíà÷åíèÿ ïî èíäåêñó (êîòîðûé ìû ñîðòèðîâàëè âûøå)
		int m = 0; // äëÿ çàïèñè çíà÷åíèÿ
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

//Ââîä ìàññèâà
istream& operator >> (istream& in, SparseArray& array) {
	// i - ïðîõîäèì ïî íåíóëåâûì ÷èñëàì
	// j - èíäåêñ íåíóëåâûõ ÷èñåë êîòîðûå ìû çàïèñûâàåì
	// y - ÷èñëî êîòîðîå ââîäèì
	// k - èíäåêñ äëÿ ïðîâåðêè íà ñëó÷àé ñîâïàäåíèÿ èíäåêñîâ
	// kol - êîëè÷åñòâî ââåäåíûõ èíäåêñîâ è çíà÷åíèé 
	double i = 0, j, y; 
	int k = 0, kol = 0; 
	bool flag;
	cout << "Ââåäèòå ýëåìåíòû, îòëè÷íûå îò 0:" << endl;
	j = rand() % (array.size_arr - 1);
	while (i < c) {
		// ïðîâåðêà íà ñîâïàäåíèå èíäåêñà
		while (k < kol * 2) {
			if (array.arr->operator[](k) == j) {
				j = rand() % (array.size_arr - 1);
				k = -2;
			}
			k = k + 2;
		}
		in >> y;
		if (y == 0)  // åñëè ïîëüçîâàòåëü ââåë 0
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

//Ìåòîä ïðèìåíèìûé ê íåïóñòûì ýëåìåíòàì
void SparseArray::foreach(func f) {
	int i = 1;
	while (i < c * 2) {
		double y = arr->operator[](i);
		y = f(y);
		arr->forfunc(i, y);
		i = i + 2;
	}
}
