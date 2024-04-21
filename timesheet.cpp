#include <iostream>
#include <string.h>
#include "timecalc.cpp"
using namespace std;
class timesheet

{

private:
    timecalc STtime;
    timecalc Endtime;
    timecalc duration;

public:
    timesheet()
    {
    }
    timesheet(int h1, int mi1, int h2, int mi2)
    {
        STtime.setTime(h1, mi1);
        Endtime.setTime(h2, mi2);
    }

    void print_timesheet()
    {
        cout << "\n\t | Starting Time :   ";
        STtime.print_time();
        cout << " \n\t | Ending Time :  ";
        Endtime.print_time();
        cout << " \n\t | Duration : ";
        duration = timecalc::duration(STtime, Endtime);
        duration.printdur();
        cout << "\n\n";
    }
    timecalc getdu()
    {
        duration = timecalc::duration(STtime, Endtime);

        return duration;
    }
};