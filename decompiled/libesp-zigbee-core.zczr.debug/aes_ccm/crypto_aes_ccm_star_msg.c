/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_aes_ccm_star_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_aes_ccm_star_msg
               (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
               undefined4 param_7,uint param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_210;
  undefined4 uStack_20c;
  undefined1 auStack_208 [16];
  undefined2 uStack_1f8;
  undefined2 uStack_1f6;
  undefined1 auStack_1f4 [4];
  undefined4 uStack_1f0;
  ushort uStack_1ec;
  undefined1 auStack_1e8 [436];
  int aiStack_34 [3];
  
  if (((param_1 == 0) || (param_3 == 0)) || (param_4 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x140,
                  "crypto_aes_ccm_star_msg",
                  "msg != ((void *)0) && key != ((void *)0) && nonce != ((void *)0)");
  }
  else {
    iVar1 = zmsg_get_length();
    if (param_5 + param_6 <= iVar1) {
      if (param_8 != 0) {
        aiStack_34[0] = 0;
        memset(auStack_1e8,0,0x1b0);
        uVar3 = (param_8 & 0x3f) << 0x10 | 0x5400100;
        if (param_2 == 0) {
          uVar2 = 0x100;
        }
        else {
          uVar2 = 0x200;
        }
        uStack_1f6 = (undefined2)param_5;
        uStack_1f8 = (undefined2)param_6;
        uStack_20c = 0;
        iVar1 = crypto_psa_import_aes_key(param_3,uVar3,uVar2,aiStack_34);
        if (iVar1 == 0) {
          if (param_2 == 0) {
            iVar1 = psa_aead_encrypt_setup(auStack_1e8,aiStack_34[0],uVar3);
          }
          else {
            iVar1 = psa_aead_decrypt_setup(auStack_1e8,aiStack_34[0],uVar3);
          }
          if (((iVar1 == 0) &&
              (iVar1 = psa_aead_set_lengths(auStack_1e8,param_5,param_6), iVar1 == 0)) &&
             (iVar1 = psa_aead_set_nonce(auStack_1e8,param_4,0xd), iVar1 == 0)) {
            zmsg_get_first_chunk(param_1,0,&uStack_1f6,auStack_1f4);
            while (uStack_1ec != 0) {
              iVar1 = psa_aead_update_ad(auStack_1e8,uStack_1f0);
              if (iVar1 != 0) goto _L0;
              zmsg_get_next_chunk(&uStack_1f6,auStack_1f4);
            }
            zmsg_get_first_chunk(param_1,param_5,&uStack_1f8,auStack_1f4);
            while (uStack_1ec != 0) {
              local_210 = 0;
              iVar1 = psa_aead_update(auStack_1e8,uStack_1f0,uStack_1ec,&local_210);
              if (iVar1 != 0) goto _L0;
              if (local_210 != uStack_1ec) {
                __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x16a,
                              "crypto_aes_ccm_star_msg","produced == chunk.len");
                break;
              }
              zmsg_get_next_chunk(&uStack_1f8,auStack_1f4);
            }
            if (param_2 == 0) {
              local_210 = 0;
              iVar1 = psa_aead_finish(auStack_1e8,auStack_208,0x10,&uStack_20c,param_7,param_8,
                                      &local_210);
            }
            else {
              iVar1 = psa_aead_verify(auStack_1e8,auStack_208,0x10,&uStack_20c,param_7,param_8);
            }
          }
        }
_L0:
        psa_aead_abort(auStack_1e8);
        if (aiStack_34[0] != 0) {
          psa_destroy_key();
        }
        psa_to_ezb_error(iVar1);
        return;
      }
      goto _L0;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x141,
                "crypto_aes_ccm_star_msg","ad_len + plaintext_len <= zmsg_get_length(msg)");
_L0:
  crypto_psa_ccm_no_tag_msg(param_2,param_3,param_4,param_1,param_5,param_6);
  return;
}

