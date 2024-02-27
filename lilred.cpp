#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Counter {
private:
    int max_value;
    int value;
    bool overflow;

public:
    
    Counter(int max_val = 9999) : max_value(max_val), value(0), overflow(false) {
        if (max_val <= 0 || max_val > 9999) {
            throw invalid_argument("Invalid maximum value for Counter");
        }
    }

    
    int getValue() const {
        return value;
    }

    int getDollars() const {
        return value / 100;
    }

    int getCents() const {
        return value % 100;
    }

    bool isOverflow() const {
        return overflow;
    }

    
    void setValue(int val) {
        if (val < 0 || val > max_value) {
            throw std::out_of_range("Counter value out of range");
        }
        value = val;
        overflow = false;
    }

    void increment() {
        if (value == max_value) {
            value = 0;
            overflow = true;
        } else {
            value++;
        }
    }

    void decrement() {
        if (value == 0) {
            value = max_value;
        } else {
            value--;
        }
        overflow = false;
    }

    
    void displayRaw() const {
        cout << setw(4) << setfill('0') << value;
    }

    void displayMonetary() const {
        cout << '$' << getDollars() << '.' << setw(2) << setfill('0') << getCents();
    }
};


int main() {
    try {
        Counter counter;

        
        counter.increment();
        counter.displayMonetary();
        cout << endl;

        
        counter.setValue(1234);
        counter.displayRaw();
        cout << endl;

        
        counter.decrement();
        counter.displayMonetary();
        cout << endl;

       
        counter.setValue(9999);
        counter.increment();
        cout << "Overflow: " << boolalpha << counter.isOverflow() << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
