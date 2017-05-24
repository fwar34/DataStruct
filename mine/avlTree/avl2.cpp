/*************************************************************************
    > File Name: avl2.cpp
    > Author: Feng
    > Created Time: 2017年05月24日 星期三 13时44分06秒
    > Content: 网上的实现https://my.oschina.net/llmm/blog/158454
 ************************************************************************/

#include<iostream>
#include<string>
#include<queue>
#include<cstdlib>
using namespace std;

class  Node
{
public:
	Node(int x,Node* f)
	{
		value=x;father=f;
		handle=1;balance=0;
		lchild=rchild=NULL;
	}
	int id,value,handle,balance;
	Node *father,*lchild,*rchild;
};

Node* NewNode(int x,Node* f)
{
	Node* T=new Node(x,f);
	T->lchild=new Node(0,T);
	T->rchild=new Node(0,T);
}

bool IsLeaf(Node* p)
{
	if(p->lchild==NULL&&p->rchild==NULL) 
		return true;
	else return false;
}

Node* LRotate(Node* T,Node* p)
{
	Node* f=p->father;
	Node* r=p->rchild;
	if(r==NULL) return T;
	p->rchild=r->lchild;
	if(r->lchild!=NULL)	r->lchild->father=p;
	r->lchild=p; p->father=r;
	if(f==NULL) 
	{
		r->father=NULL;
		return r;
	}
	else 
	{
		if(f->lchild==p) f->lchild=r;
		else f->rchild=r;
		r->father=f;
		return T;
	}
}

Node* RRotate(Node* T,Node* p)
{
	Node* f=p->father;
	Node* l=p->lchild;
	if(l==NULL) return T;
	p->lchild=l->rchild;
	if(l->rchild!=NULL)	l->rchild->father=p;
	l->rchild=p; p->father=l;
	if(f==NULL) 
	{
		l->father=NULL;
		return l;
	}
	else
	{
		if(f->lchild==p) f->lchild=l;
		else f->rchild=l;
		l->father=f;
		return T;
	}
}

void LRAdjust(Node* p)
{
	if(p->balance== -2)
	{	//平衡左旋
		if(p->rchild->balance==0)
		{
			p->balance++;
			p->rchild->balance++;
		}
		else if(p->rchild->balance==-1)
		{
			p->balance+=2;
			p->rchild->balance++;
		}
		else
		{
			p->balance+=3;
			p->rchild->balance+=2;
		}
	}
	else
	{	//偏置左旋
		if(p->rchild->balance<0)
		{
			p->balance+=2;
			p->rchild->balance+=2;
		}
		else
		{
			p->balance++;
			p->rchild->balance++;
		}
	}
}

void RRAdjust(Node* p)
{
	if(p->balance== 2)
	{	//平衡右旋
		if(p->lchild->balance==0)
		{
			p->balance--;
			p->lchild->balance--;
		}
		else if(p->lchild->balance==1)
		{
			p->balance-=2;
			p->lchild->balance--;
		}
		else 
		{
			p->balance-=3;
			p->lchild->balance-=2;
		}
	}
	else
	{	//偏置右旋
		if(p->lchild->balance>0)
		{
			p->balance-=2;
			p->lchild->balance-=2;
		}
		else
		{
			p->balance--;
			p->lchild->balance--;
		}
	}
}

Node* IAdjust(Node* T,Node* p)
{
	if(p==NULL) return T;
	if(p->balance>=2)	//左偏
	{
		if(p->lchild->balance<0) //右偏
		{
			LRAdjust(p->lchild);	
			T=LRotate(T,p->lchild);
		}
		RRAdjust(p);
		return RRotate(T,p);
	}
	else if(p->balance<=-2) //右偏
	{
		if(p->rchild->balance>0)	//左偏
		{
			RRAdjust(p->rchild);
			T=RRotate(T,p->rchild);
		}
		LRAdjust(p);
		return LRotate(T,p);
	}
	else	
	{
		if(p->father==NULL) return T; 
		if(p==p->father->lchild) 
			p->father->balance++;
		else p->father->balance--;
		if(p->father->balance!=0)	
			return IAdjust(T,p->father);
		else return T;
	}
}

Node* Insert(Node* T,int x)
{
	Node *f=NULL,*p=NULL;
	if(T==NULL) T=NewNode(x,NULL);
	else
	{
		f=p=T;
		while(!IsLeaf(p))
		{
			f=p;
			if(x<p->value)	p=p->lchild;
			else if(x>p->value) p=p->rchild;
			else {p->handle++;return T;}
		}
		delete p;p=NewNode(x,f);
		if(x<f->value) f->lchild=p;
		else f->rchild=p;
	}
	T=IAdjust(T,p);
	return T;
}

Node* Build(int* array,int size)
{
	if(size==0) return NULL;
	Node* T=NULL;
	for(int i=0;i<size;i++) T=Insert(T,array[i]);
	return T;
}

Node* Find(Node* T,int x)
{
	if(IsLeaf(T)) return NULL;
	if(x==T->value) return T;
	else if(x>T->value)
		return Find(T->rchild,x);
	else return Find(T->lchild,x);
}

Node* pre(Node* x)
{
	Node* p=x;
	if(!IsLeaf(p->lchild))
	{
		p=p->lchild;
		while(!IsLeaf(p->rchild)) p=p->rchild;
		return p;
	}
	else
	{
		while(p->father!=NULL&&p->father->rchild!=p) p=p->father;
		return p->father;
	}
}

