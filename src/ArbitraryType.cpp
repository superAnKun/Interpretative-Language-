#include "../include/ArbitraryType.h"
#include <iostream>
#include <cstdio>
using namespace std;

/**
 *
 *Object 
 *
 */
Object::Object() {
}

Object::~Object() {}

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
