#include "head.h"

/*------------------------------------------------DECLARATIONS OF FUNCTIONS-------------------------------------------------------------*/

		
/*------------------------------------------------------INSERTLISTS FUNCTION------------------------------------------------------------*/

void insert_lists(record_node **listt1, record_node **listt2)
{
	char stu_name[MAX_NAME],sub_code [MAX_CODE];
	int marks,rollno;
	char conti='y',contlist;
	printf("Do you want to insert into LIST1?[y/n]\n");
	getchar();
	contlist=getchar();
	if(contlist=='y' || contlist=='Y')
	{
		printf("ENTER LIST1\n");
		while(conti =='y'|| conti=='Y')
		{
			printf("\nEnter the  elements into LIST1\n\n");
			printf("Enter Roll No. of Student\n");
			scanf("%d",&rollno);
			printf("Enter Student name\n");
			scanf("%s",stu_name);
			printf("Enter Subject Code\n");
			scanf("%s",sub_code);
			printf("Enter Marks Obtained\n");
			scanf("%d",&marks);
			*listt1=insert_node(*listt1,rollno,stu_name,sub_code,marks);
			printf("Do you want to add another student[y/n]?");
			fflush(stdin);
			getchar();
			conti= getchar();printf("\n\n");
		}
	}
	printf("Do you want to insert into LIST2?[y/n]\n");
	getchar();
	contlist=getchar();
	if(contlist=='y' || contlist=='Y')
	{
	 	printf("\n\nENTER LIST2\n");
	 	conti='y';
	 	while(conti =='y'|| conti=='Y')
		{
			printf("\nEnter the  elements into LIST2\n\n");
			printf("Enter Roll No. of Student\n");
			scanf("%d",&rollno);
			printf("Enter Student name\n");
			scanf("%s",stu_name);
			printf("Enter Subject Code\n");
			scanf("%s",sub_code);
			printf("Enter Marks Obtained\n");
			scanf("%d",&marks);
			*listt2=insert_node(*listt2,rollno,stu_name,sub_code,marks);
			printf("Do you want to add another student[y/n]?");
			fflush(stdin);
			getchar();
			conti= getchar();printf("\n\n");
		}
	}
	*listt1=list_unique(*listt1);
	*listt2=list_unique(*listt2);
	*listt1=list_mergesort(*listt1);
	*listt2=list_mergesort(*listt2);
}

/*------------------------------------------------------DELETELISTS FUNCTION------------------------------------------------------------*/

void delete_lists(record_node **listt1, record_node **listt2)
{
	record_node *trvlist1, *trvlist2;
	int option;
	char choice='y';
	while(choice=='y' || choice=='Y')
   	{
   		printf("\nSELECT the Record which is to be DELETED\n");
      		printf("\n1.LIST1\n");
      		printf("\n2.LIST2\n");
      		printf("\n!!!!!!!!!!!!!ENTER YOUR CHOICE!!!!!!!!!!!!!!!!\n");
      		scanf("%d",&option);
		switch(option)
	      	{
	    		case 1:
			{
				if(*listt1!=NULL)
				{
					trvlist1=*listt1;
					for(;trvlist1!=NULL;)
					{
						trvlist1=trvlist1->next;
						free(*listt1);
						*listt1=trvlist1;
					}
					printf("Coplete LIST1 deleted successfully!!");
				}
				else
				printf("The list is Already Empty");				
			}
			break;
			case 2:
			{
				if(*listt2 != NULL)
				{
					trvlist2=*listt2;
					for(;trvlist2!=NULL;)
					{
						trvlist2=trvlist2->next;
						free(*listt2);
						*listt2=trvlist2;
					}
					printf("Coplete LIST2 deleted successfully!!");
				}
				else
				printf("The list is Already Empty");
			}
			break;
			default:break;
		}
		printf("\nDo you want to DELETE another list[y/n]?\n");
		fflush(stdin);
		getchar();
		choice= getchar();	
	}
}

/*-----------------------------------------------------GET_STU_REC FUNCTION--------------------------------------------------------------*/

void insert_stu_rec(record_node **sptr)
{
	char stu_name[MAX_NAME],sub_code [MAX_CODE];
	int marks,rollno;
	char conti='y';
	while(conti =='y'|| conti=='Y')
	{
		printf("\nEnter the  elements into student record\n\n");
		printf("Enter Roll No. of Student\n");
		scanf("%d",&rollno);
                printf("Enter Student name\n");
		scanf("%s",stu_name);
                printf("Enter Subject Code\n");
		scanf("%s",sub_code);
                printf("Enter Marks Obtained\n");
		scanf("%d",&marks);
		*sptr=insert_node(*sptr,rollno,stu_name,sub_code,marks);
		printf("Do you want to add another student[y/n]?");
		fflush(stdin);
		getchar();
		conti= getchar();printf("\n\n");
	}
	*sptr=list_unique(*sptr);
	*sptr=list_mergesort(*sptr);
}



/*-----------------------------------------------PRINT_RECORD FUNCTION------------------------------------------------------------------*/

void print_record(record_node *sptr)
{
	record_node *tptr;
	tptr=sptr;
	while(tptr!=NULL)//printing the record
	{
		printf("\n----ROLL NO----\t----NAME----\t----SUBJECT----\t----MARKS----\n\n");
		printf("      %d               %s            %s               %d       \n",tptr->roll_no,tptr->student_name,tptr->subject_code,tptr->marks);
		tptr=tptr->next;
	}
}



