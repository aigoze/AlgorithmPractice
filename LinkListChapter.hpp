//
//  LinkListChapter.hpp
//  Algorithms
//
//  Created by Jiandong Huang on 13/10/2018.
//  Copyright © 2018 Jiandong Huang. All rights reserved.
//

#ifndef LinkListChapter_hpp
#define LinkListChapter_hpp

#include <stdio.h>
struct ListNode{
    int data;
    ListNode *next;
};

void deleteFromLinkedList(struct ListNode *head, int position);

struct ListNode* ReverseList(struct ListNode* head);


#endif /* LinkListChapter_hpp */
