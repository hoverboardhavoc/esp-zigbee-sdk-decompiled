/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_psa_ccm_no_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_psa_ccm_no_tag
                    (int mode,uint8_t *key,uint8_t *nonce,uint8_t *input,size_t ilen,uint8_t *output
                    ,size_t output_len,size_t *olen)

{
  int psa_status;
  ezb_err_t eVar1;
  psa_key_usage_t usage;
  int local_90;
  size_t finish_len;
  size_t produced;
  psa_cipher_operation_t op;
  psa_key_id_t key_id;
  
  op.private_ctx._72_4_ = 0;
  memset(&produced,0,0x54);
  if (mode == 0) {
    usage = 0x100;
  }
  else {
    usage = 0x200;
  }
  finish_len = 0;
  local_90 = 0;
  psa_status = crypto_psa_import_aes_key
                         (key,0x4c01300,usage,(psa_key_id_t *)((int)&op.private_ctx + 0x48));
  if (psa_status == 0) {
    if (mode == 0) {
      psa_status = psa_cipher_encrypt_setup(&produced,op.private_ctx._72_4_,0x4c01300);
    }
    else {
      psa_status = psa_cipher_decrypt_setup(&produced,op.private_ctx._72_4_,0x4c01300);
    }
    if ((((psa_status == 0) &&
         (psa_status = psa_cipher_set_iv(&produced,nonce,0xd), psa_status == 0)) &&
        (psa_status = psa_cipher_update(&produced,input,ilen,output,output_len,&finish_len),
        psa_status == 0)) &&
       (psa_status = psa_cipher_finish(&produced,output + finish_len,output_len - finish_len,
                                       &local_90), psa_status == 0)) {
      *olen = finish_len + local_90;
    }
  }
  psa_cipher_abort(&produced);
  if (op.private_ctx._72_4_ != 0) {
    psa_destroy_key();
  }
  eVar1 = psa_to_ezb_error(psa_status);
  return eVar1;
}

