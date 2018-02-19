#ifndef INFIXSYNTAXANALIZER_H
#define INFIXSYNTAXANALIZER_H
#include "propsyntaxanalyzer.h"

class InfixSyntaxAnalyzer : public PROPSyntaxAnalyzer
{
public:
    InfixSyntaxAnalyzer(PROPLexAnalyzer* pLA,PROPTreeBuilder* pTB):
        PROPSyntaxAnalyzer(pLA,pTB){}
    virtual bool Compile()const;
};

#endif // INFIXSYNTAXANALIZER_H
