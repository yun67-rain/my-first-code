void Clear(List *L) {
    NodePointer p, q;

    p = HEAP[L->head].next; 
    while (p != -1) {       
        q = HEAP[p].next;   
        Free(p);            
        p = q;              
    }
    
    HEAP[L->head].next = -1; 
    L->current = NULL;       
}