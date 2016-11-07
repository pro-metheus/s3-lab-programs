//infix expression to postfix

// problem : (a+b*(c-d))*f/g+(h+i-(j*(k+l)))
#include<stdio.h>
int val[100];
int vtop=-1;


int isoperator(char c){
	if(c=='^'||c=='*'||c=='/'||c=='+'||c=='-'){
		return 1;
	}
	else{
		return 0;
	}
}//isoperator ends here

int find(int a,char ch, int b){
	if(ch=='^'){
		return a^b;
	}
	else if(ch=='*'){
		return a*b;
	}
	else if(ch=='+'){
		return a+b;
	}
	else if(ch=='-'){
		return a-b;
	}
	else if(ch=='/'){
		return a/b;
	}
}

int values(char c[100]){
	int i=0;
	while(c[i]!='\0'){
		if(isoperator(c[i])==0){
			//printf("value ");
			printf("\nEnter the value of %c",c[i]);
			vtop++;
			scanf("%d",&val[vtop]);
		}
		i++;
	}
}
void evapo(char c[100]){
	int stack[100];
	int top=-1;
	int var1,var2,var3;
	int i=0;
	int j=0;
	while(c[i]!='\0'){
		if(isoperator(c[i])==0){
			top++;
			stack[top]=val[j];
			j++;
		}
		else{
			var2=stack[top];
			top--;
			var1=stack[top];
			top--;
			var3=find(var2,c[i],var1);
			top++;
			stack[top]=var3;
		//	printf("\n%d%c%d=%d",var2,c[i],var1,var3);
		}
		i++;
	}
	printf("\n%d",var3);
}


int prec(char c){
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
}//prec ends here


void toprefix(char s[100]){
	//	printf("\n the infix expression entered is  :%s",s);
		char stack[100];
		char res[100];
		int rtop=-1;
		int stop=-1;
		int i=0;
		while(s[i]!='\0'){
			//printf("in while...");
			if(s[i]==')'){
				stop++;
				stack[stop]=s[i];
				i++;
			}
			else if(s[i]=='('){
				i++;
				while((stack[stop]!='(')&&(stack[stop]!=')')){
					rtop++;
					res[rtop]=stack[stop];
					stop--;
				}
				stop--;
			}
			else if(prec(s[i])==0){
				rtop++;
				res[rtop]=s[i];
				i++;
			}else if(stop!=-1){
			
			 if(prec(s[i])>=prec(stack[stop])){
				stop++;
				stack[stop]=s[i];
				i++;
			}
			else if((prec(s[i])<stack[stop]) &&(stack[stop]!=')')){
				int eror=0;
				while(prec(s[i])<=stack[stop]&&stop!=-1&&(stack[stop]!=')')){
					
					rtop++;
					eror++;
					res[rtop]=stack[stop];
					stop--;
					
				} //
				stop++;
				stack[stop]=s[i];
				i++;
			}
			
		}
		else{
			stop++;
			stack[stop]=s[i];
			i++;
		}
		}
	//	rtop++;
		//res[rtop]='\0';
	
		while(stop>=0){
	
			rtop++;
			res[rtop]=stack[stop];
			stop--;
		} 
		
		rtop++;
		res[rtop]='\0';
		int p=0;
		int ptop=0;
		while(res[p]!='\0'){
			ptop++;
			p++;
		}
		char fin[100];
		fin[ptop]='\0';
		ptop--;
		p=0;
		while(res[p]!='\0'){
			fin[ptop]=res[p];
			p++;
			ptop--;
		}
		printf("\n The prefix rxpression is :%s",fin);
		values(res);
		
	//	printf("\n The postfix rxpression after valuing is :%s",res);
		evapo(res);
	//	printf("final value is :%d",evapo(res));
}//converted to postfix


int main(){
	char infix[100],postfix[100],rev[100];
	printf("\nenter the infix expression :");
	scanf("%s",&infix);
	int i=0;
	int top=0;
	while(infix[i]!='\0'){
		top++;
		i++;
	}
	rev[top]='\0';
	top--;
	i=0;
	while(infix[i]!='\0'){
		rev[top]=infix[i];
		i++;
		top--;
	}
//	printf("%d",top);
//	printf("%s",rev);
	toprefix(rev);
}
