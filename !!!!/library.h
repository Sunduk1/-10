#pragma once
#include "book.h"
#include <vector>
class library
{
private:
	std::vector<Book*> books;
public:
    ~library()
    {
        for (auto& book : books)
            delete book;
    }

    void Add(Book* book)
    {
        books.push_back(book);
    }

    void AddFromConsole()
    {
        Book* book = new Book();
        book->SetFromConsole();
        books.push_back(book);
    }

    void PrintAll() const
    {
        if (books.empty())
        {
            std::cout << "Библиотека пуста." << std::endl;
            return;
        }

        std::cout << "\n--- Список книг  ---\n";
        std::cout << "Автор\t\tНазвание\t\tГод\n";
        std::cout << "----------------------------------------\n";

        for (const auto& book : books)
            book->Print();
    }
};

