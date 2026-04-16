/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_load_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_load_header(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  uint uVar2;
  uint16_t local_12 [2];
  uint16_t offset;
  
  local_12[0] = 0;
  af_read_le8(packet->payload,local_12,&(packet->header).fc);
  if (((packet->header).fc & 4) == 0) {
    (packet->header).manuf_code = 0;
  }
  else {
    af_read_le16(packet->payload,local_12,&(packet->header).manuf_code);
  }
  af_read_le8(packet->payload,local_12,&(packet->header).tsn);
  af_read_le8(packet->payload,local_12,&(packet->header).cmd_id);
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < local_12[0]) {
    zVar1 = 0x80;
  }
  else {
    zmsg_remove_header(packet->payload);
    zVar1 = '\0';
  }
  return zVar1;
}

