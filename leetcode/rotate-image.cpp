/*
 * =====================================================================================
 *
 *       Filename:  rotate-image.cpp
 *
 *    Description:  leetcode-rotate-image
 *
 *        Version:  1.0
 *        Created:  02/27/20 15:46:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix){
    pair<int, int> tL, tR, bL, bR, oTL, oTR, oBL, oBR;
    int m=matrix.size(), n=(m)?matrix[0].size():0, i=1;

    if(!n){
        return;
    }

    oTL=tL={0, 0};
    oTR=tR={0, n-1};
    oBL=bL={m-1, 0};
    oBR=bR={m-1, n-1};
    
    while(tL.first!=tR.first || tL.second!=tR.second){
        int tmp, tmp2, tmp3;
        
        tmp=matrix[tR.first][tR.second];
        tmp2=matrix[bR.first][bR.second];
        tmp3=matrix[bL.first][bL.second];
        matrix[tR.first][tR.second]=matrix[tL.first][tL.second];
        matrix[bR.first][bR.second]=tmp;
        matrix[bL.first][bL.second]=tmp2;
        matrix[tL.first][tL.second]=tmp3;

        if(tL.second+1==tR.second && tL.first==tR.first){
            return;
        }

        tL.second+=1;
        tR.first+=1; 
        bR.second-=1;
        bL.first-=1;

        if(tL.second==n-i){
            tL.first=oTL.first+1; tL.second=oTL.second+1;
            ++oTL.first; ++oTL.second;
            tR.first=oTR.first+1; tR.second=oTR.second-1;
            ++oTR.first; --oTR.second;
            bR.first=oBR.first-1; bR.second=oBR.second-1;
            --oBR.first; --oBR.second;
            bL.first=oBL.first-1; bL.second=oBL.second+1;
            --oBL.first; ++oBL.second;
            ++i;
        }
    }
}

int main(){
    int m, n;
    int tmp;
    ifstream in("input.txt");

    while(in >> m >> n){
        vector<vector<int>> ma, sampleAns;
        bool isTrue=1;

        ma.resize(m);
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                in >> tmp;
                ma[i].push_back(tmp);
            }
        }
        sampleAns.resize(m);
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                in >> tmp;
                sampleAns[i].push_back(tmp);
            }
        }

        rotate(ma);
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(ma[i][j]!=sampleAns[i][j]){
                    isTrue=0;
                    cout << "\033[1;31m" << ma[i][j] << "\033[0m" << ' ';
                }
                else{
                    cout << ma[i][j] << ' '; 
                }
            }
            cout << '\n';
        }
        if(!isTrue)
            cout << "\033[1;31mFailed!\033[0m\n" << "\n\n";
        else
            cout << "\033[1;32mPassed!\033[0m\n" << "\n\n";
    }
    
    return 0;
}

