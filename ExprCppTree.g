grammar ExprCppTree;

options {
    language = C;
    output = AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

@header {
    #include <assert.h>
}
// The suffix '^' means make it a root.
// The suffix '!' means ignore it.
PLUS: '+';
MINUS: '-';
TIMES: '*';
DIV: '/';
MOD: '%';
DOT: ',';
ASSIGN: '=';

DEF: 'def';
IF: 'if';
ELSE: 'else';

GT: '>';
GEQ: '>=';
LS: '<';
LEQ: '<=';
EQ: '==';
NEQ: '!=';
NOT: '!';
OR: '||';
AND: '&&';
BITOR: '|';
BITAND: '&';

PRINT: 'print';
FOR: 'for';
WHILE: 'while';
SWITCH: 'switch';
CASE: 'case';
DEFAULT: 'default';
BREAK: 'break';
CONTINUE: 'continue';
RETURN: 'return';

expr1: multExpr ((PLUS^ | MINUS^) multExpr)*
//    | assignExpr
    ;

multExpr
    : atom ((TIMES | DIV | MOD)^ atom)*
    ;

//midExpr: LMID (expr DOT)* expr RMID -> ^(MID expr+);

midExpr: '[' (expr (DOT expr)*)? ']' -> ^(MID expr*)
        | expr
        ;
arrayElem: ID ('[' expr ']')+ -> ^(ARRELEM ID expr+);
arrayElemAssign: arrayElem ASSIGN expr -> ^(ARRELEMASSIGN arrayElem expr);
defExpr: DEF expr (DOT expr)* -> ^(DEF expr+)
        ;
assignExpr: ID ASSIGN midExpr -> ^(ASSIGN ID midExpr)
        | arrayElemAssign
        ;
funcExpr: 'function' '(' (ID (DOT ID)*)? ')' block -> ^(FUN block ID*);
funcCall: ID '(' (expr (DOT expr)*)? ')' -> ^(FUNCALL ID expr*); 

conditionExpr: 
            expr1 ((GT | GEQ | LS | LEQ | OR | AND | EQ | NEQ)^ expr1)*
            ;
expr: 
            expr1 ((GT | GEQ | LS | LEQ | OR | AND | EQ | NEQ)^ expr1)*
            | funcExpr
            ;
returnExpr: RETURN^ expr;

ifExpr: IF '(' conditionExpr ')' block (ELSE stmt)? -> ^(IF conditionExpr block stmt?);

forExpr: FOR '(' assignExpr ';' conditionExpr ';' assignExpr ')' stmt -> ^(FOR assignExpr conditionExpr assignExpr stmt);
whileExpr: WHILE '(' conditionExpr ')' stmt -> ^(WHILE conditionExpr stmt);
caseExpr: CASE expr':' stmt* -> ^(CASE expr stmt*);
defaultExpr: (DEFAULT':' stmt+) -> ^(DEFAULT stmt+);
switchExpr: SWITCH '(' expr ')' '{' caseExpr+ defaultExpr? '}' -> ^(SWITCH expr caseExpr+ defaultExpr?);

atom: INT
    | ID
    | STRING
    | '('! expr ')'!
    | arrayElem
    | funcCall
    ;

stmt: //conditionExpr';'!  // tree rewrite syntax
     block
    | defExpr';'!
    | assignExpr';'!
    | PRINT '(' conditionExpr ')'';' -> ^(PRINT conditionExpr)
    | ifExpr
    | forExpr
    | whileExpr
    | switchExpr
    | BREAK';'!
    | CONTINUE';'!
    | funcCall';'! 
    | returnExpr';'!
    ;

block: '{' stmt* '}' -> ^(BLOCK stmt*);

prog
    : (stmt {pANTLR3_STRING s = $stmt.tree->toStringTree($stmt.tree);
             assert(s->chars);
             printf(" tree \%s\n", s->chars);
            }
        )+
    ;

ID: ('a'..'z'|'A'..'Z')+ ;
//INT: '-'? '0'..'9'+ ('.' '0'..'9'+)?;
INT: '-'? '0'..'9'+;
STRING: '\"' .* '\"';
BLOCK:'{}';
MID: '[]';
ARRELEM: 'elem[]';
ARRELEMASSIGN: 'elelm[]assign';
FUN: 'fun(){}';
FUNCALL: 'funcall()';
WS : (' ' | '\t' | '\n' | '\r')+ {$channel = HIDDEN;};
