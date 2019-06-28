#include "MiniBankingCommonDecl.h"
#include "AccountHandlr.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

int ACCOUNT::getaccID()
{
	return accID;
}

int ACCOUNT::getbalance()
{
	return balance;
}

void ACCOUNT::setplusbalance(int money)
{
	balance += money;
}

void ACCOUNT::setminusbalance(int money)
{
	balance -= money;
}

char * ACCOUNT::getcusName()
{
	return cusName;
}

ACCOUNT::~ACCOUNT() // ¼Ò¸êÀÚ
{
	delete[]cusName;
}

// --------------------------------------------------------------

int NormalAccount::getroi()
{
	return roi;
}

void NormalAccount::setplusbalance(int money)
{
	ACCOUNT::setplusbalance(money + money * roi * 0.01);
}

// --------------------------------------------------------------

void HighCreditAccount::setplusbalance(int money)
{
	ACCOUNT::setplusbalance(money + money * ((getroi() + plusroi) * 0.01));
}