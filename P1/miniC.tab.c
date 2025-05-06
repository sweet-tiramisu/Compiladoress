/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "miniC.y"

#include "listaSimbolos.h"
#include "listaCodigo.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
Lista tablaSimb;
int contCadenas=1;
int contadorEtiquetas = 1;

extern char *yytext;
extern int yylineno;
extern int yylex();
extern int errores;
void imprimirTablaS();
int perteneceTablaS(char * c);
void insertaTablaIdentificador(char * c, Tipo t);
int esConstante(char * c);
void insertaTablaString(char * c, Tipo t, int contCadenas);
void yyerror();
void imprimeLS();
char * registros[10] = {"$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$t8","$t9"};
int registrosOcupados[10] = {0};
char * obtenerReg();
char * concatena(char * a, char * b);
void liberarReg(char * reg);
void imprimirLC(ListaC codigo);
char * obtenerEtiqueta();
char * concatenaNumero (char * a, int num);


#line 104 "miniC.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "miniC.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STR = 3,                        /* STR  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_NUM = 5,                        /* NUM  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_PRINT = 13,                     /* PRINT  */
  YYSYMBOL_READ = 14,                      /* READ  */
  YYSYMBOL_SEPARADOR = 15,                 /* SEPARADOR  */
  YYSYMBOL_COMA = 16,                      /* COMA  */
  YYSYMBOL_PLUSOP = 17,                    /* PLUSOP  */
  YYSYMBOL_MINUSOP = 18,                   /* MINUSOP  */
  YYSYMBOL_MULOP = 19,                     /* MULOP  */
  YYSYMBOL_DIVOP = 20,                     /* DIVOP  */
  YYSYMBOL_ASIG = 21,                      /* ASIG  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LLLAVE = 24,                    /* LLLAVE  */
  YYSYMBOL_RLLAVE = 25,                    /* RLLAVE  */
  YYSYMBOL_INTERR = 26,                    /* INTERR  */
  YYSYMBOL_DPUNTOS = 27,                   /* DPUNTOS  */
  YYSYMBOL_MENOR = 28,                     /* MENOR  */
  YYSYMBOL_MAYOR = 29,                     /* MAYOR  */
  YYSYMBOL_MAYORIGUAL = 30,                /* MAYORIGUAL  */
  YYSYMBOL_MENORIGUAL = 31,                /* MENORIGUAL  */
  YYSYMBOL_IGUALIGUAL = 32,                /* IGUALIGUAL  */
  YYSYMBOL_NOIGUAL = 33,                   /* NOIGUAL  */
  YYSYMBOL_UMINUS = 34,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_declarations = 38,              /* declarations  */
  YYSYMBOL_tipo = 39,                      /* tipo  */
  YYSYMBOL_var_list = 40,                  /* var_list  */
  YYSYMBOL_const_list = 41,                /* const_list  */
  YYSYMBOL_statement_list = 42,            /* statement_list  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_print_list = 44,                /* print_list  */
  YYSYMBOL_print_item = 45,                /* print_item  */
  YYSYMBOL_read_list = 46,                 /* read_list  */
  YYSYMBOL_expression = 47                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    59,    62,    63,    67,    69,    72,    73,
      76,    86,   100,   104,   107,   120,   121,   157,   175,   213,
     234,   307,   308,   311,   312,   315,   341,   369,   398,   427,
     433,   439,   445,   451,   455,   464,   465,   477,   489,   508,
     528,   547,   567,   578
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STR", "ID", "NUM",
  "VAR", "CONST", "IF", "ELSE", "WHILE", "DO", "FOR", "PRINT", "READ",
  "SEPARADOR", "COMA", "PLUSOP", "MINUSOP", "MULOP", "DIVOP", "ASIG",
  "LPAREN", "RPAREN", "LLLAVE", "RLLAVE", "INTERR", "DPUNTOS", "MENOR",
  "MAYOR", "MAYORIGUAL", "MENORIGUAL", "IGUALIGUAL", "NOIGUAL", "UMINUS",
  "$accept", "program", "$@1", "declarations", "tipo", "var_list",
  "const_list", "statement_list", "statement", "print_list", "print_item",
  "read_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -25,     1,    -1,   -25,    12,    28,    46,   -25,    16,    68,
      68,     0,   -25,    70,    77,    64,    71,    81,    78,    82,
      83,    84,   -25,   -25,   -25,   -25,    17,    80,    23,    32,
      32,    32,    90,   114,    13,   116,    51,   -25,   117,    32,
     -25,   119,   -25,   -25,    32,    32,    79,   113,   130,    95,
     118,   -25,   -14,   -25,   212,   -25,     3,   -25,   -25,   212,
     131,   -25,    96,   -25,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    78,    78,    32,    32,    13,   120,
     133,   123,    32,   -25,    32,    52,    52,   -25,   -25,    10,
      10,    10,    10,    49,    49,   125,   -25,   147,   154,   -25,
     -25,   -25,   -25,   212,   171,    78,   136,    32,    32,   -25,
     -25,   188,   205,    78,   -25,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     6,    13,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     3,    12,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       5,     0,    42,    43,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    23,    25,    27,     0,    15,     9,    10,
       0,    34,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,    29,    30,    31,    32,    36,
      37,    39,    38,    40,    41,    17,    18,     0,     0,    24,
      21,    28,    22,    11,     0,     0,     0,     0,     0,    16,
      19,     0,     0,     0,    33,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -25,   -25,   -25,   -25,   144,   -25,   -25,   134,   -18,   -25,
      62,   -25,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,    13,    26,    28,    11,    24,    52,
      53,    56,    54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,     3,    78,     4,    15,    46,    47,    48,    16,    79,
      17,    18,    19,    20,    21,    59,    51,    42,    43,    80,
      61,    62,     9,    10,    22,    23,    81,    64,    65,    66,
      67,    44,    37,    38,     5,    45,    42,    43,    40,    41,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      44,     6,    97,    98,    45,    15,    95,    96,   103,    16,
     104,    17,    18,    19,    20,    21,    64,    65,    66,    67,
       7,    66,    67,    12,    25,    22,    57,    68,    69,    70,
      71,    27,    15,   111,   112,    29,    16,   109,    17,    18,
      19,    20,    21,    30,    63,   115,    64,    65,    66,    67,
      49,    39,    22,    31,    33,    34,    35,    68,    69,    70,
      71,    72,    73,    64,    65,    66,    67,    76,    50,    83,
      55,    58,    84,    60,    68,    69,    70,    71,    72,    73,
      64,    65,    66,    67,   105,   100,    74,   101,   102,    77,
      99,    68,    69,    70,    71,    72,    73,    64,    65,    66,
      67,   110,    82,    75,    14,     0,    36,     0,    68,    69,
      70,    71,    72,    73,    64,    65,    66,    67,     0,     0,
     106,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   107,    68,    69,    70,    71,    72,    73,    64,    65,
      66,    67,     0,     0,     0,     0,     0,     0,   108,    68,
      69,    70,    71,    72,    73,    64,    65,    66,    67,     0,
       0,   113,     0,     0,     0,     0,    68,    69,    70,    71,
      72,    73,    64,    65,    66,    67,     0,     0,   114,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      68,    69,    70,    71,    72,    73
};

