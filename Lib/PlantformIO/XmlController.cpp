#include "XmlController.h"

XmlController::XmlController()
{
    doc=NULL;
    xmlFile=NULL;
}

XmlController:: XmlController(QString xmlFilePath,QFile::OpenModeFlag xmlOpenMode):XmlController()
{
    switch (xmlOpenMode) {
    case QFile::OpenModeFlag::ReadOnly:
        if(!ReadXml(xmlFilePath))
            throw "无法打开文件，文件被占用或路径不存在";
        break;
    case QFile::OpenModeFlag::WriteOnly:
    {
        bool res = CreateXml(xmlFilePath);
        if(!res)
        {
            throw "无法打开文件，文件已经存在";
        }
        break;
    }
    case QFile::OpenModeFlag::ReadWrite:
        if(!CreateXml(xmlFilePath))
            ;
        else if (!ReadXml(xmlFilePath))
            ;
        else throw "无法打开文件，文件被占用或路径不存在";
        break;
    default:
        throw "只实现了ReadOnly，WriteOnly";
        break;
    }

}

/** @brief 返回doc根节点
  * @param
  * @param
  * @retval None
  */
QDomElement XmlController::GetRootNode()
{
    if(doc==NULL)
        throw "doc未初始化";
    return doc->documentElement();
}


/**public methord
 *IO
 **/


/** @brief 创建xml操作对象
  * @param
  * @param
  * @retval None
  */
bool XmlController::CreateXml()
{
    doc=new QDomDocument();
    //创建头文件
    CreateProcessingInstruction();
    //创建根节点
    return  CreateRoot();
}



/** @brief 创建xml文件对象和xml操作对象
  * @param xmlFilePath xml文件路径
  * @retval
  *     返回false:
  *     1.xmlFilePath已经存在
  *     2.xmlFile打开失败
  */
bool XmlController::CreateXml(QString xmlFilePath)
{
    xmlFile =new QFile(xmlFilePath);
    if(!xmlFile->exists()||!xmlFile->open(QFile::OpenModeFlag::WriteOnly))
        return false;
    return CreateXml();
}

/** @brief 读取xml文件
  * @param xmlFilePath 读取路径
  * @retval
  *     返回false:
  *     1.xmlFilePath读取文件不存在
  *     2.xmlFilePath不是xml文件
  */
bool XmlController::ReadXml(QString xmlFilePath)
{
    xmlFile =new QFile(xmlFilePath);
    if(!(xmlFile->exists()))
        return false;
    if(!xmlFile->open(QFile::OpenModeFlag::ReadWrite))
        return false;

    doc=new QDomDocument();
    if(!doc->setContent(xmlFile))
    {
        xmlFile->close();
        return false;
    }
    return true;
////debug code
//    QDomElement root=doc->documentElement(); //返回根节点
//    qDebug()<<root.nodeName();
//    QDomNode node=root.firstChild(); //获得第一个子节点
//    while(!node.isNull())  //如果节点不空
//    {
//        if(node.isElement()) //如果节点是元素
//        {
//            QDomElement e=node.toElement(); //转换为元素，注意元素和节点是两个数据结构，其实差不多
//             qDebug()<<e.tagName()<<" "<<e.attribute("id")<<" "<<e.attribute("time"); //打印键值对，tagName和nodeName是一个东西
//             QDomNodeList list=e.childNodes();
//             for(int i=0;i<list.count();i++) //遍历子元素，count和size都可以用,可用于标签数计数
//             {
//                 QDomNode n=list.at(i);
//                 if(node.isElement())
//                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
//             }
//         }
//         node=node.nextSibling(); //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
//     }

}

/** @brief 保存xml文件
  * @param
  * @param
  * @retval
  *     返回false:
  *     xml文件句柄不存在，建议使用WriteXml(QString xmlFilePath)
  */
bool XmlController::WriteXml()
{
    if(xmlFile == NULL) return false;
    QTextStream out_stream(xmlFile);
    doc->save(out_stream,4);//缩进4格
    xmlFile->close();

    return  true;
}

/** @brief 修改xml文件句柄的路径来保存xml文件，实现保存时的重命名
  * @param
  * @param
  * @retval None
  */
bool XmlController::WriteXml(QString xmlFilePath)
{
    QString originFileName = xmlFile->fileName();
    xmlFile->setFileName(xmlFilePath);
    bool sucess = WriteXml();
     xmlFile->setFileName(originFileName);
    return  sucess;
}


/**public methord
 *节点增删改查
 **/


/** @brief 给父节点parent增加一个名为nodeName的空节点
  * @param
  * @param
  * @retval None
  */
QDomElement XmlController::AddChildNode(QDomElement parent,QString nodeName)
{
    QDomElement childNode=doc->createElement(nodeName);
    parent.appendChild(childNode);
    return childNode;
}

void XmlController::AddChildNode(QDomNode childNode,QDomElement parent)
{
    parent.appendChild(childNode);
}

/** @brief 给父节点parent增加一个名为nodeName的子节点，
  * 子节点的属性由map传入
  * @param
  * @param
  * @retval None
  */
