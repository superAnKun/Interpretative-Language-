#ifndef __TYPE_VISITOR_H_
#define __TYPE_VISITOR_H_
#include "ArbitraryType.h"

class AddVisitor : public Object::IVisitor {
public:
    AddVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
    //virtual shared_ptr<Object> Visit(Array*);
private:
    shared_ptr<Object> obj;
};

class SubVisitor : public Object::IVisitor {
public:
    SubVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
private:
    shared_ptr<Object> obj;
};

class TimeVisitor : public Object::IVisitor {
public:
    TimeVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
private:
    shared_ptr<Object> obj;
};

class DivVisitor : public Object::IVisitor {
public:
    DivVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
private:
    shared_ptr<Object> obj;
};

class GTVisitor : public Object::IVisitor {
public:
    GTVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
private:
    shared_ptr<Object> obj;
};

class GEQVisitor : public Object::IVisitor {
public:
    GEQVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
private:
    shared_ptr<Object> obj;
};

class EQVisitor : public Object::IVisitor {
public:
    EQVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
private:
    shared_ptr<Object> obj;
};

class LSVisitor : public Object::IVisitor {
public:
    LSVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
private:
    shared_ptr<Object> obj;
};

class LEQVisitor : public Object::IVisitor {
public:
    LEQVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Number*);
    virtual shared_ptr<Object> Visit(String*);
private:
    shared_ptr<Object> obj;
};

#endif
