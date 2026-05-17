#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string name;
    string email;