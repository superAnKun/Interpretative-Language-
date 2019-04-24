#ifndef __INCLUDE_DFA_H
#define __INCLUDE_DFA_H
#include "master_chain.h"
#include "DFAEdge.h"
#include <vector>
#include <memory>
using namespace std;
class Converter {
public:
    virtual bool test(pANTLR3_COMMON_TOKEN tok) = 0;
    virtual shared_ptr<DFANode> convert(pANTLR3_BASE_TREE tree) = 0;
    virtual ~Converter() {}
protected:
    vector<shared_ptr<DFANode>> v_node;
};

class LoopConverter : public Converter {
public:
    bool test(pANTLR3_COMMON_TOKEN tok);
    shared_ptr<DFANode> convert(pANTLR3_BASE_TREE tree);
};

class BranchExprConverter : public Converter {
public:
    bool test(pANTLR3_COMMON_TOKEN tok);
    shared_ptr<DFANode> convert(pANTLR3_BASE_TREE tree);
};

class SwitchExprConverter : public Converter {
public:
    bool test(pANTLR3_COMMON_TOKEN tok);
    shared_ptr<DFANode> convert(pANTLR3_BASE_TREE);
};

#endif
