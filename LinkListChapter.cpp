//
//  LinkListChapter.cpp
//  Algorithms
//
//  Created by Jiandong Huang on 13/10/2018.
//  Copyright © 2018 Jiandong Huang. All rights reserved.
//

#include "LinkListChapter.hpp"

void deleteFromLinkedList(struct ListNode *head, int position){
    int k = 0;
    struct ListNode *p, *q;
    p = head;
    if (position == 1) {
        head = p->next;
        return;
    }else{
        while (p != NULL && k < position) {
            q = p;
            p = p->next;
            k++;
        }
        if (p == NULL) {
            printf("position does not exists\n");
        }else{
            q->next = p->next;
        }
    }
}

struct ListNode* ReverseList(struct ListNode* head){
    struct ListNode* temp, *nextNode;
    while (head) {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    return temp;
}
