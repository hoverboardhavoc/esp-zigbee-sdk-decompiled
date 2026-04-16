/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_aes_ccm_star_auth_and_decrypt
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
  ezb_err_t eVar1;
  ezb_err_t eVar2;
  size_t in_stack_00000000;
  size_t in_stack_ffffffd0;
  uint8_t check_tag [16];
  
  if (ilen < olen) {
    eVar2 = 2;
  }
  else {
    eVar1 = crypto_aes_ccm_star(2,key,nonce,ad,ad_len,input,ilen - (int)olen,output,
                                in_stack_00000000,(size_t *)&stack0xffffffd0,(uint8_t *)olen,
                                in_stack_ffffffd0);
    eVar2 = -1;
    if ((eVar1 == 0) &&
       (eVar2 = memcmp(&stack0xffffffd0,input + (ilen - (int)olen),(size_t)olen), eVar2 != 0)) {
      memset(output,0,output_len);
      eVar2 = 0x13;
    }
  }
  return eVar2;
}

