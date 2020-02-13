/*Contruct a graph and determine whether there exists a cycle in this graph*/

#include <vector>

struct Node{
    int label;
    vector<Node*> neighbors;
    Node(int x) : label(x){}; 
};

class Solution {
public:
    bool DFS(Node* node, vector<int> &visit){
        visit[node->label] = 0;
        for(int i=0; i<node->neighbors.size(); i++){
            if(visit[node->neighbors[i]->label] == -1){
                if(DFS(node->neighbors[i], visit) == false){
                    return false;
                }
            }
            else if(visit[node->neighbors[i]->label] == 0){
                return false;
            }
        }
        visit[node->label] = 1;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node*> nodes;
        vector<int> visit; // -1/0/1 means not visited/ visiting/visited
        for(int i=0; i<numCourses; i++){
            nodes.push_back(new Node(i));
            visit.push_back(-1);
        }
        // create directed graph
        for(int i=0; i<prerequisites.size(); i++){
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];
            nodes[second]->neighbors.push_back(nodes[first]);
        }
        for(int i=0; i<nodes.size(); i++){
            if(visit[i] == -1 && !DFS(nodes[i], visit)){
                return false;
            }
        }
        for(int i=0; i<nodes.size(); i++){
            delete nodes[i];
        }
        
        return true;
    }
};
