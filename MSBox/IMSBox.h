#pragma once
#include "../Define/Define.h"
#include "../Wind/Wind.h"

enum MSBox_prop : UINT {
	MSBox_prop__abort_retry_ignore = MB_ABORTRETRYIGNORE,
	MSBox_prop__cancel_try_continue = MB_CANCELTRYCONTINUE,
	msbox_prop__help = MB_HELP,
	MSBox_prop__ok = MB_OK,
	MSBox_prop__ok_cancel = MB_OKCANCEL,
	MSBox_prop__retry_cancel = MB_RETRYCANCEL,
	MSBox_prop__yes_no = MB_YESNO,
	MSBox_prop__yes_no_cancel = MB_YESNOCANCEL,

	MSBox_prop__set_foreground = MB_SETFOREGROUND
};

enum MSBox_res : int {
	MSBox_res__abort = IDABORT,
	MSBox_res__cancel = IDCANCEL,
	MSBox_res__continue = IDCONTINUE,
	MSBox_res__ignore = IDIGNORE,
	MSBox_res__no = IDABORT,
	MSBox_res__yes = IDABORT,
	MSBox_res__ok = IDABORT,
	MSBox_res__retry = IDABORT,
	MSBox_res__try_again = IDTRYAGAIN
};

interface IMSBox : public ITitle {
	void text(std::wstring txt);
	void property(MSBox_prop prop);
	void trig();
	MSBox_res resultmsg();
};
