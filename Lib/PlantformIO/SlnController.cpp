#include "SlnController.h"
Sln::Sln()
{
    ProjFactory projFactory();
}
Sln::Sln(QString slnConfigFilePath,QString slnName)
{
    this->slnConfigFilePath=slnConfigFilePath;
    this->slnName = slnName;
    projFactory.ReadProjets(slnConfigFilePath);
   // this->Read(slnConfigFilePath);
}


/**SlnController**/

/** @brief 添加一个项目
  * @param
  * @param
  * @retval None
  */
void Sln::AddProj(Project proj)
{
    projFactory.projList->append(proj);
}

/** @brief 卸载一个项目
  * @param
  * @param
  * @retval None
  */
void Sln::UnLoadProj(int index)
{
    Project selected = projFactory.projList->at(index);
    selected.SetProjLoad(false);
}

/** @brief 加载一个项目
  * @param
  * @param
  * @retval None
  */
void Sln::LoadProj(int index)
{
    Project selected = this->projFactory.projList->at(index);
    selected.SetProjLoad(true);
}

/** @brief 删除项目
  * @param
  * @param
  * @retval None
  */
void Sln::DeleteProj(int index)
{
    this->projFactory.projList->removeAt(index);
}

/** @brief 设置项目文件路径
  * @param
  * @param
  * @retval None
  */
QString Sln::GetSlnName()
{
    return slnName;
}

void Sln::SetSlnName(QString val)
{
    slnName = val;
}

/** @brief 设置项目文件路径
  * @param
  * @param
  * @retval None
  */
void  Sln::SetSlnConfigFilePath(QString val)
{
    slnConfigFilePath = val;
}

/** @brief 获取sln文件路径
  * @param
  * @param
  * @retval None
  */
QString Sln::GetSlnConfigFilePath()
{
    return slnConfigFilePath;
}


/**IO Operation**/

/** @brief 创建新的解决方案
  * @param
  * @param
  * @retval None
  */
Sln Sln::Create()
{
    return Sln("新建解决方案.sln","新建解决方案");
}

/** @brief 从指定文件读取解决方案
  * @param
  * @param
  * @retval None
  */
Sln Sln::Read(QString slnFilePath)
{
    XmlController *xml=new XmlController(slnFilePath,QFile::OpenModeFlag::ReadOnly);
    QDomElement root = xml->GetRootNode();

    auto slnConfigFilePath = root.attributeNode("slnConfigFilePath").value();
    auto slnName = root.attributeNode("slnName").value();
    Sln sln(slnConfigFilePath,slnName);
    auto child = root.childNodes();
    for(int i = 0;i<child.count();i++)
    {
        sln.AddProj(Project::Read(child.at(i)));
    }
    return sln;
}

void Sln::Save()
{
    XmlController *xml=new XmlController(GetSlnConfigFilePath(),
                                         QFile::OpenModeFlag::WriteOnly);
    QDomElement root = xml->GetRootNode();
    root.setAttribute("SlnName",GetSlnName());
    root.setAttribute("SlnConfigFilePath",GetSlnConfigFilePath());

    for(int i=0;i<projFactory.projList->count();i++)
    {
        QDomElement porjNode = xml->doc->createElement("ProjectID");
        porjNode.setNodeValue(QString::number(i));
        Project currentProj = projFactory.projList->at(i);
        Project::Save(currentProj,porjNode);
        root.appendChild(porjNode);
    }
    xml->WriteXml();
}

/** @brief sln保存至本地
  * @param
  * @param
  * @retval None
  */
void Sln::Save(Sln sln)
{
    XmlController *xml=new XmlController(sln.GetSlnConfigFilePath(),
                                         QFile::OpenModeFlag::WriteOnly);
    QDomElement root = xml->GetRootNode();
    root.setAttribute("SlnName",sln.GetSlnName());
    root.setAttribute("SlnConfigFilePath",sln.GetSlnConfigFilePath());

    for(int i=0;i<sln.projFactory.projList->count();i++)
    {
        QDomElement porjNode = xml->doc->createElement("ProjectID");
        porjNode.setNodeValue(QString::number(i));
        Project currentProj = sln.projFactory.projList->at(i);
        Project::Save(currentProj,porjNode);
        root.appendChild(porjNode);
    }
    xml->WriteXml(sln.GetSlnConfigFilePath());
}












