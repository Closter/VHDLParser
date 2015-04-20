#ifndef VP_ENTITYELEMENTS_H
#define VP_ENTITYELEMENTS_H

#include "vp_abstractdeclaration.h"


/**
 * @brief The VP_EntityElements class describe an entity's elements wich could be
 * a generic parameter or a input or output port.
 */
class VP_EntityElements : public VP_AbstractDeclaration
{
public:
  VP_EntityElements(QString name, QString type, QString defaultValue, QPoint pos = QPoint());


  // Accessors
  //----------
  QString getType()
  {
    return m_type;
  }

  QString getValue()
  {
    return m_defaultValue;
  }

  //----------

private:

  QString m_type;           ///< Element's type
  QString m_defaultValue;   ///< Element's default value
};

#endif // VP_ENTITYELEMENTS_H
