
#define WANT_TO_EXIT (0)
#define MODE_NONE (1)
#define MODE_TEACHER (2)
#define MODE_STUDENT (3)

#define MAX_NAME_LEN (50)
#define MAX_STUDENTS (30)

typedef struct student
{
	char name[MAX_NAME_LEN];
	char class_;
	int register_number;
	
	float maths_mark;
	float history_mark;
	// etc. add as many marks as you wish
} student;

typedef struct student_array
{
	student data[MAX_STUDENTS];
	int count;
} student_array;


// add student entry to array. return 0 if fail, return 1 if success
// this function will call all scanfs
int add_student(student_array* arr);

// will print all student data. will scanf name and\or reg id 
// return 0 if fail, return 1 if success
int query_student(student_array* arr);


int menu_prompt();

int teacher_prompt(student_array* arr);
int student_prompt(student_array* arr);

void print_student(student* s);