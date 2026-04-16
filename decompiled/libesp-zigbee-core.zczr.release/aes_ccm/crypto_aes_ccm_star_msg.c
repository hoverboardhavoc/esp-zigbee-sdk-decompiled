/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_aes_ccm_star_msg
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
  uint8_t *unaff_s0;
  int iVar1;
  int extraout_a1;
  undefined2 in_register_0000203a;
  uint uVar2;
  uint uVar3;
  uint8_t *puVar4;
  undefined3 in_register_00002045;
  int iVar5;
  int iVar6;
  uint8_t *unaff_s5;
  uint uVar7;
  uint16_t auStack_d2 [8];
  ushort uStack_c2;
  uint uStack_c0;
  uint16_t total_ad_len;
  size_t olen;
  zmsg_chunk_t chunk;
  mbedtls_ccm_context ccm_ctx;
  
  iVar5 = CONCAT31(in_register_00002045,tag_len);
  uVar3 = CONCAT22(in_register_0000203a,ad_len);
  auStack_d2[0] = plaintext_len;
  if (((msg != (zmsg_t *)0x0) && (unaff_s0 = key, key != (uint8_t *)0x0)) &&
     (uVar2 = uVar3, puVar4 = tag, iVar6 = iVar5, unaff_s5 = nonce, nonce != (uint8_t *)0x0))
  goto _L0;
  while( true ) {
    do {
      msg = (zmsg_t *)__assert_func(0,0,0,0);
      mode = extraout_a1;
      uVar2 = uVar3;
      puVar4 = tag;
      iVar6 = iVar5;
_L0:
      uVar7 = (uint)auStack_d2[0];
      uVar3 = uVar2;
      tag = puVar4;
      iVar5 = iVar6;
      iVar1 = zmsg_get_length();
    } while (iVar1 < (int)(uVar7 + uVar2));
    uStack_c2 = (ushort)uVar2 & -(ushort)(iVar6 != 0);
    mbedtls_ccm_init(&chunk.len);
    iVar1 = mbedtls_ccm_setkey(&chunk.len,2,unaff_s0,0x80);
    if (((iVar1 != 0) || (iVar1 = mbedtls_ccm_starts(&chunk.len,mode,unaff_s5,0xd), iVar1 != 0)) ||
       (iVar1 = mbedtls_ccm_set_lengths(&chunk.len,uStack_c2,auStack_d2[0],iVar6), iVar1 != 0))
    break;
    zmsg_get_first_chunk(msg,0,&uStack_c2,&olen);
    while ((ushort)chunk.data != 0) {
      iVar1 = mbedtls_ccm_update_ad(&chunk.len,chunk.buffer);
      if (iVar1 != 0) goto _L0;
      zmsg_get_next_chunk(&uStack_c2,&olen);
    }
    zmsg_get_first_chunk(msg,uVar2,auStack_d2,&olen);
    while( true ) {
      if ((ushort)chunk.data == 0) {
        iVar1 = mbedtls_ccm_finish(&chunk.len,puVar4,iVar6);
        goto _L0;
      }
      iVar1 = mbedtls_ccm_update(&chunk.len,chunk.buffer,(ushort)chunk.data,&stack0xffffff40);
      if (iVar1 != 0) goto _L0;
      uVar3 = (uint)(ushort)chunk.data;
      unaff_s0 = (uint8_t *)0x0;
      if (uVar3 != uStack_c0) break;
      zmsg_get_next_chunk(auStack_d2,&olen);
    }
  }
_L0:
  mbedtls_ccm_free(&chunk.len);
  return -(uint)(iVar1 != 0);
}

