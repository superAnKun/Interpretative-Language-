/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : ./ExprCppTree.g
 *     -                            On : 2019-04-26 12:51:59
 *     -                for the parser : ExprCppTreeParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser 
ExprCppTreeParser

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pExprCppTreeParser, which is returned from a call to ExprCppTreeParserNew().
 *
 * The methods in pExprCppTreeParser are  as follows:
 *
 *  - 
 ExprCppTreeParser_expr_return
      pExprCppTreeParser->expr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_multExpr_return
      pExprCppTreeParser->multExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_midExpr_return
      pExprCppTreeParser->midExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_arrayElem_return
      pExprCppTreeParser->arrayElem(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_arrayElemAssign_return
      pExprCppTreeParser->arrayElemAssign(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_defExpr_return
      pExprCppTreeParser->defExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_assignExpr_return
      pExprCppTreeParser->assignExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_conditionExpr_return
      pExprCppTreeParser->conditionExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_ifExpr_return
      pExprCppTreeParser->ifExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_forExpr_return
      pExprCppTreeParser->forExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_whileExpr_return
      pExprCppTreeParser->whileExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_caseExpr_return
      pExprCppTreeParser->caseExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_defaultExpr_return
      pExprCppTreeParser->defaultExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_switchExpr_return
      pExprCppTreeParser->switchExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_atom_return
      pExprCppTreeParser->atom(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_stmt_return
      pExprCppTreeParser->stmt(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_block_return
      pExprCppTreeParser->block(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_prog_return
      pExprCppTreeParser->prog(pExprCppTreeParser)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_ExprCppTreeParser_H
#define _ExprCppTreeParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct ExprCppTreeParser_Ctx_struct ExprCppTreeParser, * pExprCppTreeParser;



    #include <assert.h>


#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif
typedef struct ExprCppTreeParser_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_expr_return;



typedef struct ExprCppTreeParser_multExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_multExpr_return;



typedef struct ExprCppTreeParser_midExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_midExpr_return;



typedef struct ExprCppTreeParser_arrayElem_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_arrayElem_return;



typedef struct ExprCppTreeParser_arrayElemAssign_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_arrayElemAssign_return;



typedef struct ExprCppTreeParser_defExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_defExpr_return;



typedef struct ExprCppTreeParser_assignExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_assignExpr_return;



typedef struct ExprCppTreeParser_conditionExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_conditionExpr_return;



typedef struct ExprCppTreeParser_ifExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_ifExpr_return;



typedef struct ExprCppTreeParser_forExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_forExpr_return;



typedef struct ExprCppTreeParser_whileExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_whileExpr_return;



typedef struct ExprCppTreeParser_caseExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_caseExpr_return;



typedef struct ExprCppTreeParser_defaultExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_defaultExpr_return;



typedef struct ExprCppTreeParser_switchExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_switchExpr_return;



typedef struct ExprCppTreeParser_atom_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_atom_return;



typedef struct ExprCppTreeParser_stmt_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_stmt_return;



typedef struct ExprCppTreeParser_block_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_block_return;



typedef struct ExprCppTreeParser_prog_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_prog_return;




/** Context tracking structure for 
ExprCppTreeParser

 */
struct ExprCppTreeParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;

     ExprCppTreeParser_expr_return
     (*expr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_multExpr_return
     (*multExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_midExpr_return
     (*midExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_arrayElem_return
     (*arrayElem)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_arrayElemAssign_return
     (*arrayElemAssign)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_defExpr_return
     (*defExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_assignExpr_return
     (*assignExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_conditionExpr_return
     (*conditionExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_ifExpr_return
     (*ifExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_forExpr_return
     (*forExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_whileExpr_return
     (*whileExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_caseExpr_return
     (*caseExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_defaultExpr_return
     (*defaultExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_switchExpr_return
     (*switchExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_atom_return
     (*atom)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_stmt_return
     (*stmt)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_block_return
     (*block)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_prog_return
     (*prog)	(struct ExprCppTreeParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct ExprCppTreeParser_Ctx_struct * ctx);
    void	    (*free)   (struct ExprCppTreeParser_Ctx_struct * ctx);
/* @headerFile.members() */
pANTLR3_BASE_TREE_ADAPTOR	adaptor;
pANTLR3_VECTOR_FACTORY		vectors;
/* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pExprCppTreeParser ExprCppTreeParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API pExprCppTreeParser ExprCppTreeParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__41      41
#define T__42      42
#define T__43      43
#define T__44      44
#define T__45      45
#define T__46      46
#define T__47      47
#define T__48      48
#define AND      4
#define ARRELEM      5
#define ARRELEMASSIGN      6
#define ASSIGN      7
#define BITAND      8
#define BITOR      9
#define BLOCK      10
#define BREAK      11
#define CASE      12
#define CONTINUE      13
#define DEF      14
#define DEFAULT      15
#define DIV      16
#define DOT      17
#define ELSE      18
#define EQ      19
#define FOR      20
#define GEQ      21
#define GT      22
#define ID      23
#define IF      24
#define INT      25
#define LEQ      26
#define LS      27
#define MID      28
#define MINUS      29
#define MOD      30
#define NEQ      31
#define NOT      32
#define OR      33
#define PLUS      34
#define PRINT      35
#define STRING      36
#define SWITCH      37
#define TIMES      38
#define WHILE      39
#define WS      40
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for ExprCppTreeParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
