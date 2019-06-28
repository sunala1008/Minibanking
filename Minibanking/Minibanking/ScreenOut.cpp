#include "ScreenOut.h"

void ShowMenu(void)
{
	system("cls");
	cout << "┌────────── Menu ──────────┐" << endl;
	cout << "│\t\t   1. 계좌개설   \t\t│" << endl;
	cout << "│\t\t   2. 입    금   \t\t│" << endl;
	cout << "│\t\t   3. 출    금   \t\t│" << endl;
	cout << "│\t\t   4. 전체출력   \t\t│" << endl;
	cout << "│\t\t   5. 종    료   \t\t│" << endl;
	cout << "└───────────────────────┘" << endl;
}

void ShowAccMenu(void)
{
	system("cls");
	cout << "┌────────계좌 종류 선택────────┐" << endl;
	cout << "│\t\t1. 일반 예금 계좌\t\t│" << endl;
	cout << "│\t\t2. 신용 거래 계좌\t\t│" << endl;
	cout << "│\t\t3. 메  인  메  뉴\t\t│" << endl;
	cout << "└───────────────────────┘" << endl;
}

void ShowCreditLevel(void)
{
	cout << "  ┌───────신용 등급 정보───────┐" << endl;
	cout << "  │          A등급 : 기본 이율 + 7%          │" << endl;
	cout << "  │          B등급 : 기본 이율 + 4%          │" << endl;
	cout << "  │          C등급 : 기본 이율 + 2%          │" << endl;
	cout << "  └─────────────────────┘" << endl;
}