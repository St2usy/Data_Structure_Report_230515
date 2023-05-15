#include "BinaryTree2.h"

void main()
{
	BinaryTree tree;

	BinaryNode *d = new BinaryNode(4, NULL, NULL);
	BinaryNode* e = new BinaryNode(5, NULL, NULL);
	BinaryNode *b = new BinaryNode(2, d, e);
	BinaryNode *f = new BinaryNode(6, NULL, NULL);
	BinaryNode* g = new BinaryNode(7, NULL, NULL);
	BinaryNode *c = new BinaryNode(3, f, g);
	BinaryNode *a = new BinaryNode(1, b, c);

	tree.setRoot(a);
	printf(" 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());
	tree.inorder(); // 중위
	tree.preorder(); // 전위
	tree.postorder(); // 후위

	std::cout << std::endl;
	std::cout << tree.isBalanced() << std::endl;
	std::cout << tree.isFull() << std::endl;

	tree.reverse(a); // 리버스

	tree.inorder();
	tree.preorder();
	tree.postorder();
	std::cout << std::endl;

	BinaryTree tree2;
	BinaryNode* F = new BinaryNode(6, NULL, NULL);
	BinaryNode* G = new BinaryNode(7, NULL, NULL);
	BinaryNode* C = new BinaryNode(3, F, G);
	BinaryNode* A = new BinaryNode(1, NULL, C);

	tree2.setRoot(A);
	printf(" 노드의 개수 = %d\n", tree2.getCount());
	printf(" 단말의 개수 = %d\n", tree2.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree2.getHeight());
	tree2.inorder(); // 중위
	tree2.preorder(); // 전위
	tree2.postorder(); // 후위

	std::cout << std::endl;
	std::cout << tree2.isBalanced() << std::endl;
	std::cout << tree2.isFull() << std::endl;

	tree2.reverse(a); // 리버스

	tree2.inorder();
	tree2.preorder();
	tree2.postorder();
}