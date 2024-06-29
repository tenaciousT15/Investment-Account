#include "InvestmentAccount.h"

//Implementation for InvestmentAccount
InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate)
{
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
}

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit)
{
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = monthlyDeposit;
}

double InvestmentAccount::getEndingBalance(int numberOfYears)
{
	double closingBalance = initialAmount;
	double monthlyInterest = (annualInterestRate / 100) / 12;

	for (int i = 1; i <= numberOfYears * 12; i++) {
		double compoundedInterest = (closingBalance + monthlyDeposit) * monthlyInterest;
		closingBalance += monthlyDeposit + compoundedInterest;
	}
	return closingBalance;
}

double InvestmentAccount::getInterestEarned(int numberOfYears)
{
	double balanceDifference = 0;
	double totalDeposits = 0;
	double interestEarned = 0;

	if (numberOfYears >= 1) {
		balanceDifference = getEndingBalance(numberOfYears) - getEndingBalance(numberOfYears - 1);
		totalDeposits = 12 * monthlyDeposit;
		interestEarned = balanceDifference - totalDeposits;
	}
	else {
		balanceDifference = getEndingBalance(1) - initialAmount;
		totalDeposits = 12 * monthlyDeposit;
		interestEarned = balanceDifference - totalDeposits;
	}
	return interestEarned;
}

std::string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears)
{
	double endingBalance = getEndingBalance(numberOfYears);
	double roundedBalance = round(endingBalance, 2);
	return format(roundedBalance);
}

std::string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears)
{
	double interestEarned = getInterestEarned(numberOfYears);
	return format(interestEarned);
}

double InvestmentAccount::getInitialAmount()
{
	return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit()
{
	return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate()
{
	return annualInterestRate;
}

//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value - the value to round
//@param places - the number of places to round
//@returns - the rounded number
double InvestmentAccount::round(double value, int places) {
	const int multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value - the value to format
//@returns - the formatted value.
std::string InvestmentAccount::format(double value) {
	std::string valueAsString = std::to_string(value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}
