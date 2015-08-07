/*******************************************************************************
* Copyright (c) 2015 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "mon_bootstrap_utils.h"
#include "policy_manager.h"
#include "mon_addons.h"
#include "mon_dbg.h"
#include <tscdt_emulator_api.h>
#include "file_codes.h"

#define MON_DEADLOOP()          MON_DEADLOOP_LOG(ADDONS_C)
#define MON_ASSERT(__condition) MON_ASSERT_LOG(ADDONS_C, __condition)

void start_addons(uint32_t num_of_cpus,
		  const mon_startup_struct_t *startup_struct,
		  const mon_application_params_struct_t *
		  application_params_struct UNUSED)
{
	MON_LOG(mask_anonymous, level_trace, "start addons\r\n");

	if (global_policy_uses_ept()) {
		init_ept_addon(num_of_cpus);
	} else {
		MON_LOG(mask_anonymous, level_error, "No supported addons\r\n");
		MON_DEADLOOP();
	}
}