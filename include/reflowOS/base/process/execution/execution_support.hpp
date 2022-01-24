#include <tuple>
#include <utility>

namespace reflowOS {

	template <typename ExecType, typename... ExecArgs>
	struct execute_pack
	{
		typedef std::decay_t<ExecType>  exec_type;
		typedef std::tuple<ExecArgs...> args_type;

		exec_type execute_proc;
		args_type execute_args;
	};

	template <typename ExecType, typename... ExecArgs>
	auto   make_execute_pack(ExecType&& exec_proc, );
}
