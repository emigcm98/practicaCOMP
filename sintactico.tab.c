/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintactico.y"


    #include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "listaSimbolos.h"
	#include "listaCodigo.h"

    extern int yylex();
    extern int yylineno;
	extern int yytext();
    
	Lista tablaSimb;
    int errores_sintacticos = 0;
	int errores_semanticos = 0;
	int contador_string = 0;
    void yyerror (char const *);

	Tipo tipo; //para mostrar cuándo es constante, variable o string

	short registros[10] = {0};
	char* getRegistro(); //te da el primer registro disponible
	void liberarReg(char*); //libera el registro que le pases
	char* generaEtiqSalto();
	void generarCodigoFuncion(ListaC);

	/* statements */
	int contadorSalto = 1;

	/* FUNCIONES */
	char args_on; //estoy en los argumentos
	char * function_name;
	int n_args; // numero de argumentos de la funcion actual;

#line 105 "sintactico.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 41 "sintactico.y"

	#include "listaCodigo.h"

#line 152 "sintactico.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEGINN = 258,
    END = 259,
    READ = 260,
    WRITE = 261,
    PARI = 262,
    PARD = 263,
    PYC = 264,
    COMA = 265,
    ASIG = 266,
    PROGRAM = 267,
    FUNCTION = 268,
    CONST = 269,
    IF = 270,
    ELSE = 271,
    THEN = 272,
    DOSPUNTOS = 273,
    MAS = 274,
    MENOS = 275,
    POR = 276,
    DIV = 277,
    PUNTO = 278,
    INTEGER = 279,
    VAR = 280,
    WHILE = 281,
    DO = 282,
    FOR = 283,
    TO = 284,
    STRING = 285,
    ID = 286,
    ENTERO = 287,
    UMINUS = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "sintactico.y"

	char *lexema;
	ListaC codigo;

#line 202 "sintactico.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    91,   129,   130,   132,   146,   146,   146,
     132,   180,   180,   187,   187,   195,   197,   247,   301,   303,
     335,   355,   360,   361,   363,   366,   374,   428,   456,   500,
     543,   631,   635,   638,   642,   643,   652,   713,   750,   783,
     818,   836,   854,   871,   888,   902,   906,   940,   951,   991,
     992,   994,  1011
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"begin\"", "\"end\"", "\"read\"",
  "\"write\"", "\"(\"", "\")\"", "\";\"", "\",\"", "\":=\"", "\"program\"",
  "\"function\"", "\"const\"", "\"if\"", "\"else\"", "\"then\"", "\":\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\".\"", "\"integer\"", "\"var\"",
  "\"while\"", "\"do\"", "\"for\"", "\"to\"", "STRING", "ID", "ENTERO",
  "UMINUS", "$accept", "program", "$@1", "functions", "function", "$@2",
  "$@3", "$@4", "$@5", "declarations", "$@6", "$@7", "identifiers", "type",
  "constants", "compound_statement", "optional_statements", "statements",
  "statement", "print_list", "print_item", "read_list", "expression",
  "optional_arguments", "expressions", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -96,    10,     1,   -96,   -25,    14,    21,    23,   -96,    24,
      16,    58,     6,   -96,   -96,     2,   -96,   -96,    56,    52,
      79,    80,    19,    19,    57,    84,   -96,    92,    88,   -96,
      67,    68,   -96,    86,    70,     4,    19,    19,    95,   -96,
      72,    50,    93,    19,   -96,     2,    96,    43,   -96,    -6,
     -96,   -96,    17,   -96,    36,   -96,    54,    41,   -96,    19,
       2,    19,    19,    19,    19,     2,    19,    54,   -96,    19,
     -96,    75,    77,    85,    68,   -96,    81,   -96,     4,   -96,
      54,   102,   101,    87,    44,    44,   -96,   -96,   -96,    35,
      54,   103,   -96,   -96,   104,   105,   -96,   -96,   -96,    19,
       2,    19,    19,   -96,    98,    54,   -96,    63,    54,    85,
       2,   109,   -96,   100,    85,   -96,   -96,     6,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,     5,    15,
       0,     0,     0,     6,     4,    23,    13,    11,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,    22,    24,
       0,     0,     3,     0,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,    21,     0,     0,     0,    16,     0,
       7,    38,     0,    37,     0,    34,    36,     0,    44,    50,
       0,     0,     0,     0,     0,     0,     0,    26,    25,     0,
      14,     0,     0,     0,     0,    32,     0,    31,     0,    45,
      51,     0,    49,    27,    40,    41,    42,    43,    29,     0,
      19,     0,    17,    18,     0,     8,    39,    35,    48,     0,
       0,     0,     0,    12,     0,    52,    28,     0,    20,     0,
       0,     0,    30,     0,     0,     9,    15,     0,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     3,
     -96,   -96,    46,   -95,   -96,   -12,   -96,   -96,   -42,   -96,
      45,   -96,   -21,   -96,   -96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     9,    11,    19,    74,   104,   116,    12,
      31,    30,    49,    94,    47,    26,    27,    28,    29,    54,
      55,    52,    56,    81,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    40,    41,    68,    72,    15,     5,    20,    21,    15,
       3,    36,    73,     4,   111,    57,    58,    22,    83,   115,
      16,     6,    67,    88,    37,    75,    36,    76,    23,     7,
      24,    17,     8,    25,    53,    38,    39,    10,    80,    37,
      84,    85,    86,    87,    77,    89,    78,    13,    90,    79,
      38,    39,    70,    71,    61,    62,    63,    64,   106,    33,
      61,    62,    63,    64,   101,    63,    64,    14,   112,    61,
      62,    63,    64,    61,    62,    63,    64,    65,   105,    32,
     107,   108,    61,    62,    63,    64,    34,    35,    42,    60,
     110,    61,    62,    63,    64,    43,    44,    45,    46,    48,
      50,    51,    59,   100,    66,   118,    91,    69,    92,    93,
      98,    99,    96,   103,   102,    72,   109,   113,   114,   117,
      95,     0,     0,    97
};

