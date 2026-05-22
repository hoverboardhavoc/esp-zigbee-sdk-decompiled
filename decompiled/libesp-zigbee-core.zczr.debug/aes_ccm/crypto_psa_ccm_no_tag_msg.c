/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_psa_ccm_no_tag_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_psa_ccm_no_tag_msg
                    (int mode,uint8_t *key,uint8_t *nonce,zmsg_t *msg,uint16_t ad_len,
                    uint16_t plaintext_len)

{
  psa_status_t psa_status;
  ezb_err_t eVar1;
  psa_key_usage_t usage;
  undefined2 in_register_0000203a;
  uint16_t auStack_a2 [3];
  uint uStack_9c;
  size_t produced;
  size_t tail_len;
  uint8_t tail [16];
  zmsg_chunk_t chunk;
  psa_cipher_operation_t op;
  psa_key_id_t key_id;
  
  op.private_ctx._72_4_ = 0;
  auStack_a2[0] = plaintext_len;
  memset(&chunk.len,0,0x54);
  if (mode == 0) {
    usage = 0x100;
  }
  else {
    usage = 0x200;
  }
  produced = 0;
  psa_status = crypto_psa_import_aes_key
                         (key,0x4c01300,usage,(psa_key_id_t *)((int)&op.private_ctx + 0x48));
  if (psa_status == 0) {
    if (mode != 0) {
      psa_status = psa_cipher_decrypt_setup(&chunk.len,op.private_ctx._72_4_,0x4c01300);
      if (psa_status == 0) goto _L0;
      goto _L0;
    }
    psa_status = psa_cipher_encrypt_setup(&chunk.len,op.private_ctx._72_4_,0x4c01300);
    if (psa_status != 0) goto _L0;
_L0:
    psa_status = psa_cipher_set_iv(&chunk.len,nonce,0xd);
    if (psa_status != 0) goto _L0;
    zmsg_get_first_chunk(msg,CONCAT22(in_register_0000203a,ad_len),auStack_a2,tail + 0xc);
    while ((ushort)chunk.data != 0) {
      uStack_9c = 0;
      psa_status = psa_cipher_update(&chunk.len,chunk.buffer,(ushort)chunk.data,&uStack_9c);
      if (psa_status != 0) goto _L0;
      if (uStack_9c != (ushort)chunk.data) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x100,
                      "crypto_psa_ccm_no_tag_msg","produced == chunk.len");
        break;
      }
      zmsg_get_next_chunk(auStack_a2,tail + 0xc);
    }
    psa_status = psa_cipher_finish(&chunk.len,&tail_len,0x10,&produced);
    if ((psa_status != 0) || (produced == 0)) goto _L0;
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes_ccm.c",0x105,
                  "crypto_psa_ccm_no_tag_msg","tail_len == 0");
  }
  else {
_L0:
    psa_cipher_abort(&chunk.len);
    if (op.private_ctx._72_4_ == 0) goto _L0;
  }
  psa_destroy_key();
_L0:
  eVar1 = psa_to_ezb_error(psa_status);
  return eVar1;
}

