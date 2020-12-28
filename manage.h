//
// Created by 86147 on 2020/12/26.
//

#ifndef BMS_MANAGE_H
#define BMS_MANAGE_H

#define PENALTY 0.1//罚金0.1元一天
#define CREDIT_VALUE_PENALTY 2;//信用值超时一次减少2
#define DEADLINE 30//最长借书时间30天
#define ISLost 360//超过360没归还默认丢失

void Home();
void Land();
void User(char account[]);
void Manager(char account[]);
void Contact_developer();
char Check();


/*图书类别代号
A马克思主义、列宁主义、毛泽东思想、邓小平理论
B哲学、宗教
C社会科学总论
D政治、法律
E军事
F经济
G文化、科学、教育、体育
H语言、文字
I文学
J艺术
K历史、地理
N自然科学总论
O数理科学和化学
P天文学、地球科学
Q生物科学
R医药、卫生
S农业科学
T工业技术
U交通运输
V航空、航天
X环境科学、安全科学
Z综合性图书*/

typedef struct Books {
    char book_id[10];//编号
    char title[30];//书名
    char publisher[20];//出版社
    int book_version;//第几版
    char author[40];//作者
    float price;//价格
    int number;//图书数量
    char available;//是否借走
    struct Books *next;
}Books;

typedef struct Students {
    unsigned long int student_id;//学号
    char name[15];//姓名
    char class[15];//班级
    char phone_number[15];//联系方式
    int account_balance;//账户余额
    int credit_value;//信用值
}Students;

typedef struct History{//借阅历史
    unsigned long int student_id;//学号
    char books[10];//借用的书籍
    long int start_time;//借书开始时间
    int borrow_day;//借书时长（天）
    float penalty;//违约金
    struct History *next;
}History,history;

void Penalty(struct History *pHistory,struct Students *pStudents);//罚金机制
void find_book();//查询图书
void find_name_book();//按名字查询
void find_author_book();//按作者查询
void find_publish_book();//按出版社查询
void find_kinds_book();//按类别查询
Books *creat(void);//将文件中的内容读出到链表中，返回值为表头地址
void input_book();//录入图书
void save_book(Books *p);//保存图书进文件
void lend_book();
void return_book();
void book_delete(char bookname[]);
void book_return();

int Login_in();//登录函数
int Register();//注册函数
void Login_manage_home();
void Login_user_home();
void Change_user_password(char account[]);
void Change_manage_password(char account[]);

#endif //BMS_MANAGE_H
