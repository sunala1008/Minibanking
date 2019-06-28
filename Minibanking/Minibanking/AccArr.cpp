#include "AccArr.h"

template <typename T>
ACC_ARR<T>::ACC_ARR(int len) 
{
	accArr = new ACCOUNT_PTR[len];
	arrLen = len;
}

template <typename T>
T& ACC_ARR<T>::operator[](int idx) // 배열 인덱스 오버로딩 
{
	if (idx < 0 || idx >= arrLen)
	{
		// cout << "※ 올바른 인덱스 값을 넣어주세요. ※" << endl;
		cout << "┌───────────────────────┐" << endl;
		cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
		cout << "│\t    배열의 범위를 벗어났습니다.    \t│" << endl;
		cout << "└───────────────────────┘" << endl;
		//exit(1);
	}
		
	return accArr[idx]; // 배열 요소를 참조자를 통해 리턴
}

template <typename T>
T ACC_ARR<T>::operator[](int idx) const // 배열 인덱스 오버로딩 -> const화 시킨 것
{
	if (idx < 0 || idx >= arrLen)
	{
		// cout << "※ 올바른 인덱스 값을 넣어주세요. ※" << endl;
		cout << "┌───────────────────────┐" << endl;
		cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
		cout << "│\t    배열의 범위를 벗어났습니다.    \t│" << endl;
		cout << "└───────────────────────┘" << endl;
		//exit(1);
	}

	return accArr[idx]; // 배열 요소를 참조자를 통해 리턴
}

template <typename T>
int ACC_ARR<T>::getarrLen() const
{
	return arrLen;
}

template <typename T>
ACC_ARR<T>::~ACC_ARR()
{
	delete[] accArr;
}