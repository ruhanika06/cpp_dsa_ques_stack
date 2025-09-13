#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isStackSortable(vector<int>& A) {
    stack<int> S;
    int n = A.size();
    int current = 1; // smallest number expected (for 1..n). Adjust if array has different range

    for (int i = 0; i < n; i++) {
        S.push(A[i]);
        while (!S.empty() && S.top() == current) {
            S.pop();
            current++;
        }
    }

    return S.empty(); // if empty, we could sort using the stack
}

int main() {
    vector<int> A = {4, 1, 3, 2};
    if (isStackSortable(A)) {
        cout << "Yes, it's possible to sort B using stack operations.\n";
    } else {
        cout << "No, it's not possible.\n";
    }
}
