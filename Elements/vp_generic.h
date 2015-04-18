#ifndef VP_GENERIC_H
#define VP_GENERIC_H

#include "vp_abstractdeclaration.h"


/**
 * @brief The VP_Generic class describe an entity's generic.
 */
class VP_Generic : public VP_AbstractDeclaration
{
public:
  explicit VP_Generic(QString name, QString type, QString defaultValue, QPoint pos = QPoint());

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

  QString m_type;           ///< Parameter's type
  QString m_defaultValue;   ///< Generic's default value

};

#endif // VP_GENERIC_H
