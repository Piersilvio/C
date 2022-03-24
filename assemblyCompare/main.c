
/*
 * assembly compare of a simple exercise
 * spicoli piersilvio - universita degli studi di bari - aldo moro
 */

#include <stdio.h>

int main(){

	int x = 10;
	int y = 5;
	int c = 0;

	c = x + y;

	printf("%d", c);

	return 0;
}
/*
 * .LC0:
        .string "%d" //pre - processor
	main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 10 int x = 10;
        mov     DWORD PTR [rbp-8], 5  int x = 5;
        mov     DWORD PTR [rbp-12], 0 int c = 0;
        mov     edx, DWORD PTR [rbp-4]      move to address reference to 'c'
        mov     eax, DWORD PTR [rbp-8]
        add     eax, edx					opcode 'add'
        mov     DWORD PTR [rbp-12], eax     the result save on address reference 'c'
        mov     eax, DWORD PTR [rbp-12]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0						call to function 'printf' from <stdio.h>
        call    printf
        mov     eax, 0
        leave
        ret
 */
