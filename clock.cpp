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
int main() {
    cout << "--- PRUEBA SISTEMA DE RELOJ ---" << endl;
    
    Clock c1(10, 30);
    cout << "Hora inicial: " << c1.to_string() << endl;
    
    c1.add(90);
    cout << "Tras sumar 90 min (Esperado 12:00): " << c1.to_string() << endl;
    
    c1.subtract(150);
    cout << "Tras restar 150 min (Esperado 09:30): " << c1.to_string() << endl;
    
    Clock c2(9, 30);
    if (c1 == c2) {
        cout << "c1 y c2 representan la misma hora." << endl;
    }
    
    return 0;
}
