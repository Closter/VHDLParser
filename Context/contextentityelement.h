#ifndef CONTEXTENTITYELEMENT_H
#define CONTEXTENTITYELEMENT_H

#include "abstractcontext.h"

#include "Elements/vp_entityelements.h"


class ContextEntityElement : public AbstractContext
{
public:
  ContextEntityElement(QObject *parent = 0);

  VP_Word* analyze(VP_Word *firstWord);


protected:

  VP_Word* extractElement(VP_Word *elementNameWord);
  virtual void createElement(VP_Word *elementNameWord, QString elementName, QPoint pos, QString type, QString defaultValue) = 0;

  QList<VP_EntityElements*> m_elementList; ///< List of entity's element declaration

};

#endif // CONTEXTENTITYELEMENT_H