static const yytype_int8 yycheck[] =
{
      12,    22,    23,    45,    10,     3,    31,     5,     6,     3,
       0,     7,    18,    12,   109,    36,    37,    15,    60,   114,
      14,     7,    43,    65,    20,     8,     7,    10,    26,     8,
      28,    25,     9,    31,    30,    31,    32,    13,    59,    20,
      61,    62,    63,    64,     8,    66,    10,    31,    69,     8,
      31,    32,     9,    10,    19,    20,    21,    22,   100,     7,
      19,    20,    21,    22,    29,    21,    22,     9,   110,    19,
      20,    21,    22,    19,    20,    21,    22,    27,    99,    23,
     101,   102,    19,    20,    21,    22,     7,     7,    31,    17,
      27,    19,    20,    21,    22,    11,     4,     9,    31,    31,
      14,    31,     7,    16,    11,   117,    31,    11,    31,    24,
       8,    10,    31,     9,    11,    10,    18,     8,    18,   116,
      74,    -1,    -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    36,     0,    12,    31,     7,     8,     9,    37,
      13,    38,    43,    31,     9,     3,    14,    25,    49,    39,
       5,     6,    15,    26,    28,    31,    49,    50,    51,    52,
      45,    44,    23,     7,     7,     7,     7,    20,    31,    32,
      56,    56,    31,    11,     4,     9,    31,    48,    31,    46,
      14,    31,    55,    30,    53,    54,    56,    56,    56,     7,
      17,    19,    20,    21,    22,    27,    11,    56,    52,    11,
       9,    10,    10,    18,    40,     8,    10,     8,    10,     8,
      56,    57,    58,    52,    56,    56,    56,    56,    52,    56,
      56,    31,    31,    24,    47,    46,    31,    54,     8,    10,
      16,    29,    11,     9,    41,    56,    52,    56,    56,    18,
      27,    47,    52,     8,    18,    47,    42,    43,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    36,    35,    37,    37,    39,    40,    41,    42,
      38,    44,    43,    45,    43,    43,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,    10,     3,     0,     0,     0,     0,     0,
      16,     0,     7,     0,     5,     0,     1,     3,     1,     3,
       5,     3,     1,     0,     1,     3,     3,     4,     6,     4,
       8,     4,     4,     1,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     4,     1,
       0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 91 "sintactico.y"
          {tablaSimb=creaLS(); }
#line 1454 "sintactico.tab.c"
    break;

  case 3:
#line 91 "sintactico.y"
                                                                                                        { 
	
	if(errores_semanticos==0){
		
		printf("##################\n# Seccion de datos\n\t.data\n\n");
		imprimirLS(tablaSimb, CADENA);
		imprimirLS(tablaSimb, VARIABLE); 
		imprimirLS(tablaSimb, CONSTANTE);

		printf("\n####################\n # Seccion de codigo\n\t.text\n\t.globl main\n\n");
			
		Operacion o;
		o.op = "li";
		o.res = "$v0";
		o.arg1 = "10";
		o.arg2 = NULL;
		insertaLC((yyvsp[-1].codigo), finalLC((yyvsp[-1].codigo)), o);
		Operacion o2;
		o2.op = "syscall";
		o2.res = NULL;
		o2.arg1 = NULL;
		o2.arg2 = NULL;
		insertaLC((yyvsp[-1].codigo), finalLC((yyvsp[-1].codigo)), o2);

		imprimirLC((yyvsp[-3].codigo));	//funciones	
		printf("main:\n");
		imprimirLC((yyvsp[-2].codigo)); //declaraciones
		imprimirLC((yyvsp[-1].codigo)); //codigo

		liberaLC((yyvsp[-3].codigo));
		liberaLC((yyvsp[-2].codigo));
		liberaLC((yyvsp[-1].codigo));
		liberaLS(tablaSimb);
	}
	

	}
#line 1496 "sintactico.tab.c"
    break;

  case 4:
#line 129 "sintactico.y"
                                   {concatenaLC((yyval.codigo),(yyvsp[-1].codigo));}
#line 1502 "sintactico.tab.c"
    break;

  case 5:
#line 130 "sintactico.y"
                  {(yyval.codigo)=creaLC();}
#line 1508 "sintactico.tab.c"
    break;

  case 6:
#line 132 "sintactico.y"
                       {

	if (buscaLS(tablaSimb, (yyvsp[0].lexema)) == finalLS(tablaSimb)){ //si llegamos al final, no está
		Simbolo s;
		s.tipo = FUNCION;
		s.nombre = (yyvsp[0].lexema);
		s.valor = 0; // numero de argumentos
		function_name = (yyvsp[0].lexema);
		insertaLS(tablaSimb, finalLS(tablaSimb), s);
	}
	else{	//insertamos al final
		printf("Error en linea %d: Variable %s ya declarada, no puede identificar a una función\n", yylineno, (yyvsp[0].lexema));
		errores_semanticos++;
	}
}
#line 1528 "sintactico.tab.c"
    break;

  case 7:
#line 146 "sintactico.y"
              {args_on = 1;}
#line 1534 "sintactico.tab.c"
    break;

  case 8:
#line 146 "sintactico.y"
                                         {args_on=0;}
#line 1540 "sintactico.tab.c"
    break;

  case 9:
#line 146 "sintactico.y"
                                                                            {

		if(n_args>4){
			printf("Error en linea %d: se tienen %d argumentos, pero el máximo es 4\n", yylineno, n_args);
			errores_semanticos++;
		}
		
		PosicionLista p = buscaLS(tablaSimb, (yyvsp[-11].lexema));
		Simbolo s = recuperaLS(tablaSimb, p);
		s.valor = n_args; 
		suprimeLS(tablaSimb, p);
		insertaLS(tablaSimb, finalLS(tablaSimb), s); //lo sacamos, cambiamos, suprimimos e insertamos de nuevo con el nuevo valor
				
		n_args = 0; //ponemos a 0 para la siguiente funcion
		
	}
#line 1561 "sintactico.tab.c"
    break;

  case 10:
#line 161 "sintactico.y"
                                          { 
			
			(yyval.codigo) = creaLC();
			concatenaLC((yyval.codigo),(yyvsp[-9].codigo));
			concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
			concatenaLC((yyval.codigo),(yyvsp[0].codigo));		
			function_name=NULL;

			generarCodigoFuncion((yyval.codigo)); //codigo de apilación
			
			Operacion salto; //etiqueta de salto
			salto.op = NULL;
			salto.res = concat(concat("_", (yyvsp[-14].lexema)),":"); //$2 es el ID
			salto.arg1 = NULL;
			salto.arg2 = NULL;
			insertaLC((yyval.codigo), inicioLC((yyval.codigo)), salto);
	
		}
#line 1584 "sintactico.tab.c"
    break;

  case 11:
#line 180 "sintactico.y"
                                  {tipo = VARIABLE;}
#line 1590 "sintactico.tab.c"
    break;

  case 12:
#line 180 "sintactico.y"
                                                                               {
				(yyval.codigo) = creaLC();
				concatenaLC((yyval.codigo),(yyvsp[-6].codigo));
				concatenaLC((yyval.codigo),(yyvsp[-3].codigo));
				liberaLC((yyvsp[-6].codigo));
				liberaLC((yyvsp[-3].codigo));
			}
#line 1602 "sintactico.tab.c"
    break;

  case 13:
#line 187 "sintactico.y"
                                               {tipo = CONSTANTE;}
#line 1608 "sintactico.tab.c"
    break;

  case 14:
#line 187 "sintactico.y"
                                                                                 {
				(yyval.codigo) = creaLC();
				concatenaLC((yyval.codigo),(yyvsp[-4].codigo));
				concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
				liberaLC((yyvsp[-4].codigo));
				liberaLC((yyvsp[-1].codigo));

			}
#line 1621 "sintactico.tab.c"
    break;

  case 15:
#line 195 "sintactico.y"
                                      {(yyval.codigo) = creaLC();}
#line 1627 "sintactico.tab.c"
    break;

  case 16:
#line 197 "sintactico.y"
                 { 
				(yyval.codigo)=creaLC();
				if(args_on){ //si son ARGUMENTOS

					if (buscaLS(tablaSimb, (yyvsp[0].lexema)) == finalLS(tablaSimb)){
						Simbolo s;
						s.tipo = ARGUMENTO; //la variable de un argumento es constante
						s.nombre = concat(concat(function_name,"."), (yyvsp[0].lexema));
						s.valor = n_args; // el numero de argumento.
						insertaLS(tablaSimb, finalLS(tablaSimb),s);
						n_args++; //tenemos un argumento más siendo procesado

					}
					else {
						printf("Error en linea %d: Variable %s ya declarada, quizas en el nombre de la funcion \n", yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				}
				else{

					char* var;
					if (function_name == NULL) var = (yyvsp[0].lexema); 
					else{
						if(buscaLS(tablaSimb, (yyvsp[0].lexema)) == finalLS(tablaSimb))
							var = concat(concat(function_name,"."), (yyvsp[0].lexema)); //ambito de una funcion
						else var = (yyvsp[0].lexema);
					} 

					if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){ //si llegamos al final, no está
						Simbolo s;
						if (function_name!=NULL){ //estamos declarando variable del ambito de la funcion strcmp(function_name,"nada")!=0
							s.tipo = tipo;
							s.nombre = concat(concat(function_name,"."), (yyvsp[0].lexema));
							s.valor = n_args; //el numero del argumento 
						}
						else {
							s.tipo = tipo;
							s.nombre = (yyvsp[0].lexema);
							s.valor = 0; // por defecto
						}
						insertaLS(tablaSimb, finalLS(tablaSimb), s);
					}
					else{	//insertamos al final
						printf("Error en linea %d: Variable %s ya declarada \n", yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				}

			}
#line 1681 "sintactico.tab.c"
    break;

  case 17:
#line 247 "sintactico.y"
                                             {
				(yyval.codigo)=creaLC();
				if(args_on){ //si son identificadores de parametro de una función...
					//calcular el número de argumentos convirtiendo a identifiers en tipo entero
					if (buscaLS(tablaSimb, (yyvsp[0].lexema)) == finalLS(tablaSimb)){
						Simbolo s;
						s.tipo = ARGUMENTO; //la variable de un argumento es constante
						s.nombre = concat(concat(function_name,"."), (yyvsp[0].lexema)); //y.a
						s.valor = 0; // por defecto 
						insertaLS(tablaSimb, finalLS(tablaSimb),s);
						n_args++; 
					}
					else {
						printf("Error en linea %d: Variable %s ya declarada, quizas en el nombre de la funcion \n", yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				}
				else{			
					concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
					liberaLC((yyvsp[-2].codigo));

					char* var;
					if (function_name == NULL) var = (yyvsp[0].lexema); 
					else{
						if(buscaLS(tablaSimb, (yyvsp[0].lexema)) == finalLS(tablaSimb))
							var = concat(concat(function_name,"."), (yyvsp[0].lexema)); //ambito de una funcion
						else var = (yyvsp[0].lexema);
					}

					/*char* var;
					if (function_name == NULL) var = $3;
					else var = concat(concat(function_name,"."), $3); //si estoy en el ambito de una funcion*/

					if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){
						Simbolo s;
						if (function_name!=NULL){ //estamos declarando variable del ambito de la funcion strcmp(function_name,"nada")!=0
							s.tipo = tipo;
							s.nombre = concat(concat(function_name,"."), (yyvsp[0].lexema));
							s.valor = 0; // por defecto 
						}
						else {
							s.tipo = tipo;
							s.nombre = (yyvsp[0].lexema);
							s.valor = 0; // por defecto
						}
						insertaLS(tablaSimb, finalLS(tablaSimb), s);
					} 
					else{	//insertamos al final
						printf("Error en linea %d: Variable %s ya declarada \n", yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				}
					
			}
#line 1740 "sintactico.tab.c"
    break;

  case 19:
#line 303 "sintactico.y"
                                     { 
					(yyval.codigo)=creaLC();
					char* var;
					if (function_name == NULL) var = (yyvsp[-2].lexema); 
					else var = concat(concat(function_name,"."), (yyvsp[-2].lexema)); //si estoy en el ambito de una funcion

				if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){ //si llegamos al final, no está
					
					Simbolo s;
					s.tipo = CONSTANTE;
					s.nombre = var;
					s.valor = 0; // por defecto
					insertaLS(tablaSimb, finalLS(tablaSimb), s);

					concatenaLC((yyval.codigo),(yyvsp[0].codigo));

					Operacion o;
	  				o.op = "sw";
					o.res = recuperaResLC((yyvsp[0].codigo));
	  				o.arg1 = concat("_", (yyvsp[-2].lexema)); //$1 o var?
	  				o.arg2 = NULL; 
	  				insertaLC((yyval.codigo),finalLC((yyval.codigo)),o);	
					liberarReg(o.res);
					
					liberaLC((yyvsp[0].codigo));
				}
				else{	//insertamos al final
						printf("Error en linea %d: Variable %s ya declarada \n", yylineno, (yyvsp[-2].lexema));
						errores_semanticos++;
				}

			}
#line 1777 "sintactico.tab.c"
    break;

  case 20:
#line 335 "sintactico.y"
                                                           {
					(yyval.codigo)=creaLC();
				if (buscaLS(tablaSimb, (yyvsp[-2].lexema)) == finalLS(tablaSimb)){ //si llegamos al final, no está
					Simbolo s;
					s.tipo = CONSTANTE;
					s.nombre = (yyvsp[-2].lexema);
					s.valor = 0; // por defecto
					insertaLS(tablaSimb, finalLS(tablaSimb), s);
					concatenaLC((yyval.codigo),(yyvsp[-4].codigo));
					concatenaLC((yyval.codigo),(yyvsp[0].codigo));
					liberaLC((yyvsp[-4].codigo));
					liberaLC((yyvsp[0].codigo));
				}
				 else{	//insertamos al final
						printf("Error en linea %d: Variable %s ya declarada \n", yylineno, (yyvsp[-2].lexema));
						errores_semanticos++;
				}
					
			}
#line 1801 "sintactico.tab.c"
    break;

  case 21:
#line 355 "sintactico.y"
                                                   {
			(yyval.codigo) = (yyvsp[-1].codigo);

			}
#line 1810 "sintactico.tab.c"
    break;

  case 22:
#line 360 "sintactico.y"
                                 {(yyval.codigo)=(yyvsp[0].codigo);}
#line 1816 "sintactico.tab.c"
    break;

  case 23:
#line 361 "sintactico.y"
                                     {(yyval.codigo)=creaLC();}
#line 1822 "sintactico.tab.c"
    break;

  case 24:
#line 363 "sintactico.y"
                        {
				(yyval.codigo)=(yyvsp[0].codigo);
			}
#line 1830 "sintactico.tab.c"
    break;

  case 25:
#line 366 "sintactico.y"
                                                   {
				(yyval.codigo) = creaLC();
				concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));
			}
#line 1842 "sintactico.tab.c"
    break;

  case 26:
#line 374 "sintactico.y"
                               {

					char* var;
					if (function_name == NULL) var = (yyvsp[-2].lexema); 
					else {
						if (buscaLS(tablaSimb, (yyvsp[-2].lexema)) == finalLS(tablaSimb)) var = concat(concat(function_name,"."), (yyvsp[-2].lexema)); //NO ES UNA VARIABLE FUNCION
						else var = (yyvsp[-2].lexema);
					}

					(yyval.codigo) = creaLC();

					if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, (yyvsp[-2].lexema));
						errores_semanticos++;
					}
					else{
						Simbolo s = recuperaLS(tablaSimb,buscaLS(tablaSimb, var)); 
						if (s.tipo == CONSTANTE){
							printf("Error en linea %d: %s es constante\n", yylineno, (yyvsp[-2].lexema));
							errores_semanticos++;
						}
						if ( s.tipo == ARGUMENTO){
							printf("Error en linea %d: %s es un argumento, y por lo tanto es constante\n", yylineno, (yyvsp[-2].lexema));
							errores_semanticos++;
						}

						concatenaLC((yyval.codigo), (yyvsp[0].codigo));

						if ( s.tipo == FUNCION){
							Operacion o;
							o.op = "move";
							o.res = "$v0";
							o.arg1 = recuperaResLC((yyvsp[0].codigo));
							o.arg2 = NULL;
							liberarReg(o.arg1);
							insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
						}
						else {
							Operacion o;
	  						o.op = "sw";
							o.res = recuperaResLC((yyvsp[0].codigo));
	  						o.arg1 = concat("_", var);
	  						o.arg2 = NULL; 
	  						insertaLC((yyval.codigo),finalLC((yyval.codigo)),o);	
							liberarReg(o.res);
							liberaLC((yyvsp[0].codigo));
						}
						
						
					}
					

				}
#line 1900 "sintactico.tab.c"
    break;

  case 27:
#line 428 "sintactico.y"
                                                           { //SIN HACER
				
				(yyval.codigo) = creaLC();
				concatenaLC((yyval.codigo),(yyvsp[-2].codigo));

				Operacion o;

				o.op = "beqz";
				o.res = recuperaResLC((yyvsp[-2].codigo));
				o.arg1 = generaEtiqSalto();//etiqueta de salto
				o.arg2 = NULL;
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);

				concatenaLC((yyval.codigo),(yyvsp[0].codigo));

				Operacion o2; //salto
				o2.op = NULL; //la etiqueta
				o2.res = concat(o.arg1, ":");
				o2.arg1= NULL;
				o2.arg2 = NULL;
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);

				liberarReg(o.res); //liberamos el registro de la sentencia
				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));
				
			}
