#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

class vector_getter_setter{
    public:
    void get_vector(vector<int> &nums){
        int num_length;
        cout << "Enter Length : ";
        cin >> num_length;
        cout << endl;

        for(int i=0; i<num_length; i++){
            int num;
            cout << "Enter Number : ";
            cin >> num;
            nums.push_back(num);
        }
    }
    
    void print_vector(vector<int> &nums){
        for(int i=0; i<nums.size(); i++){
            cout << nums[i] << endl;
        }
        cout<<endl;
    }
};

class node : public vector_getter_setter{
    public:
    int data;
    node* next;

    // Constructor 1: With Nullptr
    public: node(int data1, node* next1){
        data = data1;
        next = next1;
    }

    // Constructor 2: Without Nullptr
    public: node(int data1){
        data = data1;
        next = nullptr;
    }

    node* convertArrto_LL(vector<int> &nums){
        node *head = new node(nums[0]);
        node *current = head;

        for(int i=1; i<nums.size(); i++){
            node *newNode = new node(nums[i]);
            current->next = newNode;
            current = newNode;
        }

        return head;
    }

    void traverse_LL(node* head){
        node *temp = head;
        
        while(temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int length_of_LL(node *head){
        int count = 0;
        node *temp = head;

        while(temp != nullptr){
            count++;
            temp = temp->next;
        }

        return count;
    }

    bool search_element(node *head, int key){
        node *temp = head;

        while (temp){
            if(temp->data == key){
                return true;
                break;
            }
        }

        return false;
        
    }

    node *Reverse_LL(node *head){
        if (head == nullptr) return nullptr;

        vector<int> temp;
        node* temp_list = head;

        while (temp_list) {
            temp.push_back(temp_list->data);
            temp_list = temp_list->next;
        }

        reverse(temp.begin(), temp.end());

        node* new_head = new node(temp[0]);
        node* current = new_head;
        
        for (int i = 1; i < temp.size(); ++i) {
            current->next = new node(temp[i]);
            current = current->next;
        }

        return new_head;
    }

    node *Better_Reverse_LL(node *head){
        if (head == nullptr || head->next == nullptr) return head;

        node *current = head;
        node *previous = nullptr;

        while (current!=previous){
            node *temp = current;
            current = current->next;
            temp->next = previous;
            previous = temp;
        }

        return previous;
    }

    bool find_cycle(node *head){
        if (head == nullptr) return false;
        if(head == nullptr || head->next == nullptr){
            return false;
        }

        node *slow = head;
        node *fast = head->next->next;

        while(slow!=fast){
            if(fast == nullptr || fast->next == nullptr){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }

    bool find_cycle_approach_two(node *head){
        node* slow = head;
        node* fast = head;

        // Step 2: Traverse the linked list with
        // the slow and fast pointers

        while (fast != nullptr && fast->next != nullptr) {
            // Move slow one step
            slow = slow->next;
            
            // Move fast two steps
            fast = fast->next->next;

            // Check if slow and fast pointers meet
            if (slow == fast) {
                return true;  // Loop detected
            }
        }

        // If fast reaches the end of the list,
        // there is no loop
        
        return false;
    }

    node *index_of_cycle(node *head){
        node *slow = head;
        node *fast = head;

        // Find if a cycle exist or not
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){
                
                // Find the index where slow and fast
                // pointers meet
                slow = head;
                
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }

    bool LL_Palindrome(node *head){
        if(head == nullptr || head->next == nullptr) return true;

        vector<int> temp;
        node* temp_list = head;

        while (temp_list) {
            temp.push_back(temp_list->data);
            temp_list = temp_list->next;
        }

        // Use two pointers to compare the list and its reverse
        int left = 0, right = temp.size() - 1;
        
        while (left < right) {
            if (temp[left] != temp[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    node *delete_node(node *head) {
    char choice;
    cout << "PLEASE ENTER DELETION TYPE, a) END | b) BEGINNING | c) MIDDLE : ";
    cin >> choice;
    cout << endl;

    if (head == nullptr || head->next == nullptr) return nullptr;

    node* temp = nullptr;
    node* deletion_node = nullptr;
    node* look_ahead = nullptr;

    switch (choice) {
        case 'a':
            cout << endl << "DELETING FROM END" << endl;
            temp = head;

            while (temp->next->next) {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = nullptr;

            return head;
        break;

        case 'b':
            cout << endl << "DELETING FROM BEGINNING" << endl;
            temp = head;
            head = head->next;

            delete temp;
            return head;
        break;

        case 'c':
            cout << endl << "DELETING FROM MIDDLE" << endl;
            cout << "Enter Index to Delete : ";
            int index;
            cin >> index;

            temp = head;

            while(temp->next != nullptr && index > 1) {
                temp = temp->next;
                index--;
            }

            if (temp->next != nullptr && temp->next->next != nullptr) {
                deletion_node = temp->next;
                look_ahead = temp->next->next;

                delete deletion_node;
                temp->next = look_ahead;

            } else if (temp->next != nullptr) {
                deletion_node = temp->next;
                temp->next = nullptr;
                delete deletion_node;
            }

            return head;
        break;

        default:
            cout << "INVALID CHOICE" << endl;
        break;
    }

    return head;
}

    node *insert_node(node *head){
        cout<<"ENTER CHOICE, 1) END, 2) Beginning, 3) Middle : ";
        int choice;
        int data;
        cin>>choice;
        
        if(head == nullptr) return nullptr;
        node *temp = head;
        node *new_node;
        node *temp_node;

        switch (choice){
            
            case 1:
                cout << endl << "INSERTING AT END" << endl;
                cout << "Enter Data : ";
                
                cin >> data;
                
                new_node = new node(data, nullptr);
                
                while(temp->next != nullptr) {
                    temp = temp->next;
                }

                temp->next = new_node;

                return head;
            break;
            
            case 2:
                cout << endl << "INSERTING AT BEGINNING" << endl;
                cout << "Enter Data : ";
                
                cin >> data;

                new_node = new node(data);
                new_node->next = head;

                return new_node;
            break;
            
            case 3:
                cout << endl << "INSERTING AT MIDDLE" << endl;
                
                cout << "Enter Data : ";
                cin>>data;

                int index;
                cout<<"ENTER INDEX : ";
                cin>>index;

                while(temp != nullptr && index>1){
                    temp = temp->next;
                    index--;
                }

                temp_node = temp->next;
                new_node = new node(data);
                temp->next = new_node;
                new_node->next = temp_node;

                return head;
            break;
        
            default: cout<<"INVALID CHOICE"<<endl;
            break;
        }
    }

    node *sort_LL(node *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        int length = length_of_LL(head);
        
        for(int i=0; i<length; i++){
            node *temp = head;
            node *lookahead = temp->next;

            while(lookahead){
                if(temp->data > lookahead->data){
                    int temp_data = temp->data;
                    temp->data = lookahead->data;
                    lookahead->data = temp_data;
                }

                temp = temp->next;
                lookahead = lookahead->next;
            }
        }
        return head;
    }
};

int main(){ 
    vector<int> nums = {2, 3, 5, 4, 1};
    node *obj;
    
    node *head = obj->convertArrto_LL(nums);
    obj->traverse_LL(head);
    
    int result = obj->length_of_LL(head);
    cout << "Length of Linked List: " << result << endl;

    cout<<obj->search_element(head, 5)<<endl;

    node *reversed_LL = obj->Reverse_LL(head);
    obj->traverse_LL(reversed_LL);

    node *better_reversed_LL = obj->Better_Reverse_LL(head);
    obj->traverse_LL(better_reversed_LL);

    cout<<obj->find_cycle(head)<<endl;
    cout<<obj->find_cycle_approach_two(head)<<endl;

    node *cycle_index = obj->index_of_cycle(head);
    cout<<cycle_index<<endl;

    cout<<obj->LL_Palindrome(head);

    node *deleted_list = obj->delete_node(head);
    obj->traverse_LL(deleted_list);

    node *sorted_list = obj->sort_LL(head);
    obj->traverse_LL(sorted_list);

    node *updated_list = obj->insert_node(head);
    obj->traverse_LL(updated_list);

    return 0;
}