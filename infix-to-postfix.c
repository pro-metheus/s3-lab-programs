

int ispref(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*'||c=='/'){
		return 2;
	}
	else if(c=='+'||c=='-'){
		return 1;
	}
	else{
		return 0;
	}
	
}

int istype(char c){
	if(c=='^'||c=='+'||c=='-'||c=='*'||c=='/'){
		return 1;
	}
	else {
		return 0;
	}
}

#include<stdio.h>
int main()
{

	
//  ispref(), istype()
char inf[100],stack[100],out[100];
int stop=-1;
int otop=-1;
int n,i;
printf("\n Enter the number of elements :");
scanf("%d",&n);
printf("\n Enter the infix expression :");
i=0;
while(i<n){
	scanf("%s",&inf[i]);
	i++;
}
	
//infix exp entered...

printf("\n the infix expression is:");
for(i=0;i<=n;i++){
	printf("%c",inf[i]);
}

printf("\n\n\n");

	
char scan;
for(i=0;i<n;i++){
	scan=inf[i];
	if(scan=='('){
		stop++;
		stack[stop]=scan;
	}
	else if(scan==')'){
		while(stack[stop]!='('){
			otop++;
			out[otop]=stack[stop];
			stop--;
		}
		stop--;
	}
	else{
		
	if(ispref(scan)==0){
		otop++;
		out[otop]=scan;
	}//operands pushed...
	else if(stop!=-1){
	
    if((ispref(scan)>ispref(stack[stop]))){
		stop++;
		stack[stop]=scan;
	}//higher priority pushed
	
	
	else if(ispref(scan)<=ispref(stack[stop])){
		while(ispref(stack[stop])>=ispref(ispref(scan))){
			otop++;
			out[otop]=stack[stop];
			stop--;
			if(stop==-1){
				break;
			}
		}
		stop++;
		stack[stop]=scan;
	}}
	else{
		stop++;
		stack[stop]=scan;
	}
	
	
}}
//printf("%c",stack[0]);
printf("\n\n");

while(stop!=-1){
	otop++;
	out[otop]=stack[stop];
	stop--;
}
//printf("%d",otop);
/*for(i=0;i<otop;i++){
	printf("%c",out[i]);
}  */

printf("%s",out);
	
}
