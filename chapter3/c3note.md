# Data Structure
由于计算机是二进制，所以计算机的最小单位是位。数据类型使得可以特定数目的位构成集合。使用指针可以间接使用这些信息。在C语言中，数据都是由以下三种数据类型组成：
* 整数
* 浮点数
* 字符
## Arrary
最基本的数据结构就是数组，一个数组是一组相同类型数据的固定集合。他们的存储空间相邻，可以通过索引访问。
## Link
当我们按照顺序一个一个访问集合中的每个数据项时，可以将数据项组织为链表（LINK LIST）。  
链表相较于数组的优势在于 **高效重排数据项的能力**  
### 链表的基本结构
通常我们使用结构体表示节点，使用指针表示链接：
```
typedef struct node *plink;
typedef struct node link;
typedef int itemtype;
struct node {
    itemtype item;
    plink next;
};
```
此外，链表的常见操作有**链表的插入和链表的删除**。
### 链表的常用用法
如下给出了链表的5种常规用法，以下方法种，我们都使用head引用链表，
1. 循环链表 
* 头指针 `head->next =head; `
* 插入 `t->next=x->next;x->next=t;`
* 删除 `t=x->next;x->next=x->next->next;free(t);`
* 遍历循环 `t=head; do{... t=t->next;}while(t!=head)`
* 测试是否只有一个元素 `if(head->next == head)`
2. 单向链表 无头节点
* 头指针 `head = NULL`
* 插入 
```
if(x == NULL)
    {
        head = t;
        head->next =NULL;
    }
else
    {
        t->next=x-next;
        x->next =t;
    }
```
* 删除 `t=x->next;x->next=x->next->next;free(t);`
* 遍历循环 `for(t=head;t!=NULL;t=t->next)`
* 测试非空 `if(head ==NULL)`
3. 单向链表，存在头节点
* 头指针 `head=mallof(sizeof(LINK));head->next =NULL;`
* 插入 `t->next=x->next;x->next=t`
* 删除 `t = x->next;x->next=x->next->next;free(t);`
* 遍历循环 `for(t=head-next;t!=NULL;t=t->next)`
* 测试非空 `if(head->next == NULL)`
4. 单向链表，有头节点和尾节点
* 头指针 `head = malloc(sizeof(LINK));end = malloc(sizeof(LINK));head->next =end;end->next =end;`
* 插入 `t->next=x->next;x->next=t;`
* 删除 `t = x->next;x->next=x->next->next;free(t);`
* 遍历循环 `for(t=head-next;t!=end;t->next)`
* 测试非空 `if(head->next == end)`
### 链表函数接口 API of Link List 
```
void initNodes();
link newNode(int);
void freeNode(link);
void insertNext(link,link);
link deleteNext(link);
```
### **拓展**双向链表
### 链表的内存分配
## String
### 什么是字符串？
通常，字符串代表一个长字符数组。由起始点和一个标志末尾的字符组成。因为许多计算机应用都会涉及对文本数据的处理，字符串通常具有较大的价值。  
### 字符串和字符数组的区别
###字符串的处理操作
```
//计算字符串长度
strlen(a);
for(i=0;a[i]!=0;i++)return i;

b=a;while(*b++);return b-a-1;
//复制字符串
strcpy(a,b);
for(i=0;(a[i]=b[i])!=0;i++)

while(*a++ =*b++);
//比较字符串
strcmp(a,b);
for(i=0;a[i]==b[i];i++)
if(a[i]==0)return 0;
return a[i]-b[i];

while(*a++ =*b++)
if(*(a-1)==0)return 0;
return *(a-1)-*(b-1);
//前缀比较

//追加字符串
strcat(a,b);
strcpy(a+strlen(a),b);
```
