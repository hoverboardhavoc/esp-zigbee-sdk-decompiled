/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> crypto_aes_mmo_hash_finish
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_aes_mmo_hash_finish(uint *param_1,void *param_2,uint param_3,undefined2 *param_4)

{
  uint uVar1;
  void *extraout_a1;
  void *extraout_a1_00;
  uint *__src;
  uint __n;
  int iVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 != (uint *)0x0) goto _L0;
  do {
    param_4 = (undefined2 *)0x0;
    param_3 = 0;
    param_1 = (uint *)__assert_func(0,0);
    param_2 = extraout_a1;
_L0:
    if (param_3 < 0x10) {
      param_1 = (uint *)crypto_aes_mmo_hash_finish_part_0();
      param_2 = extraout_a1_00;
    }
    uVar1 = *param_1;
    __src = param_1 + 1;
    __n = uVar1 & 0xf;
  } while (0x1fffffff < uVar1);
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (__n != 0) {
    memcpy(&local_30,param_1 + 5,__n);
  }
  *(undefined1 *)((int)&local_30 + __n) = 0x80;
  iVar2 = 6;
  if (uVar1 < 0x2000) {
    iVar2 = 2;
  }
  if (0x10 < __n + 1 + iVar2) {
    aes_mmo_hash_core(&local_30,__src);
    local_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
  }
  if (iVar2 == 2) {
    uStack_24 = CONCAT22((ushort)(byte)((uVar1 << 0x13) >> 0x18) | (ushort)(uVar1 << 0xb),
                         (undefined2)uStack_24);
  }
  else {
    uStack_28 = CONCAT22((ushort)((uVar1 << 3) >> 8) & 0xff00 | (ushort)(byte)((uVar1 << 3) >> 0x18)
                         ,(undefined2)uStack_28);
    uStack_24 = CONCAT22(uStack_24._2_2_,
                         (ushort)((uVar1 << 0x1b) >> 0x10) |
                         (ushort)(((uVar1 & 0x1fe0) << 0xb) >> 0x10));
  }
  aes_mmo_hash_core(&local_30,__src);
  memcpy(param_2,__src,0x10);
  *param_4 = 0x10;
  return;
}

