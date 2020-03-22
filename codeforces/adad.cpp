#include <bits/stdc++.h>
#include <string.h>

using namespace std;

void convert(int a, int t, string &ans){
    if(!a) return;
    char temp[]={'A', 'B', 'C', 'D', 'E', 'F'};
    char temp1[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    convert(a/t, t, ans);
    int tmp=a%t;
    if(tmp>=10){
        ans+=temp[tmp-10];
    }
    else{
        ans+=temp1[tmp];
    }
    //a/=t;
    //convert(a, t, ans);
}

int main(int argc, char const *argv[])
{
	/* code */
	string ans;

	convert(4, 2, ans);
	cout << ans;

	return 0;
}