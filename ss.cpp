#include <iostream>
using namespace std;

class Chair {
public:
    virtual void sitOn() = 0;
    virtual ~Chair() {}
};

class ModernChair : public Chair {
public:
    void sitOn() { cout << "\nSitting on a Modern Chair"; }
};

class VictorianChair : public Chair {
public:
    void sitOn() { cout << "\nSitting on a Victorian Chair"; }
};

class Table {
public:
    virtual void putOn() = 0;
    virtual ~Table() {}
};

class ModernTable : public Table {
public:
    void putOn() { cout << "\nPutting things on a Modern Table"; }
};

class VictorianTable : public Table {
public:
    void putOn() { cout << "\nPutting things on a Victorian Table"; }
};

class furnitureFactory {
public:
    virtual Chair* createChair() = 0;
    virtual Table* createTable() = 0;
};

class modernFactory : public furnitureFactory {
public:
    Chair* createChair() override {
        Chair* c = new ModernChair;
        return c;
    }
    Table* createTable() override {
        Table* t = new ModernTable;
        return t;
    }
};

class victorianFactory : public furnitureFactory {
public:
    Chair* createChair() override {
        Chair* c = new VictorianChair;
        return c;
    }
    Table* createTable() override {
        Table* t = new VictorianTable;
        return t;
    }
};

void manufacturer(furnitureFactory& factory, Chair*& c, Table*& t) {
    c = factory.createChair();
    t = factory.createTable();
}

void askPref(modernFactory& m, victorianFactory& v, Chair*& c, Table*& t) {
    int choice;
    do {
        cout << "\nModern or Victorian Furniture?\n  1. Modern\n  2. Victorian\nEnter Choice: ";
        cin >> choice;
    } while (choice < 1 || choice > 2);

    if (choice == 1) {
        manufacturer(m, c, t);
    }
    else
        manufacturer(v, c, t);
}

int main()
{
    modernFactory m;
    victorianFactory v;

    Chair* c = nullptr;
    Table* t = nullptr;

    askPref(m, v, c, t);

    c->sitOn();
    t->putOn();
    
    cout << "\n";
}
