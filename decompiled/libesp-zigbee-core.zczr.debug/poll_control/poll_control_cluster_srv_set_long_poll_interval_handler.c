/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_set_long_poll_interval_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
poll_control_cluster_srv_set_long_poll_interval_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  byte bVar1;
  ezb_zcl_status_t eVar2;
  uint16_t uVar3;
  uint uVar5;
  uint32_t uStack_18;
  uint32_t long_poll_interval;
  uint16_t offset;
  ushort uVar4;
  
  long_poll_interval._2_2_ = 0;
  uStack_18 = 0;
  if (packet == (zcl_packet_t *)0x0) {
    uVar4 = 0xfe;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    uVar4 = 0xfe;
  }
  else {
    uVar5 = zmsg_get_length(packet->payload);
    uVar3 = af_read_le32(packet->payload,(uint16_t *)((int)&long_poll_interval + 2),&uStack_18);
    uVar4 = uVar3 & 0xff;
    if ((uVar3 & 0xff) == 0) {
      if (uVar5 < long_poll_interval._2_2_) {
        uVar4 = 0x80;
      }
      else {
        bVar1 = zcl_message_poll_control_notify((packet->header).dst_ep,1,(uint8_t *)&uStack_18);
        uVar4 = (ushort)bVar1;
      }
    }
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar2;
}

