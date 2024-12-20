#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findSingleElements(const vector<int>& nums) {
    unordered_map<int, int> freqMap;

    // Count the frequency of each element
    for (int num : nums) {
        freqMap[num]++;
    }
  
    vector<int> result;
    for (const auto& pair : freqMap) {
        if (pair.second == 1) {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main() {
    vector<int> nums;
    int size, element;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> element;
        nums.push_back(element);
    }

    vector<int> singleElements = findSingleElements(nums);

    if (!singleElements.empty()) {
        cout << "Single element(s): ";
        for (int elem : singleElements) {
            cout << elem << " ";
        }
        cout << endl;
    } else {
        cout << "No single elements found.\n";
    }

    return 0;
}
