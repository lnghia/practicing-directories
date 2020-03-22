#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

struct stack{
    node *top;
};

void init(stack &s){
    s.top=NULL;
}

bool isempty(stack s){
    return (s.top==NULL);
}

node *makenode(int x){
    node *p=new node;
    p->data=x;
    p->next=NULL;
    return p;
}

void push(stack &s, int x){
    node *p;
    p=makenode(x);
    p->next=s.top;
    s.top=p;
}

void pop(stack &s){
    if(!isempty(s)){
        s.top=s.top->next;
    }
}

void peek(stack s){
    if(!isempty(s)){
        cout << s.top->data << endl;
    }
    else{
        cout << "Empty!" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n;
    cin >> n;
    int op;
    stack s;
    init(s);


    while(n>=1){
        cin >> op;
        if(op==1){
            long long x;
            cin >> x;
            push(s, x);
        }
        if(op==2){
            pop(s);
        }
        if(op==3){
            peek(s);
        }
        --n;
    }
    return 0;
}
