%{
#include "stdio.h"
int fileNum;
%}
digit [0-9]+
keyword read|if|then|repeat|until|write|end
letter [a-zA-Z]+
comment \{[^\}]*\}
operator ":="|"="|"+"|"-"|"*"|"/"|">"|"<"
ignore  [\n|\t|" "]+
other [","|";"]+
%%
{comment} {
}
{digit} { 
	printf("Number,val= %s\n",yytext);
}
{keyword} { 
	printf("Key word: %s\n",yytext);
}
{letter} {
	 printf("Variable,name= %s\n",yytext);
}
{operator} { 
	printf("operator: %s\n",yytext);
}
{other} { 
	printf("other: %s\n",yytext);
}
{ignore} {
	/*nothing*/
}
%%
int yywrap()
{
	return 1;
}
int main(int argc,char **argv)
{
	FILE *file;
	fileNum = argc-1;
	if(fileNum>1){
		file=fopen(argv[fileNum],"w");
		if(file){
			yyout=file;
			freopen(argv[fileNum],"w",stdout);
		}
	}

	for(int i=1;i<=fileNum-1;i++){
		file=fopen(argv[i],"r");
		if(file){
			yyin=file;
		}
		yylex();
	}

	if(fileNum==0) yylex();
	yywrap();
	return 0;

}
