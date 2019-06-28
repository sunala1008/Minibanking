#ifndef _ACC_ARR_H_
#define _ACC_ARR_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"

#define MAXACCOUNT 100

typedef ACCOUNT * ACCOUNT_PTR;

template <typename T>

class ACC_ARR
{
private:
	T *accArr;
	int arrLen;

	ACC_ARR(const ACC_ARR &arr) {}
	ACC_ARR& operator=(const ACC_ARR &arr) {}

public:
	ACC_ARR(int len = MAXACCOUNT);

	T& operator[](int idx);	   // 배열 인덱스 오버로딩 
	// ↑↓ 배열클래스의 저장공간이 더 이상 여유가 없어 저장 할 수 없는 예외 상황.
	T operator[](int idx) const; // 배열 인덱스 오버로딩 -> const화 시킨 것

	int getarrLen() const;

	~ACC_ARR();
};

#endif // !_ACC_ARR_H_
