#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
class timecalc
{

private:
    int m_hrs;
    int m_mins;

public:
    timecalc()
    {
        m_hrs = 0;
        m_mins = 0;
    }
    timecalc(int h, int mi)
    {
        m_hrs = h;
        m_mins = mi;
    }
    void setTime(int h, int mi)
    {
        m_hrs = h;
        m_mins = mi;
    }

    static timecalc duration(timecalc t1, timecalc t2)
    {
        timecalc dur;
        dur.m_hrs = abs(t2.m_hrs - t1.m_hrs);
        dur.m_mins = abs(t2.m_mins - t1.m_mins);

        return dur;
    }
    timecalc operator+(timecalc t1)
    {
        int m = m_mins + t1.m_mins;
        int h = 0;
        if (m >= 60)
        {
            h += m / 60;
            m = m % 60;
        }
        h = m_hrs + t1.m_hrs;
        return timecalc(h, m);
    }

    void print_time()
    {

        cout << m_hrs << ":" << m_mins << "\n";
    }
    void printdur()
    {
        cout << m_hrs << "H:" << m_mins << "M\n";
    }

    int convmins(timecalc all)
    {
        int mintues = (all.m_hrs * 60) + all.m_mins;
        return mintues;
    }
};

// int set_h(int h)
// {
//     return h;
// }
// int set_m(int mi)
// {
//     return mi;
// }

// timecalc operator-(timecalc time)
// {

//     // int time1 = (h1 * 3600) + (m1 * 60) + s1;
//     // int time2 = (h2 * 3600) + (m2 * 60) + s2;
//     // int diffSec = abs(time1 - time2);

//     // // Calculate the difference in hours, minutes and seconds
//     // diffHrs = diffSec / 3600;
//     // diffSec = diffSec % 3600;
//     // diffMins = diffSec / 60;
//     // diffSec = diffSec %60;
//     // int mins = m_mins - time.m_mins;
//     // int hrs = m_hrs - time.m_hrs;
//     // if (seconds >= 60)
//     // {
//     //     seconds -= 60;
//     //     mins++;
//     // }
//     // if (mins >= 60)
//     // {
//     //     mins -= 60;
//     //     hrs++;
//     // }
//     return timecalc(hrs, mins);
// }
// int time1 = (t1.m_hrs * 3600) + (t1.m_mins * 60) + t1.m_secs;
//         int time2 = (t2.m_hrs * 3600) + (t2.m_mins * 60) + t2.m_secs;
//         int diffSec = abs(time1 - time2);

//         // Calculate the difference in hours, minutes and seconds
//         dur.m_hrs = diffSec / 3600;
//         diffSec = diffSec % 3600;
//         dur.m_mins = diffSec / 60;
//         diffSec = diffSec % 60;