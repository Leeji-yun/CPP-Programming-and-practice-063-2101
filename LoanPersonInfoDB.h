#pragma once
#include "LoanPersonInfo.h"
#include <conio.h>
#include<vector>
//LoanPersonInfoDB::getpw(int idx, int pw)�Լ� �ڵ� �ۼ�

class LoanPersonInfoDB {
private:
	vector <LoanPersonInfo> Info;
public:
	void addLoanPersonInfo();
	void setPayBack(int idx, int anspayback);
	int getLoanNumber(int idx);
	int getLoanAccID(int idx);
	int getLoanAmount(int idx);
	int getSize();
	int getLoanPayback(int idx);
	int getpw(int idx, int pw);
};