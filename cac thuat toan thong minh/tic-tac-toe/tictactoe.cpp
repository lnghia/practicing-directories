//    |   |
// --- --- ---
//    |   |
// --- --- ---
//    |   |

#include <bits/stdc++.h>

using namespace std;

class GameBoard
{
    vector<vector<char>> gb;
    vector<int> cache;
    pair<int, int> nextMove;
    int count = 9;
    bool turn = 0;
    string vertical = "|", horizontal = "--- --- ---\n";

public:
    GameBoard()
    {
        gb.resize(3, vector<char>(3, ' '));
        cache.resize(6, 0);
    }

    int utility(int x, int y)
    {
        if (cache[x] == 3 || cache[y + 3] == 3 ||
            (gb[0][0] == 'X' && gb[1][1] == 'X' && gb[2][2] == 'X') ||
            (gb[0][2] == 'X' && gb[1][1] == 'X' && gb[2][0] == 'X'))
        {

            return 1;
        }
        if (cache[x] == -3 || cache[y + 3] == -3 ||
            (gb[0][0] == 'O' && gb[1][1] == 'O' && gb[2][2] == 'O') ||
            (gb[0][2] == 'O' && gb[1][1] == 'O' && gb[2][0] == 'O'))
        {

            return -1;
        }

        return 0;
    }

    int min_val(int x, int y, int prev = INT_MIN)
    {
        if (isTerminated())
        {
            return utility(x, y);
        }

        int v = INT_MAX, a, b, tmp;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (gb[i][j] == ' ')
                {
                    gb[i][j] = 'O';
                    --cache[i];
                    --cache[j + 3];
                    --count;
                    tmp = max_val(i, j, v);
                    if (v > tmp)
                    {
                        v = tmp;
                        a = i;
                        b = j;
                    }
                    gb[i][j] = ' ';
                    ++cache[i];
                    ++cache[j + 3];
                    ++count;
                    if (prev >= tmp)
                    {
                        return tmp;
                    }
                }
            }
        }
        nextMove.first = a;
        nextMove.second = b;

        return v;
    }

    int max_val(int x, int y, int prev = INT_MAX)
    {
        if (isTerminated())
        {
            return utility(x, y);
        }

        int v = INT_MIN, a, b, tmp;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (gb[i][j] == ' ')
                {
                    gb[i][j] = 'X';
                    ++cache[i];
                    ++cache[j + 3];
                    --count;
                    tmp = min_val(i, j, v);
                    if (v < tmp)
                    {
                        v = tmp;
                        a = i;
                        b = j;
                    }
                    gb[i][j] = ' ';
                    --cache[i];
                    --cache[j + 3];
                    ++count;
                    if (prev <= tmp)
                    {
                        return tmp;
                    }
                }
            }
        }
        nextMove.first = a;
        nextMove.second = b;

        return v;
    }

    bool isTerminated()
    {
        for (auto &i : cache)
        {
            if (i == 3 || i == -3)
            {
                return 1;
            }
        }

        if ((gb[0][0] == 'X' && gb[1][1] == 'X' && gb[2][2] == 'X') ||
            (gb[0][2] == 'X' && gb[1][1] == 'X' && gb[2][0] == 'X') ||
            (gb[0][0] == 'O' && gb[1][1] == 'O' && gb[2][2] == 'O') ||
            (gb[0][2] == 'O' && gb[1][1] == 'O' && gb[2][0] == 'O'))
        {
            return 1;
        }

        return !count;
    }

    void askPlayerForNextMove()
    {
        while (1)
        {
            cout << "Enter your next move!\n";
            cout << "x: ";
            cin >> nextMove.first;
            cout << "y: ";
            cin >> nextMove.second;
            if (nextMove.first < 0 || nextMove.first > 2 || nextMove.second < 0 || nextMove.second > 2)
            {
                system("clear");
                draw();
                cout << "x, y must be in range [0, 2]";
            }
            else if (gb[nextMove.first][nextMove.second] != ' ')
            {
                system("clear");
                draw();
                cout << "Invalid move!\n";
                cout << "You may made a made move!\n";
            }
            else
            {
                break;
            }
        }

        gb[nextMove.first][nextMove.second] = 'X';
        ++cache[nextMove.first];
        ++cache[nextMove.second + 3];
        --count;
    }

    void bot()
    {
        min_val(0, 0);
        gb[nextMove.first][nextMove.second] = 'O';
        --cache[nextMove.first];
        --cache[nextMove.second + 3];
        --count;
    }

    void draw()
    {
        system("clear");
        for (int i = 0; i < 3; ++i)
        {
            cout << ' ' << gb[i][0] << ' ' << vertical << ' ' << gb[i][1] << ' ' << vertical << ' ' << gb[i][2] << '\n';
            if (i != 2)
            {
                cout << horizontal;
            }
        }
    }

    void gameLoop()
    {
        int util = 0;

        cout << "Player is 'X'\n";

        while (1)
        {
            draw();
            if (isTerminated())
            {
                break;
            }
            if (!turn)
            {
                askPlayerForNextMove();
            }
            else
            {
                bot();
            }
            turn = !turn;
        }
    }
};

int main()
{
    GameBoard game;

    game.gameLoop();

    return 0;
}
