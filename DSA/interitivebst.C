#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct std
{
	int ro;
	struct std *lp;
	struct std *rp;
};
struct std *root=NULL;
void ins(int n)
{
	struct std * ne;
	struct std * tmp,*pr;
	if(root==NULL)
	{
		root=(struct std*)malloc(sizeof(struct std));
		root->ro=n;
		root->lp=NULL;
		root->rp=NULL;
	}
	else
	{
		tmp=root;
		while(tmp !=NULL)
		{
			pr=tmp;
			if(tmp->ro > n)
				tmp=tmp->lp;
			else
				tmp=tmp->rp;
		}
		ne=(struct std*)malloc(sizeof(struct std));
		ne->ro=n;
		ne->lp=NULL;
		ne->rp=NULL;
		if(pr->ro > n)
			pr->lp=ne;
		else
			pr->rp=ne;
	}
}
void dis(struct std *root)
{
	struct std *tmp;
	struct std *s[100];
	int top=-1;
	tmp = root;
	
	while(tmp!=NULL || top != -1)
	{
		while (tmp !=NULL){
			s[++top] = tmp;
			tmp = tmp->lp;
		}
		tmp = s[top--];
		printf("%d, ", tmp->ro);
		tmp = tmp->rp;
	}
}
void del(struct std *root,int n)
{
	int f=0,x,y;
	struct std *tmp,*pr;
	tmp=root;
	while(tmp != NULL)
	{
		if(tmp->ro == n)
		{
			f=1;
			break;
		}
		else if(tmp->ro > n)
		{
			pr=tmp;
			tmp=tmp->lp;
		}
		else
		{
			pr=tmp;
			tmp=tmp->rp;
		}
	}
	if(f==0)
	{
		printf("\n Number is not found ");
	}
	else
	{
		if(tmp->lp==NULL && tmp->rp==NULL)
		{
			if(pr->ro > n)
				pr->lp=NULL;
			else
				pr->rp=NULL;
			free(tmp);
		}
		else if(tmp->lp==NULL || tmp->rp==NULL)
		{
			if(tmp->rp==NULL)
			{
				if(pr->ro > n)
					pr->lp=tmp->lp;
				else
					pr->rp=tmp->lp;
			}
			else
			{
				if(pr->ro > n)
					pr->lp=tmp->rp;
				else
					pr->rp=tmp->rp;
			}
			free(tmp);
		}
		else
		{
			pr=tmp->rp;
			while(pr->lp!=NULL)
			{
				pr=pr->lp;
			}
			x=tmp->ro;
			y=pr->ro;
			pr->ro=x;
			tmp->ro=y;
			pr->ro=f;
			del(root,n);
		}
	}
}
void main()
{
	int ch,n;

	do
	{
		printf("\n=== binary search tree === \n");
		printf(" 1: insert ::\n");
		printf(" 2: display ::\n");
		printf(" 3: delete :: \n");
		printf(" 4: exit\n");

		printf(" select your choice ::");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				printf("Enter a value in Tree : ");
				scanf("%d",&n);
				ins(n);
				break;

			case 2: 
				dis(root);
				break;

			case 3: 
				printf("Enter a value Delete in Tree : ");
				scanf("%d",&n);
				del(root,n);
				break;
				
			case 4:
				printf("exit");
				break;

			default:
				printf("invalid choice ");
				break;
		}
	}while(ch != 4);
	printf("\n");

}