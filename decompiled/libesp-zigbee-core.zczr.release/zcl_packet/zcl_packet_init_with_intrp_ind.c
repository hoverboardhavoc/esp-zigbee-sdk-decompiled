/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_init_with_intrp_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_init_with_intrp_ind(zcl_packet_t *packet,void *arg)

{
  zcl_status_t zVar1;
  undefined3 extraout_var;
  
  zVar1 = 0x87;
  if ((packet != (zcl_packet_t *)0x0) && (zVar1 = 0x87, arg != (void *)0x0)) {
    packet->payload = *(zcl_packet_payload_t **)((int)arg + 0x20);
    zVar1 = zcl_packet_load_header(packet);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      (packet->header).src_ep = '\0';
      (packet->header).dst_ep = '\0';
      (packet->header).cluster_id = *(uint16_t *)((int)arg + 0x1a);
      (packet->header).profile_id = *(uint16_t *)((int)arg + 0x18);
      memcpy(packet,(void *)((int)arg + 2),10);
      memcpy(&(packet->header).dst_addr,(void *)((int)arg + 0xe),10);
      (packet->header).rssi = *(int8_t *)((int)arg + 0x25);
      zVar1 = '\0';
    }
    else {
      zVar1 = 0x80;
    }
  }
  return zVar1;
}

