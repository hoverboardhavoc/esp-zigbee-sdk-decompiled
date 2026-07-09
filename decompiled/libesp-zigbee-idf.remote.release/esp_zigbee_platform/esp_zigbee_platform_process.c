/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_platform.o -> esp_zigbee_platform_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_platform_process(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = s_workflow_list;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = (**(code **)(iVar1 + 0x18))(param_1,*(code **)(iVar1 + 0x18));
    if (iVar2 != 0) break;
    iVar1 = *(int *)(iVar1 + 0x1c);
  }
  return iVar2;
}

