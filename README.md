# Inventory
This Strayed Old School assignments ran from old 1.44MB Floppy ... my 1st experience on C Programming
Below are the requirement for the program

Program Specifications
Objectives

XXX WareHouse is a private warehouse owned by XXX wholesale Pte. Ltd which is dealing Computer Hardware Wholesale. Although the warehouse is small but recent renovations to the warehouse has allowed more inventory to be stored and this has caused the tracking of inventory to become increasingly difficult.

As a programmer, you are required to design, code, test and document a suite of programs to handle the warehouse inventory system for XXX wholesale Pte. Ltd.

This suite of programs should allow for:

1.	Maintenance Module
•	Addition of new inventory items
•	Amendment of existing inventory’s datails
•	Deletion of existing inventory which the company no longer requires

2.	Report Module
•	A report which will show the details of single inventory
•	Another report which shows the detail of all inventory in the inventory file
•	A detail of single/all inventory can be printing out. 


The modules must be separated into individual/external programs. A main menu has to be designed and coded to allow the user to choose which module is to be executed. The main menu must be presented when this system is executed and presented again after the selected module terminates. User should only therefore be allowed to exit from this system by choosing exit from the main menu. A sample of the main menu can be found in Appendix B1.


Maintenance Module

Add Inventory 
Objectives
Allows the user to enter the new inventory details. The details include the inventory code, inventory description, inventory category, quantity on hand, reorder level, purchase price and sellling price. These details are to be stored and kept for future usage.


Name	Field Name	Type	Field Size
Inventory Code	Inv_code	Integer	4
Inventory Category	Inv_cate	String	15
Inventory Description	Inv_desc	String	30
Quantity On Hand	Qty_hnd	Integer	999
Reorder Level	Reord_lvl	Integer	999
Purchase Price	Pur_price	Floating	9999.99
Selling Price	Sel_price	Floating	9999.99


Update Inventory
Objectives
Allow the user to modify the existing inventory details and update to the data file. The details of what is to be entered shown in the above. These amendments are to be stored into the inventory files.


Delete Inventory 
Objectives
Allows the user to delete the existing inventory details. The inventory code are to be deleted from the inventory data file.


Appendix A

Main Menu

XXX WareHouse Inventory System 

	MAIN MENU
1.	Add Records
2.	Update Records
3.	Delete Records
4.	Report Menu
5.	Exit

Please enter your choice : X

Report Menu

				XXX WareHouse Inventory System

					Report Menu
1.	Report on Single Inventory
2.	Report Inventory Detail Based on Inventory Code
3.	Exit to Main Menu

Please enter your choice : X







