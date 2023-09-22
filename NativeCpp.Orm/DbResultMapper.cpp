#include "DbResultMapper.h"

TIMESTAMP DbMapper::timestamp_null()
{
    TIMESTAMP timestamp;

    timestamp.year = 0;
    timestamp.month = 0;
    timestamp.day = 0;
    timestamp.hour = 0;
    timestamp.min = 0;
    timestamp.sec = 0;
    timestamp.fract = 0;

    return timestamp;
}

DATE DbMapper::date_null()
{
    DATE date;

    date.year = 0;
    date.month = 0;
    date.day = 0;

    return date;
}

TIME DbMapper::time_null()
{
    TIME time_;

    time_.hour = 0;
    time_.min = 0;
    time_.sec = 0;

    return time_;
}
