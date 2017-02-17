//////////////////////////////////////////////////////////////////////
// parser.c
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tools/re2c/globals.h"
#include "tools/re2c/parse.h"
#include "tools/re2c/parser.h"

int yylex(void);
static RegExp *parse_expr(void);
static RegExp *parse_diff(void);
static RegExp *parse_term(void);
static RegExp *parse_factor(void);
static RegExp *parse_primary(void);

static unsigned int accept;
static RegExp *spec;
static Scanner *in;

static int curtok, peektok;
yystype yylval;
static yystype peekval;

#define get_next_token()    (curtok = yylex())

static void
get_peek_token(void)
{
    yystype temp = yylval; /* structure copy */
    if (peektok != NONE)
	Scanner_fatal(in, "more than one token of lookahead?");
    peektok = yylex();
    peekval = yylval; /* structure copy */
    yylval = temp;
}

static void
yyparse(void)
{
    RegExp *re, *look;

    accept = 0;
    spec = NULL;
    get_next_token();
    while (curtok != 0) {
	switch (curtok) {
	    case ID:
		get_peek_token();
		if (peektok == '=') {
		    /* ID = expr; */
		    Symbol *sym = yylval.symbol;
		    get_next_token(); /* id */
		    get_next_token(); /* = */
		    re = parse_expr();
		    if (curtok != ';')
			Scanner_fatal(in, "missing `;' after regexp");
		    get_next_token(); /* ; */
		    if (sym->re)
			Scanner_fatal(in, "sym already defined");
		    sym->re = re;
		    break;
		}
		/*@fallthrough@*/
	    default:
		/* rule: expr [/ expr] CODE */
		re = parse_expr();
		if (!re)
		    Scanner_fatal(in, "expression syntax error");

		if (curtok == '/') {
		    get_next_token(); /* / */
		    look = parse_expr();
		} else
		    look = RegExp_new_NullOp();

		if (curtok != CODE)
		    Scanner_fatal(in, "missing code after regexp");
		re = RegExp_new_RuleOp(re, look, yylval.token, accept++);
		get_next_token(); /* CODE */
		spec = spec ? mkAlt(spec, re) : re;
	}
    }
}

static RegExp *
parse_expr(void)
{
    RegExp *e, *f;
    e = parse_diff();
    while (curtok == '|') {
	get_next_token(); /* | */
	f = parse_diff();
	e = mkAlt(e, f);
    }
    return e;
}

static RegExp *
parse_diff(void)
{
    RegExp *e, *f;
    e = parse_term();
    while (curtok == '\\') {
	get_next_token(); /* \ */
	f = parse_term();
	e = mkDiff(e, f);
	if(!e)
	    Scanner_fatal(in, "can only difference char sets");
    }
    return e;
}

static RegExp *
parse_term(void)
{
    RegExp *e, *f;
    e = parse_factor();
    while ((f = parse_factor())) {
	e = RegExp_new_CatOp(e, f);
    }
    return e;
}

static RegExp *
parse_factor(void)
{
    RegExp *e;
    char ch;
    e = parse_primary();
    while (curtok == CLOSE || curtok == CLOSESIZE) {
	switch (curtok) {
	    case CLOSE:
		ch = yylval.op;
		while (get_next_token() == CLOSE) {
		    if (ch != yylval.op)
			ch = '*';
		}
		switch (ch) {
		    case '*':
			e = mkAlt(RegExp_new_CloseOp(e), RegExp_new_NullOp());
			break;
		    case '+':
			e = RegExp_new_CloseOp(e);
			break;
		    case '?':
			e = mkAlt(e, RegExp_new_NullOp());
			break;
		}
		break;
	    case CLOSESIZE:
		e = RegExp_new_CloseVOp(e, yylval.extop.minsize,
					yylval.extop.maxsize);
		get_next_token();	/* CLOSESIZE */
		break;
	    default:
		Scanner_fatal(in, "parse error");
		break;
	}
    }
    return e;
}

static RegExp *
parse_primary(void)
{
    RegExp *e;
    switch (curtok) {
	case ID:
	    if (!yylval.symbol->re)
		Scanner_fatal(in, "can't find symbol");
	    e = yylval.symbol->re;
	    get_next_token();
	    break;
	case RANGE:
	case STRING:
	    e = yylval.regexp;
	    get_next_token();
	    break;
	case '(':
	    get_next_token();
	    e = parse_expr();
	    if (curtok != ')')
		Scanner_fatal(in, "missing closing parenthesis");
	    get_next_token();
	    break;
	default:
	    return NULL;
    }
    return e;
}

int
yylex(void)
{
    if (peektok != NONE) {
	int tok = peektok;
	yylval = peekval;
	peektok = NONE;
	return tok;
    }
    return Scanner_scan(in);
}

void line_source(FILE *o, unsigned int line)
{
    char *	fnamebuf;
    char *	token;

    if (iFlag)
	return;
    fprintf(o, "#line %u \"", line);
    if( fileName != NULL ) {
    	fnamebuf = mystrdup( fileName );
    } else {
	fnamebuf = mystrdup( "<stdin>" );
    }
    token = strtok( fnamebuf, "\\" );
    for(;;) {
	fprintf(o, "%s", token);
	token = strtok( NULL, "\\" );
	if( token == NULL ) break;
	fputs("\\\\", o);
    }
    fputs("\"\n", o); oline++;
    free( fnamebuf );
}

void parse(FILE *i, FILE *o){
    time_t now;

    time(&now);

    peektok = NONE;

    fputs("/* Generated by re2c 0.9.1-C on ", o);
    fprintf(o, "%-24s", ctime(&now));
    fputs(" */\n", o); oline+=2;

    in = Scanner_new(i);

    line_source(o, Scanner_line(in));

    while(Scanner_echo(in, o)){
	yyparse();
	if(spec)
	    genCode(o, spec);
	line_source(o, Scanner_line(in));
    }
}


//////////////////////////////////////////////////////////////////////
// iDev.Games - MuOnline S9EP2 IGC9.5 - TRONG.WIN - DAO VAN TRONG     
//////////////////////////////////////////////////////////////////////

