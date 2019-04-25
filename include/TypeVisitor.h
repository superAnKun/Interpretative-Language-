#ifndef __TYPE_VISITOR_H_
#define __TYPE_VISITOR_H_
#include "ArbitraryType.h"

class AddVisitor : public Object::IVisitor {
public:
    AddVisitor(shared_ptr<Object>);
    AddVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(String*, String*);
    virtual shared_ptr<Object> Visit(String*, Integer*);
private:
    shared_ptr<Object> obj;
};

class SubVisitor : public Object::IVisitor {
public:
    SubVisitor(shared_ptr<Object>);
    SubVisitor();
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
private:
    shared_ptr<Object> obj;
};

class TimeVisitor : public Object::IVisitor {
public:
    TimeVisitor();
    TimeVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
private:
    shared_ptr<Object> obj;
};

class DivVisitor : public Object::IVisitor {
public:
    DivVisitor(shared_ptr<Object>);
    DivVisitor();
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
private:
    shared_ptr<Object> obj;
};

class GTVisitor : public Object::IVisitor {
public:
    GTVisitor(shared_ptr<Object>);
    GTVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(String*, String*);
private:
    shared_ptr<Object> obj;
};

class GEQVisitor : public Object::IVisitor {
public:
    GEQVisitor(shared_ptr<Object>);
    GEQVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(String*, String*);
private:
    shared_ptr<Object> obj;
};

class EQVisitor : public Object::IVisitor {
public:
    EQVisitor(shared_ptr<Object>);
    EQVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(String*, String*);
private:
    shared_ptr<Object> obj;
};

class LSVisitor : public Object::IVisitor {
public:
    LSVisitor(shared_ptr<Object>);
    LSVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(String*, String*);
private:
    shared_ptr<Object> obj;
};

class LEQVisitor : public Object::IVisitor {
public:
    LEQVisitor(shared_ptr<Object>);
    LEQVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(String*, String*);
private:
    shared_ptr<Object> obj;
};

#endif
