#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <iomanip>

using namespace std;

// Prototypes
void print_board(std::array<std::array<std ::string, 3>, 3> &board);
array<int, 2> get_move();
std::array<std::array<std ::string, 3>, 3> make_move(std::array<std::array<std ::string, 3>, 3> board, array<int, 2> &move, string &&player);
bool is_valid_move(array<int, 2> &move);
string check_winner(std::array<std::array<std ::string, 3>, 3> board);

int main()
{
    std::array<std::array<std ::string, 3>, 3> board{
        std::array<std::string, 3>{"None", "None", "None"},
        std::array<std::string, 3>{"None", "None", "None"},
        std::array<std::string, 3>{"None", "None", "None"}};
    array<int, 2> move;
    int i = 0;
    string winner{};
    bool flag = false;
    while (i != 4)
    {
        move = get_move();
        if (is_valid_move(move))
            board = make_move(board, move, "X");
        print_board(board);
        if (check_winner(board) == string{"X"})
        {
            cout << "Congratulations! Player 'X' is winner!!!" << endl;
            flag = true;
            break;
        }
        move = get_move();
        if (is_valid_move(move))
            board = make_move(board, move, "O");
        print_board(board);
        if (check_winner(board) == string{"O"})
        {
            cout << "Congratulations! Player 'O' is winner!!!" << endl;
            flag = true;
            break;
        }
        i++;
    }
    if (!flag)
    {
        move = get_move();
        if (is_valid_move(move))
            board = make_move(board, move, "X");
        print_board(board);
        cout << "Game over! Draw!!!" << endl;
    }
    return 0;
}

// Functions

void print_board(std::array<std::array<std ::string, 3>, 3> &board)
{
    std::cout << std::setw(4) << right << "0"
              << std::setw(4) << right << "1"
              << std::setw(4) << right << "2" << endl
              << "  -----------" << std::endl;

    for (size_t i = 0; i < 3; i++)
    {
        cout << i << " |";
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] == std::string{"None"})
            {
                if (j != 2)
                    cout << setw(4) << left << " ";
                else
                    cout << " ";
            }
            else
            {
                if (j != 2)
                    cout << setw(4) << left << board[i][j];
                else
                    cout << board[i][j];
            }
        }
        if (i != 2)
            cout << "|" << endl
                 << endl;
        else
            cout << "|" << endl;
    }
    cout << "  -----------" << std::endl;
}

array<int, 2> get_move()
{
    array<int, 2> move;
    cout << "What is your move's X co-ordinate?: ";
    cin >> move[0];
    cout << "What is your move's Y co-ordinate?: ";
    cin >> move[1];
    return move;
}

std::array<std::array<std ::string, 3>, 3> make_move(std::array<std::array<std ::string, 3>, 3> board, array<int, 2> &move, string &&player)
{
    if (board[move[1]][move[0]] == string{"None"})
        board[move[1]][move[0]] = player;
    else
        cout << "Can't make move (" << move[0] << "," << move[1] << "), square already taken!" << endl;
    return board;
}

bool is_valid_move(array<int, 2> &move)
{
    return (move[0] >= 0 && move[1] >= 0 && move[0] <= 2 && move[1] <= 2);
}

string check_winner(std::array<std::array<std ::string, 3>, 3> board)
{
    array<string, 3> X{"X", "X", "X"}, O{"O", "O", "O"};
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == X)
            return string{"X"};
        else if (board[i] == O)
            return string{"O"};
    }
    if (board[0][0] == string{"X"} && board[1][1] == string{"X"} && board[2][2] == string{"X"})
        return string{"X"};
    else if (board[2][0] == string{"X"} && board[1][1] == string{"X"} && board[0][2] == string{"X"})
        return string{"X"};
    else if (board[0][0] == string{"O"} && board[1][1] == string{"O"} && board[2][2] == string{"O"})
        return string{"O"};
    else if (board[2][0] == string{"O"} && board[1][1] == string{"O"} && board[0][2] == string{"O"})
        return string{"O"};
    else if (board[0][0] == string{"X"} && board[1][0] == string{"X"} && board[2][0] == string{"X"})
        return string{"X"};
    else if (board[0][1] == string{"X"} && board[1][1] == string{"X"} && board[2][1] == string{"X"})
        return string{"X"};
    else if (board[0][2] == string{"X"} && board[1][2] == string{"X"} && board[2][2] == string{"X"})
        return string{"X"};
    else if (board[0][0] == string{"O"} && board[1][0] == string{"O"} && board[2][0] == string{"O"})
        return string{"O"};
    else if (board[0][1] == string{"O"} && board[1][1] == string{"O"} && board[2][1] == string{"O"})
        return string{"O"};
    else if (board[0][2] == string{"O"} && board[1][2] == string{"O"} && board[2][2] == string{"O"})
        return string{"O"};

    return string{"None"};
}