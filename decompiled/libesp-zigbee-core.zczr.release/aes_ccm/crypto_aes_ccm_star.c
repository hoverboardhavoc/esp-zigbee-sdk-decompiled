/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_aes_ccm_star
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int crypto_aes_ccm_star(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_stack_00000000;
  int *in_stack_00000004;
  undefined4 in_stack_00000008;
  uint in_stack_0000000c;
  int iStack_1fc;
  int local_1f8;
  int iStack_1f4;
  undefined1 auStack_1f0 [444];
  
  if (in_stack_0000000c == 0) {
    iStack_1fc = 0;
    memset(auStack_1f0,0,0x54);
    local_1f8 = 0;
    iStack_1f4 = 0;
    iVar2 = crypto_psa_import_aes_key_constprop_0
                      (param_2,0x4c01300,(uint)(param_1 != 0) * 0x100 + 0x100,&iStack_1fc);
    if (iVar2 == 0) {
      if (param_1 == 0) {
        iVar2 = psa_cipher_encrypt_setup();
      }
      else {
        iVar2 = psa_cipher_decrypt_setup(auStack_1f0,iStack_1fc,0x4c01300);
      }
      if (((iVar2 == 0) && (iVar2 = psa_cipher_set_iv(auStack_1f0,param_3,0xd), iVar2 == 0)) &&
         ((iVar2 = psa_cipher_update(auStack_1f0,param_6,param_7,param_8,in_stack_00000000,
                                     &local_1f8), iVar2 == 0 &&
          (iVar2 = psa_cipher_finish(auStack_1f0,local_1f8 + param_8,in_stack_00000000 - local_1f8,
                                     &iStack_1f4), iVar2 == 0)))) {
        *in_stack_00000004 = local_1f8 + iStack_1f4;
      }
    }
    psa_cipher_abort(auStack_1f0);
    if (iStack_1fc != 0) {
      psa_destroy_key();
    }
  }
  else {
    iStack_1fc = 0;
    memset(auStack_1f0,0,0x1b0);
    uVar3 = (in_stack_0000000c & 0x3f) << 0x10 | 0x5400100;
    local_1f8 = 0;
    iVar2 = crypto_psa_import_aes_key_constprop_0
                      (param_2,uVar3,(uint)(param_1 != 0) * 0x100 + 0x100,&iStack_1fc);
    if (iVar2 == 0) {
      if (param_1 == 0) {
        iVar2 = psa_aead_encrypt_setup();
      }
      else {
        iVar2 = psa_aead_decrypt_setup(auStack_1f0,iStack_1fc,uVar3);
      }
      if ((((iVar2 == 0) && (iVar2 = psa_aead_set_lengths(auStack_1f0,param_5,param_7), iVar2 == 0))
          && (iVar2 = psa_aead_set_nonce(auStack_1f0,param_3,0xd), iVar2 == 0)) &&
         ((iVar2 = psa_aead_update_ad(auStack_1f0,param_4,param_5), iVar2 == 0 &&
          (iVar2 = psa_aead_update(auStack_1f0,param_6,param_7,param_8,in_stack_00000000,
                                   in_stack_00000004), iVar2 == 0)))) {
        if (param_1 == 0) {
          iStack_1f4 = 0;
          iVar2 = psa_aead_finish(auStack_1f0,0,0,&local_1f8,in_stack_00000008,in_stack_0000000c,
                                  &iStack_1f4);
        }
        else {
          iVar2 = psa_aead_verify(auStack_1f0,0,0,&local_1f8,in_stack_00000008,in_stack_0000000c);
        }
      }
    }
    psa_aead_abort(auStack_1f0);
    if (iStack_1fc != 0) {
      psa_destroy_key();
    }
  }
  if (iVar2 == -0x87) {
    iVar1 = 2;
  }
  else {
    if (-0x87 < iVar2) {
      return -(uint)(iVar2 != 0);
    }
    iVar1 = 0x13;
    if ((iVar2 != -0x95) && (iVar1 = 1, iVar2 != -0x8a)) {
      return -1;
    }
  }
  return iVar1;
}

