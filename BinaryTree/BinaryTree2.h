#pragma once
#include "BinaryNode.h"
#include <cstdlib>
#define MAX_QUEUE_SIZE 100

inline void error(const char* str)
{
	std::cout << str << '\n';
	exit(1);
}

class CircularQueue_BinaryNode_ver {
private:
	int front;
	int rear;
	BinaryNode* data[MAX_QUEUE_SIZE];
public:
	CircularQueue_BinaryNode_ver() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(BinaryNode* n)
	{
		if (isFull())
			error("Error : 큐가 포화 상태입니다.\n");
		else
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}

	BinaryNode* dequeue()
	{
		if (isEmpty())
			error("Error : 큐가 공백 상태입니다.");
		else
		{
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};

class BinaryTree : public CircularQueue_BinaryNode_ver {
private:
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	void inorder()
	{
		printf("\n%11s ", "inorder:");
		inorder(root);
	}
	void inorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			inorder(node->getLeft());
			printf(" [%d] ", node->getData());
			inorder(node->getRight());
		}
	}

	void preorder()
	{
		printf("\n%11s ", "preorder:");
		preorder(root);
	}
	void preorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			printf(" [%d] ", node->getData());
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}

	void postorder()
	{
		printf("\n%11s ", "postorder:");
		postorder(root);
	}
	void postorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			postorder(node->getLeft());
			postorder(node->getRight());
			printf(" [%d] ", node->getData());
		}
	}
	void levelorder()
	{
		printf("\n%11s ", "levelorder:");
		if (!isEmpty())
		{
			CircularQueue_BinaryNode_ver q;
			q.enqueue(root);
			while (!q.isEmpty())
			{
				BinaryNode* n = q.dequeue();
				if (n != NULL)
				{
					printf(" [%d] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
	}
	bool isFull() { return isEmpty() ? 0 : isFull(root); }
	bool isFull(BinaryNode* node) {//레벨이 같으면 높이도 같아야함.
		if (node->isLeaf())   return true;//앞에서 자식노드들의 레벨이 모두 같았고, 현재 말단노드이면=>true
		if (getHeight(node->getLeft()) == getHeight(node->getRight())) {//높이가 같으면 자식들도 해당함수 실행
			return isFull(node->getLeft()) && isFull(node->getRight());
		}
		return false;
	}
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node) 	//매개변수를 각 서브트리의 root부터 시작하여 가장 깊은 곳까지 탐색을 진행함
	{
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	bool isBalanced() { return isEmpty() ? 1 : isBalanced(root); }
	bool isBalanced(BinaryNode* node)
	{
		if (abs(getHeight(node->getLeft()) - getHeight(node->getRight())) < 2)
			//height 함수를 호출하여 각각의 높이를 구함
			//이후 구한 높이의 차를 abs함수를 사용하여 절댓값으로 바꾸어 비교
			return true;

		return false;
	}
	bool reverse(BinaryNode* node)
	{
		if (node == NULL)	return false;
		else {
			reverse(node->getLeft());
			reverse(node->getRight());
			//leftNode와 rightNode를 서로 바꾼다
			BinaryNode* temp = node->getLeft();
			node->setLeft(node->getRight());
			node->setRight(temp);
		}
		return true;
	}
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf())return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
};