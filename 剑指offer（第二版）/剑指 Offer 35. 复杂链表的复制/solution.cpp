class Solution {
private:
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (!map.count(head)) {
            Node* newHead = new Node(head->val);
            map[head] = newHead;
            newHead->next = copyRandomList(head->next);
            newHead->random = copyRandomList(head->random);
        }

        return map[head];
    }
};