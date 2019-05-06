#ifndef GLOBAL_H
#define GLOBAL_H
#include <memory>
#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include <map>
using namespace std;

class Object;
enum class Type {
    YES,
    NO,
    BREAKL,
    CONTINUEL,
    IN,
    OUT,
    OK,
    CASEL,
    DEFAULTL,
    RETURN
};

struct Status {
    Type type;
    shared_ptr<Object> value;
};

class ExprTreeEvaluator {
private:
    map<string, shared_ptr<Object>> memory;
    ExprTreeEvaluator* next;
    Status status;
public:
    ExprTreeEvaluator(ExprTreeEvaluator* next): next(next), status({Type::OK, nullptr}) {}
    ExprTreeEvaluator(): next(nullptr) {}
    Status run(pANTLR3_BASE_TREE);
    shared_ptr<Object> getValue(pANTLR3_BASE_TREE);
    void setValue(string&, shared_ptr<Object>);
    void setStatus(Status);
    Status getStatus();
};

#endif
