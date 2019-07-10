
			 /*printf("Name:Surendra Nath");*/
			 /*printf("ID:0220-1200-3014");*/



#include<stdio.h>
#include<dos.h>

	struct inventory{
		int inv_code;
		char inv_cate[15];
		char inv_desc[30];
		int qty_hnd;
		int reord_lvl;
		float pur_price;
		float sel_price;

		};
		struct inventory record[100];

	char choice,cont,save,del;
	int i,n,c,a,found,target;

	void add_record();
	void update_record();
	void delete_record();
	void menu();
	void write_record();
	void read_record();
	void sing_inv();
	void all_inv();
	void prnt_sing();
	void prnt_all();

	FILE *data;
	int totalrec=0;
	int last_num=0;

	write_data()        /*printf("This line is used to write and open data")*/
	{	data=fopen("a:data.dat","wr+");
		fwrite(&last_num,sizeof(int),1,data);
		fwrite(&totalrec,sizeof(int),1,data);
		fwrite(record,sizeof(struct inventory),totalrec,data);
		fclose(data);
	}
	read_data()
	{	data=fopen("a:data.dat","rb+");
		fread(&last_num,sizeof(int),1,data);
		fread(&totalrec,sizeof(int),1,data);
		fread(record,sizeof(struct inventory),totalrec,data);
		fclose(data);
	}


main()
{
clrscr();
do{

struct date current_date;            /*printf("this code represent to show time and date");*/
struct time current_time;
clrscr();	getdate(&current_date);
		gettime(&current_time);
		printf("Date:%d/%d/%d",current_date.da_day,
					current_date.da_mon,
					current_date.da_year);
gotoxy(1,2);		printf("Time:%d:%2d",current_time.ti_hour,
				     current_time.ti_min);

			/*printf("the line below shows the window the main menu will be");*/


gotoxy(23,7);           printf("ษอออออออออออออออออออออออออออออออออออออป");
gotoxy(23,8);	        printf("บ                                     บ");
gotoxy(23,9);	        printf("ฬอออออออออออออออออออออออออออออออออออออน");
gotoxy(23,10);         	printf("บ                                     บ");
gotoxy(23,11);		printf("บ                                     บ");
gotoxy(23,12);		printf("บ                                     บ");
gotoxy(23,13);		printf("บ                                     บ");
gotoxy(23,14);		printf("บ                                     บ");
gotoxy(23,15);		printf("บ                                     บ");
gotoxy(23,16);		printf("บ                                     บ");
gotoxy(23,17);		printf("บ                                     บ");
gotoxy(23,18);		printf("บ                                     บ");
gotoxy(23,19);		printf("บ                                     บ");
gotoxy(23,20);		printf("บ                                     บ");
gotoxy(23,21);		printf("บ                                     บ");
gotoxy(23,22);		printf("ศอออออออออออออออออออออออออออออออออออออผ");


/*printf("below are the choice selection in the main menu");*/

gotoxy(26,8); 	printf("Dynamo WareHouse Inventory System");
gotoxy(37,11);	printf("MAIN MENU");
gotoxy(34,13);	printf("[1] Add Record");
gotoxy(34,14);	printf("[2] Update Record");
gotoxy(34,15);	printf("[3] Delete Record");
gotoxy(34,16);	printf("[4] Report Menu");
gotoxy(34,17);	printf("[5] Exit");
gotoxy(30,19);	printf("Please enter your choice:");
choice=	getchar();
flushall();
switch (choice){

		case'1':printf("Add Record");
			add_record();
			break;
		case'2':printf("Update Record");
			update_record();
			break;
		case'3':printf("Delete Record");
			delete_record();
			break;
		case'4':printf("Report Menu");
			menu();
			break;
		case'5':gotoxy(40,25);printf("EXIT");
			getch();
			break;
		default :gotoxy(37,24);printf("Try Again!!");
		getch();
		break;
	}
	}while(choice!='5');
}

