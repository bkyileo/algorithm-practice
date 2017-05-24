//Find the total area covered by two rectilinear rectangles in a 2D plane.
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

//没有AC 想得太复杂 
#include<bits/stdc++.h>
using namespace std;
bool cover(int A, int B, int C, int D, int E, int F, int G, int H)
{
	if(A>=E && B>=F && C<=G && D<=H)
		return true;
	if(A<=E && B<=F && C>=G && D>=H)
		return true;
	return false;		
}

bool out(int A, int B, int C, int D, int E, int F, int G, int H)
{
	if(B>=H || A>=G || C<=E ||D<=F )
		return true;
	return false;
}


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	if(cover(A,B,C,D,E,F,G,H))
		return (C-A)*(D-B)>(G-E)*(H-F)?(C-A)*(D-B):(G-E)*(H-F);
	
	int area=(C-A)*(D-B)+(G-E)*(H-F);
	if(out(A,B,C,D,E,F,G,H))
		return area;
	
	area=(C-A)*(D-B)+(G-E)*(H-F);
	int diff=;
	cout<<area<<" "<<diff1<<" "<<diff2<<endl;
	return area-diff1-diff2;
}
//24+27-6
int main()
{
	cout<<computeArea(-2,-2,2,2,1,1,3,3)<<endl;
}
