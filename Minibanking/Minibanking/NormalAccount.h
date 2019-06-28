#ifndef _NORMAL_H_
#define _NORMAL_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"

class NormalAccount : public ACCOUNT	// �Ϲ� ���� ���� entity class
{
private:
	int roi;	// ����
	char trust;	// �Ϲ� ���� ����

public:
	NormalAccount(const int indx, const int ID, const int Money, 
								const String myname, const int rate, const char tru)
		: ACCOUNT(indx, ID, Money, myname), roi(rate)
	{
		trust = tru;
	}

	void setplusbalance(int money);

	int getroi();

	char gettrust();
};

#endif // !_NORMAL_H_

