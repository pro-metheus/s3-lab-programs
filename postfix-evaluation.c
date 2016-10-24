#include<stdio.h>
#include<math.h>

bool isoperator(char c){
	if(c=='^'||c=='*'||c=='/'||c=='+'||c=='-'){
		return true;
	}
	else {
		return false;
	}
}
int operation(int x,char c, int y){
	if(c=='^'){
		return pow(x,y);
	}
	else if(c=='+'){
		return x+y;
		
	}
	else if(c=='-'){
		return x-y;
	}
	else if(c=='*'){
		return x*y;
	}
	else if(c=='/'){
		return x/y;
	}
}

int main()
{
	char out[100];
	int otop;
	int n,i,var1=0,var2=0,var3=0,rtop=-1;
	printf("enter number of terms :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",&out[i]);
	}
	int res[100];
	otop=0;
	while(otop<n){
		if(isoperator(out[otop])==false){
			rtop++;
			res[rtop]=out[otop];
			otop++;
		}
		else{printf("top is now %c",res[rtop]);
			var1=res[rtop]-'0';
			printf("\n var 1 =%d",var1);
			rtop--;
			var2=res[rtop]-'0';
				printf("\n var 2 =%d",var2);
			rtop--;
			var3=operation(var2,out[otop],var1);
				printf("\n var3 is %d",var3);
			otop++;
			rtop++;
			res[rtop]=var3;
			
		}
	}
	printf("\n\n\n\n");
	printf("%d",res[rtop]);
	
}
