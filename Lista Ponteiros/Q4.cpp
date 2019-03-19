include <iostream>

int main(){
	
	int i=5, j=4;
	
	p = i;
	q = &j;
	p = &*&i;
	i = (*&)j;
	i = *&j;
	i = *&*&j;
	q = *p;
	i = (*p)++ + *q;
	
	return 0
}

