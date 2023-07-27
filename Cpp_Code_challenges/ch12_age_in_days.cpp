// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ctime>

int daysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year) {
        if (year % 4 != 0) {
            return false;
        }
        else if (year % 100 != 0) {
            return true;
        }
        else if (year % 400 != 0) {
            return false;
        }
        else {
            return true;
        }

}

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d;
    int age = 0;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    time_t now = time(0);

    struct tm timeStruct;
    timeStruct = *localtime(&now);
    today_d = timeStruct.tm_mday;
    today_m = timeStruct.tm_mon + 1;
    today_y = timeStruct.tm_year + 1900;

    if (birth_y * 365 + birth_m * 30 + birth_d > today_y * 365 + today_m * 30 + today_d) {
        std::cout << "\n" << "You have not been born yet\n\n" << std::flush;
    }
 
    // solution-1

    int commonYearsCount = 0;
    int leapYearsCount = 0;
    for (int i = birth_y + 1; i < today_y; i++) {
        if (isLeapYear(i)) {
            age += 366;
        }
        else {
            age += 365;
        }
    }

    int dayslivedInBirthYear = 0;
    for (int i = birth_m; i <= 12; i++) {
        switch (i) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dayslivedInBirthYear += 31;
            break;
        case 2:
            dayslivedInBirthYear += (isLeapYear(birth_y) ? 29 : 28);
            break;
        default:
            dayslivedInBirthYear += 30;
            break;
        }
    }

    dayslivedInBirthYear -= birth_d;




    int dayslivedInCurrentYear = 0;
    for (int i = 1; i <= today_m - 1; i++) {
        switch (i) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dayslivedInCurrentYear += 31;
            break;
        case 2:
            dayslivedInCurrentYear += (isLeapYear(today_y) ? 29 : 28);
            break;
        default:
            dayslivedInCurrentYear += 30;
            break;
        }
    }

    dayslivedInCurrentYear += today_d;
    age += (dayslivedInCurrentYear + dayslivedInBirthYear);


    //solution-2
    /*
    age = 0;
    int day = birth_d, month = birth_m, year = birth_y;

    while (day != today_d || month != today_m || year != today_y) {
        age++;
        day++;
        if (day > daysInMonths[month - 1]) {
            if (isLeapYear(year) && month == 2 && day == 29) {
                continue;
            }
            else {
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
    }
   */ 


    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
