#include "utils.h"


const string P1 = "X", P2 = "O";        // for player 1 and player 2 input

vector<string> Board = {"1","2","3","4","5","6","7","8","9"};   // for game board


int gamelogic() // logic that determines the result of the match
{   
    /*
    * this func determines the winner 
    * but this is a mess -_-
    * this is not ideal but gets the job done
    */

    // if player1 wins return 1
    if ((Board[0]== P1 && Board[1] == P1 && Board [2] == P1) || 
        (Board[3]== P1 && Board[4] == P1 && Board [5] == P1) || 
        (Board[6]== P1 && Board[7] == P1 && Board [8] == P1) ||

        (Board[0]== P1 && Board[3] == P1 && Board [6] == P1) || 
        (Board[1]== P1 && Board[4] == P1 && Board [7] == P1) || 
        (Board[2]== P1 && Board[5] == P1 && Board [8] == P1) ||
        
        (Board[0]== P1 && Board[4] == P1 && Board [8] == P1) || 
        (Board[2]== P1 && Board[4] == P1 && Board [6] == P1))
        return 1;


    // if player2 wins return 2
    else if ((Board[0]== P2 && Board[1] == P2 && Board [2] == P2) || 
        (Board[3]== P2 && Board[4] == P2 && Board [5] == P2) || 
        (Board[6]== P2 && Board[7] == P2 && Board [8] == P2) ||

        (Board[0]== P2 && Board[3] == P2 && Board [6] == P2) || 
        (Board[1]== P2 && Board[4] == P2 && Board [7] == P2) || 
        (Board[2]== P2 && Board[5] == P2 && Board [8] == P2) ||
        
        (Board[0]== P2 && Board[4] == P2 && Board [8] == P2) || 
        (Board[2]== P2 && Board[4] == P2 && Board [6] == P2))
        return 2;

    else 
        return 0;

}

void clear_display()        // for detecting operating system
{
    #ifdef _WIN32           // for detecting windows 32 or 64 bit system
        system("cls");
    #elif __linux__         // for detecting linux
        system("clear");
    #elif __MACH__          // for detecting mac
        system("clear");

    #endif

}

void gameboard()            // drawing the tic tac toe board
{
    
    cout << Board[0] << " | " << Board[1] << " | "<< Board[2] << endl;
    cout << "----------" << endl;
    cout << Board[3] << " | " << Board[4] << " | "<< Board[5] << endl;
    cout << "----------" << endl;
    cout << Board[6] << " | " << Board[7] << " | "<< Board[8] << endl;
    
}
void playgame()             // actual game play
{
    string player1, player2; 
    cout << "Enter Player 1 Name: ";
    cin >> player1;
    cout << "Enter Player 2 Name: ";
    cin >> player2;
    clear_display();

    int count = 1; /*
                    *this is for counting player turn,
                    *if odd then player 1 
                    *elseif even then player 2
                    */
    
    while(gamelogic()==0) // until winner is determined
    {  
        string player;  // to assing correct player
        string P;       // to assign correct player input
        
        if (count%2==1) // see the logic couple of lines above in a comment
        {
            player = player1;
            P = P1;
            count++;
        }

        else
        {
            player = player2;
            P = P2;
            count++;
        }

        int input;
        gameboard();
        cout << player << " Select your position : ";
        cin >> input;


        // to check duplicate or invalid inputs
        if (Board[input-1] == P1||Board[input-1] == P2||input < 1||input > 9)
        {
            cout << "Invalid Input. Please Try Again" << endl;
            count--;
            continue;
        }


        Board.erase(Board.begin()+input-1);
        Board.insert(Board.begin()+input-1, P);
        clear_display();

        if (count > 9) break; // to finish the game is no winner is found


    }

    gameboard();
    int result = gamelogic();       // to determine the result

    if (result == 1) 
        cout << player1 << " is the Winner" << endl;

    else if (result == 2) 
        cout << player2 << " is the Winner" << endl;

    else 
        cout << "It is a draw" << endl;

}