#ifndef ___implement_binary_tree_h___
#define ___implement_binary_tree___

class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	};
};
class Tree
{
public:
	Node* root;
	Tree() : root(nullptr) {};
	Tree(Node* root) : root(root) {};
	Tree(vector<int> nodes_val)
	{
		vector<Node*> nodes = vector<Node*>();
		for (int i = 0; i < nodes_val.size(); i++)
		{
			Node* node = new Node(nodes_val[i]);
			nodes.push_back(node);
		}

		if (nodes.size() == 0)
			root = nullptr;
		else
			root = nodes[0];

		for (int i = 0; (i * 2) + 2 < nodes.size(); i++)
		{
			Node* parentNode = nodes[i];
			Node* leftNode = nullptr;
			Node* rightNode = nullptr;
			if (i * 2 + 1 < nodes.size())
				parentNode->left = nodes[i * 2 + 1];
			if (i * 2 + 2 < nodes.size())
				parentNode->right = nodes[i * 2 + 2];
		}
	}

	int findTreeLevel(Node* node)
	{
		if (node == nullptr)
			return 0;
		else
		{
			int leftLevel = findTreeLevel(node->left);
			int rightLevel = findTreeLevel(node->right);
			return leftLevel > rightLevel ? leftLevel + 1 : rightLevel + 1;
		}
	}
	void printTree(Node* node)
	{ // 전위순회임
		if (node == nullptr)
			return;
		cout << node->val << ", ";
		printTree(node->left);
		printTree(node->right);
	}
};


class TreeSolution {
public:
	void levelOrder() {
		vector<int> values = { 1,2,3,4,5,6,7,8,9 };
		Tree t = Tree(values);
		t.printTree(t.root);
		cout << "\n" << t.findTreeLevel(t.root) << "\n";

	}
};


#endif