#include <iostream>        
#include <string>
#include <unordered_map>

using namespace std;  

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<long long, int>> routeData;

public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkInInfo = checkIns[id];
        string startStation = checkInInfo.first;
        int checkInTime = checkInInfo.second;
        
        string routeName = startStation + "->" + stationName;
        int travelTime = t - checkInTime;
        
        routeData[routeName].first += travelTime;
        routeData[routeName].second += 1;
        
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "->" + endStation;
        auto data = routeData[routeName];
        return (double)data.first / data.second;
    }
};

int main() {
    cout << "--- PRUEBA UNDERGROUND SYSTEM ---" << endl;
    UndergroundSystem* undergroundSystem = new UndergroundSystem();
    
    undergroundSystem->checkIn(45, "Leyton", 3);
    undergroundSystem->checkIn(32, "Paradise", 8);
    undergroundSystem->checkIn(27, "Leyton", 10);
    
    undergroundSystem->checkOut(45, "Waterloo", 15);
    undergroundSystem->checkOut(27, "Waterloo", 20);
    undergroundSystem->checkOut(32, "Cambridge", 22);
    
    cout << "Promedio Leyton -> Waterloo: " 
         << undergroundSystem->getAverageTime("Leyton", "Waterloo") << endl;
         
    cout << "Promedio Paradise -> Cambridge: " 
         << undergroundSystem->getAverageTime("Paradise", "Cambridge") << endl; 
         
    delete undergroundSystem;
    return 0;
}
