#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *pre;
    struct Node *nxt;
} Node;

int N, M, T, x;
Node *head = NULL;

void myPrint() {
    Node *cur = head;
    while (cur->nxt != NULL) {
        printf("%d ", cur->val);
        cur = cur->nxt;
    }
    printf("%d\n", cur->val);
}

void node_swap(Node *LHS, Node *RHS) {
    if (LHS->pre != NULL) {
        Node *tmp = LHS->pre;
        tmp->nxt = RHS;
        RHS->pre = tmp;
    } else {
        RHS->pre = NULL;
        head = RHS;
    }
    LHS->pre = RHS;
    LHS->nxt = RHS->nxt;
    RHS->nxt = LHS;
    if (LHS->nxt != NULL) {
        LHS->nxt->pre = LHS;
    }
}

int main() {
    scanf("%d %d", &N, &M);

    head = (Node *)malloc(sizeof(Node));
    head->val = 1;
    head->pre = NULL;
    head->nxt = NULL;

    Node *cur = head;
    for (int i = 2; i <= N; i++) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->val = i;
        node->pre = cur;
        node->nxt = NULL;
        cur->nxt = node;
        cur = node;
    }

    while (M--) {
        scanf("%d %d", &T, &x);
        if (T == 0) {
            if (head->val == x) {
                Node *tmp = head;
                head = head->nxt;
                if (head != NULL) head->pre = NULL;
                free(tmp);
            } else {
                cur = head;
                while (cur->nxt != NULL && cur->nxt->val != x) {
                    cur = cur->nxt;
                }
                if (cur->nxt != NULL) {
                    Node *toDel = cur->nxt;
                    cur->nxt = toDel->nxt;
                    if (toDel->nxt != NULL) {
                        toDel->nxt->pre = cur;
                    }
                    free(toDel);
                }
            }
        } else {
            if (head->val != x) {
                cur = head;
                while (cur != NULL && cur->val != x) {
                    cur = cur->nxt;
                }
                if (cur != NULL && cur->pre != NULL) {
                    node_swap(cur->pre, cur);
                }
            }
        }
    }

    myPrint();
    return 0;
}
