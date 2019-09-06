#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct online
{
    char name[20];
    char usign[1024];
    int icon;
    int cfd;
    struct online* next;
}node;

typedef node* user_t;

void create_node(user_t* new_node)
{
    do {
        *new_node = (user_t)malloc(sizeof(node));
    } while (NULL == (*new_node));
}

void init_link(user_t* head)
{
    create_node(head);

    (*head)->next = NULL;

}

void insert_node(user_t head, user_t new_node)
{
    new_node->next = head->next;

    head->next = new_node;
}

int delete_node(user_t head, int fd)
{
    if (NULL != head->next)
    {
        user_t p, q;
        q = head;
        p = head->next;

        while (p != NULL && p->cfd != fd)
        {
            q = p;
            p = p->next;
        }

        if (p != NULL)
        {
            q->next = p->next;

            free(p);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void remove_link(user_t head)
{
    user_t p = head;

    while (head->next != NULL)
    {
        p = head->next;

        head->next = p->next;

        free(p);
    }
}

void release(user_t* head)
{
    remove_link(*head);

    user_t p = *head;

    *head = NULL;

    free(p);

}

void display(user_t head)
{
    if (NULL != head->next)
    {
        user_t p = head->next;

        while (p)
        {
            printf("fd = %d,name = %s\n", p->cfd,p->name);

            p = p->next;
        }
    }
}

int find_node(user_t head,char* name)
{
    if (head != NULL)
    {
        user_t tmp = head;

        while (tmp != NULL)
        {
            if (strcmp(tmp->name, name) == 0)
            {
                return tmp->cfd;
            }
            tmp = tmp->next;
        }
    }
    return -1;
}


