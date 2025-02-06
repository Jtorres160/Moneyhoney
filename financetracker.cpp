#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Transaction
{
    string date;
    string category;
    float amount;
    string type; // "income" or "expense"
};
vector<Transaction> transactions;

int main()
{
    // user information
    string username = ""; // user username
    string password = ""; // user password

    // income and expenses
    float income = 0.0;  // the user income
    float expense = 0.0; // the users expense

    // budget and savings
    float monthlyBudget = 0.0;  // spending limit
    float savingsGoal = 0.0;    // how much the user wants to save
    float currentSavings = 0.0; // how much the user currently has

    // tracking time
    string month = ""; // monthly monthly
    int year = 2025;   // get the user data by year

    int choice; // user choice
    do
    {
        cout << "welcome to the finance tracker" << endl;
        cout << "what would you like to do?" << endl;
        cout << "1. add income" << endl;
        cout << "2. add expense" << endl;
        cout << "3. view budget" << endl;
        cout << "4. view savings" << endl;
        cout << "5. view transactions" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1: // add income
        {
            Transaction t;

            cout << "enter the date: ";
            cin >> t.date;
            cout << "enter the category: ";
            cin >> t.category;
            cout << "enter the amount of income: ";
            cin >> t.amount;
            t.type = "income";
            currentSavings += t.amount;
            transactions.push_back(t);
            cout << "Income added successfully" << endl;
            cin.fail();
        }
        break;

        case 2: // add expense
        {
            Transaction t;
            cout << "Enter the date (YYYY-MM-DD): ";
            cin >> t.date;
            cout << "Enter the category: ";
            cin >> t.category;
            cout << "Enter the amount of expense: ";
            cin >> t.amount;
            t.type = "expense";
            if (t.amount > currentSavings)
            {
                cout << "You do not have enough money to make this transaction" << endl;
                break;
            }
            else if (t.amount > monthlyBudget)
            {
                cout << "This transaction exceeds your monthly budget" << endl;
                break;
            }
            else
            {
                // the expense is valid
                currentSavings -= t.amount;
                monthlyBudget -= t.amount;

                // add the transction to the vector transactions
                transactions.push_back(t);

                cout << "Expense added successfully!" << endl;
                cout << "Current Savings: $" << currentSavings << endl;
            }
            currentSavings -= t.amount;
            transactions.push_back(t);
            cout << "Expense added successfully!" << endl;
        }
        break;

        case 3: // View budget
            cout << "Monthly Budget: $" << monthlyBudget << endl;
            cout << "Current Savings: $" << currentSavings << endl;
            break;

        case 4: // View savings
            cout << "Savings Goal: $" << savingsGoal << endl;
            cout << "Current Savings: $" << currentSavings << endl;
            break;

        case 5:
            cout << "View transactions" << endl;
            for (int i = 0; i < transactions.size(); i++)
            {
                cout << transactions[i].date << " " << transactions[i].category << " " << transactions[i].amount << " " << transactions[i].type << endl;
            }
            break;

        case 6:
            cout << "exit" << endl;
            break;
        }

    } while (choice != 6);

    return 0;
}