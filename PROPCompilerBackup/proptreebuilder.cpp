#include "proptreebuilder.h"

PROPTreeBuilder::PROPTreeBuilder()
{
    m_lstTree.clear();
    m_lstSymbol.clear();
}

int PROPTreeBuilder::atom(QString strId){
    QMap<QString,int>::const_iterator it=m_mapSymbol2Entry.find(strId);

    if(it != m_mapSymbol2Entry.end())
        return it.value();

    else{
        m_mapSymbol2Entry.insert(strId,m_lstTree.size());
        m_mapEntry2Symbol.insert(m_lstTree.size(),strId);
        m_lstTree.append(PROPNode(PROPNode::ATOM,m_lstSymbol.size(),-1));
        m_lstSymbol.push_back(strId);
        return m_lstTree.size()-1;
    }
}

int PROPTreeBuilder::valueAtomBySymbol(QString symbol){
    if(m_mapSymbol2Entry.contains(symbol))
        return m_mapSymbol2Entry.value(symbol);
    return -1;
}

int PROPTreeBuilder::Not(int first){
    m_lstTree.append(PROPNode(PROPNode::NOT,first,-1));
    return m_lstTree.size()-1;
}

int PROPTreeBuilder::And(int first, int second){
    m_lstTree.append(PROPNode(PROPNode::AND,first,second));
    return m_lstTree.size()-1;
}

int PROPTreeBuilder::If(int first, int second){
    m_lstTree.append(PROPNode(PROPNode::IF,first,second));
    return m_lstTree.size()-1;
}

int PROPTreeBuilder::Iff(int first, int second){
    m_lstTree.append(PROPNode(PROPNode::IFF,first,second));
    return m_lstTree.size()-1;
}

int PROPTreeBuilder::Or(int first, int second){
    m_lstTree.append(PROPNode(PROPNode::OR,first,second));
    return m_lstTree.size()-1;
}

int PROPTreeBuilder::True(){
    m_lstTree.append(PROPNode(PROPNode::TRUE,-1,-1));
    return m_lstTree.size()-1;
}
