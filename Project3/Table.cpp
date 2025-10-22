#include "Table.h"
#include <iostream>

Table::Table(TableSizeManager *sizeManager){
    m_SizeManager = sizeManager;
    m_toFill = sizeManager->ColSize() * sizeManager->RowSize();
    m_Temp = new bool[m_SizeManager->ColSize()];
    m_Board = new Square * [sizeManager->RowSize()];
    for (int i = 0; i < sizeManager->RowSize(); i++) 
        m_Board[i] = new Square[sizeManager->ColSize()];

    for (int i = 0; i < m_SizeManager->RowSize(); i++) 
        for (int j = 0; j < m_SizeManager->ColSize(); j++) {
            m_Board[i][j].SetParent(this);
            m_Board[i][j].SetRowAndCol(i, j);
            m_Board[i][j].Initialize(m_SizeManager->ColSize());
        }
}

Table::~Table() {
    for (int i = 0; i < m_SizeManager->RowSize(); i++)
            delete[] m_Board[i];
    delete[] m_Board;
    delete[]m_Temp;
    delete m_SizeManager;
}

void Table::PrintTable()
{
    std::cout << "==========================" << std::endl;
    for (int i = 0; i < m_SizeManager->RowSize(); i++)
    {
        if (i % m_SizeManager->GetGroupH() == 0 && i != 0)
            for (int j = 0; j < m_SizeManager->ColSize(); j++)
            {
                std::cout << "---";
                if (j % m_SizeManager->GetGroupW()==0 && j != 0)
                    std::cout << "---";
            }
        std::cout << std::endl;
        for (int j = 0; j < m_SizeManager->ColSize(); j++) {
            if (j % m_SizeManager->GetGroupW() == 0 && j != 0)
                std::cout << " | ";
            std::cout << m_Board[i][j].GetValue() + 1<<" ";
            if (m_Board[i][j].GetValue() < 9 )
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "==========================" << std::endl;
}

void Table::SetValueInSquare(int row, int col, int value)
{
    m_Board[row-1][col-1].SetValue(value-1);
    
}

void Table::SetValueInSquareOneDigitSize(int value)
{
    SetValueInSquare(value / 100, (value % 100) / 10, value % 10);
}

void Table::SetValueInSquareTwoDigitSize(int value)
{
    SetValueInSquare(value / 10000, (value % 10000) / 100, value % 100);
}

void Table::SetValuesInSquares(int arr[], int size)
{
    if (m_SizeManager->ColSize() < 10) {

        for (int i = 0; i < size; i++) {
            SetValueInSquareOneDigitSize(arr[i]);
        }
    }
    else
    {
        for (int i = 0; i < size; i++) {
            SetValueInSquareTwoDigitSize(arr[i]);
        }
    }
}

void Table::UpdateRowNumTaken(int row, int num)
{
    for (int i = 0; i < m_SizeManager->RowSize(); i++) {
        if (row == 0 && i == 3 && num == 7)
        {
            i = i;
        }
        m_Board[row][i].RuleOutNumber(num);
    }
}

void Table::UpdateColNumTaken(int col, int num)
{
    for (int i = 0; i < m_SizeManager->ColSize(); i++) {
        if (i == 0 && col == 3 && num == 7)
        {
            i = i;
        }

        m_Board[i][col].RuleOutNumber(num);
    }
}

void Table::UpdateGroupNumTaken(int row,int col, int num)
{
    int rowS, rowE, colS, colE;
    m_SizeManager->GroupPosByPos(row, col, &rowS, &rowE, &colS, &colE);
    for(int i=rowS;i<rowE;i++)
        for (int j = colS; j < colE; j++)
        {
           m_Board[i][j].RuleOutNumber(num);
        }
}

void Table::SquareUpdateParentItFilled(int row, int col, int num) {
    m_toFill--;
    if (m_toFill != 0)
    {
        UpdateRowNumTaken(row, num);
        UpdateColNumTaken(col, num);
        UpdateGroupNumTaken(row, col, num);
    }
}

void Table::checkRow(int row) {
    resetTemp();

    updateLeftNumbersOnTempByRow(row);

    for (int i = 0; i < m_SizeManager->RowSize(); i++)
    {
        if (!m_Temp[i])
        {
            int col = -1;
            bool isCorrect = true;
            for (int j = 0; j < m_SizeManager->RowSize(); j++)
            {
                if (m_Board[row][j].isNumPossible(i)) {
                    if (col == -1)
                        col = j;
                    else
                    {
                        isCorrect = false;
                        break;
                    }
                }
            }
            if (isCorrect && col != -1)
                m_Board[row][col].SetValue(i);
        }
    }
}

void Table::checkCol(int col) {

    resetTemp();

    updateLeftNumbersOnTempByCol(col);
    for (int i = 0; i < m_SizeManager->ColSize(); i++)
    {
        if (!m_Temp[i])
        {
            int row = -1;
            bool isCorrect = true;
            for (int j = 0; j < m_SizeManager->ColSize(); j++)
            {
                if (m_Board[j][col].isNumPossible(i)) {
                    if (row == -1)
                        row = j;
                    else
                    {
                        isCorrect = false;
                        break;
                    }
                }
            }
            if (isCorrect && row!=-1)
                m_Board[row][col].SetValue(i);
        }
    }
}

void Table::checkGroup(int group) {
    resetTemp();

    int rowS, rowE, colS, colE;
    m_SizeManager->GroupPosByGroup(group, &rowS, &rowE, &colS, &colE);

    updateLeftNumbersOnTempByGroup(rowS, rowE, colS, colE);

    for (int i = 0; i < m_SizeManager->RowSize(); i++)
    {
        if (!m_Temp[i])
        {
            if (i == 4)
            {
                i = 4;
            }
            int col1 = -1;
            int row1 = -1;
            bool isCorrect = true;
            for (int j = rowS; j < rowE; j++)
                for (int k = colS; k < colE; k++)
                {
                    if (m_Board[j][k].isNumPossible(i)) {
                        if (col1 == -1) {
                            col1 = k;
                            row1 = j;
                        }
                        else
                        {
                            isCorrect = false;
                            break;
                        }
                    }
                }

            if (isCorrect && col1 != -1)
                m_Board[row1][col1].SetValue(i);
        }
    }
}

void Table::updateLeftNumbersOnTempByRow(int row)
{
    for (int j = 0; j < m_SizeManager->RowSize(); j++)
    {
        int val = m_Board[row][j].GetValue();
        if (val != -1)
            m_Temp[val] = true;
    }
}

void Table::updateLeftNumbersOnTempByCol(int col)
{
    for (int j = 0; j < m_SizeManager->ColSize(); j++)
    {
        int val = m_Board[j][col].GetValue();
        if (val != -1)
            m_Temp[val] = true;
    }
}

void Table::updateLeftNumbersOnTempByGroup(int rowS, int rowE, int colS, int colE)
{
    for (int j = rowS; j < rowE; j++)
        for (int i = colS; i < colE; i++)
        {
            int val = m_Board[j][i].GetValue();
            if (val != -1)
                m_Temp[val] = true;
        }
}

void Table::resetTemp()
{
    for (int i = 0; i < m_SizeManager->ColSize(); i++)
        m_Temp[i] = false;
}

void Table::solve() {
    for (int i = 0; i < m_SizeManager->RowSize(); i++) {
        if (m_toFill == 0) {

            PrintTable();
            break;
        }
        checkRow(i);
        checkCol(i);
        checkGroup(i);
    }
    if (m_toFill != 0) {
        std::cout << "Not Solved Yet , Please Try Solve Again Or Add More Info" << std::endl;
    }
}