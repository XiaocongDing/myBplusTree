#ifndef BPLUSTREE_NODE_H
#define BPLUSTREE_NODE_H

#include<iostream>
#include<cstdio>


template<typename Tkey, typename Tdata>
class Node {
protected:
    bool isLeafNode;
    int maxKeyNum;
    int currentKeyNum;
    int degree;
    Tkey *pKey;
    Tdata *pData;
    Node<Tkey, Tdata> **pChildren;
    Node<Tkey, Tdata> *pParent;
    Node<Tkey, Tdata> *pNextLeafNode;
    Node<Tkey, Tdata> *pPreLeafNode;

public:
    Node(bool isLeaf, int degree);
    Node(bool isLeaf, int degree, Tkey *pKeys, Tdata *pDatas, Node<Tkey, Tdata> **pNodes, int num);
    ~Node();
    // get and set functions
    void print();
    bool getIsLeaf();
    int getMaxKeyNum();
    int getCurrentKeyNum();
    int getDegree();

    Tkey *getPKey();
    Tdata *getPData();
    Node<Tkey, Tdata> **getPChildren();
    Node<Tkey, Tdata> *getPParent();
    Node<Tkey, Tdata> *getPNextLeafNode();
    Node<Tkey, Tdata> *getPPreLeafNode();
    bool setCurrentKeyNum(int currentKeyNum);
    bool setPParent(Node<Tkey,Tdata> *pParent);
    bool setPChild(Node<Tkey, Tdata> *pChild, int index);
    bool setPPre(Node<Tkey, Tdata> *pPre);
    bool setPNext(Node<Tkey, Tdata> *pNext); 

    // main functions:
    int getKeyIndex(Tkey key);
    Node<Tkey, Tdata> *getChildTreeByKey(Tkey key);
    int getPChildrenIndexByKey(Tkey key);
    int getPChildrenIndexInParent();
    Node<Tkey, Tdata> *getLeftBrotherNode();
    Node<Tkey, Tdata> *getRightBrotherNode();

    bool updateKeyByIndex(int index, Tkey key);
    bool updateThePParentInChildrenNode(Node<Tkey, Tdata> *selfNode);
    bool insertInLeafNode(Tkey key, Tdata data);
    bool insertInIndexNode(Tkey key, Node<Tkey, Tdata> *pNewChildIndex, Node<Tkey, Tdata> *pNewChildIndex2);
    bool ifNeedToSplitNode();

    KeyUnit<Tkey, Tdata> *splitLeafNode();
    KeyUnit<Tkey, Tdata> *splitIndexNode();

    bool deleteInLeafNodeByKey(Tkey key); //delete the key value in leaf node
    bool deleteInLeafNodeByIndex(int keyIndex);

    bool deleteInIndexNodeByKey(Tkey key, Node<Tkey, Tdata> *pRetainenNode); //delete the key value in key node
    bool deleteInIndexNodeByKeyIndex(int keyIndex, Node<Tkey, Tdata> *pRetainenNode);

    bool ifNeedToMergeOrBorrow();
    bool ifCanLendKeyToOtherLeafNode(); 
    bool ifCanLendKeyToOthreIndexNode(); // if the node can be borrowed to other index node

    KeyUnit<Tkey, Tdata> *lendTheMinKeyInLeafNode(); // leaf node lend the min key value;
    KeyUnit<Tkey, Tdata> *lendTheMaxKeyInLeafNode();  // leaf lend max
    KeyUnit<Tkey, Tdata> *lendTheMinKeyInIndexNode(); // index lend min
    KeyUnit<Tkey, Tdata> *lendTheMaxKeyInIndexNode(); // index lend max

    bool ifCanMergeWithOtherLeafNode();

    bool mergeWithLeftBrotherIndexNodeAndParentKey(Node<Tkey, Tdata> *pLeftBrotherNode, Tkey parentValue);
    bool mergeWithRightBrotherIndexNodeAndParentKey(Node<Tkey ,Tdata> *pRightBrotherNode, Tkey parentValue);
    bool mergeWithLeftBrotherLeafNode(Node<Tkey, Tdata> *pLeftBrotherNode); // merge with left leaf node
    bool mergeWithRightBrotherLeafNode(Node<Tkey, Tdata> *pRightBrotherNode); // merge with right leaf node 
    
};

template<typename Tkey, typename Tdata>
class KeyUnit {
protected:
    Tkey key;
    Tdata data;
    Node<Tkey, Tdata> *pLeftNode;
    Node<Tkey, Tdata> *pRightNode;

public:
    Tkey getKey();
    Tdata getData();
    Node<Tkey, Tdata> *getLeftNode;
    Node<Tkey, Tdata> *getRightNode;
    bool setKey(Tkey key);
    bool setData(Tdata data);
    bool setLeftNode(Node<Tkey, Tdata> *pNode);
    bool setRightNode(Node<Tkey, Tdata> *pNode);
    void print();
};

template<typename Tkey, typename Tdata>
Tkey KeyUnit<Tkey, Tdata>::getKey() {
    return key;
}

template<typename Tkey, typename Tdata>
Tdata KeyUnit<Tkey, Tdata>::getData() {
    return data;
}

template<typename Tkey, typename Tdata>
Node<Tkey, Tdata> *KeyUnit<Tkey, Tdata>::getLeftNode() {
    return pLeftNode;
}

