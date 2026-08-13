/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> dlk.o -> crypto_dlk_calc_link_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int crypto_dlk_calc_link_key
              (uint *param_1,uint *param_2,uint *param_3,undefined1 *param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *local_178 [4];
  undefined1 auStack_168 [258];
  undefined2 uStack_66;
  undefined1 auStack_64 [67];
  undefined1 auStack_21 [5];
  
  uVar1 = param_2[1];
  uVar3 = param_3[1];
  if (((uVar3 < uVar1) || ((uVar1 == uVar3 && (*param_3 < *param_2)))) ||
     ((*param_2 == *param_3 && ((uVar1 == uVar3 && (-1 < (char)*param_1)))))) {
    local_178[3] = (uint *)auStack_64;
    local_178[0] = param_3;
    local_178[1] = param_2;
    local_178[2] = (uint *)param_4;
  }
  else {
    local_178[2] = (uint *)auStack_64;
    local_178[0] = param_2;
    local_178[1] = param_3;
    local_178[3] = (uint *)param_4;
  }
  puVar4 = param_1 + 2;
  iVar2 = crypto_ecdh_compute_shared_secret(puVar4,auStack_64);
  if (iVar2 == 0) {
    crypto_md_start(auStack_168,*param_1 & 3);
    crypto_md_update(auStack_168,auStack_64,0x20);
    iVar2 = crypto_ecdh_export_public(puVar4,auStack_64);
    if (iVar2 == 0) {
      uVar3 = *param_1 >> 2 & 7;
      if (uVar3 == 1) {
        uStack_66 = 0x20;
      }
      else {
        if (uVar3 != 2) {
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/dlk.c",0xb5,
                        "crypto_dlk_calc_link_key",&_LC2);
          goto _L0;
        }
        uStack_66 = 0x40;
        local_178[2] = (uint *)((int)local_178[2] + 1);
        local_178[3] = (uint *)((int)local_178[3] + 1);
      }
      for (puVar4 = (uint *)0x0; puVar4 < (uint *)0x2;
          puVar4 = (uint *)((uint)((int)puVar4 + 1) & 0xff)) {
_L0:
        crypto_md_update(auStack_168,local_178[(int)puVar4],8);
        crypto_md_update(auStack_168,local_178[(int)((int)puVar4 + 2)],uStack_66);
      }
      crypto_md_update(auStack_168,param_1 + 0x26,(char)param_1[0x2e]);
      crypto_md_finish(auStack_168,auStack_64,0x41,&uStack_66);
      auStack_21[0] = 1;
      crypto_md_hmac_128(auStack_168,auStack_64,uStack_66,auStack_21,param_5);
    }
  }
  return iVar2;
}

