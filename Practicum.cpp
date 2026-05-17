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