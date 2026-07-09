/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_bind_and_unbind_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_bind_and_unbind_rsp_handler(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_14 [12];
  
  auStack_14[0] = 0;
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar2 = 0xfe;
  }
  else {
    iVar1 = zdo_op_bind_and_unbind_rsp(auStack_14,0);
    if (iVar1 == 0) {
      uVar2 = zdo_cb_bind_and_unbind_rsp(auStack_14,param_1 + 8);
    }
    else {
      uVar2 = 0xfe;
    }
  }
  return uVar2;
}

