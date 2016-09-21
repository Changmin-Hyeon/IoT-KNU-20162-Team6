#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


int index[100], cnt=0, indexcnt=0;

//노드 구조
   typedef struct node
   {
      char word[20];	//문자열을 데이터로 저장하는 노드
      struct node *next;
   }node;

//노드 생성   
   node *newnode(char word[20])
   {
      node *newnode = (node*)malloc(sizeof(node));	//node* 변수를 malloc을 이용해 동적메모리 할당
      strcpy(newnode->word, word);					//포인터 이용해 입력변수를 저장
      newnode->next=NULL;
      return newnode;
   }

//노드간 연결
   void Linknode(node* h, node* n)	//새로운 노드가 첫번째 노드일 경우 헤더 노드의 next가 가르키는 주소에 노드 지정
   {
      node* p = h->next;
      if(h->next == NULL)
      {
         h->next = n;
      }
      else
      {
         while(p->next != NULL)		//새로운 노드가 첫번째가 아닐시 각 노드의 next를 타고 마지막 노드의 next가 가르키는 주소에 노드 지정
         {
            p=p->next;
         }
         p->next= n;
      }
   }

   node *Findnode(node* h, char fword[20])	//입력 변수로 node*형 변수와 검색할 단어를 받는다.
   {
      node* p = h->next;
      
      while(1)
      {
         indexcnt++;
         if(strcmp(p->word,fword)==0){
            index[cnt]=indexcnt;
            cnt++;
         }
         if(p->next == NULL) break;
         p=p->next;
      }
   }

   //파일 불러와서 노드 만드는 함수


   node *makenode(void)
   {
	   node* h = (node*)malloc(sizeof(node));	//포인터로 해주지 않을시 함수가 끝난후 메모리가 남아있지 않게 된다.
       node* s;
       int i,k;
	  
       char buf[20], find[20];
       FILE *fileopen;

       h->word[20] = 0;
       h->next = NULL;

       fileopen = fopen("a.txt","rt");

       while(fscanf(fileopen, "%s\n", &buf) != EOF)
       {
	 	  for(i=0; i<sizeof(buf); i++) //for문으로 문자열 전체에 특수문자가 있는지 확인
	 	  {
			  while((buf[i]==33)||(buf[i]==34)||(buf[i]==39)||(buf[i]==44)||(buf[i]==46)||(buf[i]==63)) //특수문자가 없어질때까지 반복
			  {
				  if((buf[i]==33)||(buf[i]==34)||(buf[i]==39)||(buf[i]==44)||(buf[i]==46)||(buf[i]==63)) //특수문자에 널값 넣어서 삭제
	 			  {
					  for(k=i;buf[k]!=0;k++)
						  buf[k]=buf[k+1];
				  };
			  }
		  };
          printf("%s\n",&buf);
          s = newnode(buf);
          Linknode(h,s);
       }
      
       fclose(fileopen);
	   return h;
    }


   //메인함수
   int main()
   {
	   int i;
	   char find[20];

	   node *h=makenode();
	         
       printf("찾을 단어를 입력하시오:");
       scanf("%s", &find);
       Findnode(h, find);
       printf("찾으시는 단어의 개수는 %d입니다.\n", cnt);
       for(i=0; i<cnt; i++)
         printf("index:%d\n", index[i]);
      return 0;
   }