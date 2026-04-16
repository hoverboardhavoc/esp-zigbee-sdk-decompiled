/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> secur_api.o -> ezb_secur_broadcast_network_key
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
  
  if (key == (uint8_t *)0x0) {
    eVar2 = 2;
  }
  else {
    iVar1 = aps_secur_is_tc();
    if (iVar1 == 0) {
      eVar2 = 0xd;
    }
    else {
      req._8_4_ = 0;
      req.field_2._3_4_ = 0;
      req.field_2._7_4_ = 0;
      req.field_2._15_4_ = 0;
      req.field_2._19_4_ = 0;
      req._32_4_ = 0;
      req.tunnel_address.field_0.u64._2_2_ = 0;
      req.dst_address.field_0.u64._4_4_ = 1;
      req.field_2._11_4_ = (uint)key_seq << 8;
      uStack_3c = 0xffffffff;
      req.dst_address.field_0.u64._0_4_ = 0xffffffff;
      memcpy((void *)((int)&req.dst_address.field_0 + 5),key,0x10);
      eVar2 = apsme_transport_key_request(&uStack_3c);
    }
  }
  return eVar2;
}

