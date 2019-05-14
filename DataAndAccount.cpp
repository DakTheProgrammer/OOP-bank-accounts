#include <iostream>
#include <iomanip>
#include <vector>   
#include <string>
#include "DataAndAccount.h"

using namespace std;

//******************************************************************************
//							Data::Data()
//	Parameters: This is the default constructor for the data class and doesnt do
//  anything but be created when the class is called.
//******************************************************************************
Data::Data()
{

}

//******************************************************************************
//							void Data::setYear(const int &YYYY)
//	Parameters: This when called takes a integer number and sets it in a secure
//  way as the value used to set payment date in years
//******************************************************************************
void Data::setYear(const int &YYYY)
{
	Year = YYYY;
}

//******************************************************************************
//							void Data::setDay(const int &DD)
//	Parameters: This when called takes a integer number and sets it in a secure
//  way as the value used to set payment date for days
//******************************************************************************
void Data::setDay(const int &DD)
{
	Day = DD;
}

//******************************************************************************
//							void Data::setDay(const int &DD)
//	Parameters: This when called takes a integer number and sets it in a secure
//  way as the value used to set payment date in monts
//******************************************************************************
void Data::setMonth(const int &MM)
{
	Month = MM;
}

//******************************************************************************
//							int Data::getYear()
//	Parameters: This when called returns an integer of years for the payment 
//  date so that it can be used to print to screen and compair to variables
//******************************************************************************
int Data::getYear()
{
	return Year;
}

//******************************************************************************
//							int Data::getDay()
//	Parameters: This when called returns an integer of days for the payment 
//  date so that it can be used to print to screen and compair to variables
//******************************************************************************
int Data::getDay()
{
	return Day;
}

//******************************************************************************
//							int Data::getYear()
//	Parameters: This when called returns an integer of months for the payment 
//  date so that it can be used to print to screen and compair to variables
//******************************************************************************
int Data::getMonth()
{
	return Month;
}

//******************************************************************************
//							Account::Account()
//	Parameters: This is the default constructor for the account class and doesnt
//  do anything but is used when the object is called
//******************************************************************************
Account::Account()
{
	//cout << "Welcome to the Account module I hope you are having a good "
	//"day\n\n\n\n";
}

//******************************************************************************
//							void Account::setAccountNum(const int &ANum)
//	Parameters: This is a function that sets the account number when it is
//  called by the user so that it can be used
//******************************************************************************
void Account::setAccountNum(const int &ANum)
{
	AcountNum = ANum;
}

//******************************************************************************
//						void Account::setAccountNameFirst(const string &AFName)
//	Parameters: This is a function that sets the first name for a new account so
//  that the account can have a name associated to it 
//******************************************************************************
void Account::setAccountNameFirst(const string &AFName)
{
	AccountNameFirst = AFName;
}

//******************************************************************************
//						void Account::setAccountNameLast(const string &ALName)
//	Parameters: This is a function that sets the last name for a new account so
//  that the account can have a name associated to it 
//******************************************************************************
void Account::setAccountNameLast(const string &ALName)
{
	AccountNameLast = ALName;
}

//******************************************************************************
//							void Account::setAccountSavBal(const double &ASBal)
//	Parameters: This is a function that sets the saving balance on an account so
//  that it can be associated with the account
//******************************************************************************
void Account::setAccountSavBal(const double &ASBal)
{
	SavingsAccountBalance = ASBal;
}

//******************************************************************************
//						void Account::setAccountCheckBal(const double &ACBal)
// Parameters: This is a function that sets the checking balance on an account
// so that it can be associated with the account
//******************************************************************************
void Account::setAccountCheckBal(const double &ACBal)
{
	CheckingAccountBalance = ACBal;
}

//******************************************************************************
//						void Account::addAccountCheckBal(const double &NewCAmt)
//	Parameters: This is a function that adds money to the checking balance when
//  the user wants to deposit money in an account so that it can be used later
//******************************************************************************
void Account::addAccountCheckBal(const double &NewCAmt)
{
	CheckingAccountBalance = CheckingAccountBalance + NewCAmt;
}

//******************************************************************************
//						void Account::addAccountSaveBal(const double &NewSAmt)
//	Parameters: This is a function that adds money to the saving balance when
//  the user wants to deposit money in an account so that it can be used later
//******************************************************************************
void Account::addAccountSaveBal(const double &NewSAmt)
{
	SavingsAccountBalance = SavingsAccountBalance + NewSAmt;
}

//******************************************************************************
//						void Account::subAccountCheckBal(const double &SubCAmt)
// Parameters: This is a function that subtracts money from the checking balance
// when the user wants to withdraw money from an account so that it can be used 
// later
//******************************************************************************
void Account::subAccountCheckBal(const double &SubCAmt)
{
	CheckingAccountBalance = CheckingAccountBalance - SubCAmt;
}

//******************************************************************************
//						void Account::subAccountSaveBal(const double &SubSAmt)
// Parameters: This is a function that subtracts money from the savings balance
// when the user wants to withdraw money from an account so that it can be used 
// later
//******************************************************************************
void Account::subAccountSaveBal(const double &SubSAmt)
{
	SavingsAccountBalance = SavingsAccountBalance - SubSAmt;
}

//******************************************************************************
//						void Account::moveAccountSaveToCheck(const double &SToC)
// Parameters: This is a function that moves money from savings to checking of
// a users account so that it can be used when needed
//******************************************************************************
void Account::moveAccountSaveToCheck(const double &SToC)
{
	SavingsAccountBalance = SavingsAccountBalance - SToC;
	CheckingAccountBalance = CheckingAccountBalance + SToC;
}

//******************************************************************************
//						void Account::moveAccountCheckToSave(const double &CToS)
// Parameters: This is a function that moves money from checking to savings of
// a users account so that it can be used when needed
//******************************************************************************
void Account::moveAccountCheckToSave(const double &CToS)
{
	CheckingAccountBalance = CheckingAccountBalance - CToS;
	SavingsAccountBalance = SavingsAccountBalance + CToS;
}

//******************************************************************************
//						int Account::getAccountNum()
// Parameters: This is a function that gets the account number and returns it so
// that the user can see or compare the values of it
//******************************************************************************
int Account::getAccountNum()
{
	return AcountNum;
}

//******************************************************************************
//						string Account::getAccountNameFirst()
// Parameters: This is a function that gets the accounts first name and returns 
// it so that the user can see or compare the contents of it
//******************************************************************************
string Account::getAccountNameFirst()
{
	return AccountNameFirst;
}

//******************************************************************************
//						string Account::getAccountNameLast()
// Parameters: This is a function that gets the accounts last name and returns 
// it so that the user can see or compare the contents of it
//******************************************************************************
string Account::getAccountNameLast()
{
	return AccountNameLast;
}

//******************************************************************************
//						double Account::getAccountSaveBal()
// Parameters: This is a function that gets the accounts savings balance that is
// held in its savings and is returened to the user so that it can compare its 
// value or be displayed
//******************************************************************************
double Account::getAccountSaveBal()
{
	return SavingsAccountBalance;
}

//******************************************************************************
//						double Account::getAccountCheckBal()
// Parameters: This is a function that gets the accounts checking balance that 
// is held in its checking and is returened to the user so that it can compare 
// its value or be displayed
//******************************************************************************
double Account::getAccountCheckBal()
{
	return CheckingAccountBalance;
}

//******************************************************************************
//						Account::~Account()
// Parameters: This is the Account classes deconstructor and doesnt do anything
// but run when the program is ended
//******************************************************************************
Account::~Account()
{
	//cout << "Ending module have a great day\n";
}