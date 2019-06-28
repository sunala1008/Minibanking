#include "AccountHandlr.h"
#include <windows.h>

AccountHandler::AccountHandler() : accNum(0){}

// ���� �Է����� ������ �������
void AccountHandler::FMNormalAcc(int indx, int ID, int balance, String Name, 
										   int rate, char tru)
{
	accArr[accNum++] = new NormalAccount(indx, ID, balance, Name, rate, tru);
}

// ���� �Է����� ������ �ſ����
void AccountHandler::FMHighCreditAcc(int indx, int ID, int balance, String Name, 
											   int rate, char tru)
{
	accArr[accNum++] = new HighCreditAccount(indx, ID, balance, Name, rate, tru);
}

void IO_File::input(AccountHandler &hand, ifstream &fin)
{
	if (!fin.is_open())
	{
		cout << "��������������������������������������������������" << endl;
		cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
		cout << "��\tACCOUNT.txt ������ �� �� �����ϴ�.\t��" << endl;
		cout << "��������������������������������������������������" << endl;
		getchar();
		getchar();
	}
	else
	{
		while (!fin.eof())
		{
			fin >> indx; 

			if (indx == NOR) {

				fin >> id;
				fin >> name;
				fin >> balance;
				fin	>> roi;

				hand.FMNormalAcc(indx, id, balance, name, roi, NULL);
			}
			else if (indx == CRE)
			{
				//fin >> id;
				//fin >> name;
				//fin >> balance;
				//fin >> roi;
				//fin >> trust; // io �� �������̸� ���� -> ���� => ????
				fin >> id;
				fin >> name;
				fin >> trust;
				fin >> balance;
				fin >> roi;

				hand.FMHighCreditAcc(indx, id, balance, name, roi, trust);
			}
		}
	}
}

void AccountHandler::AccMenu(void)
{
	int choice;

	while (1)
	{
		ShowAccMenu();
		cout << "�� �޴� ����  >>\t";
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
			cout << "��������������������������������������������������" << endl;
			cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
			cout << "��\t���� �޴��Դϴ�. �ٽ� �������ּ���.\t��" << endl;
			cout << "��������������������������������������������������" << endl;
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
	String name;			// �� ��
	int balance;			// �ݾ�
	int roi;				// ����
			
	try
	{
		if (accNum == MAXACCOUNT)
		{
			throw FULL_ACCOUNT(accNum);
		}

		cout << "�������������������Ϲ� ���� ����������������������" << endl;
		cout << "    �� ������ �� �ڸ� ���ڷ� �Է� ���ּ���. ��" << endl << endl;
		cout << "\t���¹�ȣ : "; cin >> id;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
				throw AlreadyRegiAcc();
		}

		cout << "\t�� �� �� : "; cin >> name;
		cout << "\t��    �� : "; cin >> balance;

		if (balance < 0)
			throw IntoMoney();
		
		cout << "\t��    �� : "; cin >> roi;

		cout << "��������������������������������������������������" << endl;
		accArr[accNum++] = new NormalAccount(NOR, id, balance, name, roi, NULL);
		
		cout << "��������������������������������������������������" << endl;
		cout << "��\t       �� ���� ���� �Ϸ� �� \t\t��" << endl;
		cout << "��������������������������������������������������" << endl;

		getchar();
		getchar();
	}
	catch (IntoMoney& expn)
	{
		expn.ShowIntoMoney();
		NormalMakeAccount();
	}
	catch (FULL_ACCOUNT& expn)
	{
		expn.ShowAccFull();
	}
	catch (AlreadyRegiAcc& expn)
	{
		expn.ShowAlreadyRegi();
		NormalMakeAccount();
	}
}

void AccountHandler::CreditMakeAccount(void)	// �ſ� ���� ����
{
	system("cls");

	int id;					// ���� ��ȣ
	String name;			// �� ��
	int balance;			// �ܾ�
	int roi;				// �⺻ ����
	char trust;				// �ſ���

	try
	{
		if (accNum == MAXACCOUNT)
		{
			throw FULL_ACCOUNT(accNum);
		}
		cout << "�������������������ſ� ���� ����������������������" << endl << endl;
		ShowCreditLevel();
		cout << "    �� ������ �� �ڸ� ���ڷ� �Է� ���ּ���. ��" << endl << endl;
		cout << "\t���¹�ȣ : "; cin >> id;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
				throw AlreadyRegiAcc();
		}

		cout << "\t�� �� �� : "; cin >> name;
		cout << "\t��    �� : "; cin >> balance;

		if (balance < 0)
			throw IntoMoney();

		cout << "\t�⺻���� : "; cin >> roi;
		cout << "\t�ſ��� : "; cin >> trust;

		if (!(trust == 'A' || trust == 'a' || trust == 'B' ||
			trust == 'b' || trust == 'C' || trust == 'c'))
			throw GradeErr();

		cout << "��������������������������������������������������" << endl;
		accArr[accNum++] = new HighCreditAccount(CRE, id, balance, name, roi, trust);

		cout << "��������������������������������������������������" << endl;
		cout << "��\t       �� ���� ���� �Ϸ� �� \t\t��" << endl;
		cout << "��������������������������������������������������" << endl;
		getchar();
		getchar();
	}
	catch (GradeErr& expn)
	{
		expn.ShowGradeErr();
		CreditMakeAccount();
	}
	catch (IntoMoney& expn)
	{
		expn.ShowIntoMoney();
		CreditMakeAccount();
	}
	catch (FULL_ACCOUNT& expn)
	{
		expn.ShowAccFull();
	}
	catch (AlreadyRegiAcc& expn)
	{
		expn.ShowAlreadyRegi();
		CreditMakeAccount();
	}
}

