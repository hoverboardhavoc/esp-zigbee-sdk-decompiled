/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_aes_ccm_star
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_aes_ccm_star(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                        undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  uint in_stack_0000000c;
  undefined4 local_1f0;
  undefined4 uStack_1ec;
  undefined1 auStack_1e8 [436];
  int aiStack_34 [2];
  
  if (in_stack_0000000c == 0) {
    crypto_psa_ccm_no_tag(param_6,param_7,param_8,in_stack_00000000,in_stack_00000004);
  }
  else {
    aiStack_34[0] = 0;
    memset(auStack_1e8,0,0x1b0);
    uVar3 = (in_stack_0000000c & 0x3f) << 0x10 | 0x5400100;
    if (param_1 == 0) {
      uVar2 = 0x100;
    }
    else {
      uVar2 = 0x200;
    }
    uStack_1ec = 0;
    iVar1 = crypto_psa_import_aes_key(param_2,uVar3,uVar2,aiStack_34);
    if (iVar1 == 0) {
      if (param_1 == 0) {
        iVar1 = psa_aead_encrypt_setup(auStack_1e8,aiStack_34[0],uVar3);
      }
      else {
        iVar1 = psa_aead_decrypt_setup(auStack_1e8,aiStack_34[0],uVar3);
      }
      if ((((iVar1 == 0) && (iVar1 = psa_aead_set_lengths(auStack_1e8,param_5,param_7), iVar1 == 0))
          && (iVar1 = psa_aead_set_nonce(auStack_1e8,param_3,0xd), iVar1 == 0)) &&
         ((iVar1 = psa_aead_update_ad(auStack_1e8,param_4,param_5), iVar1 == 0 &&
          (iVar1 = psa_aead_update(auStack_1e8,param_6,param_7,param_8,in_stack_00000000,
                                   in_stack_00000004), iVar1 == 0)))) {
        if (param_1 == 0) {
          local_1f0 = 0;
          iVar1 = psa_aead_finish(auStack_1e8,0,0,&uStack_1ec,in_stack_00000008,in_stack_0000000c,
                                  &local_1f0);
        }
        else {
          iVar1 = psa_aead_verify(auStack_1e8,0,0,&uStack_1ec,in_stack_00000008,in_stack_0000000c);
        }
      }
    }
    psa_aead_abort(auStack_1e8);
    if (aiStack_34[0] != 0) {
      psa_destroy_key();
    }
    psa_to_ezb_error(iVar1);
  }
  return;
}

