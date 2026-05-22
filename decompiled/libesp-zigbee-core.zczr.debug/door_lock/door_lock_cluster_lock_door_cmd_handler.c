/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> door_lock_cluster_lock_door_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t door_lock_cluster_lock_door_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint uVar1;
  undefined1 uStack_21;
  undefined4 uStack_20;
  ezb_zcl_door_lock_lock_door_message_t message;
  
  uStack_20 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/door_lock.c",0x72,
                  "door_lock_cluster_lock_door_cmd_handler","packet && rsp");
_L0:
    message.in.header._0_1_ = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x16,&uStack_20);
    uStack_21 = (char)message.in.header != '\0';
    uVar1 = zmsg_append_bytes(rsp->payload,1,&uStack_21);
    uVar1 = uVar1 & 0xff;
    if ((uVar1 == 0) && (uVar1 = zcl_packet_setup_response(rsp,packet,0), uVar1 == 0)) goto _L0;
  }
  else {
    uVar1 = zcl_packet_to_message(&uStack_20,packet);
    if (uVar1 == 0) goto _L0;
  }
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

