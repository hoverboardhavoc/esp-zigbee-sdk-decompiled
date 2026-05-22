/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_aes_ccm_star
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
  ezb_err_t eVar1;
  int iVar2;
  uint alg;
  int in_stack_00000000;
  psa_key_id_t pStack_1fc;
  psa_key_id_t key_id;
  size_t finish_len;
  size_t tag_olen;
  psa_aead_operation_t op;
  
  if (tag == (uint8_t *)0x0) {
    pStack_1fc = 0;
    memset(&tag_olen,0,0x54);
    key_id = 0;
    finish_len = 0;
    iVar2 = crypto_psa_import_aes_key(key,0x4c01300,(uint)(mode != 0) * 0x100 + 0x100,&pStack_1fc);
    if (iVar2 == 0) {
      if (mode == 0) {
        iVar2 = psa_cipher_encrypt_setup();
      }
      else {
        iVar2 = psa_cipher_decrypt_setup(&tag_olen,pStack_1fc,0x4c01300);
      }
      if (((iVar2 == 0) && (iVar2 = psa_cipher_set_iv(&tag_olen,nonce,0xd), iVar2 == 0)) &&
         ((iVar2 = psa_cipher_update(&tag_olen,input,ilen,output,in_stack_00000000,&key_id),
          iVar2 == 0 &&
          (iVar2 = psa_cipher_finish(&tag_olen,output + key_id,in_stack_00000000 - key_id,
                                     &finish_len), iVar2 == 0)))) {
        *(psa_key_id_t *)output_len = key_id + finish_len;
      }
    }
    psa_cipher_abort(&tag_olen);
    if (pStack_1fc != 0) {
      psa_destroy_key();
    }
  }
  else {
    pStack_1fc = 0;
    memset(&tag_olen,0,0x1b0);
    alg = ((uint)tag & 0x3f) << 0x10 | 0x5400100;
    key_id = 0;
    iVar2 = crypto_psa_import_aes_key(key,alg,(uint)(mode != 0) * 0x100 + 0x100,&pStack_1fc);
    if (iVar2 == 0) {
      if (mode == 0) {
        iVar2 = psa_aead_encrypt_setup();
      }
      else {
        iVar2 = psa_aead_decrypt_setup(&tag_olen,pStack_1fc,alg);
      }
      if ((((iVar2 == 0) && (iVar2 = psa_aead_set_lengths(&tag_olen,ad_len,ilen), iVar2 == 0)) &&
          (iVar2 = psa_aead_set_nonce(&tag_olen,nonce,0xd), iVar2 == 0)) &&
         ((iVar2 = psa_aead_update_ad(&tag_olen,ad,ad_len), iVar2 == 0 &&
          (iVar2 = psa_aead_update(&tag_olen,input,ilen,output,in_stack_00000000,output_len),
          iVar2 == 0)))) {
        if (mode == 0) {
          finish_len = 0;
          iVar2 = psa_aead_finish(&tag_olen,0,0,&key_id,olen,tag,&finish_len);
        }
        else {
          iVar2 = psa_aead_verify(&tag_olen,0,0,&key_id,olen,tag);
        }
      }
    }
    psa_aead_abort(&tag_olen);
    if (pStack_1fc != 0) {
      psa_destroy_key();
    }
  }
  if (iVar2 == -0x87) {
    eVar1 = 2;
  }
  else {
    if (-0x87 < iVar2) {
      return -(uint)(iVar2 != 0);
    }
    eVar1 = 0x13;
    if ((iVar2 != -0x95) && (eVar1 = 1, iVar2 != -0x8a)) {
      return -1;
    }
  }
  return eVar1;
}

