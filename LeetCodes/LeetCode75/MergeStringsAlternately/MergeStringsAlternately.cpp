#include<iostream>
#include<vector>
using namespace std;

void displayArray(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<< " ";
    }
}

string mergeAlternately(string word1, string word2)
{
    vector<char> arr;
    int totalSize = word1.size() + word2.size();

    if(word1.size() > word2.size())
    {
        int i = word1.size(), j= word2.size();
        int m = 0, n = 0;
        while(i != 0)
        {
            arr.push_back(word1[m]);
            if( j != 0)
            {
                arr.push_back(word2[n]);
                j--;
                n++;
            }
            m++;
            i--;
        }
        string str(arr.begin(),arr.end());
        return str;
    }

    else{
        int i = word1.size(), j = word2.size();
        int m = 0, n = 0;

        while(j != 0)
        {
            if(i != 0)
            {
                arr.push_back(word1[m]);
                i--;
                m++;
            }
            arr.push_back(word2[n]);
            j--;
            n++;
        }
        string str(arr.begin(),arr.end());
        return str;
    }
}

int main()
{
    string word1 = "abc";
    string word2 = "de";

    string res = mergeArrayAlternately(word1,word2);
    cout << res;

    return 0;
}
