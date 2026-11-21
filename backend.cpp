#include <iostream>
#include <string>
#include <limits> 
using namespace std;

class User {
    int amount, total_balance;
    string title, category, transaction_type;
    string history[100];
    int count;

public:
    User(): amount(0), total_balance(0), count(0)
    {
        this->title = title;
        this->category = category;
        this->transaction_type = transaction_type;

        cout << "Enter title: ";
        getline(cin >> ws, this -> title);

        cout << "Enter amount: ";
        cin >> amount;

        cin.ignore();

        cout << "Enter category: ";
        getline(cin >> ws,this -> category);

        cout << "Enter transaction type: ";
        getline(cin >> ws,this -> transaction_type);
    }

    void details() {
        cout << "Latest transaction: " << amount << endl;
        cout << "Category: " << category << endl;
        cout << "Title: " << title << endl;
        cout << "Method of transaction: " << transaction_type << endl;
    }

    void deposit() {
        cout << "Enter amount to be deposited: " << endl;
        cin >> amount;

        if (amount > 0) {
            total_balance += amount;

            if (count < 100)
                history[count++] = "Deposit " + to_string(amount);
        }
    }

    void withdrawl() {
        cout << "Enter amount to be withdrawn: " << endl;
        cin >> amount;

        if (amount <= total_balance && amount > 0) {
            total_balance -= amount;

            if (count < 100)
                history[count++] = "Withdrew " + to_string(amount);
        }
    }

    void show_history(){
        cout << "Transaction history: " << endl;
        if(count == 0){
            cout << "No transaction yet" << endl;
        }
        else{
            for(int i=0; i<count; i++){
                cout << history[i] << endl;
            }
        }
    }

    void display_balance(){
        cout << "Balance: " << total_balance << endl;
    }
};


int main() {
    User u1;

    int choice;

    do {
        cout << "\n===== MONEY MANAGER =====" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Transaction History" << endl;
        cout << "5. User Details" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                u1.deposit();
                break;

            case 2:
                u1.withdrawl();
                break;

            case 3:
                u1.display_balance();
                break;
            
            case 4:
                u1.show_history();
                break;

            case 5:
                u1.details();
                break;
            
            case 6:
                cout << "Exiting Money Manager" << endl;
                break;
            
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}