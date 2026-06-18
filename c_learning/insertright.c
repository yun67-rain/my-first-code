int InsertRight(List *L, Element e) {
    NodePointer p;

    if (L->current == NULL) {
        return (0); 
    } 
    else {
        p = Malloc(); 
        HEAP[p].value = e;
        
        HEAP[p].next = HEAP[HEAP[L->current].next].next;
        HEAP[HEAP[L->current].next].next = p;
        
        return (1); 
    }
}