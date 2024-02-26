#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Month {
private:
    int month;

public:
    Month(int m) : month(m) {
        if (m < 1 || m > 12) {
            throw invalid_argument("Invalid month value");
        }
    }

    Month(const string& m) {
        if (m == "January" || m == "Jan" || m == "1") {
            month = 1;
        } else if (m == "February" || m == "Feb" || m == "2") {
            month = 2;
        } else if (m == "March" || m == "Mar" || m == "3") {
            month = 3;
        } else if (m == "April" || m == "Apr" || m == "4") {
            month = 4;
        } else if (m == "May" || m == "5") {
            month = 5;
        } else if (m == "June" || m == "Jun" || m == "6") {
            month = 6;
        } else if (m == "July" || m == "Jul" || m == "7") {
            month = 7;
        } else if (m == "August" || m == "Aug" || m == "8") {
            month = 8;
        } else if (m == "September" || m == "Sep" || m == "9") {
            month = 9;
        } else if (m == "October" || m == "Oct" || m == "10") {
            month = 10;
        } else if (m == "November" || m == "Nov" || m == "11") {
            month = 11;
        } else if (m == "December" || m == "Dec" || m == "12") {
            month = 12;
        } else {
            throw invalid_argument("Invalid month name or abbreviation");
        }
    }

    int get_month() const {
        return month;
    }

    void set_month(int m) {
        if (m < 1 || m > 12) {
            throw invalid_argument("Invalid month value");
        }
        month = m;
    }

    void input() {
        string input_month;
        cout << "Enter month (e.g., January, Jan, 1): ";
        cin >> input_month;
        *this = Month(input_month);
    }

    string output() const {
        switch (month) {
            case 1: return "January";
            case 2: return "February";
            case 3: return "March";
            case 4: return "April";
            case 5: return "May";
            case 6: return "June";
            case 7: return "July";
            case 8: return "August";
            case 9: return "September";
            case 10: return "October";
            case 11: return "November";
            case 12: return "December";
            default: return "Invalid month";
        }
    }

    void advance(int n) {
        month += n;
        month = (month - 1) % 12 + 1;
    }

    bool before(const Month& other) const {
        return month < other.month;
    }

    bool after(const Month& other) const {
        return month > other.month;
    }

    bool same(const Month& other) const {
        return month == other.month;
    }
};

int main() {
    try {
        
        Month m1(3);
        cout << "Month 1: " << m1.output() << endl;

       
        Month m2("December");
        cout << "Month 2: " << m2.get_month() << endl;

       
        Month m3(1);
        m3.input();
        cout << "Month 3: " << m3.output() << endl;

      
        m1.advance(5);
        cout << "After advancing 5 months: " << m1.output() << endl;

        
        if (m1.before(m2)) {
            cout << m1.output() << " comes before " << m2.output() << endl;
        } else if (m1.after(m2)) {
            cout << m1.output() << " comes after " << m2.output() << endl;
        } else if (m1.same(m2)) {
            cout << m1.output() << " is the same as " << m2.output() << endl;
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
