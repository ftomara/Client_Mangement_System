#include <iostream>
#include <cmath>
using namespace std;
class date
{
private:
    int days;
    int month;
    int year;

public:
    date()
    {
        days = 0;
        month = 0;
        year = 0;
    }
    date(int d, int m, int y)
    {
        days = set_d(d);
        month = set_m(m);
        year = set_y(y);
    }
    void setdate(int d, int m, int y)
    {
        days = d;
        month = m;
        year = y;
    }
    int set_d(int d)
    {
        return d;
    }
    int set_m(int m)
    {
        return m;
    }
    int set_y(int y)
    {
        return y;
    }
    void print_date()
    {
        cout << days << "/" << month << "/" << year << endl;
    }
    static int deadline(date dl, date t2)
    {
        int all;

        while (true)
        {
            if (dl.year > t2.year)
            {
                all = 1;
                break;
            }
            else if (dl.year < t2.year)
            {
                all = 2;
                break;
            }
            else if (dl.year == t2.year)
            {
                if (dl.month > t2.month)
                {
                    all = 1;
                    break;
                }
                else if (dl.month < t2.month)
                {
                    all = 2;
                    break;
                }
                else if (dl.month == t2.month)
                {
                    if (dl.days > t2.days)
                    {
                        all = 1;
                        break;
                    }
                    else if (dl.days < t2.days)
                    {
                        all = 2;
                        break;
                    }
                    else if (dl.days == t2.days)
                    {
                        all = 3;
                        break;
                    }
                }
            }
        }
        return all;
    }

    static void calcbefore(date st, date end)
    {

        int total1 = st.year * 365 + st.month * 30 + st.days;
        int total2 = end.year * 365 + end.month * 30 + end.days;
        int BD = abs(total2 - total1);
        date Tbd;
        Tbd.year = BD / 365;
        BD = BD % 365;
        Tbd.month = BD / 30;
        BD = BD % 30;
        Tbd.days = BD;

        Tbd.printTbd();
    }
    static void calcafter(date end, date dead)
    {
        int total2 = end.year * 365 + end.month * 30 + end.days;
        int total3 = dead.year * 365 + dead.month * 30 + dead.days;
        int AD = abs(total3 - total2);
        date Tad;
        Tad.year = AD / 365;
        AD = AD % 365;
        Tad.month = AD / 30;
        AD = AD % 30;
        Tad.days = AD;
        Tad.printTad();
    }

    void printTbd()
    {
        if (month == 0 && year == 0)
            cout << days << " days ";
        else
            cout << days << " days " << month << " month " << year << " year ";
    }
    void printTad()
    {
        if (month == 0 && year == 0)
            cout << days << " days ";

        else
            cout << days << " days " << month << " month " << year << " year ";
    }
};

// int monthnum(int month)
// {
//     int num;
//     switch (month)
//     {
//     case 1:
//     case 3:
//     case 5:
//     case 7:
//     case 8:
//     case 10:
//     case 12:
//         num = 31;
//         break;
//     case 4:
//     case 6:
//     case 9:
//     case 11:
//         num = 30;
//         break;
//     case 2:
//         num = 28;
//         break;
//     }
//     return num;

// }