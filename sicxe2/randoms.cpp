#include "pch.h"
#include "randoms.h"

#define setdbg false
#define dbg if(setdbg)
#define msize 12287//2FFF
#define pgsize 4000//4k
randoms::randoms()
{/*���n�I�s�o�ӡA�s(int)���h��*/
	cout << "[ERROR@randoms.cpp::randoms()]" << endl;
	exit(1);
}

randoms::randoms(int progsize)
{/*�s�F�ګ�A�Хsint load_addr(�ݩ�)*/
	min = 1024;
	max = msize - progsize * 125 / 100;
	pages = (max - min) / pgsize;
	dbg cout << max << endl;
	dbg cout << pages << endl;
	random_device generator;
	uniform_int_distribution<int> distribution(0, pages);
	//uniform_int_distribution<int> distribution2(0, 6);
	//dbg cout << distribution2(generator) << endl;
	pnum = distribution(generator);
	load_addr = min + pnum * pgsize;
}


randoms::~randoms()
{
}
