/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> crypto_aes_mmo_hash_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_aes_mmo_hash_update(uint *param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *extraout_a1;
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  if (param_1 == (uint *)0x0) {
    param_3 = 0;
    param_1 = (uint *)__assert_func(0,0);
    param_2 = extraout_a1;
  }
  if ((param_2 != (undefined1 *)0x0) && (param_3 != 0)) {
    uVar2 = *param_1 & 0xf;
    *param_1 = *param_1 + param_3;
    if (uVar2 != 0) {
      iVar1 = (int)param_1 + uVar2;
      do {
        *(undefined1 *)(iVar1 + 0x14) = *param_2;
        param_3 = param_3 - 1 & 0xffff;
        param_2 = param_2 + 1;
        uVar2 = uVar2 + 1 & 0xff;
        if (param_3 == 0) {
          if (uVar2 != 0x10) goto _L17;
          break;
        }
        iVar1 = iVar1 + 1;
      } while (uVar2 != 0x10);
      aes_mmo_hash_core(param_1 + 5,param_1 + 1);
    }
_L17:
    for (puVar3 = param_2; 0xf < (((uint)(param_2 + param_3) & 0xffff) - (int)puVar3 & 0xffff);
        puVar3 = puVar3 + 0x10) {
      aes_mmo_hash_core(puVar3,param_1 + 1);
    }
    uVar2 = param_3 + (param_3 >> 4) * -0x10 & 0xffff;
    if (uVar2 != 0) {
      memcpy(param_1 + 5,param_2 + (param_3 >> 4) * 0x10,uVar2);
      return;
    }
  }
  return;
}

