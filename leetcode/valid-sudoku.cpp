#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<vector<bool>> cache(10); // This is for checking duplicate numbers in columns.

    for (int i = 0; i < 10; ++i)
    {
        cache[i].resize(10, 0);
    }

    for (int i = 0; i < 9; ++i)
    {
        bool doesExist[10] = {}; // This is for checking duplicate numbers in each row.

        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                if (doesExist[board[i][j] - 48] || cache[board[i][j] - 48][j])
                {
                    return 0;
                }
                doesExist[board[i][j] - 48] = 1;
                cache[board[i][j] - 48][j] = 1;
            }
            if (i == 2 || i == 5 || i == 8)
            {
                if (j == 2 || j == 5 || j == 8)
                {
                    bool tmp[10] = {}; // This is for checking duplicate numbers in a 3x3 block.

                    for (int it = i; it >= i - 2; --it)
                    {
                        for (int jt = j; jt >= j - 2; --jt)
                        {
                            if (board[it][jt] == '.')
                            {
                                continue;
                            }
                            if (tmp[board[it][jt] - 48])
                            {
                                return 0;
                            }
                            tmp[board[it][jt] - 48] = 1;
                        }
                    }
                }
            }
        }
    }

    return 1;
}