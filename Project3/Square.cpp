#include "Square.h"
#include "Table.h"
#include <iostream>


Square::Square() {
}
Square::~Square() {
    delete[] m_ruledOutNumbers;
}
void Square::Initialize(int size) {
    m_numOfOptions = size;
    m_size = size;
    m_ruledOutNumbers = new bool[size];
    for (int i = 0; i < size; i++)
        m_ruledOutNumbers[i] = false;
}
void Square::SetParent(Table* ptrParent) {
    m_tableParent = ptrParent;
}
int Square::GetValue() {
    return m_value;
}

void Square::SetValue(int value) {
    if (!m_isFilled) {
        m_value = value;
        m_isFilled = true;
        m_tableParent->SquareUpdateParentItFilled(m_row, m_col, m_value);
    }
}

void Square::RuleOutNumber(int number) {
    if (!m_isFilled && !m_ruledOutNumbers[number]) {
        m_ruledOutNumbers[number] = true;
        m_numOfOptions--;

        if (m_numOfOptions == 1) {
            for (int i = 0; i < m_size; i++) {
                if (!m_ruledOutNumbers[i]) {
                    SetValue(i);
                    break;
                }
            }
        }
    }
}

void Square::SetRowAndCol(int row, int col) {
    m_row = row;
    m_col=col;
}

bool Square::isNumPossible(int num) {
    return !m_isFilled&&!m_ruledOutNumbers[num];
}
