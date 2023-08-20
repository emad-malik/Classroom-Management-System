
#include "typeEffect.h"


//a function to add a type-writing effect in our program
//adds a delay to the printing of characters

void typeEffect(string message, int delay)
{
    for (int i = 0; i < message.length(); i++)
    {
        cout << message[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}