#ifndef __TYPE_VISITOR_H_
#define __TYPE_VISITOR_H_
#include "ArbitraryType.h"

class AddVisitor : public Object::IVisitor {
public:
    AddVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    //virtual shared_ptr<Object> Visit(Array*);
private:
    shared_ptr<Object> obj;
};

class SubVisitor : public Object::IVisitor {
public:
    SubVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
private:
    shared_ptr<Object> obj;
};


#endif
