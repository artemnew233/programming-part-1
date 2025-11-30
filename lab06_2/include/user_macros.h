#ifndef USER_MACROS_H
#define USER_MACROS_H

#include <math.h>
#define SERIES_AR_SUM(out, a1, d, n)                                                              \
    do                                                                                            \
    {                                                                                             \
        long _ums_n = (long)(n);                                                                  \
        if (_ums_n <= 0)                                                                          \
        {                                                                                         \
            (out) = 0.0;                                                                          \
        }                                                                                         \
        else                                                                                      \
        {                                                                                         \
            double _ums_a1 = (double)(a1);                                                        \
            double _ums_d = (double)(d);                                                          \
            (out) = ((double)_ums_n) / 2.0 * (2.0 * _ums_a1 + ((double)(_ums_n) - 1.0) * _ums_d); \
        }                                                                                         \
    } while (0)

#define SERIES_GEOM_SUM(out, a0, q, n)                              \
    do                                                              \
    {                                                               \
        long _ums_n = (long)(n);                                    \
        if (_ums_n <= 0)                                            \
        {                                                           \
            (out) = 0.0;                                            \
        }                                                           \
        else                                                        \
        {                                                           \
            double _ums_a0 = (double)(a0);                          \
            double _ums_q = (double)(q);                            \
            /* epsilon for q==1 comparison */                       \
            const double _ums_eps = 1e-12;                          \
            if (fabs(_ums_q - 1.0) < _ums_eps)                      \
            {                                                       \
                (out) = ((double)_ums_n) * _ums_a0;                 \
            }                                                       \
            else                                                    \
            {                                                       \
                double _ums_qn = pow(_ums_q, (double)_ums_n);       \
                (out) = _ums_a0 * (1.0 - _ums_qn) / (1.0 - _ums_q); \
            }                                                       \
        }                                                           \
    } while (0)

#endif