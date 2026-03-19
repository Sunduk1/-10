#pragma once
#include "book.h"
#include <vector>
#include <memory> 

class library
{
private:
    std::vector<std::unique_ptr<Book>> books;

public:


    void Add(std::unique_ptr<Book> book)
    {
        books.push_back(std::move(book));
    }

    void AddFromConsole()
    {
        auto book = std::make_unique<Book>();
        try
        {
            book->SetFromConsole();
            books.push_back(std::move(book));
            std::cout << "Книга успешно добавлена!\n";
        }
        catch (const std::exception& e)
        {
            std::cout << "Ошибка при добавлении книги: " << e.what() << std::endl;
        }
    }

    void PrintAll() const
    {
        if (books.empty())
        {
            std::cout << "Библиотека пуста." << std::endl;
            return;
        }

        std::cout << "\n========== Список книг ==========\n";
        std::cout << "Всего книг: " << books.size() << "\n\n";

        for (size_t i = 0; i < books.size(); ++i)
        {
            std::cout << "Книга #" << i + 1 << ":\n";
            books[i]->Print();
        }
        std::cout << "==================================\n";
    }

    void FindByAuthor(const char* author) const
    {
        bool found = false;
        for (const auto& book : books)
        {
            if (strcmp(book->GetAuthor(), author) == 0)
            {
                if (!found)
                {
                    std::cout << "\nКниги автора " << author << ":\n";
                    found = true;
                }
                book->Print();
            }
        }
        if (!found)
            std::cout << "Книги автора " << author << " не найдены.\n";
    }

    void RemoveAt(size_t index)
    {
        if (index < books.size())
        {
            books.erase(books.begin() + index);
            std::cout << "Книга удалена.\n";
        }
        else
        {
            std::cout << "Неверный индекс!\n";
        }
    }
    size_t GetCount() const { return books.size(); }
};
