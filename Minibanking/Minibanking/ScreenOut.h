#ifndef _SCREENOUT_H_
#define _SCREENOUT_H_

#include "MiniBankingCommonDecl.h"

void ShowMenu(void);									// ���� �޴� ���
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };	// ���� �޴� ������

void ShowAccMenu(void);									// ���� �޴� ���
enum { NORMAL = 1, CREDIT = 2, UP = 3 };				// ���� �޴� ������

void ShowCreditLevel(void);								// �ſ� ��� ���� ���

#endif // !_SCREENOUT_H_

