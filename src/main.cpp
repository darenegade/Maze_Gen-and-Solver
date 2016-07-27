#include "Visualizer/Visualizer.h"
#ifdef main
# undef main
#endif /* main */
int main() {
    Visualizer visualizer = *new Visualizer();
    visualizer.visualize();
    return 0;
}