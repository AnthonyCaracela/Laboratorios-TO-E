// propuesto_2.cpp 
#include <iostream>
#include <string>

// --- Productos Abstractos ---
class Button {
public:
    virtual ~Button() {}
    virtual void Draw() const = 0;
};

class CheckBox {
public:
    virtual ~CheckBox() {}
    virtual void Draw() const = 0;
};

// --- Familia Windows ---
class WinButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Windows" << std::endl;
    }
};

class WinCheckBox : public CheckBox {
public:
    void Draw() const override {
        std::cout << "Dibujando CheckBox Windows" << std::endl;
    }
};

// --- Familia Mac ---
class MacButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Mac" << std::endl;
    }
};

class MacCheckBox : public CheckBox {
public:
    void Draw() const override {
        std::cout << "Dibujando CheckBox Mac" << std::endl;
    }
};

// --- Familia Linux ---
class LinuxButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Linux" << std::endl;
    }
};

class LinuxCheckBox : public CheckBox {
public:
    void Draw() const override {
        std::cout << "Dibujando CheckBox Linux" << std::endl;
    }
};

// --- Fábrica Abstracta ---
class GUIFactory {
public:
    virtual ~GUIFactory() {}
    virtual Button* CrearButton() const = 0;
    virtual CheckBox* CrearCheckBox() const = 0;
};

// --- Fábricas Concretas ---
class WinFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new WinButton();
    }
    CheckBox* CrearCheckBox() const override {
        return new WinCheckBox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new MacButton();
    }
    CheckBox* CrearCheckBox() const override {
        return new MacCheckBox();
    }
};

class LinuxFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new LinuxButton();
    }
    CheckBox* CrearCheckBox() const override {
        return new LinuxCheckBox();
    }
};

// --- Cliente ---
void Application(const GUIFactory& f) {
    Button* btn = f.CrearButton();
    CheckBox* chk = f.CrearCheckBox();

    btn->Draw();
    chk->Draw();

    delete btn;
    delete chk;
}

int main() {
    std::cout << "Cliente: Windows" << std::endl;
    GUIFactory* f1 = new WinFactory();
    Application(*f1);
    delete f1;

    std::cout << std::endl;

    std::cout << "Cliente: Mac" << std::endl;
    GUIFactory* f2 = new MacFactory();
    Application(*f2);
    delete f2;

    std::cout << std::endl;

    std::cout << "Cliente: Linux" << std::endl;
    GUIFactory* f3 = new LinuxFactory();
    Application(*f3);
    delete f3;

    return 0;
}