#line 1932 "sintactico.tab.c"
    break;

  case 28:
#line 456 "sintactico.y"
                                                                            {

				(yyval.codigo)=creaLC();
				concatenaLC((yyval.codigo),(yyvsp[-4].codigo));
				Operacion o;

				o.op = "beqz";
				o.res = recuperaResLC((yyvsp[-4].codigo));
				o.arg1 = generaEtiqSalto();//etiqueta de salto
				o.arg2 = NULL;
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);

				concatenaLC((yyval.codigo),(yyvsp[-2].codigo));

				Operacion o2; //salto 1
				o2.op = NULL; //la etiqueta
				o2.res = concat(o.arg1, ":");
				o2.arg1= NULL;
				o2.arg2 = NULL;			

				Operacion o3; //salto incondicional 
				o3.op = "b"; //salta incodicionlamente al resto del codigo para no pasar por el else
				o3.res = generaEtiqSalto(); //genera la etiqueta del resto del codigo
				o3.arg1 = NULL;
				o3.arg2 = NULL;

				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));

				Operacion o4; //etiqueta de salto final
				o4.op = NULL;
				o4.res = concat(o3.res, ":");
				o4.arg1 = NULL;
				o4.arg2 = NULL;

				insertaLC((yyval.codigo),finalLC((yyval.codigo)), o4);

				liberarReg(o.res); //liberamos el registro de la sentencia
				liberaLC((yyvsp[-4].codigo));
				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));
			}