template<typename Tkey, typename Tdata>
Node<Tkey, Tdata> *KeyUnit<Tkey, Tdata>::getRightNode() {
    return pRightNode;
}

template<typename Tkey, typename Tdata>
bool KeyUnit<Tkey, Tdata>::setKey(Tkey key) {
    this->key = key;
    return true;
}

template<typename Tkey, typename Tdata>
bool KeyUnit<Tkey, Tdata>::setData(Tdata data) {
    this->data = data;
    return true;
}

template<typename Tkey, typename Tdata>
bool KeyUnit<Tkey, Tdata>::setLeftNode(Node<Tkey, Tdata> *pNode) {
    pLeftNode = pNode;
    return true;
}

template<typename Tkey, typename Tdata>
bool KeyUnit<Tkey, Tdata>::setRightNode(Node<Tkey, Tdata> *pNode) {
    pRightNode = pNode;
    return true;
}

template<typename Tkey, typename Tdata>
void KeyUnit<Tkey, Tdata>::print() {
    std::cout << "key: " << key << std::endl; 
    std::cout << "data: " << data << std::endl;
    if (pLeftNode != NULL)
        pLeftNode->print();
    if (pRightNode != NULL)
        pRightNode->print();
}

// 构造&析构
template<typename Tkey, typename Tdata>
Node<Tkey, Tdata>::Node(bool isLeaf, int degree) {
    this->isLeafNode = isLeaf;
    maxKeyNum = degree - 1;
    this->degree = degree;
    currentKeyNum = 0;

    pKey = new Tkey[degree];
    pParent = nullptr;
    pNextLeafNode = nullptr;
    pNextRightNode = nullptr;
    for(int i = 0; i < degree; ++i) pKey[i] = -1;
    if(this->isLeafNode == true) pData = new Tdata[degree];
    else {
        pChildren = new Node<Tkey, Tdata> *[degree + 1];
        for(int i = 0; i < degree + 1; ++i){
            pChildren[i] = nullptr;
        }
    }
}

template<typename Tkey, typename Tdata>
Node<Tkey, Tdata>::Node(bool isLeaf, int degree, Tkey *pKeys, Tdata *pDatas, Node<Tkey, Tdata> **pNodes, int num) {
    this->isLeafNode = isLeaf;
    maxKeyNum = degree - 1;
    this->degree = degree;
    currentKeyNum = num;
    pKey = new Tkey[degree];
    pParent = nullptr;
    pNextLeafNode = nullptr;
    pPreLeafNode = nullptr;

    for (int i = 0; i < num; ++i) pKey[i] = pKeys[i];
    for (int i = num; i < degree; i++) pKey = -1;
    if (this->isLeafNode == true){
        pData = new Tdata[degree];
        for(int i = 0; i < num; i++){
            pData[i] = pDatas[i];
        }
    } else {
        pChildren = new Node<Tkey, Tdata> *[degree + 1];
        for( int i = 0; i < num + 1; i++) pChildren[i] = pNodes[i];
    }
}

template<typename Tkey, typename Tdata>
Node<Tkey, Tdata>::~Node(){
    delete[] pKey;
    if (isLeafNode == true) delete[] pData;
    else delete[] pChildren;
}

//

///// Information get
template<typename Tkey, typename Tdata>
int Node<Tkey, Tdata>::getCurrentKeyNum() {
    return currentKeyNum;
}

template<typename Tkey, typename Tdata>
int Node<Tkey, Tdata>::getDegree(){
    return degree;
}

template<typename Tkey, typename Tdata>
bool Node<Tkey, Tdata>::getIsLeaf() {
    return isLeafNode;
}

template<typename Tkey, typename Tdata>
Tkey *Node<Tkey, Tdata>::getPKey() {
    return pKey;
}

template<typename Tkey, typename Tdata>
Tdata *Node<Tkey, Tdata>::getPData() {
    if (isLeafNode == false) {
//        错误处理
        std::cout << "isIndexNode getPData()" << std::endl;
    }
    return pData;
}

template<typename Tkey, typename Tdata>
int Node<Tkey, Tdata>::getMaxKeyNum() {
    return maxKeyNum;
}

template<typename Tkey, typename Tdata>
Node<Tkey, Tdata> **Node<Tkey, Tdata>::getPChildren() {
    if (isLeafNode == true) {
        //错误处理
        std::cout << "isLeafNode getPChildren()" << std::endl;
    }
    return pChildren;
}

template<typename Tkey, typename Tdata>
Node<Tkey, Tdata> *Node<Tkey, Tdata>::getPNextLeafNode() {
    return pNextLeafNode;
}

template<typename Tkey, typename Tdata>
Node<Tkey, Tdata> *Node<Tkey, Tdata>::getPPreLeafNode() {
    return pPreLeafNode;
}

template<typename Tkey, typename Tdata>
bool Node<Tkey, Tdata>::setCurrentKeyNum(int currentKeyNum) {
    this->currentKeyNum=currentKeyNum;
    return true;
}

template<typename Tkey, typename Tdata>
Node<Tkey, Tdata> *Node<Tkey, Tdata>::getPParent() {
    return pParent;
}

template<typename Tkey, typename Tdata>
bool Node<Tkey, Tdata>::setPParent(Node<Tkey, Tdata> *pParent) {
    this->pParent = pParent;
    return true;
}
//
#endif