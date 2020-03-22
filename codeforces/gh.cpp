
#include<bits/stdc++.h>
#include<string>

using namespace std;

int rs;
int tmp;

void t2(int a){
    cout << a << ' ';
}

void t3(){

}

void t(int a, vector<int> &temp){
    (tmp%a==0)?t2(a):t3();
    --a;
    (a==0)? t3() : t(a, temp); 

    //(rs=1, a==1)||(t1(a, temp, tmp), t(--a, temp));
}

int main(){
    vector<int> s;
    cin >> tmp;
    t(tmp, s);
    //cout << 1;

    return 0;
}
