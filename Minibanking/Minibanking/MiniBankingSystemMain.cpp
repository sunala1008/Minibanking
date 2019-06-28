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
		cout << "�� �޴� ����  >>\t";
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
			cout << "��������������������������������������������������" << endl;
			cout << "��\t  �� �̿����ּż� �����մϴ�. �� \t��" << endl;
			cout << "��������������������������������������������������" << endl;
			getchar();
			return 0;
		default:
			cout << "��������������������������������������������������" << endl;
			cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
			cout << "��\t���� �޴��Դϴ�. �ٽ� �������ּ���.\t��" << endl;
			cout << "��������������������������������������������������" << endl;
			getchar();
			getchar();
		}
	}

	return 0;
}