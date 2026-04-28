#include <string>

using namespace std;

class StringList {
    private:
    class Node {
        public:
            string data;
            Node *prev, *next;
            Node (string d) {
                data = d;
                prev = next = nullprt;
            }
    };
                Node *head, *tail;
        public:
            StringList();
            ~StringList();
            void add(string s);
            string str();
}

StringList::~StringList() {
    while (head != nullptr) {
        Node *aux = head;
        head = head -> next;
        delete aux;
    }
}

void StringList::add(string S) {
    Node *aux = new Node(s);
    if(head == nullptr) {
        head = tail = aux;
    } else {
        tail -> next = aux;
        aux -> prev = tail;
        tail = aux;
    }
}