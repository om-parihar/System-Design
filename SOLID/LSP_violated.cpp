#include<iostream>
#include<vector>
using namespace std;

class Account {
public:
    virtual void deposit(double amount)=0;
    virtual void withdraw(double amount)=0;
};

class SavingAccount : public Account {
private:
    double balance;

public:
    SavingAccount(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited: "<<amount<<" in savings account, Balance: "<<amount<<endl;
    }
    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawing: "<<amount<<" from savings account, Balance: "<<amount<<endl;
        }
        else{
            cout<<"Balance is less than withdrawable amount"<<endl;
        }
    }

};

class CurrentAccount : public Account{
private:
    double balance;

public:
    CurrentAccount(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited: "<<amount<<" in current account, Balance: "<<amount<<endl;
    }
    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawing: "<<amount<<" from current account, Balance: "<<amount<<endl;
        }
        else{
            cout<<"Balance is less than withdrawable amount"<<endl;
        }
    } 
};

class FixedDeposit : public Account{
private:
    double balance;

public:
    FixedDeposit(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited: "<<amount<<" in Fixed Deposit account, Balance: "<<amount<<endl;
    }
    void withdraw(double amount){
        throw logic_error("Withdrawal not allowed in Fixed Deposit acc");
    }

};

class BankClient {
private:
    vector<Account*> accounts;

public:
    BankClient(vector<Account*> accounts){
        this->accounts=accounts;
    }
    void processTransactions(){
        for(Account* acc: accounts){
            acc->deposit(1000);     // All accounts allow deposits

            // Assuming all accounts allows withdraw(LSP violated)
            try{
                acc->withdraw(500);
            }catch(const logic_error& e){
                cout<<"Exception "<<e.what()<<endl;
            }
        }
    }

};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedDeposit());

    BankClient* client = new BankClient(accounts);
    client->processTransactions();      // Throws exception when withdrawing from fixed deposit acc

    return 0;

}