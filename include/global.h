#ifndef GLOBAL_H
#define GLOBAL_H
#include <memory>
using namespace std;

class Object;
enum class Type {
    YES,
    NO,
    BREAKL,
    CONTINUEL,
    IN,
    OUT,
    OK,
    CASEL,
    DEFAULTL
};

struct Status {
    Type type;
    shared_ptr<Object> value;
};

#endif
