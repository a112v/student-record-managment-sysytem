#include "decls.c"

/*-----------------------------------------------Main function starts here--------------------------------------------------------------*/
int main()
{
	record_node* lptr=NULL, *list1=NULL, *list2=NULL, *list3=NULL;
	int t,option;
	char choice='y';
	printf("\n\n---------------------------STUDENT RECORD--------------------------------\n\n");
	printf("\nP.S. ROLL NUMBER AND SUBJECT CODE ARE KEYS FOR THIS RECORD\n");
	printf("\n\n-------------------------FUNCTIONS-------------------------------- \n\n");
	while(choice=='y' || choice=='Y')
   	{
   		printf("Plz Select the Action you want to perform on the record amongst these\n");
      		printf("\n1.INSERT STUDENT RECORD\n");
      		printf("\n2.INSERT OR UPDATE\n");
      		printf("\n3.DELETE\n");
     		printf("\n4.GET NUMBER OF RECORDS\n");
      		printf("\n5.IS RECORD EMPTY?\n");
      		printf("\n6.IS RECORD FULL?\n");
      		printf("\n7.GET MAX MARKS IN PARTICULAR SUBJECT\n");
      		printf("\n8.FIND TOPPER\n");
      		printf("\n9.FIND Kth POPULAR SUBJECT\n");
      		printf("\n10.FIND FAILURES\n");
      		printf("\n11.LIST UNIQUE\n");      		
      		printf("\n12.INSERT LISTS FOR  LIST FUNCTIONS\n");
      		printf("\n13.DELETE LISTS FOR  LIST FUNCTIONS\n");
      		printf("\n14.LIST UNION\n");
      		printf("\n15.LIST INTERSECTION\n");
      		printf("\n16.LIST DIFFERENCE\n");
      		printf("\n17.LIST SYMMETRIC DIFFERENCE\n");
      		printf("\n18.PRINT THE LISTS\n\n");
      		printf("\n!!!!!!!!!!!!!ENTER YOUR CHOICE!!!!!!!!!!!!!!!!\n");
      		scanf("%d",&option);
		switch(option)
      		{
    			case 1:
        		insert_stu_rec(&lptr);
        		break;
    			case 2:
        		lptr=insert(lptr);
        		lptr=list_mergesort(lptr);
         		break;
         		case 3:
         		lptr=delete_node(lptr);
         		lptr=list_mergesort(lptr);
         		break;
         		
         		case 4:
         		getnumrecords(lptr);
         		break;
         		
         		case 5:
         		isempty(lptr);
         		break;
	 		
	 		case 6:
         		isfull(lptr);
         		break;
         		
         		case 7:
         		getmaxmarks(lptr);
         		break;
         		
         		case 8:
         		find_topper(lptr);
         		break;
         		
        		case 9:
         		find_kth_popular_subject(lptr);
         		break;
         		
         		case 10:
         		find_failures(lptr);
         		break;
         		
         		case 11:
         		lptr=list_unique(lptr);
             		break;
         		
         		case 12:
         		insert_lists(&list1,&list2);
         		break;
         		
         		case 13:
         		delete_lists(&list1,&list2);
         		break;         		
         		
            		case 14:
         		list_union(&list1,&list2,&list3);
         		break;
         		
         		case 15:
         		list_intersection(&list1, &list2, &list3);
         		break;
         		
        		case 16:
         		list_difference(&list1, &list2, &list3);
         		break;
         		
         		case 17:
         		list_symmetric_difference(&list1,&list2,&list3);
         		break;
         		
         		case 18:
         		print_diff_records(lptr,list1,list2);
         		break;
         		default:break;
         	}
         	printf("\nDo you want to perform another action[y/n]?\n");
         	fflush(stdin);
         	getchar();
		choice= getchar();	
         }

	return 0;
}


/*------------------------------------------------//Main function ends here--------------------------------------------------------------*/



