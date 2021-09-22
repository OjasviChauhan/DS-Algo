// https://leetcode.com/problems/swap-nodes-in-pairs/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// passing with reference for insert operation
void insert(ListNode* &head, int x) {
    if (head == NULL) {
        head = new ListNode(x);
        return;
    }
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = new ListNode(x);
}

// passing with value for print operation
void print(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

ListNode* swapNodesinPairs(ListNode* head) {
    ListNode* p = NULL;
    ListNode* c = head;
    ListNode* n;
    ListNode* start;

    ListNode* ans = new ListNode(0);
    ListNode* connect = ans;

    int k = 2;

    while (c) {
        start = c;
        while (c and k--) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        connect->next = p;
        connect = start;
        k = 2;    // restore k
        p = NULL; // reset p
    }

    return ans->next;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    ListNode* head = NULL;

    while (n--) {
        int t;
        cin >> t;
        insert(head, t);
    }

    ListNode* res = swapNodesinPairs(head);
    print(res);
}
