#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

struct queue{
    node *head;
    node *tail;
};

void init(queue &q){
    q.head=q.tail=NULL;
}

bool isempty(queue q){
    return (q.head==NULL);
}

node *makenode(int x){
    node *p=new node;
    p->data=x;
    p->next=NULL;
    return p;
}

void add_fr(queue &q, int x){
    node *p;
    p=makenode(x);
    if(!isempty(q)){
        p->next=q.head;
        q.head=p;
    }
    else{
        q.head=q.tail=p;
    }
}

void add_back(queue &q, int x){
    node *p;
    p=makenode(x);
    if(!isempty(q)){
        q.tail->next=p;
        q.tail=p;
    }
    else{
        q.head=q.tail=p;
    }
}

void reverse(queue &l){
    if(isempty(l) || l.head==l.tail){
        return;
    }
    node *p, *q, *t, *c;
    p=l.head;
    q=l.head->next;
    t=c=q->next;
    q->next=p;
    p->next=NULL;
    while(c!=NULL){
        c=c->next;
        t->next=q;
        q=t;
        t=c;
    }
    l.head=q;
    l.tail=p;
}

void back(queue &q){
    if(!isempty(q)){
        cout << q.tail->data << endl;
        node *p=q.head;
        if(q.head==q.tail){
            q.head=q.tail=NULL;
            return;
        }
        while(p->next!=q.tail){
            p=p->next;
        }
        q.tail=p;
        p->next=NULL;
    }
    else{
        cout << "No job for Ada?" << endl;
    }
}

void front(queue &q){
    if(!isempty(q)){
        cout << q.head->data << endl;
        q.head=q.head->next;
    }
    else{
        cout << "No job for Ada?" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue q;
    init(q);
    long n;
    int mode=0;
    cin >> n;
    string s;
    while(n>=1){
        cin >> s;
        if(s=="back"){
            if(mode==1)
                front(q);
            else back(q);
        }
        if(s=="front"){
            if(mode==1)
                back(q);
            else front(q);
        }
        if(s=="reverse"){
            if(mode==0)
                mode=1;
            else mode=0;
        }
        if(s=="push_back"){
            int x;
            cin >> x;
            if(mode==1)
                add_fr(q, x);
            else add_back(q, x);
        }
        if(s=="toFront"){
            int x;
            cin >> x;
            if(mode==1)
                add_back(q, x);
            else add_fr(q, x);
        }
        --n;
    }
    return 0;
}
