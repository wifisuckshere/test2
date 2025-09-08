// Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

void displayDongs(int num) {
    int divisor = 1;

    int digitcount = 1;
    while (divisor < num / 10) {
        digitcount++;
        divisor *= 10;
    }

    int howmany = 3 - digitcount % 3;
    bool firstprint = false;

    while (divisor > 0) {
        if (howmany % 3 == 0 && firstprint == true) {
            cout << ",";
        }
        int digit = num / divisor;
        cout << digit;
        num %= divisor;
        divisor /= 10;
        howmany++;
        firstprint = true;
    }
}

class Transport {
public:
    int speed;
    int load;
    int maxLoad;
    int costPerKm;
    virtual ~Transport() {}
    virtual void Identify() = 0;
    int calcRealSpeed() {
        double factor = 1.0 - (static_cast<double>(load) / maxLoad);
        factor = (factor + 1) / 2;
        cout << "\nSlowdown Factor: " << (1 - factor) * 100 << "%";
        cout << "\nReal Speed: : " << speed * factor << "KM / H";
        return static_cast<int>(speed * factor);
    }
    void calcCost(int distance) {
        int cost = load * distance * costPerKm;
        cout << "\nCost (VND): ";
        displayDongs(cost);
    }
    double calcTime(int distance) {
        return static_cast<double>(distance) / calcRealSpeed();
    }
};

class Truck : public Transport {
public:
    Truck() {
        speed = 100;
        load = 0;
        maxLoad = 20;
        costPerKm = 2600;
    }
    void Identify();
};



void Truck::Identify() {
    cout << "\nTransporting by truck.\n";
}

class Boat : public Transport {
public:
    Boat() {
        speed = 35;
        load = 0;
        maxLoad = 100000;
        costPerKm = 200;
    }
    void Identify();
};

void Boat::Identify() {
    cout << "\nTransporting by boat.\n";
}

class doLogistics {
public:
    ~doLogistics() {}
    Transport* createTransport() {
        int load;
        cout << "Enter Load (Tons): ";
        cin >> load;

        Transport* t;
        if (load <= 20)
            t = new Truck;
        else
            t = new Boat;

        t->load = load;
        return t;
    }
};


int main()
{
    doLogistics logistics;
    Transport* t = logistics.createTransport();

    t->Identify();

    int distance;
    cout << "\nEnter Distance (KM): ";
    cin >> distance;

    cout << "\nTime Required: " << fixed << setprecision(2) << t->calcTime(distance) << " hours\n";
    t->calcCost(distance);
}
