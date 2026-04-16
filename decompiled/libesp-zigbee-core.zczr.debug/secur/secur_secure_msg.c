/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> secur.o -> secur_secure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t secur_secure_msg(uint8_t seclevel,uint8_t *key,secur_ccm_nonce_t *nonce,zmsg_t *msg,
                          uint16_t hdr_len)

{
  undefined3 in_register_00002029;
  undefined4 uVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined2 in_register_0000203a;
  undefined4 uVar4;
  uint uVar5;
  
  if (msg == (zmsg_t *)0x0) {
    eVar3 = 2;
  }
  else if (key == (uint8_t *)0x0) {
    eVar3 = 2;
  }
  else if (nonce == (secur_ccm_nonce_t *)0x0) {
    eVar3 = 2;
  }
  else if (CONCAT31(in_register_00002029,seclevel) < 8) {
    uVar5 = seclevel & 3;
    if ((seclevel & 3) != 0) {
      uVar5 = 4 << (uVar5 - 1 & 0x1f) & 0xff;
    }
    uVar1 = zmsg_get_length(msg);
    uVar4 = CONCAT22(in_register_0000203a,hdr_len);
    if ((seclevel & 4) == 0) {
      uVar4 = uVar1;
    }
    iVar2 = zmsg_get_length(msg);
    eVar3 = zmsg_set_length(msg,iVar2 + uVar5 & 0xffff);
    if (eVar3 == 0) {
      eVar3 = crypto_secure_msg(msg,key,nonce,uVar4,uVar5);
    }
  }
  else {
    eVar3 = 2;
  }
  return eVar3;
}

