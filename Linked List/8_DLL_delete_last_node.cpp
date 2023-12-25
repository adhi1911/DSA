Node * deleteLastNode(Node *head) {
    Node* p = head;
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    while(p->next){
        p=p->next;
    }
    p->prev->next = NULL;
    delete p;

    return head;
}