#include "Header.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	setlocale(LC_ALL, "Rus");

	//string a1 = "����� ������ ����������";
	//int arr1[3] = { 25, 50, 85 };
	//Student st;
	//cout << st << "\n";
	//Student st1(a1, 2, 1,arr1);
	//cout << st1 << "\n";

	//cout << "\n";

	///*cin >> st;
	//cout << "\n" << st << "\n";
	//st.rating();*/

	////get-����
	//string name = st1.get_fio();
	//cout << name << " ";
	//int krs = st1.get_kyrs();
	//cout << krs << ".";
	//int gr = st1.get_grup();
	//cout << gr << " [ ";
	//int* p = st1.get_points();
	//for (int i = 0; i < 3; i++) {
	//	cout << p[i] << " ";
	//}
	//cout << "] \n";

	//cout << "\n";

	////set-����
	//Student st2;
	//string b1 = "��������� ������� ��������";
	//int krs2 = 2;
	//int gr2 = 1;
	//int pnts2[3] = { -20,71,60 };
	//st2.set_fio(b1);
	//st2.set_kyrs(krs2);
	//st2.set_grup(gr2);
	//st2.set_points(pnts2);

	//cout << st2 << "\n";

	////�������
	//st2.rating();
	//
	////������ �� �������
	//for (int i = 0; i < 3; i++) {
	//	cout << "������ �� ������� �� " << i + 1 << "-�� ��������: " << st2.check_exam(i)<<"\n";
	//}

	//cout << "\n";

	////���������
	//bool eq = st1 == st2;
	//cout << "����� ������ ������� � ������� ���������: " << eq << "\n";

	//cout << "\n";

	////������������
	//cout << st2 << "\n";
	//st2 = st1;
	//cout << st2 << "\n";

	Student arr[4];
	int col = 4; // ����� ��������� 

	// int points[3] - ������
	int ar1[3] = { -20,25,59 };
	int ar2[3] = { 75,63,85 };
	int ar3[3] = { 0,0,0 };
	int ar4[3] = { 100,59,75 };

	Student a(std::string("������ ���� �������������"), 2, 1, ar1);
	Student b(std::string("������ ����� ����������"), 3, 4, ar2);
	Student c(std::string("������ ��������� ����������"), 4, 1, ar3);
	Student d(std:: string("������ ���� �������������"), 2, 4, ar4);

	// ������ ������ �� ���� ���������
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;

	// ������� ��� ��� ����
	list(arr, col);

	std::cout << "--------------------------�� ��������:\n";
	// ����� ������ ��� ��������
	Student* arr1 = commission(arr, col);
	list(arr1, col);


	// ����
	Student st;
	std::cin >> st;
	std::cout << "\n" << st << "\n";
	st.rating();

	std::cout << '\n';
	system("pause");
	return 0;
}