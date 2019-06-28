#include "MiniBankingCommonDecl.h"
#include "AccountHandlr.h"

int main(void)
{
	AccountHandler ACC;
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "�޴� ���� : ";
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
			cout << "  �� ���� �޴��Դϴ�. �ٽ� �������ּ���. ��" << endl << endl;
			getchar();
			getchar();
		}

		if (choice == EXIT)
			break;
	}

	return 0;
}