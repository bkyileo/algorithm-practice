#include<bits/stdc++.h>
using namespace std;
/*
	USE loserTree to External sort
	step 1 : split file apart store into node;
	step 2 : sort node use qsort;
	step 3 : create loser tree;
	step 4 : K-merge and write to the output file (use vector to simulate);
*/


/* 
	FIRST : we need a big file simulation both input and output with vector 
*/
vector<int> inputFile;
vector<int> outputFile;
int fileSize;
void __init()
{
	fileSize = 10000;
	// init and random 
	inputFile = vector<int> (fileSize);
	for(int i=0;i<fileSize;++i)
	{
		inputFile[i] = rand();
	}
	/* debug 1 : check the input init 
	for(int i=0;i<fileSize;++i)
	{
		cout<<inputFile[i]<<" ";
	}
	cout<<endl;
	*/
}

/* 
	SECOND : dataStruct to split big file into node   
*/
struct node
{
	int start;
	int offset;
	int len;
};
int partSize;
int parts;
int runTimeParts;

/* 
	THEN : dataStruct and algorithm in loserTree
	link : 
		http://blog.sina.com.cn/s/blog_13a5c10be0102v1fb.html
*/
vector<int> loserTree;
vector<int> buff;
vector<node> runTimeNodes;
void createLoseTree();
void adjust(int id);

void createLoseTree()
{
	buff = vector<int> (parts + 1);
	for(int i=0;i<parts;++i)
	{
		buff[i] = inputFile[ runTimeNodes[i].start + runTimeNodes[i].offset ];
	}
	buff[parts] = INT_MIN;
	
	loserTree = vector<int> (parts,parts);
	
	for (int i = parts-1; i>=0; --i)  
        adjust(i);
          
	
}

void adjust(int id)
{
    for (int i = (id + parts)/2; i>0; i=i/2)  
    {  
        if (buff[id] > buff[loserTree[i]])   
    		swap(id, loserTree[i]);
    }  
    loserTree[0] = id ;
}

/*
	FINAL : the whole precess
*/
void slove()
{
	__init();
	
	partSize = 555;
	parts =  fileSize / partSize;
	parts += fileSize % partSize > 0 ? 1:0;
	
	runTimeNodes = vector<node>(parts);
	for(int i=0;i<parts;++i)
	{
		runTimeNodes[i].start = i*partSize ;
		runTimeNodes[i].offset = 0;
		runTimeNodes[i].len = i==parts-1 ? fileSize%partSize : partSize;
	}
	
	/*  debug 2 : check node info 
	for(int i=0;i<parts;++i)
	{
		cout<<"node id :"<<i<<" start index :"<<runTimeNodes[i].start<<" len : "<<runTimeNodes[i].len<<endl;	
	}
	*/
	
	for(int i=0;i<parts;++i)
	{
		sort( inputFile.begin() + runTimeNodes[i].start , inputFile.begin() + runTimeNodes[i].start + runTimeNodes[i].len );
	}
	
	/* debug 3 : check sort int node 
	for(int i=0;i<parts;++i)
	{
		for(int j=0;j<runTimeNodes[i].len;++j)
		{
			cout<<inputFile[runTimeNodes[i].start+j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	createLoseTree();
	runTimeParts = parts;
	
	int time = 0;
	while(runTimeParts>0)
	//while(time < 10)
	{
		/*
			loser tree pop
			change offset in correspond node
			check offset
				if offset == len
					 runTimeParts --;
					 file [index] = INT_MAX;
				else 
					offset ++;  
			
		*/
		node curr = runTimeNodes[loserTree[0]];
		outputFile.push_back( 	buff[ loserTree[0] ] );
		if(curr.offset+1 == curr.len)
		{
			buff[ loserTree[0] ] = INT_MAX;
			runTimeParts--;
		}
		else
		{
			curr.offset++ ;
			buff[ loserTree[0] ] = inputFile[ curr.start + curr.offset ];
			runTimeNodes[loserTree[0]].offset++ ;
		}
		adjust(loserTree[0]);
		
		/*
		time++;
		cout<<endl;
		cout<<"-------time : "<<time<<"-----------------"<<endl;
		for(auto i:loserTree)
			cout<<i<<" ";
		cout<<endl;
		
		for(auto i:buff)
			cout<<i<<" ";
		cout<<endl;
		
		for(auto i:outputFile)
			cout<<i<<" ";
		cout<<endl;
		cout<<"-----------------------------------------"<<endl;
		*/
	}
}

int main()
{
	slove();
	
	sort(inputFile.begin(),inputFile.end());
	for(int i=0;i<inputFile.size();++i)
	{
		if(inputFile[i]!=outputFile[i])
		{
			cout<<"false"<<endl;
			break;
		}
	}
	return 0;
} 
