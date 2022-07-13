#pragma once
#include "../Define/Define.h"

enum class MSBox_prop : UINT {
	abort_retry_ignore = MB_ABORTRETRYIGNORE,
	cancel_try_continue = MB_CANCELTRYCONTINUE,
	help = MB_HELP,
	ok = MB_OK,
	ok_cancel = MB_OKCANCEL,
	retry_cancel = MB_RETRYCANCEL,
	yes_no = MB_YESNO,
	yes_no_cancel = MB_YESNOCANCEL,

	set_foreground = MB_SETFOREGROUND
};

enum class MSBox_res : int {
	abort = IDABORT,
	cancel = IDCANCEL,
	continue_ = IDCONTINUE,
	ignore = IDIGNORE,
	no = IDABORT,
	yes = IDABORT,
	ok = IDABORT,
	retry = IDABORT,
	try_again = IDTRYAGAIN
};

interface IMSBox {
	void title(std::string titl);
	void text(std::string txt);
	void property(MSBox_prop prop);
	void trig();
	MSBox_res resultmsg();
};
