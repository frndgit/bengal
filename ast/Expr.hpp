#ifndef EXPR_HPP
#define EXPR_HPP

//#include <llvm/IR/Value.h>
//#include <llvm/IR/IRBuilder.h>
//#include <llvm/IR/Module.h>

#include "Node.hpp"

namespace sem = semantic;

namespace ast
{

//static std::unique_ptr<llvm::Module> *MainModule;
//static llvm::IRBuilder<> Builder(llvm::getGlobalContext());
//static std::map<std::string, llvm::Value *> NamedValues;

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

private:
    std::shared_ptr<Type> m_type;
};

} // namespace ast

#endif // EXPR_HPP
