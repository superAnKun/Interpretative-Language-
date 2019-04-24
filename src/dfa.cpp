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

//SwitchExpr
bool SwitchExprConverter::test(pANTLR3_COMMON_TOKEN tok) {
    switch(tok->type) {
        case SWITCH:
        return true;
    }
    return false;
}

shared_ptr<DFANode> SwitchExprConverter::convert(pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    switch (tok->type) {
        case SWITCH: {
            shared_ptr<DFANode> expr_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, 0));
            v_node.push_back(expr_tok);
            int k = tree->getChildCount(tree);
            if (k < 2) return expr_tok;
            for (int i = 1; i < k - 1; i++) {
                shared_ptr<DFANode> tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, i));
                v_node.push_back(tok);
                expr_tok->addEdge(Type::CASEL, tok);
                tok->addEdge(Type::BREAKL, nullptr);
            }
            pANTLR3_BASE_TREE temp_tree = (pANTLR3_BASE_TREE)tree->getChild(tree, k - 1);
            if (temp_tree->getToken(temp_tree)->type == DEFAULT) {
                shared_ptr<DFANode> tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, k - 1));
                v_node.push_back(tok);
                expr_tok->addEdge(Type::DEFAULTL, tok);
                tok->addEdge(Type::BREAKL, nullptr);
            } else {
                shared_ptr<DFANode> tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, k - 1));
                v_node.push_back(tok);
                expr_tok->addEdge(Type::CASEL, tok);
                tok->addEdge(Type::BREAKL, nullptr);
            }
            v_node.push_back(nullptr);
            expr_tok->addEdge(Type::OK, nullptr);
            expr_tok->reverse();
            for (int i = 1; i < k; i++) {
                v_node[i]->addEdge(Type::OK, v_node[i + 1]);
            }
            return expr_tok;
        }
        case CASE: {
            int k = tree->getChildCount(tree);
            if (k < 2) return nullptr;
            for (int i = 1; i < k; i++) {
                shared_ptr<DFANode> case_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, i));
                v_node.push_back(case_tok);
                case_tok->addEdge(Type::BREAKL, nullptr);
            }
            v_node.push_back(nullptr);
            for (int i = 1; i < k; i++) {
                v_node[i - 1]->addEdge(Type::OK, v_node[i]);
            }
            return v_node[0];
        }
        case DEFAULT: {
            int k = tree->getChildCount(tree);
            if (k < 1) return nullptr;
            for (int i = 0; i < k; i++) {
                shared_ptr<DFANode> case_tok = make_shared<DFANode>((pANTLR3_BASE_TREE)tree->getChild(tree, i));
                v_node.push_back(case_tok);
                case_tok->addEdge(Type::BREAKL, nullptr);
            }
            v_node.push_back(nullptr);
            for (int i = 0; i < k; i++) {
                v_node[i]->addEdge(Type::OK, v_node[i + 1]);
            }
            return v_node[0];
        }
    }
    return nullptr;
}