static const yytype_int8 yycheck[] =
{
      18,     0,    16,     4,     4,    29,    30,    31,     8,    23,
      10,    11,    12,    13,    14,    39,     3,     4,     5,    16,
      44,    45,     6,     7,    24,    25,    23,    17,    18,    19,
      20,    18,    15,    16,    22,    22,     4,     5,    15,    16,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      18,    23,    76,    77,    22,     4,    74,    75,    82,     8,
      84,    10,    11,    12,    13,    14,    17,    18,    19,    20,
      24,    19,    20,     5,     4,    24,    25,    28,    29,    30,
      31,     4,     4,   107,   108,    21,     8,   105,    10,    11,
      12,    13,    14,    22,    15,   113,    17,    18,    19,    20,
      10,    21,    24,    22,    22,    22,    22,    28,    29,    30,
      31,    32,    33,    17,    18,    19,    20,    22,     4,    23,
       4,     4,    26,     4,    28,    29,    30,    31,    32,    33,
      17,    18,    19,    20,     9,    15,    23,     4,    15,    21,
      78,    28,    29,    30,    31,    32,    33,    17,    18,    19,
      20,    15,    21,    23,    10,    -1,    22,    -1,    28,    29,
      30,    31,    32,    33,    17,    18,    19,    20,    -1,    -1,
      23,    17,    18,    19,    20,    28,    29,    30,    31,    32,
      33,    27,    28,    29,    30,    31,    32,    33,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    17,    18,    19,    20,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    17,    18,    19,    20,    -1,    -1,    23,    17,
      18,    19,    20,    28,    29,    30,    31,    32,    33,    -1,
      28,    29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,     4,    22,    23,    24,    38,     6,
       7,    42,     5,    39,    39,     4,     8,    10,    11,    12,
      13,    14,    24,    25,    43,     4,    40,     4,    41,    21,
      22,    22,    43,    22,    22,    22,    42,    15,    16,    21,
      15,    16,     4,     5,    18,    22,    47,    47,    47,    10,
       4,     3,    44,    45,    47,     4,    46,    25,     4,    47,
       4,    47,    47,    15,    17,    18,    19,    20,    28,    29,
      30,    31,    32,    33,    23,    23,    22,    21,    16,    23,
      16,    23,    21,    23,    26,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    43,    43,    47,    47,    45,
      15,     4,    15,    47,    47,     9,    23,    27,    27,    43,
      15,    47,    47,    23,    23,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    37,    36,    38,    38,    38,    39,    40,    40,
      41,    41,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     5,     5,     0,     1,     1,     3,
       3,     5,     2,     0,     4,     3,     7,     5,     5,     7,
       9,     5,     5,     1,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     7,     2,     3,     3,     3,     3,     3,
       3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 59 "miniC.y"
                                {tablaSimb=creaLS();}
#line 1228 "miniC.tab.c"
    break;

  case 3: /* program: $@1 ID LPAREN RPAREN LLLAVE declarations statement_list RLLAVE  */
#line 59 "miniC.y"
                                                                                                                 {/*imprimirTablaS();*/ concatenaLC((yyvsp[-2].codigo),(yyvsp[-1].codigo)); imprimeLS(); imprimirLC((yyvsp[-2].codigo)); liberaLS(tablaSimb); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[-1].codigo));}
#line 1234 "miniC.tab.c"
    break;

  case 4: /* declarations: declarations VAR tipo var_list SEPARADOR  */
#line 62 "miniC.y"
                                                                                        {(yyval.codigo) = (yyvsp[-4].codigo);}
#line 1240 "miniC.tab.c"
    break;

  case 5: /* declarations: declarations CONST tipo const_list SEPARADOR  */
#line 63 "miniC.y"
                                                                                                {(yyval.codigo) = (yyvsp[-4].codigo);
																					concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
																					liberaLC((yyvsp[-1].codigo));
																					}
