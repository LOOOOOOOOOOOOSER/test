#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//位置
struct PosType
{
	int _x, _y;

	PosType()
		:_x(0)
		, _y(0)
	{}

	PosType(int x, int y)
		:_x(x)
		, _y(y)
	{}
};

//判断两个位置是否相同,不能加const修饰，此处没有this指针
bool operator==(const PosType& pos1, const PosType& pos2)	//const
{
	return pos1._x == pos2._x && pos1._y == pos2._y;
}

//判断两个位置是否不同,不能加const修饰，此处没有this指针
bool operator!=(const PosType& pos1, const PosType& pos2)	//const
{
	return pos1._x != pos2._x || pos1._y != pos2._y;
}

//迷宫输入
void InitMaze(vector<vector<int>>& map)
{
	cout << "迷宫地图初始化开始，0表示没有障碍物，1表示有障碍物" << endl;
	int row = map.size(), col = map[0].size();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> map[i][j];
		}
	}
	cout << "初始化完毕!" << endl;
}

//打印地图
void PrintMap(const vector<vector<int>>& map)
{
	int row = map.size(), col = map[0].size();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

//判断是否有从beginPos到endPos的路径,使用栈进行深度优先搜索
bool IsHasPath(vector<vector<int>>& map, PosType beginPos, PosType endPos)
{
	int rows = map.size(), cols = map[0].size();

	//判断位置是否有效
	if (beginPos._x < 0 || beginPos._x >= rows
		|| beginPos._y < 0 || beginPos._y >= cols
		|| endPos._x < 0 || endPos._x >= rows
		|| endPos._y < 0 || endPos._y >= cols
		|| map[beginPos._x][beginPos._y] == 1 || map[endPos._x][endPos._y] == 1)
	{
		return false;
	}

	int nextStep[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };		//四个移动方向
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));	//标记数组
	stack<PosType> st;
	st.push(beginPos);

	while (!st.empty() && st.top() != endPos)
	{
		PosType top = st.top();
		//栈顶元素如果已经访问过，就让栈顶元素出栈
		if (visited[top._x][top._y])
		{
			st.pop();
		}

		visited[top._x][top._y] = true;
		map[top._x][top._y] = 8;

		//在上下左右四个方向没有访问过的，可以通过的位置
		for (int i = 0; i < 4; ++i)
		{
			int curX = top._x + nextStep[i][0];
			int curY = top._y + nextStep[i][1];
			if (curX < 0 || curX >= rows || curY < 0 || curY >= cols)
			{
				continue;
			}

			//新位置没有被访问过，而且是可通的，将其入栈
			if (!visited[curX][curY] && map[curX][curY] == 0)
			{
				st.push(PosType(curX, curY));
			}
		}
	}

	//栈顶元素就是目标位置，返回查找成功
	if (!st.empty() && st.top() == endPos)
	{
		map[st.top()._x][st.top()._y] = 8;
		return true;
	}
	//栈顶元素不是目标位置，返回查找失败
	else
	{
		return false;
	}
}

//开始游戏
void GameStart(vector<vector<int>>& map)
{
	int row = map.size(), col = map[0].size();

	PosType beginPos, endPos;		//起始位置，目标位置
	cout << "请输入起始位置下标: ";
	cin >> beginPos._x >> beginPos._y;
	cout << "请输入目标位置下标: ";
	cin >> endPos._x >> endPos._y;

	//判断是否可以到达目标位置
	bool ret = IsHasPath(map, beginPos, endPos);
	if (ret)
	{
		//可以到达目标位置，打印路径
		cout << "可以到达目标位置,路径如下,走过的位置用8表示" << endl;
		PrintMap(map);
	}
	else
	{
		//不能到达目标位置
		cout << "这是一个无法到达的位置" << endl;
	}
}

int main()
{
	int row, col;
	cout << "请输入迷宫的行数和列数: ";
	cin >> row >> col;

	vector<vector<int>> matrix(row, vector<int>(col));

	cout << "请初始化迷宫" << endl;
	InitMaze(matrix);

	//打印迷宫
	PrintMap(matrix);

	//开始游戏
	GameStart(matrix);

	return 0;
}
