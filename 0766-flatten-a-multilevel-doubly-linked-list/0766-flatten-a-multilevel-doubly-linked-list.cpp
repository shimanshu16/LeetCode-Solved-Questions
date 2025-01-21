
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        flattenNode(head);

        return head;
    }

private:
    Node* flattenNode(Node* node) {
        Node* current = node;
        Node* tail = node; 

        while (current != nullptr) {
            if (current->child != nullptr) {
                Node* child = current->child;
                current->child = nullptr;

                Node* childTail = flattenNode(child);

                childTail->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = childTail;
                }
                current->next = child;
                child->prev = current;

                tail = childTail;
            }

            current = current->next;
            if (current != nullptr) {
                tail = current; 
            }
        }

        return tail; 
    }
};