/*-----------------------------------------------CREATE AND INSERT NODE FUNCTION--------------------------------------------------------*/

record_node* create_node(int rn, char* stu_name, char* sub_code, int marks)
{
	record_node *nptr;
	nptr=(record_node*)malloc(sizeof(record_node));
	nptr->roll_no=rn;
	strcpy(nptr->student_name,stu_name);
	strcpy(nptr->subject_code,sub_code);
	nptr->marks=marks;
	nptr->next=NULL;
	return nptr;
}

record_node* insert_node(record_node* sptr, int rn, char* stu_name, char* sub_code, int marks)
{
	record_node* eptr,*nptr;eptr=sptr;int flag=0;
	nptr=create_node(rn, stu_name, sub_code, marks);
	printf("%d",nptr->roll_no);
	printf("%s",nptr->student_name);
	if(sptr ==NULL)
	{
		sptr=nptr;flag=1;
	}
	else
	{
		nptr->next=sptr;
		sptr=nptr;flag=2;
	}
	if(flag==1)
	printf("INSERTED\n\n");
	else
	printf("INSERTED2\n\n");
	return sptr;
}

/*-----------------------------------------------------INSERT FUNCTION------------------------------------------------------------------*/


record_node* insert(record_node* sptr)
{
	record_node* tptr;int flag=0;
	int rollno;
	char stu_name[MAX_NAME],sub_code [MAX_CODE];
	int marks;
	printf("\nEnter the  elements which you want to INSERT into student record\n\n");
	printf("Enter Roll No. of Student\n");
	scanf("%d",&rollno);
        printf("Enter Student name\n");
	scanf("%s",stu_name);
        printf("Enter Subject Code\n");
	scanf("%s",sub_code);
        printf("Enter Marks Obtained\n");
	scanf("%d",&marks);
	tptr=sptr;
	while(tptr!=NULL && flag==0)
	{
		if(tptr->roll_no ==rollno && strcmp(tptr->subject_code,sub_code)==0)
		flag=1;
		else
		tptr=tptr->next;
	}
	if(tptr == NULL)
	{
		sptr=insert_node(sptr,rollno,stu_name,sub_code,marks);
		printf("\nRecord inserted successfully\n");
	}
	else
	{
		strcpy(tptr->student_name, stu_name);
		tptr->marks=marks;
		printf("\nRecord updated successfully\n");
	}
	/*printf("SPTR:\n\n");
	print_record(sptr);*/
	return sptr;
}

/*----------------------------------------------------DELETE FUNCTION-------------------------------------------------------------------*/


record_node* delete_node(record_node* sptr)
{
	record_node* tptr, *prevptr, *delptr=NULL;int flag=0,noi=0;
	int rollno;
	char sub_code [MAX_CODE];
	printf("\nEnter the roll no and sub_code of student whose record is to be deleted\n\n");
	printf("Enter Roll No. of Student\n");
	scanf("%d",&rollno);
        printf("Enter Subject Code\n");//input from user about which node to be deleted
	scanf("%s",sub_code);
	tptr=sptr;prevptr=tptr;
	while(tptr!=NULL && flag==0)
	{
		if(tptr->roll_no ==rollno && strcmp(tptr->subject_code,sub_code)==0)//finding the node to be deleted
		flag=1;
		else
		{
			prevptr=tptr;//incrementing the nodes
			tptr=tptr->next;
		}
		noi++;
	}
	if(tptr != NULL && noi==1)//checking whether node to be deleted is first node?
	{//printf("HI AM HERE");
		delptr=sptr;
		sptr=sptr->next;
		free(delptr);
	}
	if(tptr != NULL && noi!=1)
	{
		prevptr->next=tptr->next;
		free(tptr);
	}
	return sptr;
}



/*----------------------------------------------PRINT_DIFF_RECORDS FUNCTION-------------------------------------------------------------*/

void print_diff_records(record_node *sptr, record_node *list1, record_node *list2)
{
	int option;record_node  *tptr;
	char choice='y';
	while(choice=='y' || choice=='Y')
   	{
   		printf("\nSELECT the Record which is to be PRINTED\n");
      		printf("\n1.STUDENT RECORD\n");
      		printf("\n2.LIST1\n");
      		printf("\n3.LIST2\n");
      		printf("\n!!!!!!!!!!!!!ENTER YOUR CHOICE!!!!!!!!!!!!!!!!\n");
      		scanf("%d",&option);
		switch(option)
	      	{
	    		case 1:
			{
				tptr=sptr;
				if(tptr != NULL)
				{
					printf("\nSTUDENT RECORD:\n");
					while(tptr!=NULL)//printing the record
					{
					printf("\n----ROLL NO----\t----NAME----\t----SUBJECT----\t----MARKS----\n\n");
					printf("      %d               %s            %s               %d       \n",tptr->roll_no,
					tptr->student_name,tptr->subject_code,tptr->marks);
					tptr=tptr->next;
					}
				}
				else
				{
					printf("Record Empty!!");
				}
			}
			break;
	    		case 2:
			{
				tptr=list1;
				if(tptr != NULL)
				{
					printf("\nLIST1:\n");
					while(tptr!=NULL)//printing the record
					{
					printf("\n----ROLL NO----\t----NAME----\t----SUBJECT----\t----MARKS----\n\n");
					printf("      %d               %s            %s               %d       \n",tptr->roll_no,
					tptr->student_name,tptr->subject_code,tptr->marks);
					tptr=tptr->next;
					}
				}
				else
				{
					printf("Record Empty!!");
				}
			}
			break;
			case 3:
			{
				tptr=list2;
				if(tptr != NULL)
				{
					printf("\nLIST2:\n");
					while(tptr!=NULL)//printing the record
					{
					printf("\n----ROLL NO----\t----NAME----\t----SUBJECT----\t----MARKS----\n\n");
					printf("      %d               %s            %s               %d       \n",tptr->roll_no,
					tptr->student_name,tptr->subject_code,tptr->marks);
					tptr=tptr->next;
					}
				}
				else
				{
					printf("Record Empty!!");
				}
			}
			break;
			default:break;
		}
		printf("\nDo you want to PRINT another list[y/n]?\n");
		fflush(stdin);
		getchar();
		choice= getchar();
	}
}



