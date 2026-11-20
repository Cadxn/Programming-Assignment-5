#include "gllist.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

gllist createGLlist() {
return NULL;
}
gllist InsertAtFront(gllist head, ListItem n) {
    gllist newNode;
    
    newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = n;
    newNode ->next = head;
    return newNode;
}

gllist InsertAtEnd(gllist head, ListItem n){
    gllist newNode;
    gllist ptr = head;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = n;
    newNode -> next = NULL;
    if (head==NULL)
        return newNode;
    while (ptr->next!=NULL)
        ptr = ptr->next;
    ptr -> next = newNode;
    return head;
}
gllist removeAtFront(gllist l){
if(l != NULL){
    gllist t = l;
    l = l->next;
    free(t);
    }
return l;
}
int RemoveANode(gllist *hhead, ListItem n) {
    gllist ptr = *hhead;
    gllist pre = NULL;
    if ((ptr == NULL)|| (hhead==NULL))
        return 0;
    
    while (ptr!=NULL){
        if (ptr->data == n) {
            //to be deleted node "n"
            if (ptr==*hhead) {
                *hhead = (*hhead)->next;
            }
            else {
                pre-> next = ptr -> next;
            }
            free(ptr);
            return 1;

        }
        
        pre = ptr;
        ptr = ptr -> next;
    }
    
    return 0;
}

gllist ReverseLinklist(gllist head) {
    gllist tptr,cur,pre;
    pre = NULL;
    tptr = NULL;
    cur = head;
    while (cur!=NULL) {
        tptr = pre;
        pre = cur;
        cur = cur->next;
        pre->next = tptr;
    }
    return pre;
}

void ReverseLinklist2(gllist *hhead) {
    gllist tptr,cur,pre;
    pre = NULL;
    tptr = NULL;
    cur = *hhead;
    while (cur!=NULL) {
        tptr = pre;
        pre = cur;
        cur = cur->next;
        pre->next = tptr;
    }
    *hhead = pre;
}
ListItem get(gllist l, int p){
    if(p < 0){
        return NULL;
    }
    for(int i = 0; i < p && l != NULL; i++){
        l = l->next;
    }
    if(l == NULL){
        return NULL;
    }
    return l->data;
}
gllist add(gllist l, ListItem item, int pos){
    if(pos < 0){
        printf("Error: Position is negative\n");
        return l;
    }

    gllist t = malloc(sizeof(struct Node));
    t->data = item;
    gllist temp = l;

    if(l == NULL || pos == 0){
        //printf("Adding %d at position %d\n", n, pos);
        t->next = l;
        return t;
    }

    for (int i = 0; i < pos - 1; i++){
        if(temp->next == NULL){
        //printf("Adding %d at position %d\n", n, pos);
            t->next = NULL;
            temp->next = t;
            return l;
        }
    temp = temp->next;
    }
    t->next = temp->next;
    temp->next = t;
    return l;
}
int size(gllist l){
    int count = 0;
    while(l != NULL){
        count++;
        l = l->next;
    }
    return count;
}
bool isEmpty(gllist l){
    return l == NULL;
}