#line 1249 "miniC.tab.c"
    break;

  case 6: /* declarations: %empty  */
#line 67 "miniC.y"
                                                                                        {(yyval.codigo) = creaLC();}
#line 1255 "miniC.tab.c"
    break;

  case 8: /* var_list: ID  */
#line 72 "miniC.y"
                                                                                                                                                                {if (!perteneceTablaS((yyvsp[0].lexema))) insertaTablaIdentificador((yyvsp[0].lexema),VARIABLE); else printf("Error en linea %d : %s ya declarada \n",yylineno,(yyvsp[0].lexema));}
#line 1261 "miniC.tab.c"
    break;

  case 9: /* var_list: var_list COMA ID  */
#line 73 "miniC.y"
                                                                                                                                                        {if (!perteneceTablaS((yyvsp[0].lexema))) insertaTablaIdentificador((yyvsp[0].lexema),VARIABLE); else printf("Error en linea %d : %s ya declarada \n",yylineno,(yyvsp[0].lexema));}
#line 1267 "miniC.tab.c"
    break;

  case 10: /* const_list: ID ASIG expression  */
#line 76 "miniC.y"
                                                                                                                                                {if (!perteneceTablaS((yyvsp[-2].lexema))) insertaTablaIdentificador((yyvsp[-2].lexema),CONSTANTE); else printf("Error en linea %d : %s ya declarada \n",yylineno,(yyvsp[-2].lexema));
																					 (yyval.codigo) = (yyvsp[0].codigo);
																					 Operacion oper;
																					 oper.op = "sw";
																					 oper.res = recuperaResLC((yyvsp[0].codigo));
																					 oper.arg1 = concatena("_",(yyvsp[-2].lexema));
																					 oper.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					 liberarReg(oper.res);
																					}
#line 1282 "miniC.tab.c"
    break;

  case 11: /* const_list: const_list COMA ID ASIG expression  */
#line 86 "miniC.y"
                                                                                                                                        {if (!perteneceTablaS((yyvsp[-2].lexema))) insertaTablaIdentificador((yyvsp[-2].lexema),CONSTANTE); else printf("Error en linea %d : %s ya declarada \n",yylineno,(yyvsp[-2].lexema));
																					 (yyval.codigo) = (yyvsp[-4].codigo);
																					 concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					 Operacion oper;
																					 oper.op = "sw";
																					 oper.res = recuperaResLC((yyvsp[0].codigo));
																					 oper.arg1 = concatena("_",(yyvsp[-2].lexema));
																					 oper.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					 concatenaLC((yyvsp[0].codigo),(yyvsp[-4].codigo));
																					 liberarReg(oper.res);
																					}
#line 1299 "miniC.tab.c"
    break;

  case 12: /* statement_list: statement_list statement  */
#line 100 "miniC.y"
                                                                                        {(yyval.codigo) = (yyvsp[-1].codigo);
																					 concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					 liberaLC((yyvsp[0].codigo));
																					}
#line 1308 "miniC.tab.c"
    break;

  case 13: /* statement_list: %empty  */
#line 104 "miniC.y"
                                                                                                                                                {(yyval.codigo) = creaLC();}
#line 1314 "miniC.tab.c"
    break;

  case 14: /* statement: ID ASIG expression SEPARADOR  */
#line 107 "miniC.y"
                                                                                                                           {if (!perteneceTablaS((yyvsp[-3].lexema))) printf("Error en linea %d : %s no declarada \n",yylineno,(yyvsp[-3].lexema)); 
																					else if (esConstante((yyvsp[-3].lexema))) printf("Error en linea %d : %s es constante\n", yylineno, (yyvsp[-3].lexema));
																					(yyval.codigo) = (yyvsp[-1].codigo);
																					Operacion oper;
																					oper.op = "sw";
																					oper.res = recuperaResLC((yyvsp[-1].codigo));
																					oper.arg1 = concatena("_",(yyvsp[-3].lexema));
																					oper.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					liberarReg(oper.res);
																					//guardaResLC($$,oper.res); 

																					/*imprimirLC($3);*/}
#line 1332 "miniC.tab.c"
    break;

  case 15: /* statement: LLLAVE statement_list RLLAVE  */
#line 120 "miniC.y"
                                                                                       {(yyval.codigo) = (yyvsp[-1].codigo);}
#line 1338 "miniC.tab.c"
    break;

  case 16: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 121 "miniC.y"
                                                                                       {(yyval.codigo) = (yyvsp[-4].codigo);
																					Operacion oper;
																					oper.op = "beqz";
																					oper.res = recuperaResLC((yyvsp[-4].codigo));
																					oper.arg1 = obtenerEtiqueta();
																					oper.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
																					liberaLC((yyvsp[-2].codigo));

																					Operacion operacion2;
																					operacion2.op = "b";
																					operacion2.res = obtenerEtiqueta();//recuperaResLC($3);
																					operacion2.arg1 = NULL;//obtenerEtiqueta();
																					operacion2.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion2);
																					
																					
																					Operacion operacion3;
																					operacion3.op = "etiqueta";
																					operacion3.res = oper.arg1;
																					operacion3.arg1 = NULL;
																					operacion3.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion3);
																					//liberarReg(recuperaResLC($$));
																					concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					liberaLC((yyvsp[0].codigo));

																					Operacion operacion4;
																					operacion4.op = "etiqueta";
																					operacion4.res = operacion2.res;
																					operacion4.arg1 = NULL;
																					operacion4.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion4);
																					liberarReg(recuperaResLC((yyvsp[-4].codigo)));																						
																					}
