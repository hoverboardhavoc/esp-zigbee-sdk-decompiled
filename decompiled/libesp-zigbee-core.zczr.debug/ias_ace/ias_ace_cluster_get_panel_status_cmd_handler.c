/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_panel_status_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_ace_cluster_get_panel_status_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint uVar1;
  int iVar2;
  ezb_zcl_status_t eStack_25;
  undefined4 uStack_24;
  ezb_zcl_ias_ace_get_panel_status_message_t message;
  
  uStack_24 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.out.result = '\0';
  message.out.payload.panel_status = '\0';
  message.out.payload.seconds_remaining = '\0';
  message.out.payload.aud_notif = '\0';
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",400,
                  "ias_ace_cluster_get_panel_status_cmd_handler","packet && rsp");
_L0:
    message.in.header._0_1_ = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x21,&uStack_24);
    uVar1 = (uint)message.in.header & 0xff;
    if (uVar1 == 0xfe) {
      uVar1 = 0x8b;
    }
    else if (uVar1 == 0) {
      eStack_25 = message.in.header._1_1_;
      iVar2 = zmsg_append_bytes(rsp->payload,1,&eStack_25);
      if (iVar2 == 0) {
        eStack_25 = message.in.header._2_1_;
        iVar2 = zmsg_append_bytes(rsp->payload,1,&eStack_25);
        if (iVar2 == 0) {
          eStack_25 = message.in.header._3_1_;
          iVar2 = zmsg_append_bytes(rsp->payload,1,&eStack_25);
          if (iVar2 == 0) {
            eStack_25 = message.out.result;
            iVar2 = zmsg_append_bytes(rsp->payload,1,&eStack_25);
            if (iVar2 == 0) {
              uVar1 = zcl_packet_setup_response(rsp,packet,5);
              if (uVar1 == 0) goto _L0;
            }
            else {
              uVar1 = 0x89;
            }
          }
          else {
            uVar1 = 0x89;
          }
        }
        else {
          uVar1 = 0x89;
        }
      }
      else {
        uVar1 = 0x89;
      }
    }
  }
  else {
    uVar1 = zcl_packet_to_message(&uStack_24,packet);
    if (uVar1 == 0) goto _L0;
  }
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

