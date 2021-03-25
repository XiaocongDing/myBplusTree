#ifndef BPLUSTREE_BPLUSTREE_H
#define BPLUSTREE_BPLUSTREE_H
#include "node.h"
#include <vector>
#include <unistd.h>
#include <mutex>

template<typename Tkey, typename Tdata>
Class BPlusTree{
    protected:
    int degree;
    Node<Tkey, Tdata> *pTreeRoot;
}
#endif