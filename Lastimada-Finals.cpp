#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int numRescueBoats(vector<int> &people, int limit)
{
    selectionSort(people);
    int left = 0, right = people.size() - 1;
    int boats = 0;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            left++;
        }
        right--;
        boats++;
    }
    return boats;
}

int main()
{
    int limit1 = 3;
    vector<int> people1 = {1, 2};
    cout << "Output: " << numRescueBoats(people1, limit1) << endl;

    int limit2 = 3;
    vector<int> people2 = {3, 2, 2, 1};
    cout << "Output: " << numRescueBoats(people2, limit2) << endl;

    int limit3 = 5;
    vector<int> people3 = {3, 5, 3, 4};
    cout << "Output: " << numRescueBoats(people3, limit3) << endl;

    return 0;
}
