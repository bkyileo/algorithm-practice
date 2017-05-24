#include<iostream>
#include<string>
#include<vector>
#include<map>
int main()
{
    int N;
    std::cin>>N;
    std::string father, son;
    //父子关系存储在两个vector中
    std::vector<std::string> parent;
    std::vector<std::string> child;
    std::map<std::string, int> person;//存储人，不重复
    std::pair<std::string, int> pa;
    for(int i = 0; i < N; ++i)
    {
        std::cin>>father>>son;
        parent.push_back(father);
        child.push_back(son);
        person.insert(std::make_pair(father,0));
        person.insert(std::make_pair(son,0));
    }

    //给每个名字编号
    int id=0;
    for(std::map<std::string, int>::iterator iter=person.begin(); iter!=person.end(); ++iter)
    {
        iter->second=id;
        ++id;
    }
    //像并查集那样存储父子关系
    std::vector<int> relationship(person.size(),-1);//没有祖先结点的设为-1
    for(int i=0; i < N; ++i)
    {
        //relationship[i]的值是其父亲的ID
        relationship[person[child[i]]]=person[parent[i]];
    }


    int M;
    std::cin>>M;
    std::string name1,name2;
    for(int i = 0; i < M; ++i)
    {
        std::cin>>name1>>name2;
        if(name1==name2)
        {
            std::cout<<name1<<std::endl;
            continue;
        }
        if(person.find(name1)==person.end()||person.find(name2)==person.end())//没有这两个名字
        {
            std::cout<<-1<<std::endl;
            continue;
        }
        std::vector<int> mark(person.size(),-1);//标记其祖先结点
        int name1id=person[name1];
        while(name1id!=-1)
        {
            mark[name1id]=1;//祖先结点标记为1
            name1id=relationship[name1id];
        }
        int name2id=person[name2];
        while(name2id!=-1)
        {
            if(mark[name2id]==1)//找到最近的公共祖先
            {
                std::map<std::string,int>::iterator iter=person.begin();
                for(int i=0; i< name2id; ++i)//在map中找到这个祖先
                    ++iter;
                std::cout<<iter->first<<std::endl;
                break;
            }
            name2id=relationship[name2id];
        }
        if(name2id==-1)
            std::cout<<-1<<std::endl;
    }

}
