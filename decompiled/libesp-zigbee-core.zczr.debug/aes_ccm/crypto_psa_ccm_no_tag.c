/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_psa_ccm_no_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_psa_ccm_no_tag
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,int param_7,int *param_8)

{
  int iVar1;
  undefined4 uVar2;
  int local_90;
  int local_8c;
  undefined1 auStack_88 [84];
  int aiStack_34 [4];
  
  aiStack_34[0] = 0;
  memset(auStack_88,0,0x54);
  if (param_1 == 0) {
    uVar2 = 0x100;
  }
  else {
    uVar2 = 0x200;
  }
  local_8c = 0;
  local_90 = 0;
  iVar1 = crypto_psa_import_aes_key(param_2,0x4c01300,uVar2,aiStack_34);
  if (iVar1 == 0) {
    if (param_1 == 0) {
      iVar1 = psa_cipher_encrypt_setup(auStack_88,aiStack_34[0],0x4c01300);
    }
    else {
      iVar1 = psa_cipher_decrypt_setup(auStack_88,aiStack_34[0],0x4c01300);
    }
    if ((((iVar1 == 0) && (iVar1 = psa_cipher_set_iv(auStack_88,param_3,0xd), iVar1 == 0)) &&
        (iVar1 = psa_cipher_update(auStack_88,param_4,param_5,param_6,param_7,&local_8c), iVar1 == 0
        )) && (iVar1 = psa_cipher_finish(auStack_88,local_8c + param_6,param_7 - local_8c,&local_90)
              , iVar1 == 0)) {
      *param_8 = local_8c + local_90;
    }
  }
  psa_cipher_abort(auStack_88);
  if (aiStack_34[0] != 0) {
    psa_destroy_key();
  }
  psa_to_ezb_error(iVar1);
  return;
}

