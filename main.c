#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct  node *link;
};
struct node *first, *prev, *tmp,*curr, *pos;

void createnode();
void display();
void insert_first();
void insert_last();
void insert_before_pos();
void insert_after_pos();
void deleteNode();
void delete_last();
void reverse();
void count();
void remove_dup();
void del_3nodes();
void del_alter();
int i,n;

int main()
{
        while(1)
        {
                   printf("\n1.creade\n2.display\n3.insert_first\n4.insert_last\n5.deleteNode\n6.delete_last\n7.insert_before_pos\n8.insert_after_pos\n9.reverse\n10.total_nodes\n11.remove_dup\n12.del_3nodes\n13.delete_alternate\n14.exit\n\n");
                   scanf("%d",&n);

           switch (n)
                {
                  case 1:
                  createnode(n);
                  break;

                  case 2:
                  display();
                  break;

                  case 3:
                  insert_first();
                  break;

                  case 4:
                  insert_last();
                  break;

                  case 5:
                  deleteNode();
                  break;

                  case 6:
                  delete_last();
                  break;

                  case 7:
                  insert_before_pos();
                  break;

                  case 8:
                  insert_after_pos();
                  break;

                  case 9:
                  reverse();
                  break;

                  case 10:
                  count();
                  break;

                  case 11:
                  remove_dup();
                  break;

                  case 12:
                  del_3nodes();
                  break;

                  case 13:
                  del_alter();
                  break;

                  case 14:
                  return 0;
                  break;
                }
        }
}
void createnode()
{
         tmp=(struct node *)malloc(sizeof(struct node));
         printf("enter data for node\n");
         scanf("%d",&(tmp->data));
         tmp->link=NULL;

                 if(first==NULL)
                     {
                         first=prev=tmp;
                     }

                 else
                     {
                        prev->link=tmp;
                        prev=tmp;
                     }

}

void display()
{
         tmp=first;
         while(tmp!=NULL)
            {
                printf("%d-->",tmp->data);
                tmp=tmp->link;
            }
}


void insert_first()
{
        tmp=(struct node *)malloc(sizeof(struct node));
        printf("enter data:\n");
        scanf("%d",&tmp->data);
        tmp->link=first;
        first=tmp;
}


void insert_last()
{
        tmp=(struct node *)malloc(sizeof(struct node));
        printf("enter data to insert after last node\n");
        scanf("%d",&tmp->data);
        while(prev->link!=NULL)
            {
                prev=prev->link;
            }

                prev->link=tmp;
                tmp->link=NULL;

}

void deleteNode()
{
        curr=prev=first;
        printf("enter position to delete\n");
        scanf("%d",&n);
        if(n==1)
           {
                curr=curr->link;
                first=curr;
                free(prev);
           }

        else
          {
                for(i=1;i<n-1;i++)
                   {
                        prev=prev->link;
                   }
                        curr=prev->link;
                        prev->link=curr->link;
                        free(curr);
         }
}

void delete_last()
{
        curr=prev=first;
        while(curr->link!=NULL)
          {
                prev=curr;
                curr=curr->link;
          }
                prev->link=NULL;
                free(curr);
}

void insert_before_pos()
{
        prev=curr=first;
        tmp=(struct node *)malloc(sizeof(struct node));
        printf("enter position\n");
        scanf("%d", &n);

        printf("enter value to insert\n");
        scanf("%d", &tmp->data);
        printf("%d", tmp->data);
        for(i=1;i<n-1;i++)
          {
                prev=prev->link;
          }
                curr=prev->link;
                prev->link=tmp;
                tmp->link=curr;
}

void insert_after_pos()
{
        prev=curr=first;
        tmp=(struct node *)malloc(sizeof(struct node));
        printf("enter position\n");
        scanf("%d", &n);

        printf("enter value\n");
        scanf("%d",&tmp->data);
        for(i=1;i<n;i++)
          {
                prev=prev->link;
          }
                curr=prev->link;
                prev->link=tmp;
                tmp->link=curr;
}

void reverse()
{
        curr=NULL;
        while(first!=NULL)
          {
                tmp=first;
                first=first->link;
                tmp->link=curr;
                curr=tmp;
          }
                first=curr;
}


void count()
{
        int count=0;
        tmp=first;
        while(tmp!=NULL)
          {
                count++;
                tmp=tmp->link;
          }
        printf("no of nodes=%d\n",count);
}


void remove_dup()
{
        prev=tmp=curr=first;
        while(tmp->link!=NULL)
          {
                curr=tmp->link;
                while(curr!=NULL)
                  {
                     if(tmp->data==curr->data)
                        {
                           prev->link=curr->link;
                           curr->link=NULL;
                           free(curr);
                           curr=prev->link;
                        }
                        else
                        {
                                prev=curr;
                                curr=curr->link;
                        }
                  }
                tmp=tmp->link;
          }
}

void del_alter()
{
        prev=curr=first;
        printf("enter position\n");
        scanf("%d", &n);
        for(i=1;i<n;i++)
        {
                 prev=prev->link;
                 curr=prev->link;
        }
        while(prev->link!=NULL)
        {
                prev->link=curr->link;
                free(curr);
                prev=prev->link;
                curr=prev->link;
        }
}


void del_3nodes()
{
        prev=curr=first;
        printf("enter position:\n");
        scanf("%d",&n);

        for(i=1;i<n;i++)
          {
                prev=prev->link;
                curr=prev->link;
          }

        for(i=1;i<=3;i++)
          {
                prev->link=curr->link;
                free(curr);
                curr=prev->link;
          }
}
