#include <iostream>

class DeskTop
{
    int width{ 0 }, height{ 0 };
    static DeskTop* instance_ptr;
    DeskTop(int a, int b) : width(a), height(b) {}
    DeskTop(const DeskTop&) = delete;
public:
    static DeskTop* get_instance(int a, int b)
    {
        if (instance_ptr == nullptr)
        {
            instance_ptr = new DeskTop(a, b); 
        }
        
        return instance_ptr;
    }
    int get_width() { return width; }
    int get_height() { return height; }
};

DeskTop* DeskTop::instance_ptr = nullptr;

int main(void)
{
    DeskTop* ptr_desk = DeskTop::get_instance(500, 200);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        delete ptr_desk;

        return 0;
}