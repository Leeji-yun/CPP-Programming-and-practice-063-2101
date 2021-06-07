#ifndef _LOAN_
#define _LOAN_
#include "LoanItem.h"
#include "LoanPersonInfoDB.h"
#include <iomanip>
#define size 10

class loan
{
private:
	int num;
	LoanItem* Items[size];
	LoanPersonInfoDB loanPersonInfoDB;

public:
	loan();
	void getLoan();
	int getnum();
	void addLoanItemMenu();
	void showLoanItemMenu();
	void payBackCheck();
	void payBack();

};

#endif