/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_panic_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_panic_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint unaff_s1;
  ezb_zcl_status_t eVar1;
  undefined4 local_20;
  ezb_zcl_ias_ace_emergency_message_t message;
  
  local_20 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  if (packet == (zcl_packet_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x13e,
                  "ias_ace_cluster_panic_cmd_handler","packet");
  }
  else {
    unaff_s1 = zcl_packet_to_message(&local_20,packet);
    if (unaff_s1 != 0) goto _L0;
  }
  message.in.header._0_1_ = 0xfe;
  message._4_4_ = packet;
  zcl_core_action_schedule(0x20,&local_20);
  if (((uint)message.in.header & 0xff) != 0xfe) {
    unaff_s1 = (uint)message.in.header & 0xff;
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,unaff_s1);
  return eVar1;
}

