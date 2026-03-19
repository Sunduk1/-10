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
        std::cout << "Введите год публикации: ";
        std::cin >> PublishedYear;
    }

    void Print() const
    {
        std::cout << Author << "\t" << Title << "\t" << PublishedYear << std::endl;
    }

    const char* GetTitle() const { return Title; }
    const char* GetAuthor() const { return Author; }
    int GetYear() const { return PublishedYear; }
};

