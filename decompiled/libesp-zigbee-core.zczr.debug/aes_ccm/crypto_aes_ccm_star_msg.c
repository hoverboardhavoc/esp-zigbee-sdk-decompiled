/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_aes_ccm_star_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_aes_ccm_star_msg
                    (zmsg_t *msg,int mode,uint8_t *key,uint8_t *nonce,uint16_t ad_len,
                    uint16_t plaintext_len,uint8_t *tag,uint8_t tag_len)

{
  int iVar1;
  ezb_err_t eVar2;
  psa_key_usage_t usage;
  undefined2 in_register_0000203a;
  int iVar3;
  undefined2 in_register_0000203e;
  undefined3 in_register_00002045;
  int iVar4;
  uint alg;
  uint local_210;
  size_t produced;
  size_t finish_len;
  uint8_t tail [16];
  uint16_t remaining;
  uint16_t remaining_ad;
  zmsg_chunk_t chunk;
  psa_aead_operation_t op;
  psa_key_id_t pStack_34;
  psa_key_id_t key_id;
  
  iVar4 = CONCAT31(in_register_00002045,tag_len);
  iVar3 = CONCAT22(in_register_0000203a,ad_len);
  if (((msg == (zmsg_t *)0x0) || (key == (uint8_t *)0x0)) || (nonce == (uint8_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x140,
                  "crypto_aes_ccm_star_msg",
                  "msg != ((void *)0) && key != ((void *)0) && nonce != ((void *)0)");
  }
  else {
    iVar1 = zmsg_get_length();
    if (iVar3 + CONCAT22(in_register_0000203e,plaintext_len) <= iVar1) {
      if (iVar4 != 0) {
        pStack_34 = 0;
        memset(&chunk.len,0,0x1b0);
        alg = (tag_len & 0x3f) << 0x10 | 0x5400100;
        if (mode == 0) {
          usage = 0x100;
        }
        else {
          usage = 0x200;
        }
        produced = 0;
        tail._12_2_ = plaintext_len;
        tail._14_2_ = ad_len;
        iVar1 = crypto_psa_import_aes_key(key,alg,usage,&pStack_34);
        if (iVar1 == 0) {
          if (mode == 0) {
            iVar1 = psa_aead_encrypt_setup(&chunk.len,pStack_34,alg);
          }
          else {
            iVar1 = psa_aead_decrypt_setup(&chunk.len,pStack_34,alg);
          }
          if (((iVar1 == 0) &&
              (iVar1 = psa_aead_set_lengths
                                 (&chunk.len,iVar3,CONCAT22(in_register_0000203e,plaintext_len)),
              iVar1 == 0)) && (iVar1 = psa_aead_set_nonce(&chunk.len,nonce,0xd), iVar1 == 0)) {
            zmsg_get_first_chunk(msg,0,tail + 0xe,&remaining);
            while ((ushort)chunk.data != 0) {
              iVar1 = psa_aead_update_ad(&chunk.len,chunk.buffer);
              if (iVar1 != 0) goto _L0;
              zmsg_get_next_chunk(tail + 0xe,&remaining);
            }
            zmsg_get_first_chunk(msg,iVar3,tail + 0xc,&remaining);
            while ((ushort)chunk.data != 0) {
              local_210 = 0;
              iVar1 = psa_aead_update(&chunk.len,chunk.buffer,(ushort)chunk.data,&local_210);
              if (iVar1 != 0) goto _L0;
              if (local_210 != (ushort)chunk.data) {
                __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x16a,
                              "crypto_aes_ccm_star_msg","produced == chunk.len");
                break;
              }
              zmsg_get_next_chunk(tail + 0xc,&remaining);
            }
            if (mode == 0) {
              local_210 = 0;
              iVar1 = psa_aead_finish(&chunk.len,&finish_len,0x10,&produced,tag,iVar4,&local_210);
            }
            else {
              iVar1 = psa_aead_verify(&chunk.len,&finish_len,0x10,&produced,tag,iVar4);
            }
          }
        }
_L0:
        psa_aead_abort(&chunk.len);
        if (pStack_34 != 0) {
          psa_destroy_key();
        }
        eVar2 = psa_to_ezb_error(iVar1);
        return eVar2;
      }
      goto _L0;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x141,
                "crypto_aes_ccm_star_msg","ad_len + plaintext_len <= zmsg_get_length(msg)");
_L0:
  eVar2 = crypto_psa_ccm_no_tag_msg(mode,key,nonce,msg,ad_len,plaintext_len);
  return eVar2;
}