#line 1379 "miniC.tab.c"
    break;

  case 17: /* statement: IF LPAREN expression RPAREN statement  */
#line 157 "miniC.y"
                                                                                       {(yyval.codigo) = (yyvsp[-2].codigo);
																					Operacion oper;
																					oper.op = "beqz";
																					oper.res = recuperaResLC((yyvsp[-2].codigo));
																					oper.arg1 = obtenerEtiqueta();
																					oper.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					liberaLC((yyvsp[0].codigo));

																					Operacion operacion2;
																					operacion2.op = "etiqueta";
																					operacion2.res = oper.arg1;
																					operacion2.arg1 = NULL;
																					operacion2.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion2);
																					liberarReg(recuperaResLC((yyval.codigo)));
																					}
#line 1402 "miniC.tab.c"
    break;

  case 18: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 175 "miniC.y"
                                                                                       {(yyval.codigo) = creaLC();
																					Operacion oper;
																					oper.op = "etiqueta";
																					oper.res = obtenerEtiqueta();
																					oper.arg1 = NULL;
																					oper.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

																					concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
																				
																					Operacion operacion2;
																					operacion2.op = "beqz";
																					operacion2.res = recuperaResLC((yyvsp[-2].codigo));
																					operacion2.arg1 = obtenerEtiqueta();
																					operacion2.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion2);
																					//liberaLC($3);

																					concatenaLC((yyval.codigo),(yyvsp[0].codigo));																					
																					liberaLC((yyvsp[0].codigo));																																																													
																					
																					Operacion operacion3;
																					operacion3.op = "b";
																					operacion3.res = oper.res;
																					operacion3.arg1 = NULL;
																					operacion3.arg2 = NULL;
																					//printf("insertando la b");
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion3);
																																										
																					Operacion operacion4;
																					operacion4.op = "etiqueta";
																					operacion4.res = operacion2.arg1;
																					operacion4.arg1 = NULL;
																					operacion4.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion4);
																					liberarReg(recuperaResLC((yyvsp[-2].codigo)));
																					
																				   }
#line 1445 "miniC.tab.c"
    break;

  case 19: /* statement: DO statement WHILE LPAREN expression RPAREN SEPARADOR  */
#line 213 "miniC.y"
                                                                                                           {(yyval.codigo) = creaLC();
																					Operacion oper;
																					oper.op = "etiqueta";
																					oper.res = obtenerEtiqueta();
																					oper.arg1 = NULL;
																					oper.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

																					concatenaLC((yyval.codigo),(yyvsp[-5].codigo));
																					concatenaLC((yyval.codigo),(yyvsp[-2].codigo));

																					Operacion operacion2;
																					operacion2.op = "bnez";
																					operacion2.res = recuperaResLC((yyvsp[-2].codigo));
																					operacion2.arg1 = oper.res;
																					operacion2.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion2);
																					
																					liberaLC((yyvsp[-5].codigo)); liberaLC((yyvsp[-2].codigo));
																					liberarReg(operacion2.res);
																					}
#line 1471 "miniC.tab.c"
    break;

  case 20: /* statement: FOR LPAREN ID ASIG expression DPUNTOS expression RPAREN statement  */
#line 234 "miniC.y"
                                                                                                                {
																					if(!perteneceTablaS((yyvsp[-6].lexema))){printf("Error en linea %d : %s no declarada \n",yylineno,(yyvsp[-6].lexema));} // ¿quitar el %s y poner variable?
																					else if (esConstante((yyvsp[-6].lexema))) printf("Error en linea %d : %s es constante, no se puede modificar\n", yylineno, (yyvsp[-6].lexema));
																					
																					// 1. inicio = $5
																					(yyval.codigo) = (yyvsp[-4].codigo);
																					Operacion oper;
																					oper.op = "sw";
																					oper.res = recuperaResLC((yyvsp[-4].codigo));
																					oper.arg1 = concatena("_",(yyvsp[-6].lexema));
																					oper.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					liberarReg(oper.res);

																					char * empiezaBucle = obtenerEtiqueta();
																					char * finalizaBucle = obtenerEtiqueta();

																					Operacion empezar;
																					empezar.op = "etiqueta";
																					empezar.res = empiezaBucle;
																					empezar.arg1 = NULL;
																					empezar.arg2 = NULL;
																					insertaLC((yyval.codigo), finalLC((yyval.codigo)), empezar);

																					Operacion carga;
																					carga.op = "lw";
																					carga.res = obtenerReg();
																					carga.arg1 = concatena("_",(yyvsp[-6].lexema));
																					carga.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),carga);
																					concatenaLC((yyval.codigo),(yyvsp[-2].codigo));

																					// Para saber si se ha llegado al final
																					Operacion comprobacion;
																					comprobacion.op = "bgt";
																					comprobacion.res = carga.res;
																					comprobacion.arg1 = recuperaResLC((yyvsp[-2].codigo));
																					comprobacion.arg2 = finalizaBucle;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),comprobacion);
																					concatenaLC((yyval.codigo),(yyvsp[0].codigo));

																					Operacion incrementar;
																					incrementar.op = "addi";
																					incrementar.res = carga.res;
																					incrementar.arg1 = carga.res;
																					incrementar.arg2 = "1";
																					insertaLC((yyval.codigo), finalLC((yyval.codigo)), incrementar);

																					Operacion almacenar;
																					almacenar.op = "sw";
																					almacenar.res = incrementar.res;
																					almacenar.arg1 = concatena("_",(yyvsp[-6].lexema));
																					almacenar.arg2 = NULL;
																					insertaLC((yyval.codigo), finalLC((yyval.codigo)), almacenar);

																					Operacion salto;
																					salto.op = "j";
																					salto.res = empiezaBucle;
																					salto.arg1 = NULL;
																					salto.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)),salto);

																					Operacion terminar;
																					terminar.op = "etiqueta";
																					terminar.res = finalizaBucle;
																					terminar.arg1 = NULL;
																					terminar.arg2 = NULL;
																					insertaLC((yyval.codigo),finalLC((yyval.codigo)), terminar);
																					liberarReg(carga.res);
																					liberarReg(recuperaResLC((yyvsp[-2].codigo)));

																					}
