#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

/*创建一个空的双向链表，给头节点分配内存空间*/
struct DListHead * CreatePersonDlist()
{
	struct DListHead *pstHead = NULL;

	pstHead = (struct DListHead *)malloc(sizeof(struct DListHead));
	if(NULL == pstHead)
	{
		printf("Malloc Failed in %s at %d\n",__FILE__,__LINE__);
		return NULL;
	}
	memset(pstHead,0,sizeof(struct DListHead));
	
	return pstHead;
}

/*销毁整个双向链表,包括头节点一起销毁*/
int DestroyPersonDList(struct DListHead *pstHead)
{
	struct PersonNode *pstNode = NULL;
	struct PersonNode *pstNext = NULL;
	
	/*检查输入参数是否合法*/
	if(NULL == pstHead)
	{
		printf("Input Param is invalid in %s:%d\n",__FILE__,__LINE__);
		return -1;
	}

	/*销毁所有节点*/
	pstNode = pstHead->pstFirst;
	while(pstNode != NULL)
	{
		pstNext = pstNode->pstNext;
		DestroyPersonNode(pstNode);
		pstNode = pstNext;
	}

	/*销毁头节点*/
	free(pstHead);
	return 0;
}

/*创建一个新的节点*/
struct PersonNode *CreatePersonNode(char *name,char *phone)
{
	struct PersonNode *pstNode = NULL;

	pstNode = (struct PersonNode *)malloc(sizeof(struct PersonNode));
	if(NULL == pstNode)
	{
		printf("Malloc Failed in %s:%d\n",__FILE__,__LINE__);
		return NULL;
	}
	memset(pstNode,0,sizeof(struct PersonNode));

	//pstNode->name = name;错误写法 
	if(name != NULL)
	{
		strncpy(pstNode->name,name,NAME_LEN - 1);
	}
	if(phone != NULL)
	{
		strncpy(pstNode->phone,phone,PHONE_LEN - 1);
	}

	return pstNode;
}

/*销毁一个节点*/
int DestroyPersonNode(struct PersonNode *pstNode)
{
	if(pstNode != NULL)
	{
		free(pstNode);
	}
	return 0;
}

/*在链表第一个位置插入新节点*/
int InsertNodeAtFirst(struct DListHead *pstHead,struct PersonNode *pstNew)
{
	if(NULL == pstHead || NULL ==  pstNew)
	{
		printf("Input Param is invalidi in %s:%d\n",__FILE__,__LINE__);
		return -1;
	}

	pstNew->pstNext = pstHead->pstFirst;
	pstNew->pstPrev = NULL;

	if(pstHead->pstFirst != NULL)
	{
		pstHead->pstFirst->pstPrev = pstNew;
	}

	pstHead->pstFirst = pstNew;
	pstHead->count++;
	return 0;
}

struct PersonNode *SearchANodeByName(struct DListHead *pstHead,char *name)
{
	struct PersonNode *pstNode = NULL;
	if(NULL == pstHead || NULL == name)
	{
		printf("Input Param is invalid in %s:%d\n",__FILE__,__LINE__);
		return NULL;
	}

	pstNode = pstHead->pstFirst;
	while(pstNode != NULL)
	{
		if(0 == strcmp(name,pstNode->name))
		{
			break;
		}
		pstNode = pstNode->pstNext;
	}
	
	return pstNode;
}

struct PersonNode *SearchANodeByPhone(struct DListHead *pstHead,char *phone)
{
	struct PersonNode *pstNode = NULL;
	if(NULL == pstHead || NULL == phone)
	{
		printf("Input Param is invalid in %s:%d\n",__FILE__,__LINE__);
		return NULL;
	}

	pstNode = pstHead->pstFirst;
	while(pstNode != NULL)
	{
		if(0 == strcmp(phone,pstNode->phone))
		{
			break;
		}
		pstNode = pstNode->pstNext;
	}
	
	return pstNode;
}
struct PersonNode *RemoveLastNode(struct DListHead *pstHead)
{
	struct PersonNode *pstLast = NULL;
	if(NULL == pstHead)
	{
		printf("Input Parameter is invalid in %s:%d\n",__FILE__,__LINE__);
		return NULL;
	}

	pstLast = pstHead->pstFirst;
	while(pstLast != NULL)
	{
		if(pstLast->pstNext == NULL)
		{
			break;
		}
		else
		{
			pstLast = pstLast->pstNext;
		}
	}

	if(pstLast != NULL)
	{
		if(pstLast->pstPrev != NULL)
		{
			pstLast->pstPrev->pstNext = NULL;
		}
		else
		{
			pstHead->pstFirst = NULL;
		}
	
		pstLast->pstPrev = NULL;
	}

	return pstLast;
}

/*打印所有节点*/
int PrintAllNode(struct DListHead *pstHead)
{
	struct PersonNode *pstNode = NULL;

	if(NULL == pstHead)
	{
		printf("Input Param is invalidi in %s:%d\n",__FILE__,__LINE__);
		return -1;
	}
	
	pstNode = pstHead->pstFirst;
	while(pstNode != NULL)
	{
		printf("Name:%s Phone:%s\n",pstNode->name,pstNode->phone);
		pstNode = pstNode->pstNext;
	}
	
	return 0;
}
