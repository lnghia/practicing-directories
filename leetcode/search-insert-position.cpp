#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int searchInsert(vector<int>& a, int target){
    int l=0, r=a.size()-1, mid, n=a.size();

    if(a[0]>target){
        return 0;
    }
    if(a[0]<target && a[1]>target ){
        return 1;
    }
    if(a[n-1]<target){
        return n;
    }
    if(a[n-1]>target && a[n-2]<target){
        return n-1;
    }

    while(l<=r){
        mid=l+(r-l)/2;
        if(mid>0 && a[mid-1]<target && a[mid]>target){
            return mid;
        }
        else if(mid<n-1 && a[mid+1]>target && a[mid]<target){
            return mid+1;
        }
        else if(a[mid]==target){
            return mid;
        }
        else if(a[mid]>target){
            r=mid;
        }
        else{
            l=mid;
        }
    }

    return 0;
}

int main(){
    fstream inp("input.txt");
    //vector<int> a;
    int target, tmp;

    while(inp >> target){
        vector<int> a;

        for(int i=0; i<target; ++i){
            inp >> tmp;
            a.push_back(tmp);
        }
        cout << searchInsert(a, target) << '\n';
    }
    inp.close();

    return 0;
}
