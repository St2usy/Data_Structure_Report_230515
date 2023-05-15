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
			error("Error : ť�� ��ȭ �����Դϴ�.\n");
		else
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}

	BinaryNode* dequeue()
	{
		if (isEmpty())
			error("Error : ť�� ���� �����Դϴ�.");
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
	bool isFull(BinaryNode* node) {//������ ������ ���̵� ���ƾ���.
		if (node->isLeaf())   return true;//�տ��� �ڽĳ����� ������ ��� ���Ұ�, ���� ���ܳ���̸�=>true
		if (getHeight(node->getLeft()) == getHeight(node->getRight())) {//���̰� ������ �ڽĵ鵵 �ش��Լ� ����
			return isFull(node->getLeft()) && isFull(node->getRight());
		}
		return false;
	}
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node) 	//�Ű������� �� ����Ʈ���� root���� �����Ͽ� ���� ���� ������ Ž���� ������
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
			//height �Լ��� ȣ���Ͽ� ������ ���̸� ����
			//���� ���� ������ ���� abs�Լ��� ����Ͽ� �������� �ٲپ� ��
			return true;

		return false;
	}
	bool reverse(BinaryNode* node)
	{
		if (node == NULL)	return false;
		else {
			reverse(node->getLeft());
			reverse(node->getRight());
			//leftNode�� rightNode�� ���� �ٲ۴�
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