#include "BinaryTree.h"
#include <iostream>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class Actor
{
public:
	bool operator==(const Actor& other) const
	{
		return false;
	}
};

// 원시 문자열 두 개를 입력 받아서 두 문자열이 서로 같은지 비교하는 함수 구현.
bool StringCompare(const char* left, const char* right)
{
	// ...

	return false;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Actor actor;
	//BinaryTree<Actor> actorTree({ });
	//actorTree.Find(actor);

	BinaryTree<std::string> tree("A");

	tree.AddLeftChild("A", "B");
	tree.AddRightChild("A", "C");

	tree.AddLeftChild("B", "D");
	tree.AddRightChild("B", "E");

	tree.AddLeftChild("C", "F");
	tree.AddRightChild("C", "G");

	std::cout << "삭제 전 중위 순회: \n";
	tree.InorderTraverse();

	if (tree.Remove("B"))
	{
		std::cout << "B 노드 제거 성공. 삭제 후 중위 순회: \n";
		tree.InorderTraverse();
	}
	else
	{
		std::cout << "삭제 실패\n";
	}

	// 검색.
	if (tree.Find("Q"))
	{
		std::cout << "Q 검색 성공\n";
	}
	else
	{
		std::cout << "Q 검색 실패\n";
	}
}