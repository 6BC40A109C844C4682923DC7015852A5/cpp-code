#include <string>
#include "SeqStack.h"

#ifndef BR_MATCH_H
#define BR_MATCH_H

bool brMatch(std::string const& bra){
    SqStack<char> sta(bra.size());
    const char *p= bra.data();

    while (*p != '\0'){
        switch(*p){
            case '(': sta.push(*p); break;
            case '[': sta.push(*p); break;
            case '{': sta.push(*p); break;
            case ')':
                if(sta.isEmpty() || sta.pop() != '(')
                    return false;
                break;
            case ']':
                if(sta.isEmpty() || sta.pop() != '[')
                    return false;
                break;
            case '}':
                if(sta.isEmpty() || sta.pop() != '{')
                    return false;
                break;
            default:
                break;
        }
        p++;
    }

    return sta.isEmpty();
}

#endif
