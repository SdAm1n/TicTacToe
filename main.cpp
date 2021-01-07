#include "utils.h"

int main ()
{
    cout << "Welcome to Tic Tac Toe"<< endl;
    gameboard();
    
    string choice;
    while(1)
    {   
        // This is the Game Menu
        cout << "Game Menu" << endl;
        cout << "1. Play Tic Tac Toe" << endl;
        cout << "2. Quit Tic Tac Toe" << endl;
        cout << "Enter 1 or 2 : ";

        cin >> choice;
        // Play the Game
        if(choice == "1")
        {
            clear_display();
            cout << "Starting Tic Tac Toe" << endl;
            gameboard();
            playgame();
        }
                

        // Quit the Game
        else if (choice == "2")
        {
            cout << "Quiting Tic Tac Toe" << endl;
            break;
        }
                
            
        // To tackle input other than 1 and 2
        else 
        {
            cout << "Please Choose between 1 & 2" << endl;
        }

    }


}