#line 1548 "miniC.tab.c"
    break;

  case 21: /* statement: PRINT LPAREN print_list RPAREN SEPARADOR  */
#line 307 "miniC.y"
                                                                                       {(yyval.codigo) = (yyvsp[-2].codigo);}
#line 1554 "miniC.tab.c"
    break;

  case 22: /* statement: READ LPAREN read_list RPAREN SEPARADOR  */
#line 308 "miniC.y"
                                                                                       {(yyval.codigo) = (yyvsp[-2].codigo);}
#line 1560 "miniC.tab.c"
    break;

  case 23: /* print_list: print_item  */
#line 311 "miniC.y"
                                                                                       {(yyval.codigo) = (yyvsp[0].codigo);}
#line 1566 "miniC.tab.c"
    break;

  case 24: /* print_list: print_list COMA print_item  */
#line 312 "miniC.y"
                                                                                       {(yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));}
#line 1572 "miniC.tab.c"
    break;

  case 25: /* print_item: expression  */
#line 315 "miniC.y"
                                                                                                                                                   { (yyval.codigo) = (yyvsp[0].codigo);
																					 Operacion oper;
																					 oper.op = "move";
																					 oper.res = "$a0";
																					 oper.arg1 = recuperaResLC((yyvsp[0].codigo));
																					 oper.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					 //guardaResLC($$,operacion2.res); 

																					 Operacion operacion2;
																					 operacion2.op = "li";
																					 operacion2.res = "$v0";
																					 operacion2.arg1 = "1";
																					 operacion2.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion2);
																					 //guardaResLC($$,operacion1.res); 
																					 																					 
																					 Operacion syscall;			
																					 syscall.op = "syscall";
																					 syscall.res = NULL;
																					 syscall.arg1 = NULL;
																					 syscall.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),syscall);
																					 //guardaResLC($$,syscall.res); 
																					 liberarReg(recuperaResLC((yyvsp[0].codigo)));
																					}
#line 1603 "miniC.tab.c"
    break;

  case 26: /* print_item: STR  */
#line 341 "miniC.y"
                                                                                                                                                                {insertaTablaString((yyvsp[0].lexema),CADENA,contCadenas);
																					 (yyval.codigo) = creaLC();
																					 Operacion operacion1;
																					 operacion1.op = "la";
																					 operacion1.res = "$a0";
																					 operacion1.arg1 = concatenaNumero("$str", contCadenas++);
																					 operacion1.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion1);
																					 //guardaResLC($$,operacion1.res); 

																					 Operacion operacion2;
																					 operacion2.op = "li";
																					 operacion2.res = "$v0";
																					 operacion2.arg1 = "4";
																					 operacion2.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion2);
																					 //guardaResLC($$,operacion2.res); 
																					 
																					 																					 Operacion syscall;			
																					 syscall.op = "syscall";
																					 syscall.res = NULL;
																					 syscall.arg1 = NULL;
																					 syscall.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),syscall);
																					 //guardaResLC($$,syscall.res); 
																					}
#line 1634 "miniC.tab.c"
    break;

  case 27: /* read_list: ID  */
#line 369 "miniC.y"
                                                                                                                                                    {if (!perteneceTablaS((yyvsp[0].lexema))) printf("Error en linea %d : %s no declarada \n", yylineno,(yyvsp[0].lexema));
																					else if (esConstante((yyvsp[0].lexema))) printf("Error en linea %d : %s es constante\n", yylineno, (yyvsp[0].lexema));
																					 (yyval.codigo) = creaLC();
																					 Operacion operacion1;
																					 operacion1.op = "li";
																					 operacion1.res = "$v0";
																					 operacion1.arg1 = "5";
																					 operacion1.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion1);
																					 //guardaResLC($$,operacion1.res); 
																					 
																					 Operacion syscall;			
																					 syscall.op = "syscall";
																					 syscall.res = NULL;
																					 syscall.arg1 = NULL;
																					 syscall.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),syscall);
																					 //guardaResLC($$,syscall.res); 
																					 
																					 Operacion operacion2;
																					 operacion2.op = "sw";
																					 operacion2.res = "$v0";
																					 operacion2.arg1 = concatena("_", (yyvsp[0].lexema));
																					 operacion2.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion2);
																					 //guardaResLC($$,operacion2.res); 

																					 
																					}
#line 1668 "miniC.tab.c"
    break;

  case 28: /* read_list: read_list COMA ID  */
