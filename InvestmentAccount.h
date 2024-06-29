#pragma once

#include <string>

class InvestmentAccount
{

public:
	//Uses private variables to set InvestmentAccount 
	InvestmentAccount(double initialAmount, double annualInterestRate); 
	InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit);

	//Calculate ending balance
	//@param value - calculation based on number of years of investment
	//@returns - ending balance after calculation 
	double getEndingBalance(int numberOfYears);
	// Use www.calculators.org/savings/monthly.php to test values

	//Calculate compounded interest earned
	//@param value - calculation based on number of years of investment
	//@returns - compounded interest
	double getInterestEarned(int numberOfYears);

	//Rounds ending balance as a decimal to 2 places and formats
	//@param value - uses number of years to fulfill the parameter of getEndingBalance and getInterestEarned
	//@returns - formatted rounded ending balance and interest earned
	std::string getEndingBalanceFormatted(int numberOfYears);
	std::string getInterestEarnedFormatted(int numberOfYears);

	double getInitialAmount();
	double getMonthlyDeposit();
	double getAnnualInterestRate();

	double round(double value, int places);
	std::string format(double value);


private:
	double initialAmount = 0;
	double monthlyDeposit = 0;
	double annualInterestRate = 0;
};

