#ifndef LUKIJADLL_GLOBAL_H
#define LUKIJADLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LUKIJADLL_LIBRARY)
#  define LUKIJADLL_EXPORT Q_DECL_EXPORT
#else
#  define LUKIJADLL_EXPORT Q_DECL_IMPORT
#endif

#endif // LUKIJADLL_GLOBAL_H