#line 1980 "sintactico.tab.c"
    break;

  case 29:
#line 500 "sintactico.y"
                                                            {

				(yyval.codigo)=creaLC();

				Operacion o3; //la pongo antes para que genere el registre y la otra le concatene los ":"
				o3.op = "b";
				o3.res = generaEtiqSalto(); //hay que quitar ":"
				o3.arg1 = NULL;
				o3.arg2 = NULL;

				Operacion o; //etiqueta de inicio;
				o.op = NULL;
				o.res = concat(o3.res, ":");
				o.arg1 = NULL;
				o.arg2 = NULL;

				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);

				concatenaLC((yyval.codigo),(yyvsp[-2].codigo));

				Operacion o2;
				o2.op = "beqz";
				o2.res = recuperaResLC((yyvsp[-2].codigo));
				o2.arg1 = generaEtiqSalto();
				o2.arg2= NULL;

				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);
				concatenaLC((yyval.codigo), (yyvsp[0].codigo));

				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
				
				Operacion o4; //etiqueta de salto 2
				o4.op = NULL;
				o4.res = concat(o2.arg1, ":");
				o4.arg1= NULL;
				o4.arg2 = NULL;

				insertaLC((yyval.codigo),finalLC((yyval.codigo)), o4);

				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));
			}
