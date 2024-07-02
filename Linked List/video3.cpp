#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp; 
        mover = temp;  // mover=mover->next
    }
    return head;
}

void printingLL(Node* head){
    Node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* removesHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;    //Using free(temp);is also same    
    return head;
}

Node* removesTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

Node* deleteK(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;
    Node* prev=NULL;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteEl(Node* head, int k){
    if(head==NULL) return head;
    if(head->data==k){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;    
}

Node* insertHead(Node* head, int val){
    // Node* temp=new Node(val,head);
    // return temp;

    //or
    return new Node(val,head);
}

Node* insertTail(Node* head, int val){
    if(head==NULL) return new Node(val);

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}

Node* insertK(Node* head,int k, int val){
    if(head==NULL){
        if(k==1) return new Node(val);
        return head;
    }
    if(k==1){
        Node* temp=new Node(val,head);
        // head=temp;
        return temp;
    } 
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            // temp->next=new Node(val,temp->next);  //Shorter way self created
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head,int x, int val){
    if(head==NULL){
        return new Node(val);
    }
    if(head->data==x){
        Node* temp=new Node(val,head);
        // head=temp;
        return temp;
    } 

    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==x){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            // temp->next=new Node(val,temp->next);  //Shorter way self created
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    //Deletion Of Head Node
    // vector<int>arr={12,5,7,8};
    // Node* head=convertArr2LL(arr);
    // head=removesHead(head);
    // printingLL(head);

    // Deletion of Tail Node
    // vector<int>arr={12,5,7,8};
    // Node* head=convertArr2LL(arr);
    // head=removesTail(head);
    // printingLL(head);

    // Deletion of Kth Node
    // vector<int>arr={12,5,7,8};
    // Node* head=convertArr2LL(arr);
    // head=deleteK(head,3);
    // printingLL(head);

    // Deletion of Element
    // vector<int>arr={12,5,7,8};
    // Node* head=convertArr2LL(arr);
    // head=deleteEl(head, 8);
    // printingLL(head);

    //Insertion At head
    // vector<int>arr={12,5,7,8};
    // Node* head=convertArr2LL(arr);
    // // head=insertHead(head, 10);
    // //or
    // head=new Node(14,head);
    // printingLL(head);


    //Insertion At Tail
    // vector<int>arr={12,5,7,8};
    // Node* head=convertArr2LL(arr);
    // head=insertTail(head, 10);
    // printingLL(head);

    //Insertion At Kth Position
    // vector<int>arr={12,5,7,8};
    // Node* head=convertArr2LL(arr);
    // head=insertK(head, 3, 27);
    // printingLL(head);

    //Insert before value x
    vector<int>arr={12,5,7,8};
    Node* head=convertArr2LL(arr);
    head=insertBeforeValue(head, 3, 27);
    printingLL(head);
    return 0;
}

// iterate till temp==null means to go over full LL
// iterate till temp->next!=null means to go to last element