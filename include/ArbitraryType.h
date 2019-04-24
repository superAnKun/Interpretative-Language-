#ifndef ARBITRARY_H
#define ARBITRARY_H
#include "global.h"
#include <vector>
#include <string>
using namespace std;
class Number;
class String;
class Object {
public:
    Object();
    virtual ~Object();
    virtual string output();
    class IVisitor {
    public:
//        virtual shared_ptr<Object> Visit(Number*) = 0;
        virtual shared_ptr<Object> Visit(Object*) = 0;
        virtual shared_ptr<Object> Visit(String*) = 0;
        virtual shared_ptr<Object> Visit(Integer*) = 0;

        virtual shared_ptr<Object> Visit(Integer*, Integer*) = 0;
        virtual shared_ptr<Object> Visit(String*, Integer*) = 0;
    };
    virtual shared_ptr<Object> accept(IVisitor*);
    virtual shared_ptr<Object> accept(IVisitor*, Object*);
    virtual shared_ptr<Object> accept(IVisitor*, Integer*);
    virtual shared_ptr<Object> accept(IVisitor*, String*);
    virtual int isZero();
private:
    string s;
};

/*
class Number : public Object {
public:
    Number(string s);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual bool operator> (Object* obj);
    virtual bool operator>= (Object* obj);
    virtual bool operator== (Object* obj);
    virtual bool operator< (Object* obj);
    virtual bool operator<= (Object* obj);
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
*/

class Integer : public Object {
public:
    Integer(string s);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    bool operator> (Integer*);
    bool operator>= (Integer*);
    bool operator< (Integer*);
    bool operator<= (Integer*);
    shared_ptr<Object> operator+ (Integer*);
    shared_ptr<Object> operator- (Integer*);
    shared_ptr<Object> operator* (Integer*);
    shared_ptr<Object> operator/ (Integer*);
private:
    int value;
};

class String : public Object {
public:
    String(string s);
    virtual string output();
    virtual shared_ptr<Object> operator+(Object* obj);
    virtual bool operator==(Object* obj);
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual int isZero();
private:
    string s;
};

#endif
