#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gllist.h"
#include "pqueue.h"


struct pqueueType {
    gllist list;
};
struct pq{
    void *data;
    int priority;
};
  // passing a NULL pq to any routine (except freepq) is undefined
  
pq createpq(){
    pq t = malloc(sizeof(struct pqueueType));
    t->list = createGLlist();
    return t;
}
void freepq(pq queue){
    pq t = queue;
    while(queue->next != NULL){
        t = queue;
        queue = queue->next;
        free(t);
    }
}
pq copy(pq q); // returns an exact (shallow) copy of p
/* priority p is defined as 0 <= p <= 100 where 0 is the lowest, 100 the highest */
void enq(pq q,void *item,int p){
    while(q->next != NULL && p >= q->priority){
        q = q->next; 
    }
        pq newNode = createpq();
        newNode->data = item;
        newNode->priority = p;

        newNode->next = q->next;
        q->next = newNode;
  


} // inserts item with priority p into
// queue q; items added with the same
// priority are added after previous
// items with that priority
void deq(pq q){
    if(q->next == NULL){
        return;
    }

    pq t = q->next;
    q->next = t->next;
    free(t);
}
// removes item at front of q
void *front(pq q){
    if(q->next == NULL){
        return NULL;
    }
    return q->next->data;
} // returns item at front of q without removing it;
// is undefined if q is empty
int frontP(pq q){
    if(q->next == NULL){
        return NULL;
    }
    return q->next->priority;
} // returns priority of item at front without removing it;
// is undefined if q is empty
void *rear(pq q){
    while(q->next != NULL){
        q = q->next; 
    }
    if(q->next == NULL){
        return NULL;
    }
    return q->data;
} // returns item at rear without removing it;
// is undefined if q is empty
int rearP(pq q){
    while(q->next != NULL){
        q = q->next; 
    }
    if(q->next == NULL){
        return NULL;
    }
    return q->priority;
} // returns priority of item at rear without removing it;
// is undefined if q is empty
int countP(pq q,int p){
    int count = 0;
    while(q->next != NULL){
        q = q->next; 
        if(q->priority == p){
            count++;
        }
    }
    return count;
} // returns count of items in q at priority p
int pqSize(pq q){
    int count = 0;
    while(q->next != NULL){
        q = q->next; 
        count++;
    }
    return count;
} // current queue size
bool pqEmpty(pq q){
    if(q->next == NULL){
        return true;
    } else{
        return false;
    }
}
bool pqFull(pq q){
    pq isFull = malloc(sizeof(struct pqueueType));
    if (isFull == NULL){
        return true;
    }
    free(isFull);
    return false;
}
char *pqToString(pq,char *f(const void*)); // returns a string representation of queue;
