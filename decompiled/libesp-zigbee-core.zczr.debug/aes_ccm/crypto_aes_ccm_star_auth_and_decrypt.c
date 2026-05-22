/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_aes_ccm_star_auth_and_decrypt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_aes_ccm_star_auth_and_decrypt
                    (uint8_t *key,uint8_t *nonce,uint8_t *ad,size_t ad_len,uint8_t *input,
                    size_t ilen,uint8_t *output,size_t output_len,size_t *olen,size_t tag_len)

{
  uint ilen_00;
  ezb_err_t eVar1;
  size_t in_stack_00000000;
  size_t in_stack_ffffffc0;
  uint8_t tag [16];
  
  if (ilen < olen) {
    eVar1 = 2;
  }
  else {
    ilen_00 = (ilen & 0xffff) - ((uint)olen & 0xffff) & 0xffff;
    memcpy(&stack0xffffffc0,input + ilen_00,(size_t)olen);
    eVar1 = crypto_aes_ccm_star(1,key,nonce,ad,ad_len,input,ilen_00,output,in_stack_00000000,
                                (size_t *)&stack0xffffffc0,(uint8_t *)olen,in_stack_ffffffc0);
  }
  return eVar1;
}

