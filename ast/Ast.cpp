//
// Created by frnd on 12/30/16.
//

#include "Ast.hpp"

using namespace ast;

namespace sem = semantic;

bool Ast::checkSemantic()
{
    sem::Scope scope;
    sem::Report report;

    return m_root->checkSemantic(scope, report);
}

void Ast::generateCode()
{
}

Ast::operator std::string() const
{
    return "Ast( " + static_cast<std::string>( *m_root ) + " )";
}
