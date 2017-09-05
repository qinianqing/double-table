#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

int main()
{
	struct DListHead *pstPersonList = NULL;
	struct PersonNode *pstNew = NULL;
	struct PersonNode *pstNode = NULL;

	pstPersonList = CreatePersonDlist();
	
	pstNew = CreatePersonNode("XiaoPiao","22222222");

	InsertNodeAtFirst(pstPersonList,pstNew);

	pstNew = CreatePersonNode("LaoTe","5555555");

	InsertNodeAtFirst(pstPersonList,pstNew);

	pstNew = CreatePersonNode("XiaoQiang","123465");

	InsertNodeAtFirst(pstPersonList,pstNew);

	pstNode = SearchANodeByName(pstPersonList,"LaoTe");
	if(pstNode != NULL)
	{
		printf("The phone number of %s:%s\n",pstNode->name,pstNode->phone);
	}
	else
	{
		printf("We did not find the node\n");
	}

	pstNode = RemoveLastNode(pstPersonList);
	if(pstNode != NULL)
	{
		printf("The node named %s has been removed\n",pstNode->name);
	}
	
	DestroyPersonNode(pstNode);	
	
	PrintAllNode(pstPersonList);


	DestroyPersonDList(pstPersonList);
	return 0;
}
