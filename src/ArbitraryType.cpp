#include "../include/ArbitraryType.h"
#include <iostream>
#include <cstdio>
using namespace std;

/**
 *
 *Object 
 *
 */
static int obj_count = 0;
static int obj_dec = 0;
Object::Object() {
//    cout << "Object create!!!!!!!     " << obj_count++ << endl;
}

Object::~Object() {
//    cout << "Object destructor!!!!!!   "<< obj_dec++ << endl;
}

shared_ptr<Object> Object::accept(Object::IVisitor* visitor) {
    return visitor->Visit(this);
}

shared_ptr<Object> Object::accept(Object::IVisitor* visitor, Object* obj) {
    return nullptr;
}

shared_ptr<Object> Object::accept(Object::IVisitor* visitor, Integer* obj) {
    return nullptr;
}

shared_ptr<Object> Object::accept(Object::IVisitor* visitor, String* obj) {
    return nullptr;
}


string Object::output() {
    return this->s;
}

int Object::isZero() {
    return this->s.length();
}

/**
 *
 * IVisitor
 *
 */
shared_ptr<Object> Object::IVisitor::Visit(Object* obj) {
    return nullptr;
}

shared_ptr<Object> Object::IVisitor::Visit(String* obj) {
    return nullptr;
}

shared_ptr<Object> Object::IVisitor::Visit(Integer* obj) {
    return nullptr;
}

shared_ptr<Object>& Object::IVisitor::Visit(Array* obj) {
    shared_ptr<Object> ret = make_shared<Object>();
    return ret;
}

shared_ptr<Object> Object::IVisitor::Visit(Function* f) {
    return nullptr;
}

shared_ptr<Object> Object::IVisitor::Visit(Integer* p1, Integer* p2) {
    return nullptr;
}

shared_ptr<Object> Object::IVisitor::Visit(String* s1, String* s2) {
    return nullptr;
}

shared_ptr<Object> Object::IVisitor::Visit(String* s1, Integer* s2) {
    return nullptr;
}

/**
 *
 * Integer
 *
 */

Integer::Integer(string s): value(0) {
    sscanf(s.c_str(), "%d", &value);
}

Integer::Integer(int value) : value(value) {}

string Integer::output() {
    char buf[1024];
    sprintf(buf, "%d", this->value);
    return buf;
}

shared_ptr<Object> Integer::accept(Object::IVisitor* visitor) {
    return visitor->Visit(this);
}

shared_ptr<Object> Integer::accept(Object::IVisitor* visitor, Integer* obj) {
    return visitor->Visit(obj, this);
}

shared_ptr<Object> Integer::accept(Object::IVisitor* visitor, String* obj) {
    return visitor->Visit(obj, this);
}

bool Integer::operator> (Integer* obj) {
    return this->value > obj->value;
}

bool Integer::operator>= (Integer* obj) {
    return this->value >= obj->value;
}

bool Integer::operator< (Integer* obj) {
    return this->value < obj->value;
}

bool Integer::operator<= (Integer* obj) {
    return this->value <= obj->value;
}

bool Integer::operator== (Integer* obj) {
    return this->value == obj->value;
}

bool Integer::operator!= (Integer* obj) {
    return this->value != obj->value;
}

shared_ptr<Object> Integer::operator+ (Integer* obj) {
    int value = this->value + obj->value;
    return make_shared<Integer>(value);
}

shared_ptr<Object> Integer::operator- (Integer* obj) {
    int value = this->value - obj->value;
    return make_shared<Integer>(value);
}

shared_ptr<Object> Integer::operator* (Integer* obj) {
    int value = this->value * obj->value;
    return make_shared<Integer>(value);
}

shared_ptr<Object> Integer::operator/ (Integer* obj) {
    int value = this->value / obj->value;
    return make_shared<Integer>(value);
}

shared_ptr<Object> Integer::operator% (Integer* obj) {
    int value = this->value % obj->value;
    return make_shared<Integer>(value);
}

int Integer::isZero() {
    return this->value;
}

/***
 *
 * String
 *
 */


String::String(string s) : s(s){
}

String::String(double value) {
    char buf[30];
    sprintf(buf, "%lf", value);
    this->s = buf;
}

String::String(int value) {
    char buf[30];
    sprintf(buf, "%d", value);
    this->s = buf;
}

string String::output() {
    return this->s;
}

shared_ptr<Object> String::accept(Object::IVisitor* visitor) {
    return visitor->Visit(this);
}

shared_ptr<Object> String::accept(Object::IVisitor* visitor, String* obj) {
    return visitor->Visit(obj, this);
}

bool String::operator> (String* s) {
    return this->s > s->s;
}

bool String::operator>= (String* s) {
    return this->s >= s->s;
}

bool String::operator< (String* s) {
    return this->s < s->s;
}

bool String::operator<= (String* s) {
    return this->s > s->s;
}

bool String::operator== (String* s) {
    return this->s == s->s;
}

bool String::operator!= (String* s) {
    return this->s != s->s;
}

shared_ptr<Object> String::operator+ (Integer* p) {
    string s = this->s + p->output();
    return make_shared<String>(s);
}

shared_ptr<Object> String::operator+ (String* p) {
    string s = this->s + p->s;
    return make_shared<String>(s);
}

int String::isZero() {
    return s.length();
}

/**
 *
 * Array
 *
 */

Array::Array(int n) : v(n) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = make_shared<Object>();
    }
}

Array::Array() {
}

string Array::output() {
    string s;
    s += "[ ";
    for (int i = 0; i < this->v.size(); i++) {
        s += this->v[i]->output();
    }
    s += " ]";
    return s;
}

shared_ptr<Object> Array::accept(Object::IVisitor* visitor) {
    return visitor->Visit(this);
}

shared_ptr<Object>& Array::operator[](int idx) {
    return this->v[idx];
}

int Array::isZero() {
    return this->v.size();
}

/**
 *
 * Function
 *
 */

Function::Function(pANTLR3_BASE_TREE tree, vector<string> s) :node(tree), param(s) {
}

string Function::output() {
    return "function!!";
}

shared_ptr<Object> Function::accept(Object::IVisitor* visitor) {
    return visitor->Visit(this);
}

int Function::isZero() {
    return true;
}

shared_ptr<Object> Function::runFunc(vector<shared_ptr<Object>>& v, ExprTreeEvaluator* eval) {
    if (v.size() != this->param.size()) return make_shared<Object>();
    map<string, shared_ptr<Object>>& memory = eval->getMap();
    for (int i = 0; i < this->param.size(); i++) {
        memory[this->param[i]] = v[i];
    }
    return eval->run(this->node).value;
}
