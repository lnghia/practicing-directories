#include<bits/stdc++.h>
#include<string>
#include<vector>

using namespace std;

int getFormatDatetime(string datetime)
{
    //cout << datetime[datetime.length()] << endl;
    if (datetime[datetime.length() - 1] == 'A')
    {
        return 0;
    }
    if (datetime[datetime.length() - 1] == 'H')
    {
        return 1;
    }
    if (datetime[datetime.length() - 2] == 'A')
    {
        return 0;
    }
    if (datetime[datetime.length() - 2] == 'P')
    {
        return 1;
    }

    return -1;
}

string formatDatetime(string datetime)
{
    vector<string> tmp = { "", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23" };

    //cout << getFormatDatetime(datetime) << endl;
    if (getFormatDatetime(datetime) == 1)
    {
        int a = datetime[11] - '0';
        int b = datetime[12] - '0';
        cout << a << ' ' << b << endl;
        string temp1 = datetime;
        string temp2 = datetime;
        string prefix = temp1.erase(11, 11);
        string suffix = temp2.erase(0, 13);

        return prefix + tmp[a * 10 + b] + suffix.erase(suffix.length()-3, 3);
    }
    if (getFormatDatetime(datetime) == 0)
    {
        return datetime.erase(datetime.length() - 3, 3);
    }

    return datetime;
}

int main(){
    string input;
    getline(cin, input);
    cout << formatDatetime(input);

    return 0;
}
