#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton rises!";
    }
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton;
        }
        return instance;
    }

    void Identify() {
        cout << "Hello world.";
    }
};

Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* s = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s->Identify();
    s->Identify();

    cout << "\n" << (s2 == s);
}

