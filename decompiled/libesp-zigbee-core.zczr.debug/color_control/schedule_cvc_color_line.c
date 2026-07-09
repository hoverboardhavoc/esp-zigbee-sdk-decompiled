/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> schedule_cvc_color_line
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 schedule_cvc_color_line(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_14 [3];
  
  iVar1 = color_control_srv_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    uVar2 = 0x86;
  }
  else {
    auStack_14[0] = *(undefined4 *)(iVar1 + 8);
    zcl_cvc_stop();
    iVar1 = zcl_cvc_ctx_create(param_1,auStack_14);
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      zcl_cvc_start(auStack_14[0]);
      uVar2 = 0;
    }
  }
  return uVar2;
}

