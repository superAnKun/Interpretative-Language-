#ifndef ARBITRARY_H
#define ARBITRARY_H
#include <vector>
#include <string>
#include "global.h"
using namespace std;
class String;
class Integer;
class Array;
class Function;
class Char;
class Double;

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
        virtual shared_ptr<Object> Visit(Function*);
        virtual shared_ptr<Object> Visit(Char*);
        virtual shared_ptr<Object> Visit(Double*);

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
    };
    virtual shared_ptr<Object> accept(IVisitor*);
    //virtual shared_ptr<Object>& accept(IVisitor*);
    virtual shared_ptr<Object> accept(IVisitor*, Object*);
    virtual shared_ptr<Object> accept(IVisitor*, Integer*);
    virtual shared_ptr<Object> accept(IVisitor*, String*);
    virtual shared_ptr<Object> accept(IVisitor*, Char*);
    virtual shared_ptr<Object> accept(IVisitor*, Double*);
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
    virtual shared_ptr<Object> accept(Object::IVisitor*, Char*);  //Char OP Integer
    virtual shared_ptr<Object> accept(Object::IVisitor*, Double*);  //Double OP Integer

    virtual int isZero();
    int getValue();
private:
    int value;
};

class Char : public Object {
public:
    Char(char c);
    Char(string);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual shared_ptr<Object> accept(Object::IVisitor*, Integer*); //Integer OP Char
    virtual shared_ptr<Object> accept(Object::IVisitor*, String*);  //String OP Char
    virtual shared_ptr<Object> accept(Object::IVisitor*, Char*);   //Char OP Char
    virtual shared_ptr<Object> accept(Object::IVisitor*, Double*);   //Char OP Char
    char getValue();

    virtual int isZero();
private:
    char value;
};

class Double : public Object {
public:
    Double(double c);
    Double(string);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual shared_ptr<Object> accept(Object::IVisitor*, Integer*); //Integer OP Char
    virtual shared_ptr<Object> accept(Object::IVisitor*, String*);  //String OP Char
    virtual shared_ptr<Object> accept(Object::IVisitor*, Char*);   //Char OP Char
    virtual shared_ptr<Object> accept(Object::IVisitor*, Double*);   //Char OP Char
    double getValue();
    virtual int isZero();
private:
    double value;
};


class String : public Object {
public:
    String(string s);
    String(double);
    String(int);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual shared_ptr<Object> accept(Object::IVisitor*, String*);  //String OP String
    virtual shared_ptr<Object> accept(Object::IVisitor*, Integer*);  //Integer OP String
    virtual shared_ptr<Object> accept(Object::IVisitor*, Char*);  //Char OP String
    virtual shared_ptr<Object> accept(Object::IVisitor*, Double*);  //Double OP String

    bool operator> (String*);
    bool operator>= (String*);
    bool operator< (String*);
    bool operator<= (String*);
    bool operator== (String*);
    bool operator!= (String*);
    char& operator[](int idx);
    shared_ptr<Object> operator+ (Integer*);
    shared_ptr<Object> operator+ (String*);
    virtual int isZero();
    string getValue();
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

class Function : public Object {
public:
    Function(pANTLR3_BASE_TREE, vector<string>);
    virtual string output();
    virtual shared_ptr<Object> accept(Object::IVisitor*);
    virtual int isZero();
    shared_ptr<Object> runFunc(vector<shared_ptr<Object>>&, ExprTreeEvaluator*);
private:
//    ExprTreeEvaluator e;
    pANTLR3_BASE_TREE node;
    vector<string> param;
};

#endif
