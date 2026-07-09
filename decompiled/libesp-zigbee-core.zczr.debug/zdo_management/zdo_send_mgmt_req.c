/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_send_mgmt_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_send_mgmt_req(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else {
    iVar1 = core_globals_get();
    piVar3 = (int *)(iVar1 + 0xce0);
    iVar1 = *piVar3;
    while (iVar1 != 0) {
      piVar3 = (int *)*piVar3;
      iVar1 = *piVar3;
    }
    *(undefined4 *)(param_1 + 4) = 0;
    *piVar3 = param_1 + 4;
    if (param_2 == 0) {
      iVar1 = core_globals_get();
      tasklet_post(iVar1 + 0xce4);
      uVar2 = 0;
    }
    else {
      zdo_mgmt_task(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}

