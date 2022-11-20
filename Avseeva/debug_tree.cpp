#include "debug_tree.h"

void initTree(TTree& root)
{
	root = 0;
}

void initTree(TTree& root, datatype elem)
{
	root = new TreeNode;
	root->data = elem;
	root->left = root->right = 0;
}

// присоединение к корню левого узла (дочернего)

void attachLeftSon(TTree root, datatype elem)
{
	if (isEmpty(root))
		std::cout << "Tree is empty";
	else
		if (root->left)
			std::cout << "The son is already exist";
		else
		{
			root->left = new TreeNode;
			root->left->data = elem;
			root->left->left = 0;
			root->left->right = 0;
		}
}

void attachRightSon(TTree root, datatype elem)
{
	if (isEmpty(root))
		std::cout << "Tree is empty";
	else
		if (root->right)
			std::cout << "The son is already exist";
		else
		{
			root->right = new TreeNode;
			root->right->data = elem;
			root->right->left = 0;
			root->right->right = 0;
		}
}

void attachLeftSubtree(TTree root, TTree subtree) // справа аналогично 
{
	if (isEmpty(root))
		std::cout << "Tree is empty";
	else
		if (root->left)
			std::cout << "The subtree is already exist";
		else
			root->left = subtree;
}

void attachRightSubtree(TTree root, TTree subtree)
{
	if (isEmpty(root))
		std::cout << "Tree is empty";
	else
		if (root->right)
			std::cout << "The subtree is already exist";
		else
			root->right = subtree;
}

// отсоединение от корня левого поддерева

void deleteLeftSubtree(TTree root, TTree subtree) // ???
{
	if (isEmpty(root))
		std::cout << "The tree is empty";
	else
	{
		subtree = root->left;
		root->left = 0;
	}
}

void deleteRightSubtree(TTree root, TTree subtree) // ???
{
	if (isEmpty(root))
		std::cout << "The tree is empty";
	else
	{
		subtree = root->right;
		root->right = 0;
	}
}

void copyTree(TTree root, TTree& newRoot)
{
	if (root)
	{
		newRoot = new TreeNode;
		newRoot->data = root->data;
		newRoot->left = 0;
		newRoot->right = 0;

		copyTree(root->left, newRoot->left);

		copyTree(root->right, newRoot->right);
	}
	else
		newRoot = 0;
}

TTree getLeftSubtree(TTree root)
{
	TTree leftSubtree = 0;

	if (root)
		copyTree(root->left, leftSubtree);

	return leftSubtree;
}

void destroyTree(TTree& root)
{
	if (root)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		root->left = root->right = 0;
		delete root;
		root = 0;
	}
}

bool isEmpty(TTree root)
{
	return (root == 0);
}


void preeorder(TTree root)
{
	if (root)
	{
		std::cout << root->data; // или тут можно использовать функцию
		preeorder(root->left);
		preeorder(root->right);
	}
}

void inorder(TTree root)
{
	if (root)
	{
		inorder(root->left);
		std::cout << root->data << '\t';
		inorder(root->right);
	}
}

void postfix(TTree root) // возможно так 
{
	if (root)
	{
		inorder(root->left);
		inorder(root->right);
		std::cout << root->data;
	}
}

// инфиксный с помощью стека 

// когда кладем в стек идем влево, когда забираем из стека, то идем вправо

//void infixIterative(TTree root)
//{
//	ListStack st;
//	bool done = false;
//	TTree cur = root;
//	st.push(root);
//	while (!done)
//	{
//		if (cur)
//		{
//			st.push(cur);
//			cur = cur->left;
//		}
//		else
//			if (!st.isEmpty())
//			{
//				cur = st.peak();
//				std::cout << cur->data;
//				cur = cur->right();
//				st.pop();
//			}
//			else
//				done = true;
//	}
//}

// обход в ширину - очередь 

//void breadthTraverse(TTree root)
//{
//	TQueue q;
//	if (root)
//	{
//		q.enque(root);
//		while (!q.isEmpty())
//		{
//			TTree cur = q.peek();
//			std::cout << cur->data;
//			q.deque();
//
//			if (cur->left)
//				q.enque(cur->left);
//			if (cur->right)
//				q.enque(cur->right);
//		}
//	}
//}

TTree createFormula(std::ifstream& fin)
{
	char ch = fin.get();
	TTree root = new TreeNode;
	if (ch >= '0' && ch <= '9')
	{
		root->data = ch;
		root->left = 0;
		root->right = 0;
	}
	else // прочитали скобку
	{
		root->left = createFormula(fin);
		root->data = fin.get();
		root->right = createFormula(fin);
		ch = fin.get();
	}
	return root;
}

//std::string printStr(TTree root)
//{
//	if (root->left == 0 && root->right == 0)
//		return std::string(1, root->data);
//	else
//		return std::string("(" + printStr(root->left) + root->data + printStr(root->right) + ")");
//}

int calcFormula(TTree root)
{
	if (root->left == 0 && root->right == 0)
		return root->data - '0';
	else
	{
		int res;
		int left_res = calcFormula(root->left);
		int right_res = calcFormula(root->right);
		switch (root->data)
		{
		case '+':
			return res = left_res + right_res;
			break;
		case '-':
			return res = left_res - right_res;
			break;
		case '*':
			return res = left_res * right_res;
			break;
		case '/':
			return res = left_res / right_res;
			break;
		}
	}
}

void createBalancedTree(std::ifstream& fin, TTree& root)
{
	int nodeCount;
	fin >> nodeCount;
	root = createNodes(nodeCount, fin);
}

TTree createNodes(int nodeCount, std::ifstream& fin)
{
	if (nodeCount == 0) return 0;
	else
	{
		TTree node = new TreeNode;
		int data;
		fin >> data;
		node->data = data;
		node->left = createNodes(nodeCount / 2, fin);
		node->right = createNodes(nodeCount - nodeCount / 2 - 1, fin);
		return node;
	}
}

void print_Tree(TTree root, int level, std::ostream & stream)
{
	if (root)
	{
		print_Tree(root->right, level + 1, stream);
		for (int i = 0; i < level; i++) 
			stream << "   ";
		stream << root->data << '\n';
		print_Tree(root->left, level + 1, stream);
	}
}

int count(TTree root, int level, int cur_level)
{
	if (!root)
		return 0;
	else
		if (level == cur_level)
			return 1;
		else
			return count(root->left, level, cur_level+1) + count(root->right, level, cur_level+1);
}