#pragma once
#include <iostream>
#include <string>
#include <cstring>

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

        strcpy_s(Author, sizeof(Author), author);
        strcpy_s(Title, sizeof(Title), title);
        PublishedYear = year;
    }

    void SetFromConsole()
    {
        std::cout << "Добавление книги.\n";

        std::cout << "Введите автора книги: ";
        std::cin.getline(Author, sizeof(Author));

        std::cout << "Введите название книги: ";
        std::cin.getline(Title, sizeof(Title));

        while (true)
        {
            std::cout << "Введите год публикации: ";
            if (std::cin >> PublishedYear)
            {
                if (PublishedYear < 0)
                    throw std::invalid_argument("Год не может быть отрицательным.");
                if (PublishedYear > 100000)
                    throw std::invalid_argument("Год не может быть больше текущего.");
                break;
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                throw std::runtime_error("Ошибка ввода: ожидалось целое число.");
            }
        }
        std::cin.ignore(10000, '\n');
    }

    void Print() const
    {
        std::cout << "Автор: " << Author << "\nНазвание: " << Title
            << "\nГод: " << PublishedYear << "\n\n";
    }

    const char* GetTitle() const { return Title; }
    const char* GetAuthor() const { return Author; }
    int GetYear() const { return PublishedYear; }
};
