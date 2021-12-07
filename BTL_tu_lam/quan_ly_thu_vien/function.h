#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct book
{
    char name[50], code[10], category[15], status[5], author[30];
};
// khai báo các hàm
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