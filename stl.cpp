#include <iostream>
#include <set>
#include <string>
#include <map>
#include <unordered_set>

int main() {
    
    /*task A. Разные*/
    
    int N=0; //создаем переменную для хранения количества различных чисел
    std::cin >> N; //сохраняем значение в переменной
    
    std::set <int> numbers; //создаем set для того, чтобы хранить уникальные значения
    
    for (int i = 0; i < N; ++i) { //пока i меньше количества различных чисел, выполняется цикл заполнения множества элементами с консоли
        int value=0; //создаем переменную для хранения значений чисел
        std::cin >> value; //сохраняем значения чисел
        numbers.insert(value); //добавляем числа в set, чтобы автоматически отсортировать все поступающие числа и оставить только уникальные значения
    }
    
    std::cout << numbers.size() << std::endl; //выводим размер получившегося множества, где остались только уникальные значения


    
    /*task B. Списки по классам*/
    
    std::multimap <int, std::string> students; //создаем мультимап с парами "ключ, значение". мультимап, т.к. ключи (классы) у нас могут повторяться
    int number=0; //создаем переменные для хранения номера класса и фамилии
    std::string surname;
    
    while (std::cin >> number >> surname) { //цикл осуществляется пока осуществляется ввод данных
        students.insert(std::make_pair(number, surname)); //вставляем пары "ключ, значение" в мультимап
    }
    
    for (int i = 9; i <= 11; ++i) { //цикл выполняется три раза (для 9, 10, 11 классов)
        auto range = students.equal_range(i); //находится диапазон, соответствующий указанному ключу (в нашем случае - номеру класса)
        for (auto it = range.first; it != range.second; ++it) { //итератор инициализируется началом диапазона и увеличивается до конца диапазона не включительно
            std::cout << it->first << " " << it->second << std::endl; //first указывает на ключ, second указывает на значение, выводятся на экран
        }
    }   
    
    
    
    /*task G. Хэширование с удалением*/
    
    std::unordered_set <std::string> setOfString; //создаем unordered_set, т. к. он использует хэширование для организации элементов, что обеспечивает эффективность при выполнении последующих операций
    
    char operation; //создаем переменные для хранения операций и слов
    std::string word;
    
    while (true) { //цикл выполняется пока не будет введен спец символ
        std::cin >> operation; //сохраняем значение операции
        
        if (operation == '#') { //если вводится спец символ, завершается программа
            break;
        }
        std::cin >> word; //сохраняем значение слова
        
        if (operation == '+') { //если вводится +,
            setOfString.insert(word); //то добавляем слово в множество
        } else if (operation == '-') { //если вводится -,
            setOfString.erase(word); //то удаляем слово из множества
        } else if (operation == '?') { //если вводится ?
            if (setOfString.find(word) != setOfString.end()) { //и если найдено слово в множестве,
                std::cout << "YES" << std::endl; //то выводим YES
            } else { //если не найдено,
                std::cout << "NO" << std::endl; //то выводим NO
            }
        }
    }
    
    return 0;
}
