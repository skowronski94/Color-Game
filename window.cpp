#include "window.h"

// private ////////////////////////////////////
                                                                       //start position 0 - 100 % of window width        //how far from the start position Widget expends 0 - 100 % where 100 % is the edge of the window
void Window::makeMoveCounterLabel(ObsLabel* label,QString const &text, float const &pos_x_part, float const &pos_y_part, float const &width_part, float const &height_part)
{
    float pos_x = pos_x_part * width();
    float pos_y = pos_y_part * height();
    label->setText(text);
    label->setGeometry(pos_x,
                       pos_y,
                       width_part * (width() - pos_x),
                       height_part * (height() - pos_y));
    label->setAlignment(Qt::AlignCenter);
}


                                                                  //start position 0 - 100 % of window width        //how far from the start position Widget expends 0 - 100 % where 100 % is the edge of the window
void Window::makeResultLabel(ObsLabel* label,QString const &text, float const &pos_x_part, float const &pos_y_part, float const &width_part, float const &height_part)
{
    float pos_x = pos_x_part * width();
    float pos_y = pos_y_part * height();
    label->setText(text);
    label->setGeometry(pos_x,
                       pos_y,
                       width_part * (width() - pos_x),
                       height_part * (height() - pos_y));
    label->setAlignment(Qt::AlignCenter);
}

                                                                        //start position 0 - 100 % of window width        //how far from the start position Widget expends 0 - 100 % where 100 % is the edge of the window
void Window::makeActionButton(ActionButton* button,QString const &text, float const &pos_x_part, float const &pos_y_part, float const &width_part, float const &height_part)
{
    float pos_x = pos_x_part * width();
    float pos_y = pos_y_part * height();
    button->setText(text);
    button->setGeometry(pos_x,
                        pos_y,
                        width_part * (width() - pos_x),
                        height_part * (height() - pos_y));
}


                                     //start position 0 - 100 % of window width        //how far from the start position Widget expends 0 - 100 % where 100 % is the edge of the window
void Window::makeBoard(BoardWidget* board, float const &pos_x_part, float const &pos_y_part, float const &width_part, float const &height_part)
{
    float pos_x = pos_x_part * width();
    float pos_y = pos_y_part * height();
    int boardWidth = width_part * (width() - pos_x);
    int boardHeight = height_part * (height() - pos_y);
    board->create(boardWidth, boardHeight, 10, 10);
    board->setGeometry(pos_x,
                       pos_y,
                       boardWidth,
                       boardHeight);
}

// constructors ////////////////////////////////////
Window::Window(QWidget *parent)
    :QMainWindow(parent), gameController(this), resultLabel(this), moveCounterLabel(this), actionButton(this), board(this)
{
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Gra w Kolory");

    float width_part = 0.25f;
    float height_part = 0.5f;

    QRect desktop = QApplication::desktop()->screenGeometry();
    int scr_width = desktop.width();
    int scr_height = desktop.height();

    int win_width = scr_width * width_part;
    int win_height = scr_height * height_part;

    int win_pos_x = (scr_width - win_width) / 2;
    int win_pos_y = (scr_height - win_height) / 2;

    this->resize(win_width, win_height);
    this->move(win_pos_x, win_pos_y);

    // Childs
    makeResultLabel(&resultLabel, "0" ,0.f, 0.f, 0.5f, 0.1f);
    makeMoveCounterLabel(&moveCounterLabel, "" ,0.5f, 0.f, 1.f, 0.1f);
    makeActionButton(&actionButton, "START", 0.f, 0.8f, 1.f, 1.f);
    makeBoard(&board, 0.f, 0.1f, 1.f, 7.f/9.f);

    connect(&actionButton, SIGNAL(clicked()), &gameController, SLOT(clickedSlot()));
    connect(&board, SIGNAL(mousePressed()), &gameController, SLOT(mousePressedSlot()));

    connect(&gameController, SIGNAL(clearArea(int&)), &board, SLOT(clearAreaSlot(int&)));
    connect(&gameController, SIGNAL(countPoints(int&, int const &)), &board, SLOT(countPointsSlot(int&, int const &)));
    connect(&gameController, SIGNAL(moveCounterChanged(int)), &moveCounterLabel, SLOT(moveCounterChangedSlot(int)));
    connect(&gameController, SIGNAL(resultChanged(int)), &resultLabel, SLOT(resultChangedSlot(int)));
    connect(&gameController, SIGNAL(stateChanged(State,int,int)), &resultLabel, SLOT(stateChangedSlot(State,int,int)));
    connect(&gameController, SIGNAL(stateChanged(State,int,int)), &moveCounterLabel, SLOT(stateChangedSlot(State,int,int)));
    connect(&gameController, SIGNAL(stateChanged(State,int,int)), &actionButton, SLOT(stateChangedSlot(State,int,int)));
    connect(&gameController, SIGNAL(stateChanged(State,int,int)), &board, SLOT(stateChangedSlot(State,int,int)));
}
