#ifndef _List_H

struct node;
typedef struct node *ptrtonode;
typedef struct ptrtonode list;
typedef struct ptrtonode position;

int IsLast(position p,list l);
position Find(position p);
void Delete(int x,list l);
position FindPrevious(int x,list l);
void Insert(int x,list l,position p);
void DeleteList(list l);
position GoToPosition(list l,int pos);
#endif