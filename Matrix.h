//
// Created by stavih19 on 17/01/2020.
//

#ifndef MILESTONE2_MATRIX_H
#define MILESTONE2_MATRIX_H

#include <utility>
#include "Searchable.h"
#include "CellMatrix.h"

class Matrix : public Searchable<CellMatrix> {
private:
    int n{}, m{};
    vector<vector<CellMatrix*>> matrix;

    CellMatrix *convertHashToPoint(int hash);

    double convertPointToHash(CellMatrix point);

    bool isUpWall(CellMatrix point) {
        if (point.getI() != 0) {
            return !isWall(point);
        }
        return false;
    }

    bool isRightWall(CellMatrix point) {
        if (point.getJ() != m) {
            return !isWall(point);
        }
        return false;
    }

    bool isDownWall(CellMatrix point) {
        if (point.getI() != n) {
            return !isWall(point);
        }
        return false;
    }

    bool isLeftWall(CellMatrix point) {
        if (point.getJ() != 0) {
            return !isWall(point);
        }
        return false;
    }

    bool isWall(CellMatrix point);
public:
    Matrix(vector<vector<CellMatrix*>> matrixN) {
        matrix = std::move(matrixN);
        n = matrix.size();
        m = matrix.at(0).size();
    }

    State<CellMatrix> getInitialState() override;

    State<CellMatrix> getGoalState() override;

    list<State<struct CellMatrix>> getAllPossibleState(State<CellMatrix> state) override;
};


#endif //MILESTONE2_MATRIX_H