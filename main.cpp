#include <QApplication>
#include <QPushButton>
#include <QMainWindow>

#include <Canvas/BlueprintCanvas.hpp>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMainWindow w{};
    w.setFixedSize(1080,720);
    ui::BlueprintCanvas canvas{};
    canvas.initCanvas();

    w.setCentralWidget(&canvas);

    w.show();

    return QApplication::exec();
}
