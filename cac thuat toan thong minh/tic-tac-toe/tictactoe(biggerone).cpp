#include <bits/stdc++.h>

using namespace std;

class GameBoard{
    vector<vector<char>> gb;
    pair<int, int> nextMove;
    int num=3;
    int m=3, n=4;
    int cnt=m*n;
    bool t=0;
    bool turn=1;
    string vertical="|", horizontal="";

public:

    GameBoard(){
        gb.resize(m, vector<char>(n, ' '));

        for(int i=0; i<n; ++i){
            horizontal+=" ---";
        }
        horizontal+='\n';
    }

    int utility(/*int x, int y*/){
        int count=0;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                count=0;
                if(j<=n-num){
                    for(int k=j; k<=j+(num-1); ++k){
                        if(gb[i][k]=='X'){
                            ++count;
                        }
                        else if(gb[i][k]=='O'){
                            --count;
                        }
                    }

                    if(count==num || count==(num*-1)){
                        return (count==num)?1:-1;
                    }
                }

                count=0;
                if(i<=m-num){
                    for(int k=i; k<=i+(num-1); ++k){
                        if(gb[k][j]=='X'){
                            ++count;
                        }
                        else if(gb[k][j]=='O'){
                            --count;
                        }
                    }
                    if(count==num || count==(num*-1)){
                        return (count==num)?1:-1;
                    }
                }

                count=0;
                if(i<=m-num && j<=n-num){
                    int t1=i, t2=j;

                    for(int k=0; k<num; ++k){
                        if(gb[t1][t2]=='X'){
                            ++count;
                        }
                        else if(gb[t1][t2]=='O'){
                            --count;
                        }
                        ++t1; ++t2;
                    }
                    if(count==num || count==(num*-1)){
                        return (count==num)?1:-1;
                    }
                }

                count=0;
                if(i<=m-num && j-(num-1)>=0){
                    int t1=i, t2=j;

                    for(int k=0; k<num; ++k){
                        if(gb[t1][t2]=='X'){
                            ++count;
                        }
                        else if(gb[t1][t2]=='O'){
                            --count;
                        }
                        ++t1; --t2;
                    }
                    if(count==num || count==(num*-1)){
                        return (count==num)?1:-1;
                    }
                }
            }
        }

        return (!cnt)?0:2;
    }

    int min_val(int x, int y, int prev=INT_MIN){
        int rs=utility(/*x, y*/);

        if(rs==-1 || rs==1 || !rs){
            return rs;
        }

        int v=INT_MAX, a, b, tmp;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(gb[i][j]==' '){
                    gb[i][j]='O';
                    --cnt;
                    tmp=max_val(i, j, v);
                    if(v>tmp){
                        v=tmp;
                        a=i;
                        b=j;
                    }
                    gb[i][j]=' ';
                    ++cnt;
                    if(prev>=tmp){
                        return tmp;
                    }
                }
            }
        }
        nextMove.first=a;
        nextMove.second=b;

        return v;
    }

    int max_val(int x, int y, int prev=INT_MAX){
        int rs=utility(/*x, y*/);

        if(rs==-1 || rs==1 || !rs){
            return rs;
        }

        int v=INT_MIN, a, b, tmp;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(gb[i][j]==' '){
                    gb[i][j]='X';
                    --cnt;
                    tmp=min_val(i, j, v);
                    if(v<tmp){
                        v=tmp;
                        a=i;
                        b=j;
                    }
                    gb[i][j]=' ';
                    ++cnt;
                    if(prev<=tmp){
                        return tmp;
                    }
                }
            }
        }
        nextMove.first=a;
        nextMove.second=b;

        return v;
    }

    void askPlayerForNextMove(){
        while(1){
            cout << "Enter your next move!\n";
            cout << "x: ";
            cin >> nextMove.first;
            cout << "y: ";
            cin >> nextMove.second;
            if(nextMove.first<0 || nextMove.first>m || nextMove.second<0 || nextMove.second>n){
                system("clear");
                draw();
                cout << "x, y must be in range [0, 2]\n";

                continue;
            }
            else if(gb[nextMove.first][nextMove.second]!=' '){
                system("clear");
                draw();
                cout << "Invalid move!\n";
                cout << "You may made a made move!\n";
            }
            else{
                break;
            }
        }

        gb[nextMove.first][nextMove.second]='X';
        --cnt;
    }

    void bot(){
        min_val(/*0, 0*/nextMove.first, nextMove.second);
        gb[nextMove.first][nextMove.second]='O';
        --cnt;
    }

    void draw(){
        system("clear");

        cout << horizontal;
        for(int i=0; i<m; ++i){
            cout << '|';
            for(int j=0; j<n; ++j){
                cout << ' ' << gb[i][j] << ' ' << '|';
            }
            cout << "\n";
            cout << horizontal;
        }
    }

    void gameLoop(){
        int util=0;

        cout << "Player is 'X'\n";

        while(1){
            draw();
            util=utility(/*nextMove.first, nextMove.second*/);
            if(util==1 || util==-1 || !util){
                break;
            }

            if(!turn){
                askPlayerForNextMove();
            }
            else{
                // if(!t){
                //     nextMove.first=1;
                //     nextMove.second=1;
                //     gb[nextMove.first][nextMove.second]='O';
                //     --cnt;
                //     t=!t;
                //     continue;
                // }
                bot();
            }
            turn=!turn;
        }
    }
};

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    GameBoard game;

    game.gameLoop();

    return 0;
}
