#ifndef SLNCONTROLLER_H
#define SLNCONTROLLER_H
#include "Lib/PlantformIO/ProjController.h"
#include "Lib/PlantformIO/InterfaceSlnController.h"

/** @brief 解决方案配置文件
  * @param
  * @param
  * @retval None
  */
class Sln //:ISlnController
{
private:
    QDomNode baseNode;

    //*.sln文件路径
    QString slnConfigFilePath;

    //解决方案名
    QString slnName;

    //所有的项目
    ProjFactory projFactory;
public:
    Sln();
    Sln(QString slnConfigFilePath,QString slnName);

    /**Sln Controller**/
    void AddProj(Project proj) ;//override;
    void UnLoadProj(int index) ;//override;
    void LoadProj(int index) ;//override;
    void DeleteProj(int index); //override;

    QString GetSlnConfigFilePath();
    void SetSlnConfigFilePath(QString val);
    QString GetSlnName();
    void SetSlnName(QString val);
    /**Sln IO Operation**/
    static Sln Create();
    static Sln Read(QString slnFilePath);
    void Save();
    static void Save(Sln sln);
 };



#endif // SLNCONTROLLER_H