/*-----------------------------------------------GETNUMRECORDS FUNCTION-----------------------------------------------------------------*/

void getnumrecords(record_node *sptr)
{
	record_node *tptr;
	tptr=sptr;int count=0;
	while(tptr!=NULL)
	{
		count++;//counting no of records
		tptr=tptr->next;
	}
	printf("The student record contains %d number of students\n",count);
}


/*-----------------------------------------------------ISEMPTY FUNCTION-----------------------------------------------------------------*/
void isempty(record_node *sptr)
{
	if(sptr==NULL)
	{
		printf("\nThe student record IS EMPTY\n");
	}
	else
	{
		printf("\nThe student record IS NOT EMPTY\n");
	}
}

/*-----------------------------------------------------ISFULL FUNCTION------------------------------------------------------------------*/

void isfull(record_node *sptr)
{
	printf("\nThe RECORD is NOT FULL\n");//as linked lis is used for implementation thus record will never be full
}


/*-----------------------------------------------------GETMAXMARKS FUNCTION-------------------------------------------------------------*/

void  getmaxmarks(record_node* sptr)
{
	record_node *tptr, *maxptr, *addptr;
	int max;char sub[MAX_CODE];
	tptr=sptr;
	max=0;maxptr=NULL;
	printf("Enter the subject code in which you want to find max marks:");
	scanf("%s",sub);
	while(tptr!=NULL)
	{
		if(strcmp(tptr->subject_code,sub)==0 && tptr->marks>max)
		{
			max=tptr->marks;
		}//max contains max marks obtained in that subject
		tptr=tptr->next;
	}
	printf("%d",max);
	tptr=sptr;
	while(tptr!=NULL)
	{
		if(strcmp(tptr->subject_code,sub)==0 && tptr->marks==max && maxptr==NULL)//if max arks are found then maxptr is initialised
		{
			maxptr=(record_node*)malloc(sizeof(record_node));
			maxptr->roll_no=tptr->roll_no;
			strcpy(maxptr->student_name,tptr->student_name);
			strcpy(maxptr->subject_code,tptr->subject_code);
			maxptr->marks=tptr->marks;
		}
		else if(strcmp(tptr->subject_code,sub)==0 && tptr->marks==max && maxptr!=NULL)
		{
			addptr=(record_node*)malloc(sizeof(record_node));
			addptr->roll_no=tptr->roll_no;
			strcpy(addptr->student_name,tptr->student_name);
			strcpy(addptr->subject_code,tptr->subject_code);
			addptr->marks=tptr->marks;
			addptr->next=maxptr;
			maxptr=addptr;
		}//if another stu with max marks is found then maxptr is incremented with that student
		tptr=tptr->next;
	}
	printf("\nThe MAXIMUM MARKS obtained in SUBJECT %s are %d and are obtained by:\n",sub,max);
	list_mergesort(maxptr);//sorting the max list
	print_record(maxptr);//record containing maxptr is printed
}

/*----------------------------------------------------FINDTOPPER FUNCTION---------------------------------------------------------------*/

void find_topper(record_node* sptr)
{
	record_node *tptr, *pptr ,*topper;
	tptr=sptr;int max=0,total;
	pptr=sptr;
	topper=(record_node*)malloc(sizeof(record_node));
	for(;tptr!=NULL;tptr=tptr->next)
	{	
		total=0;
		for(pptr=sptr;pptr!=NULL;pptr=pptr->next)
		{
			if(pptr->roll_no==tptr->roll_no)
			{
				total+=pptr->marks;
			}
		}//finding total marks obtained by each student
		if(total>max)
		{
			max=total;
			topper->roll_no=tptr->roll_no;
			strcpy(topper->student_name,tptr->student_name);
			strcpy(topper->subject_code,tptr->subject_code);
			topper->marks=max;
			topper->next=NULL;	
		}//checking if that total marks are maximum and if that person is topper
	}
	printf("\nTopper is: %s and has obtained %d total marks\n", topper->student_name,max);
	print_record(topper);
}

/*---------------------------------------------------SORTNG POPULAR SUBJECTS------------------------------------------------------------*/

typedef struct popular_sub_tag
	{
		char subject_code[MAX_CODE];
		int avg_marks;
		struct popular_sub_tag *next;
	}pop_sub;
	
