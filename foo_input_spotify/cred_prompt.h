#include <vector>
#include <memory>
#include "../../pfc/pfc.h"

const size_t CRED_BUF_SIZE = 0xff;

struct CredPromptResult : boost::noncopyable {
	CredPromptResult() : 
		un(std::vector<char>(CRED_BUF_SIZE)), 
		pw(std::vector<char>(CRED_BUF_SIZE)),
		save(true),
		cancelled(false) {
	}

	~CredPromptResult() {
		SecureZeroMemory(pw.data(), pw.size());
	}

	std::vector<char> un, pw;
	bool save;
	bool cancelled;
	
};

std::auto_ptr <CredPromptResult> credPrompt(const char * msg);
