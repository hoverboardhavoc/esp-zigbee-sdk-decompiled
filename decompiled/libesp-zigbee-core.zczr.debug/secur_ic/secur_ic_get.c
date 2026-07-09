/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> secur_ic_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 secur_ic_get(void *param_1,undefined1 *param_2)

{
  size_t __n;
  undefined4 uVar1;
  undefined1 auStack_38 [8];
  undefined1 uStack_30;
  undefined1 auStack_2f [21];
  char cStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 2;
  }
  else if (param_2 == (undefined1 *)0x0) {
    uVar1 = 2;
  }
  else {
    uStack_18 = 0;
    uStack_14 = 0;
    secur_ic_get_stored_ic(&uStack_18,auStack_38);
    if (cStack_1a == '\0') {
      *param_2 = uStack_30;
      __n = ic_size();
      memcpy(param_1,auStack_2f,__n);
      uVar1 = 0;
    }
    else {
      uVar1 = 5;
    }
  }
  return uVar1;
}

