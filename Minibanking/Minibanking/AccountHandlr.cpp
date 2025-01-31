#include "AccountHandlr.h"
#include <windows.h>

AccountHandler::AccountHandler() : accNum(0){}

// だ橾 殮溘戲煎 儅撩脹 爾鱔啗謝
void AccountHandler::FMNormalAcc(int indx, int ID, int balance, String Name, 
										   int rate, char tru)
{
	accArr[accNum++] = new NormalAccount(indx, ID, balance, Name, rate, tru);
}

// だ橾 殮溘戲煎 儅撩脹 褐辨啗謝
void AccountHandler::FMHighCreditAcc(int indx, int ID, int balance, String Name, 
											   int rate, char tru)
{
	accArr[accNum++] = new HighCreditAccount(indx, ID, balance, Name, rate, tru);
}

void IO_File::input(AccountHandler &hand, ifstream &fin)
{
	if (!fin.is_open())
	{
		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛\t\t   ≦ 唳 堅 ≦     \t\t弛" << endl;
		cout << "弛\tACCOUNT.txt だ橾擊 翮 熱 橈蝗棲棻.\t弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
				//fin >> trust; // io 裔 葆雖虞檜賊 螃盟 -> 犒餌 => ????
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
		cout << "Ⅰ 詭景 摹鷗  >>\t";
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
			cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
			cout << "弛\t\t   ≦ 唳 堅 ≦     \t\t弛" << endl;
			cout << "弛\t橈朝 詭景殮棲棻. 棻衛 摹鷗п輿撮蹂.\t弛" << endl;
			cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
			getchar();
			getchar();
		}

		if (choice == UP)
			break;
	}
}

