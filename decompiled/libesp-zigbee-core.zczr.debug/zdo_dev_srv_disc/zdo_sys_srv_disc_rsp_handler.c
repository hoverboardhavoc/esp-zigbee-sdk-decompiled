/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_sys_srv_disc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_sys_srv_disc_rsp_handler(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint auStack_14 [3];
  
  auStack_14[0] = 0;
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar2 = 0xfe;
  }
  else {
    iVar1 = zdo_op_sys_srv_disc_rsp(auStack_14,0);
    if (iVar1 == 0) {
      if ((auStack_14[0] & 0x400000) != 0) {
        iVar1 = core_globals_get();
        *(undefined2 *)(iVar1 + 0x9dc) = *(undefined2 *)(param_1 + 4);
      }
      uVar2 = zdo_cb_sys_srv_disc_rsp(auStack_14,param_1 + 8);
    }
    else {
      uVar2 = 0xfe;
    }
  }
  return uVar2;
}

