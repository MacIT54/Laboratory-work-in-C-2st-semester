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
    list *next, *prev;
};

void display(list *list);

int main() {
    int flag;
    list *head, *p, *t, *tail, *pp;
    head = tail = new list, head->next = head->prev = NULL;
    do {
        p = new list;
        //cout << "Input first name:\n";
        scanf("%s", p->fname);
        //cout << "Input 4 grades:\n"
        scanf("%s", p->g1);
        scanf("%s", p->g2);
        scanf("%s", p->g3);
        scanf("%s", p->g4);
        p->next = NULL;
        p->prev = tail;
        tail->next = p;
        tail = p;
        cout << "Input new node? 1/0\n";
        scanf("%d", &flag);
    } while (flag);
    cout << "\nList before processing\n";
    display(head->next);
    for (p = head->next; p->next; p = p->next) {
        if (p->g1[0] == '2' || p->g2[0] == '2' || p->g3[0] == '2' || p->g4[0] == '2') {
            t = p;
            t->next->prev = t->prev;
            t->prev->next = t->next;
            delete(t);
        } 
    }
    cout << "\nList after processing\n";
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













//else if (p->g2[0] == '2') {
        //     t = p;
        //     t->next->prev = t->prev;
        //     t->prev->next = t->next;
        //     delete(t);
        // } else if (p->g3[0] == '2') {
        //     t = p;
        //     t->next->prev = t->prev;
        //     t->prev->next = t->next;
        //     delete(t);
        // } else if (p->g4[0] == '2') {
        //     t = p;
        //     t->next->prev = t->prev;
        //     t->prev->next = t->next;
        //     delete(t);
        // }