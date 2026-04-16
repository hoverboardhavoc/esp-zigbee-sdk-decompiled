/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> secur_api.o -> ezb_secur_broadcast_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_secur_broadcast_network_key(uint8_t *key,uint8_t key_seq)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined4 uStack_3c;
  apsme_transport_key_req_t req;
  
  if (key != (uint8_t *)0x0) {
    iVar1 = aps_secur_is_tc();
    eVar2 = 0xd;
    if (iVar1 != 0) {
      memset((void *)((int)&req.field_2 + 0xd),0,0x10);
      req.dst_address.field_0.u8[4] = '\x01';
      uStack_3c = 0xffffffff;
      req.dst_address.field_0.u64._0_4_ = 0xffffffff;
      req.field_2.nwk.key[0xc] = key_seq;
      memcpy((void *)((int)&req.dst_address.field_0 + 5),key,0x10);
      eVar2 = apsme_transport_key_request(&uStack_3c);
    }
    return eVar2;
  }
  return 2;
}

