#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(){
    string a, temp="";
    int tmp;
    ofstream out("input.txt");

    cin >> a >> tmp;
    for(char c : a){
        if(c==','){
            out << temp << '\n';
            temp="";

            continue;
        }
        temp+=c;
    }

    return 0;
}