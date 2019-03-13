//
//  LinkList.cpp
//  Algorithms
//
//  Created by Jiandong Huang on 12/3/2019.
//  Copyright © 2019 Jiandong Huang. All rights reserved.
//

#include "LinkList.hpp"
#include <stdlib.h>
class LinkList{
    struct ListNode{
        struct ListNode *next;
        int data;
    };
    void InsertLinkList(struct ListNode **head, int data, int position){
        struct ListNode *newNode, *Ptmp, *Qtmp;
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));//the type is struc ListNode
        if (!newNode) { //Check if mem is allocated
            printf("mem error\n");
            return;
        }
        newNode->data = data;
        Ptmp = *head;
        //if insert from head
        if (position == 1) {
            newNode->next = Ptmp;
            *head = newNode;
        }
        //if insert from others
        int k = 1; //start from 1
        if (position > 1) {
            while ((k < position) && (Ptmp != NULL)) {
                Qtmp = Ptmp;// need to save previous node
                Ptmp = Ptmp->next;
                k++;
            }
            Qtmp->next = newNode; //Qtmp is the previous Ptmp
            newNode->next = Ptmp;
        }
    }

};