pop_sub* divide_popsub(pop_sub* lptr)
{
	pop_sub *fast ,*slow;
	slow=lptr;
	fast=lptr->next->next;
	pop_sub * temp;
	while(fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
		}
	}
	temp=slow->next;
	slow->next=NULL;
	return temp;
}
pop_sub* mergeself_popsub(pop_sub *lptr,pop_sub *ptr)
{
	pop_sub *p,*q,*head,*r;
	p=lptr;
	q=ptr;
	if(p==NULL)
	{
		head=q;
	}
	else if (q==NULL)
	{
		head=p;
	}
	else
	{
		if(p->avg_marks >q->avg_marks)
		{
			head=p;
			p=p->next;
		}
		else
		{
			head=q;
			q=q->next;
		}
		r=head;
		while((p!=NULL) && (q!=NULL))
		{
			if(p->avg_marks > q->avg_marks)
			{
				r->next=p;
				p=p->next;
				r=r->next;
			}
			else
			{
				r->next=q;
				r=r->next;
				q=q->next;
			}
		}
		if(p!=NULL)
		{
			r->next=p;
		}
		else
		{
			r->next=q;
		}
	}
	return head;
}	

	
	
pop_sub* list_mergesort_popsub(pop_sub* sptr)
{
	pop_sub *ptr,*head,*tptr;
	tptr=sptr;head=sptr;
	if(tptr!=NULL && tptr->next!=NULL)
	{
		ptr=divide_popsub(tptr);	//divide 
		tptr=list_mergesort_popsub(tptr);	//sort first half
		ptr=list_mergesort_popsub(ptr);	//sort second half
		head=mergeself_popsub(tptr,ptr);
	}
	return head;
}

	

/*------------------------------------------------FINDKthPOPULARSUBJECT FUNCTION--------------------------------------------------------*/

void find_kth_popular_subject(record_node* sptr)
{
	record_node *tptr, *pptr;
	pop_sub *nptr=NULL,*crptr,*ppptr,*ttptr,*prevptr,*delptr;
	int k,div,count=0,total;
	printf("\nEnter the value of k:\n");
	scanf("%d",&k);
	tptr=sptr;pptr=sptr;
	for(;tptr!=NULL;tptr=tptr->next)
	{
		total=0;div=0;
		for(pptr=sptr;pptr!=NULL;pptr=pptr->next)
		{
			if(strcmp(pptr->subject_code,tptr->subject_code)==0)
			{
					crptr=(pop_sub*)malloc(sizeof(pop_sub));
					total+=pptr->marks;
					crptr->avg_marks=total;
					strcpy(crptr->subject_code,pptr->subject_code);
					div++;
			}
		}
		if(nptr==NULL)
		{
			crptr->avg_marks=crptr->avg_marks/div;
			nptr=crptr;
		}
		else
		{
			crptr->avg_marks=crptr->avg_marks/div;
			crptr->next=nptr;
			nptr=crptr;
		}
	}
	crptr=nptr;
	ppptr=nptr;ttptr=NULL;
	for(;ppptr!=NULL;ppptr=ppptr->next)
	{	
		prevptr=ppptr;
		for(ttptr=ppptr->next;ttptr!=NULL;)
		{
			if(ttptr->avg_marks ==ppptr->avg_marks && strcmp(ttptr->subject_code,ppptr->subject_code)==0)
			{
					prevptr->next=ttptr->next;
					delptr=ttptr;
					ttptr=ttptr->next;
					free(delptr);
			}
			else
			{
				prevptr=ttptr;
				ttptr=ttptr->next;
			}
		}
	}
	while(crptr!=NULL)
	{
	printf("Subject code is:     %s     Avg Marks are     %d\n",crptr->subject_code,crptr->avg_marks);crptr=crptr->next;}
	nptr=list_mergesort_popsub(nptr);
	
	crptr=nptr;printf("AFTER MERGESORT\n\n");
	while(crptr!=NULL)
	{
	printf("Subject code is:     %s     Avg Marks are     %d\n",crptr->subject_code,crptr->avg_marks);crptr=crptr->next;}
	crptr=nptr;printf("\n\n");
	pop_sub *trvptr=nptr;int countnn=0;
	while(trvptr!=NULL)
	{
		countnn++;
		trvptr=trvptr->next;
	}
	//printf("countnn is %d",countnn);
	trvptr=nptr;
	if(k<=countnn)
	{
		while(count!=k-1 && trvptr!=NULL)
		{
			trvptr=trvptr->next;
			count++;
		}
		printf("The Kth popular subject is %s  and the avg_marks are %d \n",trvptr->subject_code, trvptr->avg_marks);
	}
	else
	{
		printf("Please enter a valid k!!\n");
	}
	/*while(nptr!=NULL)
	{
	printf("Subject code is:     %s     Avg Marks are     %d\n",nptr->subject_code,nptr->avg_marks);nptr=nptr->next;}*/
}

/*-----------------------------------------------------FINDFAILURES FUNCTION------------------------------------------------------------*/