void add_record()
{               /*printf("this is add record listings");*/

	do{
	clrscr();
	read_data();
		record[totalrec].inv_code = last_num+1;
		last_num++;

gotoxy(29,4);	printf("Inventory Code        : %.4d",record[totalrec].inv_code);
		flushall();
		n=totalrec;
gotoxy(29,6);	printf("Inventory Category    : ");
		gets(record[n].inv_cate);
gotoxy(29,8);	printf("Inventory Description : ");
		gets(record[n].inv_desc);
gotoxy(29,10);	printf("Quantity On Hand      : ");
		scanf("%d",&record[n].qty_hnd);
		flushall();
gotoxy(29,12);	printf("Reorder Level         : ");
		scanf("%d",&record[n].reord_lvl);
		flushall();
gotoxy(29,14);	printf("Purchase Price        : RM ");
		scanf("%f",&record[n].pur_price);
		flushall();
gotoxy(29,16);	printf("Selling Price         : RM ");
		scanf("%f",&record[n].sel_price);
		flushall();
		totalrec++;
gotoxy(29,18);	printf("Save......  [y/n] ?   : ");
		save=getchar();
		flushall();
		if (save=='y'){
			write_data();
			gotoxy(29,20);	printf("s.a.v.i.n.g............");
			gotoxy(29,22);	printf("Continue    [y/n] ?   : ");
			cont=getchar();
			flushall();
		}else{
			gotoxy(29,20);	printf("Continue    [y/n] ?   : ");
			cont=getchar();

		}
	}while(cont!='n');

}

void update_record()      /*printf("this is update record listings");*/
		{
		int tar;
		clrscr();
		read_data();
gotoxy(25,4);	printf("Enter Inventory Code  : ");
		scanf("%d",&tar);
		flushall();
		found = 0;
		for(n=0;n<=totalrec;n++){
		if( record[n].inv_code==tar){
		found=1;
		a=n;
		}
		}
		if(found==1){
gotoxy(31,2);	printf("UPDATE RECORD");
gotoxy(25,3);	printf("--------------------------");
gotoxy(25,6);	printf("Inventory Category    : %s",record[a].inv_cate);
gotoxy(25,8);	printf("Inventory Description : %s",record[a].inv_desc);
gotoxy(25,10);	printf("Quantity On Hand      : %d",record[a].qty_hnd);
gotoxy(25,12);	printf("Reorder Level         : %d",record[a].reord_lvl);
gotoxy(25,14);	printf("Purchace Price        : RM %.2f",record[a].pur_price);
gotoxy(25,16);	printf("Selling Price         : RM %.2f",record[a].sel_price);
gotoxy(17,19);   printf("[1] Inventory Category   [2] Inventory Description");
gotoxy(17,20);   printf("[3] Quantity On Hand     [4] Reorder Level");
gotoxy(17,21);   printf("[5] Purchases Price      [6] Selling Price");
gotoxy(17,22);   printf("[x] Exit");
gotoxy(30,24);   printf(" Enter Your Choice :");

		do{
			gotoxy(51,24); clreol();
			choice = getchar();
			flushall();

			switch(choice){

		case '1':

			gotoxy(49,6);clreol ();
			scanf("%s",record[a].inv_cate);
			break;
		case '2':
			gotoxy(49,8);clreol();
			scanf("%s",record[a].inv_desc);
			break;
		case '3':
			gotoxy(49,10);clreol();
			scanf("%d",&record[a].qty_hnd);
			break;
		case '4':
			gotoxy(49,12);clreol();
			scanf("%d",&record[a].reord_lvl);
			break;
		case '5':
			gotoxy(52,14);clreol();
			scanf("%f",&record[a].pur_price);
			break;
		case '6':
			gotoxy(52,16);clreol();
			scanf("%f",&record[a].sel_price);
			break;
		case 'x':gotoxy(40,25);printf("EXIT");
			write_data();
			break;

			}
			}while(choice !='x');
		getch();
		}else{
gotoxy(32,17);	printf("Record Not Found!");
		getch();
}                                                 }

