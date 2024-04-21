#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
#include "arraycl.cpp"
// #include "client.cpp"
//  #include "project.cpp"
using namespace std;

void print(string s)
{
    cout << s;
}
int main()
{
    // project p;
    // p.readinput();
    // p.printproject();

    arraycl clients(100);
    char charr;

    while (charr != 27)
    {
        sleep(1);
        system("clear");
        print("\n\n\t\t\t\t----------------------------------------- \n");
        print("\n\n\t\t\t\t\" Welcome to Client Time Mangement App \"\n");
        print("\n\n\t\t\t\t----------------------------------------- \n");
        print("\t\t1.Add new client \n");
        print("\t\t2.Add new project \n");
        print("\t\t3.Add timesheet for client\n");
        print("\t\t4.Display all clients \n");
        print("\t\t5.Display all projects \n");
        print("\t\t6.Search for Client \n");
        // print("\t\t7.Delete Project for a Client\n");
        print("\t\tesc.Exit program\n");
        print("Enter selection --->  ");
        cin >> charr;

        switch (charr)
        {
        case 49:

            clients.clientnum();

            break;
        case 50:

            clients.addnewproj();

            break;
        case 51:

            clients.addnewtimesheet();

            break;
        case 52:

            clients.print();

            break;
        case 53:

            clients.displaypro();

            break;

        case 54:

            clients.search();

            break;
            // case 55:
            //     clients.deleteproject();

            //     break;

        case 27:

            print("\t\t\t\t Session is over....\n");
            sleep(2);
            system("clear");
            break;
        default:
            print("\n\nINVALID\n");
            sleep(2);
            system("clear");
        }
    }

    return 0;
}