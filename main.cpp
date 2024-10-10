// COMSC-210 | Lab 20: Chair Maker 3000 | Nina Tsao

#include <iostream>
#include <iomanip>
#include <cstdlib>  // rand()
using namespace std;

const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {       // default constructor
        prices = new double[SIZE];
        legs = (rand() % (4-3+1) + 3);      // randomly select 3 or 4 legs
        for (int i = 0; i < SIZE; i++)
        prices[i] = (rand() % (MAX-MIN+1) + MIN) / (double) 100;    // randomly select prices from $100.00 to $999.99
                                                                    // (including dollars & cents)
    }
                 // an array of 3 doubles (the prices)
    Chair(int l, double p[SIZE]) {  // parameter constructor
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
        prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
        sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print();

    //creating dynamic chair object with constructor
    double p[SIZE] = {525.25, 434.34, 252.52};

    Chair *livingChair = new Chair(3, p);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];

    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    return 0;
}