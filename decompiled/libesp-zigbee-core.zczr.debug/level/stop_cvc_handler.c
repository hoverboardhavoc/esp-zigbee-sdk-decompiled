/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> stop_cvc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 stop_cvc_handler(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = level_srv_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    uVar2 = 0x86;
  }
  else {
    zcl_cvc_stop(*(undefined4 *)(iVar1 + 8));
    uVar2 = 0;
  }
  return uVar2;
}

