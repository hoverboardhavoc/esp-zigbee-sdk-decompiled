/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_reset_all_alarms_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t alarms_cluster_reset_all_alarms_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint uVar1;
  ezb_zcl_status_t eVar2;
  ezb_err_t eVar3;
  uint unaff_s2;
  undefined4 local_30;
  ezb_zcl_alarms_reset_all_alarms_message_t message;
  
  local_30 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1e7,
                  "alarms_cluster_reset_all_alarms_cmd_handler","packet && rsp");
  }
  else {
    unaff_s2 = zcl_packet_to_message(&local_30,packet);
    if (unaff_s2 != 0) goto _L0;
  }
  message.in.header._0_1_ = 0xfe;
  message._4_4_ = packet;
  zcl_core_action_schedule(0x36,&local_30);
  uVar1 = (uint)message.in.header & 0xff;
  if (((uint)message.in.header & 0xff) == 0xfe) {
    uVar1 = unaff_s2;
  }
  unaff_s2 = uVar1;
  eVar3 = alarm_table_reset((packet->header).dst_ep);
  if (eVar3 == 0) {
    if ((char)message.in.header == -2) {
      unaff_s2 = 1;
    }
  }
  else {
    unaff_s2 = 0x8b;
  }
_L0:
  eVar2 = zcl_packet_setup_default_response(rsp,packet,unaff_s2);
  return eVar2;
}

