#include <iostream>
#include <stack>
using namespace std;

void nextGreaterElement(int arr[], int n) {
    int nge[n];  // array to store Next Greater Elements
    stack<int> s;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop all elements smaller or equal to arr[i]
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // If stack is empty, no greater element
        if (s.empty())
            nge[i] = -1;
        else
            nge[i] = s.top();

        // Push current element onto stack
        s.push(arr[i]);
    }

    // Print the result
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++)
        cout << nge[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);
    return 0;
}
