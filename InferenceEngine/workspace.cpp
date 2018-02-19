#include "workspace.h"
#include "proptreebuilder.h"

Workspace::Workspace(const PROPTreeBuilder * const pTB):m_pTB(pTB){

}

void Workspace::InsertAntecedentOrConsequent(int rule, int entry, bool isConsequent){
    if(!isConsequent)
        m_mmAntecedents.insert(rule,entry);
    else
        m_mmConsequents.insert(rule,entry);
}

void Workspace::reset(){
    resetRules();
    resetAntecedentsAndConsequents();
    resetConclusions();
    resetDeniedAtoms();
    resetRules();
    m_mRuleTypes.clear();
    m_mAntecedentsValue.clear();
    m_mConsequentsValue.clear();
    m_vAskedAtoms.clear();
    m_vInferredRules.clear();
    m_vIrrelevantRules.clear();
    m_mConclusionValues.clear();
    m_mRelevantAtoms.clear();
}

void Workspace::resetRules(){
    m_vRules.clear();

    for(unsigned int i=0;i<m_pTB->getTree().size();++i)
        if(m_pTB->getTree().at(i).getType()==PROPNode::NodeType::IF)
            m_vRules.append(i);
}

void Workspace::resetAntecedentsAndConsequents(){
    m_mmAntecedents.clear();
    m_mConsequentsValue.clear();

    for(int i=0, lentry=0,rentry=0;i<m_vRules.size();++i){
        lentry=m_pTB->getTree().at(m_vRules.at(i)).first();
        pickAtom(lentry,m_vRules.at(i),0);

        rentry=m_pTB->getTree().at(m_vRules.at(i)).second();
        pickAtom(rentry,m_vRules.at(i),1);
    }
}

void Workspace::pickAtom(int entry, int rule, bool isConsequent){
    //Reach a atom type
    //Check operationst
    if(m_pTB->getTree().at(entry).getType() == PROPNode::NodeType::ATOM){
        InsertAntecedentOrConsequent(rule,entry,isConsequent);
        return;
    }

    //Operation type and verify its first and second
    //Check left part of the operation
    int first=m_pTB->getTree().at(entry).first();
    //Operation Type
    if(m_pTB->getTree().at(first).getType() != PROPNode::NodeType::ATOM){
        if(!isConsequent)
            pickAtom(first,rule,0);
        else
            pickAtom(first,rule,1);
    }
    //Atom type
    else
        InsertAntecedentOrConsequent(rule,first,isConsequent);

    //Right part
    int second=m_pTB->getTree().at(entry).second();
    if(second != 1){
        if(m_pTB->getTree().at(second).getType() != PROPNode::NodeType::ATOM){
            if(!isConsequent)
                pickAtom(second,rule,0);
            else
                pickAtom(second,rule,1);
        }
        else
            InsertAntecedentOrConsequent(rule,second,isConsequent);
    }
}

void Workspace::resetConclusions(){
    m_vConclusions.clear();

    QList<int> consequentsAtoms=m_mmConsequents.values();
    QList<int> antecedentsAtoms=m_mmAntecedents.values();

    for(unsigned int i=0U;i<consequentsAtoms.size();++i)
        if(!antecedentsAtoms.contains(consequentsAtoms.at(i)))
            if(!m_vConclusions.contains(consequentsAtoms.at(i)))
                m_vConclusions.append(consequentsAtoms.at(i));
}

void Workspace::resetDeniedAtoms(){
    for(unsigned int i=0U; i<m_pTB->getTree().size();++i)
        if(m_pTB->getTree().at(i).getType() == PROPNode::NodeType::NOT)
            m_vDeniedAtoms.append(m_pTB->getTree().at(i).first());
}
