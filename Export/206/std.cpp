#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_valid_date(int year, int month, int day) {
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int max_days = days_in_month[month];
    if (month == 2 && is_leap(year)) {
        max_days = 29;
    }

    return day <= max_days;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int date1, date2;
    cin >> date1 >> date2;

    int start_year = date1 / 10000;
    int end_year = date2 / 10000;

    int count = 0;
    for (int year = start_year; year <= end_year; ++year) {
        string s_year = to_string(year);
        if (s_year.length() < 4) {
             s_year.insert(0, 4 - s_year.length(), '0');
        }
        string reversed_s_year = s_year;
        reverse(reversed_s_year.begin(), reversed_s_year.end());

        int month = stoi(reversed_s_year.substr(0, 2));
        int day = stoi(reversed_s_year.substr(2, 2));

        if (is_valid_date(year, month, day)) {
            int current_date = year * 10000 + month * 100 + day;
            if (current_date >= date1 && current_date <= date2) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
