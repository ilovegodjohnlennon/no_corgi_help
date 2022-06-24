#include "student.h"




int main(void)
{
	int mode = MODE_NONE;
	
	student_array students;
	students.count = 0;
	
	while(mode != WANT_TO_EXIT)
	{
		switch(mode)
		{
			case MODE_NONE:
				mode = menu_prompt();
				break;
			case MODE_TEACHER:
				mode = teacher_prompt(&students);
				break;
			case MODE_STUDENT:
				mode = student_prompt(&students);
				break;
		}
	}
	
	
	return 0;
}