Node* next(Node* x)
{
	Node* p=x;
	if(!IsLeaf(p->rchild))
	{
		p=p->rchild;
		while(!IsLeaf(p->lchild)) p=p->lchild;
		return p;
	}
	else
	{
		while(p->father!=NULL&&p->father->lchild!=p) p=p->father;
		return p->father;
	}
}

Node* DAdjust(Node* T,Node* p)
{
	if(p==NULL) return T;
	if(p->balance>=2)   //左偏
	{
		if(p->lchild->balance<0) //右偏
		{
			LRAdjust(p->lchild);
			T=LRotate(T,p->lchild);
		}
		RRAdjust(p);
		T=RRotate(T,p);
		p=p->father;
	}
	else if(p->balance<=-2) //右偏
	{
		if(p->rchild->balance>0)    //左偏
		{
			RRAdjust(p->rchild);
			T=RRotate(T,p->rchild);
		}
		LRAdjust(p);
		T=LRotate(T,p);
		p=p->father;
	}
	if(p->father==NULL) return T;
	if(p==p->father->lchild) p->father->balance--;
	else p->father->balance++;
	if(p->father->balance==1||p->father->balance==-1)	return T;
	else return DAdjust(T,p->father);
}

Node* Delete(Node* T,int x)
{
	Node *p=Find(T,x),*n=NULL;
	if(p==NULL) return NULL;
	if(--p->handle) return T;
	if(IsLeaf(p->lchild)&&IsLeaf(p->rchild))
	{				//双子空
		if(p->father==NULL) return NULL;
		if(p->father->lchild==p) 
			n=p->father->lchild=p->lchild;
		else n=p->father->rchild=p->lchild;
		p->lchild->father=p->father;
		delete p->rchild;
	}
	else if(IsLeaf(p->lchild))
	{				//左空
		if(p->father==NULL) 
		{
			n=T=p->rchild;
			n->father=NULL;
		}
		else
		{
			if(p==p->father->lchild)
				n=p->father->lchild=p->rchild;
			else n=p->father->rchild=p->rchild;
			n->father=p->father;
		}
		delete p->lchild;
	}
	else if(IsLeaf(p->rchild))
	{				//右空
		if(p->father==NULL)
		{
			n=T=p->lchild;
			n->father=NULL;
		}
		else
		{
			if(p->father->lchild==p)
				p->father->lchild=p->lchild;
			else p->father->rchild=p->lchild;
			n->father=p->father;
		}
		delete p->rchild;
	}
	else
	{	
		n=next(p);
		if(n==n->father->lchild)
			n->father->lchild=n->rchild;
		else n->father->rchild=n->rchild;
		n->rchild->father=n->father;
		p->value=n->value;
		p->handle=n->handle;
		delete n->lchild;
		n=n->rchild;
	}
	return DAdjust(T,n);
}

int depth(Node* T)
{
	if(IsLeaf(T)) return 0 ;
	int a=depth(T->lchild)+1;
	int b=depth(T->rchild)+1;
	return a>b?a:b;
}

string space(int n)
{
	string s=string("");
	for(int i=0;i<n;i++) s+=" ";
	return s;
}

void Display(Node* T,int mode)
{
	if(IsLeaf(T)) return ;
	queue<Node> Q;
	int pl=0,pid=0,H=depth(T),h=0;	//pl，之前打印所在层数
	T->id=1;
	Q.push(*T);					//pid，之前打印结点的编号
	while(!Q.empty())
	{
		Node& p=Q.front();
		for(h=0;;h++)	//当前结点在树中所在的层数
			if((1<<h)>=p.id+1) break;
		int offset=(1<<(H-h+1))-1;//本层两个结点之间的偏移量
		if(h==pl) 
		{							//加上了结点本身的占位,当结点打印值超过1个字符位时会导致混乱					
			cout<<space((p.id-pid)*offset)<<space(p.id-pid-1);
			if(mode) cout<<p.value;
			else cout<<p.balance;
			pid=p.id;
		}
		else 
		{
			pid=1<<(h-1);	//前一次结点编号
			int of=(1<<(H-h))-1;	//本层总偏移量
			cout<<endl<<space(of)<<space((p.id-pid)*offset)<<space(p.id-pid);
			if(mode) cout<<p.value;
			else cout<<p.balance;
			pid=p.id;pl=h;
		}
		Q.pop();
		if(!IsLeaf(p.lchild))
		{
			p.lchild->id=p.id*2;
			Q.push(*p.lchild);
		}
		if(!IsLeaf(p.rchild))
		{
			p.rchild->id=p.id*2+1;
			Q.push(*p.rchild);
		}
	}
	cout<<endl<<endl;
}

int main(int argc,char* argv[])
{
	//	int array[9]={5,3,4,7,6,1,2,9,8};
	int array[9]={1,2,3,4,5,6,7,8,9};
	//	int array[6]={3,2,8,5,9,6};
	Node* T=Build(array,atoi(argv[1]));
	Display(T,1);
	Display(T,0);
	if(argc==3)
	{
		T=Delete(T,atoi(argv[2]));
		Display(T,1);
		Display(T,0);
	}
	return 0;
}
