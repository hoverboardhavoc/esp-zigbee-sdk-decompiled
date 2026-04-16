/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_setup_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_packet_setup_header
               (zcl_packet_t *packet,uint8_t frame_type,uint8_t manuf_spec,uint8_t direction,
               uint8_t dis_def_resp,uint16_t manuf_code,uint8_t command_id)

{
  byte bVar1;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  undefined3 in_register_00002039;
  byte bVar2;
  
  bVar1 = (packet->header).fc;
  bVar2 = bVar1 & 0xfc;
  (packet->header).fc = bVar2;
  bVar2 = bVar2 | frame_type & 3;
  (packet->header).fc = bVar2;
  if (CONCAT31(in_register_00002031,manuf_spec) == 0) {
    (packet->header).fc = bVar1 & 0xf8 | frame_type & 3;
  }
  else {
    (packet->header).fc = bVar2 | 4;
  }
  if (CONCAT31(in_register_00002035,direction) == 0) {
    (packet->header).fc = (packet->header).fc & 0xf7;
  }
  else {
    (packet->header).fc = (packet->header).fc | 8;
  }
  if (CONCAT31(in_register_00002039,dis_def_resp) == 0) {
    (packet->header).fc = (packet->header).fc & 0xef;
  }
  else {
    (packet->header).fc = (packet->header).fc | 0x10;
  }
  (packet->header).cmd_id = command_id;
  (packet->header).manuf_code = manuf_code;
  return;
}

