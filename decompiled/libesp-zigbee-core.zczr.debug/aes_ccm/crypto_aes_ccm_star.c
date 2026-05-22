/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_aes_ccm_star
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_aes_ccm_star(int mode,uint8_t *key,uint8_t *nonce,uint8_t *ad,size_t ad_len,
                             uint8_t *input,size_t ilen,uint8_t *output,size_t output_len,
                             size_t *olen,uint8_t *tag,size_t tag_len)

{
  int psa_status;
  ezb_err_t eVar1;
  psa_key_usage_t usage;
  uint alg;
  size_t in_stack_00000000;
  undefined4 local_1f0;
  size_t tag_olen;
  size_t finish_len;
  psa_aead_operation_t op;
  psa_key_id_t pStack_34;
  psa_key_id_t key_id;
  
  if (tag == (uint8_t *)0x0) {
    eVar1 = crypto_psa_ccm_no_tag
                      (mode,key,nonce,input,ilen,output,in_stack_00000000,(size_t *)output_len);
  }
  else {
    pStack_34 = 0;
    memset(&finish_len,0,0x1b0);
    alg = ((uint)tag & 0x3f) << 0x10 | 0x5400100;
    if (mode == 0) {
      usage = 0x100;
    }
    else {
      usage = 0x200;
    }
    tag_olen = 0;
    psa_status = crypto_psa_import_aes_key(key,alg,usage,&pStack_34);
    if (psa_status == 0) {
      if (mode == 0) {
        psa_status = psa_aead_encrypt_setup(&finish_len,pStack_34,alg);
      }
      else {
        psa_status = psa_aead_decrypt_setup(&finish_len,pStack_34,alg);
      }
      if ((((psa_status == 0) &&
           (psa_status = psa_aead_set_lengths(&finish_len,ad_len,ilen), psa_status == 0)) &&
          (psa_status = psa_aead_set_nonce(&finish_len,nonce,0xd), psa_status == 0)) &&
         ((psa_status = psa_aead_update_ad(&finish_len,ad,ad_len), psa_status == 0 &&
          (psa_status = psa_aead_update(&finish_len,input,ilen,output,in_stack_00000000,output_len),
          psa_status == 0)))) {
        if (mode == 0) {
          local_1f0 = 0;
          psa_status = psa_aead_finish(&finish_len,0,0,&tag_olen,olen,tag,&local_1f0);
        }
        else {
          psa_status = psa_aead_verify(&finish_len,0,0,&tag_olen,olen,tag);
        }
      }
    }
    psa_aead_abort(&finish_len);
    if (pStack_34 != 0) {
      psa_destroy_key();
    }
    eVar1 = psa_to_ezb_error(psa_status);
  }
  return eVar1;
}

