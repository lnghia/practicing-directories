#include <bits/stdc++.h>

using namespace std;

bool chessBoard[5][5];
int step=0;
int path[5][5];
int vertical[]={-2, -2, 2, 2, -1, -1, 1, 1};
int horizontal[]={1, -1, -1, 1, -2, 2, -2, 2};

// bool isDeadEnd(int i, int j){
//     bool firstWay=(i-2>=0 && j+1<=7 && !chessBoard[i-2][j+1]);
//     bool secondWay=(i-2>=0 && j-1>=0 && !chessBoard[i-2][j-1]);
//     bool thirdWay=(i)
// }

void output(){
    string suffix;

    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            suffix=(path[i][j]>=10)?"   ":"    ";

            cout << path[i][j] << suffix;
        }
        
        cout << '\n';
    }
}

void move(int i, int j){
    ++step;
    path[i][j]=step;
    chessBoard[i][j]=1;

    for(int it=0; it<8; ++it){
        if(step==25){
            output();

            exit(0);
        }

        int x=i+vertical[it];
        int y=j+horizontal[it];

        if(x>=0 && x<=4 && y>=0 && y<=4 && !chessBoard[x][y]){
            move(x, y);
        }
    }

    --step;
    path[i][j]=0;
    chessBoard[i][j]=0;
}

int main(){
    move(0, 0);

    output();

    return 0;
}