#include "MiniBankingCommonDecl.h"
#include "AccountHandlr.h"

void AccountHandler::AccMenu(void)
{
	int choice;

	while (1)
	{
		ShowAccMenu();
		cout << "�޴� ���� : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case NORMAL:
			NormalMakeAccount();
			break;
		case CREDIT:
			CreditMakeAccount();
			break;
		case UP:
			break;
		default:
			cout << "�� ���� �޴��Դϴ�. �ٽ� �������ּ���. ��" << endl << endl;
			getchar();
			getchar();
		}

		if (choice == UP)
			break;
	}
}

void AccountHandler::NormalMakeAccount(void)	// �Ϲ� ���� ����
{
	system("cls");

	int id;					// ���� ��ȣ
	char name[50];			// �� ��
	int balance;			// �ݾ�
	int roi;				// ����

	cout << "=============== �Ϲ� ���� ���� ===============" << endl;
	cout << "  �� ������ �� �ڸ� ���ڷ� �Է� ���ּ���. ��" << endl << endl;
	cout << "���¹�ȣ : "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			cout << endl;
			cout << "   �� �̹� ��ϵ� ���¹�ȣ�Դϴ�. ��" << endl;
			getchar();
			getchar();
			return;
		}
	}

	cout << "�� �� �� : "; cin >> name;
	cout << "��    �� : "; cin >> balance;

	if (balance < 0)
	{
		cout << "   �� �ݾ��� �ٽ� �Է����ּ���. ��" << endl;
		getchar();
		getchar();
		return;
	}

	cout << "��    �� : "; cin >> roi;
	cout << "==============================================" << endl;
	accArr[accNum++] = new NormalAccount(id, balance, name, roi);
	cout << "	�� ���°� �����Ǿ����ϴ�. ��" << endl;
	cout << "==============================================" << endl;
	getchar();
	getchar();

	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	} // ��
}

void AccountHandler::CreditMakeAccount(void)	// �ſ� ���� ����
{
	system("cls");

	int id;					// ���� ��ȣ
	char name[50];			// �� ��
	int balance;			// �ܾ�
	int roi;				// �⺻ ����
	int proi;				// �߰� ����

	cout << "============ �ſ� �ŷ�  ���� ���� ============" << endl;
	ShowCreditLevel();
	cout << "   �� ������ �� �ڸ� ���ڷ� �Է����ּ���. ��" << endl << endl;
	cout << " �� �߰������� �� �ڸ� ���ڷ� �Է����ּ���. ��" << endl << endl;;
	cout << "���¹�ȣ : "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			cout << endl;
			cout << "   �� �̹� ��ϵ� ���¹�ȣ�Դϴ�. ��" << endl;
			getchar();
			getchar();
			return;
		}
	}

	cout << "�� �� �� : "; cin >> name;
	cout << "��    �� : "; cin >> balance;

	if (balance < 0)
	{
		cout << "   �� �ݾ��� �ٽ� �Է����ּ���. ��" << endl;
		getchar();
		getchar();
		return;
	}

	cout << "�⺻���� : "; cin >> roi;
	cout << "�߰����� : "; cin >> proi;

	if (!(proi == LEVEL_A || proi == LEVEL_B || proi == LEVEL_C))
	{
		cout << "�� �߰� ������ �ٽ� �Է����ּ���. ��" << endl;
		getchar();
		getchar();
		return;
	}

	cout << "==============================================" << endl;
	accArr[accNum++] = new HighCreditAccount(id, balance, name, roi, proi);
	cout << "	�� ���°� �����Ǿ����ϴ�. ��" << endl;
	cout << "==============================================" << endl;
	getchar();
	getchar();

	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	} // ��
}

void AccountHandler::DepositMoney(void) const	// �Ա�
{
	system("cls");

	int money; // �Աݾ�
	int id;    // ���¹�ȣ

	cout << "=================== ��  �� ===================" << endl;
	cout << "���¹�ȣ : "; cin >> id;
	cout << "�� �� �� : "; cin >> money;
	cout << "==============================================" << endl;

	// ������? goto�� ������...

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			accArr[i]->setplusbalance(money);
			cout << "		�� �Ա� �Ϸ� ��" << endl;
			cout << "==============================================" << endl;
			getchar();
			getchar();
			break;
		}
		else
		{
			cout << "	�� ���� ���¹�ȣ�Դϴ�. ��" << endl;
			cout << "==============================================" << endl;
			getchar();
			getchar();
			return;
		}
	}
}

void AccountHandler::WithdrawMoney(void) const	// ���
{
	system("cls");

	int money;  // ��ݾ�
	int id;		// ���¹�ȣ

	cout << "=================== ��  �� ===================" << endl;
	cout << "���¹�ȣ : "; cin >> id;
	cout << "�� �� �� : "; cin >> money;
	cout << "==============================================" << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			if (accArr[i]->getbalance() < money)
			{
				cout << "	    �� �ܾ��� �����մϴ�. ��" << endl;
				cout << "==============================================" << endl;
				getchar();
				getchar();
				return;
			}

			accArr[i]->setminusbalance(money);
			cout << "		�� ��� �Ϸ� ��" << endl;
			cout << "==============================================" << endl;
			getchar();
			getchar();

			return;
		}
		else
		{
			cout << "	    �� ���� ���¹�ȣ�Դϴ�. ��" << endl;
			cout << "==============================================" << endl;
			getchar();
			getchar();
			return;
		}
	}
}

void AccountHandler::ShowAllAccInfo(void) const
{
	system("cls");

	for (int i = 0; i < accNum; i++)
	{
		cout << "==============================================" << endl;
		cout << "[ " << i + 1 << "��° �� ���� ]" << endl;
		cout << "���¹�ȣ : " << accArr[i]->getaccID() << endl;
		cout << "�� �� �� : " << accArr[i]->getcusName() << endl;
		cout << "��    �� : " << accArr[i]->getbalance() << endl;
		cout << "==============================================" << endl;
	}

	getchar();
	getchar();
}
