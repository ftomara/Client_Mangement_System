#include <iostream>
#include <string>
#include <ctime>
#include "project.cpp"

class client
{
private:
    int m_id;
    string m_name;
    string m_phone;
    string m_email;
    string m_note;
    time_t addeddate;
    project *m_project;
    int m_project_size;
    int m_project_count;
    int maxdu;

public:
    client() {}
    client(int size)
    {
        time(&addeddate);
        m_project_size = size;
        m_project = new project[m_project_size];
        m_project_count = 0;
    }
    ~client()
    {
        delete[] m_project;
    }
    void user(int i, string n, string ph, string em, string NOTE)
    {

        m_id = i;
        m_name = n;
        m_phone = ph;
        m_email = em;
        m_note = NOTE;
    }
    void GetClientInfo()
    {
        cout << "Enter Your Name please : ";
        getline(cin, m_name);
        // cin.ignore();
        cout << "Enter Your Phone Number : ";

        cin >> m_phone;
        cout << "Enter Your Email : ";
        cin >> m_email;
        cout << "Enter A Note : ";
        cin >> m_note;
        int ch;
        cout << "Do you want to add project ? (0-NO / 1-YES) : ";
        cin >> ch;
        if (ch == 1)
            addnewproject();
    }
    void addnewproject()
    {
        int n;
        cout << "How many Projects (0 - " << m_project_size - m_project_count << ")?:";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; ++i)
        {
            project *new_project = new project;
            new_project->setprojectid(m_project_count + 1);
            cout << "Enter Project NO. " << m_project_count + 1 << endl;
            new_project->readinput();
            m_project[m_project_count++] = *new_project;
            cin.ignore();
        }
    }

    void printclientdetails()
    {
        cout << "Client NO. " << m_id << " ";
        cout << "\nCreated at : " << asctime(localtime(&addeddate));
        cout << "\n\t NAME: " << m_name;
        cout << "\t EMAIL: " << m_email;
        cout << "\t PHONE: " << m_phone;
        cout << "\tNOTE : " << m_note;
        cout << "\n\n\t Maximum Duration spent on Project : " << getmax() / 60 << " H : " << getmax() % 60 << " M ";

        printprojectclient();
    }
    void printprojectclient()
    {
        if (m_project_count == 0)
        {
            cout << "\nNO PROJECT FOUND!\n";

            return;
        }
        for (int i = 0; i < m_project_count; ++i)
        {
            m_project[i].printproName();
        }
        int pro;
        cout << "\n---------------------------------------------------------";
        cout << "\n\nDo you want to display all projects details ? \n";
        cout << "Press-->"
             << "\n->0-for all"
             << "\n->type Project ID  "
             << "\n->(-1)- to Exit: ";
        cin >> pro;

        if (pro == 0)
        {

            if (m_project_count == 0)
            {
                cout << "\nNO PROJECT FOUND!\n";

                return;
            }
            for (int i = 0; i < m_project_count; ++i)
            {
                m_project[i].printproject();
            }
        }
        else if (pro == -1)
            return;
        else
            m_project[pro - 1].printproject();
    }
    void setclID(int id)
    {
        m_id = id;
    }
    void printclientname()
    {
        cout << "Client (" << m_id << ") - " << m_name << endl;
    }
    void prolist()
    {

        cout << "\t\t PROJECTS LIST for ";
        printclientname();
        if (m_project_count == 0)
        {
            cout << "\nNo Existing Projects!\n";

            return;
        }
        else
        {
            for (int i = 0; i < m_project_count; ++i)
            {
                m_project[i].printproName();
            }
        }
    }

    void addnewTSH()
    {
        if (m_project_count == 0)
        {
            cout << "\n\tNO PROJECT FOUND!\n";

            return;
        }
        else
        {
            cout << "\n---------------------------------------------------------\n";
            int n;
            cout << "For Which Project ? \n";

            for (int i = 0; i < m_project_count; ++i)
            {

                m_project[i].printproName();
            }
            cin >> n;
            m_project[n - 1].addtimesheet();
        }
    }
    int getmax()
    {
        maxdu = 0;
        for (int i = 0; i < m_project_count; ++i)
        {
            if (m_project[i].getsumdu() > maxdu)
                maxdu = m_project[i].getsumdu();
        }
        return maxdu;
    }
    void printby()
    {

        cout << "\nClient NO. " << m_id << " ";
        cout << "\nCreated at : " << asctime(localtime(&addeddate));
        cout << "\n\t NAME: " << m_name;
        cout << "\t EMAIL: " << m_email;
        cout << "\t PHONE: " << m_phone;
        cout << "\tNOTE : " << m_note;
        cout << "\n\n\t Maximum Duration spent on Project : " << maxdu / 60 << " H : " << maxdu % 60 << " M ";
    }
};

// void detproject(int project_id)
// {
//     if (m_project_count == 0)
//     {
//         cout << "NO PROJECT EXIST!\n";
//         return;
//     }
//     bool deleted = false;

//     for (int i = 0; i < m_project_count; ++i)
//     {
//         if (m_project[i].getprojectid() == project_id)
//         {
//             if (i == m_project_count - 1)
//             {
//                 m_project_count--;
//             }
//             else
//             {
//                 m_project[i] = m_project[m_project_count - 1];
//                 m_project_count--;
//             }
//             deleted = true;
//             break;
//         }
//     }
//     if (deleted)
//     {
//         cout << "PROJECT DELETED SUCCESSFULLY !\n";
//     }
//     else
//     {
//         cout << "NO CLIENT EXIST!\n";
//     }
// }
// void editproject(int project_id)
// {
//     if (m_project_count == 0)
//     {
//         cout << "NO PROJECT EXIST!\n";
//         return;
//     }
//     bool edited = false;
//     for (int i = 0; i < m_project_count; ++i)
//     {
//         m_project[i].readinput();
//         edited = true;
//         break;
//     }

//     if (edited)
//     {
//         cout << "PROJECT EDITED SUCCESSFULLY !\n";
//     }
//     else
//     {
//         cout << "NO PROJECT EXIST!\n";
//     }
// }
