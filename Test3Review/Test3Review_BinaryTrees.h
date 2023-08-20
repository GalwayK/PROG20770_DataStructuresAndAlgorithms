
typedef struct NumberNode
{
	int numberData;
	struct NumberNode* pntLeftNode; 
	struct NumberNode* pntRightNode;
} NumberNode;

typedef struct NumberTree
{
	NumberNode* pntRoot;
} NumberTree;

NumberNode* initializeBlankNumberNode();

NumberNode* initializeDetailedNumberNode(int numberData);

NumberTree* initializeNumberTree();

int countBinaryTreeNodes(NumberTree* pntBinaryTree);

void countNumberNode(NumberNode* pntNumberNode, int* pntCount);

void insertNumberIntoTree(NumberTree* pntNumberTree, int number);

void insertNumberIntoNode(NumberNode** numberNode, int number);

void printInOrderTreeTraversal(NumberTree* pntNumberTree);

void printPostOrderTreeTraversal(NumberTree* pntNumberTree);

void printPreOrderTreeTraversal(NumberTree* pntNumberTree);

void printInOrderNodeTraversal(NumberNode* pntNumberNode, int numDepth, int* pntCount);

void printPostOrderNodeTraversal(NumberNode* pntNumberNode, int numDepth, int* pntCount);

void printPreOrderNodeTraversal(NumberNode* pntNumberNode, int numDepth, int* pntCount);

int searchBinaryTreeForNumber(NumberTree* pntNumberTree, int searchNumber);


