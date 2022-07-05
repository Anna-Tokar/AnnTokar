#pragma once
#include <iostream>
using namespace std;

static int c = rand() % (20)+1;

struct Node {
	double data; //������� ������
	Node* next; //��������� �� ��������� ����
	Node* prev; //��������� �� ���������� ����

	Node() : data(0), next(nullptr), prev(nullptr) { } //�����������
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
	Node* first; //��������� �� ������ ������
	Node* last; //��������� �� ����� ������
public:
	DoubleList() : first(nullptr), last(nullptr) {	}
	~DoubleList();

	void addFirst(double x); //���������� �������� � ������
	void addLast(double val); //���������� �������� � �����
	long getFirst()const; //��������� ������� ��������
	double getLast()const; //��������� ���������� ��������
	void delFirst(); //�������� ������� ��������
	void delLast(); //�������� ���������� ��������
	double operator [] (long ix) const; //������ � ���������
	void forfunc(long ix, double y);

	friend ostream& operator << (ostream& out, const DoubleList& l); //�����
};

typedef double (*func)(double);
class SparseArray : public DoubleList {
private:
	long size_arr; //������ �������
	double x = 0; //�������� �� ���������
	DoubleList* arr;
public:
	SparseArray(long s = INT_MAX); //�����������
	~SparseArray() { delete[] arr; }
	
	long size(); //������ �������
	long notEmpty(); //���������� �������� ���������
	void showElem(); //����� �������� ���������
	double operator [] (long ix) const; //������ � ���������
	//void operator [] (long ix);

	void foreach(func f);

	friend ostream& operator << (ostream& out, const SparseArray& arr); //�����
	friend istream& operator >> (istream& in, SparseArray& arr); //����
};

inline double pos(double x) { return abs(x); } //��� ����� �������������
inline double neg(double x) { if (x < 0) return x; else return -x; } //��� ����� �������������
inline double st(double x) { return x * x; } //���������� � �������