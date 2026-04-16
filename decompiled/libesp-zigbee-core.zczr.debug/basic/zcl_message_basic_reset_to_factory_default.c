/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> basic.o -> zcl_message_basic_reset_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t zcl_message_basic_reset_to_factory_default(zcl_packet_t *packet)

{
  undefined4 local_20;
  ezb_zcl_basic_reset_factory_default_message_t message;
  
  local_20 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  zcl_packet_to_message(&local_20,packet);
  message.in.header._0_1_ = 0xfe;
  message._4_4_ = packet;
  zcl_core_action_schedule(0xb,&local_20);
  if ((ezb_zcl_status_t)message.in.header == 0xfe) {
    message.in.header._0_1_ = '\0';
  }
  return (ezb_zcl_status_t)message.in.header;
}

