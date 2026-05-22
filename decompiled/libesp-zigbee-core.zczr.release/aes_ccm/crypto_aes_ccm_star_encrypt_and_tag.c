/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_aes_ccm_star_encrypt_and_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_aes_ccm_star_encrypt_and_tag
                    (uint8_t *key,uint8_t *nonce,uint8_t *ad,size_t ad_len,uint8_t *input,
                    size_t ilen,uint8_t *output,size_t output_len,size_t *olen,size_t tag_len)

{
  ezb_err_t eVar1;
  int *in_stack_00000000;
  size_t in_stack_ffffffd0;
  uint8_t tag [16];
  
  eVar1 = 2;
  if (ilen + (int)olen <= output_len) {
    eVar1 = crypto_aes_ccm_star(0,key,nonce,ad,ad_len,input,ilen,output,(size_t)in_stack_00000000,
                                (size_t *)&stack0xffffffd0,(uint8_t *)olen,in_stack_ffffffd0);
    if (eVar1 == 0) {
      memcpy(output + ilen,&stack0xffffffd0,(size_t)olen);
      *in_stack_00000000 = *in_stack_00000000 + (int)olen;
    }
  }
  return eVar1;
}