void find_failures(record_node *sptr)
{
	typedef struct failures_tag
	{
		int rollno;
		int count;
		char student_name[MAX_NAME];
		struct failures_tag *next;
	}failures;
	record_node *tptr, *pptr;
	failures *fail,*failptr=NULL;
	int p,k,count;
	pptr=sptr;tptr=sptr;
	printf("Enter the cutoff marks for passing:\n");
        scanf("%d",&p);
        printf("Enter the minimum no. of subjects the student needs to pass:\n");
        scanf("%d",&k);
        for(;tptr!=NULL;tptr=tptr->next)
	{	
		count=0;
		for(pptr=sptr;pptr!=NULL;pptr=pptr->next)
		{
			if(strcmp(pptr->student_name,tptr->student_name)==0)
			{
				if(pptr->marks<p)
				count++;
			}
		}
		if(count>=k)
		{
			fail=(failures*)malloc(sizeof(failures));
			fail->rollno=tptr->roll_no;
			strcpy(fail->student_name,tptr->student_name);
			fail->count=count;
			fail->next=NULL;	
		}
		if(failptr == NULL)
		{
			failptr=fail;
		}
		else
		{
			fail->next=failptr;
			failptr=fail;
		}
	}
	printf("The students who have FAILED are:\n");
	while(failptr!=NULL)
	{
		printf("\n----ROLL NO----\t----NAME----\t----NO OF FAILED SUBJECTS----\n\n");
		printf("      %d               %s            %d       \n",failptr->rollno,failptr->student_name,failptr->count);
		failptr=failptr->next;
	}
 }
 
/*------------------------------------------------------LISTUNIQUE FUNCTION---------------------------------------------------------------*/

record_node* list_unique(record_node *sptr)
{
	record_node *tptr, *pptr, *prevptr, *delptr;int flag=0;
	pptr=sptr;tptr=NULL;
	for(;pptr!=NULL;pptr=pptr->next)
	{	
		flag=0;
		prevptr=pptr;
		for(tptr=pptr->next;tptr!=NULL;)
		{
			if(tptr->roll_no ==pptr->roll_no && strcmp(tptr->subject_code,pptr->subject_code)==0)
			{
					prevptr->next=tptr->next;
					delptr=tptr;
					tptr=tptr->next;
					free(delptr);
			}
			else
			{
				prevptr=tptr;
				tptr=tptr->next;
			}
		}
	}
	sptr=list_mergesort(sptr);
	return sptr;
}

/*----------------------------------------------------LISTUNION FUNCTION----------------------------------------------------------------*/

void list_union(record_node **listt1, record_node **listt2, record_node **listt3)
{
	record_node *cplist1, *cplist2, *toadd, *trvlist1, *trvlist2;
	cplist1=NULL;
	cplist2=NULL;
	for(trvlist1=*listt1;trvlist1!=NULL;trvlist1=trvlist1->next)
	{
		toadd=(record_node*)malloc(sizeof(record_node));
		toadd->roll_no=trvlist1->roll_no;
		strcpy(toadd->student_name,trvlist1->student_name);
		strcpy(toadd->subject_code,trvlist1->subject_code);
		toadd->marks=trvlist1->marks;	
		toadd->next=NULL;
		if(cplist1==NULL && toadd!=NULL)
		{
			cplist1=toadd;
		}
		else if(cplist1!=NULL && toadd!=NULL)
		{
			toadd->next=cplist1;
			cplist1=toadd;
		}
	}//creating a copy of list1
	for(trvlist2=*listt2;trvlist2!=NULL;trvlist2=trvlist2->next)
	{
		toadd=(record_node*)malloc(sizeof(record_node));
		toadd->roll_no=trvlist2->roll_no;
		strcpy(toadd->student_name,trvlist2->student_name);
		strcpy(toadd->subject_code,trvlist2->subject_code);
		toadd->marks=trvlist2->marks;	
		toadd->next=NULL;
		if(cplist2==NULL && toadd!=NULL)
		{
			cplist2=toadd;
		}
		else if(cplist2!=NULL && toadd!=NULL)
		{
			toadd->next=cplist2;
			cplist2=toadd;
		}
	}//copy of list2
	//Cheking for various conditiions of both the lists for finding union
	if(cplist1 ==NULL && cplist2 ==NULL)
	{
		*listt3=NULL;
	}
	else if(cplist1 ==NULL && cplist2 !=NULL)
	{
		*listt3=cplist2;
		trvlist2=cplist1;
	  	for(;trvlist2!=NULL;)
		{
			trvlist2=trvlist2->next;
			free(cplist1);
			cplist1=trvlist2;
	  	}
	}
	else if(cplist1 !=NULL && cplist2 ==NULL)
	{
		*listt3=cplist1;
		trvlist2=cplist2;
	  	for(;trvlist2!=NULL;)
		{
			trvlist2=trvlist2->next;
			free(cplist2);
			cplist1=trvlist2;
	  	}
	}
	//if any of the list is NULL then liist3 just becomes the list which is not NULL else remains NULL
	else if(cplist1 !=NULL && cplist2 !=NULL)
	{
		trvlist1=cplist1;
		while(trvlist1->next!=NULL)
		{
			trvlist1=trvlist1->next;
		}
		trvlist1->next=cplist2;
		*listt3=cplist1;cplist1=NULL;
	}//if both are not NULL then the second list is attached to first and then unique operated on it
	*listt3=list_unique(*listt3);
	*listt3=list_mergesort(*listt3);
	//After applying unique and mergesort list is ready
	printf("The LIST1 is:\n");
	print_record(*listt1);
	printf("\n\n\n");
	printf("The LIST2 is:\n");
	print_record(*listt2);
	printf("\n\n\n");
	printf("\nTHE UNION OF LIST1 AND LIST2 IS:\n\n");
	if(*listt3 !=NULL)
	print_record(*listt3);
	else
	printf("NO LISTS found!!\n");
	//freeing the created lists in the function
	trvlist2=*listt3;
	for(;trvlist2!=NULL;)
	{
		trvlist2=trvlist2->next;
		free(*listt3);
		*listt3=trvlist2;
  	}
  	/*printf("AFTER FREE The CPLIST1 is:\n");
	print_record(cplist1);
	printf("The CPLIST2 is:\n");
	print_record(cplist1);
	printf("The LIST3 is:\n");
	print_record(*listt3);*/
  	*listt3=NULL;
}

