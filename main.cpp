#include <QApplication>
#include <QPushButton>
#include <QMainWindow>

#include <Canvas/BlueprintCanvas.hpp>
#include <BlueprintNode/NodeUI.hpp>
#include "BlueprintPin/BlueprintPin.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMainWindow w{};
    w.setFixedSize(1080, 720);
    ui::BlueprintCanvas canvas{};
    canvas.initCanvas();


    QSharedPointer<ui::BlueprintNode> node{new ui::BlueprintNode{}};

    ui::BlueprintPin exec{ui::BlueprintPin::Input, node};
    ui::BlueprintPin exec2{ui::BlueprintPin::Output, node};

    node->addPin(&exec);
    node->addPin(&exec2);

    canvas.scene()->addItem(node.get());

    w.setCentralWidget(&canvas);

    w.show();

    return QApplication::exec();
}
