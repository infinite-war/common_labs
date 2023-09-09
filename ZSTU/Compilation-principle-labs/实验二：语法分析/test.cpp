#include<iostream>
#include<string.h>
using namespace std;

// grammar 已消除左递归
/*
	lexp->atom|list
	atom->number|identifier
	list->(lexp-seq)
	lexp-seq->lexp lexp-seq’
	lexp-seq’->lexp lexp-seq’|ε
*/


//=========global virables===========
int index=0;  //记录当前扫描的位置
int level=0;  //记录当前语法树的深度
string str;   //存储输入的串

//=========functions==========
int lexp();		// lexp->atom|list
void atom();	// atom->number|identifer
void list();	// list->(lexp-seq)
void lexp_seq();	// lexp-seq->lexp lexp-seq’
void lexp_seq_();	// lexp-seq’->lexp lexp-seq’|ε

void printLevel(){ //根据当前的level确定当前递归树结点的深度
	cout<<"str["<<index<<"]="<<str[index]<<"  ";
	for(int i=0;i<level;i++){
		cout<<"----";  //每加深一层，前缀就多一个"----"
	}
}

// lexp->atom|list
int lexp(){
	if( (str[index]>='0'&&str[index]<='9')||(str[index]>='a'&&str[index]<='z') ){
		level++; atom(); level--;
		return 1;
	}
	else if(str[index]=='('){
		level++; list(); level--;
		return 1;
	}
	else {
		return 0;
	}
}

// atom->number|identifer
void atom(){
	if(str[index]>='0'&&str[index]<='9'){
		printLevel();
		cout<<str[index]<<endl;
		index++;
	}
	else if(str[index]>='a'&&str[index]<='z'){
		printLevel();
		cout<<str[index]<<endl;
		index++;
	}
}

// list->(lexp-seq)
void list(){
	//如果符合文法，一开始匹配的符号一定是')'
	if(str[index]!='('){
		exit(-1);
	}
	// '('终结符完成匹配后，index指向下一个预读的符号
	printLevel();
	cout<<str[index]<<endl;
	index++;
	level++; lexp_seq(); level--;
	//lexp-seq推导完后，如果符合文法，那么index现在指向的字符一定是`)`
	if(str[index]!=')'){
		printLevel();
		cout<<"list()error: ')' is excepted "<<endl;
		exit(-1);
	}
	printLevel();
	cout<<str[index]<<endl;
	index++;
}

// lexp-seq->lexp lexp-seq’
void lexp_seq(){
	level++; lexp(); level--;
	level++; lexp_seq_(); level--;
}

// lexp-seq’->lexp lexp-seq’|ε
void lexp_seq_(){
	// 如果预读到的符号可以完成lexp的推导，说明本次推导选择的是第一项
	int temp=lexp(); 
	if(temp==1){
		level++; lexp_seq_(); level--;
	}
	else {
		return ;
	}	
}


int main(int argc,char* argv[]){
	cin>>str;
	int len=str.size();
	str[len++]='$';
	//可能有多个外括号，如(a)(b)
	while(index<len-1){lexp();}
	
	//如果能顺利读取到结束符号，则说明输入的串符合文法
	if(str[index]=='$') cout<<"accept."<<endl;
	else cout<<"wrong answer."<<endl;
	return 0;
}