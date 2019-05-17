#ifndef __TYPE_VISITOR_H_
#define __TYPE_VISITOR_H_
#include "ArbitraryType.h"

class AddVisitor : public Object::IVisitor {
public:
    AddVisitor(shared_ptr<Object>);
    AddVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);
    virtual shared_ptr<Object> Visit(Char*);
   

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Char*);
    virtual shared_ptr<Object> Visit(Integer*, String*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);

    virtual shared_ptr<Object> Visit(String*, String*);
    virtual shared_ptr<Object> Visit(String*, Integer*);
    virtual shared_ptr<Object> Visit(String*, Char*);
    virtual shared_ptr<Object> Visit(String*, Double*);
    
    virtual shared_ptr<Object> Visit(Char*, String*);
    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);
    virtual shared_ptr<Object> Visit(Char*, Char*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
    virtual shared_ptr<Object> Visit(Double*, Char*);
    virtual shared_ptr<Object> Visit(Double*, String*);
private:
    shared_ptr<Object> obj;
};

class SubVisitor : public Object::IVisitor {
public:
    SubVisitor(shared_ptr<Object>);
    SubVisitor();
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);
    virtual shared_ptr<Object> Visit(Char*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Char*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);


    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);
    virtual shared_ptr<Object> Visit(Char*, Char*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
    virtual shared_ptr<Object> Visit(Double*, Char*);
private:
    shared_ptr<Object> obj;
};

class TimeVisitor : public Object::IVisitor {
public:
    TimeVisitor();
    TimeVisitor(shared_ptr<Object>);
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);


    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
private:
    shared_ptr<Object> obj;
};

class DivVisitor : public Object::IVisitor {
public:
    DivVisitor(shared_ptr<Object>);
    DivVisitor();
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);


    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
private:
    shared_ptr<Object> obj;
};

class ModVisitor : public Object::IVisitor {
public:
    ModVisitor(shared_ptr<Object>);
    ModVisitor();
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
    virtual shared_ptr<Object> Visit(Double*);
    virtual shared_ptr<Object> Visit(Char*);
   

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Char*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);

    virtual shared_ptr<Object> Visit(String*, String*);
    
    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);
    virtual shared_ptr<Object> Visit(Char*, Char*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
    virtual shared_ptr<Object> Visit(Double*, Char*);
private:
    shared_ptr<Object> obj;
};

class GEQVisitor : public Object::IVisitor {
public:
    GEQVisitor(shared_ptr<Object>);
    GEQVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);
    virtual shared_ptr<Object> Visit(Char*);
   

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Char*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);

    virtual shared_ptr<Object> Visit(String*, String*);
    
    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);
    virtual shared_ptr<Object> Visit(Char*, Char*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
    virtual shared_ptr<Object> Visit(Double*, Char*);
private:
    shared_ptr<Object> obj;
};

class EQVisitor : public Object::IVisitor {
public:
    EQVisitor(shared_ptr<Object>);
    EQVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);
    virtual shared_ptr<Object> Visit(Char*);
   

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Char*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);

    virtual shared_ptr<Object> Visit(String*, String*);
    
    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);
    virtual shared_ptr<Object> Visit(Char*, Char*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
    virtual shared_ptr<Object> Visit(Double*, Char*);
private:
    shared_ptr<Object> obj;
};

class NEQVisitor : public Object::IVisitor {
public:
    NEQVisitor(shared_ptr<Object>);
    NEQVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);
    virtual shared_ptr<Object> Visit(Char*);
   

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Char*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);

    virtual shared_ptr<Object> Visit(String*, String*);
    
    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);
    virtual shared_ptr<Object> Visit(Char*, Char*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
    virtual shared_ptr<Object> Visit(Double*, Char*);
private:
    shared_ptr<Object> obj;
};

class LSVisitor : public Object::IVisitor {
public:
    LSVisitor(shared_ptr<Object>);
    LSVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);
    virtual shared_ptr<Object> Visit(Char*);
   

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Char*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);

    virtual shared_ptr<Object> Visit(String*, String*);
    
    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);
    virtual shared_ptr<Object> Visit(Char*, Char*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
    virtual shared_ptr<Object> Visit(Double*, Char*);
private:
    shared_ptr<Object> obj;
};

class LEQVisitor : public Object::IVisitor {
public:
    LEQVisitor(shared_ptr<Object>);
    LEQVisitor();
    virtual shared_ptr<Object> Visit(String*);
    virtual shared_ptr<Object> Visit(Integer*);
    virtual shared_ptr<Object> Visit(Double*);
    virtual shared_ptr<Object> Visit(Char*);
   

    virtual shared_ptr<Object> Visit(Integer*, Integer*);
    virtual shared_ptr<Object> Visit(Integer*, Char*);
    virtual shared_ptr<Object> Visit(Integer*, Double*);

    virtual shared_ptr<Object> Visit(String*, String*);
    
    virtual shared_ptr<Object> Visit(Char*, Integer*);
    virtual shared_ptr<Object> Visit(Char*, Double*);
    virtual shared_ptr<Object> Visit(Char*, Char*);

    virtual shared_ptr<Object> Visit(Double*, Double*);
    virtual shared_ptr<Object> Visit(Double*, Integer*);
    virtual shared_ptr<Object> Visit(Double*, Char*);
private:
    shared_ptr<Object> obj;
};

class ArrayElementVisitor : public Object::IVisitor {
public:
    ArrayElementVisitor(int n);
    ArrayElementVisitor(int n, shared_ptr<Object>);
    ArrayElementVisitor();
    virtual shared_ptr<Object>& Visit(Array*);
    virtual shared_ptr<Object> Visit(String*);
private:
    int n;
    shared_ptr<Object> obj;
};

class ArrayElementSetVisitor : public Object::IVisitor {
public:
    ArrayElementSetVisitor(shared_ptr<Object>, int);
    virtual shared_ptr<Object>& Visit(Array*);
    virtual shared_ptr<Object> Visit(String*);
private:
    int idx;
    shared_ptr<Object> obj;
};

class FunCallVisitor : public Object::IVisitor {
public:
    FunCallVisitor(vector<shared_ptr<Object>>& v, ExprTreeEvaluator* eval);
    virtual shared_ptr<Object> Visit(Function*);
private:
    vector<shared_ptr<Object>> v;
    ExprTreeEvaluator* e;
};

#endif
