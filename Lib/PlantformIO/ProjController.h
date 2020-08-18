#ifndef PROJCONTROLLER_H
#define PROJCONTROLLER_H
#include <QStringBuilder>

#include "XmlController.h"
namespace ProjectController {
class Project;
}

using namespace std;
/** @brief 项目配置文件
  * @param
  * @param
  * @retval None
  */
class Project
{
private:
    /**根节点参数**/

    //*.proj文件路径
    std::pair<QString,QString> *projFilePathPair = new std::pair<QString,QString>
    ("projConfigFilePath","");

    //项目名
    std::pair<QString,QString> *projNamePair = new std::pair<QString,QString>
    ("projName","");

    //是否加载到解决方案
    bool isLoad;
    std::pair<QString,QString> *isLoadPair = new std::pair<QString,QString>
    ("isLoad",isLoad?"true":"false");


public:
    Project();
    Project(QString projName,QString projFilePath);//:QDomNode();
    ~Project();

    //projName{get;set;}
    QString GetProjName();
    void SetProjName(QString projName);

    //ProjFilePath{get;set;}
    QString GetProjFilePath();
    QString GetDefinedFilePath();
    void SetProjFilePath(QString projFilePath);

    //IsProjLoad{get;set;}
    bool GetProjLoad();
    QString GetProjLoadString();
    void SetProjLoad(bool val);

    /**IO Operation**/
    void Save();

    static Project Create();
    static Project Read(QDomElement parent);
    static Project Read(QDomNode parent);
//    static void Save(Project* p,QString saveToWhere);
    static void Save(Project* p,QDomElement parent);
    static void Save(Project p,QDomElement parent);
};



class ProjFactory
{
public:
    QList<Project> *projList;//所有的*Proj

    ProjFactory();
    ~ProjFactory();
    /**IO Operation**/

    //新建项目
    Project CreateNewProj();
    //导入项目
    QList<Project>* ReadProjets(QString filePath);
};

#endif // PROJCONTROLLER_H
