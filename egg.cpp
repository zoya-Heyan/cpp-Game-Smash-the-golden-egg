#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "suiji.h"

using namespace std;

// ANSI color codes for colorful text
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define CLEAR "clear"  // use "cls" on Windows

class Egg
{
public:
    float Money = 200.0;
    Random rnd;

    void ShowMoney()
    {
        cout << CYAN << "+--------------------+" << endl;
        cout << "| Money: $" << Money << "          |" << endl;
        cout << "+--------------------+" << RESET << endl;
    }

    void Appear()
    {
        cout << YELLOW;
        cout << "     **     " << endl;
        cout << "   ******   " << endl;
        cout << "  ********  " << endl;
        cout << " ********** " << endl;
        cout << "************" << endl;
        cout << "  ********  " << endl;
        cout << "    ****    " << RESET << endl;
        ShowMoney();
    }

    void Smash()
    {
        const char* frames[] = {
            "   ***   \n"
            "  *****  \n"
            "  *****  \n"
            "   ***   \n",

            "   ***   \n"
            "  * * *  \n"
            "  ** **  \n"
            "   ***   \n",

            "   * *   \n"
            "  * * *  \n"
            "  *   *  \n"
            "   * *   \n",

            " *  *  * \n"
            "  *   *  \n"
            " *     * \n"
            "  *   *  \n",

            "*   *   *\n"
            "   *   * \n"
            " *     * \n"
            "   *   * \n"
        };

        for (int i = 0; i < 5; i++) {
            system(CLEAR);
            cout << RED;
            cout << frames[i] << RESET << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    }

    void AddMoney(float add)
    {
        float oldMoney = Money;
        float target = Money + add;

        for (int i = (int)oldMoney; i <= (int)target; i++) {
            system(CLEAR);
            cout << GREEN;
            cout << "+--------------------+" << endl;
            cout << "| Money: $" << i << "          |" << endl;
            cout << "+--------------------+" << RESET << endl;
            this_thread::sleep_for(chrono::milliseconds(10));
        }

        Money = target;
        cin.get();
    }

    void HatchDuck()
    {
        const char* frames[10] = {
            "   ***   \n"
            "  *****  \n"
            "  *****  \n"
            "   ***   \n",

            "   ***   \n"
            "  ** **  \n"
            "  *****  \n"
            "   ***   \n",

            "   * *   \n"
            "  * * *  \n"
            "  *****  \n"
            "   ***   \n",

            "   * *   \n"
            "  *   *  \n"
            "  ** **  \n"
            "   ***   \n",

            "   ^ ^   \n"
            "  (o_o)  \n"
            "  ** **  \n"
            "   ***   \n",

            "   ^ ^   \n"
            "  (o_o)  \n"
            "  /( )\\  \n"
            "   ***   \n",

            "   ^ ^   \n"
            "  (o_o)  \n"
            "  /( )\\  \n"
            "   | |   \n",

            "  \\^ ^/  \n"
            "  (o_o)  \n"
            "  /( )\\  \n"
            "   | |   \n",

            " \\ ^ ^ / \n"
            "( (o_o) )\n"
            "  /( )\\  \n"
            "   | |   \n",

            "   ^ ^   \n"
            "  (o_o)  \n"
            " <( ) ( )>\n"
            "   | |   \n"
        };

        for (int i = 0; i < 10; i++) {
            system(CLEAR);
            cout << YELLOW << frames[i] << RESET << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }

        cout << CYAN << "A duck is born! 🦆" << RESET << endl;
        cin.get();
    }

    void MoneyTree()
    {
        string input;

        cout << GREEN << "+--------------------+" << endl;
        cout << "| You found a Money Tree! |" << endl;
        cout << "+--------------------+" << RESET << endl;
        cin.get();
        cout << "It costs $300 to buy. Press Y to purchase, Q to cancel." << endl;
        getline(cin, input);

        if (input == "y" || input == "Y") {
            if (Money >= 300){
                Money -= 300;
                cout << "Purchase successful!" << endl;
                AddMoney(100.0);           
            }
            else{
                cout << "Not enough money!" << endl;
            }
        } else if(input == "q" || input == "Q") {
            cout << "Purchase canceled." << endl;
        }
    }

    void Nothing()
    {
        cout << "You got nothing." << endl;
    }

    void RandomEvent()
    {
        int i = rnd.randint(0, 3);
        switch(i)
        {
            case 0 : AddMoney(rnd.randfloat(200.0, 300.0)); break;
            case 1 : MoneyTree(); ShowMoney(); break;
            case 2 : HatchDuck(); ShowMoney(); break;
            case 3 : Nothing(); ShowMoney(); break;
        }
    }
};

int main()
{
    Egg egg;
    string input;

    while (true) {   
        system(CLEAR);
        cout << CYAN << "+====================+" << endl;
        cout << "|   Smash the Egg!   |" << endl;
        cout << "+====================+" << RESET << endl;

        egg.Appear();
        cout << "Press Enter to smash it (or type Q to quit)" << endl;

        getline(cin, input);
        if (input == "q" || input == "Q") {
            cout << "Bye bye~" << endl;
            break; 
        }

        egg.Smash();
        egg.RandomEvent();

        cout << "\nPress Enter to continue, or Q to quit." << endl;
        getline(cin, input);
        if (input == "q" || input == "Q") {
            cout << "Game Over!" << endl;
            break;
        }
    }

    return 0;
}
