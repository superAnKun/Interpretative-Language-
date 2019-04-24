#include "../include/TypeVisitor.h"
AddVisitor::AddVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> AddVisitor::Visit(Number* p) {
    return p->operator+(this->obj.get());
}

shared_ptr<Object> AddVisitor::Visit(String* s) {
    return s->operator+(this->obj.get());
}

//--------------------------------------------------
SubVisitor::SubVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> SubVisitor::Visit(Number* p) {
    return p->operator-(this->obj.get());
}

shared_ptr<Object> SubVisitor::Visit(String* s) {
    return nullptr;
}

//----------------------------------------------------

TimeVisitor::TimeVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> TimeVisitor::Visit(Number* p) {
    return p->operator*(this->obj.get());
}

shared_ptr<Object> TimeVisitor::Visit(String* s) {
    return nullptr;
}

//---------------------------------------------------
DivVisitor::DivVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> DivVisitor::Visit(Number* p) {
    return p->operator/(this->obj.get());
}


shared_ptr<Object> DivVisitor::Visit(String* s) {
    return nullptr;
}

//---------------------------------------------------
GTVisitor::GTVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> GTVisitor::Visit(Number* p) {
    if (p->operator>(this->obj.get())) return make_shared<Number>("1");
    return make_shared<Number>("0");
}

shared_ptr<Object> GTVisitor::Visit(String* s) {
    return nullptr;
}

//---------------------------------------------------
GEQVisitor::GEQVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> GEQVisitor::Visit(Number* p) {
    if (p->operator>=(this->obj.get())) return make_shared<Number>("1");
    return make_shared<Number>("0");
}

shared_ptr<Object> GEQVisitor::Visit(String* s) {
    return nullptr;
}
//-------------------------------------------------------

EQVisitor::EQVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> EQVisitor::Visit(Number* p) {
    if (p->operator==(this->obj.get())) return make_shared<Number>("1");
    return make_shared<Number>("0");
}

shared_ptr<Object> EQVisitor::Visit(String* s) {
    if (s->operator==(this->obj.get())) return make_shared<Number>("1");
    return make_shared<Number>("0");
}
//-------------------------------------------------------

LSVisitor::LSVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> LSVisitor::Visit(Number* p) {
    if (p->operator< (this->obj.get())) return make_shared<Number>("1");
    return make_shared<Number>("0");
}

shared_ptr<Object> LSVisitor::Visit(String* s) {
    return nullptr;
}

//------------------------------------------------------
LEQVisitor::LEQVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> LEQVisitor::Visit(Number* p) {
    if (p->operator<= (this->obj.get())) return make_shared<Number>("1");
    return make_shared<Number>("0");
}

shared_ptr<Object> LEQVisitor::Visit(String* s) {
    return nullptr;
}

