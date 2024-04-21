#include <iostream>
#include "client.cpp"
using namespace std;
class arraycl
{
private:
    client *m_clients;
    int m_client_size;
    int m_client_count;

public:
    arraycl(int m_csize)
    {
        m_client_size = m_csize;
        m_clients = new client[m_client_size];
        m_client_count = 0;
    }

    ~arraycl()
    {
        delete[] m_clients;
    }
    void clientnum()
    {
        int n;
        cout << "How many CLIENTS (0-" << m_client_size - m_client_count << ")?";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; ++i)
        {

            client *new_client = new client(50);

            new_client->setclID(m_client_count + 1);
            cout << "Enter Client NO. " << m_client_count + 1 << endl;
            new_client->GetClientInfo();
            m_clients[m_client_count++] = *new_client;
            cin.ignore();
        }
    }
    void print()
    {
        if (m_client_count == 0)
            cout << "\nThere are no clients to Display ! \n";
        else
        {
            int ch;
            cout << "\nDo you want them to be sorted ? (0-No/1-Yes):";
            cin >> ch;
            cout << "\n\t\tCLIENTS LIST : \n";
            if (ch == 1)
                printbymax();
            else
            {
                for (int i = 0; i < m_client_count; ++i)
                {

                    m_clients[i].printclientname();
                }
            }
            cout << "\n---------------------------------------------------------";
            int cl;
            cout << "\n\nDo you want to display all Clients details ? \n";
            cout << "Press-->"
                 << "\n0-for all CLients"
                 << "\nType Client ID :  "
                 << "\n(-1)- to Exit"
                 << "\nEnter Selection : ";

            cin >> cl;
            if (cl == -1)
                return;
            if (cl == 0)
            {
                for (int i = 0; i < m_client_count; ++i)
                {

                    m_clients[i].printclientdetails();
                }
            }
            else
            {
                while (cl > m_client_count || cl <= 0)
                {
                    cout << "\nThere is no client with this Id\n";
                    cout << "Please Enter valid ID : ";
                    cin >> cl;

                    if (cl <= m_client_count)
                    {

                        break;
                    }
                }
                m_clients[cl - 1].printclientdetails();
            }
        }
    }
    void addnewproj()
    {
        if (m_client_count == 0)
        {
            cout << "NO Client FOUND!\n";

            return;
        }
        else
        {
            cout << "\n---------------------------------------------------------\n";
            int n;
            cout << "For Which Client ? \n";

            for (int i = 0; i < m_client_count; ++i)
            {

                m_clients[i].printclientname();
            }
            cin >> n;
            m_clients[n - 1].addnewproject();
        }
    }
    void addnewtimesheet()
    {
        if (m_client_count == 0)
        {
            cout << "NO Client FOUND!\n";

            return;
        }
        else
        {
            cout << "\n---------------------------------------------------------\n";
            int n;
            cout << "For Which Client ? \n";

            for (int i = 0; i < m_client_count; ++i)
            {

                m_clients[i].printclientname();
            }
            cin >> n;
            while (n > m_client_count || n <= 0)
            {
                cout << "\nThere is no client with this Id\n";
                cout << "Please Enter valid ID : ";
                cin >> n;
                if (n <= m_client_count)
                {

                    break;
                }
            }
            m_clients[n - 1].addnewTSH();
        }
    }

    void displaypro()
    {
        if (m_client_count == 0)
        {
            cout << "\nNO Clients Exist , Please Enter a Client First ..\n";
            return;
        }
        for (int i = 0; i < m_client_count; ++i)
        {

            m_clients[i].prolist();
        }
        int m;
        cout << "If you finished press 1 : ";
        cin >> m;
        if (m)
            return;
    }
    void search()
    {
        int id;
        if (m_client_count == 0)
            cout << "\nThere are no clients to search for ! \n";
        else
        {
            cout << "\nEnter Client ID to find please..";
            cin >> id;
            while (id > m_client_count || id <= 0)
            {
                cout << "\nThere is no client with this Id\n";
                cout << "Please Enter valid ID : ";
                cin >> id;
                if (id <= m_client_count)
                {

                    break;
                }
            }
            m_clients[id - 1].printclientdetails();
        }
    }

    void printbymax()
    {
        int arr[100] = {0};
        for (int i = 0; i < m_client_count; ++i)
        {
            int max = 0;
            int pos;
            for (int j = 0; j < m_client_count; ++j)
            {
                if (arr[j] == 1)
                    continue;
                if (max <= m_clients[j].getmax())
                {
                    max = m_clients[j].getmax();
                    pos = j;
                    arr[j] = 1;
                    arr[j - 1] = 0;
                }
            }
            m_clients[pos].printby();
            pos = 0;
        }
    }
};
// void deleteproject()
// {
//     if (m_client_count == 0)
//     {
//         cout << "NO Client FOUND!\n";

//         return;
//     }
//     else
//     {
//         cout << "\n---------------------------------------------------------\n";
//         int n;
//         cout << "For Which Client ? \n";

//         for (int i = 0; i < m_client_count; ++i)
//         {

//             m_clients[i].printclientname();
//         }
//         cin >> n;
//         m_clients[n - 1].prolist();
//         cout << "\nFor Which Project ? \n";
//         cin >> n;
//         m_clients[n - 1].detproject(n);
//     }
// }
