#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int num;
	char name[10];
	int password;
	struct node *next;	
} LNode;
typedef struct node *Linklist;

Linklist Init(){
	Linklist list;
	list = (Linklist)malloc(sizeof(LNode));
	return list;
} 
void Add(int n,Linklist list){	
	int i;
	Linklist p = list;
	for(i = 1;i <= n;i++){
		scanf("%d,%[^,],%d",&p->num,p->name,&p->password);
		p->next = (Linklist)malloc(sizeof(LNode));
		if(i == n)
			p->next = list;
		else
			p = p->next;			
	} 	
} 
void Search(Linklist list,int m,int n){
	Linklist p = list;
	Linklist q ;
	int i;
	while(n != 0){
			
	 		for(i = 1;i < m;i++){	
				q = p;
				p = p->next;
			}
			m = p->password;
			printf("%d,%s,%d\n",p->num,p->name,p->password);
			q->next = p->next;
			p = p->next;	
			n--;		
	} 		
} 
int main(){
	int n,m;
	scanf("%d",&n);
	
	Linklist list = Init();
	
	Add(n,list);
	
	scanf("%d",&m);

	Search(list,m,n);
	
	return 0;
}
