#ifndef DATAANDACCOUNT_H
#define DATAANDACCOUNT_H
#include <iostream>
#include <iomanip>
#include <vector>   
#include <string>

using namespace std;

class Data
{
private:

	int Year;
	int Month;
	int Day;

public:
	Data();
	void setYear(const int &YYYY);
	void setDay(const int &DD);
	void setMonth(const int &MM);
	int getYear();
	int getDay();
	int getMonth();
};

class Account
{
private:

	int AcountNum;
	string AccountNameFirst;
	string AccountNameLast;
	double SavingsAccountBalance;
	double CheckingAccountBalance;

public:
	Account();
	Data DData;
	void setAccountNum(const int &ANum);
	void setAccountNameFirst(const string &AFName);
	void setAccountNameLast(const string &ALName);
	void setAccountSavBal(const double &ASBal);
	void setAccountCheckBal(const double &ACBal);
	void addAccountCheckBal(const double &NewCAmt);
	void addAccountSaveBal(const double &NewSAmt);
	void subAccountCheckBal(const double &SubCAmt);
	void subAccountSaveBal(const double &SubSAmt);
	void moveAccountSaveToCheck(const double &SToC);
	void moveAccountCheckToSave(const double &CToS);
	int getAccountNum();
	string getAccountNameFirst();
	string getAccountNameLast();
	double getAccountSaveBal();
	double getAccountCheckBal();
	~Account();
};
#endif