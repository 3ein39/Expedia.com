//
// Created by hussein on 8/1/22.
//

#ifndef EXPEDIA_COM_USR_MGR_H
#define EXPEDIA_COM_USR_MGR_H

#include<map>
using namespace std;

#include "payment_card.h"
#include "user.h"
#include "utils.h"

class UsersManager {
protected:
    User* current_user = nullptr;
    map<string, User*> username_userobject_map;

    void FreeLoadedData() {
        for (auto pair : username_userobject_map) {
            delete pair.second;
        }
        username_userobject_map.clear();
        current_user = nullptr;
    }

public:

    // Default constructor
    UsersManager() {}

    // Destructor
    ~UsersManager() {
        cout << "Destructor: UsersManager\n";
        FreeLoadedData();
    }

    // Prevent copy constructor and assignment operator
    UsersManager(const UsersManager&) = delete;
    void operator=(const UsersManager&) = delete;

    // Load dummy database
    void LoadDatabase() {
        cout << "UsersManager: LoadDatabase\n";

    FreeLoadedData();

    // some "Dummy Data" for simplicity
    Admin* admin_user = new Admin();
    admin_user->SetUserName("hussein");
    admin_user->SetPassword("111");
    admin_user->SetEmail("hussein@gmail.com");
    admin_user->SetName("Hussein Hany Hussein");
    username_userobject_map[admin_user->GetUserName()] = admin_user;

    Customer* customer_user = new Customer();
    customer_user->SetUserName("user");
    customer_user->SetPassword("111");
    customer_user->SetEmail("hany@gmail.com");
    customer_user->SetName("Hany Hussien Ahmed");

    DebitCard* debit_card = new DebitCard();
    debit_card->SetOwnerName(customer_user->GetName());
    debit_card->SetCardNumber("11-22-33-44");
    debit_card->SetExpiryDate("11/20");
    debit_card->SetSecurityCode(111);
    debit_card->SetBillingAddress("111 hello st, BC, Canada");
    customer_user->AddPaymentCard(*debit_card);

    CreditCard* credit_card = new CreditCard();
    credit_card->SetOwnerName(customer_user->GetName());
    credit_card->SetCardNumber("22-11-03-44");
    credit_card->SetExpiryDate("11/25");
    credit_card->SetSecurityCode(1117);
    customer_user->AddPaymentCard(*credit_card);
    username_userobject_map[customer_user->GetUserName()] = customer_user;

    }

    void AccessSystem() {
        int choice = ShowReadMenu( { "Login", "Customer Sign Up" });
        if (choice == 1)
            DoLogin();
        else
            DoSignUp();
    }

    void DoLogin() {
        LoadDatabase();

        while (true) {
            string user_name, pass;
            cout << "Enter user user_name & password: ";
            cin >> user_name >> pass;

            if (!username_userobject_map.count(user_name)) {
                cout << "\nInvalid user user_name or password. Try again\n\n";
                continue;
            }
            User* user_exist = username_userobject_map.find(user_name)->second;

            if (pass != user_exist->GetPassword()) {
                cout << "\nInvalid user user_name or password. Try again\n\n";
                continue;
            }
            current_user = user_exist;
            break;
        }
    }

    void DoSignUp() {
        string user_name;
        while (true) {
            cout << "Enter user name. (No spaces): ";
            cin >> user_name;

            if (username_userobject_map.count(user_name))
                cout << "Already used. Try again\n";
            else
                break;
        }
        current_user = new Customer();
        current_user->Read(user_name);
        username_userobject_map[current_user->GetUserName()] = current_user;
    }

    User* GetCurrentUser() const {
        // For simplicity, I don't return it as const, which is not good
        // One ok way: return as const, and user support clone + copy contstructor. Then caller can make his own copy
        return current_user;
    }
};

#endif //EXPEDIA_COM_USR_MGR_H
