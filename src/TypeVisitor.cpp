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

shared_ptr<Object> AddVisitor::Visit(Char* c) {
    AddVisitor visitor;
    return this->obj->accept(&visitor, c);
}

shared_ptr<Object> AddVisitor::Visit(Double* d) {
    AddVisitor visitor;
    return this->obj->accept(&visitor, d);
}

//-------------------------------Integer----------------------
shared_ptr<Object> AddVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 + value2);
}

shared_ptr<Object> AddVisitor::Visit(Integer* p1, Char* p2) {
    int value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 + value2);
}

shared_ptr<Object> AddVisitor::Visit(Integer* p1, String* p2) {
    string s = p1->output() + p2->getValue();
    return make_shared<String>(s);
}

shared_ptr<Object> AddVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Double>(value1 + value2);
}

//-----------------------String------------------------------
shared_ptr<Object> AddVisitor::Visit(String* s1, String* s2) {
    return s1->operator+(s2);
}

shared_ptr<Object> AddVisitor::Visit(String* s, Integer* p) {
    return s->operator+(p);
}

shared_ptr<Object> AddVisitor::Visit(String* s, Char* c) {
    string temp = s->getValue();
    temp.push_back(c->getValue());
    return make_shared<String>(temp);
}

shared_ptr<Object> AddVisitor::Visit(String* s, Double* d) {
    string temp = s->getValue();
    double value = d->getValue();
    char buf[30];
    sprintf(buf, "%lf", value);
    temp += buf;
    return make_shared<String>(temp);
}

//------------------------Char------------------------------
shared_ptr<Object> AddVisitor::Visit(Char* c1, Char* c2) {
    char value1 = c1->getValue();
    char value2 = c2->getValue();
    return make_shared<Char>(value1 + value2);
}

shared_ptr<Object> AddVisitor::Visit(Char* c, String* s) {
    char ch = c->getValue();
    string temp = s->getValue();
    temp.insert(temp.begin(), ch);
    return make_shared<String>(temp);
}

shared_ptr<Object> AddVisitor::Visit(Char* c, Double* d) {
    char ch = c->getValue();
    double f = d->getValue();
    return make_shared<Double>(f + ch);
}

shared_ptr<Object> AddVisitor::Visit(Char* c, Integer* obj) {
    char ch = c->getValue();
    int in = obj->getValue();
    return make_shared<Integer>(ch + in);
}

//-------------------------------Double--------------------
shared_ptr<Object> AddVisitor::Visit(Double* obj1, Double* obj2) {
    double value1 = obj1->getValue();
    double value2 = obj2->getValue();
    return make_shared<Double>(value1 + value2);
}

shared_ptr<Object> AddVisitor::Visit(Double* obj1, Integer* obj2) {
    double value1 = obj1->getValue();
    int value2 = obj2->getValue();
    return make_shared<Double>(value1 + value2);
}

shared_ptr<Object> AddVisitor::Visit(Double* obj1, Char* obj2) {
    double value1 = obj1->getValue();
    char value2 = obj2->getValue();
    return make_shared<Double>(value1 + value2);
}

shared_ptr<Object> AddVisitor::Visit(Double* obj1, String* obj2) {
    double value1 = obj1->getValue();
    string value2 = obj2->getValue();
    char buf[20];
    sprintf(buf, "%lf", value1);
    value2.insert(0, buf, strlen(buf));
    return make_shared<String>(value2);
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

shared_ptr<Object> SubVisitor::Visit(Char* p) {
    SubVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> SubVisitor::Visit(Double* p) {
    SubVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//----------------------------Integer-------------------
shared_ptr<Object> SubVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 - value2);
}

shared_ptr<Object> SubVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Double>(value1 - value2);
}

shared_ptr<Object> SubVisitor::Visit(Integer* p1, Char* p2) {
    int value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 - value2);
}

//---------------------------Char-----------------------
shared_ptr<Object> SubVisitor::Visit(Char* p1, Char* p2) {
    char value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Char>(value1 - value2);
}

shared_ptr<Object> SubVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 - value2);
}

shared_ptr<Object> SubVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Double>(value1 - value2);
}

//---------------------------Double---------------------
shared_ptr<Object> SubVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Char>(value1 - value2);
}

shared_ptr<Object> SubVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Double>(value1 - value2);
}

