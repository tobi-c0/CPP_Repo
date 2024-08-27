#include "src\\ToyRobot.h"

using namespace std;

int main()
{
    ToyRobot myRobot;
    string console_input;

    while (getline(cin, console_input)) // Takes the user input from the console
    {
        myRobot.ProcessCommandLineInput(console_input);
        if (!myRobot.isKeepAlive())
        {
            break;
        }
    }
}