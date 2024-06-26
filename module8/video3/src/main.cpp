#include <QDebug>
#include <QList>
#include <algorithm> 
#include "book.h"
 
bool compareByTitle(const Book &b1, const Book &b2) {
    
  return b1.getTitle() < b2.getTitle();
}
 
int main(void) {

    QList<Book> books = {
        Book("Jack London", "The Call of the Wild"),
        Book("Honoré de Balzac", "Father Goriot"),
        Book("Leo Tolstoy", "War and Peace"),
        Book("Gustave Flaubert", "Sentimental education"),
        Book("Guy de Maupassant", "Une vie"),
        Book("William Shakespeare", "Hamlet")
    };
    
    std::sort(books.begin(), books.end(), compareByTitle);


    for (Book book : books) {
        qInfo() << book.getAuthor() << ": " << book.getTitle() << Qt::endl;
    }

    return 0;
}