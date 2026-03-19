#pragma once
#include "book.h"
#include <vector>
#include <fstream>
#include <stdexcept>

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


    void AddFromConsole()
    {
        Book* book = new Book();

        try
        {
            book->SetFromConsole();
            books.push_back(book);
        }
        catch (const std::exception& e)
        {
            delete book; 
            std::cout << "Ошибка при добавлении книги: " << e.what() << std::endl;

            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
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
        std::cout << "-------------------------------------------------------------\n";

        for (const auto& book : books)
            book->Print();
    }

    void DeleteIndex(int index) 
    {
        if (index < 0)
        {
            std::cout << "Неверно введен номер книги\n";
            return;
        }

        delete books[index];
        books.erase(books.begin() + index);
        std::cout << "Книга удалена!\n";
    }

    void SaveToFile(const char* filename) const
    {
        try
        {
            std::ofstream file(filename);

            if (!file.is_open())
                throw std::runtime_error(std::string("Не удалось открыть файл для записи: ") + filename);

            for (const auto& book : books)
            {
                file << book->GetAuthor() << "\n"
                    << book->GetTitle() << "\n"
                    << book->GetYear() << "\n";
            }

            file.close();
            std::cout << "Библиотека сохранена в файл: " << filename << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Ошибка сохранения: " << e.what() << std::endl;
        }
    }

    void LoadFromFile(const char* filename)
    {
        try
        {
            std::ifstream file(filename);

            if (!file.is_open())
                throw std::runtime_error(std::string("Не удалось открыть файл для чтения: ") + filename);

            for (auto& book : books)
                delete book;
            books.clear();

            char author[255], title[255];
            int year;

            while (file.getline(author, 255))
            {
                if (!file.getline(title, 255))
                    throw std::runtime_error("Файл повреждён: отсутствует название книги.");

                if (!(file >> year))
                    throw std::runtime_error("Файл повреждён: отсутствует год публикации.");

                file.ignore(); 

                Book* book = new Book(author, title, year);
                books.push_back(book);
            }

            file.close();
            std::cout << "Загружено книг: " << books.size() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Ошибка загрузки: " << e.what() << std::endl;

            for (auto& book : books)
                delete book;
            books.clear();
        }
    }

};
