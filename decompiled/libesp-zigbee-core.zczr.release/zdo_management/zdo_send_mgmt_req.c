/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_send_mgmt_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_send_mgmt_req(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    iVar1 = core_globals_get();
    piVar2 = (int *)(iVar1 + 0xce0);
    iVar1 = *(int *)(iVar1 + 0xce0);
    while (iVar1 != 0) {
      piVar2 = (int *)*piVar2;
      iVar1 = *piVar2;
    }
    *(undefined4 *)(param_1 + 4) = 0;
    *piVar2 = param_1 + 4;
    if (param_2 == 0) {
      iVar1 = core_globals_get();
      tasklet_post(iVar1 + 0xce4);
    }
    else {
      zdo_mgmt_task(param_1);
    }
    return 0;
  }
  return 2;
}

