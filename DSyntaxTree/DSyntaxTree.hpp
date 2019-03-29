#include<string>


class Tree{
    std::string data;
    Tree* left,*right;
};
class DSyntaxTree{
    std::string *tokens;
    std::string *tokenCorrections;
    void parse();
    void output();
    int allocAmmount;
public:
    void buildTree(const std::string& expression);
    void tokenize();
    void correctTokens();
    void infix();
    void eval(std::string expression);
    std::string expression;
    friend class Tree;
};