#include<stdio.h>
#include<stdlib.h>
struct node{
	int c;
	int e;
	struct node* next;
}*starta=NULL,*startb=0,*cura=0,*curb=0,*pdt,*startp=0,*nextp,*curp=0,*new_node,*prevp;
int main()
{
		int n,i,tempe,tempc,j,count=0;
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
		}
		else{
			cura->next=new_node;
			cura=new_node;
		}
		
	}
	
	
	
printf("enter the number of terms :");
	scanf("%d",&n);
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
		}
		else{
			curb->next=new_node;
			curb=new_node;
		}
		
	}
	
	
	//operations begin from here...
	//int tempc,tempe;
count=0;
	
	for(cura=starta;cura!=0;cura=cura->next){
		for(curb=startb;curb!=0;curb=curb->next){
			//multiply here...
			//printf("iterated...\n\n\n");
	count++;
			tempc=(cura->c)*(curb->c);
			tempe=(cura->e)+(curb->e);
			if(startp==NULL){
				new_node=(struct node*)malloc(sizeof(struct node));
				
				new_node->c=tempc;
				new_node->e=tempe;
				new_node->next=0;
				startp=new_node;
				curp=new_node;
				//break;
			
			}//first product
			
			else{
			new_node=(struct node*)malloc(sizeof(struct node));
			new_node->c=tempc;
			new_node->e=tempe;
			new_node->next=NULL;
			curp=startp;
			while(curp!=NULL){
			
				int e;
				e=curp->e;
				
				if(curp->e==tempe){
					int temp;
					curp->c=(curp->c)+tempc;
					
					break;
				}
				else {
				
					if(curp->next!=NULL){
						if((curp->next)->e>=new_node->e){
							curp=curp->next;
							
						}
						else{
							new_node->next=curp->next;
							curp->next=new_node;
							count++;
							break;
						}}
					else{
						curp->next=new_node;
						break;
					
					
					}
				}}}
			
		
	}}
	printf("\n\n\n");
	curp=startp;
	while(curp!=0){
		printf("%d(x^%d)",curp->c,curp->e);
	
		curp=curp->next;
	}
	curp=startp;
	
}
