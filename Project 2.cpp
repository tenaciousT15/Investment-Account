#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

using namespace std;


//Main Class function prototypes
void displayOutput(InvestmentAccount account, int numberOfYears);    //Displays the account details, as well as account balances and interest earned for each year.


int main()
{
    //Get the input...validate that the values are non-negative.
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;


    cout << string(80, '*') << endl;
    cout << endl;

    int totalWidth = 80;
    string text = " Data Input ";
    int asteriskBorder = (totalWidth - text.length()) / 2;
    string dataInputLine = string(asteriskBorder, '*') + text + string(asteriskBorder, '*');
    cout << dataInputLine;
    cout << endl;

    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Annual Interest: % ";
    cin >> annualInterest;

    cout << "Number of years: ";
    cin >> numYears;

    cout << "Press any key to continue..." << endl;

    while (numYears < 1) {
        cout << "Please enter a positive integer: ";
        cin >> numYears;
     }

    //Create two InvestmentAccount variables...one with monthly deposit and one without monthly deposit
    InvestmentAccount withMonthlyDeposit(initialInvestment, annualInterest, monthlyDeposit);
    InvestmentAccount withoutMonthlyDeposit(initialInvestment, annualInterest);

    //Display the output for each investment account
    cout << endl << setw(60) << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << string(80, '=') << endl;
    cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest" << endl;
    cout << string(80, '-') << endl;

    for (int i = 1; i <= numYears; ++i) {
        cout << setw(10) << i << setw(20) << withoutMonthlyDeposit.getEndingBalanceFormatted(i) << setw(35)
            << withoutMonthlyDeposit.getInterestEarnedFormatted(i) << endl;
    }

    cout << endl << setw(60) << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << string(80, '=') << endl;
    cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest" << endl;
    cout << string(80, '-') << endl;

    for (int i = 1; i <= numYears; ++i) {
        cout << setw(10) << i << setw(20) << withMonthlyDeposit.getEndingBalanceFormatted(i) << setw(35)
            << withMonthlyDeposit.getInterestEarnedFormatted(i) << endl;
    }

    return 0;
    
}

