#ifndef CONTEXTENTITYDECLARATION_H
#define CONTEXTENTITYDECLARATION_H

#include "Context/abstractcontext.h"

#include "Elements/vp_entity.h"

/**
 * @brief The ContextEntityDeclaration class describe an entity context.
 * This context contains only entity declaration.
 * This class manage only one entity.
 */
class ContextEntityDeclaration : public AbstractContext
{
public:
  ContextEntityDeclaration(QObject *parent = 0);

  VP_Word* analyze(VP_Word *firstWord);


private:

  VP_Word *findSubContext(VP_Word *firstWord);


  VP_Entity *m_entity;

};

#endif // CONTEXTENTITYDECLARATION_H
