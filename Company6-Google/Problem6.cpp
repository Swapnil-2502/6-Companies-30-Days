23. Merge k Sorted Lists
LinK: https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    void insertAtTail(ListNode* &head,ListNode* &tail, int data){
        ListNode* newNode = new ListNode(data);

        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        map<int,int> mp;

        for(int i=0;i<lists.size();i++){
            ListNode* curr = lists[i];

            while(curr){
                mp[curr->val]++;
                curr = curr->next;
            }
        }

        ListNode* head = NULL, *tail = NULL;

        for(auto it: mp){
            int freq = it.second;

            while(freq--){
                insertAtTail(head,tail,it.first);
            }
        }

        return head;
    }
};
// Time complexity: O(N * K * log K) -> {N*K for tarversing each nodes and log k for inserting in map}
// Space complexity: O(N*K) -> {total number of nodes, to store values in map}