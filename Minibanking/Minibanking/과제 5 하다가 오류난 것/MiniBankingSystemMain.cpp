#include "MiniBankingCommonDecl.h"
#include "AccountHandlr.h"

int main(void)
{
	AccountHandler ACC;
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "메뉴 선택 : ";
		cin >> choice;
		cout << endl;

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
			ACC.ShowAllAccInfo();
			break;
		case EXIT:
			break;
		default:
			cout << "  ※ 없는 메뉴입니다. 다시 선택해주세요. ※" << endl << endl;
			getchar();
			getchar();
		}

		if (choice == EXIT)
			break;
	}

	return 0;
}