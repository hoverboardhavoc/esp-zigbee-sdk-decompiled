/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  undefined2 in_register_0000203a;
  int iVar2;
  undefined3 in_register_00002045;
  int iVar3;
  uint16_t auStack_d2 [7];
  uint uStack_c4;
  size_t olen;
  mbedtls_ccm_context ccm_ctx;
  zmsg_chunk_t chunk;
  uint16_t total_ad_len;
  
  iVar3 = CONCAT31(in_register_00002045,tag_len);
  iVar2 = CONCAT22(in_register_0000203a,ad_len);
  auStack_d2[0] = plaintext_len;
  if (((msg == (zmsg_t *)0x0) || (key == (uint8_t *)0x0)) || (nonce == (uint8_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/crypto/aes_ccm.c",0x77,"crypto_aes_ccm_star_msg",
                  "msg != ((void *)0) && key != ((void *)0) && nonce != ((void *)0)");
_L0:
    __assert_func("//build/esp-zigbee/src/core/crypto/aes_ccm.c",0x78,"crypto_aes_ccm_star_msg",
                  "ad_len + plaintext_len <= zmsg_get_length(msg)");
  }
  else {
    iVar1 = zmsg_get_length();
    if (iVar1 < (int)((uint)plaintext_len + iVar2)) goto _L0;
    iVar1 = iVar2;
    if (iVar3 != 0) goto _L0;
  }
  iVar1 = 0;
_L0:
  chunk._10_2_ = (undefined2)iVar1;
  mbedtls_ccm_init(&olen);
  iVar1 = mbedtls_ccm_setkey(&olen,2,key,0x80);
  if (((iVar1 == 0) && (iVar1 = mbedtls_ccm_starts(&olen,mode,nonce,0xd), iVar1 == 0)) &&
     (iVar1 = mbedtls_ccm_set_lengths(&olen,chunk._10_2_,auStack_d2[0],iVar3), iVar1 == 0)) {
    zmsg_get_first_chunk(msg,0,&chunk.field_0xa,&ccm_ctx.private_state);
    while ((ushort)chunk.data != 0) {
      iVar1 = mbedtls_ccm_update_ad(&olen,chunk.buffer);
      if (iVar1 != 0) goto _L0;
      zmsg_get_next_chunk(&chunk.field_0xa,&ccm_ctx.private_state);
    }
    zmsg_get_first_chunk(msg,iVar2,auStack_d2,&ccm_ctx.private_state);
    while ((ushort)chunk.data != 0) {
      iVar1 = mbedtls_ccm_update(&olen,chunk.buffer,(ushort)chunk.data,&uStack_c4);
      if (iVar1 != 0) goto _L0;
      if (uStack_c4 != (ushort)chunk.data) {
        __assert_func("//build/esp-zigbee/src/core/crypto/aes_ccm.c",0x91,"crypto_aes_ccm_star_msg",
                      "chunk.len == olen");
        break;
      }
      zmsg_get_next_chunk(auStack_d2,&ccm_ctx.private_state);
    }
    iVar1 = mbedtls_ccm_finish(&olen,tag,iVar3);
  }
_L0:
  mbedtls_ccm_free(&olen);
  if (iVar1 != 0) {
    iVar1 = -1;
  }
  return iVar1;
}

