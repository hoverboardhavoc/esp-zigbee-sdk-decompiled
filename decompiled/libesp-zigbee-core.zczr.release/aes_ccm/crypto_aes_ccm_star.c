/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  uint uVar1;
  int iVar2;
  undefined4 in_stack_00000000;
  undefined1 auStack_b0 [4];
  mbedtls_ccm_context ccm_ctx;
  
  mbedtls_ccm_init(auStack_b0);
  uVar1 = ad_len & -(uint)(tag != (uint8_t *)0x0);
  iVar2 = mbedtls_ccm_setkey(auStack_b0,2,key,0x80);
  if ((((iVar2 == 0) && (iVar2 = mbedtls_ccm_starts(auStack_b0,mode,nonce,0xd), iVar2 == 0)) &&
      (iVar2 = mbedtls_ccm_set_lengths(auStack_b0,uVar1,ilen,tag), iVar2 == 0)) &&
     ((iVar2 = mbedtls_ccm_update_ad(auStack_b0,ad,uVar1), iVar2 == 0 &&
      (iVar2 = mbedtls_ccm_update(auStack_b0,input,ilen,output,in_stack_00000000,output_len),
      iVar2 == 0)))) {
    iVar2 = mbedtls_ccm_finish(auStack_b0,olen,tag);
  }
  mbedtls_ccm_free(auStack_b0);
  return -(uint)(iVar2 != 0);
}

