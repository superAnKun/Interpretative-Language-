#ifndef _INCLUDE_MASTER_CHAIN_H
#define _INCLUDE_MASTER_CHAIN_H
#include <cstdio>
#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include "ArbitraryType.h"
#include "global.h"
#include <vector>
using namespace std;

class Calculate {
public:
    virtual Status getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree) = 0;
    pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i) {
        assert(i < tree->getChildCount(tree));
        return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
    }
    const char* getText(pANTLR3_BASE_TREE tree) {
        return (const char*) tree->getText(tree)->chars;
    }
    virtual ~Calculate() {};
};

class Factory {
public:
    virtual bool test(pANTLR3_COMMON_TOKEN) = 0;
    virtual Calculate* create() = 0;
    virtual void destory(Calculate* c) = 0;
    virtual ~Factory() {};
    Factory* next;
};

class MasterChain {
private:
    MasterChain();
    MasterChain(MasterChain& m) {}
    MasterChain(MasterChain&& m) {}
    ~MasterChain();
    static MasterChain* master;
    Factory* factory;
public:
    static MasterChain* getInstance() {
        if (MasterChain::master) return MasterChain::master;
        MasterChain::master = new MasterChain;
        return MasterChain::master;
    }
    static void Destory() {
        MasterChain* m = getInstance();
        m->~MasterChain();
        MasterChain::master = nullptr;
    }
    Status valid(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree);
};


class ExprFactory : public Factory {
public:
    class ExprCalculate : public Calculate {
    public:
        ExprCalculate() {}
        virtual Status getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree);
        virtual ~ExprCalculate() {}
    };
    virtual bool test(pANTLR3_COMMON_TOKEN);
    virtual Calculate* create();
    virtual void destory(Calculate* c);
    virtual ~ExprFactory() {}
};

class ConditionExprFactory : public Factory {
public:
    class ConditionExprCalculate : public Calculate {
        virtual Status getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree);
        virtual ~ConditionExprCalculate() {}
    };
    virtual bool test(pANTLR3_COMMON_TOKEN token);
    virtual Calculate* create();
    virtual void destory(Calculate* c);
    virtual ~ConditionExprFactory() {}
};

class BranchExprFactory : public Factory {
public:
    class BranchExprCalculate : public Calculate {
        virtual Status getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree);
        virtual ~BranchExprCalculate() {}
    };
    virtual bool test(pANTLR3_COMMON_TOKEN token);
    virtual Calculate* create();
    virtual void destory(Calculate* c);
    virtual ~BranchExprFactory() {}
};

class LoopExprFactory : public Factory {
public:
    class LoopExprCalculate : public Calculate {
        virtual Status getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree);
        virtual ~LoopExprCalculate() {}
    };
    virtual bool test(pANTLR3_COMMON_TOKEN token);
    virtual Calculate* create();
    virtual void destory(Calculate* c);
    virtual ~LoopExprFactory() {}
};

class FunctionFactory : public Factory {
public:
    class FunctionCalculate : public Calculate {
        virtual Status getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree);
        virtual ~FunctionCalculate() {}
    };
    virtual bool test(pANTLR3_COMMON_TOKEN token);
    virtual Calculate* create();
    virtual void destory(Calculate* c);
    virtual ~FunctionFactory() {}
};

#endif
