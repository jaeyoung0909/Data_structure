#include <iostream>

using namespace std;

typedef struct Node{
    Node* prev;
    Node* post;
    int val;
}Node_list;

class Linkedlist{
    int num;
    Node_list* first;
    Node_list* last;
    public:
        void enqueue(Node_list* node);
        int dequeue();
        int size();
        int find(int x);

    Linkedlist(int _num, Node_list* _first, Node_list* _last){
        num = _num;
        first = _first;
        last = _last;
    }    
};

void Linkedlist::enqueue(Node_list* node){
    if(!num){
        node->prev = NULL;
        node->prev = NULL;
        first = node;
        last = node;    
    }
    node->post = NULL;
    last->post = node;
    node->prev = last;
    last = node;
    num++;
}

int Linkedlist::dequeue(){
    if(!num) return -1;
    int result = last->val;
    (last->prev)->post = NULL;
    last = (last->prev);
    num--;
    return result;

}
int Linkedlist::size(){
    return num;
}


int Linkedlist::find(int x){
    Node_list* comp = first;
    for(int i=0; i<num; i++){
        if(x == comp->val) return i;
        comp = comp->post;
    }
    return -1;
}
int main(){
    Node_list* first = new Node_list;
    Node_list* last= new Node_list;
    Node_list* ex1=new Node_list;
    ex1->val = 10;
    Node_list* ex2=new Node_list;
    ex2->val = 20;
    Linkedlist list(0, first, last);
    list.enqueue(ex1);
    list.enqueue(ex2);
    list.dequeue();
    cout << list.find(10) << endl;
    delete first;
    delete last;
    return 0;
}