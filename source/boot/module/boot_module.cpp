#include <reflowOS/boot/boot_module.hpp>

void		  				  reflowOS::boot::module_initialize()
{
	std::memset((void*)reflowOS::boot::module_table_section, 0x00, 4096 * 3);
}

void* 						  reflowOS::boot::module_find  	   (const char* name)
{
	module_entry* fnd_table_entry = module_find_table(name);
	if(!fnd_table_entry)
		return nullptr;

	return (void*)fnd_table_entry->module_pointer;
}

reflowOS::boot::module_entry* reflowOS::boot::module_find_table	   (const char* name)
{
	module_entry* fnd_table_entry   = (module_entry*)module_table_section;

	MODULE_ITERATE_TABLE_START(it_table)
		if(std::strcmp(fnd_table_entry[it_table].module_name, name) == 0)
			return &fnd_table_entry[it_table];
	MODULE_ITERATE_TABLE_END

	return nullptr;
}

void* reflowOS::boot::module_find_empty()
{
	module_entry* fnd_table_entry   = (module_entry*)module_table_section;
	pointer_type  fnd_table_pointer = (pointer_type) module_entity_section;

	MODULE_ITERATE_TABLE_START(it_table)
		if(fnd_table_entry[it_table].module_name[0] == 0x00)
			return (void*)fnd_table_pointer;
		else
			fnd_table_pointer += fnd_table_entry[it_table].module_size;
	MODULE_ITERATE_TABLE_END

	return nullptr;
}

reflowOS::boot::module_entry* reflowOS::boot::module_find_empty_table()
{
	module_entry* fnd_table_entry = (module_entry*)module_table_section;

	MODULE_ITERATE_TABLE_START(it_table)
		if(fnd_table_entry[it_table].module_name[0] == 0x00)
			return &fnd_table_entry[it_table];
	MODULE_ITERATE_TABLE_END

	return nullptr;
}