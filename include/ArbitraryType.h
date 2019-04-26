#ifndef ARBITRARY_H
#define ARBITRARY_H
#include "global.h"
#include <vector>
#include <string>
using namespace std;
class String;
class Integer;
class Array;

class Object {
public:
    Object();
    virtual ~Object();
    virtual string output();
    class IVisitor {
    public:
        virtual shared_ptr<Object> Visit(Object*);
        virtual shared_ptr<Object> Visit(String*);
        virtual shared_ptr<Object> Visit(Integer*);
        virtual shared_ptr<Object>& Visit(Array*);

        virtual shared_ptr<Object> Visit(Integer*, Integer*);
        virtual shared_ptr<Object> Visit(String*, String*);
        virtual shared_ptr<Object> Visit(String*, Integer*);
    };
    virtual shared_ptr<Object> accept(IVisitor*);
    //virtual shared_ptr<Object>& accept(IVisitor*);
    virtual shared_ptr<Object> accept(IVisitor*, Object*);
    virtual shared_ptr<Object> accept(IVisitor*, Integer*);
    virtual shared_ptr<Object> accept(IVisitor*, String*);
    virtual int isZero();
private:
    string s;
};



class Integer : public Object {
public:
    Integer(string);
    Integer(int);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual shared_ptr<Object> accept(Object::IVisitor*, Integer*); //Integer OP Integer
    virtual shared_ptr<Object> accept(Object::IVisitor*, String*);  //String OP Integer
    bool operator> (Integer*);
    bool operator>= (Integer*);
    bool operator< (Integer*);
    bool operator<= (Integer*);
    bool operator== (Integer*);
    bool operator!= (Integer*);
    shared_ptr<Object> operator+ (Integer*);
    shared_ptr<Object> operator- (Integer*);
    shared_ptr<Object> operator* (Integer*);
    shared_ptr<Object> operator/ (Integer*);
    shared_ptr<Object> operator% (Integer*);
    virtual int isZero();
private:
    int value;
};


class String : public Object {
public:
    String(string s);
    String(double);
    String(int);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual shared_ptr<Object> accept(Object::IVisitor*, String*);  //String OP Integer

    bool operator> (String*);
    bool operator>= (String*);
    bool operator< (String*);
    bool operator<= (String*);
    bool operator== (String*);
    bool operator!= (String*);
    shared_ptr<Object> operator+ (Integer*);
    shared_ptr<Object> operator+ (String*);
    virtual int isZero();
private:
    string s;
};

class Array : public Object {
public:
    Array(int n);
    Array();
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    shared_ptr<Object>& operator[](int idx);
    virtual int isZero();
private:
    vector<shared_ptr<Object>> v;
};

#endif
