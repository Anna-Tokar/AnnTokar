#pragma once
#include <iostream>
using namespace std;

static int c = rand() % (20)+1;

struct Node {
	double data; //ýëåìåíò äàííûõ
	Node* next; //óêàçàòåëü íà ñëåäóþùèé óçåë
	Node* prev; //óêàçàòåëü íà ïðåäûäóùèé óçåë

	Node() : data(0), next(nullptr), prev(nullptr) { } //êîíñòðóêòîð
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
	Node* first; //óêàçàòåëü íà íà÷àëî ñïèñêà
	Node* last; //óêàçàòåëü íà êîíåö ñïèñêà
public:
	DoubleList() : first(nullptr), last(nullptr) {	}
	~DoubleList();

	void addFirst(double x); //äîáàâëåíèå ýëåìåíòà â íà÷àëî
	void addLast(double val); //äîáàâëåíèå ýëåìåíòà â êîíåö
	long getFirst()const; //ïîëó÷åíèå ïåðâîãî ýëåìåíòà
	double getLast()const; //ïîëó÷åíèå ïîñëåäíåãî ýëåìåíòà
	void delFirst(); //óäàëåíèå ïåðâîãî ýëåìåíòà
	void delLast(); //óäàëåíèå ïîñëåäíåãî ýëåìåíòà
	double operator [] (long ix) const; //äîñòóï ê ýëåìåíòàì
	void forfunc(long ix, double y);

	friend ostream& operator << (ostream& out, const DoubleList& l); //âûâîä
};

typedef double (*func)(double);
class SparseArray : public DoubleList {
private:
	long size_arr; //ðàçìåð ìàññèâà
	double x = 0; //çíà÷åíèå ïî óìîë÷àíèþ
	DoubleList* arr;
public:
	SparseArray(long s = INT_MAX); //êîíñòðóêòîð
	~SparseArray() { delete[] arr; }
	
	long size(); //ðàçìåð ìàññèâà
	long notEmpty(); //êîëè÷åñòâî íåïóñòûõ ýëåìåíòîâ
	void showElem(); //âûâîä íåïóñòûõ ýëåìåíòîâ
	double operator [] (long ix) const; //äîñòóï ê ýëåìåíòàì
	//void operator [] (long ix);

	void foreach(func f);

	friend ostream& operator << (ostream& out, const SparseArray& arr); //âûâîä
	friend istream& operator >> (istream& in, SparseArray& arr); //ââîä
};

inline double pos(double x) { return abs(x); } //âñå ÷èñëà ïîëîæèòåëüíûå
inline double neg(double x) { if (x < 0) return x; else return -x; } //âñå ÷èñëà îòðèöàòåëüíûå
inline double st(double x) { return x * x; } //âîçâåäåíèå â êâàäðàò
