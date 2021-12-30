# postfix-calculator

Postfix notation is an unambiguous way of writing an arithmetic expression without parentheses. It is defined so that 
if "(exp1 ) ⊗ (exp2 )" is a normal fully parenthesized expression whose operation is "⊗", then the postfix version of this 
is "pexp1 pexp2 ⊗", where pexp1 is the postfix version of exp1 and pexp2 is the postfix version of exp2 . The postfix version 
of a single number or variable is just that number or variable. So, for example, the postfix version of "((5 + 2) * (8 - 3))/4" is "5 2 + 8 3 - * 4 /".

A normal expression may have more than one acceptable fully parenthesized version though. For example 2 + 3 + 4 + 5 can be fully 
parenthesized as ((2 + 3) + (4 + 5)) or (((2 + 3) + 4 ) + 5). It follows that a normal expression may have more than one equivalent 
postfix notation.


Postfix expressions can be evaluated non-recursively using stack ADT. This program evaluates a given normal (not necessarily fully parenthesized) 
expression by transforming it into an equivalent postfix notation, and evaluating that using stacks.

try it out:

g++ -c postfixUtility.cpp
g++ -o main.o main.cpp postfixUtility.o
./main.o "(4+3* 12)/ ( 12+ 3/ 2+ 46 /4)"
1.6667
