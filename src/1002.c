
#include <stdio.h>
typedef struct dialTable{
	//链表
	struct dial{
		char phone[10];
		struct dial * next;
	} dial;
	//表长
	int length;

}dialTable;


int main(void){
	printf("Nihao ");

}