/*---------------------------------------------------LISTUNIONRETURN FUNCTION------------------------------------------------------------*/

record_node* list_union_return(record_node *listt1, record_node *listt2, record_node *listt3)
{
	record_node *trvlist1, *trvlist2;
	trvlist1=listt1;
	trvlist2=listt2;
	if(trvlist1 ==NULL && trvlist2 ==NULL)
	{
		listt3=NULL;
	}
	else if(trvlist1 ==NULL && trvlist2 !=NULL)
	{
		listt3=trvlist2;
	}
	else if(trvlist1 !=NULL && trvlist2 ==NULL)
	{
		listt3=trvlist1;
	}
	else
	{
		while(trvlist1->next!=NULL)
		{
			trvlist1=trvlist1->next;
		}
		trvlist1->next=listt2;
		listt3=listt1;
	}
	listt3=list_unique(listt3);
	listt3=list_mergesort(listt3);
	return listt3;
}
/*---------------------------------------------------LISTINTERSECTION FUNCTION----------------------------------------------------------*/

void list_intersection(record_node **listt1, record_node **listt2, record_node **listt3)
{
	record_node *cplist1, *cplist2, *toadd, *trvlist1, *trvlist2;
	cplist1=NULL;
	cplist2=NULL;
	for(trvlist1=*listt1;trvlist1!=NULL;trvlist1=trvlist1->next)
	{
		toadd=(record_node*)malloc(sizeof(record_node));
		toadd->roll_no=trvlist1->roll_no;
		strcpy(toadd->student_name,trvlist1->student_name);
		strcpy(toadd->subject_code,trvlist1->subject_code);
		toadd->marks=trvlist1->marks;	
		toadd->next=NULL;
		if(cplist1==NULL && toadd!=NULL)
		{
			cplist1=toadd;
		}
		else if(cplist1!=NULL && toadd!=NULL)
		{
			toadd->next=cplist1;
			cplist1=toadd;
		}
	}//creating a copy of list1
	for(trvlist2=*listt2;trvlist2!=NULL;trvlist2=trvlist2->next)
	{
		toadd=(record_node*)malloc(sizeof(record_node));
		toadd->roll_no=trvlist2->roll_no;
		strcpy(toadd->student_name,trvlist2->student_name);
		strcpy(toadd->subject_code,trvlist2->subject_code);
		toadd->marks=trvlist2->marks;	
		toadd->next=NULL;
		if(cplist2==NULL && toadd!=NULL)
		{
			cplist2=toadd;
		}
		else if(cplist2!=NULL && toadd!=NULL)
		{
			toadd->next=cplist2;
			cplist2=toadd;
		}
	}//creating a copy of list2
	int flag;
	trvlist1=cplist1;
	for(;trvlist1!=NULL;trvlist1=trvlist1->next)
	{
		toadd=NULL;flag=0;
		for(trvlist2=cplist2;trvlist2!=NULL && flag==0;trvlist2=trvlist2->next)
		{//checking whether the element in list1 is equal to element in list2 on basis of rollno and sub_code
			if(trvlist2->roll_no ==trvlist1->roll_no && strcmp(trvlist2->subject_code,trvlist1->subject_code)==0)
			{
				toadd=(record_node*)malloc(sizeof(record_node));
				toadd->roll_no=trvlist1->roll_no;
				strcpy(toadd->student_name,trvlist1->student_name);
				strcpy(toadd->subject_code,trvlist1->subject_code);
				toadd->marks=trvlist1->marks;	
				toadd->next=NULL;flag=1;
			}
			//saving the common elements into toadd node
			if(*listt3==NULL && toadd!=NULL)
			{
				*listt3=toadd;
			}
			else if(*listt3!=NULL && toadd!=NULL)
			{
				toadd->next=*listt3;
				*listt3=toadd;
			}//adding the toadd node to list3
		}
	}
	*listt3=list_unique(*listt3);//operating unique on list3
	printf("The LIST1 is:\n");
	print_record(*listt1);
	printf("\n\n\n");
	printf("The LIST2 is:\n");
	print_record(*listt2);
	printf("\n\n\n");
	*listt3=list_mergesort(*listt3);
	printf("\nTHE INTERSECTION OF LIST1 AND LIST2 IS:\n\n");
	if(*listt3 !=NULL)
	print_record(*listt3);
	else
	printf("NO common elements found!!\n");
	//freeing the created lists in the given function
	trvlist2=*listt3;
	for(;trvlist2!=NULL;)
	{
		trvlist2=trvlist2->next;
		free(*listt3);
		*listt3=trvlist2;
  	}
  	trvlist1=cplist1;
  	for(;trvlist1!=NULL;)
	{
		trvlist1=trvlist1->next;
		free(cplist1);
		cplist1=trvlist1;
  	}
  	trvlist2=cplist2;
  	for(;trvlist2!=NULL;)
	{
		trvlist2=trvlist2->next;
		free(cplist2);
		cplist2=trvlist2;
  	}
	*listt3=NULL;
}

