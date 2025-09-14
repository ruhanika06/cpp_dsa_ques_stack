#include <iostream>
#include <queue>
using namespace std;

// Function to find index of minimum element in first 'n' elements of queue
int minIndex(queue<int> &q, int sortedIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        // Only consider elements till sortedIndex
        if (curr <= min_val && i <= sortedIndex) {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);
    }
    return min_index;
}

// Function to move min element to rear
void insertMinToRear(queue<int> &q, int min_index) {
    int min_val;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i != min_index) {
            q.push(curr);
        } else {
            min_val = curr;
        }
    }
    q.push(min_val);
}

// Function to sort queue
void sortQueue(queue<int> &q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    sortQueue(q);

    cout << "\nSorted Queue: ";
    while (!q.empty()) {
        cout
