

Node * insertAtTail(Node *head, int k) {
    Node* p = head;
    Node* temp = new(Node);
    temp->value = k;
    temp->next = NULL;
    if(head == NULL){
        temp->prev=NULL;
        head = temp;
    }
    else{
        while (p->next) {
          p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    return head;

}

