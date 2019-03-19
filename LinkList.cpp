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
    struct DLLNode{
        struct DLLNode *next;
        struct DLLNode *prev;
        int data;
    };
    
    struct CLLNode{
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
    
    void DeleteNodeFromLinkedList(struct ListNode **head, int position){
        int k = 1;
        struct ListNode *Ptmp, *Qtmp;
        if (*head == nullptr) {
            printf("List is Empty\n");
            return;
        }
        Ptmp = *head;
        if (position == 1) {
            *head = (*head)->next;
            free(Ptmp);
            return;
        }else{
            while ((Ptmp != nullptr) && (k < position)) {
                Qtmp = Ptmp;
                Ptmp = Ptmp->next;
                k++;
            }
            if (Ptmp == nullptr) {
                printf("Position is not exist\n");
                return;
            }else{
                Qtmp->next = Ptmp->next;
                free(Ptmp);
            }
        }
    }
    
    void DLLInsert(struct DLLNode **head, int data, int position){
        int k = 1;
        struct DLLNode *temp, *newNode;
        newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
        if (!newNode) {
            printf("Memory Error\n");
            return;
        }
        newNode->data = data;
        if (position == 1) {
            newNode->next = *head;
            newNode->prev = nullptr;
            if (*head) {
                (*head)->prev = newNode;
                *head = newNode;
                return;
            }
        }
        temp = *head;
        while ((k < position) && (temp->next != nullptr)) {
            k++;
            temp = temp->next;
        }
        if (k != position) {
            printf("required position does not exists\n");
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        return;
    }
    
    void DLLDelete(struct DLLNode **head, int position){
        struct DLLNode *temp, *temp2;
        temp = *head;
        int k = 1;
        if (position == 1) {
            *head = (*head)->next;
            if ((*head) != nullptr) {
                (*head)->prev = nullptr;
            }
            free(temp);
            return;
        }else{
            while ((k < position) && (temp->next != nullptr)) {
                temp = temp->next;
                k++;
            }
            if (k != position) {
                printf("Desired position does not exists!\n");
                return;
            }
            temp2 = temp->prev;
            temp2->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = temp2;
            free(temp);
            return;
        }
    }

    
};

