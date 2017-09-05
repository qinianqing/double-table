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

/*自己写的在链表最后插入节点*/成功
/*int InsertNodeAtTail(struct DListHead *pstHead,struct PersonNode *pstNew)
{
	if(NULL == pstHead || NULL ==  pstNew)
	{
		printf("Input Param is invalidi in %s:%d\n",__FILE__,__LINE__);
		return -1;
	}
	pstNew->pstNext=NULL;
       if(pstHead->pstFirst!=NULL)
	{
		struct PersonNode *pstTail =NULL;
		pstTail=pstHead->pstFirst;
		if(pstTail->pstNext!=NULL)
		{
			pstTail=pstTail->pstNext;
		}
			pstTail->pstNext=pstNew;
			pstNew->pstPrev=pstTail;
			
	}
	else
	{	
		pstHead->pstFirst=pstNew;
		
		
		pstNew->pstPrev=NULL;
	}
	return 0;
}*/
/*尾插*/
struct PersonNode *InsertNodeAtTail(struct DListHead * pstHead ,struct PersonNode *pstNew)
{
	struct PersonNode * pstTail=NULL;
	pstTail=pstHead->pstFirst;
	while(pstTail!=NULL)
	{	
		if(pstTail->pstNext==NULL)
		{
			break;
		}
		else
		{
			pstTail=pstTail->pstNext;
		}
	}
	if(pstTail!=NULL)
	{	
			pstTail->pstNext=pstNew;
			pstNew->pstNew=NULL;
			pstTail->pstNext->pstPrev=pstTail;
	}
	else
	{
		pstHead->pstFirst=pstNew;
		pstNew->pstPrev=NULL;
		pstNew->pstNext=NULL;
	}
	return pstTail;
}
/*自己写的移除最后一个节点*/

/*struct PersonNode *RemoveLastNode(struct DListHead *pstHead)
{
	struct PersonNode *pstTail = NULL;
	pstTail=pstHead->pstFirst;
	if(NULL == pstHead || NULL ==  pstHead->pstFirst)
	{
		printf("Input Param is invalidi in %s:%d\n",__FILE__,__LINE__);
		return 	NULL;
	}
	while(pstHead->pstFirst!=NULL)
	{	
           if(pstTail->pstNext!=NULL)
           {
               // if(pstTail->pstNext!=NULL)
                //{
                  //      pstTail=pstTail->pstNext;
                //}
                //else
                //{
                  //      pstTail->pstPrev->pstNext=NULL;
                   //     pstTail->pstPrev=NULL;
                //}
		for(;pstTail->pstNext!=NULL; pstTail=pstTail->pstNext);
			pstTail->pstPrev->pstNext=NULL;
                     pstTail->pstPrev=NULL;
			
           }
           else
           {
                pstTail->pstPrev=NULL;
                pstHead->pstFirst=NULL;
           }

	}
	return pstTail;
}*/
/* 自己写的移除第一个节点*/
struct PersonNode *RemoveFirstNode(struct DListHead *pstHead)
{
	struct PersonNode *pstNode = NULL;
	if(NULL == pstHead)
	{
		printf("Input Parameter is invalid in %s:%d\n",__FILE__,__LINE__);
		return NULL;
	}

	pstNode=pstHead->pstFirst;
	if(pstNode!=NULL)
	{	
		if(pstNode->pstNext!=NULL)
		{
			pstHead->pstFirst=pstNode->pstNext;
			pstNode->pstNext->pstPrev=NULL;
		}
		else
		{	
			pstHead->pstFirst=NULL;
		}
	}
	return pstNode;
	
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
/*在指定节点后插入新节点*/
int InsertNodeAfterANode(struct DListHead *pstHead,
                     struct PersonNode *pstNode,
                     struct PersonNode *pstNew)
{
	if(NULL == pstHead || NULL ==  pstNew||NULL==pstNode)
	{
		printf("Input Param is invalidi in %s:%d\n",__FILE__,__LINE__);
		return -1;
	}
//	struct PersonNode pstNode=SearchANodeByName(pstHead,name);
	if(pstNode->pstNext!=NULL)
	{
		pstNew->pstNext=pstNode->pstNext;
		//pstNode->pstNext=pstNew;
		pstNode->pstNext->pstPrev=pstNew;
		pstNode->pstNext=pstNew;
		pstNew->pstPrev=pstNode;
	}	
	else
	{
		pstNew->pstNest=NULL;
		pstNode->pstNext=pstNew;
		pstNew->pstPrev=pstNode;
	}
	return 0;
	
}
/*在指定节点前插入新节点*/
int InsertNodeBeforeANode(struct DListHead *pstHead,
                     struct PersonNode *pstNode,
                     struct PersonNode *pstNew)
{

	if(NULL == pstHead || NULL ==  pstNew||NULL==pstNode)
	{
		printf("Input Param is invalidi in %s:%d\n",__FILE__,__LINE__);
		return -1;
	}
	if(pstNode->pstPrev!=NULL)
	{
		pstNode->pstPrev->pstNext=pstNew;
		pstNew->pstPrev=pstNode->pstPrev;
		pstNew->pstNext=pstNode;
		pstNode->pstPrev=pstNew;
	}
	else
	{
		
		pstHead->pstFirst->pstPrev=pstNew;
		pstHead->pstFirst=pstNew;
		pstNew->pstPrev=NULL;
		pstNew->pstNext=pstNode;
	}
	return 0;
}
	
/*已知节点地址，移除该节点*/
int RemoveANode(struct DListHead *pstHead,struct PersonNode *pstNode)
{
	if(NULL == pstHead || NULL==pstNode)
	{
		printf("Input Param is invalidi in %s:%d\n",__FILE__,__LINE__);
		return -1;
	}
	if(pstNode->pstPrev!=NULL)
	{
		if(pstNode->pstNext!=NULL)
		{
			pstNode->pstPrev->pstNext=pstNode->pstNext;
			pstNode->pstNext->pstPrev=pstNode->pstPrev;
		}
		else
		{
			pstNode->pstPrev->pstNext=NULL;	
		}
	}
	else
	{
		if(pstNode->pstNext!=NULL)
		{
			pstHead->pstFirst=pstNode->pstNext;
			pstNode->pstNext->pstPrev=NULL;
		}
		else
		{
			pstHead->pstFirst=NULL;
		}
	}
	pstNode->pstNext=NULL;
	pstNode->pstPrev=NULL;
	return 0;
}

/*已知节点地址，移除该节点下一个节点*/
int RemoveANextNode(struct DListHead *pstHead,struct PersonNode *pstNode)
{
	if(NULL == pstHead || NULL==pstNode)
	{
		printf("Input Param is invalidi in %s:%d\n",__FILE__,__LINE__);
		return -1;
	}
	struct PersonNode * pstNodeNext=NULL;
	pstNodeNext=pstNode->pstNext;
	if(pstNode->pstNext!=NULL)
	{
		if(pstNodeNext->pstNext!=NULL)
		{
			pstNode->pstNext=pstNodeNext->pstNext;
			pstNodeNext->pstNext->pstPrev=pstNodeNext->pstPrev;
		}
		else
		{	
			pstNode->pstNext=NULL;
		}
	}
	else
	{
		printf("The pstNode Next is NULL");
	}
	return 0;
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
