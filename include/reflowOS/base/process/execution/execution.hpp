#include <reflowOS/base/process/basic_context.hpp>

namespace reflowOS {

	template <typename ExecPack>
	void execute(ExecPack*);

	template <typename ExecContext, typename ExecType, typename... ExecArgs>
	void execute(ExecContext&&, ExecType&&, ExecArgs&&...);
}

template <typename ExecContext, typename ExecType, typename... ExecArgs>
void reflowOS::execute(ExecContext&& exec_context, ExecType&& exec_proc, ExecArgs&&... exec_args)
{

}
