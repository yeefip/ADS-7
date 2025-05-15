// Copyright 2022 NNTU-CS
  Car *first; // точка входа в поезд (первый вагон)
public:
  Train();
  ~Train();
  void addCar(bool hasLight); // добавить вагон с начальным состоянием лампочки
  int getLength();            // вычислить длину поезда
  int getOpCount();           // получить количество операций
