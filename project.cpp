#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
#include "timesheet.cpp"
#include "date.cpp"

class project
{
private:
    string name;
    string description;
    date startdate;
    date deadline;
    date enddate;
    time_t created;
    timesheet *m_timesheets;
    int m_time_size;
    int m_time_count;
    int passed;
    int m_id;
    timecalc sumdu;

public:
    project()
    {
        time(&created);
        m_time_size = 5;
        m_timesheets = new timesheet[m_time_size];
        m_time_count = 0;
    }
    ~project()
    {

        delete[] m_timesheets;
    }
    void setname_desc(string n, string desc)
    {
        name = n;
        description = desc;
    }
    void addtimesheetss(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << "\n\n\tPlease Enter time in 24-hour time notation \n";
            cout << "------------------------" << endl;
            int h1, mi1, h2, mi2;

            cout << "Enter start time : \n";
            cout << "Enter Hour : ";
            cin >> h1;
            cout << "Enter Minutes : ";
            cin >> mi1;

            cout << "------------------------" << endl;
            cout << "Enter End time : \n";
            cout << "Enter Hour : ";
            cin >> h2;
            cout << "Enter Minutes : ";
            cin >> mi2;

            timesheet *new_time = new timesheet(h1, mi1, h2, mi2);
            m_timesheets[m_time_count++] = *new_time;
            cout << " \n\nTIME SHEET has been added :)\n";
            sleep(2);
            system("clear");
        }
    }
    void addtimesheet()
    {
        cout << "\n\n\tPlease Enter time in 24-hour time notation \n";
        cout << "------------------------" << endl;
        int h1, mi1, h2, mi2;

        cout << "Enter start time : \n";
        cout << "Enter Hour : ";
        cin >> h1;
        cout << "Enter Minutes : ";
        cin >> mi1;

        cout << "------------------------" << endl;
        cout << "Enter End time : \n";
        cout << "Enter Hour : ";
        cin >> h2;
        cout << "Enter Minutes : ";
        cin >> mi2;

        timesheet *new_time = new timesheet(h1, mi1, h2, mi2);
        m_timesheets[m_time_count++] = *new_time;
        totaldu();

        cout << " \n\nTIME SHEET has been added :)\n";
    }

    void readinput()
    {
        cout << "Enter project information :-\n";
        cout << "Project Name:";
        // cin.ignore();
        getline(cin, name);
        // cin.ignore();
        cout << "Description:";
        // cin.ignore();
        getline(cin, description);
        sleep(1);
        system("clear");
        int n = 0;

        int d0, m0, y0;
        cout << "\n\nEnter starting Date : \n";
        cout << "Enter day number : ";
        cin >> d0;
        cout << "Enter Month number : ";
        cin >> m0;
        cout << "Enter Year number : ";
        cin >> y0;
        startdate.setdate(d0, m0, y0);
        sleep(2);
        system("clear");
        cout << "How many Time sheets (0-" << m_time_size - m_time_count << ")?";
        cin.ignore();
        cin >> n;
        if (n != 0)
        {
            addtimesheetss(n);
            totaldu();
            sleep(2);
            system("clear");
        }
        int d1, m1, y1, d2, m2, y2;
        cout << "------------------------" << endl;
        cout << " Enter your End date : \n";
        cout << "------------------------" << endl;
        cout << "Enter day number : ";
        cin >> d1;
        cout << "Enter Month number : ";
        cin >> m1;
        cout << "Enter Year number : ";
        cin >> y1;
        enddate.setdate(d1, m1, y1);

        cout << "------------------------" << endl;
        cout << "Enter your Deadline Date : \n";
        cout << "------------------------" << endl;
        cout << "Enter day number : ";
        cin >> d2;
        cout << "Enter Month number : ";
        cin >> m2;
        cout << "Enter Year number : ";
        cin >> y2;
        deadline.setdate(d2, m2, y2);
        sleep(2);
        system("clear");
        cout << " \n\n PROJECT has been added :)\n";
        sleep(2);
        system("clear");
    }
    void printproject()
    {

        cout << "\n\nHere is project(" << m_id << ")information -->\n "
             << "Created at : " << asctime(localtime(&created))
             << "\n Name:" << name
             << "\n Description:" << description;

        int t;
        cout << "\n\nDo you want to print all Timesheets ?"
             << "\n->0-for all Timesheets"
             << "\n->type it's number "
             << "\n->(-1)- to Exit: ";
        cin >> t;
        if (t == 0)
        {

            if (m_time_count > 0)
            {
                cout << "\n\t Timesheets List for ";
                printproName();
            }
            for (int i = 0; i < m_time_count; ++i)
            {
                cout << i + 1 << " - ";
                m_timesheets[i].print_timesheet();
                cout << "\n\t------------------------------------------\n";
            }
        }
        else if (t == -1)
            return;
        else
        {
            cout << "\n\tTime sheet NO." << t << "\n";
            m_timesheets[t - 1].print_timesheet();
        }

        cout << "\n-->You started it at : ";
        startdate.print_date();
        cout << "\n-->You finished it at : ";
        enddate.print_date();
        cout << "\n-->You Spent : ";
        sumdu.printdur();
        cout << " And ";
        date::calcbefore(startdate, enddate);
        cout << "\n-->Deadline is due to : ";
        deadline.print_date();

        int pass = date::deadline(deadline, enddate);
        if (pass == 1)
        {
            cout << "\n-->There is  ";
            date::calcafter(enddate, deadline);
            cout << " left till the deadline :)\n";
        }
        else if (pass == 2)
        {
            cout << "\n-->Deadline passed ";
            date::calcafter(enddate, deadline);
            cout << " ago \n";
        }
        else if (pass == 3)
            cout << "\n-->Deadline is today!\n";
        int y;
        cout << "---> Did you finish? press 1 to continue : ";
        cin >> y;
        if (y)
            system("clear");
    }

    void setprojectid(int id)
    {
        m_id = id;
    }
    int getprojectid()
    {
        return m_id;
    }
    void printproName()
    {
        cout << "\n\n project(" << m_id << ") - " << name << "\n";
    }
    timecalc totaldu()
    {
        timecalc sum;
        for (int i = 0; i < m_time_count; i++)
        {
            sum = sum + m_timesheets[i].getdu();
        }
        sumdu = sum;
        return sumdu;
    }
    int getsumdu()
    {
        int conv;
        conv = sumdu.convmins(sumdu);
        return conv;
    }
};