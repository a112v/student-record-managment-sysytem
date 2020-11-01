#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 50
#define MAX_CODE 10

/*------------------------------------------Global Declaration of all the functions and structures--------------------------------------*/


typedef struct record_node_tag
{
	int roll_no;
	char student_name[MAX_NAME];
	char subject_code[MAX_CODE];
	int marks;
	struct record_node_tag *next;
}record_node;//declaration of structure of node


void insert_lists(record_node **listt1, record_node **listt2);
void delete_lists(record_node **listt1, record_node **listt2);
void insert_stu_rec(record_node **sptr);
record_node* create_node(int rn, char* stu_name, char* sub_code, int marks);
record_node* insert_node(record_node* sptr, int rn, char* stu_name, char* sub_code, int marks);
record_node* insert(record_node* sptr);
record_node* delete_node(record_node* sptr);
record_node* list_unique(record_node *sptr);
void print_diff_records(record_node *sptr, record_node *list1, record_node *list2);
void getnumrecords(record_node *sptr);
void isempty(record_node*);
void isfull(record_node*);
void getmaxmarks(record_node* sptr);
void find_topper(record_node* sptr);
void find_kth_popular_subject(record_node* sptr);
void find_failures(record_node* sptr);
void list_union(record_node **listt1, record_node **listt2, record_node **listt3);
void list_intersection(record_node **listt1, record_node **listt2, record_node **listt3);
void list_difference(record_node** listt1, record_node** listt2, record_node** listt3);
void list_symmetric_difference(record_node **list1, record_node **list2,record_node **list3);
record_node* list_difference_return(record_node* listtt1, record_node* listtt2, record_node* listt3);
record_node* list_union_return(record_node *listt1, record_node *listt2, record_node *listt3);
record_node* mergeself(record_node *lptr,record_node *ptr);
record_node* divide(record_node* lptr);
record_node* list_mergesort(record_node* sptr);

/*----------------------------------------//Global Declaration of all the functions and structures--------------------------------------*/


#endif
