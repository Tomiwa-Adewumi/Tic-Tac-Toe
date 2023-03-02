#include <iostream>
#include <string>
using namespace std;

// declare count unction that accepts game board as 2d array
int Count(char board[3][3])
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '*')
                counter += 1;
        }
    }
    return counter;
}

int main()
{
    char board[3][3];   // 2d array
    int row, column;    // for user input
    bool end = false;   // to end the while loop
    string winner = ""; // declare winner

    // initialize each element to use asterick
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '*';
        }
    }

    // display starting board
    cout << "  BOARD\n\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j];
        }
        cout << "\n";
    }

    // a while loop that will last as long as end variable is false
    while (!end)
    {

        cout << "\n1st player turn\n";
        cout << "Enter the number of a row: "; // prompt for row
        cin >> row;
        // verify input
        while (row != 1 && row != 2 && row != 3)
        {
            cout << "Wrong input\n";
            cout << "Enter the number of a row: ";
            cin >> row;
        }
        cout << "Enter number of a column: ";
        cin >> column;
        while (column != 1 && column != 2 && column != 3)
        {
            cout << " Wrong input\n";
            cout << "Enter number of a column: ";
            cin >> column;
        }
        if (board[row - 1][column - 1] == '*')
        {
            board[row - 1][column - 1] = 'X';
            cout << " BOARD\n\n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << " " << board[i][j];
                }
                cout << "\n";
            }
        }
        else if (Count(board) == 0)
        {
            cout << "\nIt is a tie";
            end = true;
        }
        else
        {
            cout << "That was a wrong move\n";
            continue;
        }

        for (int i = 0; i < 3; i++)
        {
            // to check columns
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            {
                winner += "First player won\n";
                end = true;
                break;
            }
            // check rows
            else if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
            {
                winner += "First player won\n";
                end = true;
                break;
            }
        }
        // check main diagonal
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        {
            winner = +"first player won\n";
            end = true;
        }
        // check secondary diagonal
        else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        {
            winner += "First player won\n";
            end = true;
        }
        if (Count(board) == 0)
        {
            cout << "It is a tie!\n";
            end = true;
        }
        if (end)
            break;

        // repeat for second player
        cout << "\n2nd player turn\n";
        cout << "Enter the number od a row: "; // prompt for row
        cin >> row;
        // verify input
        while (row != 1 && row != 2 && row != 3)
        {
            cout << "Wrong input!\n";
            cout << "Enter a row number: ";
            cin >> row;
        }
        // prompt for column
        cout << "Enter the number of a column: ";
        cin >> column;
        // verify input
        while (column != 1 && column != 2 && column != 3)
        {
            cout << "Wrong Input!\n";
            cout << "Enter the number of a column: ";
            cin >> column;
        }
        if (board[row - 1][column - 1] == '*')
        {
            board[row - 1][column - 1] = 'O';
            cout << " BOARD\n\n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << " " << board[i][j];
                }
                cout << "\n";
            }
        }
        else if (Count(board) == 0)
        {
            cout << "\nIts a tie!\n";
            end = true;
        }
        else
        {
            cout << "Wrong move!" << endl;
            continue;
        }

        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            {
                winner += "Second player won the game";
                end = true;
                break;
            }
            else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
            {
                winner += "Second player won the game";
                end = true;
                break;
            }
        }
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        {
            winner += "Second player won the game";
            end = true;
        }
        else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        {
            winner += "Second player won the game";
            end = true;
        }

        if (Count(board) == 0)
        {
            cout << "It's a tie!\n";
            end = true;
        }
    }
    // we have to print the winner outside the loop
    cout << winner;

    return 0;
}
