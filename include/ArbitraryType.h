#ifndef ARBITRARY_H
#define ARBITRARY_H
#include "global.h"
#include <vector>
using namespace std;
class Number;
class Object {
public:
    Object();
    virtual ~Object();
    virtual string output();
    class IVisitor {
    public:
//        virtual shared_ptr<Object> Visit(Array* p) = 0;
        virtual shared_ptr<Object> Visit(Number* p) = 0;
    };
    virtual shared_ptr<Object> accept(IVisitor*);
private:
    string s;
};

/*
class Array : public Object {
public:
    virtual string output();
    virtual shared_ptr<Object> accept(IVisitor*);
    void addValue(shared_ptr<Object>);
    vector<shared_ptr<Object>>& getValue();
private:
    vector<shared_ptr<Object>> v;
};
*/

class Number : public Object {
public:
    Number(string s);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual shared_ptr<Object> operator> (Object* obj);
    virtual shared_ptr<Object> operator+ (Object* obj);
    virtual shared_ptr<Object> operator- (Object* obj);
    virtual shared_ptr<Object> operator* (Object* obj);
    virtual shared_ptr<Object> operator/ (Object* obj);
    int isZero();
private:
    void add(vector<unsigned char>&, vector<unsigned char>&, vector<unsigned char>&);
    void mul(vector<unsigned char>&, vector<unsigned char>&, vector<unsigned char>&);
    void adjust(shared_ptr<Number>& p);
    vector<unsigned char> num;
    int pos;
};

#endif
