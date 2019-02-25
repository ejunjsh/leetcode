/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * head_cp = nullptr, * cur = head, * cur_cp = nullptr;
        if (head == nullptr)
            return nullptr;
        //在原链表的每个节点后面拷贝出一个新的节点
        while (cur != nullptr)
        {
            cur_cp = new Node (cur->val,nullptr,nullptr);
            cur_cp->next = cur->next;
            cur->next = cur_cp;
            cur = cur_cp->next;
        }
        cur = head;
        //依次给新的节点的随机指针赋值，而且这个赋值非常容易 cur->next->random = cur->random->next
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            if (cur->random)
                cur_cp->random = cur->random->next;
            cur = cur_cp ->next;
        }
        cur = head;
        head_cp = head->next;
        //断开链表可得到深度拷贝后的新链表
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            cur->next = cur_cp->next;
            cur = cur->next;
            if (cur)
                cur_cp->next = cur->next;
        }
        return head_cp;
    }
};