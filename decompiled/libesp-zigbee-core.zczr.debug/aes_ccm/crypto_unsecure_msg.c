/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_unsecure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: tag */
/* WARNING: Unknown calling convention */

ezb_err_t crypto_unsecure_msg(zmsg_t *msg,uint8_t *key,uint8_t *ccm_nonce,uint16_t ad_len,
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
    zmsg_read_bytes(msg,iVar4 + (uVar1 & 0xffff) & 0xffff,iVar5,auStack_30);
    eVar3 = crypto_aes_ccm_star_msg(msg,1,key,ccm_nonce,ad_len,(uint16_t)uVar1,auStack_30,tag_len);
  }
  return eVar3;
}

