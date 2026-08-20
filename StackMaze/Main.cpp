#include "Stack.h"
#include <iostream>

// 이동 좌표를 처리하기 위한 클래스.
class Location2D
{
public:
	Location2D(int row = 0, int col = 0)
		: row(row), col(col)
	{
	}

public:
	// 행-Y축.
	int row = 0;

	// 열-X축.
	int col = 0;
};

const int mazeSize = 6;

// 미로.
char maze[mazeSize][mazeSize] =
{
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}
};

// 맵에서 방문을 했는지 확인하기 위한 배열.
bool visited[mazeSize][mazeSize] = {};

// 전달한 미로의 위치가 이동 가능한지 판단하는 함수.
// row-행-y축 값 | col-열-x축 값.
bool IsValidLocation(int row, int col)
{
	// 미로의 범위를 벗어났는지 확인.
	if (row < 0 || row >= mazeSize
		|| col < 0 || col >= mazeSize)
	{
		return false;
	}

	// 이미 방문한 위치인지 확인.
	if (visited[row][col])
	{
		return false;
	}

	// 길이거나 출구인 경우 이동 가능.
	return maze[row][col] == '0' || maze[row][col] == 'x';
}

int main()
{
	// 시작 위치 검색.
	int startRow = -1;
	int startCol = -1;

	// 미로 출력 및 시작 위치 검색.
	for (int row = 0; row < mazeSize; ++row)
	{
		for (int col = 0; col < mazeSize; ++col)
		{
			// 미로 출력.
			std::cout << maze[row][col] << ' ';

			// 시작 위치인지 확인.
			if (maze[row][col] == 'e')
			{
				startRow = row;
				startCol = col;
			}
		}

		std::cout << "\n";
	}

	// 입구를 찾지 못한 경우 탐색 종료.
	if (startRow == -1 || startRow == -1)
	{
		std::cout << "입구를 못찾음\n";
		return 0;
	}

	// 탐색에 사용할 스택.
	Stack<Location2D> locationStack;

	// 입구부터 탐색 시작.
	locationStack.Push(Location2D(startRow, startCol));
	visited[startRow][startCol] = true;	// 시작 위치는 방문한 위치로 설정.

	// 상하좌우 이동에 사용할 오프셋 값 (방향 데이터로 활용함).
	const int rowOffset[4] = { -1, 1, 0, 0 };
	const int colOffset[4] = { 0, 0, -1, 1 };
}