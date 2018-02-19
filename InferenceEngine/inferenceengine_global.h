#ifndef INFERENCEENGINE_GLOBAL_H
#define INFERENCEENGINE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(INFERENCEENGINE_LIBRARY)
#  define INFERENCEENGINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define INFERENCEENGINESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // INFERENCEENGINE_GLOBAL_H
