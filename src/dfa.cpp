#include "../include/dfa.h"
#include "../include/global.h"

//LoopConverter
bool LoopConverter::test(pANTLR3_COMMON_TOKEN tok) {
    switch (tok->type) {
        case FOR:
        case WHILE:
            return true;
    }
    return false;
}

shared_ptr<DFANode> LoopConverter::convert(pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    switch (tok->type) {
        case FOR: {
            //shared_ptr<DFANode> for_tok = make_shared<DFANode>(tree);
            shared_ptr<DFANode> init_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, 0));
            shared_ptr<DFANode> condition_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, 1));
            shared_ptr<DFANode> block_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, 3));
            shared_ptr<DFANode> expr_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, 2));
            shared_ptr<DFANode> out_tok = nullptr;

            //for_tok->addEdge(Type::OK, init_tok);
            init_tok->addEdge(Type::OK, condition_tok);
            condition_tok->addEdge(Type::YES, block_tok);
            condition_tok->addEdge(Type::NO, out_tok);
            block_tok->addEdge(Type::BREAKL, out_tok);
            block_tok->addEdge(Type::CONTINUEL, expr_tok);
            block_tok->addEdge(Type::OK, expr_tok);
            expr_tok->addEdge(Type::OK, condition_tok);

            v_node.push_back(init_tok);
            v_node.push_back(condition_tok);
            v_node.push_back(block_tok);
            v_node.push_back(expr_tok);
            return init_tok;
        }
        case WHILE: {
            shared_ptr<DFANode> condition_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, 0)); 
            shared_ptr<DFANode> block_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, 1));

            condition_tok->addEdge(Type::YES, block_tok);
            condition_tok->addEdge(Type::NO, nullptr);
            block_tok->addEdge(Type::OK, condition_tok);
            block_tok->addEdge(Type::CONTINUEL, condition_tok);
            block_tok->addEdge(Type::BREAKL, nullptr);

            v_node.push_back(condition_tok);
            v_node.push_back(block_tok);
            return condition_tok;
        }
    }
    return nullptr;
}

//BreakConverter
bool BranchExprConverter::test(pANTLR3_COMMON_TOKEN tok) {
    switch (tok->type) {
        case BLOCK:
           return true;
    }
    return false;
}

shared_ptr<DFANode> BranchExprConverter::convert(pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    switch (tok->type) {
        case BLOCK: {
            int k = tree->getChildCount(tree);
            if (k <= 0) return nullptr;
            vector<shared_ptr<DFANode>> v;
            for (int i = 0; i < k; i++) {
                shared_ptr<DFANode> node_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, i));
                v.push_back(node_tok);
                v_node.push_back(node_tok);
            }
            v.push_back(nullptr);
            for (int i = 0; i < k; i++) {
                v[i]->addEdge(Type::OK, v[i + 1]);
                v[i]->addEdge(Type::BREAKL, nullptr);
                v[i]->addEdge(Type::CONTINUEL, nullptr);
            }
            return v[0];
        }
    }
    return nullptr;
}
