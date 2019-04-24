#ifndef __INCLUDE_DFAEDGE_H__
#define __INCLUDE_DFAEDGE_H__
#include <memory>
#include "master_chain.h"
#include "TypeVisitor.h"
#include "global.h"
class ExprTreeEvaluator;
using namespace std;

class DFANode;

class Edge {
public:
    Edge(Type, shared_ptr<DFANode>);
    bool check(Status, ExprTreeEvaluator*);

    weak_ptr<DFANode> node;
    shared_ptr<Edge> next;
    Type type;
};

class DFANode {
public:
    DFANode(pANTLR3_BASE_TREE node);
    shared_ptr<DFANode> forward(ExprTreeEvaluator*);
    void addEdge(Type, shared_ptr<DFANode>);
    pANTLR3_BASE_TREE getTree();
    void reverse();
private:
    pANTLR3_BASE_TREE tree;
    shared_ptr<Edge> edge;
    Status status;
};

#endif
