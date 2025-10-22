#pragma once
#include <iostream>
class Table;

class Square {
private:
    int m_size;
    int m_row;
    int m_col;
    bool m_isFilled = false;
    int m_numOfOptions;
    bool *m_ruledOutNumbers;
    int m_value = -1;
    Table *m_tableParent = nullptr;
public:
    Square();
    ~Square();
    void Initialize(int size);
    bool isNumPossible(int num);
    void SetRowAndCol(int row, int col);
    void SetParent(Table* ptrParent);
    int GetValue();
    void SetValue(int value);
    void RuleOutNumber(int number);
    
};

