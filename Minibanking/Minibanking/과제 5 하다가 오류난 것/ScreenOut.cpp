#include <iostream>
#include "ScreenOut.h"

using namespace std;

void ShowMenu(void)
{
	system("cls");
	cout << "==================== Menu ====================" << endl;
	cout << "	         1. ���°���" << endl;
	cout << "	         2. ��    ��" << endl;
	cout << "	         3. ��    ��" << endl;
	cout << "	         4. ��ü���" << endl;
	cout << "	         5. ��    ��" << endl;
	cout << "==============================================" << endl;
}

void ShowAccMenu(void)
{
	system("cls");
	cout << "=============== ���� ���� ���� ===============" << endl;
	cout << "              1. �Ϲ� ���� ����" << endl;
	cout << "              2. �ſ� �ŷ� ����" << endl;
	cout << "              3. ��  ��  ��  ��" << endl;
	cout << "==============================================" << endl;
}

void ShowCreditLevel(void)
{
	cout << "=============== �ſ� ��� ���� ===============" << endl;
	cout << "            A��� : �⺻ ���� + 7%" << endl;
	cout << "            B��� : �⺻ ���� + 4%" << endl;
	cout << "            C��� : �⺻ ���� + 2%" << endl;
	cout << "==============================================" << endl;
}