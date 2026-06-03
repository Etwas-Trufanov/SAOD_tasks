#pragma once

#include <cstddef>

namespace lists {
    template<typename T>
    struct TListItem {
        T data;

        TListItem<T> *next;
        TListItem<T> *prev;
    };
    template<typename T>
    class TList {
        private:
            void clear() {
                while (head != nullptr) {
                    TListItem<T> *temp = head;
                    head = head->next;
                    delete temp;
                }
                head = nullptr;
                nail = nullptr;
            }

            void copyFrom(const TList<T> &other) {
                TListItem<T> *current = other.head;
                while (current != nullptr) {
                    pushBack(current->data);
                    current = current->next;
                }
            }
        private:
            TListItem<T> *head = nullptr;
            TListItem<T> *nail = nullptr;
        public:

            // Конструктор
            TList() : head(nullptr), nail(nullptr) {}

            // Конструктор c копированием
            TList(const TList<T> &other) : head(nullptr), nail(nullptr) {
                copyFrom(other);
            }

            // Оператор присваивания
            TList<T>& operator=(const TList<T> &other) {
                if (this != &other) {
                    clear();
                    copyFrom(other);
                }
                return *this;
            }

            // Деструктор
            // Перебирает все элементы и схлопывает их
            ~TList() {
                while (head != nullptr) {
                    TListItem<T> *temp = head;
                    head = head->next;
                    delete temp;
                }
            }


            // Добавление в начало
            // value - добавляемое значение
            void pushForward(const T &value) {
                        TListItem<T> *newItem = new TListItem<T>;
                        newItem->data = value;
                        newItem->next = head;
                        newItem->prev = nullptr;
                        if (head != nullptr) {
                            head->prev = newItem;
                        }
                        head = newItem;
                        if (nail == nullptr) {
                            nail = newItem;
                        }
                    }

            // Добавление в конец
            // value - значение
            void pushBack(const T &value) {
                        TListItem<T> *newItem = new TListItem<T>;
                        newItem->data = value;
                        newItem->next = nullptr;
                        newItem->prev = nail;
                        if (nail != nullptr) {
                            nail->next = newItem;
                        }
                        nail = newItem;
                        if (head == nullptr) {
                            head = newItem;
                        }
                    }

            // Поиск по значению
            bool find(const T &value) {
                        TListItem<T> *current = head;
                        while (current != nullptr) {
                            if (current->data == value) {
                                return true;
                            }
                            current = current->next;
                        }
                        return false;
                    }

            // Удаление по значению
            void remove(const T &value) {
                        TListItem<T> *current = head;
                        while (current != nullptr) {
                            if (current->data == value) {
                                if (current->prev != nullptr) {
                                    current->prev->next = current->next;
                                } else {
                                    head = current->next;
                                }
                                if (current->next != nullptr) {
                                    current->next->prev = current->prev;
                                } else {
                                    nail = current->prev;
                                }
                                delete current;
                                return;
                            }
                            current = current->next;
                        }
                    }

            // Добавляет копируя к хвосту себя второй список
            void copyAndConnect(const TList<T> &list) {
                        TListItem<T> *current = list.head;
                        while (current != nullptr) {
                            pushBack(current->data);
                            current = current->next;
                        }
                    }

            // Кол-во элементов
            std::size_t getSize() {
                        std::size_t size = 0;
                        TListItem<T> *current = head;
                        while (current != nullptr) {
                            size++;
                            current = current->next;
                        }
                        return size;
                    }
    };
};
