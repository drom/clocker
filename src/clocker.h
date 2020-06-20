#include <climits>

class Clocker {
    int *conters;
    const int *periods;
    unsigned char* *ports;
    int length;
  public:
    Clocker (int a, int *b, const int *c, unsigned char** d)
      : length(a), conters(b), periods(c), ports(d) { }
    int tick() {
      // find smallest conter
      int delta = INT_MAX;
      for (int j = 0; j < length; j++) {
        if (conters[j] < delta) {
          delta = conters[j];
        }
      }
      // reduce all counters by delta
      for (int j = 0; j < length; j++) {
        conters[j] -= delta;
      }
      // flip zero counters
      for (int j = 0; j < length; j++) {
        if (conters[j] == 0) {
          *ports[j] = !*ports[j];
          conters[j] = periods[j];
        }
      }
      return delta;
    }
};
