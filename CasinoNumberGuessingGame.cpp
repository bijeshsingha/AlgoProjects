#include <bits/stdc++.h>
using namespace std;

void welcomeScreen(string &name)
{
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to the Guessing Game " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl
         << endl;
    cout << "Enter your name: ";
    cin >> name;
    cout << endl
         << endl;
    cout << "Hi " << name << ", Please enter deposit amount: ";
}

void congWindow(string name, int balance, int betAmount)
{
    system("cls");
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to the Guessing Game " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl
         << endl;
    cout << "Congratulations! " << name << " you won $" << betAmount << endl
         << endl
         << endl;
    cout << "Your current balance is: $" << balance;
}

void lostWindow(string name, int randNumber, int betAmount)
{
    system("cls");
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to the Guessing Game " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl
         << endl;
    cout << "Sorry " << name << " you lost yout bet -$" << betAmount << endl
         << endl
         << endl
         << "The winning number was " << randNumber << endl
         << endl
         << endl;
}

void casinoGame()
{
    char ch;
    string name;
    int deptAmount = 10000;
    int betAmount = 0;
    int guessNumber;
    int randNumber = 2;
    int balance;

    welcomeScreen(name);
    // cin >> deptAmount;
    while (!(cin >> deptAmount))
    {
        std::cin.clear();                                                   // clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        std::cout << endl
                  << "Invalid input! please re-enter.\n";
    }
    balance = deptAmount;

    do
    {
        randNumber = rand() % 5;
        if (randNumber == 0)
        {
            randNumber = 5;
        }
        system("cls");
        cout << "-------------------------------------------------" << endl;
        cout << "Welcome to the Guessing Game " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl
             << endl;
        cout << name << ", your current balance is: $" << balance;
        cout << endl
             << endl;
        cout << "Enter bet amount: ";
        while (!(cin >> betAmount))
        {
            std::cin.clear();                                                   // clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
            std::cout << endl
                      << "Invalid input! please re-enter: ";
        }
        cout << endl
             << endl;
        cout << "Guess the winning number between 1 - 5: ";
        while (!(cin >> guessNumber))
        {
            std::cin.clear();                                                   // clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
            std::cout << endl
                      << "Invalid input! please re-enter: ";
        }
        cout << endl
             << endl;
        while (guessNumber < 1 || guessNumber > 5)
        {
            cout << "You cannot guess outside the range! " << endl;
            cout << "Try guessing again: ";
            while (!(cin >> guessNumber))
            {
                std::cin.clear();                                                   // clear bad input flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
                std::cout << endl
                          << "Invalid input! please re-enter: ";
            }
            cout << endl
                 << endl;
        }
        if (guessNumber == randNumber)
        {
            balance += betAmount;
            congWindow(name, balance, betAmount);
        }
        else
        {

            balance -= betAmount;
            balance = max(balance, 0);
            lostWindow(name, randNumber, betAmount);
            if (balance == 0)
            {
                int topUp;
                cout << "Oops! your balance is exhaused! " << endl
                     << endl
                     << "Do you want to top up?y/n: ";
                cin >> ch;
                switch (ch)
                {
                case 'y':
                    cout << "Enter top up amount: ";
                    while (!(cin >> topUp))
                    {
                        std::cin.clear();                                                   // clear bad input flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
                        std::cout << endl
                                  << "Invalid input! please re-enter: ";
                    }
                    balance += topUp;
                    if (balance > 0)
                        continue;
                    break;
                case 'n':
                    break;
                default:
                    cout << "Invalid input! " << endl
                         << endl;
                }
                break;
            }
            cout << "Your current balance is: $" << balance;
        }
        cout << endl
             << endl;
        cout << "Do you want to continue?y/n: ";
        while (!(cin >> ch))
        {
            std::cin.clear();                                                   // clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
            std::cout << endl
                      << "Invalid input! The game automatically closed";
            break;
        }
        if (ch != 'y' && ch != 'n')
        {
            cout << endl
                 << "Invalid input! The game automatically closed" << endl
                 << endl;
            break;
        }
    } while (ch != 'n');
    cout << endl
         << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Thanks for playing!" << endl;
    cout << "-------------------------------------------------" << endl;
}

int main()
{
    srand(time(0));
    system("CLS");
    casinoGame();
    system("pause");
    return 0;
}