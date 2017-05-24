//hihocoder 24点 搜索

#include<bits/stdc++.h>
using namespace std;

int ops[6]={1,2,3,4,5,6};

void swap(float &a,float &b)
{
	float temp=a;
	a=b;
	b=temp;
}

bool cal(float a[])
{
	// (((a ⊙ b) ⊙ c ) ⊙ d)
	// ((a ⊙ b) ⊙ (c ⊙ d))
	//5 5 5 1
	//cout<<"a "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
	for(int i=0;i<6;++i)
	for(int j=0;j<6;++j)
	for(int k=0;k<6;++k)
	{
		int ops1=ops[i];
		int ops2=ops[j];
		int ops3=ops[k];
		//模式1
		{
			float ans=0;
			switch (ops1)
			{
				case 1:
				{
					ans = a[0]+a[1];
					break;
				}
				case 2:
				{
					ans = a[0]-a[1];
					break;
				}
				case 3:
				{
					ans = a[0]*a[1];
					break;
				}
				case 4:
				{
					ans = a[0]/a[1];
					break;
				}
				case 5:
				{
					ans = a[1]-a[0];
					break;
				}
				case 6:
				{
					ans = a[1]/a[0];
					break;
				}
			}
			
			switch (ops2)
			{
				case 1:
				{
					ans = ans+a[2];
					break;
				}
				case 2:
				{
					ans = ans-a[2];
					break;
				}
				case 3:
				{
					ans = ans*a[2];
					break;
				}
				case 4:
				{
					ans = ans/a[2];
					break;
				}
				case 5:
				{
					ans = a[2]-ans;
					break;
				}
				case 6:
				{
					if(abs(ans-0)<0.000001)
					{
						ans=0;
						break;
					}
					
					ans = a[2]/ans;
					break;
				}
			}
			
			switch (ops3)
			{
				case 1:
				{
					ans = ans+a[3];
					break;
				}
				case 2:
				{
					ans = ans-a[3];
					break;
				}
				case 3:
				{
					ans = ans*a[3];
					break;
				}
				case 4:
				{
					ans = ans/a[3];
					break;
				}
				case 5:
				{
					ans = a[3]-ans;
					break;
				}
				case 6:
				{
					if(abs(ans-0)<0.000001)
					{
						ans=0;
						break;
					}
					ans = a[3]/ans;
					break;
				}
			}
			if(abs(ans-24.0)<0.000001)
			{
				return true;				
			}		
		} 
		//模式2
		{
			float ans1=0;
			float ans2=0;
			float ans=0;
			switch (ops1)
			{
				case 1:
				{
					ans1 = a[0]+a[1];
					break;
				}
				case 2:
				{
					ans1 = a[0]-a[1];
					break;
				}
				case 3:
				{
					ans1 = a[0]*a[1];
					break;
				}
				case 4:
				{
					ans1 = a[0]/a[1];
					break;
				}
				case 5:
				{
					ans1 = a[1]-a[0];
					break;
				}
				case 6:
				{
					ans1 = a[1]/a[0];
					break;
				}
			}
			
			switch (ops3)
			{
				case 1:
				{
					ans2 = a[2]+a[3];
					break;
				}
				case 2:
				{
					ans2 = a[2]-a[3];
					break;
				}
				case 3:
				{
					ans2 = a[2]*a[3];
					break;
				}
				case 4:
				{
					ans2 = a[2]/a[3];
					break;
				}
				case 5:
				{
					ans2 = a[3]-a[2];
					break;
				}
				case 6:
				{
					ans2 = a[3]/a[2];
					break;
				}
			}
			switch (ops2)
			{
				case 1:
				{
					ans = ans1+ans2;
					break;
				}
				case 2:
				{
					ans = ans1-ans2;
					break;
				}
				case 3:
				{
					ans = ans1*ans2;
					break;
				}
				case 4:
				{
					if(abs(ans2-0)<0.000001)
					{
						ans=0;
						break;
					}
					ans = ans1/ans2;
					break;
				}
				case 5:
				{
					ans = ans2-ans1;
					break;
				}
				case 6:
				{
					if(abs(ans1-0)<0.000001)
					{
						ans=0;
						break;
					}
					ans = ans2/ans1;
					break;
				}
			}
			if(abs(ans-24.0)<0.000001)
			{
				return true;				
			}	
		}
	}
	return false;
}

void solve(float a[],int curr,bool &can)
{
	if(curr==3)
	{
		//全排列 
		if(cal(a)) 
			can=true;
		return ;
	}
	for(int i=curr;i<4;++i)
	{
		swap(a[i],a[curr]);
		solve(a,curr+1,can);
		swap(a[i],a[curr]);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		float card[4];
		bool can=false;
		float a,b,c,d;
		cin>>a>>b>>c>>d;
		card[0]=a;card[1]=b;card[2]=c;card[3]=d;
		solve(card,0,can);
		if(can) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
 } 

 
