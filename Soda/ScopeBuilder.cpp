#include "Ast.h"
#include "Compiler.h"
#include "ScopeBuilder.h"
#include "ScopeVisitor.h"
#include "SymbolTable.h"
#include "Visitor.h"
#include <cassert>
#include <stack>

namespace Soda
{
    struct ScopeBuilder final : ScopeVisitor
    {
        std::stack< AstNode * > parentStack;

        ScopeBuilder(Compiler &compiler)
            : ScopeVisitor(compiler)
        {
            parentStack.push(nullptr);
        }

        AstNode *currentParent()
        {
            assert(!parentStack.empty());
            return parentStack.top();
        }

        void handleBasicNode(AstNode &n)
        {
            beginParent(n);
            n.acceptChildren(*this);
            endParent(n);
        }

        void beginParent(AstNode &n)
        {
            n.parentNode = currentParent();
            n.ownerScope = currentScope();
            parentStack.push(&n);
        }

        void endParent(AstNode &n)
        {
            assert(!parentStack.empty());
            assert(currentParent() == &n);
            parentStack.pop();
        }

        template < class NodeT >
        void openParentScope(NodeT &n)
        {
            beginParent(n);
            openScope(n);
        }

        template < class NodeT >
        void closeParentScope(NodeT &n)
        {
            closeScope(n);
            endParent(n);
        }

        virtual void visit(AstNil &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstBool &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstInt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstFloat &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstChar &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstString &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstIdentifier &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstUnary &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstBinary &n) override final
        {
            handleBasicNode(n);
        }

        virtual void visit(AstCast &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstIfExpr &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstFuncExpr &n) override final
        {
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }
        virtual void visit(AstCallExpr &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstIndexExpr &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstMemberExpr &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstEmptyStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstExprStmt &n) override final
        {
            handleBasicNode(n);
        }

        virtual void visit(AstBlockStmt &n) override final
        {
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }

        virtual void visit(AstReturnStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstBreakStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstContinueStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstGotoStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstIfStmt &n) override final
        {
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }
        virtual void visit(AstCaseStmt &n) override final
        {
            if (n.expr)
                n.expr->accept(*this);
            openParentScope(n);
            for (auto &stmt : n.stmts)
                stmt->accept(*this);
            closeParentScope(n);
        }
        virtual void visit(AstSwitchStmt &n) override final
        {
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }
        virtual void visit(AstForStmt &n) override final
        {
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }
        virtual void visit(AstDoStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstWhileStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstCatchStmt &n) override final
        {
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }
        virtual void visit(AstFinallyStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstTryStmt &n) override final
        {
            handleBasicNode(n);
        }
        virtual void visit(AstLabelDecl &n) override final
        {
            define(n);
            beginParent(n);
            n.acceptChildren(*this);
            endParent(n);
        }
        virtual void visit(AstUsingDecl &n) override final
        {
            handleBasicNode(n);
        }

        virtual void visit(AstTypedef &n) override final
        {
            define(n);
            beginParent(n);
            n.acceptChildren(*this);
            endParent(n);
        }

        virtual void visit(AstNamespaceDecl &n) override final
        {
            define(n);
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }

        virtual void visit(AstVarDecl &n) override final
        {
            define(n);
            beginParent(n);
            n.acceptChildren(*this);
            endParent(n);
        }

        virtual void visit(AstParamDecl &n) override final
        {
            define(n);
            beginParent(n);
            n.acceptChildren(*this);
            endParent(n);
        }

        virtual void visit(AstFuncDecl &n) override final
        {
            define(n);
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }

        virtual void visit(AstDelegateDecl &n) override final
        {
            define(n);
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }

        virtual void visit(AstConstructorDecl &n) override final
        {
            define(n);
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }

        virtual void visit(AstDestructorDecl &n) override final
        {
            define(n);
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }

        virtual void visit(AstStructDecl &n) override final
        {
            define(n);
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }

        virtual void visit(AstEnumeratorDecl &n) override final
        {
            define(n);
            beginParent(n);
            n.acceptChildren(*this);
            endParent(n);
        }

        virtual void visit(AstEnumDecl &n) override final
        {
            define(n);
            openParentScope(n);
            n.acceptChildren(*this);
            closeParentScope(n);
        }

        virtual void visit(AstModule &n) override final
        {
            handleBasicNode(n);
        }
    };

    unsigned int buildScopes(Compiler &compiler, AstNode &node)
    {
        ScopeBuilder builder(compiler);
        node.accept(builder);
        return builder.errorCount;
    }

} // namespace Soda
