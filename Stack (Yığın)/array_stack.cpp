#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 4


typedef struct {
	int data[STACK_SIZE]; 		// Ihtiyaca gore veri turu degisebilir.
	int top;
	// Surekli eleman ekleme ve silme islemi yapilacagi için en ustteki
	// elemanin indisini tutan top adinda bir deðisken tanimladik.
}stack;

// Eleman Ekleme Islemi (push)
void push(stack *stk, int c){
	if(stk->top == STACK_SIZE-1){ // "top" son indisi tutuyorsa doludur.
		printf("\nStack dolu\n\n");
	}
	else{
		stk->top ++;
		stk->data[stk -> top] = c;
	}
	// Eleman eklendikten sonra "top" deðiskeni en son eklenen elemanin indis degerini tutmaktadir.
}

// Tum Elemanlari Silme Islemi
void reset(stack *stk) {
	stk->top = -1;
	// stack’i resetlemek için top degiskeninin degerini -1 yapmamiz yeterlidir.
	// Bu atamadan sonra top herhangi bir indis degeri tutmuyor demektir.
}

// Eleman Cikarma Islemi (pop)
int pop(stack *stk) {
	if(stk -> top == -1){ 		// stack bos mu diye kontrol ediliyor.
		printf("Stack bos\n");
	}
	else{
		int x = stk -> top--; 	// -- operatorunun islem sirasina dikkat!
		return x; 				// Cikarilan elemanin indis degeriyle geri donüyor.
	}
	/* else kismi su tek satir kodla da yazýlabilirdi.
	Fakat bu kez geri donus degerinin stack’den cikarilan verinin kendisi olduguna dikkat ediniz.
	else{
		return(stk -> data[stk -> top--]);
	} */
}

int main(){
	int x;
	stack n;
	reset(&n);
	push(&n, 4);
	push(&n, 2);
	push(&n, 5);
	push(&n, 7);
	push(&n, 11);
	x = pop(&n);
	printf("%d\n", x);
	x = pop(&n);
	printf("%d\n", x);
	x = pop(&n);
	printf("%d\n", x);
	x = pop(&n);
	printf("%d\n", x);
	x = pop(&n);
	printf("%d\n", x);
	//getch();
	
	return 0;	
}
