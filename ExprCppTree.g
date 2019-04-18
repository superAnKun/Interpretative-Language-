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
DOT: ',';
ASSIGN: '=';

DEF: 'd''e''f';
IF: 'i''f';
ELSE: 'e''l''s''e';

GT: '>';
GEQ: '>''=';
LS: '<';
LEQ: '<''=';
EQ: '=''=';
NOT: '!';
OR: '|''|';
AND: '&''&';
BITOR: '|';
BITAND: '&';

PRINT: 'p''r''i''n''t';
FOR: 'f''o''r';
WHILE: 'w''h''i''l''e';
BREAK: 'b''r''e''a''k';
CONTINUE: 'c''o''n''t''i''n''u''e';

expr: multExpr ((PLUS^ | MINUS^) multExpr)*
    | ID ASSIGN expr -> ^(ASSIGN ID expr)
    ;
multExpr
    : atom ((TIMES | DIV)^ atom)*
    ;

defExpr: DEF expr (DOT expr)* -> ^(DEF expr+);
conditionExpr: 
            expr ((GT | GEQ | LS | LEQ | OR | AND | EQ)^ expr)*
            ;

atom: INT
    | ID
    | '('! expr ')'!
    ;

stmt: conditionExpr';'!  // tree rewrite syntax
    | block
    | defExpr';'!
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
INT: '~'? '0'..'9'+ ('.' '0'..'9'+)?;
BLOCK:'{}';
WS : (' ' | '\t' | '\n' | '\r')+ {$channel = HIDDEN;};
