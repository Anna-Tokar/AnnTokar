#include "Header.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "Rus");

	//string a1 = "Зотов Максим Алексеевич";
	//int arr1[3] = { 25, 50, 85 };
	//Student st;
	//cout << st << "\n";
	//Student st1(a1, 2, 1,arr1);
	//cout << st1 << "\n";

	//cout << "\n";

	///*cin >> st;
	//cout << "\n" << st << "\n";
	//st.rating();*/

	////get-ерры
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

	////set-ерры
	//Student st2;
	//string b1 = "Бухтияров Виталий Маркович";
	//int krs2 = 2;
	//int gr2 = 1;
	//int pnts2[3] = { -20,71,60 };
	//st2.set_fio(b1);
	//st2.set_kyrs(krs2);
	//st2.set_grup(gr2);
	//st2.set_points(pnts2);

	//cout << st2 << "\n";

	////рейтинг
	//st2.rating();
	//
	////допуск на экзамен
	//for (int i = 0; i < 3; i++) {
	//	cout << "Допуск на экзамен по " << i + 1 << "-му предмету: " << st2.check_exam(i)<<"\n";
	//}

	//cout << "\n";

	////сравнение
	//bool eq = st1 == st2;
	//cout << "Сумма баллов первого и второго студентов: " << eq << "\n";

	//cout << "\n";

	////присваивание
	//cout << st2 << "\n";
	//st2 = st1;
	//cout << st2 << "\n";

	Student arr[4];
	int col = 4; // всего студентов 

	// int points[3] - оценки
	int ar1[3] = { -20,25,59 };
	int ar2[3] = { 75,63,85 };
	int ar3[3] = { 0,0,0 };
	int ar4[3] = { 100,59,75 };

	Student a(std::string("Токарь Анна Александровна"), 2, 1, ar1);
	Student b(std::string("Токарь Елена Васильевна"), 3, 4, ar2);
	Student c(std::string("Токарь Александр Николаевич"), 4, 1, ar3);
	Student d(std:: string("Токарь Олег Александрович"), 2, 4, ar4);

	// создаём массив из всех студентов
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;

	// выводит все обо всех
	list(arr, col);

	std::cout << "--------------------------На комиссию:\n";
	// новый массив для комиссии
	Student* arr1 = commission(arr, col);
	list(arr1, col);


	// ввод
	Student st;
	std::cin >> st;
	std::cout << "\n" << st << "\n";
	st.rating();

	std::cout << '\n';
	system("pause");
	return 0;
}