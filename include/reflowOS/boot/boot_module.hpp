#include <xparameters.h>

#include <cstddef>
#include <cstdint>
#include <cstring>

#define MODULE_STATIC(type) constexpr static type

#define MODULE_ITERATE_TABLE_START(it_var) for(int it_var = 0 ; it_var < 32 ; it_var++) {
#define MODULE_ITERATE_TABLE_END }

namespace reflowOS {
namespace boot 	   {

	typedef char  	      name_type[112]; // 112 Byte
	typedef std::uint64_t pointer_type  ; // 8 Byte
	typedef std::uint64_t size_type     ; // 8 Byte		==> Total 128 Byte. 4096 / 128 = 32. 32 Module can be added in Boot Progress.

	MODULE_STATIC(pointer_type) base_pointer = XPAR_MIG_7SERIES_0_BASEADDR;
	MODULE_STATIC(pointer_type) table_size   = 4096;
	MODULE_STATIC(pointer_type) entity_size  = 4096 * 32;

	MODULE_STATIC(std::uint64_t) module_table_section  = XPAR_MIG_7SERIES_0_BASEADDR;
	MODULE_STATIC(std::uint64_t) module_entity_section = module_table_section + 4096;

	struct module_entry
	{
		name_type    		 module_name;
		size_type    		 module_size;

		pointer_type 		 module_pointer;
		module_init_function module_init;
	}; // Total 128 Byte. 128 * 32 = 4096 Byte (1 Page).

	typedef module_table  module_entry 		   [32]   ;
	typedef std::uint8_t  module_entity		   [4096] ; // Allocated each modules. Total 32 Page. Thus Boot Module uses total 33 pages.
	typedef module_entity module_entity_section[32]   ;
	typedef void		(*module_init_function)(void*);

	void		  module_initialize	   ();

	template <typename ModuleType>
	ModuleType*   module_load  		   (const char*, module_init_function);
	template <typename ModuleType>
	void 		  module_unload		   (const char*);

	void*		  module_find  	 	   (const char*);
	module_entry* module_find_table	   (const char*);

	void*		  module_find_empty	     ();
	module_entry* module_find_empty_table();
}
}



template <typename ModuleType>
ModuleType* reflowOS::boot::module_load  (const char* name, module_init_function init)
{
	ModuleType  * mod_entity = reinterpret_cast<ModuleType*>(module_find_empty());
	module_entry* mod_entry  = module_find_empty_table();

	if(!mod_entity || !mod_entry)
		return nullptr;

	mod_entry->module_pointer = mod_entity;
	mod_entry->module_size    = sizeof(ModuleType);
	std::strcpy				   (mod_entry->module_name, name);

	return mod_entity;
}

template <typename ModuleType>
void reflowOS::boot::module_unload(const char* module_name)
{
	module_entry* fnd_module_entry = module_find_table(module_name);
	if(!fnd_module_entry)
		return;

	std::memset(fnd_module_entry->module_pointer, 0x00, fnd_module_entry->module_size);
	std::memset(fnd_module_entry				, 0x00, sizeof(module_entry));
}
