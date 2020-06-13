#include <bits/stdc++.h>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    // ListNode* recursiveTravel(ListNode* head){
    //     if(!head){
    //         recursiveTravel(head->next);
    //         return head;
    //     }
    // }

    // ListNode* recursiveTravel(ListNode* head){
    //     if(!head){
    //         recursiveTravel(head->next);
    //         return head;
    //     }
    // }
    
    ListNode* addNode(ListNode* h, int t){
        if(h==NULL){
            h=new ListNode(t);
        }
        else{
            ListNode* tmp=new ListNode(t);
            
            h->next=tmp;
        }

        return h;
    }

    void input(ListNode* head){
        int i=5;
        int tmp;

        while(i--){
            cin >> tmp;
            head=addNode(head, tmp);
        }
    }

    void print(ListNode* head){
        ListNode* it=head;

        while(head!=NULL){
            cout << head->val << '\n';
            head=head->next;
        }
    }
    
    ListNode* addHead(ListNode* h, int t){
        if(h==NULL){
            h=new ListNode(t);
        }
        else{
            ListNode* tmp=new ListNode(t);
            
            tmp->next=h;
            h=tmp;
        }
        
        return h;
    }

    ListNode* reverseLinkedList(ListNode* head){
        if(head==NULL){
            return head;
        }

        ListNode *curr=head, *prev=NULL, *nxt=head->next;

        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        return prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        
        ListNode *h=NULL, *it=head;
    
        while(it!=NULL){
            h=addHead(h, it->val);
            it=it->next;
        }
        
        return h;
    }
};

int main(){
    Solution sol;
    ListNode* temp;

    sol.input(temp);
    sol.print(temp);

    return 0;
}