#line 398 "miniC.y"
                                                                                                                                                        {if (!perteneceTablaS((yyvsp[0].lexema))) printf("Error en linea %d : %s no declarada \n", yylineno, (yyvsp[0].lexema));
																					else if (esConstante((yyvsp[0].lexema))) printf("Error en linea %d : %s es constante\n", yylineno, (yyvsp[0].lexema));
																					 (yyval.codigo) = (yyvsp[-2].codigo);
																					 Operacion operacion1;
																					 operacion1.op = "li";
																					 operacion1.res = "$v0";
																					 operacion1.arg1 = "5";
																					 operacion1.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion1);
																					 //guardaResLC($$,operacion1.res); 
																					 
																					 Operacion syscall;			
																					 syscall.op = "syscall";
																					 syscall.res = NULL;
																					 syscall.arg1 = NULL;
																					 syscall.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),syscall);
																					 //guardaResLC($$,syscall.res); 
																					 
																					 Operacion operacion2;
																					 operacion2.op = "sw";
																					 operacion2.res = "$v0";
																					 operacion2.arg1 = concatena("_", (yyvsp[0].lexema));
																					 operacion2.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion2);
																					 //guardaResLC($$,operacion2.res); 
																					}
#line 1700 "miniC.tab.c"
    break;

  case 29: /* expression: expression PLUSOP expression  */
#line 427 "miniC.y"
                                                                                                                        { (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					  Operacion oper; oper.op = "add"; oper.res = obtenerReg();
																					  oper.arg1 = recuperaResLC((yyvsp[-2].codigo)); oper.arg2 = recuperaResLC((yyvsp[0].codigo));
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); guardaResLC((yyval.codigo),oper.res); 
																					  liberarReg(oper.arg1); liberarReg(oper.arg2); liberaLC((yyvsp[0].codigo));
																					}
#line 1711 "miniC.tab.c"
    break;

  case 30: /* expression: expression MINUSOP expression  */
#line 433 "miniC.y"
                                                                                                        { (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					  Operacion oper; oper.op = "sub"; oper.res = obtenerReg();
																					  oper.arg1 = recuperaResLC((yyvsp[-2].codigo)); oper.arg2 = recuperaResLC((yyvsp[0].codigo));
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); guardaResLC((yyval.codigo),oper.res); 
																					  liberarReg(oper.arg1); liberarReg(oper.arg2); liberaLC((yyvsp[0].codigo));
																					}
#line 1722 "miniC.tab.c"
    break;

  case 31: /* expression: expression MULOP expression  */
#line 439 "miniC.y"
                                                                                                        { (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					  Operacion oper; oper.op = "mul"; oper.res = obtenerReg();
																					  oper.arg1 = recuperaResLC((yyvsp[-2].codigo)); oper.arg2 = recuperaResLC((yyvsp[0].codigo));
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); guardaResLC((yyval.codigo),oper.res); 
																					  liberarReg(oper.arg1); liberarReg(oper.arg2); liberaLC((yyvsp[0].codigo));
																					}
#line 1733 "miniC.tab.c"
    break;

  case 32: /* expression: expression DIVOP expression  */
#line 445 "miniC.y"
                                                                                        { (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					  Operacion oper; oper.op = "div"; oper.res = obtenerReg();
																					  oper.arg1 = recuperaResLC((yyvsp[-2].codigo)); oper.arg2 = recuperaResLC((yyvsp[0].codigo));
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); guardaResLC((yyval.codigo),oper.res); 
																					  liberarReg(oper.arg1); liberarReg(oper.arg2); liberaLC((yyvsp[0].codigo));
																					}
#line 1744 "miniC.tab.c"
    break;

  case 33: /* expression: LPAREN expression INTERR expression DPUNTOS expression RPAREN  */
#line 451 "miniC.y"
                                                                                        { (yyval.codigo)=(yyvsp[-5].codigo);
																					  Operacion oper;

																					}
#line 1753 "miniC.tab.c"
    break;

  case 34: /* expression: MINUSOP expression  */
#line 455 "miniC.y"
                                                                                        {(yyval.codigo) = (yyvsp[0].codigo);
																					 Operacion oper;
																					 oper.op = "neg";
																					 oper.res = recuperaResLC((yyvsp[0].codigo));
																					 oper.arg1 = recuperaResLC((yyvsp[0].codigo));
																					 oper.arg2 = NULL;
																					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					 guardaResLC((yyval.codigo),oper.res);
																					}
#line 1767 "miniC.tab.c"
    break;

  case 35: /* expression: LPAREN expression RPAREN  */
#line 464 "miniC.y"
                                                                                        {(yyval.codigo) = (yyvsp[-1].codigo);}
#line 1773 "miniC.tab.c"
    break;

  case 36: /* expression: expression MENOR expression  */
#line 465 "miniC.y"
                                                                                                                                                { (yyval.codigo) = (yyvsp[-2].codigo);
																					  Operacion menor;
																					  menor.op = "slt";
																					  menor.res = recuperaResLC((yyvsp[-2].codigo));
																					  menor.arg1 = menor.res;
																					  menor.arg2 = recuperaResLC((yyvsp[0].codigo));

																					  concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),menor);
																					  liberarReg(recuperaResLC((yyvsp[0].codigo)));
																					  liberaLC((yyvsp[0].codigo));
																					}
#line 1790 "miniC.tab.c"
    break;

  case 37: /* expression: expression MAYOR expression  */
#line 477 "miniC.y"
                                                                                                                                                { (yyval.codigo) = (yyvsp[-2].codigo);
																					  Operacion mayor;
																					  mayor.op = "slt";
																					  mayor.res = recuperaResLC((yyvsp[0].codigo));
																					  mayor.arg1 = mayor.res;
																					  mayor.arg2 = recuperaResLC((yyvsp[-2].codigo));
																					  liberarReg(recuperaResLC((yyvsp[-2].codigo)));
																					  concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),mayor);
																					  guardaResLC((yyval.codigo),recuperaResLC((yyvsp[0].codigo)));
																					  liberaLC((yyvsp[0].codigo));
																					}
