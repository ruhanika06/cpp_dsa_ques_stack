#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even!\n";
        return;
    }

    queue<int> firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); firstHalf.pop();
        q.push(q.front()); q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    for (int x : arr) q.push(x);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) { cout << temp.front() << " "; temp.pop(); }

    interleave(q);

    cout << "\nInterleaved Queue: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << endl;

    return 0;
}
