// 
//  PointersandRefs.cpp : A simple numeric menu that when the user inputs a certain integer, the numbered function will run.
//  
//
//  Created by Danny Nguyen on 2/8/18.
//  Copyright © 2018 Danny Nguyen. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
void threeInts(int *a, int *b, int *c);
void threeInts(int &a, int &b, int &c);
int main()
{
	int a, b, c;
	std::cout << "Enter two integers: "<< std::endl;
	std::cin >> a >> b;
	threeInts(&a,&b,&c);
	threeInts(a,b,c);
    return 0;
}
/*
	*Addition and Multiplication by pointer
*/
void threeInts(int *aptr, int *bptr, int *cptr) {
	*cptr = *aptr + *bptr;
	std::cout << "Sum is " << *cptr << std::endl;
	*cptr = *aptr * *bptr;
	std::cout << "Product is " << *cptr << std::endl;
}
/*
	*Addition and Multiplication by Reference
*/
void threeInts(int &a, int &b, int &c) {
	c = a + b;
	std::cout << "Sum is " << c << std::endl;
	c = a * b;
	std::cout << "Product is " << c << std::endl;
}

			