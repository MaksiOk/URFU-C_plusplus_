#include "Date.h"

ostream& operator<<(ostream& wd, const Date& os)
{
    os << "<" << wd._occurList.size() << "> "
        << wd._word << endl;
}
