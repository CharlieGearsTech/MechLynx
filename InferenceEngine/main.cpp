#include <QCoreApplication>
#include <QDebug>

#include "proptreebuilder.h"
#include "propnode.h"
#include "infixsyntaxanalizer.h"
#include "proplexanalyzer.h"
#include "workspace.h"
#include "inferencekernel.h"

#include <iostream>
#include <QTextStream>

int main(int argc,char* argv[]){
    QTextStream out(stdout);
    QTextStream in(stdin);

    QCoreApplication a(argc,argv);
    PROPTreeBuilder TB;
    PROPLexAnalyzer LA;
    InfixSyntaxAnalyzer IASA(&LA,&TB);
    InferenceKernel IK(&TB);

    if(LA.pushFile("/home/quique/Documents/Qt17/InferenceEngine/Resources/KnowledgeBase")){
        bool cpRes=IASA.Compile();
        if(cpRes){
            out<<"Success in compilation"<<endl;
            //IK.askForValue(0);
            //IK.setValue2Atom(1,1);
            //IK.propagate(9,true);
            //To make infer work
            IK.setValue2Atom(8,false);
            //We changed some stuff here
            IK.eval(9,Workspace::RuleType::ModusPonens);
            //There is a bug here.
            IK.infer(9);
            if(IK.isCube(7))
                out<<"This rule is a cube: 9"<<endl;
            else
                out<<"This rule is not a cube: 9 "<<endl;
            if(IK.isClousure(7))
                out<<"This rule is a closure: 9"<<endl;
            else
                out<<"This rule is not a closure: 9 "<<endl;

            if(IK.isCube(18))
                out<<"This rule is a cube: 12"<<endl;
            else
                out<<"This rule is not a cube: 12"<<endl;
            if(IK.isClousure(18))
                out<<"This rule is a closure: 12"<<endl;
            else
                out<<"This rule is not a closure: 12"<<endl;
        }
    }
    return 0;
}
