#include "ACCOUNT.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

int ACCOUNT::getaccID() // 계좌번호
{
	return accID;
}

int ACCOUNT::getbalance() // 계좌 잔액
{
	return balance;
}

int ACCOUNT::getindx() // 계좌 상태 구분
{
	return indx;
}

char * ACCOUNT::getcusName() const // 고객 이름
{
	return cusName.getcusNamestr();
}

void ACCOUNT::setplusbalance(int money) //throw (D_Exception)// 입금, 예외처리
{
	balance += money;
}

void ACCOUNT::setminusbalance(int money) throw (W_Exception) // 출금, 예외처리
{
	if (money > balance)
	{
		W_Exception expn(money); //throw 발생 => exception class
		throw expn;
	}

	balance -= money;
}

ACCOUNT::ACCOUNT(const ACCOUNT &copy) // default 복사 생성자
{
	accID = copy.accID;
	balance = copy.balance;
	cusName = copy.cusName;
}


//ACCOUNT::~ACCOUNT() // 소멸자
//{
//	delete[]cusName;
//}

// --------------------------------------------------------------

int NormalAccount::getroi()
{
	return roi;
}

char NormalAccount::gettrust()
{
	return trust;
}

void NormalAccount::setplusbalance(int money)
{
	ACCOUNT::setplusbalance(money + money * roi * 0.01);
}

// --------------------------------------------------------------

void HighCreditAccount::setplusbalance(int money)
{
	if (trust == 'A' || trust == 'a')
	{
		ACCOUNT::setplusbalance(money + money * ((getroi() + LEVEL_A) * 0.01));
	}
	else if (trust == 'B' || trust == 'b')
	{
		ACCOUNT::setplusbalance(money + money * ((getroi() + LEVEL_B) * 0.01));
	}
	else if (trust == 'C' || trust == 'c')
	{
		ACCOUNT::setplusbalance(money + money * ((getroi() + LEVEL_C) * 0.01));
	}
}

int HighCreditAccount::getroi()
{
	return roi;
}

char HighCreditAccount::gettrust()
{
	return trust;
}

