#include <bits/stdc++.h>

using namespace std;

class GameBoard{
    vector<vector<char>> gb;
    pair<int, int> nextMove={-1, -1};
    int num=3;
    int m=3, n=3;
    int cnt=m*n;
    bool t=0;
    bool turn=0;
    string vertical="|", horizontal="";
    unordered_map<char, int> score={{'X', 1}, {'O', -1}, {' ', 0}};
    queue<pair<int, int>> winMoves;
    stack<pair<int, int>> _winMoves;

public:

    GameBoard(){
        gb.assign(m, vector<char>(n, ' '));

        for(int i=0; i<n; ++i){
            horizontal+=" ---";
        }
        horizontal+='\n';
    }

    int utility(char winner){
        return score[winner];
    }

    pair<bool, char> check(int x, int y, int stepX, int stepY){
        int count=0;
        int px=x, py=y;
        char latestMove=gb[x][y];

        queue<pair<int, int>> tmp;
        stack<pair<int, int>> _tmp;

        for(int i=0; i<num; ++i){
            if(px>=m || py>=n || px<0 || py<0 || gb[px][py]!=latestMove){
                break;
            }
            ++count;
            tmp.push({px, py});
            px+=stepX;
            py+=stepY;
        }

        if(count==num){
            winMoves=tmp;
            _winMoves=_tmp;

            return {1, latestMove};
        } 

        for(int i=0; i<num-1; ++i){
            x-=stepX;
            y-=stepY;
            if(x>=m || y>=n || x<0 || y<0 || gb[x][y]!=latestMove){
                break;
            }
            ++count;
            _tmp.push({x, y});
        }

        if(count==num){
            winMoves=tmp;
            _winMoves=_tmp;

            return {1, latestMove};
        } 
        
        return !cnt?make_pair(1, ' '):make_pair(0, ' ');
    }

    pair<bool, char> isTerminated(int x, int y){
        if(x==-1){
            return {0, ' '};
        }

        pair<bool, char> rs1=check(x, y, 1, 0);
        pair<bool, char> rs2=check(x, y, 0, 1);
        pair<bool, char> rs3=check(x, y, 1, 1);
        pair<bool, char> rs4=check(x, y, 1, -1);

        if(rs1.first) return rs1;
        if(rs2.first) return rs2;
        if(rs3.first) return rs3;
        if(rs4.first) return rs4;
        
        return {0, ' '};
    }

    int min_val(int x, int y, int prev=INT_MIN){
        pair<bool, char> rs=isTerminated(x, y);

        if(rs.first){
            return utility(rs.second);
        }

        int v=INT_MAX, a, b, tmp;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(gb[i][j]==' '){
                    gb[i][j]='O';
                    nextMove.first=i;
                    nextMove.second=j;
                    --cnt;
                    tmp=max_val(i, j, v);
                    if(v>tmp){
                        v=tmp;
                        a=i;
                        b=j;
                    }
                    gb[i][j]=' ';
                    nextMove.first=x;
                    nextMove.second=y;
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
        pair<bool, char> rs=isTerminated(x, y);

        if(rs.first){
            return utility(rs.second);
        }

        int v=INT_MIN, a, b, tmp;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(gb[i][j]==' '){
                    gb[i][j]='X';
                    nextMove.first=i;
                    nextMove.second=j;
                    --cnt;
                    tmp=min_val(i, j, v);
                    if(v<tmp){
                        v=tmp;
                        a=i;
                        b=j;
                    }
                    gb[i][j]=' ';
                    nextMove.first=x;
                    nextMove.second=y;
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
            cout << "You are X !\n";
            cout << "Note: enter two integers indicating coordinates of the cell you want to put your move in. (0 <= x, y <= 2) !\n";
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

    void draw(bool isOver=0){
        system("clear");

        vector<pair<int, int>> temp;
        int ind=0;
        if(isOver){
            while(!_winMoves.empty()){
                temp.push_back(_winMoves.top());
                _winMoves.pop();
            }
            while(!winMoves.empty()){
                temp.push_back(winMoves.front());
                winMoves.pop();
            }
        }

        cout << horizontal;
        for(int i=0; i<m; ++i){
            cout << '|';
            for(int j=0; j<n; ++j){
                if(isOver && i==temp[ind].first && j==temp[ind].second){
                    cout << "\033[1;32m " <<  gb[i][j] << "\033[0m |";
                    ++ind;
                }
                else{
                    cout << ' ' << gb[i][j] << ' ' << '|';
                }
            }
            cout << "\n";
            cout << horizontal;
        }
    }

    void gameLoop(){
        pair<bool, char> rs;

        cout << "Player is 'X'\n";

        while(1){
            draw();

            rs=isTerminated(nextMove.first, nextMove.second);
            if(rs.first){
                draw(rs.second!=' ');

                break;
            }

            if(!turn){
                askPlayerForNextMove();
            }
            else{
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
