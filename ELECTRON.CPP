#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Product
{
    int id;
    char name[50];
    char category[30];
    float price;
    int stock;
};

Product p[100];
int count = 0;

/* Function Declarations */
int login();
void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void deleteProduct();
void sortProducts();
void stockCheck();
void lowStock();
void restockProduct();
void categoryManagement();

/* LOGIN */
int login()
{
    char username[30], password[30];
    clrscr();
    cout << "\n========================================";
    cout << "\n       ELECTRONIC MANAGEMENT SYSTEM";
    cout << "\n========================================";
    cout << "\n\n              USER LOGIN";
    cout << "\n----------------------------------------";
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if(strcmp(username, "admin") == 0 &&
       strcmp(password, "1234") == 0)
    {
	cout << "\n\nLogin Successful!";
	cout << "\nWelcome, " << username << "!";
	getch();
	return 1;
    }
    else
    {
	cout << "\n\nInvalid Username or Password!";
	getch();
	return 0;
    }
}

/* 1. ADD PRODUCT */
void addProduct()
{
    clrscr();
    cout << "\n========== ADD PRODUCT ==========\n";
    cout << "Enter Product ID: ";
    cin >> p[count].id;
    cout << "Enter Product Name: ";
    cin >> p[count].name;
    cout << "Enter Category: ";
    cin >> p[count].category;
    cout << "Enter Price: ";
    cin >> p[count].price;
    cout << "Enter Stock: ";
    cin >> p[count].stock;
    count++;
    cout << "\nProduct Added Successfully!";
    getch();
}

/* 2. DISPLAY ALL PRODUCTS */
void displayProducts()
{
    int i;
    clrscr();
    cout << "\n================ ALL PRODUCTS ================\n";
    if(count == 0)
    {
	cout << "\nNo Products Available!";
	getch();
	return;
    }

    cout << "\nID\tName\t\tCategory\tPrice\tStock";
    cout << "\n------------------------------------------------";
    for(i = 0; i < count; i++)
    {
	cout << "\n" << p[i].id;
	cout << "\t" << p[i].name;
	cout << "\t\t" << p[i].category;
	cout << "\t\t" << p[i].price;
	cout << "\t" << p[i].stock;
    }
    getch();
}

/* 3. SEARCH PRODUCT */
void searchProduct()
{
    int id, i, found = 0;
    clrscr();
    cout << "\n========== SEARCH PRODUCT ==========\n";
    cout << "Enter Product ID: ";
    cin >> id;
    for(i = 0; i < count; i++)
    {
	if(p[i].id == id)
	{
	    cout << "\nProduct Found!";
	    cout << "\n----------------------------";
	    cout << "\nProduct ID : " << p[i].id;
	    cout << "\nName       : " << p[i].name;
	    cout << "\nCategory   : " << p[i].category;
	    cout << "\nPrice      : " << p[i].price;
	    cout << "\nStock      : " << p[i].stock;
	    found = 1;
	    break;
	}
    }

    if(found == 0)
	cout << "\nProduct Not Found!";
    getch();
}

/* 4. UPDATE PRODUCT */
void updateProduct()
{
    int id, i, found = 0;
    clrscr();
    cout << "\n========== UPDATE PRODUCT ==========\n";
    cout << "Enter Product ID: ";
    cin >> id;
    for(i = 0; i < count; i++)
    {
	if(p[i].id == id)
	{
	    cout << "\nEnter New Product Name: ";
	    cin >> p[i].name;
	    cout << "Enter New Category: ";
	    cin >> p[i].category;
	    cout << "Enter New Price: ";
	    cin >> p[i].price;
	    cout << "Enter New Stock: ";
	    cin >> p[i].stock;
	    cout << "\nProduct Updated Successfully!";
	    found = 1;
	    break;
	}
    }

    if(found == 0)
	cout << "\nProduct Not Found!";
    getch();
}

/* 5. DELETE PRODUCT */
void deleteProduct()
{
    int id, i, j, found = 0;
    clrscr();
    cout << "\n========== DELETE PRODUCT ==========\n";
    cout << "Enter Product ID: ";
    cin >> id;
    for(i = 0; i < count; i++)
    {
	if(p[i].id == id)
	{
	    for(j = i; j < count - 1; j++)
	    {
		p[j] = p[j + 1];
	    }
	    count--;
	    cout << "\nProduct Deleted Successfully!";
	    found = 1;
	    break;
	}
    }

    if(found == 0)
	cout << "\nProduct Not Found!";
    getch();
}

