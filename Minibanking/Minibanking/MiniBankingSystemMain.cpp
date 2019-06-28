#include "MiniBankingCommonDecl.h"
#include "AccountHandlr.h"
#include <iostream>

using namespace std;

int main(void)
{
	AccountHandler ACC;
	
	ifstream fin("ACCOUNT.txt");
	if (fin) 
	{
		IO_File file;
		
		file.input(ACC, fin);	
	}

	fin.close();

	int choice;

	while (1)
	{
		ShowMenu(); 		
		cout << "▷ 메뉴 선택  >>\t";
		cin >> choice;

		switch (choice)
		{
		case MAKE:
			ACC.AccMenu();
			break;
		case DEPOSIT:
			ACC.DepositMoney();
			break;
		case WITHDRAW:
			ACC.WithdrawMoney();
			break;
		case INQUIRE:
			ACC.ShowAccInfo();
			break;
		case EXIT:
			cout << "┌───────────────────────┐" << endl;
			cout << "│\t  ♬ 이용해주셔서 감사합니다. ♬ \t│" << endl;
			cout << "└───────────────────────┘" << endl;
			getchar();
			return 0;
		default:
			cout << "┌───────────────────────┐" << endl;
			cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
			cout << "│\t없는 메뉴입니다. 다시 선택해주세요.\t│" << endl;
			cout << "└───────────────────────┘" << endl;
			getchar();
			getchar();
		}
	}

	return 0;
}