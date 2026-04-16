/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_init_with_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_init_with_msg(zcl_packet_t *packet,af_data_ind_t *ind)

{
  ezb_shortaddr_t eVar1;
  ezb_shortaddr_t eVar2;
  zcl_status_t zVar3;
  undefined3 extraout_var;
  
  if (packet != (zcl_packet_t *)0x0) {
    zVar3 = 0x87;
    if (ind != (af_data_ind_t *)0x0) {
      packet->payload = ind->asdu;
      zVar3 = zcl_packet_load_header(packet);
      if (CONCAT31(extraout_var,zVar3) == 0) {
        (packet->header).src_ep = (ind->addr_info).src_ep;
        (packet->header).dst_ep = (ind->addr_info).dst_ep;
        (packet->header).cluster_id = (ind->addr_info).cluster_id;
        (packet->header).profile_id = (ind->addr_info).profile_id;
        (packet->header).src_addr.addr_mode = '\x02';
        eVar1 = (ind->addr_info).src_addr;
        (packet->header).dst_addr.addr_mode = '\x02';
        eVar2 = (ind->addr_info).dst_addr;
        (packet->header).src_addr.u.short_addr = eVar1;
        (packet->header).dst_addr.u.short_addr = eVar2;
        (packet->header).rssi = -1;
        zVar3 = '\0';
      }
      else {
        zVar3 = 0x80;
      }
    }
    return zVar3;
  }
  return 0x87;
}

