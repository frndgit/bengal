#ifndef EXPR_HPP
#define EXPR_HPP

//#include <llvm/IR/Value.h>
//#include <llvm/IR/IRBuilder.h>
//#include <llvm/IR/Module.h>

#include "Node.hpp"

namespace sem = semantic;

namespace ast
{

class Expr : public Node
{
protected:
    using Type = sem::Type;
    using IntType = sem::IntType;
    using StringType = sem::StringType;
    using NilType = sem::NilType;
    using ArrayType = sem::ArrayType;
    using StructType = sem::StructType;
    using FunctionType = sem::FunctionType;
    using AliasType = sem::AliasType;
    using Procedure = sem::ProcedureType;
    using NoneType = sem::NoneType;

    const std::shared_ptr<Type>& type() const;
    void setType(const std::shared_ptr<Type>& type);

    static bool sameType(const std::shared_ptr<Type>& type, std::initializer_list<std::shared_ptr<Expr> > expr_list)
    {
        for (auto& x : expr_list)
            if ( not ( x->type() == type ) )
                return false;
        return true;
    }

    static bool sameType( std::initializer_list<std::shared_ptr<Expr> > expr_list )
    {
        auto i = expr_list.begin();
        if (i == expr_list.end()) return true;
        auto j = i + 1;
        while (j != expr_list.end())
        {
            if ( ( *i++ )->type() != ( *j++ )->type() )
                return false;
        }
        return true;
    }

private:
    std::shared_ptr<Type> m_type;

    // Node interface
public:
    virtual operator std::string() const override
    {
        return "Expr()";
    }
};

} // namespace ast

#endif // EXPR_HPP
