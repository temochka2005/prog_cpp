#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int key;
    Node *next;
};

void destroy_list(Node *&head_ptr) {
    Node *following = new Node;
    if (head_ptr != nullptr) {
        following = head_ptr->next;
    }

    while (head_ptr != nullptr) {
        delete head_ptr;
        head_ptr = following;
        if (following != nullptr) {
            following = following->next;
        }
    }
}

void print_list(Node *head_ptr) {
    if (head_ptr == nullptr) {
        std::cout << std::endl;
        return;
    }
    Node *current = head_ptr;
    while (current->next != nullptr) {
        std::cout << current->key << ' ';
        current = current->next;
    }
    std::cout << current->key << std::endl;
}


void push_back(Node *&head, int new_key) {
    if (head == nullptr) {
        head       = new Node;
        head->key  = new_key;
        head->next = nullptr;
        return;
    }
    Node *current = head;
    while (current->next)
        current = current->next;
    current->next       = new Node;
    current->next->key  = new_key;
    current->next->next = nullptr;
}

Node *read_list(Node *head) {
    int new_key = 0;

    cin >> new_key;

    while (new_key != 0) {
        push_back(head, new_key);
        cin >> new_key;
    }
    push_back(head, 0);
    return head;
}

Node *reverse(Node *head) {
    if (head == nullptr) {
        return head;
    }

    Node *current = head;
    Node *Next    = current->next;
    Node *Prev    = nullptr;

    while (Next != nullptr) {
        current->next = Prev;
        Prev          = current;
        current       = Next;
        Next          = Next->next;
    }
    current->next = Prev;
    head          = current;
    return head;
}

int main() {
    Node *head = nullptr;
    head       = read_list(head);
    head       = reverse(head);
    print_list(head);
    destroy_list(head);
    return 0;
}