/*------------------------------------------------LISTDIFFERENCE FUNCTION---------------------------------------------------------------*/

void list_difference(record_node **listt1, record_node **listt2, record_node **listt3)
{
	record_node *cplist1, *cplist2, *toadd, *trvlist1, *trvlist2;
	cplist1=NULL;
	cplist2=NULL;
	for(trvlist1=*listt1;trvlist1!=NULL;trvlist1=trvlist1->next)
	{
		toadd=(record_node*)malloc(sizeof(record_node));
		toadd->roll_no=trvlist1->roll_no;
		strcpy(toadd->student_name,trvlist1->student_name);
		strcpy(toadd->subject_code,trvlist1->subject_code);
		toadd->marks=trvlist1->marks;	
		toadd->next=NULL;
		if(cplist1==NULL && toadd!=NULL)
		{
			cplist1=toadd;
		}
		else if(cplist1!=NULL && toadd!=NULL)
		{
			toadd->next=cplist1;
			cplist1=toadd;
		}
	}//creating copy of list1
	for(trvlist2=*listt2;trvlist2!=NULL;trvlist2=trvlist2->next)
	{
		toadd=(record_node*)malloc(sizeof(record_node));
		toadd->roll_no=trvlist2->roll_no;
		strcpy(toadd->student_name,trvlist2->student_name);
		strcpy(toadd->subject_code,trvlist2->subject_code);
		toadd->marks=trvlist2->marks;	
		toadd->next=NULL;
		if(cplist2==NULL && toadd!=NULL)
		{
			cplist2=toadd;
		}
		else if(cplist2!=NULL && toadd!=NULL)
		{
			toadd->next=cplist2;
			cplist2=toadd;
		}
	}//creating copy of list2
	int found;
	trvlist1=cplist1;
	for(;trvlist1!=NULL;trvlist1=trvlist1->next)
	{
		toadd=NULL;found=0;
		for(trvlist2=cplist2;trvlist2!=NULL && found==0;trvlist2=trvlist2->next)
		{
			if(trvlist2->roll_no ==trvlist1->roll_no && strcmp(trvlist2->subject_code,trvlist1->subject_code)==0)
			{
				found=1;
			}
		}//checking if element in list1 is whether present in list 2
		//if found ignore else add it to the list3 thus adding uncommon or subtracted elements to llist3
		if(found==0)
		{
			toadd=(record_node*)malloc(sizeof(record_node));
			toadd->roll_no=trvlist1->roll_no;
			strcpy(toadd->student_name,trvlist1->student_name);
			strcpy(toadd->subject_code,trvlist1->subject_code);
			toadd->marks=trvlist1->marks;	
			toadd->next=NULL;
		}
		if(*listt3==NULL && toadd!=NULL)
		{
				*listt3=toadd;
		}
		else if(*listt3!=NULL && toadd!=NULL)
		{
				toadd->next=*listt3;
				*listt3=toadd;
		}
	}
	*listt3=list_unique(*listt3);//operating unique on list3
	printf("The LIST1 is:\n");
	print_record(*listt1);
	printf("\n\n\n");
	printf("The LIST2 is:\n");
	print_record(*listt2);
	printf("\n\n\n");
	*listt3=list_mergesort(*listt3);
	printf("\nTHE DIFFERENCE OF LIST1 AND LIST2 IS:\n\n");
	if(*listt3 !=NULL)
	print_record(*listt3);
	else
	printf("NO LISTS found!!\n");
	//freeing the lists which were created in this function
	for(trvlist2=*listt3;trvlist2!=NULL;trvlist2=trvlist2->next)
	{
		*listt3=(*listt3)->next;
  		free(trvlist2);
  	}
  	for(trvlist2=cplist1;trvlist2!=NULL;trvlist2=trvlist2->next)
	{
		cplist1=(cplist1)->next;
  		free(trvlist2);
  	}
  	for(trvlist2=cplist2;trvlist2!=NULL;trvlist2=trvlist2->next)
	{
		cplist2=(cplist2)->next;
  		free(trvlist2);
  	}
	*listt3=NULL;
}

/*----------------------------------------------LISTDIFFERENCERETURN FUNCTION------------------------------------------------------------*/

record_node * list_difference_return(record_node* listt1, record_node* listt2, record_node* listt3)
{
	record_node *trvlist1, *trvlist2, *toadd;
	trvlist1=listt1;
	trvlist2=listt2;
	int found;
	for(;trvlist1!=NULL;trvlist1=trvlist1->next)
	{
		toadd=NULL;found=0;
		for(trvlist2=listt2;trvlist2!=NULL && found==0;trvlist2=trvlist2->next)
		{
			if(trvlist2->roll_no ==trvlist1->roll_no && strcmp(trvlist2->subject_code,trvlist1->subject_code)==0)
			{
				found=1;
			}
		}
		if(found==0)
		{
			toadd=(record_node*)malloc(sizeof(record_node));
			toadd->roll_no=trvlist1->roll_no;
			strcpy(toadd->student_name,trvlist1->student_name);
			strcpy(toadd->subject_code,trvlist1->subject_code);
			toadd->marks=trvlist1->marks;	
			toadd->next=NULL;
		}
		if(listt3==NULL && toadd!=NULL)
		{
				listt3=toadd;
		}
		else if(listt3!=NULL && toadd!=NULL)
		{
				toadd->next=listt3;
				listt3=toadd;
		}
	}
	listt3=list_unique(listt3);
	listt3=list_mergesort(listt3);
	if(listt1==NULL && listt2!=NULL)
	listt3=NULL;
	return listt3;
}
/*---------------------------------------------LISTSYMMETRICDIFFERENCE FUNCTION----------------------------------------------------------*/

