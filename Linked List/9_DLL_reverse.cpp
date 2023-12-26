Node* reverseDLL(Node* head)
{   
    Node* p = head;
    Node* temp = nullptr;

    while (p != nullptr) {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    }

  
    if (temp != nullptr) {
        head = temp->prev;
    }

    return head;  
}