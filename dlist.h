#ifndef D_LIST_H
#define D_LIST_H

#define NAME_LEN 20
#define PHONE_LEN 20
struct PersonNode
{
	/*Data field*/
	char name[NAME_LEN];
	char phone[PHONE_LEN];

	/*Address field*/
	struct PersonNode *pstNext;
	struct PersonNode *pstPrev;
};

struct DListHead
{
	int count;
	
	/*Address Field*/
	struct PersonNode *pstFirst;
};

/*创建一个空的双向链表，给头节点分配内存空间*/
struct DListHead * CreatePersonDlist();

/*销毁整个双向链表,包括头节点一起销毁*/
int DestroyPersonDList(struct DListHead *pstHead);

/*创建一个新的节点*/
struct PersonNode *CreatePersonNode(char *name,char *phone);

/*销毁一个节点*/
int DestroyPersonNode(struct PersonNode *pstNode);

/*在指定节点后插入新节点*/
int InsertNodeAfterANode(struct DListHead *pstHead,
                     struct PersonNode *pstNode,
                     struct PersonNode *pstNew);

/*在指定节点前插入新节点*/
int InsertNodeBeforeANode(struct DListHead *pstHead,
                     struct PersonNode *pstNode,
                     struct PersonNode *pstNew);

/*在链表尾部插入新节点*/
int InsertNodeAtTail(struct DListHead *pstHead,struct PersonNode *pstNew);

/*在链表第一个位置插入新节点*/
int InsertNodeAtFirst(struct DListHead *pstHead,struct PersonNode *pstNew);

/*通过人名查找节点*/
struct PersonNode *SearchANodeByName(struct DListHead *pstHead,char *name);

/*通过电话号码查找节点*/
struct PersonNode *SearchANodeByPhone(struct DListHead *pstHead,char *phone);

/*移除最后一个节点*/
struct PersonNode *RemoveLastNode(struct DListHead *pstHead);

/*移除第一个节点*/
struct PersonNode *RemoveFirstNode(struct DListHead *pstHead);

/*已知节点地址，移除该节点*/
int RemoveANode(struct DListHead *pstHead,struct PersonNode *pstNode);

/*已知节点地址，移除该节点下一个节点*/
int RemoveANextNode(struct DListHead *pstHead,struct PersonNode *pstNode);

/*打印所有节点*/
int PrintAllNode(struct DListHead *pstHead);
#endif
