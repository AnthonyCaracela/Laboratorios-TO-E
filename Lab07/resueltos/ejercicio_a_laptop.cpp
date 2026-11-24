#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- Clases base y componentes ---

class item {
public:
    virtual ~item() {} // Añadido para evitar fugas de memoria
    virtual string GetName() { return ""; }
    virtual float GetPrice() { return 0.0; }
    virtual void GetConfiguration() {}
};

class Processor : public item {
public:
    virtual string GetName() { return string(""); }
    virtual float GetPrice() { return 0.0; }
    virtual void GetConfiguration() {}
};

class IntelI5 : public Processor {
public:
    string GetName() override {
        return "Intel i5";
    }
    float GetPrice() override {
        return 3000.00;
    }
    void GetConfiguration() override {
        cout << "1.50 Ghz, up to 2.0 Ghz with turbo, 2 cores, 4 threads, 8 MB cache, RAM 4 GB - 8 GB" << endl;
    }
};

class IntelI7 : public Processor {
public:
    string GetName() override {
        return "Intel i7";
    }
    float GetPrice() override {
        return 4700.00;
    }
    void GetConfiguration() override {
        cout << "1.6 Ghz, up to 1.99 Ghz, 9na Gen, 4 cores, 8 threads, 16 MB cache, RAM 16 GB" << endl;
    }
};

class Drive : public item {
public:
    virtual string GetName() { return string(""); }
    virtual float GetPrice() { return 0.0; }
    virtual void GetConfiguration() {}
};

class HDD : public Drive {
public:
    string GetName() override {
        return "Hard disk drive: ";
    }
    float GetPrice() override {
        return 150.00;
    }
    void GetConfiguration() override {
        cout << "capacity: 1 TB, data transfer 1050 mbits/s" << endl;
    }
};

class SDD : public Drive {
public:
    string GetName() override {
        return "Solid state drive: ";
    }
    float GetPrice() override {
        return 270.00;
    }
    void GetConfiguration() override {
        cout << "capacity: 250 GB, data transfer 1800 mbits/s" << endl;
    }
};

class DisplayType : public item {
public:
    virtual string GetName() { return string(""); }
    virtual float GetPrice() { return 0.0; }
    virtual void GetConfiguration() {}
};

class Normal : public DisplayType {
public:
    string GetName() override {
        return "Non-touch screen: ";
    }
    float GetPrice() override {
        return 195.00;
    }
    void GetConfiguration() override {
        cout << "15.6 inch FHD(1920 x 1080), plane, ....etc" << endl;
    }
};

// --- Clases del Patrón Builder ---

class laptop {
private:
    vector <item*> mLaptopParts;

public:
    ~laptop() {
        // Liberar memoria de los componentes
        for (auto part : mLaptopParts) {
            delete part;
        }
    }

    void AddParts(item *item) {
        mLaptopParts.push_back(item);
    }

    float GetCost() {
        float cost = 0.0;
        for (auto item : mLaptopParts) {
            cost += item->GetPrice();
        }
        return cost;
    }

    void GetConfiguration() {
        for (auto i = 0; i < mLaptopParts.size(); i++) {
            cout << mLaptopParts[i]->GetName() << ": ";
            mLaptopParts[i]->GetConfiguration();
        }
    }
};

class laptopBuilder {
public:
    laptop *opcion1() {
        laptop *lap = new laptop();
        lap->AddParts(new IntelI5());
        lap->AddParts(new Normal());
        lap->AddParts(new HDD());
        return lap;
    }

    laptop *opcion2() {
        laptop *lap = new laptop();
        lap->AddParts(new IntelI7());
        lap->AddParts(new Normal());
        lap->AddParts(new SDD());
        return lap;
    }
};

int main()
{
    laptopBuilder cotizar;
    cout << "Laptop Lenovo XY \n";

    laptop *lenovo = cotizar.opcion1();
    lenovo->GetConfiguration();
    cout << "precio: " << lenovo->GetCost() << endl;

    delete lenovo; // Liberar memoria

    return 0;
}