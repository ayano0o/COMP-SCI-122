#ifndef CITY_HEADER_INCLUDED
#define CITY_HEADER_INCLUDED


class City {
public:
    City(const string& name, double x, double y) : name(name), x(x), y(y) {}

    const string& getName() const {
        return name;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

private:
    string name;
    double x, y;
};

#endif
