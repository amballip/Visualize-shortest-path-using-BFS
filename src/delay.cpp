#include "functions.h"

// to intruduce delay for graphics
void delaySmall()
{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    sleep_for(10ms);
}
void delayLarge()
{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    sleep_for(100ms);
}

