#include <iostream>
#include <vector>
using namespace std;

void draw_board(const vector< vector<char> >& vec)
{
    cout << "    0   1   2  \n";
    cout << "  -------------\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << i << " " ;
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout <<"| "<<vec[i][j] <<" ";
        }
        cout << "|";
        cout << '\n';
        cout << "  ------------- \n";
    }
}

void enter(unsigned int row, unsigned int column, char ch, vector <vector<char> >& vec)
{
    vec[row][column] = ch;
}

bool check(const vector< vector<char> >& vec)
{

    if ((vec[0][0] == 'X' && vec[1][1] == 'X' && vec[2][2] == 'X')
        || (vec[0][2] == 'X' && vec[1][1] == 'X' && vec[2][0] == 'X'))
        {
            cout << "Player X won this game\n";
            return true;
        }
    else if ((vec[0][0] == 'O' && vec[1][1] == 'O' && vec[2][2] == 'O')
             || (vec[0][2] == 'O' && vec[1][1] == 'O' && vec[2][0] == 'O'))
             {
                cout << "Player O won this game\n";
                return true;
             }


    for (int i = 0; i < vec.size(); i++)
    {
        if ((vec[i][0] == 'X' && vec[i][1] == 'X' && vec[i][2] == 'X')
              || (vec[0][i] == 'X' && vec[1][i] == 'X' && vec[2][i] == 'X'))
              {
                  cout << "Player X won this game\n";
                  return true;
              }
        else if((vec[i][0] == 'O' && vec[i][1] == 'O' && vec[i][2] == 'O')
              || (vec[0][i] == 'O' && vec[1][i] == 'O' && vec[2][i] == 'O'))
              {
                  cout << "Player O won this game\n";
                  return true;
              }
    }
    return false;
}

void start(vector< vector<char> >& vec)
{
    unsigned int row, column;
    int res = 0;
    char ch;

    for (int i = 0; i < 9;)
    {
        if (i == 0 || i%2 == 0)
        {
            ch = 'X';
            cout << "Chance to enter X\n";
        }
        else
        {
            ch = 'O';
            cout << "Chance to enter O\n";
        }
        cout << "Enter row number ";
        cin >> row;
        cout << "Enter columnumn number ";
        cin >> column;
        if (row < 3 && column < 3)
        {
            if (vec[row][column] == ' ' || vec[row][column] == ' ')
            {
                enter(row, column, ch, vec);
                draw_board(vec);
                if ( i >= 2)
                {
                    res = check(vec);
                    if (res == 1)
                    {
                      break;
                    }
                }
                i++;
              }
              else
              {
                  cerr << "This position already contains a character\n";
              }
        }
        else
        {
            cerr << "Enter row number and columnumn number between 0 to 2\n";
        }

    }
    if (res == 0)
    {
        cout << "This game draws\n";
    }
}

int main()
{
    vector< vector<char> > board(3, vector<char>(3, ' '));
    draw_board(board);
    start(board);
}
