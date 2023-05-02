#include <iostream>
#include <chrono>
#define MAX_SIZE 50

using namespace std;
using namespace std::chrono;

#include <iostream>
using namespace std;

int stack_size = 0;
int number_of_elements = 0;


struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = NULL;
        }

        void push(int value) {
            Node* temp = new Node;
            temp->data = value;
            temp->next = top;
            top = temp;
            number_of_elements+=1;
        }

        int pop() {
            if (top == NULL) {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete(temp);
            number_of_elements-=1;
            return value;
        }

        int stackTop() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return 0;
            }
            return top->data;
        }

        bool isEmpty() {
            if (number_of_elements == 0){
                return true;
            }
            return false;
        }

        bool isFull(){
            if (stack_size == number_of_elements){
                return true;
            }
            return false;
        }

        void display() {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};


int main() {
   
    auto start1 = high_resolution_clock::now();
    Stack s;
    stack_size = 100;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(30);
    s.push(1);
    s.display();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
cout <<"Time taken by linked list implementation " << duration1.count()<<" ns" << endl;

   

    return 0;
}
