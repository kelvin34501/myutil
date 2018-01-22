#ifndef __MYUTIL_LIBRARY_H__
#define __MYUTIL_LIBRARY_H__

#define min(x, y)                               \
        ({                                      \
                typeof(x) _min1 = (x);          \
                typeof(y) _min2 = (y);          \
                (void) (&_min1 == &_min2);      \
                _min1 < _min2 ? _min1 : _min2;  \
        })

#define max(x, y)                               \
        ({                                      \
                typeof(x) _max1 = (x);          \
                typeof(y) _max2 = (y);          \
                (void) (&_max1 == &_max2);      \
                _max1 > _max2 ? _max1 : _max2;  \
        })

#define min3(x, y, z)                                             \
        ({                                                        \
                typeof(x) _min1 = (x);                            \
                typeof(y) _min2 = (y);                            \
                typeof(z) _min3 = (z);                            \
                (void) (&_min1 == &_min2);                        \
                (void) (&_min1 == &_min3);                        \
                _min1 < _min2 ? (_min1 < _min3 ? _min1 : _min3) : \
                        (_min2 < _min3 ? _min2 : _min3);          \
        })

#define max3(x, y, z)                                             \
        ({                                                        \
                typeof(x) _max1 = (x);                            \
                typeof(y) _max2 = (y);                            \
                typeof(z) _max3 = (z);                            \
                (void) (&_max1 == &_max2);                        \
                (void) (&_max1 == &_max3);                        \
                _max1 > _max2 ? (_max1 > _max3 ? _max1 : _max3) : \
                        (_max2 > _max3 ? _max2 : _max3);          \
        })

#define swap(x, y) do                               \
                {                                   \
                        typeof(x) * _swap1 = &(x);  \
                        typeof(y) * _swap2 = &(y);  \
                        if (_swap1 == _swap2)       \
                                break;              \
                        typeof(x) _tmp = *_swap1;   \
                        *_swap1 = *_swap2;          \
                        *_swap2 = _tmp;             \
                }while(0)
#endif
