#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

struct list {
    char fname[30];
    char g1[3];
    char g2[3];
    char g3[3];
    char g4[3];
    list *next;
 } *head, *p, *tail, *pp;

void display(list *list);

int main() {
    int flag, f;
    list *t1, *t2;
    head = tail = new list;
    tail->next = NULL;
    do {
        p = new list;
        scanf("%s", p->fname);
        scanf("%s", p->g1);
        scanf("%s", p->g2);
        scanf("%s", p->g3);
        scanf("%s", p->g4);
        tail->next = p;
        tail = p;
        cout << "Input new node? 1/0\n";
        scanf("%d", &flag);
        
    } while (flag);
    tail->next = NULL;
    display(head->next);
    cout << "\n";
    do {
        f = 0;
        for (p = head; p->next->next; p = p->next) {
            t1 = p->next; t2 = t1->next;
            if (strcmp(t1->fname, t2->fname) > 0) {
                p->next = t2; 
                t1->next = t2->next;
                t2->next = t1;
                f = 1;
            }
        }
    } while (f);
    display(head->next);    
    for (p = head; p; p = pp) {
        pp = p-> next;
        delete(p);
    }
    return 0;
}

void display(list *list) {
    while (list != NULL) {
        printf("First name: %s\tGrades:\t%s, %s, %s, %s\n", list -> fname, list -> g1, list -> g2, list -> g3, list -> g4);
        list = list -> next;
    }
}



// #include <iostream>
// #include <ctime>
// #include <cstdlib>
// #include <cmath>

// using namespace std;

// typedef struct list {
//     char *fname;
//     int g1;
//     int g2;
//     int g3;
//     int g4;
//     struct list *next;
// } t_list;

// t_list *create_node(char *set_fname, int set_g1, int set_g2, int set_g3, int set_g4) {
//     t_list *node = (t_list*)malloc(sizeof(t_list));

//     node -> fname = set_fname;
//     node -> g1 = set_g1;
//     node -> g2 = set_g2;
//     node -> g3 = set_g3;
//     node -> g4 = set_g4;

//     node -> next = NULL;

//     return node;
// }

// t_list sort() {

// }

// void push_front(t_list **list, char *set_fname, int set_g1, int set_g2, int set_g3, int set_g4) {
//     t_list *new_element = create_node(set_fname, set_g1, set_g2, set_g3, set_g4);

//     new_element -> next = *list;
//     *list = new_element;
// }

// void display( struct list *node )
// {
//     for ( ; node != NULL; node = node->next ) printf( "%s ", node->fname );
// }

// int main() {
//     t_list *list = create_node("Ledin", 5, 5, 5, 5);

//     push_front(&list, "Wilson", 4, 4, 5, 4);
//     push_front(&list, "Madison", 5, 4, 5, 5);

//     // while (list != NULL) {
//     //     printf("First name: %s\tGrades:\t%d, %d, %d, %d\n", list -> fname, list -> g1, list -> g2, list -> g3, list -> g4);
//     //     list = list -> next;
//     // }
//     struct list *root = NULL;
//     struct list **tmp = &root;
//     struct list *new_root = NULL;

//     while (root != NULL) {
//         struct list *node = root;
//         root = root -> next;

//         if (new_root == NULL || node -> fname < new_root -> fname) {
//             node -> next = new_root;
//             new_root = node;
//         } else {
//             struct list *current = new_root;
//             while (current -> next != NULL && !(node->fname < current->next->fname)) {                   
//                 current = current -> next;
//             }                
//             node -> next = current -> next;
//             current -> next = node;
//         }
//     }
//     display(list);
//     // while (list != NULL) {
//     //     printf("First name: %s\tGrades:\t%d, %d, %d, %d\n", list -> fname, list -> g1, list -> g2, list -> g3, list -> g4);
//     //     list = list -> next;
//     // }
//     return 0;
// }
// // node = head = tail
// // p = list

// //
// // head = new grades;
//     // head -> next = NULL;
//     // //int *array1 = (int*)malloc(n * sizeof(int));
//     // cout << "Input first names:\n";
//     // int flag;
//     // do {
//     //     p = new grades;
//     //     cin >> p -> fname;
//     //     p -> next = head -> next;
//     //     head -> next = p;
//     //     cout << "New elevent? 1/0 ";
//     //     cin >> flag;
//     // } while (flag);
//     // for (p = head -> next; p; p = p -> next)
//     //     printf("%s\n", p -> fname);
//     // cout << "\nInput grades 1:\n";
//     // do {
//     //     cin >> p -> grade1;  
//     //     p -> next = head -> next;
//     //     head -> next = p;
//     //     cout << "New elevent? 1/0 ";
//     //     cin >> flag;
//     // } while (flag);
//     // for (p = head -> next; p; p = p -> next)
//     //     printf("%d\n", p -> grade1);
//     // delete head;
//     // delete p;
