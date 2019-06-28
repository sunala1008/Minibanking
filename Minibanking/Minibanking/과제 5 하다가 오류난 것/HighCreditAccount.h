#ifndef _CREDIT_H_
#define _CREDIT_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount	// �ſ� �ŷ� ���� entity class
{
private:
	int plusroi;		// �߰� ����

public:
	HighCreditAccount(const int ID, const int Money,
		const char * myname, const int rate, const int prate)
		: NormalAccount(ID, Money, myname, rate)
	{
		plusroi = prate;
	}

	//HighCreditAccount(const HighCreditAccount &copy) // default ���� ������
	//	: NormalAccount(copy.getaccID, copy.getbalance, copy.getcusName, copy.getroi),
	//		plusroi(copy.plusroi)
	//{	}

	void setplusbalance(int money);
};

enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 }; // �ſ� ���

#endif // !_CREDIT_H_
