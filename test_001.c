#include <stdio.h>
int main()
{
	int i,k,temp=0;
	int this,max,fir,end;
	int matrix[100000];
	int first[100000]={0};
	this=max=0;
	
	scanf("%d",&k);
	for(i=0;i<k;i++)
		scanf("%d",&matrix[i]);
	for(i=0;i<k;i++)
	{	this+=matrix[i];
		if(this>max)
		{	max=this;
			end=i;
		}	
		else if(this < 0)
		{	this=0;
		}
	}
	for(i=end;i>=0;i--)
	{	temp+=matrix[i];
		if(temp==max)
		{//	while(matrix[i-1]==0)
		//		i=i-1;
			first[i]=1;
		//	break;
		}
		
	}
	for(i=0;i<k;i++)
		if(first[i]==1)
		{	fir=matrix[i];
			break;
		}
//	fir=matrix[fir];
	end=matrix[end];
	if(max==0)
	{	for(i=0;i<k;i++)
			if(matrix[i]==0)
			{	fir=0;
				end=0;
				break;
			}
		if(i==k)
		{	
			fir=matrix[0];
			end=matrix[k-1];
		}
	}
	printf("%d %d %d\n",max,fir,end);
}
	