#line 2027 "sintactico.tab.c"
    break;

  case 30:
#line 543 "sintactico.y"
                                                                                 {

				(yyval.codigo)=creaLC();
				if (buscaLS(tablaSimb, (yyvsp[-6].lexema)) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, (yyvsp[-6].lexema));
						errores_semanticos++;
					}
				else{
					Simbolo s = recuperaLS(tablaSimb,buscaLS(tablaSimb, (yyvsp[-6].lexema))); 
					if (s.tipo == CONSTANTE){
						printf("Error en linea %d: %s es constante\n", yylineno, (yyvsp[-6].lexema));
						errores_semanticos++;
					}
					else{ //si todo está bien pasemos a generar las operaciones

						concatenaLC((yyval.codigo),(yyvsp[-4].codigo)); 
						
						Operacion o;
						o.op = "sw";
						o.res = recuperaResLC((yyvsp[-4].codigo));
						o.arg1 = concat("_", (yyvsp[-6].lexema));
						o.arg2 = NULL;
						liberarReg(o.res);
						insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);

						Operacion o2; 
						o2.op = "lw";
						o2.res = getRegistro();
						o2.arg1 = concat("_", (yyvsp[-6].lexema));
						o2.arg2 = NULL;
						insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);

						concatenaLC((yyval.codigo),(yyvsp[-2].codigo));

						Operacion o3;
						o3.op = "b";
						o3.res = generaEtiqSalto(); 
						o3.arg1 = NULL;
						o3.arg2 = NULL;				

						Operacion o4; //etiqueta de inicio for;
						o4.op = NULL;
						o4.res = concat(o3.res, ":");
						o4.arg1 = NULL;
						o4.arg2 = NULL;

						insertaLC((yyval.codigo), finalLC((yyval.codigo)), o4); //añadimos primera etiqueta

						Operacion o5; //para ver cuando salimos, si es mayor de la expression
						o5.op = "bgt";
						o5.res = o2.res; //el registro temporal 
						o5.arg1 = recuperaResLC((yyvsp[-2].codigo)); //recuperamos el registro de la expression de "to"
						o5.arg2 = generaEtiqSalto();

						insertaLC((yyval.codigo), finalLC((yyval.codigo)), o5);

						concatenaLC((yyval.codigo), (yyvsp[0].codigo));

						Operacion o6; //sumar 1 a la variable MIRAR
						o6.op = "addiu";
						o6.res = o2.res;
						o6.arg1 = o2.res;
						o6.arg2 = "1";
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),o6);

						Operacion o7; //sumar 1 a la variable MIRAR
						o7.op = "sw";
						o7.res = o5.res;
						o7.arg1 = concat("_", (yyvsp[-6].lexema));
						o7.arg2 = NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)), o7);
						
						insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
				
						Operacion o8; //etiqueta de salto 2
						o8.op = NULL;
						o8.res = concat(o5.arg2, ":");
						o8.arg1= NULL;
						o8.arg2 = NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)), o8);

						liberaLC((yyvsp[-4].codigo));
						liberaLC((yyvsp[-2].codigo));
						liberaLC((yyvsp[0].codigo));
					}	
				}	
			}
#line 2119 "sintactico.tab.c"
    break;

  case 31:
#line 631 "sintactico.y"
                                                     {

				(yyval.codigo)=(yyvsp[-1].codigo);
			}
#line 2128 "sintactico.tab.c"
    break;

  case 32:
#line 635 "sintactico.y"
                                                   {
				(yyval.codigo)=(yyvsp[-1].codigo);
			}
