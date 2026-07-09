/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_psa_ccm_no_tag_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_psa_ccm_no_tag_msg
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined2 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 auStack_a2 [3];
  uint uStack_9c;
  int iStack_98;
  undefined1 auStack_94 [16];
  undefined1 auStack_84 [4];
  undefined4 uStack_80;
  ushort uStack_7c;
  undefined1 auStack_78 [84];
  int aiStack_24 [3];
  
  aiStack_24[0] = 0;
  auStack_a2[0] = param_6;
  memset(auStack_78,0,0x54);
  if (param_1 == 0) {
    uVar2 = 0x100;
  }
  else {
    uVar2 = 0x200;
  }
  iStack_98 = 0;
  iVar1 = crypto_psa_import_aes_key(param_2,0x4c01300,uVar2,aiStack_24);
  if (iVar1 == 0) {
    if (param_1 != 0) {
      iVar1 = psa_cipher_decrypt_setup(auStack_78,aiStack_24[0],0x4c01300);
      if (iVar1 == 0) goto _L0;
      goto _L0;
    }
    iVar1 = psa_cipher_encrypt_setup(auStack_78,aiStack_24[0],0x4c01300);
    if (iVar1 != 0) goto _L0;
_L0:
    iVar1 = psa_cipher_set_iv(auStack_78,param_3,0xd);
    if (iVar1 != 0) goto _L0;
    zmsg_get_first_chunk(param_4,param_5,auStack_a2,auStack_84);
    while (uStack_7c != 0) {
      uStack_9c = 0;
      iVar1 = psa_cipher_update(auStack_78,uStack_80,uStack_7c,&uStack_9c);
      if (iVar1 != 0) goto _L0;
      if (uStack_9c != uStack_7c) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x100,
                      "crypto_psa_ccm_no_tag_msg","produced == chunk.len");
        break;
      }
      zmsg_get_next_chunk(auStack_a2,auStack_84);
    }
    iVar1 = psa_cipher_finish(auStack_78,auStack_94,0x10,&iStack_98);
    if ((iVar1 != 0) || (iStack_98 == 0)) goto _L0;
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x105,
                  "crypto_psa_ccm_no_tag_msg","tail_len == 0");
  }
  else {
_L0:
    psa_cipher_abort(auStack_78);
    if (aiStack_24[0] == 0) goto _L0;
  }
  psa_destroy_key();
_L0:
  psa_to_ezb_error(iVar1);
  return;
}

