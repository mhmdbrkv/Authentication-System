#include <iostream>
#include <string>

using namespace std;



void mainmenu()
{
    system("cls");
    cout << "Welcom to Baraka security system project.\n";
    cout << "-----------------------------------------\n";
    cout << "1) Login.\n\n";
    cout << "2) Register.\n\n";
    cout << "3) Show Data.\n\n";
    cout << "4) Clear Screen.\n\n";
    cout << "5) Exit.\n";
    cout << "-----------------------------------------\n\n";

}


class security {

    int idx{ 0 };

    int Password[50]{};

    string Username[50]{};
    
public:

    void Register() {


        if (idx == 50)
        {
            cout << "Too much accounts.";
            return;
        }
        else {

            string username;
            cout << "Enter username: ";
            cin >> username;

            int password;

            for (int i = 0; i <= idx; i++)
            {
                if (Username[i] == username)
                {
                    cout << "Username is already exists\n";
                    break;
                }
                else {

                    Username[idx] = username;

                    cout << "Enter password: ";
                    cin >> password;

                    Password[idx] = password;

                    idx++;

                    break;
                }
            }

        }
        cout << endl;
    }

    void Login()
    {

        int password{0};
        string username;

        cout << "Enter your username: ";
        cin >> username;

        cout << "Enter your password: ";
        cin >> password;

        int cnt = 0;

        for (int i = 0; i <= idx; i++)
        {
            if (Password[i] == password && Username[i] == username)
            {
                cnt++;
                break;
            }
            
        }

        if (cnt != 0)
        {
            cout << "Login done successfully.\n";
        }
        else cout << "This account does not exist\n";

        cnt = 0;
        cout << endl;
    }

    void showdata()
    {
        int option = 1;

        while (option) {

            cout << "Usernames\tPassword\n";

            for (int i = 0; i < idx; i++)
            {
                cout << Username[i] << "\t\t" << Password[i] << endl;
            }
            cout << endl;

            cout << "Press 0 to back to main menu: ";
            cin >> option;
            mainmenu();
        }
        cout << endl;
    }

};


int main()


{
    security account;
    mainmenu();

    int option{0};

    while (option != 5)
    {

        cout << "Enter your option: ";
        cin >> option;

        if (option < 1 || option > 5)
        {
            cout << "Error... try again: \n";
            break;
        }
        else
        {
            switch (option)
            {
            case 1: account.Login();
                break;

            case 2: account.Register();
                break;


            case 3: account.showdata();
                break;

            case 4: mainmenu();
                break;

            case 5:cout << "See you soon :)\n";
                break;

            default: cout << "Error..! try again\n";
                break;
            }
            cout << endl;

        }
    }

    return 0;
}

