#include <QApplication>
#include <QPushButton>
#include <QMainWindow>

#include <Canvas/BlueprintCanvas.hpp>
#include <Canvas/BlueprintNode.hpp>
#include <Canvas/BlueprintPin.hpp>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMainWindow w{};
    w.setFixedSize(1080,720);
    ui::BlueprintCanvas canvas{};
    canvas.initCanvas();


    ui::BlueprintNode node{};
    ui::BlueprintPin exec{ui::BlueprintPin::Input};
    ui::BlueprintPin exec2{ui::BlueprintPin::Output};

    node.addPin(&exec);
    node.addPin(&exec2);

    canvas.scene()->addItem(&node);

    w.setCentralWidget(&canvas);

    w.show();

    return QApplication::exec();
}
