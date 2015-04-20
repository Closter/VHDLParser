#ifndef VP_GENERIC_H
#define VP_GENERIC_H

#include "vp_entityelements.h"

/**
 * @brief The VP_Generic class describe an entity's generic.
 */
class VP_Generic : public VP_EntityElements
{
public:
  explicit VP_Generic(QString name, QString type, QString defaultValue, QPoint pos = QPoint());


private:


};

#endif // VP_GENERIC_H
