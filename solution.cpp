/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // push first nodes
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            current->next = node;
            current = current->next;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
