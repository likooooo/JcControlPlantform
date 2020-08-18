#ifndef XMLCONTROLLER_H
#define XMLCONTROLLER_H
#include <QString>
#include <QtXml>
#include <QMap>

class XmlController
{
private:
    //添加xml头文件
    void CreateProcessingInstruction();
    //添加根节点
    bool CreateRoot(QString rootName="root");
    bool IsContainTargetAttributeName(QDomNamedNodeMap source,QString target);

public:
    //inline
    //xml操作对象
    QDomDocument* doc;
    //xml文件对象
    QFile* xmlFile;
    XmlController();
    XmlController(QString xmlFilePath,QFile::OpenModeFlag xmlOpenMode);

    QDomElement GetRootNode();

    /**IO操作**/
    //创建xml
    bool CreateXml();
    bool CreateXml(QString xmlFilePath);
    //读取xml
    bool ReadXml(QString xmlFilePath);
    //保存xml文件
    bool WriteXml();
    bool WriteXml(QString xmlFilePath);
    /**节点的增删改查**/
    //增加子节点
    QDomElement  AddChildNode(QDomElement parent,QString nodeName);
    void  AddChildNode(QDomNode childNode,QDomElement parent);
    QDomElement  AddChildNode(QDomElement parent,QString nodeName,QMap<QString ,QString> attributeData);
    //删除子节点
    bool RemoveChildNode(QDomNode childNode);
    bool RemoveChildNode(QList<QDomNode> selectedNode);
    //修改子节点
    void EditChildNodeAttribute(QDomElement toEditNode,QString attribute,QString val);
    void EditChildNodeAttribute(QDomElement toEditNode,QMap<QString ,QString> attribute);
    //查找子节点
    void FindChildNode(QDomElement parent,QString nodeName,QList<QDomNode> selectedNode);
    void FindChildNodeByIteration(QDomNode parent,QString nodeName, QList<QDomNode> selectedNode);
    QDomNodeList FindChildNodeByTargetName(QString nodeName);
    void FindChildNodeByTargetName(QDomElement parent,QString nodeName,QList<QDomNode> selectedNode);
    void FindNodeByFilter(QList<QDomNode> source,QMap<QString ,QString> attributeFilter,QList<QDomNode> selectedNode);
};

#endif // XMLCONTROLLER_H
