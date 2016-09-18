#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


int index[100], cnt=0, indexcnt=0;

//노드 구조
   typedef struct node
   {
      char word[20];
      struct node *next;
   }node;

//노드 생성   
   node *newnode(char word[20])
   {
      node *newnode = (node*)malloc(sizeof(node));
      strcpy(newnode->word, word);
      newnode->next=NULL;
      return newnode;
   }

//노드간 연결
   void Linknode(node* h, node* n)
   {
      node* p = h->next;
      if(h->next == NULL)
      {
         h->next = n;
      }
      else
      {
         while(p->next != NULL)
         {
            p=p->next;
         }
         p->next= n;
      }
   }

   node *Findnode(node* h, char fword[20])
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
	   node* h = (node*)malloc(sizeof(node));
      node* s;
      int i;
	  
      char buf[20], find[20];
      FILE *fileopen;

      h->word[20] = 0;
      h->next = NULL;

      fileopen = fopen("a.txt","rt");

      while(fscanf(fileopen, "%s\n", &buf) != EOF)
      {
		  for(i=0; i<sizeof(buf); i++)
		  {
			  if((buf[i]==33)||(buf[i]==34)||(buf[i]==39)||(buf[i]==44)||(buf[i]==46)||(buf[i]==63)) //특수문자에 널값 넣어서 삭제
			  {
				  buf[i]=NULL;

			  };
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