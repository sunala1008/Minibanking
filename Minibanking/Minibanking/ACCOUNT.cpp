#include "ACCOUNT.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

int ACCOUNT::getaccID() // ���¹�ȣ
{
	return accID;
}

int ACCOUNT::getbalance() // ���� �ܾ�
{
	return balance;
}

int ACCOUNT::getindx() // ���� ���� ����
{
	return indx;
}

char * ACCOUNT::getcusName() const // �� �̸�
{
	return cusName.getcusNamestr();
}

void ACCOUNT::setplusbalance(int money) //throw (D_Exception)// �Ա�, ����ó��
{
	balance += money;
}

void ACCOUNT::setminusbalance(int money) throw (W_Exception) // ���, ����ó��
{
	if (money > balance)
	{
		W_Exception expn(money); //throw �߻� => exception class
		throw expn;
	}

	balance -= money;
}

ACCOUNT::ACCOUNT(const ACCOUNT &copy) // default ���� ������
{
	accID = copy.accID;
	balance = copy.balance;
	cusName = copy.cusName;
}


//ACCOUNT::~ACCOUNT() // �Ҹ���
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

