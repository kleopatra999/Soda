#pragma once

namespace Soda
{

    struct AstAmbiguityStmt;
    struct AstNil;
    struct AstBool;
    struct AstInt;
    struct AstFloat;
    struct AstChar;
    struct AstString;
    struct AstIdentifier;
    struct AstUnary;
    struct AstBinary;
    struct AstTypedef;
    struct AstTypeRef;
    struct AstCast;
    struct AstIfExpr;
    struct AstCaseStmt;
    struct AstSwitchStmt;
    struct AstCallExpr;
    struct AstIndexExpr;
    struct AstMemberExpr;
    struct AstEmptyStmt;
    struct AstCommentStmt;
    struct AstExprStmt;
    struct AstBlockStmt;
    struct AstReturnStmt;
    struct AstBreakStmt;
    struct AstContinueStmt;
    struct AstGotoStmt;
    struct AstIfStmt;
    struct AstDoStmt;
    struct AstWhileStmt;
    struct AstEmptyDecl;
    struct AstCommentDecl;
    struct AstLabelDecl;
    struct AstUsingDecl;
    struct AstNamespaceDecl;
    struct AstVarDecl;
    struct AstParamDecl;
    struct AstFuncDecl;
    struct AstDelegateDecl;
    struct AstStructDecl;
    struct AstEnumeratorDecl;
    struct AstEnumDecl;
    struct AstModule;

    class AstVisitor
    {
    public:
        virtual void visit(AstAmbiguityStmt &) = 0;
        virtual void visit(AstNil &) = 0;
        virtual void visit(AstBool &) = 0;
        virtual void visit(AstInt &) = 0;
        virtual void visit(AstFloat &) = 0;
        virtual void visit(AstChar &) = 0;
        virtual void visit(AstString &) = 0;
        virtual void visit(AstIdentifier &) = 0;
        virtual void visit(AstUnary &) = 0;
        virtual void visit(AstBinary &) = 0;
        virtual void visit(AstTypedef &) = 0;
        virtual void visit(AstTypeRef &) = 0;
        virtual void visit(AstCast &) = 0;
        virtual void visit(AstIfExpr &) = 0;
        virtual void visit(AstCallExpr &) = 0;
        virtual void visit(AstIndexExpr &) = 0;
        virtual void visit(AstMemberExpr &) = 0;
        virtual void visit(AstEmptyStmt &) = 0;
        virtual void visit(AstCommentStmt &) = 0;
        virtual void visit(AstExprStmt &) = 0;
        virtual void visit(AstBlockStmt &) = 0;
        virtual void visit(AstReturnStmt &) = 0;
        virtual void visit(AstBreakStmt &) = 0;
        virtual void visit(AstContinueStmt &) = 0;
        virtual void visit(AstGotoStmt &) = 0;
        virtual void visit(AstIfStmt &) = 0;
        virtual void visit(AstCaseStmt &) = 0;
        virtual void visit(AstSwitchStmt &) = 0;
        virtual void visit(AstDoStmt &) = 0;
        virtual void visit(AstWhileStmt &) = 0;
        virtual void visit(AstEmptyDecl &) = 0;
        virtual void visit(AstCommentDecl &) = 0;
        virtual void visit(AstLabelDecl &) = 0;
        virtual void visit(AstUsingDecl &) = 0;
        virtual void visit(AstNamespaceDecl &) = 0;
        virtual void visit(AstVarDecl &) = 0;
        virtual void visit(AstParamDecl &) = 0;
        virtual void visit(AstFuncDecl &) = 0;
        virtual void visit(AstDelegateDecl &) = 0;
        virtual void visit(AstStructDecl &) = 0;
        virtual void visit(AstEnumeratorDecl &) = 0;
        virtual void visit(AstEnumDecl &) = 0;
        virtual void visit(AstModule &) = 0;
    };

    class AstDefaultVisitor : public AstVisitor
    {
    public:
        virtual void visit(AstAmbiguityStmt &n) override;
        virtual void visit(AstNil &n) override;
        virtual void visit(AstBool &n) override;
        virtual void visit(AstInt &n) override;
        virtual void visit(AstFloat &n) override;
        virtual void visit(AstChar &n) override;
        virtual void visit(AstString &n) override;
        virtual void visit(AstIdentifier &n) override;
        virtual void visit(AstUnary &n) override;
        virtual void visit(AstBinary &n) override;
        virtual void visit(AstTypedef &n) override;
        virtual void visit(AstTypeRef &n) override;
        virtual void visit(AstCast &n) override;
        virtual void visit(AstIfExpr &n) override;
        virtual void visit(AstCallExpr &n) override;
        virtual void visit(AstIndexExpr &n) override;
        virtual void visit(AstMemberExpr &n) override;
        virtual void visit(AstEmptyStmt &n) override;
        virtual void visit(AstCommentStmt &n) override;
        virtual void visit(AstExprStmt &n) override;
        virtual void visit(AstBlockStmt &n) override;
        virtual void visit(AstReturnStmt &n) override;
        virtual void visit(AstBreakStmt &n) override;
        virtual void visit(AstContinueStmt &n) override;
        virtual void visit(AstGotoStmt &n) override;
        virtual void visit(AstIfStmt &n) override;
        virtual void visit(AstCaseStmt &n) override;
        virtual void visit(AstSwitchStmt &n) override;
        virtual void visit(AstDoStmt &n) override;
        virtual void visit(AstWhileStmt &n) override;
        virtual void visit(AstEmptyDecl &n) override;
        virtual void visit(AstCommentDecl &n) override;
        virtual void visit(AstLabelDecl &n) override;
        virtual void visit(AstUsingDecl &n) override;
        virtual void visit(AstNamespaceDecl &n) override;
        virtual void visit(AstVarDecl &n) override;
        virtual void visit(AstParamDecl &n) override;
        virtual void visit(AstFuncDecl &n) override;
        virtual void visit(AstDelegateDecl &n) override;
        virtual void visit(AstStructDecl &n) override;
        virtual void visit(AstEnumeratorDecl &n) override;
        virtual void visit(AstEnumDecl &n) override;
        virtual void visit(AstModule &n) override;
    };

} // namespace Soda
