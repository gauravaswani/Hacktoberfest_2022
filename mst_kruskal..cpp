#include<iostream>
#include<list>
using namespace std;
class Node
{
public:
    char data;
    Node* parent;
    int rank;
    Node(char val)
    {
        data=val;
    }
};
class Edge
{
public:
    Node* source;
    Node* destination;
    int weight;

    Edge(Node* temp_u,Node* temp_v,int w)
    {
        source=temp_u;
        destination=temp_v;
        weight=w;
    }
};
bool Compare_the_edges(Edge* edge_u,Edge* edge_v)
{
    return (edge_u->weight < edge_v->weight);
}
class Graph
{
private:
    list<Node*> node_list;
    list<Edge*> edge_list;
    Node* find_node_in_list(char val)
    {
        Node* temp=NULL;
        for(auto i=node_list.begin();i!=node_list.end();i++)
        {
            if((*i)->data == val)
            {
                temp=*i;
                break;
            }
        }
        return temp;
    }
    void make_set(Node* temp)
    {
        temp->parent=temp;
        temp->rank=0;
    }
    void link(Node* temp_x,Node* temp_y)
    {
        if(temp_x->rank > temp_y->rank)
        {
            temp_y->parent=temp_x;
        }
        else
        {
            temp_x->parent=temp_y;
            if(temp_y->rank == temp_x->rank)
            {
                temp_y->rank=temp_y->rank + 1;
            }
        }
    }
    Node* find_set(Node* temp)
    {
        if(temp!=temp->parent)
        {
            temp->parent=find_set(temp->parent);
        }
        return temp->parent;
    }
    void make_union(Node* temp_x,Node* temp_y)
    {
        link(find_set(temp_x),find_set(temp_y));
    }

public:
    void push_edge(char val_u,char val_v,int w_el)
    {
        Node* temp_u=NULL;
        Node* temp_v=NULL;
        if(node_list.empty()==true)
        {
            temp_u=new Node(val_u);
            temp_v=new Node(val_v);
            node_list.push_back(temp_u);
            node_list.push_back(temp_v);
            edge_list.push_back(new Edge(temp_u,temp_v,w_el));
        }
        else
        {
            temp_u=find_node_in_list(val_u);
            temp_v=find_node_in_list(val_v);
            if(temp_u==NULL && temp_v==NULL)
            {
                temp_u=new Node(val_u);
                temp_v=new Node(val_v);
                node_list.push_back(temp_u);
                node_list.push_back(temp_v);
            }
            else if(temp_u!=NULL && temp_v==NULL)
            {
                temp_v=new Node(val_v);
                node_list.push_back(temp_v);
            }
            else if(temp_u==NULL && temp_v!=NULL)
            {
                temp_u=new Node(val_u);
                node_list.push_back(temp_u);
            }
            else
            {
                //both the nodes are already created and are found in the temp_u, temp_v variables
            }
            edge_list.push_back(new Edge(temp_u,temp_v,w_el));
        }
    }
    int mst_kruskal()
    {
        int mst_weight=0;
        for(auto i=node_list.begin();i!=node_list.end();i++)
        {
            Node* temp=*i;
            make_set(temp);
        }
        edge_list.sort(Compare_the_edges);
        for(auto i=edge_list.begin();i!=edge_list.end();i++)
        {
            Node* temp_u=(*i)->source;
            Node* temp_v=(*i)->destination;
            if(find_set(temp_u)!=find_set(temp_v))
            {
                make_union(temp_u,temp_v);
                mst_weight+=(*i)->weight;
            }
        }
        return mst_weight;
    }
};
int main()
{
    Graph obj;
    obj.push_edge('a','b',4);
    obj.push_edge('a','h',8);
    obj.push_edge('b','c',8);
    obj.push_edge('b','h',11);
    obj.push_edge('c','i',2);
    obj.push_edge('c','d',7);
    obj.push_edge('c','f',4);
    obj.push_edge('d','e',9);
    obj.push_edge('d','f',14);
    obj.push_edge('e','f',10);
    obj.push_edge('f','g',2);
    obj.push_edge('g','i',6);
    obj.push_edge('g','h',1);
    obj.push_edge('h','i',7);

    int mst_weight=obj.mst_kruskal();
    cout<<"The weight of the minimum spanning tree is= "<<mst_weight<<endl;
    return 0;
}