#ifndef MAIN_CPP
#define MAIN_CPP

#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include "include/master_chain.h"

using std::map;
using std::string;
using std::cout;

/*
class ExprTreeEvaluator {
private:
    map<string,int> memory;
    ExprTreeEvaluator* next;
    Status status;
public:
    ExprTreeEvaluator(ExprTreeEvaluator* next): next(next), status({Type::OK, -1}) {}
    ExprTreeEvaluator(): next(nullptr) {}
    Status run(pANTLR3_BASE_TREE);
    int getValue(pANTLR3_BASE_TREE);
    void setValue(string&, int);
    void setStatus(Status);
    Status getStatus();
};
*/
pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);
  
int main(int argc, char* argv[])
{ 
  pANTLR3_INPUT_STREAM input;
  pExprCppTreeLexer lex;
  pANTLR3_COMMON_TOKEN_STREAM tokens;
  pExprCppTreeParser parser;
  
  assert(argc > 1);
  input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1],ANTLR3_ENC_8BIT);
  lex = ExprCppTreeLexerNew(input);
  
  tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT,
                                            TOKENSOURCE(lex));
  parser = ExprCppTreeParserNew(tokens);
  
  ExprCppTreeParser_prog_return r = parser->prog(parser);
  
  pANTLR3_BASE_TREE tree = r.tree;


  ExprTreeEvaluator eval;
  shared_ptr<Object> rr = eval.run(tree).value;
  cout << "Evaluator result: " << rr->output() << '\n';
  
  parser->free(parser);
  tokens->free(tokens);
  lex->free(lex);
  input->close(input);
  
  return 0;
}
 
Status ExprTreeEvaluator::run(pANTLR3_BASE_TREE tree)
{
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    if(tok) {
        MasterChain* chain = MasterChain::getInstance();
        return chain->valid(this, tree);
    }
    else {
        int k = tree->getChildCount(tree);
        Status r = {Type::OUT, 0};
        for(int i = 0; i < k; i++) {
            r = run(getChild(tree, i));
        }
        return r;
    }
}

shared_ptr<Object> ExprTreeEvaluator::getValue(pANTLR3_BASE_TREE tree) {
    ExprTreeEvaluator* p = this;
    while (p) {
        if (p->memory.find(getText(tree)) != p->memory.end()) {
            return p->memory[getText(tree)];
        }
        p = p->next;
    }
//    p = this;
//    p->memory[getText(tree)] = 250;
    printf("undeclear variable %s in line %d\n", getText(tree), tree->getLine(tree));
    fflush(stdout);
    return nullptr;
}

void ExprTreeEvaluator::setValue(string& key, shared_ptr<Object> value) {
    ExprTreeEvaluator* p = this;
    while (p) {
        if (p->memory.find(key) != p->memory.end()) {
            p->memory[key] = value;
            return;
        }
        p = p->next;
    }
    this->memory[key] = value;
}

void ExprTreeEvaluator::setStatus(Status status) {
    this->status = status;
}

Status ExprTreeEvaluator::getStatus() {
    return this->status;
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i)
{
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}
 
const char* getText(pANTLR3_BASE_TREE tree)
{
    return (const char*) tree->getText(tree)->chars;
}

#endif
