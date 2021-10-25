#ifndef NOSUCHOBJECT_H
#define NOSUCHOBJECT_H
#include <stdexcept>
#include <exception>

using namespace std;

// DOUBLE CHECK WITH FILENOTFOUND CODE FROM PREVIOUS NOTES
class NoSuchObject: public logic_error{
public:
    NoSuchObject(): logic_error("Stack empty"){}
    NoSuchObject(const string & what):logic_error(what){}
};

#endif // NOSUCHOBJECT_H



