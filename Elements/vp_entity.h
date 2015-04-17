#ifndef VP_ENTITY_H
#define VP_ENTITY_H

#include "vp_abstractdeclaration.h"


/**
 * @brief The VP_Entity class describe an entity.
 */
class VP_Entity : public VP_AbstractDeclaration
{
  Q_OBJECT
public:
  explicit VP_Entity(QString name, QPoint posDeclaration);


private:

};

#endif // VP_ENTITY_H