void delete_record()
{               clrscr();
		read_data();
gotoxy(29,6);	printf("Enter Inventory Code: ");
		scanf("%4d",&target);
		flushall();
		found = 0;
		for(n=0;n<=totalrec;n++){
		if(record[n].inv_code==target){
		found=1;
		a=n;
		}
		}
		if(found==1){
gotoxy(34,3);	printf("DELETE RECORD");
gotoxy(30,4);	printf("---------------------");
gotoxy(29,8);	printf("Inventory Category    : %s",record[a].inv_cate);
gotoxy(29,10);	printf("Inventory Description : %s",record[a].inv_desc);
gotoxy(29,12);	printf("Quantity On Hand      : %d",record[a].qty_hnd);
gotoxy(29,14);	printf("Reorder Level         : %d",record[a].reord_lvl);
gotoxy(29,16);	printf("Purchase Price        : %.2f",record[a].pur_price);
gotoxy(29,18);	printf("Selling Price         : %.2f",record[a].sel_price);
gotoxy(29,20);	printf("Delete....   [y/n] ?  : ");
		del=getchar();
		flushall();
		if(del=='y'){
		totalrec--;
		write_data();
gotoxy(29,20);	printf("Deleting...");}
		for(a=0;a<=totalrec;a++)
		{
		if(record[a].inv_code>=target)
		record[a]=record[a+1];

		}
		}
		}
void menu()
{
	clrscr();    /*printf("the box below is the window for report menu");*/
	do{

gotoxy(16,5);	printf("ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ");
gotoxy(16,6);	printf("ณ                                                       ณ");
gotoxy(16,7);	printf("ณ                                                       ณ");
gotoxy(16,8);	printf("ณ                                                       ณ");
gotoxy(16,9);	printf("ณ                                                       ณ");
gotoxy(16,10);	printf("ณ                                                       ณ");
gotoxy(16,11);	printf("ณ                                                       ณ");
gotoxy(16,12);	printf("ณ                                                       ณ");
gotoxy(16,13);	printf("ณ                                                       ณ");
gotoxy(16,14);	printf("ณ                                                       ณ");
gotoxy(16,15);	printf("ณ                                                       ณ");
gotoxy(16,16);  printf("ณ                                                       ณ");
gotoxy(16,17);  printf("ณ                                                       ณ");
gotoxy(16,18);  printf("ณ                                                       ณ");
gotoxy(16,19);	printf("ณ                                                       ณ");
gotoxy(16,20);	printf("ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู");


gotoxy(27,7);	 printf("Dynamo Warehouse Inventory System");
gotoxy(38,10);	 printf("Report Menu");
gotoxy(20,12);	 printf("[1] Report on Single Inventory");
gotoxy(20,13);	 printf("[2] Report on All Inventory ");
gotoxy(20,14);   printf("[3] Print Report on Single Inventory");
gotoxy(20,15);   printf("[4] Print Report on all Inventory");
gotoxy(20,16);	 printf("[e] Exit to Main Menu");
gotoxy(31,18);	 printf("Please Enter Your Choice:");

		choice=getchar();
		flushall();
		switch(choice){

			case'1':sing_inv();
				break;
			case'2':all_inv();
				break;
			case'3':prnt_sing();
				break;
			case'4':prnt_all();
				break;
			case'e':gotoxy(42,25);printf("Exit");
				getch();
				break;
			default:gotoxy(33,23);printf("Invalid...try again!!");
				getch();
				break;	}
				}while(choice!='e');
					}
