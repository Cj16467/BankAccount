#include <iostream>
using namespace std;

class BankAccount {
    public:
    BankAccount() {
        balance = 0.00; 
        savingsBalance = 0.00;
        savingsRate = 0.10;
    }

   
    double GetBalance() {
        return balance;
    }
    double GetSavingsBalance() {
        return savingsBalance;
    }
  
    void Deposit(double amount) {
        if (amount > 0) {
            double savingsPortion = amount * savingsRate;
            double remainingAmount = amount - savingsPortion;
            balance += remainingAmount;
            savingsBalance += savingsPortion;
            cout << "$" << savingsPortion << " has been placed into your savings!" << endl;
        } else {
            cout << "You cannot deposit a negative or 0 amount." << endl;
        }
    }

   
    void Withdraw(double amount) {
        if (amount <= 0) {
            cout << "You cannot withdraw a negative or 0 amount." << endl;
        } else if (balance < amount) {
            cout << "Insufficient funds for this withdrawal." << endl;
        } else {
            balance -= amount;
        }
    }
   
    private:
    double balance;
    double savingsBalance;
    double savingsRate;
};

 int main() {
    BankAccount my_account;

   
    my_account.Deposit(900.00);
    cout << "Balance after depositing $200.00: " << my_account.GetBalance() << endl;
    cout << "Savings balance after depositing $200.00: " << my_account.GetSavingsBalance() << endl;
    
    my_account.Deposit(300.00);
    cout << "Balance after depositing $300.00: " << my_account.GetBalance() << endl;
    cout << "Savings balance after depositing $300.00: " << my_account.GetSavingsBalance() << endl;
    
    my_account.Deposit(0.00);
    cout << "Balance after depositing $0.00: " << my_account.GetBalance() << endl;
    cout << "Savings balance after depositing $0.00: " << my_account.GetSavingsBalance() << endl;
    
    my_account.Deposit(-50.00);
    cout << "Balance after attempting to deposit -$50.00: " << my_account.GetBalance() << endl;
    cout << "Savings balance after depositing $-50.00: " << my_account.GetSavingsBalance() << endl;
    
    my_account.Withdraw(100.00);
    cout << "Balance after withdrawing $100.00: " << my_account.GetBalance() << endl;
    
    
    my_account.Withdraw(150.00);
    cout << "Balance after attempting to withdraw $150.00: " << my_account.GetBalance() << endl;
    

    my_account.Withdraw(-20.00);
    cout << "Balance after attempting to withdraw -$20.00: " << my_account.GetBalance() << endl;
    
    
    my_account.Withdraw(900.00);
    cout << "Balance after attempting to withdraw $900.00: " << my_account.GetBalance() << endl;
    
   
  
    return 0;
}
