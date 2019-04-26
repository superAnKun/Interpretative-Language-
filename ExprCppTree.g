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

expr: multExpr ((PLUS^ | MINUS^) multExpr)*
    | assignExpr
    ;

multExpr
    : atom ((TIMES | DIV | MOD)^ atom)*
    ;

//midExpr: LMID (expr DOT)* expr RMID -> ^(MID expr+);

midExpr: '[' (expr (DOT expr)*)? ']' -> ^(MID expr*)
        | expr
        ;
arrayElem: ID '[' INT ']' -> ^(ARRELEM ID INT);
arrayElemAssign: arrayElem ASSIGN expr -> ^(ARRELEMASSIGN arrayElem expr);
defExpr: DEF expr (DOT expr)* -> ^(DEF expr+)
        ;
assignExpr: ID ASSIGN midExpr -> ^(ASSIGN ID midExpr)
        | arrayElemAssign
        ;

conditionExpr: 
            expr ((GT | GEQ | LS | LEQ | OR | AND | EQ | NEQ)^ expr)*
            ;

ifExpr: IF '(' conditionExpr ')' block (ELSE stmt)? -> ^(IF conditionExpr block stmt?);

forExpr: FOR '(' expr ';' conditionExpr ';' expr ')' stmt -> ^(FOR expr conditionExpr expr stmt);
whileExpr: WHILE '(' conditionExpr ')' stmt -> ^(WHILE conditionExpr stmt);
caseExpr: CASE expr':' stmt* -> ^(CASE expr stmt*);
defaultExpr: (DEFAULT':' stmt+) -> ^(DEFAULT stmt+);
switchExpr: SWITCH '(' expr ')' '{' caseExpr+ defaultExpr? '}' -> ^(SWITCH expr caseExpr+ defaultExpr?);

atom: INT
    | ID
    | STRING
    | '('! expr ')'!
    | arrayElem
    ;

stmt: conditionExpr';'!  // tree rewrite syntax
    | block
    | defExpr';'!
    | PRINT '(' conditionExpr ')'';' -> ^(PRINT conditionExpr)
    | ifExpr
    | forExpr
    | whileExpr
    | switchExpr
    | BREAK';'!
    | CONTINUE';'!
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
WS : (' ' | '\t' | '\n' | '\r')+ {$channel = HIDDEN;};
