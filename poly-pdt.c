//polinomial multiplication using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int c;
	int e;
	struct node* next;
}*starta=NULL,*startb=0,*cura=0,*curb=0,*pdt,*startp=0,*nextp,*curp=0,*new_node,*prevp;
int main()
{
	int op;
	int count=0;
	printf("enter the number of terms in eqtn 1 :");
	scanf("%d",&op);
	cura=starta;
	while(count<op){
		if(cura==0){
			new_node=(struct node*)malloc(sizeof(node));
			scanf("%d",&new_node->c);
			scanf("%d",&new_node->e);
			new_node->next=NULL;
			starta=new_node;
			cura=starta;
			count++;
		}
		else{
			new_node=(struct node*)malloc(sizeof(node));
			scanf("%d",&new_node->c);
			scanf("%d",&new_node->e);
			cura->next=new_node;
			cura=new_node;
			count++;
		}
	}
	cura->next=0;
//linked list one inserted...
   count=0;

	printf("enter the number of terms in eqtn 2 :");
	scanf("%d",&op);
	curb=startb;
	while(count<op){
		if(curb==0){
			new_node=(struct node*)malloc(sizeof(node));
			scanf("%d",&new_node->c);
			scanf("%d",&new_node->e);
			new_node->next=NULL;
			startb=new_node;
			curb=startb;
			count++;
		}
		else{
			new_node=(struct node*)malloc(sizeof(node));
			scanf("%d",&new_node->c);
			scanf("%d",&new_node->e);
			curb->next=new_node;
			curb=new_node;
			count++;
		}
	}
	curb->next=0;
	//testing printing froh here...
	printf("the first polinomial is : ");
	cura=starta;
	while(cura!=0){
	
	printf("%d(X^%d)+",cura->c,cura->e);
	cura=cura->next;
}


	printf("the second polinomial is : ");
	curb=startb;
	while(curb!=0){
	
	printf("%d(X^%d)+",curb->c,curb->e);
	curb=curb->next;
}
	
	
	//operations begin from here...
	int tempc,tempe;
count=0;
	
	for(cura=starta;cura!=0;cura=cura->next){
		for(curb=startb;curb!=0;curb=curb->next){
			//multiply here...
			//printf("iterated...\n\n\n");
	count++;
			tempc=(cura->c)*(curb->c);
			tempe=(cura->e)+(curb->e);
			if(curp==NULL){
				new_node=(struct node*)malloc(sizeof(node));
				
				new_node->c=tempc;
				new_node->e=tempe;
				new_node->next=0;
				startp=new_node;
				curp=new_node;
				//break;
				printf("start added\n");
			}//first product
			
			
			else{
				printf("entered.......");
				new_node=(struct node*)malloc(sizeof(node));
				new_node->c=tempc;
				new_node->e=tempe;
				new_node->next=NULL;
				curp=startp;
				while(curp!=NULL){
					if(curp->e==tempe){
						curp->c=curp->c+tempc;
						break;
					}
					else{
						curp=curp->next;
					}
					curp=startp;
					while(curp=NULL){
						if(curp->e>tempe){
							if((curp->next)->e>tempe){
								//prep=curp;
								curp=curp->next;
							}
							else{
								new_node->next=curp->next;
								curp->next=new_node;
							}}
						else if((curp->e)<tempe){
								if(prevp==NULL){
								new_node->next=curp;
								startp=new_node;	
								}
								else{
									new_node->next=curp;
									prevp->next=new_node;
								}}
						else{
								prevp=curp;
								curp=curp->next;
							}
							}
						}
					}
				}
			}
		
		curp=startp;
		while(curp!=NULL){
			printf("%d(X^%d)",curp->c,curp->e);
			curp=curp->next;
		}
	}
         /* else{
          	new_node=(struct node*)malloc(sizeof(node));
          	
          	  curp=startp;
          	while(curp!=NULL){
          		if(curp->e==tempe){
          			curp->c=curp->c+tempc;
          			break;
				  }
				else{
					curp=curp->next;
				}}
				curp=startp;
				while(curp!=NULL){
					if(nextp!=NULL){
						if(curp->e>tempe){
							if(nextp->e>tempe){
								curp=nextp;
								nextp=nextp->next;
							}
							else{
								new_node->next=nextp;
								curp->next=new_node;
						}}
						else{
							if(prevp==NULL){
								new_node->next=curp;
								startp=new_node;
							}
							else{
								new_node->next=curp;
								prevp->next=new_node;
							}
						}
						}
					
					else{
						curp->next=new_node;
						new_node->next=NULL;
					}
				}
					printf("program ended...");
		curp=startp;
		do{
			printf("%d(X^%d)",curp->c,curp->e);
			curp=curp->next;
		}while(curp->next!=NULL);
		printf("executed %d times",count);
			  }
          	
          	
          	
          	
          	
          	
          	
          	
          	
          	
          	
          	
          	
          	
          	
          	
          	
		  }		
	}
}

		/*	else{
				new_node=(struct node*)malloc(sizeof(node));
				new_node->e=tempe;
				new_node->c=tempc;
				prevp=NULL;
				curp=startp;
				do{
					printf("in while...\n");
					if((new_node->e)>(curp->e)){
						new_node->next=curp;
						if(prevp!=NULL){
							printf("in if");
							prevp->next=new_node;
							curp=startp;
							prevp=NULL;
							printf("greater\n");
						}
						else{
							printf("in else...");
							startp=new_node;
							curp=startp;
							prevp=NULL;
						}
						//break;
					}
					else if((new_node->e)<(curp->e)){
						if(curp->next!=NULL){
							prevp=curp;
							curp=curp->next;
							new_node->next=curp;
							prevp->next=curp;
							curp=startp;
							prevp=NULL;
							printf("less than -if\n");
						}
						else{
							curp->next=new_node;
							new_node->next=NULL;
							curp=startp;
							prevp=NULL;
							
						
					}break;}
					else if(new_node->e==curp->e){
						curp->c=(curp->c)+(new_node->c);
						curp=startp;
							prevp=NULL;
							printf("equals\n");
						//	break;
						
					}
					else{
						prevp=curp;
						curp=curp->next;
						//break;
						printf("whiled...\n");
						
					}
				}while(curp->next!=NULL);
				
				
				
			}
			
			
			
			
			
			
		
		}
		}
		
		
		printf("program ended...");
		curp=startp;
		do{
			printf("%d(X^%d)",curp->c,curp->e);
			curp=curp->next;
		}while(curp->next!=NULL);
		printf("executed %d times",count);
		}
		
		
		
		
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		/*	else{
				new_node->c=tempc;
				new_node->e=tempe;
				curp=startp;
				while(curp!=0){
					if(curp->next!=0){
						if(curp->e<tempe<(curp->next)->e){
							new_node->next=curp->next;
							curp->next=new_node;
						}
						else{
							curp->next=new_node;
							new_node->next=0;
						}
					}
				}
			}
			
	}}}
			
		/*	else{
				
				new_node=(struct node*)malloc(sizeof(node));
				new_node->c=tempc;
				new_node->e=tempe;
				printf("came here\n");
				
				curp=startp;
				while(curp!=0){
					prevp=curp;
					//curp=curp->next;
					if(new_node->e<curp->e){
						printf("came here\n");
						new_node->next=curp;
						prevp->next=new_node;
						while(curp->next!=0){
						
						prevp=curp;
						curp=curp->next;
					}}
					
					else if(curp->e==tempe){
						printf("came here\n");
						new_node->c=(curp->c)+tempc;
						curp=new_node;
						prevp=curp;
						curp=curp->next;
					}
					else{
						//new_node->next=(curp->next);
						new_node->next=0;
						curp->next=new_node;
			//			printf("came here\n");
			             prevp=curp;
			             curp=curp->next;
					}
					
					
					
					
					
					
					
				}
				
			}
			
			
			
			
			
			
			
			
		}
		printf("product id\n");
		curp=startp;
		while(curp!=0){
			printf("%d(X^%d))",curp->c,curp->e);
			curp=curp->next;
	}
	
	
	
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*free(new_node);
free(new_node);
free(cura);
free(curb);	*/
	//to here
//7printf("end...");




	

	

