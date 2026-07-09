/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur_ic.o -> secur_ic_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 secur_ic_get(void *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [8];
  undefined1 uStack_28;
  undefined1 auStack_27 [21];
  char cStack_12;
  
  if (param_1 != (void *)0x0) {
    uVar1 = 2;
    if (param_2 != (undefined1 *)0x0) {
      uStack_38 = 0;
      uStack_34 = 0;
      secur_ic_get_stored_ic(&uStack_38,auStack_30);
      uVar1 = 5;
      if (cStack_12 == '\0') {
        *param_2 = uStack_28;
        iVar2 = ic_crc_offset();
        memcpy(param_1,auStack_27,iVar2 + 2U & 0xff);
        uVar1 = 0;
      }
    }
    return uVar1;
  }
  return 2;
}

