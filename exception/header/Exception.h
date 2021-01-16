/**
* Author: Zubeyir Bodur
* Date: 13.1.2021
 * Description: Exception interface for an ADT
*/
#ifndef __EXCEPTION_H_
#define __EXCEPTION_H_
#include <string>
using namespace std;

class Exception : public exception {

private:
    string msg;

public:
    virtual const char* what() const throw() {
        return msg.c_str();
    }
    Exception(const string& message ="")
            :exception(), msg(message) {};
    ~Exception() throw() {};
};
#endif
