#include "../include/TypeVisitor.h"

/**
 *
 * AddVisitor
 *
 */
AddVisitor::AddVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

AddVisitor::AddVisitor() {
}

shared_ptr<Object> AddVisitor::Visit(Integer* p) {
    AddVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> AddVisitor::Visit(String* s) {
    AddVisitor visitor;
    return this->obj->accept(&visitor, s);
}

shared_ptr<Object> AddVisitor::Visit(Integer* p1, Integer* p2) {
    return p1->operator+(p2);
}

shared_ptr<Object> AddVisitor::Visit(String* s1, String* s2) {
    return s1->operator+(s2);
}

shared_ptr<Object> AddVisitor::Visit(String* s, Integer* p) {
    return s->operator+(p);
}

/**
 *
 * SubVisitor
 *
 */

SubVisitor::SubVisitor(shared_ptr<Object> p) {
    this->obj = p;
}

SubVisitor::SubVisitor() {
}

shared_ptr<Object> SubVisitor::Visit(Integer* p) {
    SubVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> SubVisitor::Visit(Integer* p1, Integer* p2) {
    return p1->operator-(p2);
}

/**
 *
 * TimeVisitor
 *
 */

TimeVisitor::TimeVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

TimeVisitor::TimeVisitor() {
}

shared_ptr<Object> TimeVisitor::Visit(Integer* p) {
    TimeVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> TimeVisitor::Visit(Integer* p1, Integer* p2) {
    return p1->operator* (p2);
}


/**
 *
 * DivVisitor
 *
 */

DivVisitor::DivVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

DivVisitor::DivVisitor() {
}

shared_ptr<Object> DivVisitor::Visit(Integer* p) {
    DivVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> DivVisitor::Visit(Integer* p1, Integer* p2) {
    return p1->operator/ (p2);
}

/**
 *
 * ModVisitor
 *
 */

ModVisitor::ModVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

ModVisitor::ModVisitor() {
}

shared_ptr<Object> ModVisitor::Visit(Integer* p) {
    ModVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> ModVisitor::Visit(Integer* p1, Integer* p2) {
    return p1->operator% (p2);
}

/**
 *
 * GTVisitor
 *
 */

GTVisitor::GTVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

GTVisitor::GTVisitor() {
}

shared_ptr<Object> GTVisitor::Visit(String* p) {
    GTVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> GTVisitor::Visit(Integer* p) {
    GTVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> GTVisitor::Visit(Integer* p1, Integer* p2) {
    return make_shared<Integer>(p1->operator> (p2));
}

shared_ptr<Object> GTVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator> (p2));
}

/**
 *
 * GEQVisitor
 *
 */

GEQVisitor::GEQVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

GEQVisitor::GEQVisitor() {
}

shared_ptr<Object> GEQVisitor::Visit(String* s) {
    GEQVisitor visitor;
    return this->obj->accept(&visitor, s);
}

shared_ptr<Object> GEQVisitor::Visit(Integer* p) {
    GEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> GEQVisitor::Visit(Integer* p1, Integer* p2) {
    return make_shared<Integer>(p1->operator>= (p2));
}

shared_ptr<Object> GEQVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator>= (p2));
}

/**
 *
 * EQVisitor
 *
 */

EQVisitor::EQVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

EQVisitor::EQVisitor() {
}

shared_ptr<Object> EQVisitor::Visit(Integer* p) {
    EQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> EQVisitor::Visit(String* p) {
    EQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> EQVisitor::Visit(Integer* p1, Integer* p2) {
    return make_shared<Integer>(p1->operator==(p2));
}

shared_ptr<Object> EQVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator==(p2));
}

/**
 *
 * NEQVisitor
 *
 */

NEQVisitor::NEQVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

NEQVisitor::NEQVisitor() {
}

shared_ptr<Object> NEQVisitor::Visit(Integer* p) {
    NEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> NEQVisitor::Visit(String* p) {
    NEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> NEQVisitor::Visit(Integer* p1, Integer* p2) {
    return make_shared<Integer>(p1->operator!=(p2));
}

shared_ptr<Object> NEQVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator!=(p2));
}

/**
 *
 * LSVisitor
 *
 */

LSVisitor::LSVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

LSVisitor::LSVisitor() {
}

shared_ptr<Object> LSVisitor::Visit(String* p) {
    LSVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> LSVisitor::Visit(Integer* p) {
    LSVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> LSVisitor::Visit(Integer* p1, Integer* p2) {
    return make_shared<Integer>(p1->operator<(p2));
}

shared_ptr<Object> LSVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator<(p2));
}

/**
 *
 * LEQVisitor 
 *
 */

LEQVisitor::LEQVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

LEQVisitor::LEQVisitor() {
}

shared_ptr<Object> LEQVisitor::Visit(String* p) {
    LEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> LEQVisitor::Visit(Integer* p) {
    LEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> LEQVisitor::Visit(Integer* p1, Integer* p2) {
    return make_shared<Integer>(p1->operator<= (p2));
}

shared_ptr<Object> LEQVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator<= (p2));
}


/**
 *
 * ArrayElementVisitor
 *
 */

ArrayElementVisitor::ArrayElementVisitor(int n) : n(n), obj(nullptr){
}

ArrayElementVisitor::ArrayElementVisitor(int n, shared_ptr<Object> obj) {
    this->obj = obj;
    this->n = n;
}

ArrayElementVisitor::ArrayElementVisitor() : n(-1), obj(nullptr) {
}

shared_ptr<Object>& ArrayElementVisitor::Visit(Array* obj) {
    if (this->obj != nullptr) {
        shared_ptr<Object>& p = obj->operator[](this->n);
        p = this->obj;
        return this->obj;
    }
    return obj->operator[](this->n);
}

/**
 *
 * ArrayElementSetVisitor
 *
 * Param obj要赋值的对象 idx数组索引
 */

ArrayElementSetVisitor::ArrayElementSetVisitor(shared_ptr<Object> obj, int idx) {
    this->obj = obj;
    this->idx = idx;
}

shared_ptr<Object>& ArrayElementSetVisitor::Visit(Array* p) {
    p->operator[](this->idx) = this->obj;
    return this->obj;
}

/**
 *
 * FunCallVisitor
 *
 */

FunCallVisitor::FunCallVisitor(vector<shared_ptr<Object>>& v) : v(v) {}

shared_ptr<Object> FunCallVisitor::Visit(Function* f) {
    return f->runFunc(this->v);
}

