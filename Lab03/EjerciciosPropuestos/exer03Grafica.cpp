#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QPen>
#include <QBrush>
#include <QString>
#include <string>

// 1. Clase Base Abstracta Polimórfica
class NodoExpresion {
public:
    virtual ~NodoExpresion() {}
    virtual double evaluar() const = 0;
    virtual std::string getEtiqueta() const = 0;

    // Método polimórfico para dibujar en la escena gráfica de Qt
    virtual void dibujar(QGraphicsScene* scene, double x, double y, double xOffset, double levelHeight) = 0;
};

// 2. Clase para Números (Hojas del Árbol)
class NodoNumero : public NodoExpresion {
private:
    double valor;

public:
    NodoNumero(double val) : valor(val) {}

    double evaluar() const override { return valor; }

    std::string getEtiqueta() const override {
        return std::to_string((int)valor);
    }

    void dibujar(QGraphicsScene* scene, double x, double y, double xOffset, double levelHeight) override {
        Q_UNUSED(xOffset);
        Q_UNUSED(levelHeight);

        double radio = 22.0;

        // Estilos: Borde azul y fondo blanco/celeste
        QPen pen(QColor(41, 128, 185), 2);
        QBrush brush(QColor(245, 247, 250));

        // Dibujar círculo
        scene->addEllipse(x - radio, y - radio, radio * 2, radio * 2, pen, brush);

        // Dibujar valor centrado dentro del círculo
        QGraphicsTextItem* text = scene->addText(QString::fromStdString(getEtiqueta()));
        QFont font("Arial", 12, QFont::Bold);
        text->setFont(font);
        text->setDefaultTextColor(Qt::black);

        QRectF bounds = text->boundingRect();
        text->setPos(x - bounds.width() / 2.0, y - bounds.height() / 2.0);
    }
};

// 3. Clase para Operadores (+, *)
class NodoOperador : public NodoExpresion {
private:
    char operador;
    NodoExpresion* izquierdo;
    NodoExpresion* derecho;

public:
    NodoOperador(char op, NodoExpresion* izq, NodoExpresion* der)
        : operador(op), izquierdo(izq), derecho(der) {}

    ~NodoOperador() override {
        delete izquierdo;
        delete derecho;
    }

    double evaluar() const override {
        if (operador == '+') return izquierdo->evaluar() + derecho->evaluar();
        if (operador == '*') return izquierdo->evaluar() * derecho->evaluar();
        return 0.0;
    }

    std::string getEtiqueta() const override {
        return std::string(1, operador);
    }

    void dibujar(QGraphicsScene* scene, double x, double y, double xOffset, double levelHeight) override {
        double radio = 22.0;

        // Coordenadas para los nodos hijos
        double xIzq = x - xOffset;
        double yIzq = y + levelHeight;

        double xDer = x + xOffset;
        double yDer = y + levelHeight;

        // Ajuste especial para que el nodo '54' descienda al nivel inferior igual a la imagen
        if (xOffset > 120 && izquierdo->getEtiqueta() == "54") {
            yIzq = y + levelHeight * 3.0;
            xIzq = x - 220.0;
        }

        QPen linePen(QColor(52, 152, 219), 2);

        // Dibujar rama izquierda y procesar subárbol
        if (izquierdo) {
            scene->addLine(x, y + radio, xIzq, yIzq - radio, linePen);
            izquierdo->dibujar(scene, xIzq, yIzq, xOffset * 0.52, levelHeight);
        }

        // Dibujar rama derecha y procesar subárbol
        if (derecho) {
            scene->addLine(x, y + radio, xDer, yDer - radio, linePen);
            derecho->dibujar(scene, xDer, yDer, xOffset * 0.52, levelHeight);
        }

        // Dibujar círculo del operador
        QPen pen(QColor(41, 128, 185), 2);
        QBrush brush(Qt::white);

        scene->addEllipse(x - radio, y - radio, radio * 2, radio * 2, pen, brush);

        // Dibujar símbolo del operador
        QGraphicsTextItem* text = scene->addText(QString::fromStdString(getEtiqueta()));
        QFont font("Arial", 14, QFont::Bold);
        text->setFont(font);
        text->setDefaultTextColor(Qt::black);

        QRectF bounds = text->boundingRect();
        text->setPos(x - bounds.width() / 2.0, y - bounds.height() / 2.0);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Construcción de la expresión matemática: 54 + ( (5 * 34) + (1 * 2) )
    NodoExpresion* mult1 = new NodoOperador('*', new NodoNumero(5), new NodoNumero(34));
    NodoExpresion* mult2 = new NodoOperador('*', new NodoNumero(1), new NodoNumero(2));
    NodoExpresion* sumaDer = new NodoOperador('+', mult1, mult2);
    NodoExpresion* raiz = new NodoOperador('+', new NodoNumero(54), sumaDer);

    QGraphicsScene scene;
    scene.setBackgroundBrush(Qt::white);

    // Título superior
    QGraphicsTextItem* titulo = scene.addText("54+5*34+1*2");
    QFont fontTitulo("Times New Roman", 18, QFont::Bold);
    titulo->setFont(fontTitulo);
    titulo->setPos(310, 15);

    // Dibujar el árbol comenzando desde la raíz (X=400, Y=80)
    raiz->dibujar(&scene, 400, 80, 160, 90);

    // Texto con el resultado de la evaluación
    double resultado = raiz->evaluar();
    QGraphicsTextItem* resText = scene.addText(QString("Resultado Evaluado = %1").arg(resultado));
    QFont fontRes("Arial", 12, QFont::Bold);
    resText->setFont(fontRes);
    resText->setDefaultTextColor(QColor(39, 174, 96));
    resText->setPos(300, 410);

    // Crear la vista de la ventana gráfica
    QGraphicsView view(&scene);
    view.setWindowTitle("Binary Expression Tree - Qt Graphics Window");
    view.resize(820, 480);
    view.setRenderHint(QPainter::Antialiasing); // Renderizado suave/anti-aliasing
    view.show();

    int execResult = app.exec();

    delete raiz; // Liberación de memoria
    return execResult;
}