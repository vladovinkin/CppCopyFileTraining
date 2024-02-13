#include <iostream>
#include <fstream>
#include <string>
#include <optional>

int main(int argc, char* argv[])
{
    // Проверка правильности аргументов командной строки
    if (argc != 3)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: CopyFile.exe <input file name> <output file name>\n";
        return 1;
    }

    // Открываем входной файл
    std::ifstream input;
    input.open(argv[1]);
    if (!input.is_open())
    {
        std::cout << "Failed to open '" << argv[1] << "' for reading\n";
        return 1;
    }
    
    // Открываем выходной файл
    std::ofstream output;
    output.open(argv[2]);
    if (!output.is_open())
    {
        std::cout << "Failed to open '" << argv[2] << "' for writing\n";
        return 1;
    }

    // Копируем содержимое входного файла в выходной
    char ch;
    while (input.get(ch))
    {
        if (!output.put(ch))
        {
            break;
        }
    }

    // Проверяем случилась ли проблема чтения входного файла
    if (input.bad())
    {
        std::cout << "Failed to read data from input file\n";
        return 1;
    }

    // Проверяем на ошибку записи в выходной файл
    if (!output.flush())
    {
        std::cout << "Failed to write data to output file\n";
        return 1;
    }
    
    return 0;

}