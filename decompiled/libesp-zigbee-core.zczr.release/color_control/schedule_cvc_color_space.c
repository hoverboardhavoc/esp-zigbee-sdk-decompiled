/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> schedule_cvc_color_space
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 schedule_cvc_color_space(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_18;
  int aiStack_14 [2];
  
  iVar1 = color_control_srv_get_attr_desc_part_0();
  if (iVar1 == 0) {
    uVar2 = 0x86;
  }
  else {
    iStack_18 = *(int *)(iVar1 + 8);
    aiStack_14[0] = iStack_18 + 0x40;
    zcl_cvc_stop();
    zcl_cvc_stop(aiStack_14[0]);
    iVar1 = zcl_cvc_ctx_create(param_1,&iStack_18);
    if ((iVar1 == 0) || (iVar1 = zcl_cvc_ctx_create(param_2,aiStack_14), iVar1 == 0)) {
      uVar2 = 1;
    }
    else {
      zcl_cvc_start(iStack_18);
      zcl_cvc_start(aiStack_14[0]);
      uVar2 = 0;
    }
  }
  return uVar2;
}

