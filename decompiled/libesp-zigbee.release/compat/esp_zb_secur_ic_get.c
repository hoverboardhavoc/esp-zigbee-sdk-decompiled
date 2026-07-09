/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_secur_ic_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * esp_zb_secur_ic_get(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = ezb_secur_ic_get(ic_0,param_1);
  if (iVar1 == 0) {
    puVar2 = ic_0;
  }
  else {
    puVar2 = (undefined1 *)0x0;
  }
  return puVar2;
}

