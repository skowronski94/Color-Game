#include "../../board/tile.h"
#include <QtTest/QtTest>

class Test: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
};

void Test::toUpper()
{
    Tile t;
    QColor const c(Qt::white);
    t.setColor(&c);
    QColor const c_comp(Qt::white);
    QCOMPARE(*t.getColor(), c_comp);
}

QTEST_MAIN(Test)
#include "test.moc"
