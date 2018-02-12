#include "../../board/tile.h"
#include "../../board/board.h"
#include "../../board/move_columns_algorithm.h"
#include <QtTest/QtTest>
#include <QDebug>

class FindEmptyColumnsRight_test: public QObject
{
    Q_OBJECT
private slots:
    void findColumnsRight();
};

void FindEmptyColumnsRight_test::findColumnsRight()
{
    MoveColumnsAlgorithm mca;
    QPoint p(0, 4);
    Board b(10, 10);

    b[0][9] = new Tile(0,0,0); b[0][8] = new Tile(0,0,0); b[0][7] = new Tile(0,0,0); b[0][6] = new Tile(0,0,0); b[0][5] = new Tile(0,0,0); b[0][4] = new Tile(0,0,0); b[0][3] = new Tile(0,0,0); b[0][2] = new Tile(0,0,0); b[0][1] = new Tile(0,0,0); b[0][0] = new Tile(0,0,0);
    b[1][9] = new Tile(0,0,2); b[1][8] = new Tile(0,0,2); b[1][7] = new Tile(0,0,4); b[1][6] = new Tile(0,0,1); b[1][5] = new Tile(0,0,2); b[1][4] = new Tile(0,0,2); b[1][3] = new Tile(0,0,3); b[1][2] = new Tile(0,0,4); b[1][1] = new Tile(0,0,1); b[1][0] = new Tile(0,0,2);
    b[2][9] = new Tile(0,0,0); b[2][8] = new Tile(0,0,0); b[2][7] = new Tile(0,0,0); b[2][6] = new Tile(0,0,0); b[2][5] = new Tile(0,0,0); b[2][4] = new Tile(0,0,0); b[2][3] = new Tile(0,0,0); b[2][2] = new Tile(0,0,0); b[2][1] = new Tile(0,0,0); b[2][0] = new Tile(0,0,0);
    b[3][9] = new Tile(0,0,1); b[3][8] = new Tile(0,0,2); b[3][7] = new Tile(0,0,4); b[3][6] = new Tile(0,0,3); b[3][5] = new Tile(0,0,2); b[3][4] = new Tile(0,0,1); b[3][3] = new Tile(0,0,1); b[3][2] = new Tile(0,0,3); b[3][1] = new Tile(0,0,2); b[3][0] = new Tile(0,0,4);
    b[4][9] = new Tile(0,0,1); b[4][8] = new Tile(0,0,2); b[4][7] = new Tile(0,0,3); b[4][6] = new Tile(0,0,1); b[4][5] = new Tile(0,0,3); b[4][4] = new Tile(0,0,1); b[4][3] = new Tile(0,0,1); b[4][2] = new Tile(0,0,4); b[4][1] = new Tile(0,0,4); b[4][0] = new Tile(0,0,1);
    b[5][9] = new Tile(0,0,3); b[5][8] = new Tile(0,0,3); b[5][7] = new Tile(0,0,3); b[5][6] = new Tile(0,0,2); b[5][5] = new Tile(0,0,3); b[5][4] = new Tile(0,0,4); b[5][3] = new Tile(0,0,4); b[5][2] = new Tile(0,0,1); b[5][1] = new Tile(0,0,1); b[5][0] = new Tile(0,0,1);
    b[6][9] = new Tile(0,0,2); b[6][8] = new Tile(0,0,2); b[6][7] = new Tile(0,0,4); b[6][6] = new Tile(0,0,4); b[6][5] = new Tile(0,0,1); b[6][4] = new Tile(0,0,3); b[6][3] = new Tile(0,0,2); b[6][2] = new Tile(0,0,1); b[6][1] = new Tile(0,0,4); b[6][0] = new Tile(0,0,3);
    b[7][9] = new Tile(0,0,4); b[7][8] = new Tile(0,0,1); b[7][7] = new Tile(0,0,1); b[7][6] = new Tile(0,0,3); b[7][5] = new Tile(0,0,3); b[7][4] = new Tile(0,0,3); b[7][3] = new Tile(0,0,3); b[7][2] = new Tile(0,0,4); b[7][1] = new Tile(0,0,3); b[7][0] = new Tile(0,0,4);
    b[8][9] = new Tile(0,0,0); b[8][8] = new Tile(0,0,0); b[8][7] = new Tile(0,0,0); b[8][6] = new Tile(0,0,0); b[8][5] = new Tile(0,0,0); b[8][4] = new Tile(0,0,0); b[8][3] = new Tile(0,0,0); b[8][2] = new Tile(0,0,0); b[8][1] = new Tile(0,0,0); b[8][0] = new Tile(0,0,0);
    b[9][9] = new Tile(0,0,2); b[9][8] = new Tile(0,0,1); b[9][7] = new Tile(0,0,4); b[9][6] = new Tile(0,0,2); b[9][5] = new Tile(0,0,1); b[9][4] = new Tile(0,0,3); b[9][3] = new Tile(0,0,4); b[9][2] = new Tile(0,0,2); b[9][1] = new Tile(0,0,4); b[9][0] = new Tile(0,0,1);

    Board t(10, 10);
    t[0][9] = new Tile(0,0,0); t[0][8] = new Tile(0,0,0); t[0][7] = new Tile(0,0,0); t[0][6] = new Tile(0,0,0); t[0][5] = new Tile(0,0,0); t[0][4] = new Tile(0,0,4); t[0][3] = new Tile(0,0,0); t[0][2] = new Tile(0,0,0); t[0][1] = new Tile(0,0,0); t[0][0] = new Tile(0,0,0);
    t[1][9] = new Tile(0,0,2); t[1][8] = new Tile(0,0,2); t[1][7] = new Tile(0,0,4); t[1][6] = new Tile(0,0,1); t[1][5] = new Tile(0,0,2); t[1][4] = new Tile(0,0,2); t[1][3] = new Tile(0,0,3); t[1][2] = new Tile(0,0,4); t[1][1] = new Tile(0,0,1); t[1][0] = new Tile(0,0,2);
    t[2][9] = new Tile(0,0,0); t[2][8] = new Tile(0,0,0); t[2][7] = new Tile(0,0,0); t[2][6] = new Tile(0,0,0); t[2][5] = new Tile(0,0,0); t[2][4] = new Tile(0,0,0); t[2][3] = new Tile(0,0,0); t[2][2] = new Tile(0,0,0); t[2][1] = new Tile(0,0,0); t[2][0] = new Tile(0,0,0);
    t[3][9] = new Tile(0,0,1); t[3][8] = new Tile(0,0,2); t[3][7] = new Tile(0,0,4); t[3][6] = new Tile(0,0,3); t[3][5] = new Tile(0,0,2); t[3][4] = new Tile(0,0,1); t[3][3] = new Tile(0,0,1); t[3][2] = new Tile(0,0,3); t[3][1] = new Tile(0,0,2); t[3][0] = new Tile(0,0,4);
    t[4][9] = new Tile(0,0,1); t[4][8] = new Tile(0,0,2); t[4][7] = new Tile(0,0,3); t[4][6] = new Tile(0,0,1); t[4][5] = new Tile(0,0,3); t[4][4] = new Tile(0,0,1); t[4][3] = new Tile(0,0,1); t[4][2] = new Tile(0,0,4); t[4][1] = new Tile(0,0,4); t[4][0] = new Tile(0,0,1);
    t[5][9] = new Tile(0,0,3); t[5][8] = new Tile(0,0,3); t[5][7] = new Tile(0,0,3); t[5][6] = new Tile(0,0,2); t[5][5] = new Tile(0,0,3); t[5][4] = new Tile(0,0,4); t[5][3] = new Tile(0,0,4); t[5][2] = new Tile(0,0,1); t[5][1] = new Tile(0,0,1); t[5][0] = new Tile(0,0,1);
    t[6][9] = new Tile(0,0,2); t[6][8] = new Tile(0,0,2); t[6][7] = new Tile(0,0,4); t[6][6] = new Tile(0,0,4); t[6][5] = new Tile(0,0,1); t[6][4] = new Tile(0,0,3); t[6][3] = new Tile(0,0,2); t[6][2] = new Tile(0,0,1); t[6][1] = new Tile(0,0,4); t[6][0] = new Tile(0,0,3);
    t[7][9] = new Tile(0,0,4); t[7][8] = new Tile(0,0,1); t[7][7] = new Tile(0,0,1); t[7][6] = new Tile(0,0,3); t[7][5] = new Tile(0,0,3); t[7][4] = new Tile(0,0,3); t[7][3] = new Tile(0,0,3); t[7][2] = new Tile(0,0,4); t[7][1] = new Tile(0,0,3); t[7][0] = new Tile(0,0,4);
    t[8][9] = new Tile(0,0,2); t[8][8] = new Tile(0,0,1); t[8][7] = new Tile(0,0,4); t[8][6] = new Tile(0,0,2); t[8][5] = new Tile(0,0,1); t[8][4] = new Tile(0,0,3); t[8][3] = new Tile(0,0,4); t[8][2] = new Tile(0,0,2); t[8][1] = new Tile(0,0,4); t[8][0] = new Tile(0,0,1);
    t[9][9] = new Tile(0,0,2); t[9][8] = new Tile(0,0,1); t[9][7] = new Tile(0,0,4); t[9][6] = new Tile(0,0,2); t[9][5] = new Tile(0,0,1); t[9][4] = new Tile(0,0,3); t[9][3] = new Tile(0,0,4); t[9][2] = new Tile(0,0,2); t[9][1] = new Tile(0,0,4); t[9][0] = new Tile(0,0,1);


    int result = mca.findEmptyColumnsRight(b);
    mca.moveColumnsRight(b);
    for(int j = 5; j < b.getWidth() - result; j++)
        for(int k = 5; k < b.getHeight(); k++)
            QCOMPARE(t[j][k]->getColor(), b[j][k]->getColor());
}
QTEST_MAIN(FindEmptyColumnsRight_test)
#include "test.moc"
