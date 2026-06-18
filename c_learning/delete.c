int Delete(List *L) {
    NodePointer p;

    if (L->current == NULL) {
        return (0); 
    } 
    else {
        p = HEAP[L->current].next;             
        HEAP[L->current].next = HEAP[p].next; 
        Free(p);                               
        
        if (HEAP[L->current].next == -1) {
            L->current = NULL;
        }
        return (1); 
    }
}