#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

int main()
{
	struct DListHead *pstPersonList = NULL;
	struct PersonNode *pstNew = NULL;
        struct PersonNode *pstNode=NULL;
	pstPersonList = CreatePersonDlist();
	
	pstNew = CreatePersonNode("XiaoPiao","22222222");

	InsertNodeAtFirst(pstPersonList,pstNew);

	pstNew = CreatePersonNode("LaoTe","5555555");

	InsertNodeAtFirst(pstPersonList,pstNew);
	pstNode=pstRemoveLastNode(pstPersonList);

	PrintAllNode(pstPersonList);


	DestroyPersonDList(pstPersonList);
	return 0;
}
