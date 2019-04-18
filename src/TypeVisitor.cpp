#include "../include/TypeVisitor.h"

AddVisitor::AddVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> AddVisitor::Visit(Number* p) {
    return p->operator+(obj.get());
}


SubVisitor::SubVisitor(shared_ptr<Object> obj) {
    this->obj = obj;
}

shared_ptr<Object> SubVisitor::Visit(Number* p) {
    return p->operator-(this->obj.get());
}

