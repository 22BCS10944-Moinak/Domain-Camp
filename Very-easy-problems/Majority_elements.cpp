#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findMajorityElements(const vector<int>& nums) 
{
    int n = nums.size();
    int candidate = 0, count = 0;

    for (int num : nums) 
    {
        if (count == 0) 
        {
            candidate = num;
            count = 1;
        } 
        
        else if (num == candidate) 
        {
            count++;
        } 
        
        else 
        {
            count--;
        }
    }

    count = 0;
    for (int num : nums) 
    {
        if (num == candidate) 
        {
            count++;
        }
    }

    vector<int> result;
    if (count > n / 2) 
    {
        result.push_back(candidate);
    }
    return result;
}

int main() 
{
    vector<int> nums;
    int size, element;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) 
    {
        cin >> element;
        nums.push_back(element);
    }

    vector<int> majorityElements = findMajorityElements(nums);

    if (!majorityElements.empty()) {
        cout << "Majority element(s): ";
        for (int elem : majorityElements) 
        {
            cout << elem << " ";
        }
        cout << endl;
    } 
    else 
    {
        cout << "No majority element found.\n";
    }

    return 0;
}
