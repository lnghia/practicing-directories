#include<bits/stdc++.h>

using namespace std;

class phanso{
public:
    int tu, mau;
public:
    void rutgon(){
        int tmp =__gcd(tu,mau);
        tu /= tmp;
        mau /= tmp;
    }
    phanso operator+(phanso ps2) const
    {
        phanso tmp;
        tmp.tu=this->tu*ps2.mau+ this->mau*ps2.tu;
        tmp.mau=this->mau*ps2.mau;
        tmp.rutgon();
        ps2.mau = 1;
        return tmp;
    }
    bool operator ==(const phanso &p) const{
        return (tu*1.0/mau==p.tu*1.0/p.mau);
    }
};

int main(){
    phanso a, b, c;
    cin >> a.tu >> a.mau;
    cin >> b.tu >> b.mau;
    c = a + b;
    cout << a.mau;
    return 0;
}
