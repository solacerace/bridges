#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct GraphNode
{
	int label;
	vector<GraphNode*> neighbours;
	
	GraphNode(int l): label(l), neighbours()
	{
	}
};


GraphNode* DFS(GraphNode* node, 
	unordered_map<GraphNode*, GraphNode*>& visited)
{

	unordered_map<GraphNode*, GraphNode*>::iterator 
	iter = visited.find(node);
	if ( iter != visited.end())
	{
		return iter->second;
	}
	
	GraphNode* newNode = new GraphNode(node->label);
	visited.insert(make_pair(node, newNode));
	for(auto&& neig: node->neighbours)
	{
		newNode->neighbours.push_back(DFS(neig, visited));
	}
	
	return newNode;
}


GraphNode* cloneGraph(GraphNode* node)
{
	unordered_map<GraphNode*, GraphNode*> visited;
	
	return DFS(node,visited );

}

void printGraphRec(GraphNode* node, 
	unordered_set<GraphNode*>& printed)
{
	
	if (printed.find(node) != printed.end())
	{
		return;
	}
	
	printed.insert(node);
	cout << "Label [" << node->label << "]==>" ;
	for(auto&& neig : node->neighbours)
	{
		cout << neig->label << ", ";
	}
	cout << endl;
	for(auto&& neig : node->neighbours)
	{
		printGraphRec(neig, printed);
	}
	
	
}


void printGraph(GraphNode* node)
{
	unordered_set<GraphNode*> printed;
	printGraphRec(node, printed);
}

int main(int argc, char* argv[])
{
	
	// 
	GraphNode* node1 = new GraphNode(1);
	GraphNode* node2 = new GraphNode(2);
	GraphNode* node3 = new GraphNode(3);
	
	node1->neighbours.push_back(node2);
	node1->neighbours.push_back(node3);
	
	node2->neighbours.push_back(node1);
	node2->neighbours.push_back(node3);
	
	node3->neighbours.push_back(node1);
	node3->neighbours.push_back(node2);
	
	GraphNode* cGraph = cloneGraph(node1);
	
	printGraph(node1);
	
	printGraph(cGraph);
	
	
	return 0;	
}




