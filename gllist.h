#ifndef GLLIST_H
#define GLLIST_H

typedef void *ListItem;

struct Node {
    ListItem data;
    struct Node * next;
};

typedef struct Node *gllist;

gllist createGLlist();
gllist InsertAtFront(gllist head, ListItem n);
gllist InsertAtEnd(gllist head, ListItem n);
gllist removeAtFront(gllist l);
int RemoveANode(gllist *hhead, ListItem n);
gllist ReverseLinklist(gllist head);
void ReverseLinklist2(gllist *hhead);
ListItem get(gllist l, int p);
gllist add(gllist l, ListItem item, int pos);
int size(gllist l);
bool isEmpty(gllist l);
#endif
