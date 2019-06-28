#include "AccountHandlr.h"
#include <windows.h>

AccountHandler::AccountHandler() : accNum(0){}

// ÆÄÀÏ ÀÔ·ÂÀ¸·Î »ý¼ºµÈ º¸Åë°èÁÂ
void AccountHandler::FMNormalAcc(int indx, int ID, int balance, String Name, 
										   int rate, char tru)
{
	accArr[accNum++] = new NormalAccount(indx, ID, balance, Name, rate, tru);
}

// ÆÄÀÏ ÀÔ·ÂÀ¸·Î »ý¼ºµÈ ½Å¿ë°èÁÂ
void AccountHandler::FMHighCreditAcc(int indx, int ID, int balance, String Name, 
											   int rate, char tru)
{
	accArr[accNum++] = new HighCreditAccount(indx, ID, balance, Name, rate, tru);
}

void IO_File::input(AccountHandler &hand, ifstream &fin)
{
	if (!fin.is_open())
	{
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢\t\t   ¡Ø °æ °í ¡Ø     \t\t¦¢" << endl;
		cout << "¦¢\tACCOUNT.txt ÆÄÀÏÀ» ¿­ ¼ö ¾ø½À´Ï´Ù.\t¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
				//fin >> trust; // io ¸Ç ¸¶Áö¸·ÀÌ¸é ¿À·ù -> º¹»ç => ????
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
		cout << "¢¹ ¸Þ´º ¼±ÅÃ  >>\t";
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
			cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
			cout << "¦¢\t\t   ¡Ø °æ °í ¡Ø     \t\t¦¢" << endl;
			cout << "¦¢\t¾ø´Â ¸Þ´ºÀÔ´Ï´Ù. ´Ù½Ã ¼±ÅÃÇØÁÖ¼¼¿ä.\t¦¢" << endl;
			cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
			getchar();
			getchar();
		}

		if (choice == UP)
			break;
	}
}

