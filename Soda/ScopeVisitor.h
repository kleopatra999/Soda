#pragma once

#include "Ast.h"
#include "Compiler.h"
#include "SymbolTable.h"
#include "Visitor.h"
#include <cassert>
#include <iostream>
#include <stack>

namespace Soda
{

    class ScopeVisitor : public AstDefaultVisitor
    {
    public:
        Compiler &compiler;
        std::stack< SymbolTable * > scopeStack;
        unsigned int errorCount;

        ScopeVisitor(Compiler &compiler)
            : compiler(compiler)
            , errorCount(0)
        {
            scopeStack.push(&compiler.getGlobalScope());
        }

        SymbolTable *currentScope()
        {
            assert(!scopeStack.empty());
            return scopeStack.top();
        }

        template < class NodeT >
        void openScope(NodeT &n)
        {
            n.ownerScope = currentScope();
            n.scope.parent = currentScope();
            scopeStack.push(&n.scope);
        }

        template < class NodeT >
        void closeScope(NodeT &n)
        {
            assert(!scopeStack.empty());
            assert(currentScope() == &n.scope);
            scopeStack.pop();
        }

        void define(AstDecl &decl)
        {
            assert(currentScope());
            auto sym = currentScope()->define(&decl);
            if (!sym) {
                compiler.error(decl, "multiple definitions of '%'", decl.name);
                errorCount++;
            }
        }

        auto splitName(const std::string &name)
        {
            std::vector< std::string > parts;
            size_t index = 0;
            parts.push_back("");
            for (auto &ch : name) {
                if (ch != '.')
                    parts[index] += ch;
                else {
                    index++;
                    parts.push_back("");
                }
            }
            return parts;
        }

        Symbol *lookup(AstNode &n, const std::string &name, bool rec = true)
        {
            assert(currentScope());
            auto nameParts = splitName(name);
            if (nameParts.size() == 1) {
                if (auto sym = currentScope()->lookup(nameParts[0], rec))
                    return sym;
                else {
                    compiler.error(n, "undefined symbol '%'", nameParts[0]);
                    errorCount++;
                    return nullptr;
                }
            } else if (nameParts.size() == 0) {
                compiler.error(n, "cannot lookup empty symbol");
                errorCount++;
                return nullptr;
            } else /* if (nameParts.size() > 1) */ {
                if (auto sym = currentScope()->lookup(nameParts[0])) {
                    for (size_t i = 1; sym != nullptr && i < nameParts.size();
                         i++) {
                        switch (sym->primaryDecl()->kind) {
                        case NK_NAMESPACE_DECL:
                            sym = static_cast< AstNamespaceDecl * >(
                                      sym->primaryDecl())
                                      ->scope.lookup(nameParts[i]);
                            break;
                        case NK_STRUCT_DECL:
                            sym = static_cast< AstStructDecl * >(
                                      sym->primaryDecl())
                                      ->scope.lookup(nameParts[i]);
                            break;
                        case NK_ENUM_DECL:
                            sym = static_cast< AstEnumDecl * >(
                                      sym->primaryDecl())
                                      ->scope.lookup(nameParts[i]);
                            break;
                        default:
                            i = nameParts.size();
                            break;
                        }
                    }
                    assert(sym);
                    return sym;
                }
                return nullptr;
            }
        }
    };

} // namespace Soda
