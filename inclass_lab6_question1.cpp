#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int max_size = 20; 

int top = -1; 
int arr[max_size]; 


void Push(int x) {
    if (top >= max_size - 1) { 
        cout << "Error: stack overflow" << endl;
        return ;
    }
    top+=1;
    arr[top] = x; 
    return ;
}

int Pop() {
    if (top < 0) { 
        cout << "Error: stack underflow!" << endl;
        return -1;
    }
    int x = arr[top]; 
        top-=1;

    return x;
}

bool isEmpty() {
    return (top < 0);
}

bool isFull() {
    return (top >= max_size - 1);
}

int stackTop() {
    if (top < 0) { 
        cout << "Stack is empty" << endl;
        return 0;
    }
    return arr[top]; 
}


void Display() {
    if (top < 0) { 
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements are: ";
    for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
auto start1 = high_resolution_clock::now();
Push(8);
Push(10);
Push(5);
Push(11);
Push(15);
Push(23);
Push(6);
Push(18);
Push(20);
Push(17);
Display();
Pop() ;
Pop();
Pop();
Pop();
Pop();
Display();
Push(4);
Push(30);
Push(3);
Push(1);
Display();
auto stop1 = high_resolution_clock::now();
auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
cout << "Time taken by array implementation " << duration1.count()<< " ns" << endl;
    
    
    
    return 0;
}
