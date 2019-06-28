#ifndef _CREDIT_H_
#define _CREDIT_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount // �ſ� �ŷ� ���� entity class
{
private:
	int roi;			// ����
	char trust;			// �ſ� ���

public:
	HighCreditAccount(const int indx, const int ID, const int Money,
						const String myname, const int rate, const char tru)
		: NormalAccount(indx, ID, Money, myname, rate, tru)
	{
		roi = rate;
		trust = tru;
	}
	
	void setplusbalance(int money);
	
	int getroi();

	char gettrust();
};

enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 }; // �ſ� ���

#endif // !_CREDIT_H_
