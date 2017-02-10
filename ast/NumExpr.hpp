#ifndef NUMEXPR_HPP
#define NUMEXPR_HPP

#include "RValue.hpp"

#include <iostream>
#include <string>

namespace ast
{

class NumExpr : public RValue
{
    int m_val;

public:
    NumExpr(int val) :
        RValue()
      , m_val(val)
    {
    }

//    virtual void generateCode();

    // Node interface
public:
    virtual bool checkSemantic(Scope&, Report&) override
    {
        setType( single_town<IntType>() );
        return true;
    }

    virtual operator std::string() const override
    {
        return "NumExpr( " + std::to_string(m_val) + " )";
    }
};

} // ast namespace

#endif // NUMEXPR_HPP
