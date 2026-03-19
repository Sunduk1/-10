#include <iostream>
#include "library.h"

int main()
{
    system("chcp 1251");
    int choice;
    library lib;
    do
    {
        std::cout << "\n=== Меню ===\n";
        std::cout << "1. Добавить книгу\n";
        std::cout << "2. Показать все книги\n";
        std::cout << "3. Удалить по индексу\n";
        std::cout << "4. Сохранить в файл\n";
        std::cout << "5. Загрузить из файла\n";
        std::cout << "0. Выход\n";
        std::cout << "Выбор: ";

        std::cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                lib.AddFromConsole();
                break;
            case 2:
                lib.PrintAll();
                break;
            case 3:
            {
                lib.PrintAll();
                int idx;
                std::cout << "Введите индекс для удаления: ";
                if (!(std::cin >> idx))
                    throw std::runtime_error("Ошибка ввода: ожидалось целое число.");
                lib.DeleteIndex(idx);
                break;
            }
            case 4:
            {
                char filename[255];
                std::cout << "Введите имя файла для сохранения: ";
                std::cin >> filename;
                lib.SaveToFile(filename);
                break;
            }

            case 5:
            {
                char filename[255];
                std::cout << "Введите имя файла для загрузки: ";
                std::cin >> filename;
                lib.LoadFromFile(filename);
                break;
            }
            case 0:
                std::cout << "Выход." << std::endl;
                break;

            default:
                std::cout << "Неверный выбор." << std::endl;
            }
        }
        catch (const std::exception& e)
        {
            std::cout << "Исключение: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    } while (choice != 0);
}
