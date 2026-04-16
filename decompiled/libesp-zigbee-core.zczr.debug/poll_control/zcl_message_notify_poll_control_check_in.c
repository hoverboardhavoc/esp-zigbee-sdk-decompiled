/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> zcl_message_notify_poll_control_check_in
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_notify_poll_control_check_in(zcl_packet_t *packet,uint16_t *fast_poll_timeout)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_20;
  ezb_zcl_poll_control_check_in_message_t message;
  
  local_20 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  uVar1 = zcl_packet_to_message(&local_20,packet);
  uVar2 = uVar1;
  if (uVar1 == 0) {
    message.in.header._0_1_ = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x3d,&local_20);
    uVar2 = (uint)message.in.header & 0xff;
    if ((uVar2 == 0xfe) || (uVar1 = uVar2, uVar2 == 0)) {
      uVar2 = uVar1;
      *fast_poll_timeout = message.in.header._2_2_;
    }
  }
  return (ezb_zcl_status_t)uVar2;
}

