/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_init_with_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_init_with_msg(zcl_packet_t *packet,af_data_ind_t *ind)

{
  zcl_status_t zVar1;
  undefined3 extraout_var;
  int iVar2;
  
  if (packet == (zcl_packet_t *)0x0) {
    iVar2 = 0x87;
  }
  else if (ind == (af_data_ind_t *)0x0) {
    iVar2 = 0x87;
  }
  else {
    packet->payload = ind->asdu;
    zVar1 = zcl_packet_load_header(packet);
    iVar2 = CONCAT31(extraout_var,zVar1);
    if (iVar2 == 0) {
      (packet->header).src_ep = (ind->addr_info).src_ep;
      (packet->header).dst_ep = (ind->addr_info).dst_ep;
      (packet->header).cluster_id = (ind->addr_info).cluster_id;
      (packet->header).profile_id = (ind->addr_info).profile_id;
      (packet->header).src_addr.addr_mode = '\x02';
      (packet->header).src_addr.u.short_addr = (ind->addr_info).src_addr;
      (packet->header).dst_addr.addr_mode = '\x02';
      (packet->header).dst_addr.u.short_addr = (ind->addr_info).dst_addr;
      (packet->header).rssi = ind->rssi;
    }
  }
  return (zcl_status_t)iVar2;
}

