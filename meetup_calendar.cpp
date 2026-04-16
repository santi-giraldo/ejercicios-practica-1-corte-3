#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class MeetupCalendar {
private:
    map<string, int> dayOfWeekMap = {
        {"Sunday", 0}, {"Monday", 1}, {"Tuesday", 2}, 
        {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6}
    };

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int getDaysInMonth(int year, int month) {
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        return 31;
    }

    int getFirstDayOfWeek(int year, int month) {
        static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        year -= month < 3;
        return ( year + year/4 - year/100 + year/400 + t[month-1] + 1) % 7;
    }

public:
    int getMeetupDate(int year, int month, string dayName, string weekSpecifier) {
        int targetDayOfWeek = dayOfWeekMap[dayName];
        int firstDayOfWeek = getFirstDayOfWeek(year, month);
        int daysInMonth = getDaysInMonth(year, month);
        
        vector<int> matchingDates;
        
        int currentDate = 1 + (targetDayOfWeek - firstDayOfWeek + 7) % 7;
        
        while (currentDate <= daysInMonth) {
            matchingDates.push_back(currentDate);
            currentDate += 7;
        }
        
        if (weekSpecifier == "first") return matchingDates[0];
        if (weekSpecifier == "second") return matchingDates[1];
        if (weekSpecifier == "third") return matchingDates[2];
        if (weekSpecifier == "fourth") return matchingDates[3];
        if (weekSpecifier == "last") return matchingDates.back();
        
        if (weekSpecifier == "teenth") {
            for (int date : matchingDates) {
                if (date >= 13 && date <= 19) {
                    return date;
                }
            }
        }
        
        return -1;
    }
};
