#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkQueueSorted(queue<int>& q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == expected) {
            expected++;
        } else {
            if (!st.empty() && st.top() == expected) {
                while (!st.empty() && st.top() == expected) {
                    st.pop();
                    expected++;
                }
            }
            st.push(front);
        }
    }

    // Empty remaining stack
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    return (expected - 1 == n);
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (checkQueueSorted(q))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
