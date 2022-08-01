//
// Created by hussein on 8/1/22.
//

#ifndef EXPEDIA_COM_USER_H
#define EXPEDIA_COM_USER_H

using namespace std;

enum class UserType { CustomerUser = 0, AdminUser = 1 };

class User {
protected:
    string user_name;
    string password;
    string name;
    string email;
    UserType type = UserType::CustomerUser;

public:
    // prevent copy constructor and assignment operator
    User(const User&) = delete;
    void operator=(const User&) = delete;

    User() {}

    // to allow dynamic casting
    virtual ~User() {}

    // for printing user || admin
    string ToString() const {
        ostringstream oss;
        oss << "Name: " << user_name;
        if (type == UserType::AdminUser)
            oss << " | Admin";
        else if (type == UserType::CustomerUser)
            oss << " | Customer";
        oss << "\n";
        oss << "Email: " << email << "\n";
        oss << "User name: " << user_name << "\n";
        return oss.str();
    }

    // for reading user info
    void Read(const string &user_name) {
        SetUserName(user_name);

        string str;

        cout << "Enter password: ";
        cin >> str;
        SetPassword(str);

        cout << "Enter name: ";
        cin >> str;
        SetName(str);

        cout << "Enter email: ";
        cin >> str;
        SetEmail(str);
    }

    // getters and setters
    const string& GetUserName() const {
        return user_name;
    }

    void SetUserName(const string& user_name) {
        this->user_name = user_name;
    }

    const string& GetPassword() const {
        return password;
    }

    void SetPassword(const string& password) {
        this->password = password;
    }

    const string& GetName() const {
        return name;
    }

    void SetName(const string& name) {
        this->name = name;
    }

    const string& GetEmail() const {
        return email;
    }

    void SetEmail(const string& email) {
        this->email = email;
    }

    UserType GetType() const {
        return type;
    }

    void SetType(UserType type) {
        this->type = type;
    }
};

class Admin : public User {
protected:
public:
    // prevent copy constructor and assignment operator
    Admin(const Admin&) = delete;
    void operator=(const Admin&) = delete;
    // default constructor
    Admin() {
        SetType(UserType::AdminUser);
    }

};

#endif //EXPEDIA_COM_USER_H