#line 2136 "sintactico.tab.c"
    break;

  case 33:
#line 638 "sintactico.y"
                                             {
				(yyval.codigo)=(yyvsp[0].codigo);
			}
#line 2144 "sintactico.tab.c"
    break;

  case 34:
#line 642 "sintactico.y"
                        {(yyval.codigo)=(yyvsp[0].codigo);}
#line 2150 "sintactico.tab.c"
    break;

  case 35:
#line 643 "sintactico.y"
                                                          {
				(yyval.codigo)=creaLC();
				concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));

			}
#line 2163 "sintactico.tab.c"
    break;

  case 36:
#line 652 "sintactico.y"
                        {

				(yyval.codigo)=creaLC();
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));

				if (function_name!=NULL){

					Operacion op;
					op.op = "move";
					op.res = "$s0";
					op.arg1 = "$a0"; //lo que haya previamente
					op.arg2 = NULL;
					insertaLC((yyval.codigo), finalLC((yyval.codigo)),op);

					Operacion op2;
					op2.op = "move";
					op2.res = "$s1";
					op2.arg1 = "$v0"; //lo que haya previamente
					op2.arg2 = NULL;
					insertaLC((yyval.codigo), finalLC((yyval.codigo)),op2);					
				}

				Operacion o1;
				o1.op = "move"; //move o li?
				o1.res = "$a0"; 
				o1.arg1 = recuperaResLC((yyvsp[0].codigo));
				o1.arg2 = NULL;
				Operacion o2;
				o2.op = "li";
				o2.res = "$v0"; 
				o2.arg1 = "1";
				o2.arg2 = NULL;
				Operacion o3;
				o3.op = "syscall";
				o3.res = NULL;
				o3.arg1 = NULL;
				o3.arg2 = NULL;
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o1);
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
				liberaLC((yyvsp[0].codigo));
				liberarReg(o1.arg1); //ya no lo queremos

				if (function_name!=NULL){

					Operacion op3;
					op3.op = "move";
					op3.res = "$a0";
					op3.arg1 = "$s0"; //lo que haya previamente
					op3.arg2 = NULL;
					insertaLC((yyval.codigo), finalLC((yyval.codigo)),op3);

					Operacion op4;
					op4.op = "move";
					op4.res = "$v0";
					op4.arg1 = "$s1"; //lo que haya previamente
					op4.arg2 = NULL;
					insertaLC((yyval.codigo), finalLC((yyval.codigo)),op4);					
				}
		}
#line 2228 "sintactico.tab.c"
    break;

  case 37:
#line 713 "sintactico.y"
                                 {

				(yyval.codigo)= creaLC();
				contador_string++;

				Simbolo s;
				s.tipo = CADENA;
				s.nombre = (yyvsp[0].lexema);
				s.valor = contador_string; // para saber cuál es
				insertaLS(tablaSimb, finalLS(tablaSimb), s);
				
				Operacion o1;
				o1.op = "la"; 
				o1.res = "$a0"; 
				char res[8];
				sprintf(res, "$Str%d", contador_string);
				o1.arg1 = strdup(&res[0]); //reserva memoria
				o1.arg2 = NULL;
				
				Operacion o2;
				o2.op = "li"; 
				o2.res = "$v0"; 
				o2.arg1 = "4"; 
				o2.arg2 = NULL;

				Operacion o3;
				o3.op = "syscall";
				o3.res = NULL;
				o3.arg1 = NULL;
				o3.arg2 = NULL;

				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o1);
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
				
			}
#line 2269 "sintactico.tab.c"
    break;

  case 38:
#line 750 "sintactico.y"
               {
				(yyval.codigo) = creaLC();
				if (buscaLS(tablaSimb, (yyvsp[0].lexema)) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				else if (recuperaLS(tablaSimb, buscaLS(tablaSimb,(yyvsp[0].lexema))).tipo == CONSTANTE) {
						printf("Error en linea %d: %s es constante\n", yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				else{ //si todo está bien creamos
						
					Operacion o1;
					o1.op = "li";
					o1.res = "$v0";
					o1.arg1 = "5"; 
					o1.arg2 = NULL;
					Operacion o2;
					o2.op = "syscall";
					o2.res = NULL;
					o2.arg1 = NULL;
					o2.arg2 = NULL;
					Operacion o3;
					o3.op = "sw";
					o3.res = "$v0";
					o3.arg1 = concat("_", (yyvsp[0].lexema));
					o3.arg2 = NULL;
					insertaLC((yyval.codigo), finalLC((yyval.codigo)), o1);
					insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);
					insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
				}
			}
#line 2306 "sintactico.tab.c"
    break;

  case 39:
#line 783 "sintactico.y"
                                           {	

				(yyval.codigo) = creaLC();
				if (buscaLS(tablaSimb, (yyvsp[0].lexema)) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				else if (recuperaLS(tablaSimb, buscaLS(tablaSimb,(yyvsp[0].lexema))).tipo == CONSTANTE) {
						printf("Error en linea %d: %s es constante\n", yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				else{				
					concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
					Operacion o1;
					o1.op = "li";
					o1.res = "$v0"; //no hay que comprobar registros
					o1.arg1 = "5"; //AQUÍ HAY QUE DISTINGUIR ENTRE ENTEROS Y STRINGS
					o1.arg2 = NULL;
					Operacion o2;
					o2.op = "syscall";
					o2.res = NULL;
					o2.arg1 = NULL;
					o2.arg2 = NULL;
					Operacion o3;
					o3.op = "sw";
					o3.res = "v0";
					o3.arg1 = concat("_", (yyvsp[0].lexema));
					o3.arg2 = NULL;
					insertaLC((yyval.codigo), finalLC((yyval.codigo)), o1);
					insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);
					insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
					liberaLC((yyvsp[-2].codigo));
				}
			}
#line 2345 "sintactico.tab.c"
    break;

  case 40:
#line 818 "sintactico.y"
                                       {

				(yyval.codigo)=creaLC();
				concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
				concatenaLC((yyval.codigo), (yyvsp[0].codigo));
				Operacion o;
				o.op = "add";
				o.res = getRegistro();
				o.arg1 = recuperaResLC((yyvsp[-2].codigo));
				o.arg2 = recuperaResLC((yyvsp[0].codigo));
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
				guardaResLC((yyval.codigo), o.res);
				liberarReg(o.arg1);
				liberarReg(o.arg2);
				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));
			}
#line 2367 "sintactico.tab.c"
    break;

  case 41:
#line 836 "sintactico.y"
                                                    {

				(yyval.codigo)=creaLC();
				concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
				concatenaLC((yyval.codigo), (yyvsp[0].codigo));
				Operacion o;
				o.op = "sub";
				o.res = getRegistro();
				o.arg1 = recuperaResLC((yyvsp[-2].codigo));
				o.arg2 = recuperaResLC((yyvsp[0].codigo));
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
				guardaResLC((yyval.codigo), o.res);
				liberarReg(o.arg1);
				liberarReg(o.arg2);
				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));
			}
