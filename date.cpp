#include "../class .h"

storage::date::date() {
    day = month = year = 0;
}

storage::date::date(int m_day, int m_month, int m_year) {
    day = m_day;
    month = m_month;
    year = m_year;
}

storage::date::date(const date &date) {
    day=date.day;
    month=date.month;
    year = date.year;
}

namespace storage {
    istream &operator>>(istream &in, storage::date &date) {
        cout << "\n\tDay: ";
        while (!(in >> date.day) || (date.day < 1) || (date.day > 31)) {
            cout << "\tERROR: wrong day\n";
            cout << "\tDay: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "\tMonth: ";
        while (!(in >> date.month) || (date.month < 1) || (date.month > 12)) {
            cout << "\tERROR: wrong month\n";
            cout << "\tMonth: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "\tYear: ";
        while (!(in >> date.year) || (date.year < 2000) || (date.day >= 3000)) {
            cout << "\tERROR: wrong year\n";
            cout << "\tYear: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        return in;
    }

    ostream &operator<<(ostream &out, const storage::date &date) {
        out << date.day << ".";
        if ((date.month >= 1) && (date.month <= 9))
            out << "0" << date.month << "." << date.year;
        else
            out << date.month << "." << date.year;
        return out;
    }
}