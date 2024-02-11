#include<iostream>
#include<vector>

using namespace std;

void displayArray(vector<bool>& arr)
{
    for(int i = 0; i < arr.size();i++)
    {
        cout << arr[i] << " ";
    }
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> arr;

    int n = candies.size();
    int maxNum = candies[0];

    for(int i = 0 ; i < n; i++)
    {
        if(candies[i] > maxNum)
        {
            maxNum = candies[i];
        }
    }

    for(int i =0 ; i < n; i++)
    {
        if(candies[i] + extraCandies >= maxNum)
        {
            arr.push_back(true);
        }
        else
        {
            arr.push_back(false);
        }
    }

    return arr;

}

int main()
{
    vector<int> candies  {2,3,5,1,3};
    int extraCandies = 3;

    vector<bool> result = kidsWithCandies(candies, extraCandies);

    cout << "Result: ";
    displayArray(result);
    cout << endl;

    return 0;
}
