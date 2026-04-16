/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> secur.o -> secur_unsecure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t secur_unsecure_msg(uint8_t seclevel,uint8_t *key,secur_ccm_nonce_t *nonce,zmsg_t *msg,
                            uint16_t hdr_len)

{
  uint uVar1;
  undefined3 in_register_00002029;
  int iVar2;
  uint uVar3;
  undefined2 in_register_0000203a;
  
  uVar3 = CONCAT22(in_register_0000203a,hdr_len);
  if ((((msg != (zmsg_t *)0x0) && (key != (uint8_t *)0x0)) && (nonce != (secur_ccm_nonce_t *)0x0))
     && (CONCAT31(in_register_00002029,seclevel) < 8)) {
    uVar1 = seclevel & 3;
    if ((seclevel & 3) != 0) {
      uVar1 = 4 << (uVar1 - 1 & 0x1f) & 0xff;
    }
    iVar2 = zmsg_get_length(msg);
    if ((seclevel & 4) == 0) {
      uVar3 = iVar2 - uVar1 & 0xffff;
    }
    iVar2 = crypto_unsecure_msg(msg,key,nonce,uVar3,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (uVar1 == 0) {
      return 0;
    }
    iVar2 = zmsg_get_length(msg);
    iVar2 = zmsg_set_length(msg,iVar2 - uVar1 & 0xffff);
    if (iVar2 == 0) {
      return 0;
    }
    __assert_func(0,0,0,0);
  }
  return 2;
}