#line 2389 "sintactico.tab.c"
    break;

  case 42:
#line 854 "sintactico.y"
                                                    {
				(yyval.codigo) = creaLC();
				concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
				concatenaLC((yyval.codigo), (yyvsp[0].codigo));
				Operacion o;
				o.op = "mul";
				o.res = getRegistro();
				o.arg1 = recuperaResLC((yyvsp[-2].codigo));
				o.arg2 = recuperaResLC((yyvsp[0].codigo));
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
				guardaResLC((yyval.codigo), o.res);
				liberarReg(o.arg1);
				liberarReg(o.arg2);
				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));
			}
#line 2410 "sintactico.tab.c"
    break;

  case 43:
#line 871 "sintactico.y"
                                                    {
				(yyval.codigo) = creaLC();
				concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
				concatenaLC((yyval.codigo), (yyvsp[0].codigo));
				Operacion o;
				o.op = "div";
				o.res = getRegistro();
				o.arg1 = recuperaResLC((yyvsp[-2].codigo));
				o.arg2 = recuperaResLC((yyvsp[0].codigo));
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
				guardaResLC((yyval.codigo), o.res);
				liberarReg(o.arg1);
				liberarReg(o.arg2);
				liberaLC((yyvsp[-2].codigo));
				liberaLC((yyvsp[0].codigo));
			}
#line 2431 "sintactico.tab.c"
    break;

  case 44:
#line 888 "sintactico.y"
                                                      {
				(yyval.codigo) = creaLC();
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				Operacion o;
				o.op = "neg";
				o.res = getRegistro();
				o.arg1 = recuperaResLC((yyvsp[0].codigo));
				o.arg2 = NULL;
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
				guardaResLC((yyval.codigo), o.res);
				liberarReg(o.arg1);
				liberaLC((yyvsp[0].codigo)); 
			}
#line 2449 "sintactico.tab.c"
    break;

  case 45:
#line 902 "sintactico.y"
                                             { //PUTOS PARENTESIS

				(yyval.codigo)=(yyvsp[-1].codigo);
			}
#line 2458 "sintactico.tab.c"
    break;

  case 46:
#line 906 "sintactico.y"
                                {

				(yyval.codigo) = creaLC();
				char* var;
				if (function_name == NULL) var = (yyvsp[0].lexema); 
					else {
						if (buscaLS(tablaSimb, (yyvsp[0].lexema)) == finalLS(tablaSimb)) var = concat(concat(function_name,"."), (yyvsp[0].lexema)); //NO ES UNA VARIABLE FUNCION
						else var = (yyvsp[0].lexema);
					}				
	
				if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, (yyvsp[0].lexema));
						errores_semanticos++;
					}
				else {
						Simbolo s = recuperaLS(tablaSimb, buscaLS(tablaSimb, var)); 
					if (s.tipo != ARGUMENTO){
						Operacion o;
						o.op = "lw";
						o.res = getRegistro();
						o.arg1 = concat("_", var);
						o.arg2 = NULL;
						insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
						guardaResLC((yyval.codigo), o.res);
					}
					else {
						char reg[4];
						sprintf(reg, "$a%d", s.valor);
						guardaResLC((yyval.codigo), strdup(reg)); //se guarda el registro de parametro
					}

				}
			}
#line 2496 "sintactico.tab.c"
    break;

  case 47:
#line 940 "sintactico.y"
                                 {
				(yyval.codigo)=creaLC();
				Operacion o;
  				o.op = "li";
				o.res = getRegistro();
  				o.arg1 = (yyvsp[0].lexema);
  				o.arg2 = NULL;
  				insertaLC((yyval.codigo),finalLC((yyval.codigo)),o);
				guardaResLC((yyval.codigo),o.res);
			}
#line 2511 "sintactico.tab.c"
    break;

  case 48:
#line 951 "sintactico.y"
                                                        { //comprobar que ID existe y es de tipo FUNCION

				(yyval.codigo) = creaLC();
				Simbolo s;
				
				if (buscaLS(tablaSimb, (yyvsp[-3].lexema)) == finalLS(tablaSimb)){ 
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, (yyvsp[-3].lexema));
						errores_semanticos++;
				}
				else {
					s = recuperaLS(tablaSimb, buscaLS(tablaSimb, (yyvsp[-3].lexema)));
					if (s.tipo != FUNCION){
						printf("Error en linea %d: La variable %s no es una funcion\n" , yylineno, (yyvsp[-3].lexema));
						errores_semanticos++;
					}
					else if (s.valor != n_args){
						printf("Error en linea %d: Numero de argumentos incorrectos para %s, se esperaban %d y se tienen %d\n" , yylineno, (yyvsp[-3].lexema), s.valor, n_args);
						errores_semanticos++;
					}
				}
				
				concatenaLC((yyval.codigo),(yyvsp[-1].codigo));

				Operacion o;
				o.op = "jal";
				o.res = concat("_", (yyvsp[-3].lexema));
				o.arg1 = o.arg2 = NULL;
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);

				Operacion o2;
				o2.op = "move";
				o2.res = getRegistro();
				o2.arg1 = "$v0";
				o2.arg2=NULL;
				guardaResLC((yyval.codigo), o2.res); //GUARDAR
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);

				n_args = 0; //se vuelven a poner a 0 para posteriores usos
			}
