#ifndef _SCREENOUT_H_
#define _SCREENOUT_H_

#include "MiniBankingCommonDecl.h"

void ShowMenu(void);									// 메인 메뉴 출력
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };	// 메인 메뉴 열거자

void ShowAccMenu(void);									// 계좌 메뉴 출력
enum { NORMAL = 1, CREDIT = 2, UP = 3 };				// 계좌 메뉴 열거자

void ShowCreditLevel(void);								// 신용 등급 정보 출력

#endif // !_SCREENOUT_H_

