#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	SparseArray M(20);
	//c = (rand() % (INT_MAX)+1) / 1000; //количество элементов
	cin >> M;

	ofstream fin;
	fin.open("z2.txt");
	int* ind = new int[c];
	for (int i = 0; i < c; i++)
		ind[i] = M.operator[](i * 2);
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
	while (i <= ind[c - 1]) {
		if (k == 0)
			for (int j = 0; j < ind[k]; j++) {
				fin << "0 ";
				i++;
			}
		else
			for (int j = 0; j < (ind[k] - ind[k - 1] - 1); j++) {
				fin << "0 ";
				i++;
			}
		// цикл для поиска в исходном массиве значения по индексу (который мы сортировали выше)
		int m = 0; // для записи значения
		while (M.operator[](m) != ind[k])
			m = m + 2;
		fin << M.operator[](m + 1) << " ";
		k++;
		i++;
	}
	for (int j = ind[c - 1] + 1; j < M.size(); j++)
		fin << "0 ";
	fin.close();

	SparseArray A(10);
	cout << "Размер массива:" << A.size() << endl;
	cout << "Количество непустых элементов: " << A.notEmpty() << endl;
	cin >> A;
	cout << "Все элементы: " << endl;
	cout << A << endl;
	cout << "Непустые элементы: " << endl;
	A.showElem();
	cout << "Непустые элементы, возведенные в квадрат: " << endl;
	A.foreach(st);
	A.showElem();
	cout << "Непустые элементы, переведенные в положительные: " << endl;
	A.foreach(pos);
	A.showElem();
	cout << "Непустые элементы, переведенные в отрицательные: " << endl;
	A.foreach(neg);
	A.showElem();
}
