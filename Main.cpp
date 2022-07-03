// Mailbox Akutonn.cpp: определяет точку входа для приложения.
//

#include "Main.h"

int main()
{
	MSBoxErr ms(NULL);
	ms.add_property(MSBox_prop__ok);
	ms.add_title(L"Title");
	ms.add_text(L"Text");
	ms.trig();

	return 0;
}
