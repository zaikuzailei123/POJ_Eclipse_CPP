#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNA{
	char * SQ;
	int value;
	struct DNA * next;
}DNA;


int countValue(char * str,int length){
	char * cur;char * p;int value = 0;
	for(cur = str;(*cur)!='\0';cur++){
		p = cur;
		while(*p !='\0'){
			if(*p < *cur) value++;
			p = p+1;
		}
	}
	return (value);
}


int main(){
	int length;int num;
	DNA * head = (DNA*)malloc(sizeof(DNA));
	head->SQ = NULL;head->value = 0;head->next = NULL;

	scanf("%d%d",&length,&num);getchar();
	char SQs[num][length+1];

	DNA * cur = head;
	for(int i = 0;i<num;i++){
		gets(SQs[i]);
		cur->next = (DNA* )malloc(sizeof(DNA));
		cur->next->SQ = SQs[i];

		//计算SQ的value值
		cur->next->value = countValue(SQs[i], length);
		cur->next->next = NULL;
		cur = cur->next;
	}
	DNA * L = head;DNA * M;DNA * R;
	for(int i = 1;i<num;i++){
		for(L = head,M = L->next,R = M->next;R!=NULL && L!=NULL;L = L->next,M = L->next,R = M->next){
			if(M->value > R->value){
				//交换节点
				L->next = R;
				M->next = R->next;
				R->next = M;

				//将LRM归位
				M = L->next;R = M->next;
			}
		}
	}
	cur = head->next;
	free(head);DNA * ff;
	while(cur!=NULL){
		printf("%s\n",cur->SQ);
		ff = cur;
		cur = cur->next;
		free(ff);
	}
	return 0;
}