#line 2555 "sintactico.tab.c"
    break;

  case 50:
#line 992 "sintactico.y"
                                     {(yyval.codigo) = creaLC();}
#line 2561 "sintactico.tab.c"
    break;

  case 51:
#line 994 "sintactico.y"
                         {
	
				(yyval.codigo)=creaLC();
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				Operacion o;
				o.op = "move";
				char arr[4];
				sprintf(arr, "$a%d", n_args);
				o.res = strdup(arr); 
				o.arg1 = recuperaResLC((yyvsp[0].codigo));
				o.arg2 = NULL;
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
				guardaResLC((yyval.codigo), o.res);
				liberarReg(o.arg1);
				
				n_args++;
			}
#line 2583 "sintactico.tab.c"
    break;

  case 52:
#line 1011 "sintactico.y"
                                                     {
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				
				Operacion o;
				o.op = "move";
				char arr[4];
				sprintf(arr, "$a%d", n_args);
				o.res = strdup(arr); 
				o.arg1 = recuperaResLC((yyvsp[0].codigo));
				o.arg2 = NULL;
				guardaResLC((yyval.codigo), o.res);
				liberarReg(o.arg1);
				insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
				liberaLC((yyvsp[0].codigo));
				n_args++;
			}
#line 2604 "sintactico.tab.c"
    break;


#line 2608 "sintactico.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1029 "sintactico.y"


void yyerror (char const *s)
     {
	   errores_sintacticos++;
       fprintf (stderr, "%s en linea %d\n", s, yylineno);
     }


void liberarReg(char *r){ //r = registro
	if (r==NULL)return;	//POR SI LA VARIABLE NO ESTÁ DECLARADA. Si no lo está, recuperará un Res NULL, y por lo tanto no se podrá liberar
	short pos = atoi(r + 2); // $tn, donde n es la segunda posicion;
	registros[pos] = 0;
}

char* getRegistro(){
	for(int i = 0; i < 10; i++){
		if (registros[i]==0){
			registros[i]=1;
			char *res = malloc(4); //mirar si reserva bien
			sprintf(res, "$t%d", i);
			return res;
		}
	}
	return NULL;
}

char *generaEtiqSalto() {
	char aux[10];
	sprintf(aux, "$l%d", contadorSalto++);
	return strdup(aux);	
}

void generarCodigoFuncion(ListaC lista_statements){

	char temporales[11] = {0};	

	PosicionListaC p = inicioLC(lista_statements);
	while (p != finalLC(lista_statements)){
		Operacion o = recuperaLC(lista_statements, p);	

		if(o.res!=NULL && o.res[0]=='$'){
			if (o.res[1]=='t'){
				temporales[o.res[2]-'0']=1;
			}
		}
		/*if(o.arg1!=NULL && o.arg1[0]=='$'){
			if (o.arg1[1]=='t'){
			temporales[o.arg1[2]]=1;
			}
		}
		if(o.arg2!=NULL && o.arg2[0]=='$'){
			if (o.arg2[1]=='t'){
				temporales[o.arg2[2]]=1;
			}
		}*/
		
		p = siguienteLC(lista_statements, p);
	}

	int tempors=0;
	for(int i = 0; i < 11; i++ ) if(temporales[i]==1)tempors++;	

	Operacion o;
	o.op = "move";
	o.res = "$v0";
	o.arg1 = "$zero";
	o.arg2 = NULL;
	insertaLC(lista_statements, inicioLC(lista_statements), o);

	Operacion ra;
	ra.op = "sw";
	ra.res="$ra";
	ra.arg1 = "0 ($sp)";
	ra.arg2 = NULL;
	insertaLC(lista_statements, inicioLC(lista_statements), ra);

	int cont = 1;
	for (int i = 0; i < 11; i++){
		if (temporales[i]==1){
			Operacion o;
			o.op = "sw";
			char ja[4];
			sprintf(ja, "$t%d",i);
			o.res = strdup(ja);
			char ja2[10];
			sprintf(ja2, "%d ($sp)", cont*4);
			o.arg1 = strdup(ja2);
			o.arg2 = NULL;
			insertaLC(lista_statements, inicioLC(lista_statements), o);
			cont++;
		}

	}
	cont = 1;

	Operacion o2;
	o2.op = "addiu";
	o2.res = "$sp";
	o2.arg1 = "$sp";
	char pr[4];
	sprintf(pr, "%d", -4*(tempors+1));
	o2.arg2 = strdup(pr); 
	insertaLC(lista_statements, inicioLC(lista_statements), o2);

	Operacion ral;
	ral.op = "lw";
	ral.res="$ra";
	ral.arg1 = "0 ($sp)";
	ral.arg2 = NULL;
	insertaLC(lista_statements, finalLC(lista_statements), ral);

	for (int i = 0; i < 11; i++){
		if (temporales[i]==1){
			Operacion o;
			o.op = "lw";
			char ja[4];
			sprintf(ja, "$t%d",i);
			o.res = strdup(ja);
			char ja2[10];
			sprintf(ja2, "%d ($sp)", cont*4);
			o.arg1 = strdup(ja2);
			o.arg2 = NULL;
			insertaLC(lista_statements, finalLC(lista_statements), o);
			cont++;
		}

	}

	Operacion o3;
	o3.op = "addiu";
	o3.res = "$sp";
	o3.arg1 = "$sp";
	sprintf(pr, "%d", 4*(tempors+1));
	o3.arg2 = strdup(pr); 
	insertaLC(lista_statements, finalLC(lista_statements), o3);	

	Operacion jra;
	jra.op = "jr";
	jra.res = "$ra";
	jra.arg1=NULL;
	jra.arg2= NULL;
	insertaLC(lista_statements, finalLC(lista_statements), jra);
}
