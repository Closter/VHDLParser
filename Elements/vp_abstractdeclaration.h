#ifndef VP_ABSTRACTDECLARATION_H
#define VP_ABSTRACTDECLARATION_H

#include <QPoint>


/**
 * @brief The VP_AbstractDeclaration class is an abstract class describe
 * a declaration of a element. Ex : port, entity, signal...
 * It manage all common information : name, position
 */
class VP_AbstractDeclaration
{
public:
  VP_AbstractDeclaration(QString name, QPoint declarationPos);


  // Accessors
  //----------
  QString getName()
  {
    return m_name;
  }

  QPoint getDeclarationPos()
  {
    return m_declarationPos;
  }

  int getDeclarationLine()
  {
    return m_declarationPos.x();
  }

  int getDeclarationCol()
  {
    return m_declarationPos.y();
  }

  //----------

private:

  QString m_name;
  QPoint  m_declarationPos;
};

#endif // VP_ABSTRACTDECLARATION_H
