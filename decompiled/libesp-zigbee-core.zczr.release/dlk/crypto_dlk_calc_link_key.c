/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> dlk.o -> crypto_dlk_calc_link_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int crypto_dlk_calc_link_key
              (uint *param_1,uint *param_2,uint *param_3,undefined1 *param_4,undefined4 param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 uStack_177;
  undefined2 uStack_176;
  undefined1 auStack_174 [68];
  undefined1 auStack_130 [268];
  
  uVar4 = param_2[1];
  uVar1 = param_3[1];
  puVar2 = param_2;
  if (uVar1 < uVar4) goto _L0;
  if ((uVar4 == uVar1) && (*param_3 < *param_2)) goto _L0;
  if ((*param_2 == *param_3) && ((uVar4 == uVar1 && (-1 < (char)*param_1)))) goto _L0;
  puVar5 = param_4;
  param_4 = auStack_174;
  while( true ) {
    iVar3 = crypto_ecdh_compute_shared_secret(param_1 + 2,auStack_174);
    if (iVar3 != 0) {
      return iVar3;
    }
    crypto_md_start(auStack_130,*param_1 & 3);
    crypto_md_update(auStack_130,auStack_174,0x20);
    iVar3 = crypto_ecdh_export_public(param_1 + 2,auStack_174);
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar4 = *param_1 >> 2 & 7;
    if (uVar4 == 1) break;
    if (uVar4 == 2) {
      param_4 = param_4 + 1;
      puVar5 = puVar5 + 1;
      uStack_176 = 0x40;
      goto _L0;
    }
    param_4 = (undefined1 *)__assert_func(0,0,0);
    puVar2 = param_3;
    param_3 = param_2;
_L0:
    param_2 = param_3;
    param_3 = puVar2;
    puVar5 = auStack_174;
  }
  uStack_176 = 0x20;
_L0:
  crypto_md_update(auStack_130,param_2,8);
  crypto_md_update(auStack_130,param_4,uStack_176);
  crypto_md_update(auStack_130,param_3,8);
  crypto_md_update(auStack_130,puVar5,uStack_176);
  crypto_md_update(auStack_130,param_1 + 0x26,(char)param_1[0x2e]);
  crypto_md_finish(auStack_130,auStack_174,0x41,&uStack_176);
  uStack_177 = 1;
  crypto_md_hmac_128(auStack_130,auStack_174,uStack_176,&uStack_177,param_5);
  return 0;
}