QDomElement XmlController::AddChildNode(QDomElement parent,QString nodeName,
                                         QMap<QString,QString> attributeData)
{
    QDomElement childNode=doc->createElement(nodeName);

    foreach(auto v ,attributeData)
    {
        childNode.setAttribute(v,attributeData[v]);
    }
    parent.appendChild(childNode);
    return childNode;
}

/** @brief 删除节点childNode
  * @param
  * @param
  * @retval None
  */
bool XmlController::RemoveChildNode(QDomNode childNode)
{
    auto res = childNode.parentNode().removeChild(childNode);
    childNode.clear();
    return  true;
}

/** @brief 删除节点selectedNode
  * @param
  * @param
  * @retval None
  */
bool XmlController::RemoveChildNode(QList<QDomNode> selectedNode)
{
   foreach(auto n ,selectedNode)
   {
       RemoveChildNode(n);
   }

   return  true;
}

/** @brief 修改节点属性
  * @param
  * @param
  * @retval None
  */
void XmlController::EditChildNodeAttribute(QDomElement toEditNode,QString attribute, QString val)
{
   auto currentAttribute = toEditNode.attributes();
   if(currentAttribute.contains(attribute))
       toEditNode.attribute(attribute) = val;
   else {
      toEditNode.setAttribute(attribute,val);
   }
}

/** @brief 修改节点属性
  * @param toEditNode 待修改的节点对象
  * @param attribute 修改的内容，若原有节点存在同名属性则修改属性值，若不存在对应属性创建新的属性再写入
  * @retval None
  */
void XmlController::EditChildNodeAttribute(QDomElement toEditNode, QMap<QString, QString> attribute)
{
    foreach(auto a ,attribute)
    {
        EditChildNodeAttribute(toEditNode,a,attribute[a]);
    }
}

/** @brief 查找连接着父节点的子节点
  * @param
  * @param
  * @retval None
  */
void XmlController::FindChildNode(QDomElement parent, QString nodeName,QList<QDomNode> selectedNode)
{
    for(int i = 0;i<parent.childNodes().count();i++)
    {
        if(parent.childNodes().at(i).nodeName()==nodeName){
          selectedNode.append(parent.childNodes().at(i));
        }
    }

}

/** @brief 以迭代的方式查找节点，每一条节点匹配到nodeName或已经到了末端节点，就会开始搜索下一条子节点
  * @param parent 搜索范围
  * @param nodeName 搜索条件
  * @param selectedNode 搜索结果
  */
void XmlController::FindChildNodeByIteration(QDomNode parent, QString nodeName, QList<QDomNode> selectedNode)
{
     auto childArry = parent.childNodes();
     for(int i = 0;i<childArry.count();i++)
     {
         if(childArry.at(i).nodeName()==nodeName){
             selectedNode.append(childArry.at(i));
         }
         else if (childArry.at(i).childNodes().size()>0) {
             FindChildNodeByIteration(childArry.at(i),nodeName,selectedNode);
         }
     }
}

/** @brief 通过标签名nodeName，查找存在的所有节点
  * @param
  * @param
  * @retval None
  */
QDomNodeList XmlController::FindChildNodeByTargetName(QString targetName)
{
   return doc->elementsByTagName(targetName);//由标签名定位
}

/** @brief 通过标签名和父节点名字来筛选结果
  * @param
  * @param selectedNode 查找的结果
  * @retval None
  */
void XmlController::FindChildNodeByTargetName(QDomElement parent,QString targetName,QList<QDomNode> selectedNode)
{
   auto tempNodeList = FindChildNodeByTargetName(targetName);
   for(int i=0;i<tempNodeList.count();i++)
   {
       if(tempNodeList.item(i).parentNode()!=parent)
        selectedNode.append(tempNodeList.item(i));
   }
}

/** @brief 通过指定的筛选方式和指定的筛选参数来筛选结果(未完成)，此处应该是终极的方法
  * @param
  * @param
  * @retval None
  */
void XmlController::FindNodeByFilter(QList<QDomNode> source, QMap<QString, QString> attributeFilter,QList<QDomNode>selectedNode)
{
    throw "未完成";
    bool canSave;
    foreach(auto s ,source)
    {
        canSave=true;
        foreach(auto v ,attributeFilter)
        {
           if(false)//关键
           {
               canSave=false;
               break;
           }
        }
        if(canSave)
            selectedNode.append(s);
    }
}


/**private methord**/



/** @brief 创建xml标准头文件
  * @param
  * @param
  * @retval None
  */
void XmlController::CreateProcessingInstruction()
{
    QDomProcessingInstruction instruction; //添加处理命令
    instruction=doc->createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc->appendChild(instruction);
}


/** @brief 创建根节点
  * @param
  * @param
  * @retval None
  *     返回false:
  *     1.doc存在其他节点，即必然存在根节点
  */
bool XmlController::CreateRoot(QString rootName)
{
  auto i=  doc->childNodes().at(0).nodeName();
    if(doc->childNodes().size()>1)
        return false;

    //创建根节点
    QDomElement root=doc->createElement(rootName);
    doc->appendChild(root);
    return true;
}

/** @brief 属性名target是否存在于source
  * @param
  * @param
  * @retval None
  */
bool XmlController::IsContainTargetAttributeName(QDomNamedNodeMap source, QString target)
{
    return source.contains(target);
}
















