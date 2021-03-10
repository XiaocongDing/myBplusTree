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
    bool getKeyIndex(Tkey key);
    

    bool mergeWithLeftBrotherLeafNode(Node<Tkey, Tdata> *pLeftBrotherNode);
    bool mergeWithRightBrotherLeafNode(Node<Tkey, Tdata> *pRightBrotherNode);
    
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