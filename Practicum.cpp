#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string name;
    string email;
public:
    // Constructor
    User(string n, string e) {
        name = n;
        email = e;
        generateId();
    }
    void generateId() {
        globalId++;
        id = globalId;
    }
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }

    string getEmail() {
        return email;
    }
};
int User::globalId = 1000;

class Member : public User {
private:
    bool status;

public:
    // Constructor
    Member(string n, string e, bool s = true)
        : User(n, e) {
        status = s;
    }
    void showProfile() {
        cout << "\n===== MEMBER PROFILE =====\n";
        cout << "ID     : " << id << endl;
        cout << "Name   : " << name << endl;
        cout << "Email  : " << email << endl;

        if (status)
            cout << "Status : Active\n";
        else
            cout << "Status : Inactive\n";
    }
    void setStatus(bool s) {
        status = s;
    }

    // Get status
    bool getStatus() {
        return status;
    }
};
class Admin : public User {
public:
    // Constructor
    Admin(string n, string e)
        : User(n, e) {
    }
    void showAllMembers(vector<Member>& members) {
        cout << "\n===== ALL MEMBERS =====\n";

        for (int i = 0; i < members.size(); i++) {
            cout << "\nMember " << i + 1 << endl;
            members[i].showProfile();
        }
    }
    void toggleMemberActivation(Member& m) {

        if (m.getStatus()) {
            m.setStatus(false);
            cout << "\nMember deactivated successfully.\n";
        }
        else {
            m.setStatus(true);
            cout << "\nMember activated successfully.\n";
        }
    }
};

int main()
{
    Member m1("Ali", "ali@gmail.com");
    Member m2("Sara", "sara@gmail.com");

    Admin admin1("Admin", "admin@gmail.com");

    vector<Member> members;
    members.push_back(m1);
    members.push_back(m2);

    admin1.showAllMembers(members);

    admin1.toggleMemberActivation(members[0]);

    admin1.showAllMembers(members);

}

