#ifndef PROJECT
#define PROJECT
/*
　　参加运动会有n个学校，学校编号为1⋯⋯n。比赛分成m个男子项目，和w个女子项目。项目编号为男子1⋯⋯m，女子m+1⋯⋯m+w。不同的项目取前五名或前三名积分；取前五名的积分分别为：7、5、3、2、1，前三名的积分分别为：5、3、2；哪些取前五名或前三名由学生自己设定。（m<=20,n<=20）
　　【基本要求】
　　（1）可以输入各个项目的前三名或前五名的成绩；
　　（2）能统计各学校总分，
　　（3）可以按学校编号或名称、学校总分、男女团体总分排序输出；
　　（4）可以按学校编号查询学校某个项目的情况；可以按项目编号查询取得前三或前五名的学校。
　　（5）存储结构自选，但要求运动会的相关数据存入并能随时查询
　　（6）规定：输入数据形式和范围：可以输入学校的名称，运动项目的名称
　　（7）输出形式：有中文提示，各学校分数为整形
    （8）界面要求：有合理的提示，每个功能可以设立菜单，根据提示，可以完成相关的功能要求。
*/

//学院信息结构体
typedef struct College
{
    int college_id;            //学院编号
    char college_name[20];      //学院名称
    int college_score;         //学院总分
    int man_score;            //男团分数
    int woman_score;          //女团分数
    struct College* next;
}CollegeNode;

//项目信息结构体
typedef struct Project
{
    int project_id;           //项目编号
    char project_name[20];  //项目名称
    char sex[5];            //男女团体
    int power;               //计分方式
    int College[100];        //获奖学校
    struct Project* next;
}ProjectNode;

//学院、项目信息初始化
void IntiInfo(CollegeNode*& pHead, ProjectNode*& ppEnd);

//链表操作
CollegeNode* GetCollegeNode(CollegeNode*& pHead, CollegeNode*& p, int& id_s);
ProjectNode* GetProjectNode(ProjectNode*& ppHead, ProjectNode*& p, int& id_p);


//输入项目成绩信息
void InputScore(ProjectNode* pnode, CollegeNode* pHead);


//计分函数
void AddCollegeScore(CollegeNode* pHead, ProjectNode* pNode, int id, int sort);

//修改模块
int CollegeModify(CollegeNode* head, ProjectNode* pNode);

//删除函数 删除学院，删除项目
int CollegeNodeDel(CollegeNode*& head, ProjectNode*& pNode);

//查询学院 模糊查找
int CollegeSearch(CollegeNode* head);
//查询项目
int ProjectSearch(ProjectNode* head, CollegeNode* chead);


//排序模块
void SortModule(CollegeNode*& pHead);
void ManScoreSort(CollegeNode*& pHead);
void WomanScoreSort(CollegeNode*& pHead);
void SchoolScoreSort(CollegeNode*& pHead);


//输出浏览浏览项目排名情况
void PrintProject(CollegeNode* pHead, ProjectNode* pNode);
//输出浏览学院得分情况
void PrintCollege(CollegeNode*& pHead);


//学院信息文件读取 读取到内存中
CollegeNode* CollegeFileRead(CollegeNode*& head); //读取到内存中
bool CollegeFileWrite(CollegeNode* pHead); //写入到文件中

//项目文件读写
ProjectNode* ProjectFileRead(ProjectNode*& head);//读取到内存中
bool ProjectFileWrite(ProjectNode* ppHead);//写入到文件中

#endif
