#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Clock {
private:
    int total_minutes;

    void normalize() {
        total_minutes = total_minutes % 1440;
        if (total_minutes < 0) {
            total_minutes += 1440;
        }
    }

public:
    Clock(int h, int m) {
        total_minutes = h * 60 + m;
        normalize();
    }

    Clock& add(int m) {
        total_minutes += m;
        normalize();
        return *this;
    }

    Clock& subtract(int m) {
        total_minutes -= m;
        normalize();
        return *this;
    }

    bool operator==(const Clock& other) const {
        return total_minutes == other.total_minutes;
    }

    bool operator!=(const Clock& other) const {
        return total_minutes != other.total_minutes;
    }

    string to_string() const {
        int h = total_minutes / 60;
        int m = total_minutes % 60;
        stringstream ss;
        ss << setfill('0') << setw(2) << h << ":" 
           << setfill('0') << setw(2) << m;
        return ss.str();
    }
};