shared_ptr<Object> SubVisitor::Visit(Double* p1, Char* p2) {
    double value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Double>(value1 - value2);
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

shared_ptr<Object> TimeVisitor::Visit(Double* p) {
    TimeVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//-------------------------------Integer----------------------
shared_ptr<Object> TimeVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 * value2);
}

shared_ptr<Object> TimeVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Double>(value1 * value2);
}

//-----------------------------Char------------------------
shared_ptr<Object> TimeVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 * value2);
}

shared_ptr<Object> TimeVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 * value2);
}

//-----------------------------Double---------------------------
shared_ptr<Object> TimeVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Double>(value1 * value2);
}

shared_ptr<Object> TimeVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Double>(value1 * value2);
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

shared_ptr<Object> DivVisitor::Visit(Double* p) {
    DivVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//------------------------------Integer-----------------------
shared_ptr<Object> DivVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 / value2);
}

shared_ptr<Object> DivVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 / value2);
}

//------------------------------Char--------------------------
shared_ptr<Object> DivVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 / value2);
}

shared_ptr<Object> DivVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Double>(value1 / value2);
}


//------------------------------Double-------------------------
shared_ptr<Object> DivVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 / value2);
}

shared_ptr<Object> DivVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 / value2);
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

//----------------------------Integer--------------------
shared_ptr<Object> ModVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 % value2);
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

shared_ptr<Object> GTVisitor::Visit(Char* p) {
    GTVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> GTVisitor::Visit(Double* p) {
    GTVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//---------------------------Integer--------------------------
shared_ptr<Object> GTVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);;
}

shared_ptr<Object> GTVisitor::Visit(Integer* p1, Char* p2) {
    int value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);;
}

shared_ptr<Object> GTVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);;
}

//---------------------------String-----------------
shared_ptr<Object> GTVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator> (p2));
}

//---------------------------Char--------------------
shared_ptr<Object> GTVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);
}

shared_ptr<Object> GTVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);
}

shared_ptr<Object> GTVisitor::Visit(Char* p1, Char* p2) {
    char value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);
}

//---------------------------Double-------------------
shared_ptr<Object> GTVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);
}

shared_ptr<Object> GTVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);
}

shared_ptr<Object> GTVisitor::Visit(Double* p1, Char* p2) {
    double value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 > value2);
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

shared_ptr<Object> GEQVisitor::Visit(Double* p) {
    GEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> GEQVisitor::Visit(Char* p) {
    GEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//-------------------------Integer-------------------------
shared_ptr<Object> GEQVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
}

shared_ptr<Object> GEQVisitor::Visit(Integer* p1, Char* p2) {
    int value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
}

shared_ptr<Object> GEQVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
}

//---------------------------String-------------------
shared_ptr<Object> GEQVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator>= (p2));
}

//--------------------------Char--------------------------
shared_ptr<Object> GEQVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
}

shared_ptr<Object> GEQVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
}

shared_ptr<Object> GEQVisitor::Visit(Char* p1, Char* p2) {
    char value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
}

//-------------------------------double-----------------
shared_ptr<Object> GEQVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
}

shared_ptr<Object> GEQVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
}

shared_ptr<Object> GEQVisitor::Visit(Double* p1, Char* p2) {
    double value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 >= value2);
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

shared_ptr<Object> EQVisitor::Visit(Double* p) {
    EQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> EQVisitor::Visit(Char* p) {
    EQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//------------------------------Integer--------------------------
shared_ptr<Object> EQVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
}

shared_ptr<Object> EQVisitor::Visit(Integer* p1, Char* p2) {
    int value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
}

shared_ptr<Object> EQVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
}

//---------------------------String-----------------------
shared_ptr<Object> EQVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator==(p2));
}

//------------------------------Char------------------------
shared_ptr<Object> EQVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
}

shared_ptr<Object> EQVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
}

shared_ptr<Object> EQVisitor::Visit(Char* p1, Char* p2) {
    char value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
}

//----------------------------Double---------------------
shared_ptr<Object> EQVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
}

shared_ptr<Object> EQVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
}

shared_ptr<Object> EQVisitor::Visit(Double* p1, Char* p2) {
    double value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 == value2);
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

