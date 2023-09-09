#include<iostream>
#include<string.h>
using namespace std;

// grammar 已消除左递归
/*
	E->TE’
	E’->+TE’|ε
	T->FT’
	T’->*FT’|ε
	F->(E)|id
*/


//=========global virables===========
int index=0;  //记录当前扫描的位置
int level=0;  //记录当前语法树的深度
string str;   //存储输入的串

//=========functions==========
void E();		// E->TE’
void E_();	// E’->+TE’|ε
void T();	// T->FT’
void T_();	// T’->*FT’|ε
int F();	// F->(E)|id

void printLevel(){ //根据当前的level确定当前递归树结点的深度
	cout<<"str["<<index<<"]="<<str[index]<<"  ";
	for(int i=0;i<level;i++){
		cout<<"----";  //每加深一层，前缀就多一个"----"
	}
}

// E->TE’
void E(){
	level++; T(); level--;
	level++; E_(); level--;
}

// E’->+TE’|ε
void E_(){
	//如果一开始匹配的符号是'+',则匹配第一项，否则匹配空
	if(str[index]!='+'){
		return ;
	}
	else{
		printLevel();
		cout<<str[index]<<endl;
		index++;
		level++; T(); level--;
		level++; E_(); level--;
	}
}

// T->*FT’
void T(){
	level++; F(); level--;
	level++; T_(); level--;
}

// T’->*FT’|ε
void T_(){
	//如果预读的符号可以完成F的推导，则选择第一项
	if(str[index]!='*'){
		return ;
	}
	else{
		printLevel();
		cout<<str[index]<<endl;
		index++;
		level++; F(); level--;
		level++; T_(); level--;
	}
}



// F->(E)|id
int F(){
	//如果一开始匹配的符号不是'(',则选择推导id
	if(str[index]!='('){
		printLevel();
		cout<<str[index]<<endl;
		index++;
		return 0;
	}
	// '('终结符完成匹配后，index指向下一个预读的符号
	printLevel();
	cout<<str[index]<<endl;
	index++;
	level++; E(); level--;
	//lexp-seq推导完后，如果符合文法，那么index现在指向的字符一定是`)`
	if(str[index]!=')'){
		printLevel();
		cout<<"list()error: ')' is excepted "<<endl;
		exit(-1);
	}
	printLevel();
	cout<<str[index]<<endl;
	index++;
	return 1;
}


int main(int argc,char* argv[]){
	cin>>str;
	int len=str.size();
	str[len++]='$';
	while(index<len-1){E();;}
	if(str[index]=='$') cout<<"accept."<<endl;
	else cout<<"wrong answer."<<endl;
	return 0;
}