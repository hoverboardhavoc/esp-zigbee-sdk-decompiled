/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_secure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_secure_msg(zmsg_t *msg,uint8_t *key,uint8_t *ccm_nonce,uint16_t ad_len,
                           uint8_t tag_len)

{
  uint uVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined2 in_register_00002036;
  int iVar4;
  undefined3 in_register_00002039;
  int iVar5;
  uint8_t auStack_30 [4];
  uint8_t tag [16];
  
  iVar5 = CONCAT31(in_register_00002039,tag_len);
  iVar4 = CONCAT22(in_register_00002036,ad_len);
  iVar2 = zmsg_get_length();
  if (iVar2 < iVar4 + iVar5) {
    eVar3 = 2;
  }
  else {
    iVar2 = zmsg_get_length(msg);
    uVar1 = (iVar2 - iVar4 & 0xffffU) - iVar5;
    eVar3 = crypto_aes_ccm_star_msg(msg,3,key,ccm_nonce,ad_len,(uint16_t)uVar1,auStack_30,tag_len);
    if (eVar3 == 0) {
      zmsg_write_bytes(msg,iVar4 + (uVar1 & 0xffff) & 0xffff,iVar5,auStack_30);
    }
  }
  return eVar3;
}

