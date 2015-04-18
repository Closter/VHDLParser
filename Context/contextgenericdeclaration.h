#ifndef CONTEXTGENERICDECLARATION_H
#define CONTEXTGENERICDECLARATION_H

#include "abstractcontext.h"

#include "Elements/vp_generic.h"

/**
 * @brief The ContextGenericDeclaration class describe entity's generic
 * parameters declaration.
 */
class ContextGenericDeclaration : public AbstractContext
{
public:
  ContextGenericDeclaration(QObject *parent = 0);

  VP_Word* analyze(VP_Word *firstWord);


private:

  VP_Word* newGeneric(VP_Word *genericNameWord);

  QList<VP_Generic*> m_genericList; ///< List of generic parameters declaration
};

#endif // CONTEXTGENERICDECLARATION_H
