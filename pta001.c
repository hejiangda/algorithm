#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Merge( List L1, List L2);

int main()
{
	struct Node	L1,L2,l1,l2,l3,l4,l5,l6,l7;
	List L,s1,s2;
  s1=&L1;s2=&L2;
	L1.Data=1;L1.Next=&l1;
	l1.Data=3;l1.Next=&l2;
	l2.Data=5;l2.Next=NULL;
	// l3.Data=7;l3.Next=NULL;

	L2.Data=2;L2.Next=&l4;
	l4.Data=4;l4.Next=&l5;
	l5.Data=6;l5.Next=&l6;
	l6.Data=8;l6.Next=&l7;
  l7.Data=10;l7.Next=NULL;
	L=Merge(s1,s2);

//   L=s1;

	while(L)
	{
		printf("%d ",L->Data);
		L=L->Next;
	}
}


List Merge(List L1,List L2){
    List L = (List)malloc(sizeof(List));
    List ll = L;
    List l1 = L1 -> Next,l2 = L2 -> Next;
    
    while (l1 && l2 ) {
        if (l1 -> Data < l2 -> Data) {
            ll -> Next = l1;
            ll = l1;
            l1 = l1 -> Next;
        }else{
            ll -> Next = l2;
            ll = l2;
            l2 = l2 -> Next;
        }
    }
    
    if (l1 && !l2) {
        ll -> Next = l1;
    }else if(!l1 && l2){
        ll -> Next = l2;
    }
    L1 -> Next = NULL;
    L2 -> Next = NULL;
    
    return L;
}