#line 1807 "miniC.tab.c"
    break;

  case 38: /* expression: expression MENORIGUAL expression  */
#line 489 "miniC.y"
                                                                                                                                        { (yyval.codigo) = (yyvsp[-2].codigo);			// Si se tiene a > b -> ¬(a > b) = a <= b
																					  Operacion mayor;
																					  mayor.op = "slt";
																					  mayor.res = recuperaResLC((yyvsp[0].codigo));
																					  mayor.arg1 = mayor.res;
																					  mayor.arg2 = recuperaResLC((yyvsp[-2].codigo));

																					  Operacion negado;
																					  negado.op = "xori";
																					  negado.res = mayor.res;
																					  negado.arg1 = mayor.res;
																					  negado.arg2 = "1";
																					  concatenaLC((yyval.codigo),(yyvsp[0].codigo));

																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),mayor);
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),negado);
																					  guardaResLC((yyval.codigo),recuperaResLC((yyvsp[0].codigo)));
																					  liberaLC((yyvsp[0].codigo));																					  
																					}
#line 1831 "miniC.tab.c"
    break;

  case 39: /* expression: expression MAYORIGUAL expression  */
#line 508 "miniC.y"
                                                                                                                                        { (yyval.codigo) = (yyvsp[-2].codigo);			// Si se tiene a < b -> ¬(a < b) = a >= b
																					  Operacion menor;
																					  menor.op = "slt";
																					  menor.res = recuperaResLC((yyvsp[-2].codigo));
																					  menor.arg1 = menor.res;
																					  menor.arg2 = recuperaResLC((yyvsp[0].codigo));

																					  Operacion negado;
																					  negado.op = "xori";
																					  negado.res = menor.res;
																					  negado.arg1 = menor.res;
																					  negado.arg2 = "1";
																					  concatenaLC((yyval.codigo),(yyvsp[0].codigo));

																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),menor);
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),negado);
																					  //guardaResLC($$,recuperaResLC($3));
																					  liberarReg(recuperaResLC((yyvsp[0].codigo)));
																					  liberaLC((yyvsp[0].codigo));	
																					}
#line 1856 "miniC.tab.c"
    break;

  case 40: /* expression: expression IGUALIGUAL expression  */
#line 528 "miniC.y"
                                                                                                                                        { (yyval.codigo) = (yyvsp[-2].codigo);
																					  Operacion xor;
																					  xor.op = "xor";
																					  xor.res = obtenerReg();
																					  xor.arg1 = recuperaResLC((yyvsp[-2].codigo));
																					  xor.arg2 = recuperaResLC((yyvsp[0].codigo));
																					  
																					  Operacion igual;
																					  igual.op = "sltiu";
																					  igual.res = xor.res;
																					  igual.arg1 = xor.res;
																					  igual.arg2 = "1";

																					  concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),xor);
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),igual);
																					  liberarReg(recuperaResLC((yyvsp[0].codigo)));
																					  liberaLC((yyvsp[0].codigo));
																					}
#line 1880 "miniC.tab.c"
    break;

  case 41: /* expression: expression NOIGUAL expression  */
#line 547 "miniC.y"
                                                                                                                                        { (yyval.codigo) = (yyvsp[-2].codigo);
																					  Operacion xor;
																					  xor.op = "xor";
																					  xor.res = obtenerReg();
																					  xor.arg1 = recuperaResLC((yyvsp[-2].codigo));
																					  xor.arg2 = recuperaResLC((yyvsp[0].codigo));
																					  
																					  Operacion distinto;
																					  distinto.op = "sltu";
																					  distinto.res = xor.res;
																					  distinto.arg1 = xor.res;
																					  distinto.arg2 = "0";

																					  concatenaLC((yyval.codigo),(yyvsp[0].codigo));
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),xor);
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),distinto);
																					  liberarReg(recuperaResLC((yyvsp[0].codigo)));
																					  liberaLC((yyvsp[0].codigo));
																					}
#line 1904 "miniC.tab.c"
    break;

  case 42: /* expression: ID  */
#line 567 "miniC.y"
                                                                                                                                                                        { if (!perteneceTablaS((yyvsp[0].lexema))) printf("Error en linea %d : %s no declarada \n", 
																					  yylineno, (yyvsp[0].lexema)); 
																					  (yyval.codigo) = creaLC();
																					  Operacion oper;
																					  oper.op = "lw";
																					  oper.res = obtenerReg();
																					  oper.arg1 = concatena("_",(yyvsp[0].lexema));
																					  oper.arg2 = NULL;
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					  guardaResLC((yyval.codigo),oper.res); 
																					}
#line 1920 "miniC.tab.c"
    break;

  case 43: /* expression: NUM  */
#line 578 "miniC.y"
                                                                                                                                                        { (yyval.codigo) = creaLC();
																					  Operacion oper;
																					  oper.op = "li";
																					  oper.res = obtenerReg();
																					  oper.arg1 = (yyvsp[0].lexema);
																					  oper.arg2 = NULL;
																					  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
																					  guardaResLC((yyval.codigo),oper.res);
																					}
#line 1934 "miniC.tab.c"
    break;


#line 1938 "miniC.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 589 "miniC.y"



void yyerror() {
    printf("Error sintactico en token %s y linea %d\n", yytext, yylineno);
}