void AccountHandler::NormalMakeAccount(void)	// ÀÏ¹Ý °èÁÂ °³¼³
{
	system("cls");

	int id;					// °èÁÂ ¹øÈ£
	String name;			// °í°´ ¸í
	int balance;			// ±Ý¾×
	int roi;				// ÀÌÀ²
			
	try
	{
		if (accNum == MAXACCOUNT)
		{
			throw FULL_ACCOUNT(accNum);
		}

		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ÀÏ¹Ý °èÁÂ °³¼³¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "    ¡Ø ÀÌÀ²Àº ÇÑ ÀÚ¸® ¼ýÀÚ·Î ÀÔ·Â ÇØÁÖ¼¼¿ä. ¡Ø" << endl << endl;
		cout << "\t°èÁÂ¹øÈ£ : "; cin >> id;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
				throw AlreadyRegiAcc();
		}

		cout << "\t°í °´ ¸í : "; cin >> name;
		cout << "\t±Ý    ¾× : "; cin >> balance;

		if (balance < 0)
			throw IntoMoney();
		
		cout << "\tÀÌ    À² : "; cin >> roi;

		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		accArr[accNum++] = new NormalAccount(NOR, id, balance, name, roi, NULL);
		
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢\t       ¢Ý °èÁÂ »ý¼º ¿Ï·á ¢Ý \t\t¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;

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

void AccountHandler::CreditMakeAccount(void)	// ½Å¿ë °èÁÂ °³¼³
{
	system("cls");

	int id;					// °èÁÂ ¹øÈ£
	String name;			// °í°´ ¸í
	int balance;			// ÀÜ¾×
	int roi;				// ±âº» ÀÌÀ²
	char trust;				// ½Å¿ëµî±Þ

	try
	{
		if (accNum == MAXACCOUNT)
		{
			throw FULL_ACCOUNT(accNum);
		}
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡½Å¿ë °èÁÂ °³¼³¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl << endl;
		ShowCreditLevel();
		cout << "    ¡Ø ÀÌÀ²Àº ÇÑ ÀÚ¸® ¼ýÀÚ·Î ÀÔ·Â ÇØÁÖ¼¼¿ä. ¡Ø" << endl << endl;
		cout << "\t°èÁÂ¹øÈ£ : "; cin >> id;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
				throw AlreadyRegiAcc();
		}

		cout << "\t°í °´ ¸í : "; cin >> name;
		cout << "\tÀÜ    ¾× : "; cin >> balance;

		if (balance < 0)
			throw IntoMoney();

		cout << "\t±âº»ÀÌÀ² : "; cin >> roi;
		cout << "\t½Å¿ëµî±Þ : "; cin >> trust;

		if (!(trust == 'A' || trust == 'a' || trust == 'B' ||
			trust == 'b' || trust == 'C' || trust == 'c'))
			throw GradeErr();

		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		accArr[accNum++] = new HighCreditAccount(CRE, id, balance, name, roi, trust);

		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢\t       ¢Ý °èÁÂ »ý¼º ¿Ï·á ¢Ý \t\t¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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

void AccountHandler::DepositMoney(void) const	// ÀÔ±Ý
{
	system("cls");

	try
	{
		int money; // ÀÔ±Ý¾×
		int id;    // °èÁÂ¹øÈ£

		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ ÀÔ    ±Ý ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "\t°èÁÂ¹øÈ£ : "; cin >> id;
		cout << "\tÀÔ ±Ý ¾× : "; cin >> money;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
			{
				accArr[i]->setplusbalance(money);

				if (money < 0)
					throw D_Exception(money);
				cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
				cout << "¦¢\t\t ¢Ý ÀÔ±Ý ¿Ï·á ¢Ý \t\t¦¢" << endl;
				cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
				getchar();
				getchar();
				return;
			}
		}

		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢\t\t   ¡Ø °æ °í ¡Ø     \t\t¦¢" << endl;
		cout << "¦¢\t   °èÁÂ ¹øÈ£¸¦ Ã£À» ¼ö ¾ø½À´Ï´Ù.     \t¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		getchar();
		getchar();
	}
	catch (A_Exception &expn)
	{
		expn.ShowExceptionReason();
		DepositMoney();
	}
}

void AccountHandler::WithdrawMoney(void) const	// Ãâ±Ý
{
	system("cls");
	
	try
	{
		int money;  // Ãâ±Ý¾×
		int id;		// °èÁÂ¹øÈ£
	
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ Ãâ    ±Ý ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "\t°èÁÂ¹øÈ£ : "; cin >> id;
		cout << "\tÃâ ±Ý ¾× : "; cin >> money;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
			{
				if (money < 0)
					throw NoMinusMoney(money);

				accArr[i]->setminusbalance(money);

				cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
				cout << "¦¢\t\t ¢Ý Ãâ±Ý ¿Ï·á ¢Ý \t\t¦¢" << endl;
				cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
				getchar();
				getchar();
				return;
			}
		}

		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢\t\t   ¡Ø °æ °í ¡Ø     \t\t¦¢" << endl;
		cout << "¦¢\t   °èÁÂ ¹øÈ£¸¦ Ã£À» ¼ö ¾ø½À´Ï´Ù.     \t¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
			cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ÀÏ  ¹Ý  °í  °´¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
			cout << "\t°èÁÂ¹øÈ£ : " << accArr[i]->getaccID() << endl;
			cout << "\t°í °´ ¸í : " << accArr[i]->getcusName() << endl;
			cout << "\tÀÜ    ¾× : " << accArr[i]->getbalance() << "¿ø" << endl;
			cout << "\tÀÌ    À² : " << accArr[i]->getroi() << '%' << endl;
			cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl << endl;
		}	
		else
		{
			cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡½Å  ¿ë  °í  °´¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
			cout << "\t°èÁÂ¹øÈ£ : " << accArr[i]->getaccID() << endl;
			cout << "\t°í °´ ¸í : " << accArr[i]->getcusName() << endl;
			cout << "\tÀÜ    ¾× : " << accArr[i]->getbalance() << "¿ø" << endl;
			cout << "\tÀÌ    À² : " << accArr[i]->getroi() << '%' << endl;
			cout << "\t½Å¿ëµî±Þ : " << accArr[i]->gettrust() << "µî±Þ" << endl;
			cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢\t\t   ¡Ø °æ °í ¡Ø     \t\t¦¢" << endl;
		cout << "¦¢\tACCOUNT.txt ÆÄÀÏÀ» ¿­ ¼ö ¾ø½À´Ï´Ù.\t¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		return;
	}

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getindx() == NOR)	// ÀÏ¹Ý °èÁÂ
		{
			fout << accArr[i]->getindx() << '\t'
				<< accArr[i]->getaccID() << '\t'
				<< accArr[i]->getcusName() << '\t'
				<< accArr[i]->getbalance() << '\t'
				<< accArr[i]->getroi();
		}
		else			   // ½Å¿ë °èÁÂ
		{
			fout << accArr[i]->getindx() << '\t'
				<< accArr[i]->getaccID() << '\t'
				<< accArr[i]->getcusName() << '\t'
				<< accArr[i]->gettrust() << '\t'  // ¸¶Áö¸· °¡¸é ¿À·ù
				<< accArr[i]->getbalance() << '\t'
				<< accArr[i]->getroi();
		}
		 
		if (i != accNum - 1) 
		{
			fout << "\n";	// ¡Ú Ä¿¼­ ¿Å±â±â ¡Ù
		}

		delete accArr[i];
	}
	
	fout.close();
}

