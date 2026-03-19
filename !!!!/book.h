
#pragma once
#include <iostream>
class Book
{
private:
    char Title[255];
    char Author[255];
    int PublishedYear;

public:
    Book()
    {
        Title[0] = '\0';
        Author[0] = '\0';
        PublishedYear = 0;
    }

    Book(const char* author, const char* title, int year)
    {
        strcpy_s(Author, sizeof(Title), author);
        strcpy_s(Title, sizeof(Title), title);
        PublishedYear = year;
    }

    void SetFromConsole()
    {
        std::cout << "Добавление книги.\nВведите автора книги: ";
        std::cin >> Author;
        std::cout << "Введите название книги: ";
        std::cin >> Title;

        while (true)
        {
            std::cout << "Введите год публикации: ";
            if (std::cin >> PublishedYear)
            {
                if (PublishedYear < 0)
                    throw std::invalid_argument("Год не может быть отрицательным.");
                break;
            }
            else
            {
                throw std::runtime_error("Ошибка ввода: ожидалось целое число.");
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
    }

    void Print() const
    {
        std::cout << Author << "\t" << Title << "\t" << PublishedYear << std::endl;
    }

    const char* GetTitle() const 
    { 
        return Title;
    }
    const char* GetAuthor() const
    {
        return Author; 
    }
    int GetYear() const 
    { 
        return PublishedYear;
    }
};

