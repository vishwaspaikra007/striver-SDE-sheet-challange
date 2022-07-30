// striver SDE sheet challange Clone Graph
// author Vishwas Paikra
/***************************************************************************

    Class for graph node is as follows:

    class graphNode
    {
        public:
            int data;
        vector<graphNode *> neighbours;
        graphNode()
        {
            data = 0;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val)
        {
            data = val;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val, vector<graphNode *> neighbours)
        {
            data = val;
            this->neighbours = neighbours;
        }
    };

******************************************************************************/
graphNode * dfs(graphNode *node, unordered_map<int, graphNode *> &chk) {
    graphNode *clone = new graphNode(node->data);
    chk[node->data] = clone;
    for(graphNode *neighbour : node->neighbours) {
        if(!chk[neighbour->data]) {
            clone->neighbours.push_back(dfs(neighbour, chk));
        } else {
            clone->neighbours.push_back(chk[neighbour->data]);
        }
    }
    return clone;
}
graphNode *cloneGraph(graphNode *node)
{
    if(!node) return NULL;
    unordered_map<int, graphNode *> chk;
    return dfs(node, chk);
}
