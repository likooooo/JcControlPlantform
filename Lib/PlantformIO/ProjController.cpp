#include "ProjController.h"


/**ProjConfig
 *
 **/


Project:: Project(QString projName,QString projFilePath)
{
    this->SetProjName(projName);
    this->SetProjFilePath(projFilePath);
    this->SetProjLoad(true);
}

Project::~Project()
{
    this->projNamePair = NULL;
    this->projFilePathPair = NULL;
    this->isLoadPair = NULL;
}

/** @brief 获取Proj的名称
  * @param
  * @param
  * @retval None
  */
QString Project::GetProjName()
{
    return  this->projNamePair->second;
}

/** @brief 设置Proj的名称
  * @param
  * @param
  * @retval None
  */
void Project::SetProjName(QString projName)
{
    this->projNamePair->second = projName;
}

/** @brief 获取配置文件路径
  * @param
  * @param
  * @retval None
  */
QString Project::GetProjFilePath()
{
    return this->projFilePathPair->second;
}

/** @brief 依据projName,生成默认的projFilePath
  * @param
  * @param
  * @retval None
  */
QString Project::GetDefinedFilePath()
{
    return GetProjName()+".proj";
}

/** @brief 设置配置文件路径
  * @param
  * @param
  * @retval None
  */
void Project::SetProjFilePath(QString projFilePath)
{
    this->projFilePathPair->second = projFilePath;
}

/** @brief 获取当前proj是否导入
  * @param
  * @param
  * @retval None
  */
bool Project::GetProjLoad()
{
    return isLoad;
}

/** @brief 获取当前proj是否导入的状态在文本中的信息
  * @param
  * @param
  * @retval None
  */
QString Project::GetProjLoadString()
{
    return this->isLoadPair->second;
}

/** @brief 设定proj导入状态
  * @param
  * @param
  * @retval None
  */
void Project::SetProjLoad(bool val)
{
    isLoad = val;
    this->isLoadPair->second = val?"true":"false";
}


/**IO Operation**/


/** @brief 保存当前*.proj
  * @param
  * @param
  * @retval None
  */
void Project::Save()
{
    throw " ";
  // Project::Save(this,GetProjFilePath());
}

/** @brief 创建新项目
  * @param
  * @param
  * @retval None
  */
Project Project::Create()
{
    QString projName = "新建Proj";
    QString projFilePath = projName+".proj";
    return Project(projName,projFilePath);
}

/** @brief 从parent中读取数据，创建proj
  * @param
  * @param
  * @retval None
  */
Project Project::Read(QDomElement parent)
{
    auto xmlFilePath = parent.attributeNode("projConfigFilePath").value();
    auto projName = parent.attributeNode("projName").value();
    auto isLoad = parent.attributeNode("isLoad").value();
    Project p(projName,xmlFilePath);
    p.SetProjLoad((isLoad=="true")?true:false);
    return p;
}

/** @brief 从parent中读取数据，创建proj
  * @param
  * @param
  * @retval None
  */
Project Project::Read(QDomNode parent)
{
    auto xmlFilePath =  parent.attributes().namedItem("projConfigFilePath").nodeValue();
    auto projName =  parent.attributes().namedItem("projName").nodeValue();
    auto isLoad =  parent.attributes().namedItem("isLoad").nodeValue();
    Project p(projName,xmlFilePath);
    p.SetProjLoad((isLoad=="true")?true:false);
    return p;
}

///** @brief 保存Project
//  * @param
//  * @param
//  * @retval None
//  */
//void Project::Save(Project* p,QString saveToWhere)
//{
//    XmlController *xml=new XmlController(p->GetProjFilePath(),
//                                         QFile::OpenModeFlag::WriteOnly);
//    auto root = xml->GetRootNode();
//    root.setAttribute("projName",p->GetProjName());
//    root.setAttribute("projConfigFilePath",p->GetProjFilePath());
//    root.setAttribute("isLoad",p->GetProjLoad());
//    xml->WriteXml(saveToWhere);
//}

/** @brief proj保存至指定节点
  * @param
  * @param
  * @retval None
  */
void Project:: Save(Project* p,QDomElement parent)
{
    parent.setAttribute("projName",p->GetProjName());
    parent.setAttribute("projConfigFilePath",p->GetProjFilePath());
    parent.setAttribute("isLoad",p->GetProjLoad());
}

/** @brief proj保存至指定节点
  * @param
  * @param
  * @retval None
  */
void Project::Save(Project p, QDomElement parent)
{
    parent.setAttribute("projName",p.GetProjName());
    parent.setAttribute("projConfigFilePath",p.GetProjFilePath());
    parent.setAttribute("isLoad",p.GetProjLoad());
}


/**ProjController
 *
 **/



ProjFactory::ProjFactory()
{
    this->projList = new QList<Project>() ;
}

/** @brief 析构函数
  * @param
  * @param
  * @retval None
  */
ProjFactory::~ProjFactory()
{
    delete projList;
}

/** @brief 创建一个空对象
  * @param
  * @param
  * @retval None
  */
Project ProjFactory::CreateNewProj()
{
    auto res = Project::Create();
    projList->append(res);
    return  res;
}

/** @brief 导入项目
  * @param
  * @param
  * @retval None
  */
QList<Project>* ProjFactory::ReadProjets(QString filePath)
{

    XmlController *xml =new XmlController(filePath,QFile::OpenModeFlag::ReadOnly);
    auto projXmlArry=xml->GetRootNode().elementsByTagName("proj");
    QList<Project> *res =new QList<Project>();
    for(int i=0;i<projXmlArry.size();i++)
    {
        res->append(Project::Read(projXmlArry.at(i)));
    }
    delete projList;
    projList = res;
    return res;
}

