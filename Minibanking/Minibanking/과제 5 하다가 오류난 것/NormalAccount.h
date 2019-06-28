#ifndef _NORMAL_H_
#define _NORMAL_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"

class NormalAccount : public ACCOUNT	// 일반 예금 계좌 entity class
{
private:
	int roi;		// 이율

public:
	NormalAccount(const int ID, const int Money, const char * myname, const int rate)
		: ACCOUNT(ID, Money, myname), roi(rate)
	{}
	
	int getroi();
	void setplusbalance(int money);
};

#endif // !_NORMAL_H_

