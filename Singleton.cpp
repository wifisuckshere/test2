#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton rises!\n";
    }
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton;
        }
        return instance;
    }

    void Identify() {
        cout << "Hello world.\n";
    }
};

Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* s = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s->Identify();
    s2->Identify();

    cout << "\n" << (s2 == s);
}

