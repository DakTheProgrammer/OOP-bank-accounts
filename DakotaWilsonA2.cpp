//******************************************************************************
//						Assignment #2
//					Student 1: Dakota Wilson
//
//					Data Structures Due Date: 2/20/19
//******************************************************************************
//		DISCRIPTION: This Program displays a nice menu and allows the user to
// enter bank accounts that have a number, name, checking and savings blances,
// and the date of the last payments. it also alows the user to diposit money
// to an account, withdraw money, and move money from there checkings to savings
// accounts. It will also pose errors to the user for instances such as negative
// balances and the account number not existing.
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <vector>   
#include <string>
#include "DataAndAccount.h"

using namespace std;

int main()
{
	vector<Account> TotalAccounts(50);//makes a vector of objects for 50 objects
	int Select, i = 0, TotalAccs = 0, MM, DD, YYYY;
	bool Exit;//creates bool to loop the menue
	Exit = true;

	while (Exit)
	{
		cout << "Press keys 1-6 to select entry:\n";
		cout << "-------------------------------\n";
		cout << "1: Create bank account(s)\n";
		cout << "2: Show bank accounts\n";
		cout << "3: Deposit money to a bank account\n";
		cout << "4: Withdraw money from bank account\n";
		cout << "5: Transfer money between cheeckings and savings\n";
		cout << "6: Exit Program\n";

		cin >> Select;
		cout << '\n';
		switch (Select)
		{
		case 1:
			while (i < 50)
			{
				bool done, YN, IfAccNumNeg, IfSavBalNeg, IfCheckBalNeg, 
					IfNameSame, IfDateNeg;// creats bool for loops
				done = true;
				YN = true;
				char YorN;
				int ANum;
				string AFName, ALName;
				double ASNum, ACNum;

				//TotalAccounts[i].DData.setYear(55);
				//cout << TotalAccounts[i].DData.getYear();


				cout << "Enter account number you want:";
				cin >> ANum;
				IfAccNumNeg = true;
				while (IfAccNumNeg)//used to produce errors with miss entrys
				{
					while (i >= 1)
					{
						for (i = 0; i <= TotalAccs; i++)
						{
							if (ANum == TotalAccounts[i].getAccountNum())
							{
								cout << 
								"Account number already in use try a new one:";
								cin >> ANum;
								i = -1;
							}
							else if (ANum < 0)
							{
								cout <<
								"Account numbers cant be negative" 
									 " enter a new one:";
								cin >> ANum;
								i = -1;
							}
							else
								IfAccNumNeg = false;
						}
						if (IfAccNumNeg == false)
							break;
					}
					if (ANum < 0)
					{
						cout <<
						"Account numbers cant be negative enter a new one:";
						cin >> ANum;
					}
					else
						IfAccNumNeg = false;
				}
				TotalAccounts[i].setAccountNum(ANum);//sets account num

				cout << "Enter account name (First, Last):";
				cin >> AFName >> ALName;
				IfNameSame = true;
				while (IfNameSame)//used to produce errors with miss entrys
				{
					while (i >= 1)
					{
						for (i = 0; i <= TotalAccs; i++)
						{
							if (AFName == TotalAccounts[i].getAccountNameFirst()
								&& ALName == 
								TotalAccounts[i].getAccountNameLast())
							{
								cout << 
								"Account name already in use try a new one:";
								cin >> AFName >> ALName;
								i = -1;
							}
							else
								IfNameSame = false;
						}
						if (IfNameSame == false)
							break;
					}
					IfNameSame = false;
				}
				TotalAccounts[i].setAccountNameFirst(AFName);//sets first name
				TotalAccounts[i].setAccountNameLast(ALName);//sets last name

				cout << "Enter savings amount:";
				cin >> ASNum;
				IfSavBalNeg = true;
				while (IfSavBalNeg)//used to produce errors with miss entrys
				{
					if (ASNum < 0)
					{
						cout << 
						"Account can not have a balance below 0. Try again:";
						cin >> ASNum;
					}
					else
						IfSavBalNeg = false;
				}
				TotalAccounts[i].setAccountSavBal(ASNum);// sets account save bal

				cout << "Enter checking amount:";
				cin >> ACNum;
				IfCheckBalNeg = true;
				while (IfCheckBalNeg)//used to produce errors with miss entrys
				{
					if (ACNum < 0)
					{
						cout << 
						"Account can not have a balance below 0. Try again:";
						cin >> ACNum;
					}
					else
						IfCheckBalNeg = false;
				}
				TotalAccounts[i].setAccountCheckBal(ACNum);//sets check bal

				cout << 
				"Enter date of last payment(from Years 2000 - 2100)." 
					<< "(MM DD YYYY):";
				cin >> MM >> DD >> YYYY;
				IfDateNeg = true;
				while (IfDateNeg)//used to produce errors with miss entrys
				{
					if (MM <= 0 || MM > 12 || DD <= 0 || DD > 31 ||
						YYYY < 2000 || YYYY > 2100)
					{
						cout << 
						"invalid date try again(Months 1-12, Days 1-31,"
							" Years 2000-2100):";
						cin >> MM >> DD >> YYYY;
					}
					else
						IfDateNeg = false;
				}
				TotalAccounts[i].DData.setMonth(MM);// sets last pay month
				TotalAccounts[i].DData.setDay(DD);// sets last pay day
				TotalAccounts[i].DData.setYear(YYYY);// sets last pay year

				TotalAccs = i;//so that loops dont have to go to 50 each time

				cout << "Do you want to enter another set of data? (Y/N):";
				while (YN)//prompts user to continue or not and produces error
				{
					cin >> YorN;
					cout << '\n';
					if (YorN == 'Y' || YorN == 'y')
					{
						i++;
						YN = false;
					}
					else if (YorN == 'N' || YorN == 'n')
					{
						i++;
						YN = false;
						cout << "\n";
					}
					else
					{
						cout << "Invalid input try again. Y/N:";
					}
				}
				if (YorN == 'N' || YorN == 'n')
					break;
			}
			break;
		case 2:
			if (i == 0)//used to produce errors with miss entrys
			{
				cout << "No Accounts yet input some then come back\n";
				break;
			}
			cout << "Account Number  Account Name                    Savings"
				<< "Balance  Checking Balance Month  Date  Year\n";
			cout << "__________________________________________________________"
				"_________________________________________\n";
			for (int j = 0; j <= TotalAccs; j++)
			{
				cout << left << setw(15) << TotalAccounts[j].getAccountNum() <<
					'|' << setw(15) << TotalAccounts[j].getAccountNameFirst() <<
					' ' << setw(15) << TotalAccounts[j].getAccountNameLast()
					<< '|' << setw(16) << fixed << setprecision(2) << 
					TotalAccounts[j].getAccountSaveBal() << '|' << fixed << 
					setprecision(2) << setw(16) << 
					TotalAccounts[j].getAccountCheckBal() << '|' << setw(6) <<
					TotalAccounts[j].DData.getMonth() << '|' << setw(5) << 
					TotalAccounts[j].DData.getDay() << '|' << setw(4) <<
					TotalAccounts[j].DData.getYear() << '\n';
				cout << "_____________________________________________________"
					"______________________________________________\n";
			}
			break;
		case 3:
			if (i == 0)//used to produce errors with miss entrys
			{
				cout << "No Accounts yet input some then come back\n";
				break;
			}
			bool IncreaseAmt, YRN, CRS, More, AddAmtCNeg, AddAmtSNeg, IfDNeg;
			IncreaseAmt = true;
			char YesOrNo, COrS, AddMore;
			while (IncreaseAmt)// used to continuesly ask to deposit
			{
				int IncANum, NewMM, NewDD, NewYYYY;
				double AddedAmt;
				cout << "Enter Account Number you want to deposit money into:";
				cin >> IncANum;
				for (int k = 0; k <= TotalAccs; k++)
				{
					if (IncANum == TotalAccounts[k].getAccountNum())
					{
						cout << "Account Number  Account Name                   "
						" Savings Balance  Checking Balance Month  Date  Year\n";
						cout << "______________________________________________"
					   "_____________________________________________________\n";
						cout << left << setw(15) << 
							TotalAccounts[k].getAccountNum() << '|' << setw(15) 
							<< TotalAccounts[k].getAccountNameFirst() << ' ' <<
							setw(15) << TotalAccounts[k].getAccountNameLast()
							<< '|' << setw(16) << fixed << setprecision(2) <<
							TotalAccounts[k].getAccountSaveBal() << '|'
							<< fixed << setprecision(2) << setw(16) << 
							TotalAccounts[k].getAccountCheckBal() << '|' << 
							setw(6) << TotalAccounts[k].DData.getMonth() <<
							'|' << setw(5) << TotalAccounts[k].DData.getDay() 
							<< '|' << setw(4) <<
							TotalAccounts[k].DData.getYear() << "\n\n";

						cout << "Add to savings or checkings?(C/S):";
						cin >> COrS;// so that they destinguesh where its going
						CRS = true;
						while (CRS)//used to produce errors with miss entrys
						{
							if (COrS == 'c' || COrS == 'C')
							{
								cout << "How much are you dipositing "
									"to checking?:";
								cin >> AddedAmt;
								AddAmtCNeg = true;
								while (AddAmtCNeg)
								{
									if (AddedAmt < 0)
									{
										cout << "Cant enter a negative value. "
											"Try agnin:";
										cin >> AddedAmt;
									}
									else
										AddAmtCNeg = false;
								}
								TotalAccounts[k].addAccountCheckBal(AddedAmt);

								cout << "Enter Date for updated payment date."
									"(MM DD YYYY):";
								cin >> NewMM >> NewDD >> NewYYYY;
								//^sets new pay day
								IfDNeg = true;
								while (IfDNeg)
									//used to produce errors with miss entrys
								{
									if (i >= 0)
									{
										for (int z = 0; z <= TotalAccs; z++)
										{
											if ((TotalAccounts[z].DData.getDay() 
												> NewDD && 
												TotalAccounts[z].DData.getMonth()
												== NewMM && 
												TotalAccounts[z].DData.getYear()
												== NewYYYY) || (
												TotalAccounts[z].DData.getMonth()
											    > NewMM && 
												TotalAccounts[z].DData.getYear() 
												== NewYYYY) || (
												TotalAccounts[z].DData.getYear()
												> NewYYYY))
											{
												cout << "Invalid date try again."
													" (MM DD YYYY)";
												cin >> NewMM >> NewDD >> NewYYYY;
												z = -1;
											}
											else
												break;
										}
										break;
									}
									else if (MM <= 0 || MM > 12 || DD <= 0 || 
										DD > 31 || YYYY < 2000 || YYYY > 2100)
									{
										cout << "Invalid date try again."
											" (MM DD YYYY)";
										cin >> NewMM >> NewDD >> NewYYYY;
									}
									else
										IfDNeg = false;
								}
								TotalAccounts[k].DData.setMonth(NewMM);
								//sets new month for pay
								TotalAccounts[k].DData.setDay(NewDD);
								//sets new day for pay
								TotalAccounts[k].DData.setYear(NewYYYY);
								//sets new year for pay

								CRS = false;
								cout << "Account Number  Account Name          "
								"          Savings Balance  Checking Balance "
									"Month  Date  Year\n";
								cout << "_______________________________________"
									"___________________________________________"
									"_________________\n";
								cout << left << setw(15) << 
									TotalAccounts[k].getAccountNum() << '|' <<
									setw(15) << 
									TotalAccounts[k].getAccountNameFirst() << 
									' ' << setw(15) << 
									TotalAccounts[k].getAccountNameLast()
									<< '|' << setw(16) << fixed << 
									setprecision(2) << 
									TotalAccounts[k].getAccountSaveBal() << '|'
									<< fixed << setprecision(2) << setw(16) << 
									TotalAccounts[k].getAccountCheckBal() << '|'
									<< setw(6) << 
									TotalAccounts[k].DData.getMonth() << '|' 
									<< setw(5) << TotalAccounts[k].DData.getDay()
									<< '|' << setw(4) <<
									TotalAccounts[k].DData.getYear() << "\n\n";
							}
							else if (COrS == 's' || COrS == 'S')
							{
								cout << "How much are you dipositing to "
									"savings?:";
								cin >> AddedAmt;
								AddAmtSNeg = true;
								while (AddAmtSNeg)
								{
									if (AddedAmt < 0)
									{
										cout << "Cant enter a negative value. "
											"Try agnin:";
										cin >> AddedAmt;
									}
									else
										AddAmtSNeg = false;
								}
								TotalAccounts[k].addAccountSaveBal(AddedAmt);

								cout << "Enter Date for updated payment date."
									"(MM DD YYYY):";
								cin >> NewMM >> NewDD >> NewYYYY;
								//enters new date
								IfDNeg = true;
								while (IfDNeg)
								//used to produce errors with miss entrys
								{
									if (i >= 0)
									{
										for (int z = 0; z <= TotalAccs; z++)
										{
											if ((TotalAccounts[z].DData.getDay()
												> NewDD && 
												TotalAccounts[z].DData.getMonth()
												== NewMM && 
												TotalAccounts[z].DData.getYear()
												== NewYYYY) || (
												TotalAccounts[z].DData.getMonth()
												> NewMM && 
												TotalAccounts[z].DData.getYear()
												== NewYYYY) || 
												(TotalAccounts[z].DData.getYear()
												> NewYYYY))
											{
												cout << "Invalid date try again."
													" (MM DD YYYY)";
												cin >> NewMM >> NewDD >> NewYYYY;
												z = -1;
											}
											else
												break;
										}
										break;
									}
									else if (MM <= 0 || MM > 12 || DD <= 0 ||
										DD > 31 || YYYY < 2000 || YYYY > 2100)
									{
										cout << "Invalid date try again. "
											"(MM DD YYYY)";
										cin >> NewMM >> NewDD >> NewYYYY;
									}
									else
										IfDNeg = false;
								}
								TotalAccounts[k].DData.setMonth(NewMM);
								TotalAccounts[k].DData.setDay(NewDD);
								TotalAccounts[k].DData.setYear(NewYYYY);

								CRS = false;
								cout << "Account Number  Account Name          "
									"          Savings Balance  Checking Balance"
									" Month  Date  Year\n";
								cout << "______________________________________"
									"__________________________________________"
									"___________________\n";
								cout << left << setw(15) << 
									TotalAccounts[k].getAccountNum() << '|' << 
									setw(15) << 
									TotalAccounts[k].getAccountNameFirst() << 
									' ' << setw(15) << 
									TotalAccounts[k].getAccountNameLast()
									<< '|' << setw(16) << fixed << 
									setprecision(2) << 
									TotalAccounts[k].getAccountSaveBal() << '|'
									<< fixed << setprecision(2) << setw(16) <<
									TotalAccounts[k].getAccountCheckBal() <<
									'|' << setw(6) <<
									TotalAccounts[k].DData.getMonth() << '|' <<
									setw(5) << TotalAccounts[k].DData.getDay()
									<< '|' << setw(4) <<
									TotalAccounts[k].DData.getYear() << "\n\n";
							}
							else
							{
								cout << "invalid input try again (C/S):";
								cin >> COrS;
							}
						}
						cout << "Do you want to add more money to another "
							"account? (Y/N):";
						cin >> AddMore;//asks to continue
						More = true;
						while (More)//used to produce errors with miss entrys
						{
							if (AddMore == 'Y' || AddMore == 'y')
							{
								More = false;
							}
							else if (AddMore == 'N' || AddMore == 'n')
							{
								More = false;
								IncreaseAmt = false;
							}
							else
							{
								cout << "Invalid input try again (Y/N):";
								cin >> AddMore;
							}
						}
						k = 51;
					}
					else if (k == TotalAccs)
					{
						cout << "Account does not exits try again? (Y/N):";
						cin >> YesOrNo;
						YRN = true;
						while (YRN)
						{
							if (YesOrNo == 'y' || YesOrNo == 'Y')
							{
								YRN = false;
							}
							else if (YesOrNo == 'n' || YesOrNo == 'N')
							{
								YRN = false;
								IncreaseAmt = false;
							}
							else
							{
								cout << "Invalid answer try again(Y/N):";
								cin >> YesOrNo;
							}
						}
					}
					if (AddMore == 'N' || AddMore == 'n')
						break;//breaks out of loop
				}
			}
			break;
		case 4:
			if (i == 0)//used to produce errors with miss entrys
			{
				cout << "No Accounts yet input some then come back\n";
				break;
			}
			bool WithAmt, YRNWith, CRSWith, MoreWith, IfNegC, IfNegS;
			WithAmt = true;
			char YesOrNoWith, COrSWith, WithMore;
			while (WithAmt)
			{
				int WithANum;
				double RemAmt;
				cout << "Enter Account Number you want to withdraw money from:";
				cin >> WithANum;
				for (int l = 0; l <= TotalAccs; l++)
				{
					if (WithANum == TotalAccounts[l].getAccountNum())
					{
						cout << "Account Number  Account Name                   "
						" Savings Balance  Checking Balance Month  Date  Year\n";
						cout << "_______________________________________________"
						"____________________________________________________\n";
						cout << left << setw(15) << 
							TotalAccounts[l].getAccountNum() << '|' << setw(15)
							<< TotalAccounts[l].getAccountNameFirst() << ' '
							<< setw(15) << TotalAccounts[l].getAccountNameLast()
							<< '|' << setw(16) << fixed << setprecision(2) 
							<< TotalAccounts[l].getAccountSaveBal() << '|'
							<< fixed << setprecision(2) << setw(16) << 
							TotalAccounts[l].getAccountCheckBal() << '|' <<
							setw(6) << TotalAccounts[l].DData.getMonth() <<
							'|' << setw(5) << TotalAccounts[l].DData.getDay()
							<< '|' << setw(4) <<
							TotalAccounts[l].DData.getYear() << "\n\n";

						cout << "Withdraw from savings or checkings?(C/S):";
						cin >> COrSWith;// prompts which account to withdraw
						CRSWith = true;
						while (CRSWith)//used to produce errors with miss entrys
						{
							if (COrSWith == 'c' || COrSWith == 'C')
							{
								cout << "How much are you withdrawing from "
									"checking?:";
								cin >> RemAmt;
								IfNegC = true;
								while (IfNegC)
								{
									if (RemAmt > 
										TotalAccounts[l].getAccountCheckBal()
										|| RemAmt < 0)
									{
										cout << "Balance cant be negative "
											"enter new amount to withdraw:";
										cin >> RemAmt;
									}
									else
									{
										IfNegC = false;
									}
								}
								TotalAccounts[l].subAccountCheckBal(RemAmt);
								CRSWith = false;
								cout << "Account Number  Account Name          "
								"          Savings Balance  Checking Balance "
									"Month  Date  Year\n";
								cout << "______________________________________"
									"__________________________________________"
									"___________________\n";
								cout << left << setw(15) << 
									TotalAccounts[l].getAccountNum() << '|' <<
									setw(15) <<
									TotalAccounts[l].getAccountNameFirst() <<
									' ' << setw(15) << 
									TotalAccounts[l].getAccountNameLast()
									<< '|' << setw(16) << fixed << 
									setprecision(2) << 
									TotalAccounts[l].getAccountSaveBal() << '|'
									<< fixed << setprecision(2) << setw(16) <<
									TotalAccounts[l].getAccountCheckBal() << '|'
									<< setw(6) << 
									TotalAccounts[l].DData.getMonth() << '|' <<
									setw(5) << TotalAccounts[l].DData.getDay() 
									<< '|' << setw(4) <<
									TotalAccounts[l].DData.getYear() << "\n\n";
							}
							else if (COrSWith == 's' || COrSWith == 'S')
							{
								cout << "How much are you withdrawing from "
									"savings?:";
								cin >> RemAmt;//asks for amount to remove
								IfNegS = true;
								while (IfNegS)
								//used to produce errors with miss entrys
								{
									if (RemAmt > 
										TotalAccounts[l].getAccountSaveBal()
										|| RemAmt < 0)
									{
										cout << "Balance cant be negative "
											"enter new amount to withdraw:";
										cin >> RemAmt;
									}
									else
									{
										IfNegS = false;
									}
								}
								TotalAccounts[l].subAccountSaveBal(RemAmt);
								CRSWith = false;
								cout << "Account Number  Account Name          "
								"          Savings Balance  Checking Balance "
									"Month  Date  Year\n";
								cout << "______________________________________"
									"__________________________________________"
									"___________________\n";
								cout << left << setw(15) << 
									TotalAccounts[l].getAccountNum() << '|' << 
									setw(15) << 
									TotalAccounts[l].getAccountNameFirst() << 
									' ' << setw(15) << 
									TotalAccounts[l].getAccountNameLast()
									<< '|' << setw(16) << fixed << 
									setprecision(2) << 
									TotalAccounts[l].getAccountSaveBal() << '|'
									<< fixed << setprecision(2) << setw(16) <<
									TotalAccounts[l].getAccountCheckBal() << 
									'|' << setw(6) <<
									TotalAccounts[l].DData.getMonth() << '|' 
									<< setw(5) << 
									TotalAccounts[l].DData.getDay() << '|' 
									<< setw(4) <<
									TotalAccounts[l].DData.getYear() << 
									"\n\n";
							}
							else
							{
								cout << "invalid input try again (C/S):";
								cin >> COrSWith;
							}
						}
						cout << "Do you want to withdraw more money from "
							"another account? (Y/N):";
						cin >> WithMore;
						MoreWith = true;
						while (MoreWith)//used to produce errors with miss entrys
						{
							if (WithMore == 'Y' || WithMore == 'y')
							{
								MoreWith = false;
							}
							else if (WithMore == 'N' || WithMore == 'n')
							{
								MoreWith = false;
								WithAmt = false;
							}
							else
							{
								cout << "Invalid input try again (Y/N):";
								cin >> WithMore;
							}
							l = 51;
						}
					}
					else if (l == TotalAccs)
					//used to produce errors with miss entrys
					{
						cout << "Account does not exits try again? (Y/N):";
						cin >> YesOrNoWith;
						YRNWith = true;
						while (YRNWith)
						{
							if (YesOrNoWith == 'y' || YesOrNoWith == 'Y')
							{
								YRNWith = false;
							}
							else if (YesOrNoWith == 'n' || YesOrNoWith == 'N')
							{
								YRNWith = false;
								WithAmt = false;
							}
							else
							{
								cout << "Invalid answer try again(Y/N):";
								cin >> YesOrNoWith;
							}
						}
					}
					if (WithMore == 'N' || WithMore == 'n')
						break;//breaks so that it exits loop
				}
			}
			break;//breaks to exit loop
		case 5:
			if (i == 0)//used to produce errors with miss entrys
			{
				cout << "No Accounts yet input some then come back\n";
				break;
			}
			bool Transfer, Which, MoreEnt, IfCToSNeg, IfSToCNeg;
			char WhichCS, MoreEntYOrN;
			Transfer = true;
			while (Transfer)//used to produce errors with miss entrys
			{
				int TranAccNum;
				double CToS, SToC;
				cout << "Enter the account number you want to transfer funds "
					"between:";
				cin >> TranAccNum;
				for (int m = 0; m <= TotalAccs; m++)
				{
					if (TranAccNum == TotalAccounts[m].getAccountNum())
					{
						cout << "Account Number  Account Name                  "
					 "  Savings Balance  Checking Balance Month  Date  Year\n";
						cout << "______________________________________________"
					 "_____________________________________________________\n";
						cout << left << setw(15) <<
							TotalAccounts[m].getAccountNum() << '|' << setw(15)
							<< TotalAccounts[m].getAccountNameFirst() << ' ' 
							<< setw(15) << TotalAccounts[m].getAccountNameLast()
							<< '|' << setw(16) << fixed << setprecision(2) << 
							TotalAccounts[m].getAccountSaveBal() << '|' << 
							fixed << setprecision(2) << setw(16) << 
							TotalAccounts[m].getAccountCheckBal() << '|' <<
							setw(6) << TotalAccounts[m].DData.getMonth() << '|'
							<< setw(5) << TotalAccounts[m].DData.getDay() << 
							'|' << setw(4) << TotalAccounts[m].DData.getYear()
							<< "\n\n";

						Which = true;
						cout << "What Account types are you transfering? (C "
						"for checking to savings/ S for savings to checking):";
						cin >> WhichCS;//enters where to exchange
						while (Which)//used to produce errors with miss entrys
						{
							if (WhichCS == 'C' || WhichCS == 'c')
							{
								cout << "How much are you transfering from "
									"checking to savings?:";
								cin >> CToS;
								IfCToSNeg = true;
								while (IfCToSNeg)
								{
									if (CToS > 
										TotalAccounts[m].getAccountCheckBal()
										|| CToS < 0)
									{
										cout << "Invalid entry not enough funds"
										"in checking or negitve number entered."
											"try again:";
										cin >> CToS;
									}
									else
									{
										IfCToSNeg = false;
									}
								}
								TotalAccounts[m].moveAccountCheckToSave(CToS);
								Which = false;
								cout << "Account Number  Account Name          "
								"          Savings Balance  Checking Balance "
									"Month  Date  Year\n";
								cout << "______________________________________"
									"__________________________________________"
									"___________________\n";
								cout << left << setw(15) << 
									TotalAccounts[m].getAccountNum() << '|' <<
									setw(15) << 
									TotalAccounts[m].getAccountNameFirst() <<
									' ' << setw(15) <<
									TotalAccounts[m].getAccountNameLast() <<
									'|' << setw(16) << fixed << setprecision(2)
									<< TotalAccounts[m].getAccountSaveBal() <<
									'|' << fixed << setprecision(2) << setw(16)
									<< TotalAccounts[m].getAccountCheckBal() <<
									'|' << setw(6) <<
									TotalAccounts[m].DData.getMonth() << '|' <<
									setw(5) << TotalAccounts[m].DData.getDay()
									<< '|' << setw(4) <<
									TotalAccounts[m].DData.getYear() << "\n\n";
							}
							else if (WhichCS == 's' || WhichCS == 'S')
							{
								cout << "How much are you transfering from "
									"savings to cheking?:";
								cin >> SToC;
								IfSToCNeg = true;
								while (IfSToCNeg)
								{
									if (SToC > 
										TotalAccounts[m].getAccountSaveBal()
										|| SToC < 0)
									{
										cout << "Invalid entry not enough "
										"funds in savings or negitve number "
											"entered. try again:";
										cin >> SToC;
									}
									else
									{
										IfSToCNeg = false;
									}
								}
								TotalAccounts[m].moveAccountSaveToCheck(SToC);
								Which = false;
								cout << "Account Number  Account Name          "
								"          Savings Balance  Checking Balance "
									"Month  Date  Year\n";
								cout << "______________________________________"
									"__________________________________________"
									"___________________\n";
								cout << left << setw(15) << 
									TotalAccounts[m].getAccountNum() << '|' 
									<< setw(15) <<
									TotalAccounts[m].getAccountNameFirst() <<
									' ' << setw(15) << 
									TotalAccounts[m].getAccountNameLast()
									<< '|' << setw(16) << fixed <<
									setprecision(2) << 
									TotalAccounts[m].getAccountSaveBal() << '|'
									<< fixed << setprecision(2) << setw(16) <<
									TotalAccounts[m].getAccountCheckBal() << '|'
									<< setw(6) <<
									TotalAccounts[m].DData.getMonth() << '|' <<
									setw(5) << TotalAccounts[m].DData.getDay() 
									<< '|' << setw(4) <<
									TotalAccounts[m].DData.getYear() << "\n\n";
							}
							else
							{
								cout << "Invalid input try again. (C for "
							 "checking to savings/ S for savings to checking):";
								cin >> WhichCS;
							}
						}
						MoreEnt = true;
						cout << "Would you like to transfer another account? "
							"(Y/N):";
						cin >> MoreEntYOrN;//Enters if they want to do more
						while (MoreEnt)//used to produce errors with miss entrys
						{
							if (MoreEntYOrN == 'Y' || MoreEntYOrN == 'y')
							{
								MoreEnt = false;
							}
							else if (MoreEntYOrN == 'N' || MoreEntYOrN == 'n')
							{
								MoreEnt = false;
								Transfer = false;
							}
							else
							{
								cout << "Invalid answer try again(Y/N):";
								cin >> MoreEntYOrN;
							}
						}
					}
					if (WithMore == 'N' || WithMore == 'n')
						break;//breaks the loop
				}
			}
			break;//breaks the loop
		case 6:
			Exit = false;//exits the program
			break;
		default:
			cout << "Invalid input try again numbers 1-6\n";
			break;//used to produce errors with miss entrys
		}
	}

	system("pause");
	return 0;
}
