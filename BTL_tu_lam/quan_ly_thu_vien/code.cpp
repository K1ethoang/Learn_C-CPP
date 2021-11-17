#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct book
{
    char name[50], code[10], category[15], status[5], author[30];
};

void enter_one_book(book *input);                  // nhập 1 cuốn sách
void print_one_book(book *output);                 // xuất 1 cuốn sách
void enter_book_list(book *&input, int &quantity); // nhập danh sách cuốn sách
void print_book_list(book *output, int quantity);  // xuất danh sách cuốn sách
void dele_book(book *b, int &quantity);            // xoá 1 cuốn sách
void find_book_by_code(book *b, int quantity);     // tình sách theo mã sách
void swap(book *a, book *b);                       // hoán vị
void sort_by_code(book *b, int quantity);          // sắp xếp theo mã sách
void save_file(book *b, int quantity);
void press_anykey();
void menu();

int main()
{

    menu();
    return 0;
}

void menu()
{
    book *b = (book *)malloc(sizeof(book));

    int n;
    short key;
    bool exit = false;
    do
    {
        printf("########################*MENU*########################");
        printf("\n#\t1. Add book list.                            #");
        printf("\n#\t2. Show book list.                           #");
        printf("\n#\t3. Delete a book.                            #");
        printf("\n#\t4. Sort book list by code.                   #");
        printf("\n#\t5. Find book by code.                        #");
        printf("\n#\t6. Save file.                                #");
        printf("\n#\t0. Exit program.                             #");
        printf("\n######################################################");
        printf("\n\t->Enter key: ");
        scanf("%d", &key);

        switch (key)
        {
        case 0:
            printf("\nExit successfully :v");
            exit = true;
            press_anykey;
            break;
        case 1:

            enter_book_list(b, n);
            press_anykey();
            break;

        case 2:
            print_book_list(b, n);
            press_anykey();
            break;
        case 3:
            dele_book(b, n);
            press_anykey();
            break;
        case 4:
            sort_by_code(b, n);
            press_anykey();
            break;
        case 5:
            find_book_by_code(b, n);
            press_anykey();
            break;
        case 6:
            save_file(b, n);
            press_anykey();
            break;

        default:
            printf("\n\tError! Enter again");
            press_anykey();
            break;
        }

    } while (!exit);
    free(b);
}

void enter_one_book(book *input)
{
    fflush(stdin);
    printf("\n(?) Enter book's name: ");
    gets(input->name);
    printf("(?) Enter book's code: ");
    gets(input->code);
    printf("(?) Enter book's category: ");
    gets(input->category);
    printf("(?) Enter book's status: ");
    gets(input->status);
    printf("(?) Enter book's author: ");
    gets(input->author);
}

void print_one_book(book *output)
{
    printf("\nName: %s", output->name);
    printf("\nCode: %s", output->code);
    printf("\nCategory: %s", output->category);
    printf("\nStatus: %s", output->status);
    printf("\nAuthor: %s", output->author);
}

void enter_book_list(book *&input, int &quantity)
{
    do
    {
        printf("\nEnter number of books: ");
        scanf("%d", &quantity);
    } while (quantity < 0);
    input = (book *)malloc(quantity * sizeof(book));
    for (int i = 0; i < quantity; i++)
    {
        printf("\n\tEnter book [%d]\n", i + 1);
        enter_one_book(&*(input + i));
    }
}

void print_book_list(book *output, int quantity)
{
    printf("\n\tBook Information\n");
    for (int i = 0; i < quantity; i++)
    {
        printf("\n\tBook's information [%d]\n", i + 1);
        {
            print_one_book(output + i);
        }
    }
}

void dele_book(book *b, int &quantity)
{
    int pos;
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    printf("\n\tDeleting");
    for (int i = 0; i < 10; i++)
    {
        Sleep(300);
        printf(".");
    }
    pos -= 1;
    bool check = false;
    for (int i = pos + 1; i < quantity; i++)
    {
        *(b + i - 1) = *(b + i);
        check = true;
    }
    quantity--;
    if (check == true)
        printf("\n\tDelete book successfully <3");
    else
        printf("\n\tCan't delete book :(");
}

void find_book_by_code(book *b, int quantity)
{
    char code[10];
    fflush(stdin);
    printf("\nEnter book's code to find: ");
    gets(code);
    printf("\n\tFinding");
    for (int i = 0; i < 10; i++)
    {
        Sleep(300);
        printf(".");
    }
    bool check = false;
    for (int i = 0; i < quantity; i++)
    {
        if (strcmp((b + i)->code, code) == 0)
        {
            print_one_book(b + i);
            check = true;
        }
    }

    if (check == false)
        printf("\n\tBook's code does not exist :(");
}

void swap(book *a, book *b)
{
    book temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_code(book *b, int quantity)
{
    // selection sort
    printf("\n\tSorting");
    for (int i = 0; i < 10; i++)
    {
        Sleep(300);
        printf(".");
    }

    for (int i = 0; i < quantity - 1; i++)
    {
        int pos_min = i;
        for (int j = i; j < quantity; j++)
        {
            if (strcmp((b + i)->code, (b + j)->code) > 0)
                pos_min = j;
        }

        if (pos_min != i)
            swap(b + i, b + pos_min);
    }
}

void save_file(book *b, int quantity)
{
    FILE *file;
    file = fopen("book.txt", "w");

    if (file == NULL)
    {
        printf("\n\tError");
    }
    fprintf(file, "%-50s|| %-10s|| %-20s|| %-10s|| %-30s", "Name", "Code", "Category", "Status", "Author");
    for (int i = 0; i < quantity; i++)
    {
        fprintf(file, "\n%-50s|| %-10s|| %-20s|| %-10s|| %-30s", (b + i)->name, (b + i)->code, (b + i)->category, (b + i)->status, (b + i)->author);
    }
    printf("\n\tSaving");
    for (int i = 0; i < 10; i++)
    {
        Sleep(300);
        printf(".");
    }

    printf("\n\n\tFile saved successfully <3");
    fclose(file);
}

void press_anykey()
{
    printf("\n\tpress any key to continue :>>");
    getch();
    system("cls");
}