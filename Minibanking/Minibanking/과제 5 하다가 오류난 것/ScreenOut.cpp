#include <iostream>
#include "ScreenOut.h"

using namespace std;

void ShowMenu(void)
{
	system("cls");
	cout << "==================== Menu ====================" << endl;
	cout << "	         1. 계좌개설" << endl;
	cout << "	         2. 입    금" << endl;
	cout << "	         3. 출    금" << endl;
	cout << "	         4. 전체출력" << endl;
	cout << "	         5. 종    료" << endl;
	cout << "==============================================" << endl;
}

void ShowAccMenu(void)
{
	system("cls");
	cout << "=============== 계좌 종류 선택 ===============" << endl;
	cout << "              1. 일반 예금 계좌" << endl;
	cout << "              2. 신용 신뢰 계좌" << endl;
	cout << "              3. 메  인  메  뉴" << endl;
	cout << "==============================================" << endl;
}

void ShowCreditLevel(void)
{
	cout << "=============== 신용 등급 정보 ===============" << endl;
	cout << "            A등급 : 기본 이율 + 7%" << endl;
	cout << "            B등급 : 기본 이율 + 4%" << endl;
	cout << "            C등급 : 기본 이율 + 2%" << endl;
	cout << "==============================================" << endl;
}