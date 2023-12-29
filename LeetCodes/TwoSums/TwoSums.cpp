#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector <int> myVector;
    for(int i = 0; i < nums.size() ; i++)
    {
        for(int j = i+1; j < nums.size();j++)
        {
            if(nums[i] + nums[j] == target)
            {
                myVector.push_back(i);
                myVector.push_back(j);
                return myVector;
            }
        }
    }
    return myVector;

}



int main()
{
    vector<int> test1 = {2,7,11,15};
    vector<int>test2 = {3,3};
    vector<int> test3 = {3,4,7,11};

    display(twoSum(test1,9));
    cout << "done" << endl;
    display(twoSum(test2,6));
    cout << "done" << endl;
    display(twoSum(test3,15));
    cout << "done" << endl;

    return 0;
}
