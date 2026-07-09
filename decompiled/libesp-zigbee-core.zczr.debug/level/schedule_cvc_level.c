/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> schedule_cvc_level
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 schedule_cvc_level(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = level_srv_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    uVar3 = 0x86;
  }
  else {
    zcl_cvc_stop(*(undefined4 *)(iVar1 + 8));
    iVar2 = zcl_cvc_ctx_create(param_1,iVar1 + 8);
    if (iVar2 == 0) {
      uVar3 = 1;
    }
    else {
      zcl_cvc_start(*(undefined4 *)(iVar1 + 8));
      uVar3 = 0;
    }
  }
  return uVar3;
}

