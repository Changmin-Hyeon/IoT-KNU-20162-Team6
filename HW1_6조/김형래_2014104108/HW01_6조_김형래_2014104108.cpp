#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

   char word[20];       // 문자열을 저장하는 노드이므로 char형 배열을 멤버로 넣었다.
   struct node* next;
   int index;           // 구조체 node의 멤버에 index를 넣었다.

}node;  

node* NewNode(char* word1){

   node* n = (node*)malloc(sizeof(node));
   n->next = NULL;
    strcpy(n->word, word1); //배열에 있는 스트링을 카피하는 함수다. 처음에 단순 대입으로 했더니 프로그램이 작동하지 않았다.
    return n;
}

void LinkNode(node* head, node* n){

   node* a = head->next;
   
   if(head->next == NULL){
      head->next = n;
	  n->index = 1;              // 노드가 없을시 새로운 노드를 연결하고 인덱스 번호 1을 주었다.
     
      
   }
   else
   {
       a->index = 1;         

      while(a->next != NULL)  // a 노드를 이용해 n 노드의 자리를 잡는 과정.
      {
         a = a->next;
		
      }
      a->next = n;  
      n->index = a->index+1;  // loop가 끝나면 마지막에 자리잡은 a의 next가 n을 가리킨다.
              
            
   }    
}


int Error(FILE* fo){             // 스트림이 NULL일 때 오류를 알려주기 위해 만든 함수.

   printf("파일오픈 실패\n");
   fclose(fo);
   return -1;

}

node* LList(void){

   node* head = (node*)malloc(sizeof(node));
   node* s;
   int i=0, j=0;
   char buf[20];
   FILE* fo; 

   head->word[20]=0;
   head->next = NULL;

   
   fo = fopen("hw.txt", "rt");

   if(fo == NULL){
      Error(fo);              // Error 함수 호출을 통해 오류 발생시 사용자가 알 수 있게 하였다.
   }
   
   while(fscanf(fo, "%s", buf) != EOF){
     
	   for(i=0;i<sizeof(buf);i++)
	   {
	   if((buf[i]==33)||(buf[i]==34)||(buf[i]==39)||(buf[i]==44)||(buf[i]==46)||(buf[i]==63)) // 아스키코드에서 !"',.? 문자 제외
	   {
			  
		   for(j=i;buf[j]!=0;j++)
			   buf[j] = buf[j+1]; //특수문자가 있는 다음 배열값을 특수문자의 배열에 넣었다.  
	   }
	  
	  }
	   
	  if((buf[j-2]==34)||(buf[j-2]==39)) // 특수문자가 연속으로 올 때 한 번 더 없애준다. 특수문자가 연속하는 경우는 따옴표나 쌍따옴표이므로 두개만 예외처리 하였다.
		  buf[j-2]=0;
	  printf("%s\n", buf);
      s = NewNode(buf);                  // 문자를 저장했으면 문자열을 새로운 노드의 멤버로 넘겨준다.
      LinkNode(head,s);                  // 새로운 노드를 연결하는 함수 호출
   }

   fclose(fo);
   
   return head;
}

int search(node* n, char* sear){
   
   int count=0;

   while(n != NULL){
      
      if(strcmp(n->word, sear)==0){
      count+=1;                                // 스트링 비교 후 같으면(strcmp ==0) count가 증가한다.
    }
   n = n->next;
   }
   return count;
}
void indx(node* n, char* sear){

	int a[100];
	int i=0,j;

   while(1){
	   
	   if(strcmp(n->word,sear)==0){
       
		   a[i] = n->index;
		   n = n->next;
		   i++; 
	   }                                              // 스트링 비교 후 같으면 index를 배열에 저장한다.
	   else
		   n = n->next;

	   if(n == NULL)
		   break;
 }
   for(j=0;j<i;j++)
		   printf("검색한 단어의 index = %d \n",a[j]); // index가 저장된 배열을 반복.
}

int main(void){

   int count;
   char sear[20];
   
   node* newnode = LList();
   
   printf("검색할 단어 : ");
   scanf("%s", sear);
   count = search(newnode, sear);
    
    printf("같은 단어 수 : %d \n", count);
	indx(newnode, sear);
	
   return 0;
}

	




