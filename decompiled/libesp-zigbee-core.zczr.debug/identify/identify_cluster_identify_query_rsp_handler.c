/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_identify_query_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t identify_cluster_identify_query_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  uint16_t auStack_14 [2];
  uint16_t offset;
  uint16_t timeout;
  
  auStack_14[1] = 0;
  auStack_14[0] = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x14c,
                  "identify_cluster_identify_query_rsp_handler","packet && rsp");
  }
  else {
    af_read_le16(packet->payload,auStack_14,auStack_14 + 1);
    uVar2 = zmsg_get_length(packet->payload);
    if (auStack_14[0] <= uVar2) {
      eVar1 = zcl_packet_setup_default_response(rsp,packet,0);
      return eVar1;
    }
  }
  return 0x80;
}

