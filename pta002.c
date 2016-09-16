#include <stdio.h>
#include <stdlib.h>

int main()
{	int i,j,k;
	int *l1,*l2,*l3,*l4;
	scanf("%d",&i);
	l1=malloc(sizeof(int)*2*i);
	k=i;
	for(k=0;k<i;k++)
	{	scanf("%d",l1+2*k);
		scanf("%d",l1+2*k+1);
	}
	scanf("%d",&j);
	l2=malloc(sizeof(int)*2*j);
	for(k=0;k<j;k++)
	{	scanf("%d",l2+2*k);
		scanf("%d",l2+2*k+1);
	}
	l3=malloc(sizeof(int)*(2*i*j));
	l4=malloc(sizeof(int)*(2*i+2*j));
	int ki=0,kj=0;k=0;
	while(ki!=i && kj!=j)
	{	for(ki=0;ki<i;ki++)
		{	for(kj=0;kj<j;kj++)
			{	l3[2*k]=l1[2*ki]*l2[2*kj];
				l3[2*k+1]=l1[2*ki+1]+l2[2*kj+1];
				k++;
			}
		}
	}
	int tmp,tmpk,tmpi,tmpj,tmpl;
	for(k=0;k<i*j;k++)
	{	tmp=l3[2*k+1];
		for(tmpi=k+1;tmpi<i*j;tmpi++)
		{	if(tmp==l3[2*tmpi+1])
			{	l3[2*tmpi+1]=0;
				l3[2*k]+=l3[2*tmpi];
				l3[2*tmpi]=0;
			}
		}
	}
	tmpi=tmpj=tmpk=tmpl=0;
	for(k=0;k<i*j;k++)
	{	for(tmpi=k;tmpi<i*j;tmpi++)
		{	if(l3[2*tmpi+1]>l3[2*k+1])
			{	tmp=l3[2*tmpi+1];
				l3[2*tmpi+1]=l3[2*k+1];
				l3[2*k+1]=tmp;

				tmp=l3[2*tmpi];
				l3[2*tmpi]=l3[2*k];
				l3[2*k]=tmp;
			}
		}
	}
	ki=kj=k=0;
	while(ki!=i && kj!=j)
	{	if(l1[2*ki+1]>l2[2*kj+1])
		{	l4[2*k]=l1[2*ki];
			l4[2*k+1]=l1[2*ki+1];
			ki++;
			k++;
		}
		else if(l1[2*ki+1]<l2[2*kj+1])
		{	l4[2*k]=l2[2*kj];
			l4[2*k+1]=l2[2*kj+1];
			kj++;
			k++;
		}
		else if(l1[2*ki+1]==l2[2*kj+1])
		{	l4[2*k]=l1[2*ki]+l2[2*kj];
			l4[2*k+1]=l1[2*ki+1];
			ki++;kj++;
			if(l4[2*k]!=0)
				k++;
		}
	}if(ki==i && kj!=j)
	{
		while(kj!=j)
		{	l4[2*k]=l2[2*kj];
			l4[2*k+1]=l2[2*kj+1];
			kj++;
			k++;
		}
	}else if(kj==j &&	ki!=i)
	{	while(ki!=i)
		{	l4[2*k]=l1[2*ki];
			l4[2*k+1]=l1[2*ki+1];
			ki++;
			k++;
		}
	}
	int tmpa,tmpb,tmpc;
	for(tmpc=0;tmpc<i+j;tmpc++)
	{	for(tmpb=tmpc+1;tmpb<i+j;tmpb++)
		{	if(l4[2*tmpb+1]==l4[2*tmpc+1])
			{	l4[2*tmpb+1]=0;
				l4[2*tmpc]+=l4[2*tmpb];
				l4[2*tmpb]=0;
			}else if(l4[2*tmpb+1]>l4[2*tmpc+1])
			{	tmpa=l4[2*tmpb];
				l4[2*tmpb]=l4[2*tmpc];
				l4[2*tmpc]=tmpa;

				tmpa=l4[2*tmpb+1];
				l4[2*tmpb+1]=l4[2*tmpc+1];
				l4[2*tmpc+1]=tmpa;
			}
		}
	}
	//puts("");
	int tmpy=0;int tmpz=0;
	for(k=0;k<i*j;k++)
	{	if(l3[2*k]==0 )
		{
			tmpz++;
			continue;
		}
		if(k==0 || tmpy==0)
		{	printf("%d",l3[2*k]);
			printf(" %d",l3[2*k+1]);
		}
		else
		{	printf(" %d",l3[2*k]);
			printf(" %d",l3[2*k+1]);
		}
		tmpy++;
	}
	if(tmpz==k)
	{	printf("0 0");
	}
	puts("");
	tmpz=0;
	tmpy=0;
	for(k=0;k<i+j;k++)
	{	if(l4[2*k]==0  )
		{	tmpz++;
			continue;
		}

		if(k==0 || tmpy==0)
		{	printf("%d",l4[2*k]);
			printf(" %d",l4[2*k+1]);
		}
		else
		{	printf(" %d",l4[2*k]);
			printf(" %d",l4[2*k+1]);
		}
		tmpy++;
	}
	// printf("k%d z%d\n",k,tmpz );
	if(tmpz==k)
	{	printf("0 0");
	}

}