void sing_inv()
	{

		int tar;
		clrscr();
		read_data();
gotoxy(27,8);	printf("Enter Inventory Code  : ");
		scanf("%d",&tar);
		flushall();
		found=0;
		for(n=0;n<=totalrec;n++){
		if(record[n].inv_code==tar){
		found=1;
		a=n;
		}
		}
		if(found==0){
			gotoxy(36,15);	printf("File Not Found !!");
			}else{
			gotoxy(27,5);	printf("  SINGLE INVENTORY REPORT");
			gotoxy(27,6);   printf("---------------------------");
			gotoxy(27,10);	printf("Inventory Category    : %s",record[a].inv_cate);
			gotoxy(27,12);	printf("Inventory Description : %s",record[a].inv_desc);
			gotoxy(27,14);	printf("Quantity On Hand      : %d",record[a].qty_hnd);
			gotoxy(27,16);	printf("Reorder Level         : %d",record[a].reord_lvl);
			gotoxy(27,18);	printf("Purchase Price        : %.2f",record[a].pur_price);
			gotoxy(27,20);	printf("Selling Price         : %.2f",record[a].sel_price);

					}
										getch();
					getch();


					}





void all_inv()
{
	clrscr();
	read_data();
	gotoxy(8,8);
	printf ("Code   Category   Description    QTY    Reorder   Purchase   Selling ");
	for(i=0;i<=totalrec;i++)

{
			gotoxy(8,10+i); printf("%.4d",record[i].inv_code);
			gotoxy(15,10+i);printf("%s",record[i].inv_cate);
			gotoxy(26,10+i);printf("%s",record[i].inv_desc);
			gotoxy(42,10+i);printf("%d",record[i].qty_hnd);
			gotoxy(52,10+i);printf("%d",record[i].reord_lvl);
			gotoxy(60,10+i);printf("%.2f",record[i].pur_price);
			gotoxy(70,10+i);printf("%.2f",record[i].sel_price);

					}
					getch();clrscr();
}

void prnt_sing()
			{
			int tar;             /*printf("line to print a report");*/
			clrscr();
			read_data();
gotoxy(29,8);  		printf("Enter Inventory Code:");
			scanf("%d",&tar);
			flushall();
			found=0;
			for(n=0;n<=totalrec;n++){
			if(record[n].inv_code==tar){
			found=1;
			a=n;
			}
			}
			if(found==0){gotoxy(29,10);printf("File Not Found !!!");
			}else{
			fprintf(stdprn,"Single Inventory Report");
			fprintf(stdprn,"\n");
			fprintf(stdprn,"%d\n",record[a].inv_code);
			fprintf(stdprn,"%s\n",record[a].inv_cate);
			fprintf(stdprn,"%s\n",record[a].inv_desc);
			fprintf(stdprn,"%d\n",record[a].qty_hnd);
			fprintf(stdprn,"%d\n",record[a].reord_lvl);
			fprintf(stdprn,"%.2f\n",record[a].pur_price);
			fprintf(stdprn,"%.2f\n",record[a].sel_price);
			} getch();
			  }

void prnt_all()
		{
		clrscr();
		read_data();
gotoxy(8,8);	fprintf(stdprn,"Code   Category   Description    Reorder  QTY   Purchase  Selling ");
gotoxy(8,9);	fprintf(stdprn,"----   --------   -----------    -------  ---   --------  -------");
		for(i=0;i<=totalrec;i++)
{  		gotoxy(8,10+i);fprintf(stdprn,"%.4d",record[i].inv_code);
		gotoxy(15,10+i);fprintf(stdprn,"%s",record[i].inv_cate);
		gotoxy(26,10+i);fprintf(stdprn,"%s",record[i].inv_desc);
		gotoxy(42,10+i);fprintf(stdprn,"%d",record[i].reord_lvl);
		gotoxy(52,10+i);fprintf(stdprn,"%d",record[i].qty_hnd);
		gotoxy(60,10+i);fprintf(stdprn,"%.2f",record[i].pur_price);
		gotoxy(70,10+i);fprintf(stdprn,"%.2f",record[i].sel_price);
	}       getch();
	}
