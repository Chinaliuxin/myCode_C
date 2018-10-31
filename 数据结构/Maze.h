#pragma once
#include <stdio.h>
#include "Stack.h"



#if 0
#define  MAX_ROW  6
#define  MAX_COL  6

typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;


int _PassMaze(Maze* m, Position entry, Position cur);

 void InitMap(Maze* m, int map[MAX_ROW][MAX_COL])
 {
	 int i = 0, j = 0;
     if(NULL == m)
		 return;

	 for(i = 0; i < MAX_ROW; ++i)
	 {
		 for(j = 0; j < MAX_COL; ++j)
			 m->_map[i][j] = map[i][j];
	 }
 }

 // 检测迷宫的入口是否有效
 int IsValidEnter(Maze* m, Position enter)
 {
	 if(NULL == m)
		 return 0;

	 if(0 == enter._x || MAX_ROW-1 == enter._x ||
		0 == enter._y || MAX_COL-1 == enter._y)
	 {
		 return 1 == m->_map[enter._x][enter._y];
	 }
	 
	 return 0;
 }

 // 检测cur位置是否为迷宫的出口
 int IsMazeExit(Maze* m, Position cur, Position enter)
 {
	 if(cur._x == enter._x  && cur._y == enter._y)
		 return 0;

	 if(0 == cur._x || MAX_ROW - 1 == cur._x || 
		0 == cur._y || MAX_COL - 1 == cur._y)
	 {
		 return 1;
	 }

	 return 0;
 }

 int IsPass(Maze* m, Position cur)
 {
	 return 1 == m->_map[cur._x][cur._y];
 }

 void PassMazeNor(Maze* m, Position enter, Stack* s)
 {
	 Position next;
	 if(!IsValidEnter(m, enter))
	 {
		 printf("迷宫入口有误!!!\n");
		 return;
	 }

	 StackPush(s, enter);

	 while(!StackEmpty(s))
	 {
		 Position cur = StackTop(s);
		 m->_map[cur._x][cur._y] = 2;

		 if(IsMazeExit(m, cur, enter))
			 return;

		 // 上
		 next = cur;
		 next._x -= 1;
		 if(IsPass(m, next))
		 {
			 StackPush(s, next);
			 continue;
		 }

		 // 左
		 next = cur;
		 next._y -= 1;
		 if(IsPass(m, next))
		 {
			 StackPush(s, next);
			 continue;
		 }

		 // 右
		 next = cur;
		 next._y += 1;
		 if(IsPass(m, next))
		 {
			 StackPush(s, next);
			 continue;
		 }

		 // 下
		 next = cur;
		 next._x += 1;
		 if(IsPass(m, next))
		 {
			 StackPush(s, next);
			 continue;
		 }

		 //说明：cur步走错了
		 m->_map[cur._x][cur._y] = 3;
		 StackPop(s);
	 }
 }

 void PassMaze(Maze* m, Position enter)
 {
	 if(!IsValidEnter(m, enter))
	 {
		 printf("迷宫入口有误!!!\n");
		 return;
	 }

	 _PassMaze(m, enter, enter);
 }

 int _PassMaze(Maze* m, Position entry, Position cur)
 {
	 if(IsPass(m, cur))
	 {
		 Position next;
		 m->_map[cur._x][cur._y] = 2;
		 if(IsMazeExit(m, cur, entry))
			 return 1;

		 // 上
		 next = cur;
		 next._x -= 1;
		 if(_PassMaze(m, entry, next))
			 return 1;

		 // 左
		 next = cur;
		 next._y -= 1;
		 if(_PassMaze(m, entry, next))
			 return 1;

		 // 右
		 next = cur;
		 next._y += 1;
		 if(_PassMaze(m, entry, next))
			 return 1;

		 // 下
		 next = cur;
		 next._x += 1;
		 if(_PassMaze(m, entry, next))
			 return 1;

		  m->_map[cur._x][cur._y] = 3;
	 }

	 return 0;
 }



 void PrintMap(Maze* m)
 {
	 int i = 0, j = 0;
	 if(NULL == m)
		 return;

	 for(i = 0; i < MAX_ROW; ++i)
	 {
		 for(j = 0; j < MAX_COL; ++j)
			 printf("%d ", m->_map[i][j]);

		 printf("\n");
	 }
 }

 void PrintPath(Stack* s)
 {
	  Position top;
	 while(StackSize(s) > 1)
	 {
		 top = StackTop(s);
		 printf("{%d, %d}<---", top._x, top._y);
		 StackPop(s);
	 }

	 top = StackTop(s);
	 printf("{%d, %d}", top._x, top._y);
 }


void TestMap()
{
	Maze m;
	Stack s;
	Position enter;
	int map[MAX_ROW][MAX_COL] = {
		{0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 0, 1, 1, 1, 0},
		{0, 0, 1, 0, 1, 1},
		{0, 0, 1, 0, 0, 0}};
	InitMap(&m, map);
	PrintMap(&m);
	printf("\n");

	StackInit(&s);

	enter._x = 5;
	enter._y = 2;
	//PassMaze(&m, enter, &s);
	PassMaze(&m, enter);

	PrintMap(&m);
	printf("\n");
	PrintPath(&s);
}

