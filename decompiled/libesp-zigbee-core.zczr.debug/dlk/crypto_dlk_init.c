/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> dlk.o -> crypto_dlk_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 crypto_dlk_init(uint *param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (param_1 == (uint *)0x0) {
    uVar2 = 2;
  }
  else {
    if (param_2 == 2) {
      bVar1 = (byte)*param_1;
      *(byte *)param_1 = bVar1 & 0x9f | 0x20;
      *(byte *)param_1 = bVar1 & 0x83 | 0x24;
      *(byte *)param_1 = bVar1 & 0x80 | 0x26;
    }
    else if (param_2 == 3) {
      bVar1 = (byte)*param_1;
      *(byte *)param_1 = bVar1 & 0x9f | 0x40;
      *(byte *)param_1 = bVar1 & 0x83 | 0x48;
      *(byte *)param_1 = bVar1 & 0x80 | 0x4a;
    }
    else {
      if (param_2 != 1) {
        return 6;
      }
      bVar1 = (byte)*param_1;
      *(byte *)param_1 = bVar1 & 0x9f | 0x20;
      *(byte *)param_1 = bVar1 & 0x83 | 0x24;
      *(byte *)param_1 = bVar1 & 0x80 | 0x25;
    }
    *(byte *)param_1 = (byte)*param_1 & 0x7f | (byte)(param_3 << 7);
    crypto_ecdh_init(param_1 + 2,*param_1 >> 2 & 7);
    uVar2 = 0;
  }
  return uVar2;
}

