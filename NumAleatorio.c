#include<time.h> 
#include<stdlib.h> 
  
main() 
{ 
int i,j,a[10][10],b[10][10]; 
  
srand(time(NULL)); 
for(i=1;i<=10;i++){ 
  
    printf("%d ", rand() % 100); 
  } 
  
  getch(); 
  return 0; 
} 
 
