#include "../include/ArbitraryType.h"
#include <iostream>
using namespace std;
#define PERSISION 100
void complement_flip(vector<unsigned char>& num) {
    if (num.size() < PERSISION) {
        cout << "ERROR: the size of number is less than PERSITIION" << endl;
        return;
    }
    for (int i = 0; i < PERSISION; i++) {
        num[i] = 9 - num[i];
    }
    num[0]++;
    for (int i = 0; i < PERSISION - 1; i++) {
        num[i + 1] += num[i] / 10;
        num[i] = num[i] % 10;
    }
    num[PERSISION - 1] %= 10;
}

void right_move(vector<unsigned char>& num, int n) {
    unsigned char x = num[PERSISION - 1];
    for (int i = 0; i < n; i++) {
        num[PERSISION - 2] = x;
        for (int i = PERSISION - 1; i > 0; i--) {
            num[i] = num[i - 1];
        }
        num[0] = 0;
    }
} 

Object::Object() {
    this->s.append("undefined!");
}

Object::~Object() {}

Number::Number(string s) : num(PERSISION, 0), pos(0) {
    bool flag = false;
    if (s[0] == '~') {
        flag = true;
        s.erase(s.begin());
    }
    int len = s.length() > PERSISION - 1 ? PERSISION - 1 :  s.length();
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '.') {
            this->pos = idx;
            continue;
        }
        num[idx++] = s[i] - '0';
    }
    if (flag) {
        ::complement_flip(this->num);
    }
}

shared_ptr<Object> Number::accept(Object::IVisitor* visitor) {
    return visitor->Visit(this);
}

shared_ptr<Object> Object::accept(Object::IVisitor* visitor) {
    return nullptr;
}

string Object::output() {
    return this->s;
}

string Number::output() {
    string ret;
    vector<unsigned char> num = this->num;
    if (this->num[PERSISION - 1] == 9) {
        complement_flip(num);
        ret.push_back('~');
    }
    int i = PERSISION - 2;
    for (int i = PERSISION - 2; i >= this->pos; i--) {
        if (num[i] == 0) continue;
        ret.push_back(num[i] + '0');
    }
    if (this->pos != 0) {
        ret.push_back('.');
        for (int i = this->pos - 1; i >= 0; i--) {
            ret.push_back(num[i] + '0');  
        }
    }
    return ret;
}

void Number::add(vector<unsigned char>& ret, vector<unsigned char>& v1, vector<unsigned char>& v2) {
    for (int i = 0; i < PERSISION; i++) {
        ret[i] = v1[i] + v2[i];
    }
    for (int i = 0; i < PERSISION - 1; i++) {
        ret[i + 1] += ret[i] / 10;
        ret[i] = ret[i] % 10;
    }
    ret[PERSISION - 1] %= 10;
}

void Number::mul(vector<unsigned char>& ret, vector<unsigned char>& v1, vector<unsigned char>& v2) {
    for (int i = 0; i < PERSISION; i++) {
        for (int j = 0; j + i < PERSISION; j++) {
            ret[j + i] += v1[i] * v2[j];
        }
        for (int j = 0; j < PERSISION - 1; j++) {
            ret[j] += ret[j] / 10;
            ret[j] %= 10;
        }
        ret[PERSISION - 1] %= 10;
    }
}

void Number::adjust(shared_ptr<Number>& p) {
    if (p->pos == 0) return;
    int i, idx = 0;
    for (i = 0; i < p->num.size(); i++) {
        if (p->num[i]) break;
    }
    if (i == 0) return;
    p->pos -= i;
    for (; i < PERSISION; i++) {
        p->num[idx++] = p->num[i];
    }
    for (; idx < PERSISION - 1; idx++) {
        p->num[idx] = p->num[PERSISION - 1];
    }
}

shared_ptr<Object> Number::operator+(Object* obj) {
    Number* ptr = dynamic_cast<Number*>(obj);
    if (ptr == nullptr) {
        return nullptr;
    }
    shared_ptr<Number> ret = make_shared<Number>("");
    ret->pos = this->pos > ptr->pos ? this->pos : ptr->pos;
    vector<unsigned char> num1 = ptr->num;
    vector<unsigned char> num2 = this->num;
    ::right_move(num1, ret->pos - ptr->pos);
    ::right_move(num2, ret->pos - this->pos);
    add(ret->num, num1, num2);
    adjust(ret);
    return ret;
}

shared_ptr<Object> Number::operator-(Object* obj) {
    Number* ptr = dynamic_cast<Number*>(obj);
    if (ptr == nullptr) {
        return nullptr;
    }
    shared_ptr<Number> p = make_shared<Number>(ptr->output());
    complement_flip(p->num);
    return this->operator+(p.get());
}

shared_ptr<Object> Number::operator* (Object* obj) {
    Number* ptr = dynamic_cast<Number*>(obj);
    if (ptr == nullptr) return nullptr;
    shared_ptr<Number> p = make_shared<Number>("");
    p->pos = this->pos * ptr->pos;
    mul(p->num, this->num, ptr->num);
    adjust(p);
    return p;
}


shared_ptr<Object> Number::operator> (Object* obj) {
    Number* ptr = dynamic_cast<Number*>(obj);
    if (ptr == nullptr) return nullptr;
    shared_ptr<Number> p = this->operator-(ptr);
    if (p->isZero()) return p;
    if (p->num[PERSISION - 1] == 0) {
        return make_shared<Number>("1");
    }
    return make_shared<Number>("0");
}


shared_ptr<Object> Number::operator/ (Object* obj) {
    Number* ptr = dynamic_cast<Number*>(obj);
    if (ptr == nullptr) return nullptr;
    vector<unsigned char> num1 = this->num;
    vector<unsigned char> num2 = ptr->num;
    
}


int Number::isZero() {
    for (int i = 0; i < PERSISION - 1; i++) {
        if (this->num[i] == 0) continue;
        return false;
    }
    return true;
}
