/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_init_with_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_init_with_msg(zdo_packet_t *packet,af_data_ind_t *ind)

{
  uint uVar1;
  zdp_status_t zVar2;
  uint8_t auStack_11 [4];
  uint8_t tsn;
  
  auStack_11[0] = '\0';
  if (packet == (zdo_packet_t *)0x0) {
    zVar2 = 0x80;
  }
  else if (ind == (af_data_ind_t *)0x0) {
    zVar2 = 0x80;
  }
  else {
    uVar1._0_2_ = (ind->addr_info).grp_addr;
    uVar1._2_1_ = (ind->addr_info).src_ep;
    uVar1._3_1_ = (ind->addr_info).dst_ep;
    if (uVar1 < 0x10000) {
      zmsg_read_bytes(ind->asdu,0,1,auStack_11);
      zmsg_remove_header(ind->asdu,1);
      packet->tsn = auStack_11[0];
      packet->src_addr = (ind->addr_info).src_addr;
      packet->dst_addr = (ind->addr_info).dst_addr;
      packet->cluster_id = (ind->addr_info).cluster_id;
      packet->payload = ind->asdu;
      zVar2 = '\0';
    }
    else {
      zVar2 = 0x82;
    }
  }
  return zVar2;
}

