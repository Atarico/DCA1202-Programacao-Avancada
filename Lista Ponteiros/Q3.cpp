#include <iostream>

int main(){
	
	int i=5, *p;
	p = &i;
	printf("%x %d %d %d %d", p,*p+2,**&p,3**p,**&p+4);
	
	return 0
}