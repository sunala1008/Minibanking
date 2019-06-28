#include "MiniBankingCommonDecl.h"
#include "AccountHandlr.h"

void AccountHandler::AccMenu(void)
{
	int choice;

	while (1)
	{
		ShowAccMenu();
		cout << "메뉴 선택 : ";
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
			cout << "※ 없는 메뉴입니다. 다시 선택해주세요. ※" << endl << endl;
			getchar();
			getchar();
		}

		if (choice == UP)
			break;
	}
}

void AccountHandler::NormalMakeAccount(void)	// 일반 계좌 개설
{
	system("cls");

	int id;					// 계좌 번호
	char name[50];			// 고객 명
	int balance;			// 금액
	int roi;				// 이율

	cout << "=============== 일반 계좌 개설 ===============" << endl;
	cout << "  ※ 이율은 한 자리 숫자로 입력 해주세요. ※" << endl << endl;
	cout << "계좌번호 : "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			cout << endl;
			cout << "   ※ 이미 등록된 계좌번호입니다. ※" << endl;
			getchar();
			getchar();
			return;
		}
	}

	cout << "고 객 명 : "; cin >> name;
	cout << "금    액 : "; cin >> balance;

	if (balance < 0)
	{
		cout << "   ※ 금액을 다시 입력해주세요. ※" << endl;
		getchar();
		getchar();
		return;
	}

	cout << "이    율 : "; cin >> roi;
	cout << "==============================================" << endl;
	accArr[accNum++] = new NormalAccount(id, balance, name, roi);
	cout << "	☞ 계좌가 생성되었습니다. ☜" << endl;
	cout << "==============================================" << endl;
	getchar();
	getchar();

	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	} // ♠
}

void AccountHandler::CreditMakeAccount(void)	// 신용 계좌 개설
{
	system("cls");

	int id;					// 계좌 번호
	char name[50];			// 고객 명
	int balance;			// 잔액
	int roi;				// 기본 이율
	int proi;				// 추가 이율

	cout << "============ 신용 신뢰  계좌 개설 ============" << endl;
	ShowCreditLevel();
	cout << "   ※ 이율은 한 자리 숫자로 입력해주세요. ※" << endl << endl;
	cout << " ※ 추가이율도 한 자리 숫자로 입력해주세요. ※" << endl << endl;;
	cout << "계좌번호 : "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			cout << endl;
			cout << "   ※ 이미 등록된 계좌번호입니다. ※" << endl;
			getchar();
			getchar();
			return;
		}
	}

	cout << "고 객 명 : "; cin >> name;
	cout << "잔    액 : "; cin >> balance;

	if (balance < 0)
	{
		cout << "   ※ 금액을 다시 입력해주세요. ※" << endl;
		getchar();
		getchar();
		return;
	}

	cout << "기본이율 : "; cin >> roi;
	cout << "추가이율 : "; cin >> proi;

	if (!(proi == LEVEL_A || proi == LEVEL_B || proi == LEVEL_C))
	{
		cout << "※ 추가 이율을 다시 입력해주세요. ※" << endl;
		getchar();
		getchar();
		return;
	}

	cout << "==============================================" << endl;
	accArr[accNum++] = new HighCreditAccount(id, balance, name, roi, proi);
	cout << "	☞ 계좌가 생성되었습니다. ☜" << endl;
	cout << "==============================================" << endl;
	getchar();
	getchar();

	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	} // ♠
}

void AccountHandler::DepositMoney(void) const	// 입금
{
	system("cls");

	int money; // 입금액
	int id;    // 계좌번호

	cout << "=================== 입  금 ===================" << endl;
	cout << "계좌번호 : "; cin >> id;
	cout << "입 금 액 : "; cin >> money;
	cout << "==============================================" << endl;

	// 적당한? goto는 괜찮대...

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			accArr[i]->setplusbalance(money);
			cout << "		♬ 입금 완료 ♬" << endl;
			cout << "==============================================" << endl;
			getchar();
			getchar();
			break;
		}
		else
		{
			cout << "	※ 없는 계좌번호입니다. ※" << endl;
			cout << "==============================================" << endl;
			getchar();
			getchar();
			return;
		}
	}
}

void AccountHandler::WithdrawMoney(void) const	// 출금
{
	system("cls");

	int money;  // 출금액
	int id;		// 계좌번호

	cout << "=================== 출  금 ===================" << endl;
	cout << "계좌번호 : "; cin >> id;
	cout << "출 금 액 : "; cin >> money;
	cout << "==============================================" << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			if (accArr[i]->getbalance() < money)
			{
				cout << "	    ※ 잔액이 부족합니다. ※" << endl;
				cout << "==============================================" << endl;
				getchar();
				getchar();
				return;
			}

			accArr[i]->setminusbalance(money);
			cout << "		♬ 출금 완료 ♬" << endl;
			cout << "==============================================" << endl;
			getchar();
			getchar();

			return;
		}
		else
		{
			cout << "	    ※ 없는 계좌번호입니다. ※" << endl;
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
		cout << "[ " << i + 1 << "번째 고객 정보 ]" << endl;
		cout << "계좌번호 : " << accArr[i]->getaccID() << endl;
		cout << "고 객 명 : " << accArr[i]->getcusName() << endl;
		cout << "잔    액 : " << accArr[i]->getbalance() << endl;
		cout << "==============================================" << endl;
	}

	getchar();
	getchar();
}
