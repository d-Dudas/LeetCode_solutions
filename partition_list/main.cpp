#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    // void removeNextNode(ListNode* node)
    // {
    //     ListNode* temp = node->next;
    //     node->next = node->next->next;
    //     free(temp);
    // }

    void removeNode(ListNode* head, ListNode* prev, ListNode* node)
    {
        if(node == head)
        {
            ListNode* tmp;
            tmp = head;
            head = node->next;
            prev = head;
            delete(tmp);
        } else {
            prev->next = prev->next->next;
            delete(node);
        }
    }

    void insertNodeBeforeX(ListNode* prev, ListNode* insertMe)
    {
        insertMe->next = prev->next;
        prev->next = insertMe;
    }

    ListNode* partition(ListNode* head, int x) {

        ListNode *xNode, *prev, *tempf, *templ, *temp;
        xNode = head;
        prev = head;
        tempf = nullptr; templ = nullptr;
        while(xNode != nullptr and xNode->val != x)
        {
            if(xNode->val >= x)
            {
                tempf = new ListNode(xNode->val, tempf);
                if(templ == nullptr) templ = tempf;
                removeNode(head, prev, xNode);
                xNode = prev->next;
            } else {
                prev = xNode;
                xNode = xNode->next;
            }
        }
        temp = xNode;
        while(temp->next != nullptr)
        {
            cout << temp->val << "\n";
            if(temp->next->val < x)
            {
                prev->next = temp->next;
                prev = prev->next;
                prev->next = xNode;
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        if(tempf != nullptr)
        {
            temp = xNode->next;
            xNode->next = tempf;
            templ->next = temp;
        }

        return head;
    }
};

int main()
{
    ListNode* list = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    Solution sol;

    ListNode* re = sol.partition(list, 3);
    ListNode* it = re;
    while(it != nullptr)
    {
        cout << it->val << " ";
        it = it->next;
    }
    cout << "\n";

    return 0;
}