#include<stdio.h>
#include<stdlib.h>
struct node{
	int c;
	int e;
	struct node* next;
}*cura,*curb,*starta=NULL,*startb=NULL,*new_node,*curs,*starts=NULL,*temp,*curt;

int main()
{
		int n,i,tempe,tempc,j,count1=0;
		int count2=0;
	printf("enter the number of terms :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("enter the coefficient :");
		scanf("%d",&new_node->c);
		printf("enter the exponent :");
		scanf("%d",&new_node->e);
		new_node->next=NULL;
		if(starta==NULL){
			starta=new_node;
			cura=new_node;
			count1++;
		}
		else{
			cura->next=new_node;
			cura=new_node;
			count1++;
		}
		
	}
	printf("\nEntered polinomial one is :");
cura=starta;
while(cura!=NULL){
	printf("%d(X^%d)",cura->c,cura->e);
	cura=cura->next;
}
	//filter one here...
	
	
		for(i=0;i<count1;i++){
		cura=starta;
		do{
		//	printf("in while\n");
			
			if(cura->next!=NULL){
		//		printf("in primary\n");
				if((cura->next)->e>cura->e){
					tempe=cura->e;
					tempc=cura->c;
					cura->c=(cura->next)->c;
					cura->e=(cura->next)->e;
					(cura->next)->e=tempe;
					(cura->next)->c=tempc;
		//			printf("in if\n");
				}
				else{
					cura=cura->next;
		//			printf("in else\n");
				}
			}
		}while(cura->next!=NULL);
	
		}
		
		printf("\nsorted polinomial one is  :");
cura=starta;
while(cura!=NULL){
	printf("%d(X^%d)",cura->c,cura->e);
	cura=cura->next;
}
	
	
printf("\nenter the number of terms :");
	scanf("%d",&n);
	count2=0;
	for(i=0;i<n;i++){
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("enter the coefficient :");
		scanf("%d",&new_node->c);
		printf("enter the exponent :");
		scanf("%d",&new_node->e);
		new_node->next=NULL;
		if(startb==NULL){
			startb=new_node;
			curb=new_node;
			count2++;
		}
		else{
			curb->next=new_node;
			curb=new_node;
			count2++;
		}
		
	}
	printf("\nEntered polinomial two is :");
curb=startb;
while(curb!=NULL){
	printf("%d(X^%d)",curb->c,curb->e);
	curb=curb->next;
}

	for(i=0;i<count2;i++){
		curb=startb;
		do{
		//	printf("in while\n");
			
			if(curb->next!=NULL){
		//		printf("in primary\n");
				if((curb->next)->e>curb->e){
					tempe=curb->e;
					tempc=curb->c;
					curb->c=(curb->next)->c;
					curb->e=(curb->next)->e;
					(curb->next)->e=tempe;
					(curb->next)->c=tempc;
		//			printf("in if\n");
				}
				else{
					curb=curb->next;
		//			printf("in else\n");
				}
			}
		}while(curb->next!=NULL);
	
		}
		
		printf("\nsorted polinomial two is :");
curb=startb;
while(curb!=NULL){
	printf("%d(X^%d)",curb->c,curb->e);
	curb=curb->next;
}

//addition starts here...

cura=starta;
curb=startb;
int count3=0;
while(cura!=NULL && curb!=NULL){
	if(cura->e==curb->e){
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->c=(cura->c)+(curb->c);
		new_node->e=cura->e;
		new_node->next=NULL;
		count3++;
		if(starts==NULL){
			starts=new_node;
			curs=new_node;
			cura=cura->next;
			curb=curb->next;
		}
		else{
			curs->next=new_node;
			curs=new_node;
			cura=cura->next;
			curb=curb->next;
		}
	}
	else if(cura->e > curb->e){
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->c=(cura->c);
		new_node->e=cura->e;
		new_node->next=NULL;
		count3++;
		if(starts==NULL){
			starts=new_node;
			curs=new_node;
			cura=cura->next;
		}
		else{
			curs->next=new_node;
			curs=new_node;
			cura=cura->next;
		}
		
	}
	else{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->c=(curb->c);
		new_node->e=curb->e;
		new_node->next=NULL;
		count3++;
		if(starts==NULL){
			starts=new_node;
			curs=new_node;
			curb=curb->next;
		}
		else{
			curs->next=new_node;
			curs=new_node;
			curb=curb->next;
		}
	}
}


while(cura!=NULL){
	count3++;
	//printf("remainders present...");
	curs->next=cura;
	curs=cura;
	cura=cura->next;
}


while(curb!=NULL){
	count3++;
	//printf("remainders present...");
	curs->next=curb;
	curs=curb;
	curb=curb->next;
}

printf("\nthe resultant is :");
curs=starts;
while(curs!=NULL){
	printf("%d(X^%d)",curs->c,curs->e);
	curs=curs->next;
}




	for(i=0;i<count3;i++){
		curs=starts;
		do{
		//	printf("in while\n");
			
			if(curs->next!=NULL){
		//		printf("in primary\n");
				if((curs->next)->e>curs->e){
					tempe=curs->e;
					tempc=curs->c;
					curs->c=(curs->next)->c;
					curs->e=(curs->next)->e;
					(curs->next)->e=tempe;
					(curs->next)->c=tempc;
		//			printf("in if\n");
				}
				else{
					curs=curs->next;
		//			printf("in else\n");
				}
			}
		}while(curs->next!=NULL);
	
		}
	



printf("\nthe sorted resultant is :");
curs=starts;
while(curs!=NULL){
	printf("%d(X^%d)",curs->c,curs->e);
	curs=curs->next;
}










}