void imprimirTablaS() {
	//printf("Imprimiendo lista de %d simbolos\n",longitudLS(tablaSimb));
  	PosicionLista p = inicioLS(tablaSimb);
  	while (p != finalLS(tablaSimb)) {
    		Simbolo aux = recuperaLS(tablaSimb,p);
    		char *tipo;
    		switch (aux.tipo) {
        		case VARIABLE:
            			tipo = "variable";
           		break;
        		case CONSTANTE:
            			tipo = "constante";
            		break;
				case CADENA:
						tipo = "cadena";
					break;
        		default:
            		tipo = "otro";
    		}
    		//printf("%s es %s\n",aux.nombre,tipo);    
    		p = siguienteLS(tablaSimb,p);
  	}
}

int perteneceTablaS(char * c) {
	PosicionLista p = buscaLS(tablaSimb, c);
	return (p != finalLS(tablaSimb));
}

void insertaTablaIdentificador(char * c, Tipo t) {
	Simbolo aux;
	aux.nombre = c;
	aux.tipo = t;
	aux.valor = 0;
	//printf("El tipo es %d\n", aux.tipo);
	//printf("Insertando variable %s en la tabla de simbolos\n", c);
	
	insertaLS(tablaSimb, finalLS(tablaSimb), aux);
	
}

int esConstante(char * c) {
	PosicionLista p = buscaLS(tablaSimb, c);
	int cte = 0;
	if(p!= finalLS(tablaSimb)){
		Simbolo aux = recuperaLS(tablaSimb,p);
		if(aux.tipo == CONSTANTE)
			cte = 1;
	}
	
	return cte;
}

void insertaTablaString(char * c, Tipo t, int contCadenas) {
	/*Simbolo aux;
	sprintf(aux.nombre, "str%d",contCadenas);
	aux.tipo = t;
	// aux.valor = c;
	printf("Insertando cadena str%d -> (%s) en la tabla de simbolos\n", contCadenas, c);*/
	Simbolo aux;
	aux.nombre = c;
	aux.tipo = t;
	aux.valor = contCadenas;
	contCadenas++;
	insertaLS(tablaSimb, finalLS(tablaSimb), aux);
}

void imprimeLS(){	// .data del programa
	printf("##################\n");
	printf("# Seccion de datos\n");
	printf("\t.data\n\n");
	PosicionLista p = inicioLS(tablaSimb);
	//Primero imprimimos las cadenas
	while(p!=finalLS(tablaSimb)){
		Simbolo aux = recuperaLS(tablaSimb,p);
		if(aux.tipo == CADENA){
			printf("str%d: \n\t.asciiz %s \n",aux.valor,aux.nombre);
		}
		p = siguienteLS(tablaSimb,p);
	}

	//Imprimo variables y constantes
	p = inicioLS(tablaSimb);
	while(p!=finalLS(tablaSimb)){
		Simbolo aux = recuperaLS(tablaSimb,p);
		if(aux.tipo == VARIABLE || aux.tipo == CONSTANTE){
			printf("_%s: \n\t.word 0 \n",aux.nombre);
		} 
		p = siguienteLS(tablaSimb,p);
	}

}

char * obtenerReg(){
	// Algoritmo de búsqueda:
	int i = 0;
	while(i < 10 && registrosOcupados[i]){
		i++;
	}

	if(!registrosOcupados[i]){
		registrosOcupados[i] = 1;
	}

	return registros[i];

}

char * concatena(char * a, char * b){
	/*int tamanoBuffer = strlen(a) + strlen(b) + 1; //malloc(sizeof(char)*34); //32 del tamaño del ID + "/0" + "_"
	char * buffer = malloc(tamanoBuffer * sizeof(char));
	sprintf(buffer, "%s%s", a, b);
	return buffer;*/
	char buffer[40];
	sprintf(buffer, "%s%s", a, b);
	return strdup(buffer);
}

char * concatenaNumero (char * a, int num){
	char buffer[32];
	sprintf(buffer, "%s%d", a, num);
	return strdup(buffer);
}

void liberarReg(char * reg) {
    if (reg == NULL) return;

    char * numero = &reg[2];				// tomo el dígito del registro: "$t7" -> 7
    int nuevoRegistro = atoi(numero);		
	 if (nuevoRegistro >= 0 && nuevoRegistro < 10) 
		registrosOcupados[nuevoRegistro] = 0;	// libero el reg seleccionado
}

void imprimirLC(ListaC codigo) {
	printf("###################\n");
	printf("# Seccion de codigo\n");
	printf("\t.text\n");
	printf("\t.globl main\n");
	printf("main:\n");
	PosicionListaC p = inicioLC(codigo);
	while (p != finalLC(codigo)) {
		Operacion oper = recuperaLC(codigo,p);
		if(strcmp(oper.op, "etiqueta") == 0){
			 printf("%s: \n", oper.res);
		}else{
			printf("\t%s",oper.op);
			if (oper.res) printf(" %s",oper.res);
			if (oper.arg1) printf(", %s",oper.arg1);
			if (oper.arg2) printf(", %s",oper.arg2);
			printf("\n");
		}
		
		p = siguienteLC(codigo,p);
	}
	printf("\n");
	printf("##############\n");
	printf("# Fin\n");
	printf("\tli $v0, 10\n");
	printf("\tsyscall\n");
	
}

char *obtenerEtiqueta() {
	char aux[32];
	sprintf(aux,"$l%d",contadorEtiquetas++);
	return strdup(aux);
}
