#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define n2 9
#include <cstdlib>
using namespace std;

void changeColor(int desiredColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void print(int mat[n2][n2])
{

    cout << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << "\t\t\t\t";
        for (int j = 0; j < n2; j++)
        {
            if (mat[i][j] == 0)
            {
                changeColor(2);
            }
            cout << mat[i][j] << " ";
            changeColor(7);
            if ((j + 1) % 3 == 0 && (j + 1) != 9)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && (i + 1) != 9)
        {
            cout << "\t\t\t\t-----------------------" << endl;
        }
    }
}

bool isSafe(int arr[n2][n2], int row, int column, int number)
{

    // check first if that number is in the row

    for (int i = 0; i < n2; i++)
    {
        if (arr[i][column] == number)
        {
            return false;
        }
    }

    // check second if that number is in the column

    for (int i = 0; i < n2; i++)
    {
        if (arr[row][i] == number)
        {
            return false;
        }
    }

    // Now check that the number is unique in it's own 3x3 matrix

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int r = row - row % 3;
            int c = column - column % 3;
            if (arr[i + r][j + c] == number)
            {
                return false;
            }
        }
    }

    return true;
}

bool findemptyplace(int arr[n2][n2], int &row, int &column)
{
    for (row = 0; row < n2; row++)
    {
        for (column = 0; column < n2; column++)
        {
            if (arr[row][column] == 0)
            {
                return true;
            }
        }
    }
    return false;
}
bool ifempty(int arr[n2][n2])
{
    for (int row = 0; row < n2; row++)
    {
        for (int column = 0; column < n2; column++)
        {
            if (arr[row][column] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool SolveSudoko(int arr[n2][n2], int row, int column)
{
    if (findemptyplace(arr, row, column) == false)
    {
        return true;
    }

    for (int number = 1; number < 10; number++)
    {
        if (isSafe(arr, row, column, number))
        {
            arr[row][column] = number;

            if (SolveSudoko(arr, row, column))
            {
                return true;
            }

            arr[row][column] = 0;
        }
    }
    return false;
}

int randomnumgen()
{
    int x = 1 + (rand() % 9);
    return x;
    x = 0;
}

int randomrow()
{
    int x = rand() % 9;
    return x;
    x = 0;
}

void removevaluesfrommatrix(int mat[n2][n2], int k)
{
    int count = 0;

    while (count != k)
    {
        int x, y;
        x = randomrow();
        y = randomrow();
        if (mat[x][y] == 0)
        {
            continue;
        }
        else
        {
            mat[x][y] = 0;
            count++;
        }
    }
}

void matrixgen(int sud[n2][n2], int sol[n2][n2], int x)
{

    while (1)
    {

        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                sud[i][j] = 0;
            }
        }
        srand(time(0));
        for (int i = 0; i < 5; i++)
        {
            sud[randomrow()][randomrow()] = randomnumgen();
        }
        if (SolveSudoko(sud, 0, 0))
        {
            break;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            sol[i][j] = sud[i][j];
        }
    }

    //    print(sud);
    //    cout << endl;
    //    cout << "\n"
    //         << endl;
    removevaluesfrommatrix(sud, x);
    // print(sud);
}

void takeinput(int sud[n2][n2], int sol[n2][n2])
{
    bool flag = 0;
    int x, y;
    int number, mistakes = 0;
    print(sud);
    while (1)
    {
        if (ifempty(sud))
        {
            cout << "Mistakes: " << mistakes << "/3" << endl;
            cout << "Enter Row And Column where you want to Enter the value: ";
            cin >> x >> y;
            if (x == -1 || y == -1)
            {
                cout << "Thanks for Exiting" << endl;
                break;
            }
            if (x < 0 || x > 9 || y < 0 || y > 9)
            {
                cout << "You have entered wrong row/column number please enter again" << endl;
                continue;
            }
            if (sud[x][y] != 0)
            {
                cout << "There is already a number that is in that row and column number" << endl;
                continue;
            }
            while (1)
            {
                cout << "Enter the number you want to enter: ";
                cin >> number;
                if (number >= 1 && number <= 9)
                {
                    if (number != sol[x][y])
                    {
                        cout << "You have entered a wrong number!" << endl;
                        mistakes++;
                        system("PAUSE");
                        if (mistakes == 3)
                        {
                            flag = 1;
                            break;
                        }
                        system("CLS");
                        print(sud);
                        cout << "Mistakes: " << mistakes << "/3" << endl;
                        continue;
                    }
                    else
                    {
                        sud[x][y] = number;
                        break;
                    }
                }
                else
                {
                    cout << "Please enter a number in range 1-9" << endl;
                    continue;
                }
            }
            system("CLS");
            print(sud);
            if (flag == 1)
            {
                break;
            }
            continue;
        }
        break;
    }

    if (flag == 1)
    {
        cout << "Sorry You have lost the game!" << endl;
    }
    else if (flag == 0)
    {
        cout << "You have won the game!" << endl;
    }
}



void start_program(){
	   int x;
    int sud[n2][n2];
    int sol[n2][n2];

    while (1)
    {
        system("CLS");
        cout << "\t\t\t\tWelcome to Sudoku" << endl;
        cout << "Please chose your difficulty level" << endl;
        cout << "1-Very Easy\n2-Easy\n3-Medium\n4-Hard\n5-Exit" << endl;
        cout << "Please Enter your choice: ";
        cin >> x;
        if (x < 1 || x > 5)
        {
            cout << "Please Enter a valid choice" << endl;
            system("Pause");
            continue;
        }
        else if(x==5){
        	return;
		}
        else
        {
            break;
        }
    }
    system("CLS");
    if (x == 1)
    {
        x = 10;
    }
    else if (x == 2)
    {
        x = 31;
    }
    else if (x == 3)
    {
        x = 38;
    }
    else if (x == 4)
    {
        x = 43;
    }
    matrixgen(sud, sol, x);

    takeinput(sud, sol);

    cout << "\nPress 1 to Play again or press any other key to exit: ";
    int key;
    cin >> key;
    if (key == 1)
    {
        start_program();
    }
    else{
		return;
	}
	
	
}
//int main()
//{
//    start_program();
//    
//}