/* 6. SORT PRODUCTS */
void sortProducts()
{
    int i, j;
    Product temp;
    clrscr();
    cout << "\n========== SORT PRODUCTS ==========\n";
    if(count == 0)
    {
	cout << "\nNo Products Available!";
	getch();
	return;
    }

    /* Bubble Sort by Price */
    for(i = 0; i < count - 1; i++)
    {
	for(j = 0; j < count - i - 1; j++)
	{
	    if(p[j].price > p[j + 1].price)
	    {
		temp = p[j];
		p[j] = p[j + 1];
		p[j + 1] = temp;
	    }
	}
    }
    cout << "\nProducts Sorted By Price (Low to High)!";
    cout << "\n\nID\tName\t\tPrice\tStock";
    cout << "\n----------------------------------------";
    for(i = 0; i < count; i++)
    {
	cout << "\n" << p[i].id;
	cout << "\t" << p[i].name;
	cout << "\t\t" << p[i].price;
	cout << "\t" << p[i].stock;
    }
    getch();
}

/* 7. PRODUCT STOCK CHECK */
void stockCheck()
{
    int id, i, found = 0;
    clrscr();
    cout << "\n========== PRODUCT STOCK CHECK ==========\n";
    cout << "Enter Product ID: ";
    cin >> id;
    for(i = 0; i < count; i++)
    {
	if(p[i].id == id)
	{
	    cout << "\nProduct Name : " << p[i].name;
	    cout << "\nCurrent Stock: " << p[i].stock;
	    found = 1;
	    break;
	}
    }

    if(found == 0)
	cout << "\nProduct Not Found!";
    getch();
}

/* 8. LOW STOCK PRODUCTS */
void lowStock()
{
    int i, found = 0;
    clrscr();
    cout << "\n========== LOW STOCK PRODUCTS ==========\n";
    for(i = 0; i < count; i++)
    {
	if(p[i].stock <= 5)
	{
	    cout << "\nID       : " << p[i].id;
	    cout << "\nProduct  : " << p[i].name;
	    cout << "\nStock    : " << p[i].stock;
	    cout << "\n-------------------------";
	    found = 1;
	}
    }

    if(found == 0)
	cout << "\nNo Low Stock Products!";
    getch();
}

/* 9. RESTOCK PRODUCT */
void restockProduct()
{
    int id, quantity, i, found = 0;
    clrscr();
    cout << "\n========== RESTOCK PRODUCT ==========\n";
    cout << "Enter Product ID: ";
    cin >> id;
    for(i = 0; i < count; i++)
    {
	if(p[i].id == id)
	{
	    cout << "Current Stock: " << p[i].stock;
	    cout << "\nEnter Quantity To Add: ";
	    cin >> quantity;
	    p[i].stock = p[i].stock + quantity;
	    cout << "\nStock Updated Successfully!";
	    cout << "\nNew Stock: " << p[i].stock;
	    found = 1;
	    break;
	}
    }

    if(found == 0)
	cout << "\nProduct Not Found!";
    getch();
}

/* 10. CATEGORY MANAGEMENT */
void categoryManagement()
{
    clrscr();
    cout << "\n========== PRODUCT CATEGORIES ==========\n";
    cout << "\n1. Mobile";
    cout << "\n2. Laptop";
    cout << "\n3. Television";
    cout << "\n4. Headphones";
    cout << "\n5. Keyboard";
    cout << "\n6. Mouse";
    cout << "\n7. Other Electronics";
    cout << "\n\nThese categories can be used while adding products.";
    getch();
}

/* MAIN FUNCTION */
void main()
{
    int choice;
    /* LOGIN FIRST */
    if(login() == 0)
    {
	cout << "\n\nProgram Terminated.";
	getch();
	return;
    }

    /* PRODUCT MANAGEMENT MENU */
    do
    {
	clrscr();
	cout << "\n========================================";
	cout << "\n       ELECTRONIC MANAGEMENT SYSTEM";
	cout << "\n========================================";
	cout << "\n\n         PRODUCT MANAGEMENT";
	cout << "\n----------------------------------------";
	cout << "\n1. Add Product";
	cout << "\n2. Display All Products";
	cout << "\n3. Search Product";
	cout << "\n4. Update Product";
	cout << "\n5. Delete Product";
	cout << "\n6. Sort Products";
	cout << "\n7. Product Stock Check";
	cout << "\n8. Low Stock Products";
	cout << "\n9. Restock Product";
	cout << "\n10. Product Category Management";
	cout << "\n11. Exit";
	cout << "\n\nEnter Your Choice: ";
	cin >> choice;
	switch(choice)
	{
	    case 1:
		addProduct();
		break;

	    case 2:
		displayProducts();
		break;

	    case 3:
		searchProduct();
		break;

	    case 4:
		updateProduct();
		break;

	    case 5:
		deleteProduct();
		break;

	    case 6:
		sortProducts();
		break;

	    case 7:
		stockCheck();
		break;

	    case 8:
		lowStock();
		break;

	    case 9:
		restockProduct();
		break;

	    case 10:
		categoryManagement();
		break;

	    case 11:
		cout << "\n\nThank You!";
		break;

	    default:
		cout << "\n\nInvalid Choice!";
		getch();
	}

    } while(choice != 11);

    getch();
}