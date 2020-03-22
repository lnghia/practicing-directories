#include <bits/stdc++.h>

using namespace std;

// Complete the gridChallenge function below.
string gridChallenge(vector<string> grid) {
    for(int i=0; i<grid.size(); ++i){
        for(int j=0; j<grid.size()-1; ++j){
            for(int k=j+1; k<grid.size(); ++k){
                if(grid[i][k]<grid[i][j]){
                    string t;
                    t=grid[i][j];
                    grid[i][j]=grid[i][k];
                    grid[i][k]=grid[i][j];
                }
            }
        }
    }
    for(int i=0; i<grid.size(); ++i){
        for(int j=0; j<grid.size()-1; ++j){
            if(grid[j][i]>grid[j+1][i]){
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