void list_symmetric_difference(record_node **listt1, record_node **listt2,record_node **listt3)
{
	record_node *cplist1, *cplist2, *toadd, *trvlist1, *trvlist2, *listdiff12=NULL, *listdiff21=NULL;
	cplist1=NULL;
	cplist2=NULL;
	for(trvlist1=*listt1;trvlist1!=NULL;trvlist1=trvlist1->next)
	{
		toadd=(record_node*)malloc(sizeof(record_node));
		toadd->roll_no=trvlist1->roll_no;
		strcpy(toadd->student_name,trvlist1->student_name);
		strcpy(toadd->subject_code,trvlist1->subject_code);
		toadd->marks=trvlist1->marks;	
		toadd->next=NULL;
		if(cplist1==NULL && toadd!=NULL)
		{
			cplist1=toadd;
		}
		else if(cplist1!=NULL && toadd!=NULL)
		{
			toadd->next=cplist1;
			cplist1=toadd;
		}
	}//creating copy of list1
	for(trvlist2=*listt2;trvlist2!=NULL;trvlist2=trvlist2->next)
	{
		toadd=(record_node*)malloc(sizeof(record_node));
		toadd->roll_no=trvlist2->roll_no;
		strcpy(toadd->student_name,trvlist2->student_name);
		strcpy(toadd->subject_code,trvlist2->subject_code);
		toadd->marks=trvlist2->marks;	
		toadd->next=NULL;
		if(cplist2==NULL && toadd!=NULL)
		{
			cplist2=toadd;
		}
		else if(cplist2!=NULL && toadd!=NULL)
		{
			toadd->next=cplist2;
			cplist2=toadd;
		}
	}//creating copy of list2
	listdiff12=list_difference_return(cplist1,cplist2,listdiff12);//difference of l1 and l2
	//printf("HI I AM HERE LIST4:\n");
	//print_record(listdiff12);
	listdiff21=list_difference_return(cplist2,cplist1,listdiff21);//difference of l2 and l1
	//printf("HI I AM HERE LIST7:\n");
	//print_record(listdiff21);
	*listt3=list_union_return(listdiff12,listdiff21,*listt3);//union of two differences
	*listt3=list_mergesort(*listt3);
	printf("The LIST1 is:\n");
	print_record(*listt1);
	printf("\n\n\n");
	printf("The LIST2 is:\n");
	print_record(*listt2);
	printf("\n\n\n");
	printf("\nTHE SYMMETRIC DIFFERENCE OF LIST1 AND LIST2 IS:\n\n");
	if(*listt3 !=NULL)
	print_record(*listt3);
	else
	printf("NO LISTS found!!\n");
	trvlist2=*listt3;
	for(;trvlist2!=NULL;)
	{
		trvlist2=trvlist2->next;
		free(*listt3);
		*listt3=trvlist2;
  	}
  	trvlist1=cplist1;
  	for(;trvlist1!=NULL;)
	{
		trvlist1=trvlist1->next;
		free(cplist1);
		cplist1=trvlist1;
  	}
  	trvlist2=cplist2;
  	for(;trvlist2!=NULL;)
	{
		trvlist2=trvlist2->next;
		free(cplist2);
		cplist2=trvlist2;
  	}
	*listt3=NULL;
}

/*------------------------------------------------------LISTSORT FUNCTION----------------------------------------------------------------*/

record_node* list_mergesort(record_node* sptr)
{
	record_node *ptr,*head,*tptr;
	tptr=sptr;head=sptr;
	if(tptr!=NULL && tptr->next!=NULL)
	{
		ptr=divide(tptr);	//divide 
		tptr=list_mergesort(tptr);	//sort first half
		ptr=list_mergesort(ptr);	//sort second half
		head=mergeself(tptr,ptr);
	}
	return head;
}

record_node* divide(record_node* lptr)
{
	record_node *fast ,*slow;
	slow=lptr;
	fast=lptr->next->next;
	record_node * temp;
	while(fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
		}
	}
	temp=slow->next;
	slow->next=NULL;
	return temp;
}
record_node* mergeself(record_node *lptr,record_node *ptr)
{
	record_node *p,*q,*head,*r;
	p=lptr;
	q=ptr;
	if(p==NULL)
	{
		head=q;
	}
	else if (q==NULL)
	{
		head=p;
	}
	else
	{
		if(p->roll_no <q->roll_no)
		{
			head=p;
			p=p->next;
		}
		else
		{
			head=q;
			q=q->next;
		}
		r=head;
		while((p!=NULL) && (q!=NULL))
		{
			if(p->roll_no < q->roll_no)
			{
				r->next=p;
				p=p->next;
				r=r->next;
			}
			else
			{
				r->next=q;
				r=r->next;
				q=q->next;
			}
		}
		if(p!=NULL)
		{
			r->next=p;
		}
		else
		{
			r->next=q;
		}
	}
	return head;
}	

/*-----------------------------------------------//DECLARATIONS OF FUNCTIONS-------------------------------------------------------------*/

