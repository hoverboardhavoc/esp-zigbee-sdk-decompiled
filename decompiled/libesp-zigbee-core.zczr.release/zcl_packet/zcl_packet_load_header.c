/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_load_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_load_header(zcl_packet_t *packet)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  zcl_status_t zVar4;
  
  uVar1 = zmsg_read_bytes(packet->payload,0,1,&(packet->header).fc);
  if (uVar1 == 0) {
    uVar1 = 0xffff;
  }
  if (((packet->header).fc & 4) == 0) {
    (packet->header).manuf_code = 0;
  }
  else {
    iVar2 = zmsg_read_bytes(packet->payload,uVar1,2,&(packet->header).manuf_code);
    if (iVar2 == 0) {
      uVar1 = 0xffff;
    }
    else {
      uVar1 = uVar1 + iVar2 & 0xffff;
    }
  }
  iVar2 = zmsg_read_bytes(packet->payload,uVar1,1,&(packet->header).tsn);
  if (iVar2 == 0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = iVar2 + uVar1 & 0xffff;
  }
  iVar2 = zmsg_read_bytes(packet->payload,uVar1,1,&(packet->header).cmd_id);
  if (iVar2 == 0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = iVar2 + uVar1 & 0xffff;
  }
  uVar3 = zmsg_get_length(packet->payload);
  zVar4 = 0x80;
  if (uVar1 <= uVar3) {
    zmsg_remove_header(packet->payload);
    zVar4 = '\0';
  }
  return zVar4;
}

