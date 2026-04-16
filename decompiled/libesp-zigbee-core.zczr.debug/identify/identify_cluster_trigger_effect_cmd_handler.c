/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_trigger_effect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t identify_cluster_trigger_effect_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  uint16_t uStack_14;
  uint8_t local_12;
  uint8_t uStack_11;
  uint16_t offset;
  uint8_t effect_variant;
  uint8_t effect_id;
  
  uStack_11 = '\0';
  local_12 = '\0';
  uStack_14 = 0;
  if (packet == (zcl_packet_t *)0x0) {
    eVar1 = 0xfe;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    eVar1 = 0xfe;
  }
  else {
    af_read_le8(packet->payload,&uStack_14,&uStack_11);
    af_read_le8(packet->payload,&uStack_14,&local_12);
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < uStack_14) {
      eVar1 = 0x80;
    }
    else {
      eVar1 = zcl_message_identify_trigger_effect(packet,uStack_11,local_12);
    }
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,eVar1);
  return eVar1;
}

