/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_workflow.o -> zb_esp_workflow_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_workflow_update(undefined4 param_1)

{
  int iVar1;
  
  for (iVar1 = s_workflow_list; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
    (**(code **)(iVar1 + 0x10))(param_1,*(code **)(iVar1 + 0x10));
  }
  return;
}

