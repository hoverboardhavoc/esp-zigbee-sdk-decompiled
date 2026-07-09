/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_req_get_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_mgmt_req_get_param(int param_1)

{
  int iVar1;
  int iVar2;
  int extraout_a1;
  int *piVar3;
  
  if (param_1 != 0) {
    return param_1 + 8;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_management.c",0x66,
                        "zdo_mgmt_req_get_param","handle != ((void *)0)");
  if (iVar1 == 0) {
    iVar1 = 2;
  }
  else {
    iVar2 = core_globals_get();
    piVar3 = (int *)(iVar2 + 0xce0);
    iVar2 = *piVar3;
    while (iVar2 != 0) {
      piVar3 = (int *)*piVar3;
      iVar2 = *piVar3;
    }
    *(undefined4 *)(iVar1 + 4) = 0;
    *piVar3 = iVar1 + 4;
    if (extraout_a1 == 0) {
      iVar1 = core_globals_get();
      tasklet_post(iVar1 + 0xce4);
      iVar1 = 0;
    }
    else {
      zdo_mgmt_task(iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

