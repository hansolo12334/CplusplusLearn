#include "dosomething7_21.h"

namespace Foo
{
    int dosomthing(int x,int y)
    {
        return x + y;
    }
    void print()
    {
        std::cout << "han\n";
    }
} // namespace Foo


namespace Hh
{
    namespace Ll
    {
        void print()
         {
            std::cout << "inside!!\n";
        }

    } // namespace ll

} // namespace hh

namespace Koo::Soo
{
    int add(int x, int y)
    {
        return x + y;
    }
}
