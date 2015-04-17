#ifndef CONTEXTGENERICDECLARATION_H
#define CONTEXTGENERICDECLARATION_H

#include "abstractcontext.h"

/**
 * @brief The ContextGenericDeclaration class describe entity's generic
 * parameters declaration.
 */
class ContextGenericDeclaration : public AbstractContext
{
public:
  ContextGenericDeclaration(QObject *parent = 0);

  VP_Word* analyze(VP_Word *firstWord);
};

#endif // CONTEXTGENERICDECLARATION_H
