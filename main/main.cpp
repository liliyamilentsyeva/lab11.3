#include<iostream>
using namespace std;
void main()
{
	int A[3][4] = {{5,25,31,21},{5,60,7,18},{2,8,11,67}}; 
	int n=3, m=4;

	_asm 
	{ 
			mov ecx, 0    
		begin_n: 
			mov ebx, 0  
		begin_m: 
			mov eax, m 
			mul ecx  
			add eax, ebx 
			mov esi, eax  
			mov edi, A[esi*4] 
 
			not edi
			mov A[esi*4], edi
 
			inc ebx   
			cmp ebx, m 
			jl begin_m  
			inc ecx    
			cmp ecx, n 
			jl begin_n  
	} 

 for(int i=0; i<n; i++)
	{ for(int j=0; j<m; j++)
	cout<<A[i][j]<<" ";}

}