// Copyright 2022 NNTU-CS
 #ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

struct Car {
    bool light;
    Car* next;
    Car* prev;
};

class Train {
 private:
    int operationCount;
    Car* headCar; // точка входа в поезд (первый вагон)
 public:
    Train();
    ~Train();
    void addCar(bool hasLight); // добавить вагон с начальным состоянием лампочки
    int getLength();            // вычислить длину поезда
    int getOpCount();           // получить количество операций
};

#endif  // INCLUDE_TRAIN_H_