void AccountHandler::NormalMakeAccount(void)	// 橾奩 啗謝 偃撲
{
	system("cls");

	int id;					// 啗謝 廓��
	String name;			// 堅偌 貲
	int balance;			// 旎擋
	int roi;				// 檜徽
			
	try
	{
		if (accNum == MAXACCOUNT)
		{
			throw FULL_ACCOUNT(accNum);
		}

		cout << "忙式式式式式式式式橾奩 啗謝 偃撲式式式式式式式式忖" << endl;
		cout << "    ≦ 檜徽擎 и 濠葬 璋濠煎 殮溘 п輿撮蹂. ≦" << endl << endl;
		cout << "\t啗謝廓�� : "; cin >> id;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
				throw AlreadyRegiAcc();
		}

		cout << "\t堅 偌 貲 : "; cin >> name;
		cout << "\t旎    擋 : "; cin >> balance;

		if (balance < 0)
			throw IntoMoney();
		
		cout << "\t檜    徽 : "; cin >> roi;

		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		accArr[accNum++] = new NormalAccount(NOR, id, balance, name, roi, NULL);
		
		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛\t       Ｏ 啗謝 儅撩 諫猿 Ｏ \t\t弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;

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

void AccountHandler::CreditMakeAccount(void)	// 褐辨 啗謝 偃撲
{
	system("cls");

	int id;					// 啗謝 廓��
	String name;			// 堅偌 貲
	int balance;			// 濤擋
	int roi;				// 晦獄 檜徽
	char trust;				// 褐辨蛔晝

	try
	{
		if (accNum == MAXACCOUNT)
		{
			throw FULL_ACCOUNT(accNum);
		}
		cout << "忙式式式式式式式式褐辨 啗謝 偃撲式式式式式式式式忖" << endl << endl;
		ShowCreditLevel();
		cout << "    ≦ 檜徽擎 и 濠葬 璋濠煎 殮溘 п輿撮蹂. ≦" << endl << endl;
		cout << "\t啗謝廓�� : "; cin >> id;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
				throw AlreadyRegiAcc();
		}

		cout << "\t堅 偌 貲 : "; cin >> name;
		cout << "\t濤    擋 : "; cin >> balance;

		if (balance < 0)
			throw IntoMoney();

		cout << "\t晦獄檜徽 : "; cin >> roi;
		cout << "\t褐辨蛔晝 : "; cin >> trust;

		if (!(trust == 'A' || trust == 'a' || trust == 'B' ||
			trust == 'b' || trust == 'C' || trust == 'c'))
			throw GradeErr();

		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		accArr[accNum++] = new HighCreditAccount(CRE, id, balance, name, roi, trust);

		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛\t       Ｏ 啗謝 儅撩 諫猿 Ｏ \t\t弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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

void AccountHandler::DepositMoney(void) const	// 殮旎
{
	system("cls");

	try
	{
		int money; // 殮旎擋
		int id;    // 啗謝廓��

		cout << "忙式式式式式式式式式 殮    旎 式式式式式式式式式忖" << endl;
		cout << "\t啗謝廓�� : "; cin >> id;
		cout << "\t殮 旎 擋 : "; cin >> money;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
			{
				accArr[i]->setplusbalance(money);

				if (money < 0)
					throw D_Exception(money);
				cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
				cout << "弛\t\t Ｏ 殮旎 諫猿 Ｏ \t\t弛" << endl;
				cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
				getchar();
				getchar();
				return;
			}
		}

		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛\t\t   ≦ 唳 堅 ≦     \t\t弛" << endl;
		cout << "弛\t   啗謝 廓�ㄧ� 瓊擊 熱 橈蝗棲棻.     \t弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		getchar();
		getchar();
	}
	catch (A_Exception &expn)
	{
		expn.ShowExceptionReason();
		DepositMoney();
	}
}

void AccountHandler::WithdrawMoney(void) const	// 轎旎
{
	system("cls");
	
	try
	{
		int money;  // 轎旎擋
		int id;		// 啗謝廓��
	
		cout << "忙式式式式式式式式式 轎    旎 式式式式式式式式式忖" << endl;
		cout << "\t啗謝廓�� : "; cin >> id;
		cout << "\t轎 旎 擋 : "; cin >> money;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->getaccID() == id)
			{
				if (money < 0)
					throw NoMinusMoney(money);

				accArr[i]->setminusbalance(money);

				cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
				cout << "弛\t\t Ｏ 轎旎 諫猿 Ｏ \t\t弛" << endl;
				cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
				getchar();
				getchar();
				return;
			}
		}

		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛\t\t   ≦ 唳 堅 ≦     \t\t弛" << endl;
		cout << "弛\t   啗謝 廓�ㄧ� 瓊擊 熱 橈蝗棲棻.     \t弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
			cout << "忙式式式式式式式式橾  奩  堅  偌式式式式式式式式忖" << endl;
			cout << "\t啗謝廓�� : " << accArr[i]->getaccID() << endl;
			cout << "\t堅 偌 貲 : " << accArr[i]->getcusName() << endl;
			cout << "\t濤    擋 : " << accArr[i]->getbalance() << "錳" << endl;
			cout << "\t檜    徽 : " << accArr[i]->getroi() << '%' << endl;
			cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl << endl;
		}	
		else
		{
			cout << "忙式式式式式式式式褐  辨  堅  偌式式式式式式式式忖" << endl;
			cout << "\t啗謝廓�� : " << accArr[i]->getaccID() << endl;
			cout << "\t堅 偌 貲 : " << accArr[i]->getcusName() << endl;
			cout << "\t濤    擋 : " << accArr[i]->getbalance() << "錳" << endl;
			cout << "\t檜    徽 : " << accArr[i]->getroi() << '%' << endl;
			cout << "\t褐辨蛔晝 : " << accArr[i]->gettrust() << "蛔晝" << endl;
			cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl << endl;
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
		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛\t\t   ≦ 唳 堅 ≦     \t\t弛" << endl;
		cout << "弛\tACCOUNT.txt だ橾擊 翮 熱 橈蝗棲棻.\t弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		return;
	}

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getindx() == NOR)	// 橾奩 啗謝
		{
			fout << accArr[i]->getindx() << '\t'
				<< accArr[i]->getaccID() << '\t'
				<< accArr[i]->getcusName() << '\t'
				<< accArr[i]->getbalance() << '\t'
				<< accArr[i]->getroi();
		}
		else			   // 褐辨 啗謝
		{
			fout << accArr[i]->getindx() << '\t'
				<< accArr[i]->getaccID() << '\t'
				<< accArr[i]->getcusName() << '\t'
				<< accArr[i]->gettrust() << '\t'  // 葆雖虞 陛賊 螃盟
				<< accArr[i]->getbalance() << '\t'
				<< accArr[i]->getroi();
		}
		 
		if (i != accNum - 1) 
		{
			fout << "\n";	// ≠ 醴憮 衡晦晦 ≧
		}

		delete accArr[i];
	}
	
	fout.close();
}

