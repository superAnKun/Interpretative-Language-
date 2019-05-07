#include "../include/master_chain.h"
#include "../include/dfa.h"
#include "../include/TypeVisitor.h"
MasterChain* MasterChain::master = nullptr;
shared_ptr<Object> getArrayElem(pANTLR3_BASE_TREE, ExprTreeEvaluator* eval);
shared_ptr<Object> createArray(pANTLR3_BASE_TREE tree, int len, ExprTreeEvaluator* eval);
MasterChain::MasterChain() {
    this->factory = new ExprFactory();
    this->factory->next = new ConditionExprFactory();
    this->factory->next->next = new BranchExprFactory();
    this->factory->next->next->next = new LoopExprFactory();
    this->factory->next->next->next->next = new FunctionFactory();
    this->factory->next->next->next->next->next = nullptr;
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
    case STRING:
    case PLUS:
    case MINUS:
    case TIMES:
    case DIV:
    case MOD:
    case ASSIGN:
    case MID:
    case ARRELEM:
    case ARRELEMASSIGN:
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
        shared_ptr<Integer> p = make_shared<Integer>(s);
        return {Type::OK, p};
    }
    case ID: {
        return {Type::OK, eval->getValue(tree)};
    }
    case STRING: {
        const char* s = getText(tree);
        string temp(s);
        shared_ptr<String> p = make_shared<String>(string(temp.begin() + 1, temp.end() - 1));
        return {Type::OK, p};
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
    }
    case TIMES: {
        TimeVisitor time(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&time);
        return {Type::OK, p};
    }
    case DIV: {
        DivVisitor div(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&div);
        return {Type::OK, p};
    }
    case MOD: {
        ModVisitor mod(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&mod);
        return {Type::OK, p};
    }
    case ASSIGN: {
        string var(getText(getChild(tree,0)));
        shared_ptr<Object> val = eval->run(getChild(tree,1)).value;
        eval->setValue(var, val);
        return {Type::OK, val};
    }
    case MID: {
        int k = tree->getChildCount(tree);
        shared_ptr<Array> p = make_shared<Array>(k);
        for (int i = 0; i < k; i++) {
            shared_ptr<Object>& temp = p->operator[](i);
            temp = eval->run(getChild(tree, i)).value;
        }
        return {Type::OK, p};
    }
    case ARRELEM: {
        shared_ptr<Object> p = eval->getValue(getChild(tree, 0));       
        if (p == nullptr) {
            p = createArray(tree, 1, eval);
            string var(getText(getChild(tree, 0)));
            eval->setValue(var, p);
            return {Type::OK, p};
        }
        p = getArrayElem(tree, eval);
        return {Type::OK, p};
    }
    case ARRELEMASSIGN: {
        pANTLR3_BASE_TREE arrelem = (pANTLR3_BASE_TREE)tree->getChild(tree, 0);
        shared_ptr<Object> p = eval->run(getChild(tree, 1)).value;
        shared_ptr<Object> p1 = eval->getValue((pANTLR3_BASE_TREE)arrelem->getChild(arrelem, 0));       
        int k = arrelem->getChildCount(arrelem);
        shared_ptr<Object> ans;
        for (int i = 1; i < k - 1; i++) {
            ans = eval->run((pANTLR3_BASE_TREE)arrelem->getChild(arrelem, i)).value;
            int idx = ans->isZero();
            ArrayElementVisitor visitor(idx);
            p1 = p1->accept(&visitor);
        }
        shared_ptr<Object> p2 = eval->run((pANTLR3_BASE_TREE)arrelem->getChild(arrelem, k - 1)).value;
        ArrayElementSetVisitor visitor(p, p2->isZero());
        p1->accept(&visitor);
        return {Type::OK, p};
    }
    default:
        cout << "Unhandled token: #" << tok->type << '\n';
        return {Type::OK, make_shared<Object>()};
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
    case NEQ:
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
        GTVisitor visitor(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&visitor);
        return {Type::OK, p};
    }
    case GEQ:{
        GEQVisitor visitor(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&visitor);
        return {Type::OK, p};
    }
    case LS:{
        LSVisitor visitor(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&visitor);
        return {Type::OK, p};
    }
    case LEQ:{
        LEQVisitor visitor(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&visitor);
        return {Type::OK, p};
    }
    case EQ: {
        EQVisitor visitor(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&visitor);
        return {Type::OK, p};
    }
    case NEQ: {
        NEQVisitor visitor(eval->run(getChild(tree, 1)).value);
        shared_ptr<Object> p = eval->run(getChild(tree, 0)).value->accept(&visitor);
        return {Type::OK, p};
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
                 } else if (tok->type == ARRELEM) {
                     eval->run(child);
                 } 
             }
             return {Type::OK, make_shared<Object>()};
         }
         case IF:{
             if (eval->run(getChild(tree, 0)).value->isZero()) {
                 return eval->run(getChild(tree, 1));
             } else if (tree->getChildCount(tree) == 3) {
                 return eval->run(getChild(tree, 2));
             }
             return {Type::OK, make_shared<Object>()};
         }
         case PRINT:{
             int k = tree->getChildCount(tree);
             shared_ptr<Object> p;
             for (int i = 0; i < k; i++) {
                 p = eval->run(getChild(tree, i)).value;
                 cout << p->output() << endl;
             }
             return {Type::OK, p};
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
    case CASE:
    case DEFAULT:
    case SWITCH:
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
        LoopConverter* c = new LoopConverter;
        shared_ptr<DFANode> p = c->convert(tree);
        while (p) {
            p = p->forward(&e);
        }
        delete c;
        if (e.getStatus().type == Type::RETURNL) return e.getStatus();
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
        if (e.getStatus().type == Type::RETURNL) return e.getStatus();
        return e.getStatus();
    }
    case SWITCH: {
        ExprTreeEvaluator e(eval);
        SwitchExprConverter c;
        shared_ptr<DFANode> p = c.convert(tree);
        while (p) p = p->forward(&e);
        if (e.getStatus().type == Type::RETURNL) return e.getStatus();
        return e.getStatus();
    }
    case CASE: {
        SwitchExprConverter c;
        shared_ptr<DFANode> p = c.convert(tree);
        while (p) p = p->forward(eval);
        return eval->getStatus();
    }
    case DEFAULT: {
        SwitchExprConverter c;
        shared_ptr<DFANode> p = c.convert(tree);
        while (p) p = p->forward(eval);
        return eval->getStatus();
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


/**
 *
 * FunctioinFactory
 *
 */
bool FunctionFactory::test(pANTLR3_COMMON_TOKEN tok) {
    switch (tok->type) {
        case FUN:
        case FUNCALL:
        case RETURN:
            return true;
    }
    return false;
}

Calculate* FunctionFactory::create() {
    return new FunctionCalculate;
}

void FunctionFactory::destory(Calculate* c) {
    delete c;
}
/**
 *
 * FunctionCalculate
 *
 */
Status FunctionFactory::FunctionCalculate::getResult(ExprTreeEvaluator* eval, pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN token = tree->getToken(tree);
    switch (token->type) {
        case FUN: {
            pANTLR3_BASE_TREE block = (pANTLR3_BASE_TREE)tree->getChild(tree, 0);
            vector<string> param;
            int k = tree->getChildCount(tree);
            for (int i = 1; i < k; i++) {
                param.push_back(getText((pANTLR3_BASE_TREE)tree->getChild(tree, i)));
            }
            shared_ptr<Function> f = make_shared<Function>(block, param);     
            return {Type::OK, f};
        }
        case FUNCALL: {
            shared_ptr<Object> func = eval->getValue((pANTLR3_BASE_TREE)tree->getChild(tree, 0));
            int k = tree->getChildCount(tree);
            vector<shared_ptr<Object>> params;
            for (int i = 1; i < k; i++) {
                params.push_back(eval->run(getChild(tree, i)).value);
            }
            ExprTreeEvaluator e(eval);
            FunCallVisitor visitor(params, &e);
            return {Type::OK, func->accept(&visitor)};
        }
        case RETURN: {
             return {Type::RETURNL, eval->run(getChild(tree, 0)).value};             
        }
    }
}

shared_ptr<Object> getArrayElem(pANTLR3_BASE_TREE tree, ExprTreeEvaluator* eval) {
    shared_ptr<Object> p1 = eval->getValue((pANTLR3_BASE_TREE)tree->getChild(tree, 0));       
    int k = tree->getChildCount(tree);
    shared_ptr<Object> p2 = nullptr;
    for (int i = 1; i < k; i++) {
        p2 = eval->run((pANTLR3_BASE_TREE)tree->getChild(tree, i)).value;
        int idx = p2->isZero();
        ArrayElementVisitor visitor(idx);
        p1 = p1->accept(&visitor);
    }
    return p1;
}

shared_ptr<Object> createArray(pANTLR3_BASE_TREE tree, int len, ExprTreeEvaluator* eval) {
    pANTLR3_BASE_TREE node = (pANTLR3_BASE_TREE)tree->getChild(tree, len);
    if (node == nullptr) return make_shared<Object>();
    shared_ptr<Object> p = eval->run((pANTLR3_BASE_TREE)tree->getChild(tree, len)).value;
    int idx = p->isZero();
    shared_ptr<Object> ret = make_shared<Array>(idx);
    for (int i = 0; i < idx; i++) {
        shared_ptr<Object> lvalue = createArray(tree, len + 1, eval);
        ArrayElementVisitor visitor(i, lvalue);
        ret->accept(&visitor);
    }
    return ret;
}











