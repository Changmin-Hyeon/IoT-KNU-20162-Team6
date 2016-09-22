#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

   char word[20];       // ���ڿ��� �����ϴ� ����̹Ƿ� char�� �迭�� ����� �־���.
   struct node* next;
   int index;           // ����ü node�� ����� index�� �־���.

}node;  

node* NewNode(char* word1){

   node* n = (node*)malloc(sizeof(node));
   n->next = NULL;
    strcpy(n->word, word1); //�迭�� �ִ� ��Ʈ���� ī���ϴ� �Լ���. ó���� �ܼ� �������� �ߴ��� ���α׷��� �۵����� �ʾҴ�.
    return n;
}

void LinkNode(node* head, node* n){

   node* a = head->next;
   
   if(head->next == NULL){
      head->next = n;
	  n->index = 1;              // ��尡 ������ ���ο� ��带 �����ϰ� �ε��� ��ȣ 1�� �־���.
     
      
   }
   else
   {
       a->index = 1;         

      while(a->next != NULL)  // a ��带 �̿��� n ����� �ڸ��� ��� ����.
      {
         a = a->next;
		
      }
      a->next = n;  
      n->index = a->index+1;  // loop�� ������ �������� �ڸ����� a�� next�� n�� ����Ų��.
              
            
   }    
}


int Error(FILE* fo){             // ��Ʈ���� NULL�� �� ������ �˷��ֱ� ���� ���� �Լ�.

   printf("���Ͽ��� ����\n");
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
      Error(fo);              // Error �Լ� ȣ���� ���� ���� �߻��� ����ڰ� �� �� �ְ� �Ͽ���.
   }
   
   while(fscanf(fo, "%s", buf) != EOF){
     
	   for(i=0;i<sizeof(buf);i++)
	   {
	   if((buf[i]==33)||(buf[i]==34)||(buf[i]==39)||(buf[i]==44)||(buf[i]==46)||(buf[i]==63)) // �ƽ�Ű�ڵ忡�� !"',.? ���� ����
	   {
			  
		   for(j=i;buf[j]!=0;j++)
			   buf[j] = buf[j+1]; //Ư�����ڰ� �ִ� ���� �迭���� Ư�������� �迭�� �־���.  
	   }
	  
	  }
	   
	  if((buf[j-2]==34)||(buf[j-2]==39)) // Ư�����ڰ� �������� �� �� �� �� �� �����ش�. Ư�����ڰ� �����ϴ� ���� ����ǥ�� �ֵ���ǥ�̹Ƿ� �ΰ��� ����ó�� �Ͽ���.
		  buf[j-2]=0;
	  printf("%s\n", buf);
      s = NewNode(buf);                  // ���ڸ� ���������� ���ڿ��� ���ο� ����� ����� �Ѱ��ش�.
      LinkNode(head,s);                  // ���ο� ��带 �����ϴ� �Լ� ȣ��
   }

   fclose(fo);
   
   return head;
}

int search(node* n, char* sear){
   
   int count=0;

   while(n != NULL){
      
      if(strcmp(n->word, sear)==0){
      count+=1;                                // ��Ʈ�� �� �� ������(strcmp ==0) count�� �����Ѵ�.
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
	   }                                              // ��Ʈ�� �� �� ������ index�� �迭�� �����Ѵ�.
	   else
		   n = n->next;

	   if(n == NULL)
		   break;
 }
   for(j=0;j<i;j++)
		   printf("�˻��� �ܾ��� index = %d \n",a[j]); // index�� ����� �迭�� �ݺ�.
}

int main(void){

   int count;
   char sear[20];
   
   node* newnode = LList();
   
   printf("�˻��� �ܾ� : ");
   scanf("%s", sear);
   count = search(newnode, sear);
    
    printf("���� �ܾ� �� : %d \n", count);
	indx(newnode, sear);
	
   return 0;
}

	




