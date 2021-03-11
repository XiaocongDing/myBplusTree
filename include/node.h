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
    Node<Tkey, TNode> *getLeftNode;
    Node<Tkey, TNode> *getRightNode;
    bool setKey(Tkey key);
    bool setData(TData data);
    bool setLeftNode(Node<Tkey, TData> *pNode);
    bool setRightNode(Node<Tkey, Tdata> *pNode);
    void print();
};



#endif