void AccountHandler::DepositMoney(void) const	// �Ա�
{
	system("cls");

	try
	{
		int money; // �Աݾ�
		int id;    // ���¹�ȣ

		cout << "�������������������� ��    �� ��������������������" << endl;
		cout << "\t���¹�ȣ : "; cin >> id;
		cout << "\t�� �� �� : "; cin >> money;
		cout << "��������������������������������������������������" << endl;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
			{
				accArr[i]->setplusbalance(money);

				if (money < 0)
					throw D_Exception(money);
				cout << "��������������������������������������������������" << endl;
				cout << "��\t\t �� �Ա� �Ϸ� �� \t\t��" << endl;
				cout << "��������������������������������������������������" << endl;
				getchar();
				getchar();
				return;
			}
		}

		cout << "��������������������������������������������������" << endl;
		cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
		cout << "��\t   ���� ��ȣ�� ã�� �� �����ϴ�.     \t��" << endl;
		cout << "��������������������������������������������������" << endl;
		getchar();
		getchar();
	}
	catch (A_Exception &expn)
	{
		expn.ShowExceptionReason();
		DepositMoney();
	}
}

void AccountHandler::WithdrawMoney(void) const	// ���
{
	system("cls");
	
	try
	{
		int money;  // ��ݾ�
		int id;		// ���¹�ȣ
	
		cout << "�������������������� ��    �� ��������������������" << endl;
		cout << "\t���¹�ȣ : "; cin >> id;
		cout << "\t�� �� �� : "; cin >> money;
		cout << "��������������������������������������������������" << endl;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
			{
				if (money < 0)
					throw NoMinusMoney(money);

				accArr[i]->setminusbalance(money);

				cout << "��������������������������������������������������" << endl;
				cout << "��\t\t �� ��� �Ϸ� �� \t\t��" << endl;
				cout << "��������������������������������������������������" << endl;
				getchar();
				getchar();
				return;
			}
		}

		cout << "��������������������������������������������������" << endl;
		cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
		cout << "��\t   ���� ��ȣ�� ã�� �� �����ϴ�.     \t��" << endl;
		cout << "��������������������������������������������������" << endl;
		getchar();
		getchar();
	}
	catch (NoMinusMoney& expn)
	{
		expn.ShowNoMinusMoney();
		WithdrawMoney();
	}
	catch (A_Exception& expn)
	{
		expn.ShowExceptionReason();
		WithdrawMoney();
	}
}

void AccountHandler::ShowAccInfo(void) const
{
	system("cls");

	for (int i = 0; i < accNum; i++)
	{		
		if (accArr[i]->getindx() == NOR)
		{
			cout << "��������������������  ��  ��  ��������������������" << endl;
			cout << "\t���¹�ȣ : " << accArr[i]->getaccID() << endl;
			cout << "\t�� �� �� : " << accArr[i]->getcusName() << endl;
			cout << "\t��    �� : " << accArr[i]->getbalance() << "��" << endl;
			cout << "\t��    �� : " << accArr[i]->getroi() << '%' << endl;
			cout << "��������������������������������������������������" << endl << endl;
		}	
		else
		{
			cout << "��������������������  ��  ��  ��������������������" << endl;
			cout << "\t���¹�ȣ : " << accArr[i]->getaccID() << endl;
			cout << "\t�� �� �� : " << accArr[i]->getcusName() << endl;
			cout << "\t��    �� : " << accArr[i]->getbalance() << "��" << endl;
			cout << "\t��    �� : " << accArr[i]->getroi() << '%' << endl;
			cout << "\t�ſ��� : " << accArr[i]->gettrust() << "���" << endl;
			cout << "��������������������������������������������������" << endl << endl;
		}
	}

	getchar();
	getchar();
}

AccountHandler::~AccountHandler()
{
	ofstream fout("ACCOUNT.txt");

	if (fout.fail())
	{
		cout << "��������������������������������������������������" << endl;
		cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
		cout << "��\tACCOUNT.txt ������ �� �� �����ϴ�.\t��" << endl;
		cout << "��������������������������������������������������" << endl;
		return;
	}

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getindx() == NOR)	// �Ϲ� ����
		{
			fout << accArr[i]->getindx() << '\t'
				<< accArr[i]->getaccID() << '\t'
				<< accArr[i]->getcusName() << '\t'
				<< accArr[i]->getbalance() << '\t'
				<< accArr[i]->getroi();
		}
		else			   // �ſ� ����
		{
			fout << accArr[i]->getindx() << '\t'
				<< accArr[i]->getaccID() << '\t'
				<< accArr[i]->getcusName() << '\t'
				<< accArr[i]->gettrust() << '\t'  // ������ ���� ����
				<< accArr[i]->getbalance() << '\t'
				<< accArr[i]->getroi();
		}
		 
		if (i != accNum - 1) 
		{
			fout << "\n";	// �� Ŀ�� �ű�� ��
		}

		delete accArr[i];
	}
	
	fout.close();
}

