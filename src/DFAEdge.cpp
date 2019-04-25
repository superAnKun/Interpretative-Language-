#include "../include/DFAEdge.h"
#include <iostream>
using namespace std;
DFANode::DFANode(pANTLR3_BASE_TREE node) {
    this->tree = node;
}

pANTLR3_BASE_TREE DFANode::getTree() {
    return this->tree;
}

shared_ptr<DFANode> DFANode::forward(ExprTreeEvaluator* eval) {
    this->status = eval->run(this->tree);
    eval->setStatus(this->status);
    for (shared_ptr<Edge> i = this->edge; i != nullptr; i = i->next) {
        if (i->check(this->status, eval)) return i->node.lock();
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

void DFANode::reverse() {
    shared_ptr<Edge> p = this->edge;
    shared_ptr<Edge> q = nullptr;
    Edge temp(Type::OK, nullptr);
    temp.next = nullptr;
    while (p) {
        q = p;
        p = p->next;
        q->next = temp.next;
        temp.next = q;
    }
    this->edge = temp.next;
}

Edge::Edge(Type type, shared_ptr<DFANode> node) {
    this->type = type;
    this->node = node;
}

bool Edge::check(Status status, ExprTreeEvaluator* eval) {
    switch (this->type) {
        case Type::OK:
            return this->type == status.type;
        case Type::YES:
            return status.value != nullptr && status.value->isZero();
        case Type::NO:
            return status.value == nullptr || !status.value->isZero();
        case Type::CASEL: {
            pANTLR3_BASE_TREE tree = this->node.lock()->getTree();
            tree = (pANTLR3_BASE_TREE)tree->getChild(tree, 0);
            shared_ptr<Object> p = eval->run(tree).value;
            EQVisitor visitor(p);
            return !status.value->accept(&visitor)->isZero();
        }
        case Type::DEFAULTL:
            return true;                     
    }
    if (this->type == status.type) return true;
    return false;
}

