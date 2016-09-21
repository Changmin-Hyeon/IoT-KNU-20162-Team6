#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


int index[100], cnt=0, indexcnt=0;

//��� ����
   typedef struct node
   {
      char word[20];	//���ڿ��� �����ͷ� �����ϴ� ���
      struct node *next;
   }node;

//��� ����   
   node *newnode(char word[20])
   {
      node *newnode = (node*)malloc(sizeof(node));	//node* ������ malloc�� �̿��� �����޸� �Ҵ�
      strcpy(newnode->word, word);					//������ �̿��� �Էº����� ����
      newnode->next=NULL;
      return newnode;
   }

//��尣 ����
   void Linknode(node* h, node* n)	//���ο� ��尡 ù��° ����� ��� ��� ����� next�� ����Ű�� �ּҿ� ��� ����
   {
      node* p = h->next;
      if(h->next == NULL)
      {
         h->next = n;
      }
      else
      {
         while(p->next != NULL)		//���ο� ��尡 ù��°�� �ƴҽ� �� ����� next�� Ÿ�� ������ ����� next�� ����Ű�� �ּҿ� ��� ����
         {
            p=p->next;
         }
         p->next= n;
      }
   }

   node *Findnode(node* h, char fword[20])	//�Է� ������ node*�� ������ �˻��� �ܾ �޴´�.
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

   //���� �ҷ��ͼ� ��� ����� �Լ�


   node *makenode(void)
   {
	   node* h = (node*)malloc(sizeof(node));	//�����ͷ� ������ ������ �Լ��� ������ �޸𸮰� �������� �ʰ� �ȴ�.
       node* s;
       int i,k;
	  
       char buf[20], find[20];
       FILE *fileopen;

       h->word[20] = 0;
       h->next = NULL;

       fileopen = fopen("a.txt","rt");

       while(fscanf(fileopen, "%s\n", &buf) != EOF)
       {
	 	  for(i=0; i<sizeof(buf); i++) //for������ ���ڿ� ��ü�� Ư�����ڰ� �ִ��� Ȯ��
	 	  {
			  while((buf[i]==33)||(buf[i]==34)||(buf[i]==39)||(buf[i]==44)||(buf[i]==46)||(buf[i]==63)) //Ư�����ڰ� ������������ �ݺ�
			  {
				  if((buf[i]==33)||(buf[i]==34)||(buf[i]==39)||(buf[i]==44)||(buf[i]==46)||(buf[i]==63)) //Ư�����ڿ� �ΰ� �־ ����
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


   //�����Լ�
   int main()
   {
	   int i;
	   char find[20];

	   node *h=makenode();
	         
       printf("ã�� �ܾ �Է��Ͻÿ�:");
       scanf("%s", &find);
       Findnode(h, find);
       printf("ã���ô� �ܾ��� ������ %d�Դϴ�.\n", cnt);
       for(i=0; i<cnt; i++)
         printf("index:%d\n", index[i]);
      return 0;
   }