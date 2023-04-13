// // #include <iostream>


// // struct Node
// // {
// //     char key;
// //     Node *next;
// // };

// // void destroy_list(Node *&head_ptr) {
// //     Node *following = nullptr;
// //     if (head_ptr != nullptr) {
// //         following = head_ptr->next;
// //     }

// //     while (head_ptr != nullptr) {
// //         Node *temp = head_ptr;
// //         head_ptr = following;
// //         if (following != nullptr) {
// //             following = following->next;
// //         }
// //         delete temp;
// //     }
// // }


// // // void checker(Node* head){
// // //     if (head == nullptr){
// // //         head = new Node;
// // //         head->key = std::getchar();
// // //         if (head->key == ')'){
// // //             std::cout << "NO" << std::endl;
// // //             destroy_list(head); 
// // //             return;
// // //         }else if (head->key == '\n'){
// // //             std::cout << "YES" << std::endl;
// // //             destroy_list(head); 
// // //             return;
// // //         }
// // //         head->next = nullptr;
// // //     }

// // //     Node* current = head;
// // //     Node* Next = current->next;
// // //     Node* Prev = nullptr;
// // //     int rcounter = 0;
// // //     int lcounter = 0;
// // //     while(current->key != '\n'){
// // //         Next = new Node;
// // //         Next->key = std::getchar();
// // //         if ( Next->key == ')') rcounter++;
// // //         if ( Next->key == '(') lcounter++;
// // //         Next->next = nullptr;
// // //         Prev = current;
// // //         current = Next;
// // //         Next = Next->next;
// // //     }
    
// // //     if ( rcounter != lcounter+1 or Prev->key == '('){
// // //         std::cout << "NO" << std::endl;
// // //         destroy_list(head); 
// // //         return;
// // //     }
// // //     destroy_list(head);
// // //     std::cout << "YES" << std::endl;
// // //     return;
// // // }

// // void checker(Node* head){
// //     if (head == nullptr){
// //         head = new Node;
// //         head->key = std::getchar();
// //         if (head->key == ')'){
// //             std::cout << "NO" << std::endl;
// //             destroy_list(head); 
// //             return;
// //         }else if (head->key == '\n'){
// //             std::cout << "YES" << std::endl;
// //             destroy_list(head); 
// //             return;
// //         }
// //         head->next = nullptr;
// //     }

// //     Node* current = head;
// //     Node* Next = current->next;
// //     Node* Prev = nullptr;
// //     int rcounter = 0;
// //     int lcounter = 0;
// //     while(current->key != '\n'){
// //         Next = new Node;
// //         Next->key = std::getchar();
// //         if ( Next->key == ')') rcounter++;
// //         if ( Next->key == '(') lcounter++;
// //         Next->next = nullptr;
// //         Prev = current;
// //         current = Next;
// //         Next = Next->next;
// //         delete Prev;
// //     }
    
// //     if ( rcounter != lcounter+1 or Prev->key == '('){
// //         std::cout << "NO" << std::endl;
// //         destroy_list(head); 
// //         return;
// //     }
// //     destroy_list(head); 
// //     std::cout << "YES" << std::endl;
// //     return;
// // }


// // void print_list(Node *head_ptr) {
// //     if (head_ptr == nullptr) {
// //         std::cout << std::endl;
// //         return;
// //     }
// //     Node *current = head_ptr;
// //     while (current->next != nullptr) {
// //         std::cout << current->key << ' ';
// //         current = current->next;
// //     }
// //     std::cout << current->key << std::endl;
// // }



// //     // if (current->key == Next->key){
// //         //     std::cout << "NO" << std::endl;
// //         //     return;
// //         // }

// // int main() {
// //     Node *head  = nullptr;
// //     checker(head);
// //     print_list(head);   
// //     return 0;
// // }




// #include <iostream>

// struct Node {
//     char key;
//     Node* next;
// };

// void destroy_list(Node* head) {
//     while (head) {
//         Node* tmp = head;
//         head = head->next;
//         delete tmp;
//     }
// }

// void checker(Node* head){
//     if (head == nullptr){
//         head = new Node;
//         head->key = std::getchar();
//         if (head->key == ')'){
//             std::cout << "NO" << std::endl;
//             destroy_list(head);
//             return;
//         }else if (head->key == '\n'){
//             std::cout << "YES" << std::endl;
//             destroy_list(head); 
//             return;
//         }
//         head->next = nullptr;
//     }

//     Node* current = head;
//     Node* Next = current->next;
//     Node* Prev = nullptr;
//     int rcounter = 0;
//     int lcounter = 0;
//     while(current->key != '\n'){
//         Next = new Node;
//         Next->key = std::getchar();
//         if ( Next->key == ')') rcounter++;
//         if ( Next->key == '(') lcounter++;
//         Next->next = nullptr;
//         Prev = current;
//         current = Next;
//         Next = Next->next;
//         delete Prev;
//     }
    
//     if ( rcounter != lcounter+1 or Prev->key == '('){
//         std::cout << "NO" << std::endl;
//         destroy_list(head); 
//         return;
//     }
//     destroy_list(head); 
//     std::cout << "YES" << std::endl;
//     return;
// }

// int main() {
//     Node* head = nullptr;
//     checker(head);
//     return 0;
// }







#include <iostream>

struct Node {
    char key;
    Node* next;
};

void destroy_list(Node*& head) {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void checker(Node* head){
    if (head == nullptr){
        head = new Node;
        head->key = std::getchar();
        if (head->key == ')'){
            std::cout << "NO" << std::endl;
            destroy_list(head); 
            return;
        }else if (head->key == '\n'){
            std::cout << "YES" << std::endl;
            destroy_list(head); 
            return;
        }
        head->next = nullptr;
    }
    Node* current = head;
    Node* Next = current->next;
    Node* Prev = nullptr;
    int rcounter = 0;
    int lcounter = 0;
    while(current->key != '\n'){
        Next = new Node;
        Next->key = std::getchar();
        if ( Next->key == ')') rcounter++;
        if ( Next->key == '(') lcounter++;
        Next->next = nullptr;
        Prev = current;
        current = Next;
        Next = Next->next;
        delete Prev;
    }
    
    if ( rcounter != lcounter+1 or Prev->key == '('){
        std::cout << "NO" << std::endl;
        destroy_list(head); 
        return;
    }
    destroy_list(head); 
    std::cout << "YES" << std::endl;
    return;
}

int main() {
    Node* head = nullptr;
    checker(head);

    return 0;
}