#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	//SparseArray M(20);
	////c = 10;
	////c = (rand() % (INT_MAX)+1) / 1000; //êîëè÷åñòâî ýëåìåíòîâ
	////cout << c << endl;
	//cin >> M;

	//ofstream fin;
	//fin.open("z2.txt");
	//int* ind = new int[c];
	//for (int i = 0; i < c; i++)
	//	ind[i] = M.operator[](i * 2);
	//int temp;
	//for (int i = 1; i < c; i++)
	//{
	//	for (int j = 0; j < c - 1; j++)
	//	{
	//		if (ind[j] > ind[j + 1])
	//		{
	//			temp = ind[j];
	//			ind[j] = ind[j + 1];
	//			ind[j + 1] = temp;
	//		}
	//	}
	//}
	//int i = 0, k = 0;
	//while (i <= ind[c - 1]) {
	//	if (k == 0)
	//		for (int j = 0; j < ind[k]; j++) {
	//			fin << "0 ";
	//			i++;
	//		}
	//	else
	//		for (int j = 0; j < (ind[k] - ind[k - 1] - 1); j++) {
	//			fin << "0 ";
	//			i++;
	//		}
	//	// öèêë äëÿ ïîèñêà â èñõîäíîì ìàññèâå çíà÷åíèÿ ïî èíäåêñó (êîòîðûé ìû ñîðòèðîâàëè âûøå)
	//	int m = 0; // äëÿ çàïèñè çíà÷åíèÿ
	//	while (M.operator[](m) != ind[k])
	//		m = m + 2;
	//	fin << M.operator[](m + 1) << " ";
	//	k++;
	//	i++;
	//}
	//for (int j = ind[c - 1] + 1; j < M.size(); j++)
	//	fin << "0 ";
	//fin.close();


	SparseArray A(10);
	//c = 5;
	cout << "Ðàçìåð ìàññèâà:" << A.size() << endl;
	cout << "Êîëè÷åñòâî íåïóñòûõ ýëåìåíòîâ: " << A.notEmpty() << endl;
	cin >> A;
	cout << "Âñå ýëåìåíòû: " << endl;
	cout << A << endl;
	cout << "Íåïóñòûå ýëåìåíòû: " << endl;
	A.showElem();
	cout << "Íåïóñòûå ýëåìåíòû, âîçâåäåííûå â êâàäðàò: " << endl;
	A.foreach(st);
	A.showElem();
	cout << "Íåïóñòûå ýëåìåíòû, ïåðåâåäåííûå â ïîëîæèòåëüíûå: " << endl;
	A.foreach(pos);
	A.showElem();
	cout << "Íåïóñòûå ýëåìåíòû, ïåðåâåäåííûå â îòðèöàòåëüíûå: " << endl;
	A.foreach(neg);
	A.showElem();
}
