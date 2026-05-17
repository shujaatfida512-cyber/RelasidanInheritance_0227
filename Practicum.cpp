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