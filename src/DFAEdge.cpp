#include "../include/DFAEdge.h"
#include <iostream>
using namespace std;
DFANode::DFANode(pANTLR3_BASE_TREE node) {
    this->tree = node;
}

shared_ptr<DFANode> DFANode::forward(ExprTreeEvaluator* eval) {
    this->status = eval->run(this->tree);
    eval->setStatus(this->status);
    for (shared_ptr<Edge> i = this->edge; i != nullptr; i = i->next) {
        if (i->check(this->status)) return i->node.lock();
    }
    if (this->edge == nullptr) return nullptr;
    cout << "return status is not edge match!" << endl;
    return nullptr;
}

void DFANode::addEdge(Type type, shared_ptr<DFANode> node) {
    shared_ptr<Edge> newEdge = make_shared<Edge>(type, node);
    newEdge->next = edge;
    edge = newEdge;
}

Edge::Edge(Type type, shared_ptr<DFANode> node) {
    this->type = type;
    this->node = node;
}

bool Edge::check(Status status) {
    switch (this->type) {
        case Type::OK:
            return this->type == status.type;
        case Type::YES:
            return status.value != nullptr;
        case Type::NO: 
            return status.value == nullptr;
    }
    if (this->type == status.type) return true;
    return false;
}

