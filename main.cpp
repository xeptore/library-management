#include <iostream>
#include "book.h"
using namespace std;

int main() {
    Book book = Book();
    book.setPublishYear(1992);
    book.setAuthor("Mamad Johnson");
    cout << book.getAuthor() << endl;
    return 0;
}
