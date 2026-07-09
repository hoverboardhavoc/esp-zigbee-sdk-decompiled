/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_schedule_cnf_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_data_schedule_cnf_cb(int param_1)

{
  short sVar1;
  int *unaff_s0;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0x57,
                  "af_data_schedule_cnf_cb",0x10000);
    goto _L0;
  }
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0xca4);
  if (iVar3 == 0) {
    uVar2 = 5;
  }
  else {
    while (unaff_s0 = (int *)(iVar3 + -0xc), unaff_s0 != (int *)0xfffffff4) {
      if ((unaff_s0 != (int *)0x0) && (*unaff_s0 == *(int *)(param_1 + 0x14))) {
        iVar4 = core_globals_get();
        list_remove_node(iVar4 + 0xca4,iVar3);
        break;
      }
_L0:
      iVar3 = unaff_s0[3];
    }
    if (unaff_s0 == (int *)0xfffffff4) {
      uVar2 = 5;
    }
    else if (unaff_s0 == (int *)0x0) {
      uVar2 = 5;
    }
    else {
      sVar1 = *(short *)(param_1 + 0xe);
      if ((sVar1 == 0x104) || (sVar1 == -0x3fa2)) {
        zcl_confirm_handler(param_1,iVar3 + -8);
        uVar2 = 0;
      }
      else if (sVar1 == 0) {
        zdo_confirm_handler(param_1,iVar3 + -8);
        uVar2 = 0;
      }
      else {
        uVar2 = 6;
      }
      mm_free(unaff_s0);
    }
  }
  return uVar2;
}

