#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include "MiniBankingCommonDecl.h"

class A_Exception // 입출금 예외
{
public:
	virtual void ShowExceptionReason() = 0;
};

class D_Exception : public A_Exception // 입금 예외
{
private:
	int depositMoney;

public:
	D_Exception(int money) : depositMoney(money) {}

	void ShowExceptionReason();
};

class W_Exception : public A_Exception //출금 예외
{
private:
	int balance;

public:
	W_Exception(int money) : balance(money) {}

	void ShowExceptionReason();
};

class FULL_ACCOUNT // 개설 계좌 갯수 초과
{
private:
	int NUM;

public:
	FULL_ACCOUNT(int num) : NUM(num) {}

	void ShowAccFull();
};

class AlreadyRegiAcc // 이미 등록된 계좌 번호
{
public:
	AlreadyRegiAcc() {}

	void ShowAlreadyRegi();
};

class IntoMoney	// 계좌 생성시 -금액
{
public:
	IntoMoney() {}

	void ShowIntoMoney();
};

class GradeErr // 등급 오류
{
public:
	GradeErr() {}

	void ShowGradeErr();
};

class NoMinusMoney	// - 출금 ('1000 - (-5000) = 6000' 방지)
{
private:
	int money;

public:
	NoMinusMoney(int cash) : money(cash) {}

	void ShowNoMinusMoney();
};

#endif // !_EXCEPTION_H_
