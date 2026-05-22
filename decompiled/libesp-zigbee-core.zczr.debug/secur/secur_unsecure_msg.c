/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> secur.o -> secur_unsecure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t secur_unsecure_msg(uint8_t seclevel,uint8_t *key,secur_ccm_nonce_t *nonce,zmsg_t *msg,
                            uint16_t hdr_len)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined2 in_register_0000203a;
  uint uVar2;
  uint uVar3;
  
  if (msg != (zmsg_t *)0x0) {
    if (key == (uint8_t *)0x0) {
      return 2;
    }
    if (nonce == (secur_ccm_nonce_t *)0x0) {
      return 2;
    }
    if (7 < CONCAT31(in_register_00002029,seclevel)) {
      return 2;
    }
    uVar2 = seclevel & 3;
    if ((seclevel & 3) != 0) {
      uVar2 = 4 << (uVar2 - 1 & 0x1f) & 0xff;
    }
    iVar1 = zmsg_get_length(msg);
    uVar3 = CONCAT22(in_register_0000203a,hdr_len);
    if ((seclevel & 4) == 0) {
      uVar3 = iVar1 - uVar2 & 0xffff;
    }
    iVar1 = crypto_unsecure_msg(msg,key,nonce,uVar3,uVar2);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (uVar2 == 0) {
      return 0;
    }
    iVar1 = zmsg_get_length(msg);
    iVar1 = zmsg_set_length(msg,iVar1 - uVar2 & 0xffff);
    if (iVar1 == 0) {
      return 0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/secur/secur.c",0x47,
                  "secur_unsecure_msg",0x10000);
  }
  return 2;
}