shared_ptr<Object> NEQVisitor::Visit(Double* p) {
    NEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> NEQVisitor::Visit(Char* p) {
    NEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> NEQVisitor::Visit(String* p) {
    NEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//----------------------------Integer--------------------------
shared_ptr<Object> NEQVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
}

shared_ptr<Object> NEQVisitor::Visit(Integer* p1, Char* p2) {
    int value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
}

shared_ptr<Object> NEQVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
}

//---------------------String--------------------------
shared_ptr<Object> NEQVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator!=(p2));
}

//--------------------------Char-----------------------
shared_ptr<Object> NEQVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
}

shared_ptr<Object> NEQVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
}

shared_ptr<Object> NEQVisitor::Visit(Char* p1, Char* p2) {
    char value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
}

//--------------------------Double----------------------
shared_ptr<Object> NEQVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
}

shared_ptr<Object> NEQVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
}

shared_ptr<Object> NEQVisitor::Visit(Double* p1, Char* p2) {
    double value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 != value2);
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

shared_ptr<Object> LSVisitor::Visit(Double* p) {
    LSVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> LSVisitor::Visit(Char* p) {
    LSVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//--------------------------Integer------------------------
shared_ptr<Object> LSVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
}

shared_ptr<Object> LSVisitor::Visit(Integer* p1, Char* p2) {
    int value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
}

shared_ptr<Object> LSVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
}

//-----------------------------String----------------------
shared_ptr<Object> LSVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator<(p2));
}

//----------------------------Char---------------------
shared_ptr<Object> LSVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
}

shared_ptr<Object> LSVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
}

shared_ptr<Object> LSVisitor::Visit(Char* p1, Char* p2) {
    char value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
}

//-------------------------Double-----------------
shared_ptr<Object> LSVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
}

shared_ptr<Object> LSVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
}

shared_ptr<Object> LSVisitor::Visit(Double* p1, Char* p2) {
    double value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 < value2);
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

shared_ptr<Object> LEQVisitor::Visit(Double* p) {
    LEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

shared_ptr<Object> LEQVisitor::Visit(Char* p) {
    LEQVisitor visitor;
    return this->obj->accept(&visitor, p);
}

//-------------------------------Integer-----------------------
shared_ptr<Object> LEQVisitor::Visit(Integer* p1, Integer* p2) {
    int value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
}

shared_ptr<Object> LEQVisitor::Visit(Integer* p1, Char* p2) {
    int value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
}

shared_ptr<Object> LEQVisitor::Visit(Integer* p1, Double* p2) {
    int value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
}

//-------------------------String-------------------
shared_ptr<Object> LEQVisitor::Visit(String* p1, String* p2) {
    return make_shared<Integer>(p1->operator<= (p2));
}

//-------------------------Char----------------------
shared_ptr<Object> LEQVisitor::Visit(Char* p1, Integer* p2) {
    char value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
}

shared_ptr<Object> LEQVisitor::Visit(Char* p1, Double* p2) {
    char value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
}

shared_ptr<Object> LEQVisitor::Visit(Char* p1, Char* p2) {
    char value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
}

//-------------------------Double-----------------------
shared_ptr<Object> LEQVisitor::Visit(Double* p1, Double* p2) {
    double value1 = p1->getValue();
    double value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
}

shared_ptr<Object> LEQVisitor::Visit(Double* p1, Integer* p2) {
    double value1 = p1->getValue();
    int value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
}

shared_ptr<Object> LEQVisitor::Visit(Double* p1, Char* p2) {
    double value1 = p1->getValue();
    char value2 = p2->getValue();
    return make_shared<Integer>(value1 <= value2);
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

shared_ptr<Object> ArrayElementVisitor::Visit(String* s) {
    char value = s->operator[](this->n);
    return make_shared<Char>(value);
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

shared_ptr<Object> ArrayElementSetVisitor::Visit(String* p) {
    p->operator[](this->idx) = this->obj->isZero();
    return this->obj;
}
/**
 *
 * FunCallVisitor
 *
 */

FunCallVisitor::FunCallVisitor(vector<shared_ptr<Object>>& v, ExprTreeEvaluator* eval) : v(v), e(eval) {}

shared_ptr<Object> FunCallVisitor::Visit(Function* f) {
    return f->runFunc(this->v, this->e);
}

