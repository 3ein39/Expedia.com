//
// Created by hussein on 8/2/22.
//

#include<iostream>
#include<vector>
using namespace std;

#include"customer.h"
#include"usr_mgr.h"
#include"customer_view.h"

class ExpediaFrontend {
private:
    UsersManager* users_manager;
    ExpediaBackend* expedia_manager;
    CustomerManager* customer_manager = nullptr;

    void LoadDatabase() {
        users_manager->LoadDatabase();
    }

public:
    // prevent copy constructor and assignment operator
    ExpediaFrontend(const ExpediaFrontend&) = delete;
    void operator=(const ExpediaFrontend&) = delete;

    ExpediaFrontend() : users_manager(new UsersManager()), expedia_manager(new ExpediaBackend()){
    }

    ~ExpediaFrontend() {
        cout << "Destructor: ExpediaFrontend\n";

        if (users_manager != nullptr) {
            delete users_manager;
            users_manager = nullptr;
        }
    }

    void Run() {
        LoadDatabase();

        while (true) {
            users_manager->AccessSystem(); // login/signup

            if(users_manager->GetCurrentUser()->GetType() == UserType::CusomterUser) {
                customer_manager = new CustomerManager(users_manager->GetCurrentUser(), *expedia_manager);
                CustomerView view(*customer_manager);
                view.Display();
            } else
                assert(false);
        }
    }
};

// TODO  Add more flight classes + later operator overloading something + Simulators + logging + integration/unit test + its exception hierarchy
//  Singleton loading DB config for flights

int main() {
    ExpediaFrontend site;
    site.Run();

    User* user = new Customer();
    // dynamic_cast<Customer*>(user);

    return 0;
}


