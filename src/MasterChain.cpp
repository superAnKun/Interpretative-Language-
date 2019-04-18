#include "../include/master_chain.h"
#include "../include/dfa.h"
//#include "../include/ArbitraryType.h"
#include "../include/TypeVisitor.h"
MasterChain* MasterChain::master = nullptr;

MasterChain::MasterChain() {
    this->factory = new ExprFactory();
    this->factory->next = new ConditionExprFactory();
    this->factory->next->next = new BranchExprFactory();
    this->factory->next->next->next = new LoopExprFactory();
    this->factory->next->next->next->next = nullptr;
}

MasterChain::~MasterChain() {
    Factory* f;
    while (this->factory) {
        f = this->factory;
        this->factory = f->next;
        delete f;
    }
}

Status MasterChain::valid(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree) {
    Factory* f = this->factory;
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    while (f) {
        if (f->test(tok)) {
            Calculate* cal = f->create();
            Status ret = cal->getResult(eval, tree);
            f->destory(cal);
            return ret; 
        }
        f = f->next;
    }
    cout << "ERROR: " << tok->toString(tok)->chars << endl;
    return {Type::OK, nullptr};
}

bool ExprFactory::test(pANTLR3_COMMON_TOKEN token) {
    switch(token->type) {
    case INT:
    case ID:
    case PLUS:
    case MINUS:
    case TIMES:
    case DIV:
    case ASSIGN:
        return true;
    }
    return false;
}

Calculate* ExprFactory::create() {
    ExprCalculate* expr = new ExprCalculate();
    return expr;
}

void ExprFactory::destory(Calculate* cal) {
    delete cal;
}

Status ExprFactory::ExprCalculate::getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    switch(tok->type) {
    case INT: {
        const char* s = getText(tree);
        shared_ptr<Number> p = make_shared<Number>(s);
        return {Type::OK, p};
    }
    case ID: {
        return {Type::OK, eval->getValue(tree)};
    }
    case PLUS: {
        AddVisitor add(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&add);
        return {Type::OK, p};
    }
    case MINUS: {
        SubVisitor sub(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&sub);
        return {Type::OK, p};
        //return {Type::OK, eval->run(getChild(tree,0)).value - eval->run(getChild(tree,1)).value};
    }
    case TIMES:{
        return {Type::OK, nullptr};
        //return {Type::OK, eval->run(getChild(tree,0)).value * eval->run(getChild(tree,1)).value};
    }
    case DIV: {
        return {Type::OK, nullptr};
    //    return {Type::OK, eval->run(getChild(tree, 0)).value / eval->run(getChild(tree, 1)).value};
    }
    case ASSIGN: {
        string var(getText(getChild(tree,0)));
        shared_ptr<Object> val = eval->run(getChild(tree,1)).value;
        eval->setValue(var, val);
        return {Type::OK, val};
    }
    default:
        cout << "Unhandled token: #" << tok->type << '\n';
        return {Type::OK, nullptr};
    }
}

//ConditionExprFactory
bool ConditionExprFactory::test(pANTLR3_COMMON_TOKEN token) {
    switch (token->type) {
    case GT:
    case GEQ:
    case LS:
    case LEQ:
    case EQ:
    case OR:
    case AND:
    case NOT:
        return true;
    }
    return false;
}

Calculate* ConditionExprFactory::create() {
    return new ConditionExprCalculate();
}

void ConditionExprFactory::destory(Calculate* cal) {
    delete cal;
}

Status ConditionExprFactory::ConditionExprCalculate::getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    switch (tok->type) {
    case GT:{
    //    int left = eval->run(getChild(tree, 0)).value;
    //    int right = eval->run(getChild(tree, 1)).value;
        return {Type::OK, nullptr};
    }
    case GEQ:{
     //   int left = eval->run(getChild(tree, 0)).value;
     //   int right = eval->run(getChild(tree, 1)).value;
     //   return {Type::OK, left >= right};
        return {Type::OK, nullptr};
    }
    case LS:{
    //    int left = eval->run(getChild(tree, 0)).value;
    //    int right = eval->run(getChild(tree, 1)).value;
    //    return {Type::OK, left < right};
        return {Type::OK, nullptr};
    }
    case LEQ:{
     //`   int left = eval->run(getChild(tree, 0)).value;
     //`   int right = eval->run(getChild(tree, 1)).value;
     //`   return {Type::OK, left <= right};
        return {Type::OK, nullptr};
    }
    case EQ: {
       // int left = eval->run(getChild(tree, 0)).value;
       // int right = eval->run(getChild(tree, 1)).value;
       // return {Type::OK, left == right};
        return {Type::OK, nullptr};
    }
    case OR:{       
      //  int left = eval->run(getChild(tree, 0)).value;
      //  int right = eval->run(getChild(tree, 1)).value;
      //  return {Type::OK, left || right};
        return {Type::OK, nullptr};
    }
    case AND:{
      //  int left = eval->run(getChild(tree, 0)).value;
      //  int right = eval->run(getChild(tree, 1)).value;
      //  return {Type::OK, left && right};
        return {Type::OK, nullptr};
    }
    case NOT:{
       // int ret = eval->run(getChild(tree, 0)).value;
       // return {Type::OK, !ret};
        return {Type::OK, nullptr};
    }
    default:
        cout << "Unhandled token: #" << tok->type << '\n';
        return {Type::OK, nullptr};
    }
}

