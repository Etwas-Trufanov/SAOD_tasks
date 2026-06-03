#include "list.hpp"
#include <cassert>

int main() {
    // Тест заполнения
    {
        lists::TList<int> list;
        for (int i = 1; i < 11; i++) {
            list.pushForward(i);
        }
        assert(list.find(1) == true);
        assert(list.find(2) == true);
        assert(list.find(3) == true);
        assert(list.find(4) == true);
        assert(list.find(6) == true);
        assert(list.find(5) == true);
        assert(list.find(20)== false);
        assert(list.find(7) == true);
        assert(list.find(8) == true);
        assert(list.find(9) == true);
        assert(list.find(10)== true);
    }
    // Тест удаления из начала
    {
        lists::TList<int> list;
        for (int i = 1; i < 11; i++) {
            list.pushForward(i);
        }
        list.remove(1);
        assert(list.find(1) == false);
    }
    // Тест удаления из конца
    {
        lists::TList<int> list;
        for (int i = 1; i < 11; i++) {
            list.pushForward(i);
        }
        list.remove(10);
        assert(list.find(10) == false);
    }

    // Из середины
    {
        lists::TList<int> list;
        for (int i = 1; i < 11; i++) {
            list.pushForward(i);
        }
        list.remove(5);
        assert(list.find(5) == false);
    }

    // Слияние списков
    {
        lists::TList<int> list1;
        lists::TList<int> list2;
        for (int i = 1; i < 11; i++) {
            list1.pushForward(i);
        }
        for (int i = 21; i < 31; i++) {
            list2.pushForward(i);
        }
        list1.copyAndConnect(list2);
        assert(list1.find(1) == true);
        assert(list1.find(2) == true);
        assert(list1.find(3) == true);
        assert(list1.find(4) == true);
        assert(list1.find(5) == true);
        assert(list1.find(6) == true);
        assert(list1.find(7) == true);
        assert(list1.find(8) == true);
        assert(list1.find(9) == true);
        assert(list1.find(10)== true);
        assert(list1.find(21) == true);
        assert(list1.find(25) == true);
        assert(list1.find(30) == true);
    }

    // Слияние списков
    {
        lists::TList<int> list1;
        lists::TList<int> list2;
        for (int i = 1; i < 11; i++) {
            list1.pushForward(i);
        }
        list1.copyAndConnect(list2);
        assert(list1.find(1) == true);
        assert(list1.find(2) == true);
        assert(list1.find(3) == true);
        assert(list1.find(4) == true);
        assert(list1.find(5) == true);
        assert(list1.find(6) == true);
        assert(list1.find(7) == true);
        assert(list1.find(8) == true);
        assert(list1.find(9) == true);
        assert(list1.find(10)== true);
        list1.pushBack(67);
        assert(list1.find(67) == true);
    }
    return 0;
}
