#include "Header.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251);// óñòàíîâêà êîäîâîé ñòðàíèöû win-cp 1251 â ïîòîê ââîäà
	SetConsoleOutputCP(1251); // óñòàíîâêà êîäîâîé ñòðàíèöû win-cp 1251 â ïîòîê âûâîäà
	setlocale(LC_ALL, "Rus");

	//string a1 = "Çîòîâ Ìàêñèì Àëåêñååâè÷";
	//int arr1[3] = { 25, 50, 85 };
	//Student st;
	//cout << st << "\n";
	//Student st1(a1, 2, 1,arr1);
	//cout << st1 << "\n";

	//cout << "\n";

	///*cin >> st;
	//cout << "\n" << st << "\n";
	//st.rating();*/

	////get-åððû
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

	////set-åððû
	//Student st2;
	//string b1 = "Áóõòèÿðîâ Âèòàëèé Ìàðêîâè÷";
	//int krs2 = 2;
	//int gr2 = 1;
	//int pnts2[3] = { -20,71,60 };
	//st2.set_fio(b1);
	//st2.set_kyrs(krs2);
	//st2.set_grup(gr2);
	//st2.set_points(pnts2);

	//cout << st2 << "\n";

	////ðåéòèíã
	//st2.rating();
	//
	////äîïóñê íà ýêçàìåí
	//for (int i = 0; i < 3; i++) {
	//	cout << "Äîïóñê íà ýêçàìåí ïî " << i + 1 << "-ìó ïðåäìåòó: " << st2.check_exam(i)<<"\n";
	//}

	//cout << "\n";

	////ñðàâíåíèå
	//bool eq = st1 == st2;
	//cout << "Ñóììà áàëëîâ ïåðâîãî è âòîðîãî ñòóäåíòîâ: " << eq << "\n";

	//cout << "\n";

	////ïðèñâàèâàíèå
	//cout << st2 << "\n";
	//st2 = st1;
	//cout << st2 << "\n";

	Student arr[4];
	int col = 4; // âñåãî ñòóäåíòîâ 

	// int points[3] - îöåíêè
	int ar1[3] = { -20,25,59 };
	int ar2[3] = { 75,63,85 };
	int ar3[3] = { 0,0,0 };
	int ar4[3] = { 100,59,75 };

	Student a(std::string("Òîêàðü Àííà Àëåêñàíäðîâíà"), 2, 1, ar1);
	Student b(std::string("Òîêàðü Åëåíà Âàñèëüåâíà"), 3, 4, ar2);
	Student c(std::string("Òîêàðü Àëåêñàíäð Íèêîëàåâè÷"), 4, 1, ar3);
	Student d(std:: string("Òîêàðü Îëåã Àëåêñàíäðîâè÷"), 2, 4, ar4);

	// ñîçäà¸ì ìàññèâ èç âñåõ ñòóäåíòîâ
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;

	// âûâîäèò âñå îáî âñåõ
	list(arr, col);

	std::cout << "--------------------------Íà êîìèññèþ:\n";
	// íîâûé ìàññèâ äëÿ êîìèññèè
	Student* arr1 = commission(arr, col);
	list(arr1, col);


	// ââîä
	Student st;
	std::cin >> st;
	std::cout << "\n" << st << "\n";
	st.rating();

	std::cout << '\n';
	system("pause");
	return 0;
}