#endif


#define  MAX_ROW  4
#define  MAX_COL  4

typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;


void _PassMaze(Maze* m, Position entry, Position cur, Stack* path, Stack* shortPath);

void InitMap(Maze* m, int map[MAX_ROW][MAX_COL])
{
	int i = 0, j = 0;
	if(NULL == m)
		return;

	for(i = 0; i < MAX_ROW; ++i)
	{
		for(j = 0; j < MAX_COL; ++j)
			m->_map[i][j] = map[i][j];
	}
}

// 检测迷宫的入口是否有效
int IsValidEnter(Maze* m, Position enter)
{
	if(NULL == m)
		return 0;

	if(0 == enter._x || MAX_ROW-1 == enter._x ||
		0 == enter._y || MAX_COL-1 == enter._y)
	{
		return 1 == m->_map[enter._x][enter._y];
	}

	return 0;
}

// 检测cur位置是否为迷宫的出口
int IsMazeExit(Maze* m, Position cur, Position enter)
{
	if(cur._x == enter._x  && cur._y == enter._y)
		return 0;

	if(0 == cur._x || MAX_ROW - 1 == cur._x || 
		0 == cur._y || MAX_COL - 1 == cur._y)
	{
		return 1;
	}

	return 0;
}

int IsPass(Maze* m, Position cur)
{
	return 1 == m->_map[cur._x][cur._y];
}

void PassMazeNor(Maze* m, Position enter, Stack* s)
{
	Position next;
	if(!IsValidEnter(m, enter))
	{
		printf("迷宫入口有误!!!\n");
		return;
	}

	StackPush(s, enter);

	while(!StackEmpty(s))
	{
		Position cur = StackTop(s);
		m->_map[cur._x][cur._y] = 2;

		if(IsMazeExit(m, cur, enter))
			return;

		// 上
		next = cur;
		next._x -= 1;
		if(IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}

		// 左
		next = cur;
		next._y -= 1;
		if(IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}

		// 右
		next = cur;
		next._y += 1;
		if(IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}

		// 下
		next = cur;
		next._x += 1;
		if(IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}

		//说明：cur步走错了
		m->_map[cur._x][cur._y] = 3;
		StackPop(s);
	}
}

void PassMaze(Maze* m, Position enter, Stack* ShortPath)
{
	Stack path;
	if(!IsValidEnter(m, enter))
	{
		printf("迷宫入口有误!!!\n");
		return;
	}

	StackInit(&path);
	_PassMaze(m, enter, enter, &path, ShortPath);
}

void SaveShortPath(Stack* path, Stack* shortPath)
{
	int i = 0;
	int size = StackSize(path);
	for(; i < size; ++i)
		shortPath->_array[i] = path->_array[i];

	shortPath->_top = i;
}

int IsNextPass(Maze* m, Position cur, Position next, Position entry)
{
	if(next._x < 0 || next._x >= MAX_ROW ||
	   next._y < 0 || next._y >= MAX_COL)
	{
		return 0;
	}

	if((1 == m->_map[next._x][next._y]) || 
	   (m->_map[cur._x][cur._y] < m->_map[next._x][next._y]))
	{
		return 1;
	}

	return 0;
}


void _PassMaze(Maze* m, Position entry, Position cur, Stack* path, Stack* shortPath)
{
	Position next;
	if(StackEmpty(path))
		m->_map[cur._x][cur._y] = 2;

	StackPush(path, cur);
	if(IsMazeExit(m, cur, entry))
	{
		if(StackEmpty(shortPath) || StackSize(path) < StackSize(shortPath))
			SaveShortPath(path, shortPath);

		StackPop(path);
		return;
	}

	// 上
	next = cur;
	next._x -= 1;
	if(IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}

	// 左
	next = cur;
	next._y -= 1;
	if(IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}

	// 右
	next = cur;
	next._y += 1;
	if(IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}

	// 下
	next = cur;
	next._x += 1;
	if(IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}

	StackPop(path);
}

void PrintMap(Maze* m)
{
	int i = 0, j = 0;
	if(NULL == m)
		return;

	for(i = 0; i < MAX_ROW; ++i)
	{
		for(j = 0; j < MAX_COL; ++j)
			printf("%d ", m->_map[i][j]);

		printf("\n");
	}
}

void PrintPath(Stack* s)
{
	Position top;
	while(StackSize(s) > 1)
	{
		top = StackTop(s);
		printf("{%d, %d}<---", top._x, top._y);
		StackPop(s);
	}

	top = StackTop(s);
	printf("{%d, %d}", top._x, top._y);
}


void TestMap()
{
	Maze m;
	Stack s;
	Position enter;
	int map[MAX_ROW][MAX_COL] = {
		{0, 0, 0, 0},
		{0, 1, 1, 0},
		{0, 1, 1, 1},
	    {0, 1, 0, 0}};
		InitMap(&m, map);
		PrintMap(&m);
		printf("\n");

		StackInit(&s);

		enter._x = 3;
		enter._y = 1;
		//PassMaze(&m, enter, &s);
		PassMaze(&m, enter, &s);

		PrintMap(&m);
		printf("\n");
		PrintPath(&s);
}

