/**
 * 双向链表，实现增删查改操作
 *
 * 双向链表的定义，请参考维基百科
 * https://en.wikipedia.org/wiki/Doubly_linked_list
 *
 * 接口说明：
 *
 * 创建一个链表，内容为 words
 * struct DoubleLinkList* creatList(char* words[], int length);
 *
 * 删除一个链表
 * void destroyList(struct DoubleLinkList* list);
 *
 * 复制一个链表
 * struct DoubleLinkList* cloneList(struct DoubleLinkList* list);
 *
 * 打印一个链表
 * void dumpList(struct DoubleLinkList* list);
 *
 * 删除第 k 个节点
 * void listDelete(struct DoubleLinkList* list, int k);
 *
 * 查找值为 value 的节点，返回节点的位置，找不到返回 -1
 * int listFind(struct DoubleLinkList* list, const char* value);
 *
 * 从头部插入一个节点
 * void listInsertToHead(struct DoubleLinkList* list, const char* value);
 *
 * 从尾部插入一个节点
 * void listInsertToTail(struct DoubleLinkList* list, const char* value);
 *
 * 在第 k 个位置，插入一个值为 value 的节点
 * void listInsert(struct DoubleLinkList* list, int k, const char* value);
 *
 * 将第 k 个位置的节点，更新为 value
 * void listUpdate(struct DoubleLinkList* list, int k, const char* value);
 *
 * 翻转一个链表的顺序
 * void listReverse(struct DoubleLinkList* list);
 *
 * 链表排序，比较规则按字典序
 * void listSort(struct DoubleLinkList* list);
 *
 * 链表排序，比较函数从外部传入
 * void listSortBy(struct DoubleLinkList* list, int(*compare)(node*, node*));
 *
 * 编译：
 * gcc -Wall -g -std=c99 double_link_list.c
 * 
 * 运行：
 * ./a.out
 */

#include <stdio.h>
 #include <stdlib.h>

// typedef struct Node node;

// struct Node {
//     node* prev;
//     node* next;
//     const char* value;
// };

// struct DoubleLinkList {
//     node* head;
//     node* tail;
// };

// struct DoubleLinkList* creatList(char* words[], int length);

// void destroyList(struct DoubleLinkList* list);

// void dumpList(struct DoubleLinkList* list);

// struct DoubleLinkList* cloneList(struct DoubleLinkList* list);

// void listDelete(struct DoubleLinkList* list, int index);

// int listFind(struct DoubleLinkList* list, const char* value);

// void listInsertToHead(struct DoubleLinkList* list, const char* value);

// void listInsertToTail(struct DoubleLinkList* list, const char* value);

// void listInsert(struct DoubleLinkList* list, int index, const char* value);

// void listUpdate(struct DoubleLinkList* list, int index, const char* value);

// void listReverse(struct DoubleLinkList* list);

// void listSort(struct DoubleLinkList* list);

// void listSortBy(struct DoubleLinkList* list, int(*compare)(node*, node*));

// void test_creatList(void);


// void dumpList(struct DoubleLinkList* list) {
//     node* head = list->head->next;
//     while(head != list->tail) {
//         printf("%s -> ", head->value);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// 测试用例：
// 屏幕上打印出: Hello -> world -> and -> my -> friends -> NULL
void test_creatList(void) {
    char* words[] = {"Hello", "world", "and", "my", "friends"};
    int length = 5;
    struct DoubleLinkList* list = creatList(words, length);
    dumpList(list);
}

int main(int argc, char* argv[]) {
    test_creatList();
    return 0;
}

