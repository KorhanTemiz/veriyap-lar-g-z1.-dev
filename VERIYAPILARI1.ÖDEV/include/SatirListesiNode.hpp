#ifndef SatirListesiNode_hpp
#define SatirListesiNode_hpp

#include <iostream>
using namespace std;


class SatirListesiNode{
	public:
		int data;
		SatirListesiNode *next;
		SatirListesiNode *prev;
		SatirListesiNode(int,SatirListesiNode *next=NULL,SatirListesiNode *prev=NULL);
};


#endif