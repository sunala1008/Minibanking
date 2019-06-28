#include <iostream>
#include <string>

using namespace std;

const int NAME_LEN = 50;	// 이름 문자열

class ACCOUNT
{
private:
	int accID;		// 계좌번호
	int balance;	// 잔액
	char * cusName; // 고객 이름

public:
	ACCOUNT(const int ID, const int money, const char * myname) // 생성자
		: accID(ID), balance(money)
	{
		int len = strlen(myname) + 1;
		cusName = new char[len];
		strcpy(cusName, myname);
	}

	ACCOUNT(const ACCOUNT &copy) // default 복사 생성자
		: accID(copy.accID), balance(copy.balance)
	{
		cusName = new char[strlen(copy.cusName) + 1];
		strcpy(cusName, copy.cusName);
	}

	int getaccID()
	{
		return accID;
	}

	int getbalance()
	{
		return balance;
	}

	void setplusbalance(int money) 
	{							   
		balance += money;		   
	}

	void setminusbalance(int money) 
	{								
		balance -= money;			
	}

	char * getcusName() 
	{					
		return cusName;
	}

	~ACCOUNT() // 소멸자
	{
		delete[]cusName;
	}
};

class AccountHandler
{
private:
	ACCOUNT * accArr[100];		// 계좌를 관리할 배열
	int accNum = 0;				// 개설된 계좌 수 

public:
	AccountHandler() : accNum(0) // 생성자
	{}

	/*void AddAccount(ACCOUNT *acc)
	{
		accArr[accNum++] = acc;
	}*/

	void MakeAccount(void);								// 계좌 개설 
	void DepositMoney(void) const;						// 입금
	void WithdrawMoney(void) const;						// 출금
	void ShowAllAccInfo(void) const; 					// 잔액조회
};

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };	// 메뉴용 열거자 
void ShowMenu(void);									// 메뉴 출력

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
			ACC.MakeAccount();
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
			return 0;
		default:
			cout << "※ 없는 메뉴입니다. 다시 선택해주세요. ※" << endl << endl;
			getchar();
			getchar();
		}
	}

	return 0;
}

void ShowMenu(void)
{
	system("cls");

	cout << "============ Menu ============" << endl;
	cout << "	 1. 계좌개설" << endl;
	cout << "	 2. 입    금" << endl;
	cout << "	 3. 출    금" << endl;
	cout << "	 4. 전체출력" << endl;
	cout << "	 5. 종    료" << endl;
	cout << "==============================" << endl;
}

void AccountHandler::MakeAccount(void)	// 계좌 개설
{
	system("cls");

	//AccountHandler acc;

	int id;					// 계좌 번호
	char name[NAME_LEN];	// 고객 명
	int balance;			// 잔액

	cout << "========== 계좌개설 ==========" << endl;
	cout << "계좌번호 : "; cin >> id;
	cout << "고객명   : "; cin >> name;
	cout << "잔액     : "; cin >> balance;
	cout << "==============================" << endl;
	accArr[accNum++] = new ACCOUNT(id, balance, name);
	//acc.AddAccount(new ACCOUNT(id, balance, name));
	cout << "☞ 계좌가 생성되었습니다. ☜" << endl;
	cout << "==============================" << endl;
	getchar();
	getchar();
}

void AccountHandler::DepositMoney(void) const	// 입금
{
	system("cls");

	int money; // 입금액
	int id;    // 계좌번호

	cout << "=========== 입  금 ===========" << endl;
	cout << "계좌번호 : "; cin >> id;
	cout << "입금액   : "; cin >> money;
	cout << "==============================" << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			accArr[i]->setplusbalance(money);
			cout << "	♬ 입금 완료 ♬" << endl;
			cout << "==============================" << endl;
			getchar();
			getchar();

			return;

			if (!(accArr[i]->getaccID() == id))
			{
				cout << "※ 없는 계좌번호입니다. ※" << endl;
				cout << "==============================" << endl;
				getchar();
				getchar();

				return;
			}
		}
	}
}

void AccountHandler::WithdrawMoney(void) const	// 출금
{
	system("cls");

	int money;  // 출금액
	int id;		// 계좌번호

	cout << "=========== 출  금 ===========" << endl;
	cout << "계좌번호 : "; cin >> id;
	cout << "출금액   : "; cin >> money;
	cout << "==============================" << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccID() == id)
		{
			if (accArr[i]->getbalance() < money)
			{
				cout << "※ 잔액이 부족합니다. ※" << endl;
				cout << "==============================" << endl;
				getchar();
				getchar();

				return;
			}

			if (!(accArr[i]->getaccID() == id))
			{
				cout << "※ 없는 계좌번호입니다. ※" << endl;
				cout << "==============================" << endl;
				getchar();
				getchar();

				return;
			}

			accArr[i]->setminusbalance(money);
			cout << "	♬ 출금 완료 ♬" << endl;
			cout << "==============================" << endl;
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
		cout << "==============================" << endl;
		cout << "[ " << i + 1 << "번째 고객 정보 ]" << endl;
		cout << "계좌번호 : " << accArr[i]->getaccID() << endl;
		cout << "고 객 명 : " << accArr[i]->getcusName() << endl;
		cout << "잔    액 : " << accArr[i]->getbalance() << endl;
		cout << "==============================" << endl;
		cout << endl;
	}

	getchar();
	getchar();
}
