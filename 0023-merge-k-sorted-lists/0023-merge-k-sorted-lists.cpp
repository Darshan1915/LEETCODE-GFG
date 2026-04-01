/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min Heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Step 1: push first node of each list
        for (auto list : lists) {
            if (list != NULL) {
                pq.push(list);
            }
        }

        // Dummy node for result
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Step 2: process heap
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = temp;

            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        }

        return dummy->next;
    }
};