//BranchExprFactory
bool BranchExprFactory::test(pANTLR3_COMMON_TOKEN token) {
    switch (token->type) {
    case IF:
    case BLOCK:
    case DEF:
    case PRINT:
        return true;
    }
    return false;
}
Calculate* BranchExprFactory::create() {
    return new BranchExprCalculate();
}
void BranchExprFactory::destory(Calculate* c) {
    delete c;
}

Status BranchExprFactory::BranchExprCalculate::getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN token = tree->getToken(tree);
    switch (token->type) {
         case BLOCK:{
             ExprTreeEvaluator e(eval);
             BranchExprConverter converter;
             shared_ptr<DFANode> p = converter.convert(tree);
             while (p) p = p->forward(&e);
             return e.getStatus();
         }
         case DEF:{
             int k = tree->getChildCount(tree);
             for (int i = 0; i < k; i++) {
                 pANTLR3_BASE_TREE child = getChild(tree, i);
                 pANTLR3_COMMON_TOKEN tok = child->getToken(child);
                 if (tok->type == ID) {
                     string var(getText(child));
                     eval->setValue(var, 0);
                 } else if (tok->type == ASSIGN){
                      eval->run(child);
                 }
             }
             return {Type::OK, nullptr};
         }
         case IF:{
             if (eval->run(getChild(tree, 0)).value) {
                 return eval->run(getChild(tree, 1));
             } else if (tree->getChildCount(tree) == 3) {
                 return eval->run(getChild(tree, 2));
             }
             return {Type::OK, nullptr};
         }
         case PRINT:{
             int k = tree->getChildCount(tree);
             for (int i = 0; i < k; i++) {
                 cout << eval->run(getChild(tree, i)).value << endl;
             }
             return {Type::OK, nullptr};
         }
         default:
             cout << "Unhandled token: #" << token->type << '\n';
             return {Type::OUT, nullptr};
         }
}

//LoopExprFactory.....
bool LoopExprFactory::test(pANTLR3_COMMON_TOKEN token) {
    switch (token->type) {
    case FOR:
    case WHILE:
    case BREAK:
    case CONTINUE:
        return true;
    }
    return false;
}

Calculate* LoopExprFactory::create() {
    return new LoopExprCalculate();
}

void LoopExprFactory::destory(Calculate* c) {
    delete c;
}

Status LoopExprFactory::LoopExprCalculate::getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN token = tree->getToken(tree);
    switch (token->type) {
    case FOR: {
        int k = tree->getChildCount(tree);
        if (k != 4) return {Type::OUT, nullptr};
        ExprTreeEvaluator e(eval);
        LoopConverter c;
        shared_ptr<DFANode> p = c.convert(tree);
        while (p) p = p->forward(&e);

        //不管是正常循环结束还是通过break结束循环 都是正常的跳出循环 对外层dfa会产生相同的影响
        return {Type::OK, e.getStatus().value};
    }
    case WHILE: {
        int k = tree->getChildCount(tree);
        if (k != 2) return {Type::OUT, nullptr};
        ExprTreeEvaluator e(eval);
        LoopConverter c;
        shared_ptr<DFANode> p = c.convert(tree);
        while (p) p = p->forward(&e);
        return {Type::OK, e.getStatus().value};
    }
    case BREAK:
        return {Type::BREAKL, nullptr};
    case CONTINUE:
        return {Type::CONTINUEL, nullptr};
    default:
        cout << "Unhandled token: #" << token->type << '\n';
        return {Type::OUT, nullptr};
    }
}
