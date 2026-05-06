#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node{ 
int data;
Node* next;
Node* prev;
Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList{
private:
Node* head;
Node* tail;
int size;
public:
DoublyLinkedList() : head(nullptr), tail(nullptr), size(0){}
void insertBegin(int x) {
Node* newNode = new Node(x);
if (!head){
head = tail = newNode;
}
else{
newNode->next = head;
head->prev = newNode;
head = newNode;
}                                                                                             
size++;
}                                                                                                                           
void insertEnd(int x) {
Node* newNode = new Node(x);
if (!tail){ 
head = tail = newNode;
}                                                                                                                                  else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}                                                                                                                                  size++;
}                                                                                                                                  void insertAt(int pos, int x) {
if (pos < 1 || pos > size + 1) {
cout << "Invalid position" << endl;
return;
}                                                                                                                                  if (pos == 1) {
insertBegin(x);
}                                                                                                                                  else if (pos == size  +1) {
insertEnd(x);
}                                                                                                                           
else{                                                                                                                                  Node* newNode = new Node(x);
Node* curr = head;
    for (int i = 1; i < pos; i++) {
curr = curr->next;
    }newNode->next = curr;
 newNode->prev = curr->prev;
curr->prev->next = newNode;
curr->prev = newNode;
size++;
} 
}void search(int x) {
Node* curr = head;
vector<int> positions;
int currentPos = 1;
while (curr) {
if (curr->data == x) {
positions.push_back(currentPos);
}curr = curr->next;
currentPos++;
}if (positions.empty()) {
 cout << "Element " << x << " not found" << endl;
}
else {
 cout << "Found at position:";
for (int p : positions) {
cout << " " << p;
}cout << endl;
}
}void display() {
    if(!head){
        cout<<"List is empty"<<endl;
        return;
    }
    Node *curr=head;
    while(curr){
        cout<<curr->data;
        if(curr->next){
            cout<<" <-> ";
        }
        curr=curr->next;
    }
        cout<<endl;
    }
};
int main() {
int Q;
if (!(cin >> Q)) return 0;
DoublyLinkedList dll;
string command;
while (Q--) {
cin >> command;
if (command == "INSERT_BEGIN") {
int x; cin >> x;
dll.insertBegin(x);
}
else if (command == "INSERT_END") {
int x; cin >> x;
dll.insertEnd(x);
}
else if (command == "INSERT_AT") {
int pos, x; cin >> pos >> x;
dll.insertAt(pos, x);
}
else if (command == "SEARCH") {
int x; cin >> x;
 dll.search(x);
}
else if (command == "DISPLAY") {
dll.display();
}
}return 0;
}
