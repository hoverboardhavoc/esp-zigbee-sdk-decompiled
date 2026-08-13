/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> dlk.o -> crypto_dlk_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 crypto_dlk_init(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 2;
  if (param_1 == (byte *)0x0) {
    return 2;
  }
  if (param_2 != 2) {
    if (param_2 == 3) {
      param_2 = 2;
      goto _L0;
    }
    if (param_2 != 1) {
      return 6;
    }
  }
  iVar1 = 1;
_L0:
  *param_1 = (byte)param_2 | (byte)(iVar1 << 2) | (byte)(iVar1 << 5) | (byte)(param_3 << 7);
  crypto_ecdh_init(param_1 + 8);
  return 0;
}

