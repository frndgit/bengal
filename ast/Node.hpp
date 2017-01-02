#ifndef NODE_HPP
#define NODE_HPP

#include "utils.hpp"
//#include "CodeGenerator.hpp"

// Semantic
#include <Scope.hpp>
#include <Report.hpp>

namespace ast
{

class Node
{
protected:
    using Scope = semantic::Scope;
    using Report = semantic::Report;
    using Type = Scope::Type;

private:
    std::shared_ptr< Scope::Type > m_type;

protected:
    std::shared_ptr<Type> type() const;
    void setType(const std::shared_ptr<Type>& type);

public:
    virtual ~Node();

//    virtual void generateCode(ptr<CodeGenerator>& cg) = 0;
    virtual bool checkSemantic(Scope& scope, Report& report) = 0;
};

} // ast namespace

#endif // NODE_HPP
