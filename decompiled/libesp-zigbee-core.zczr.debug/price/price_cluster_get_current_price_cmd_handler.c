/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_get_current_price_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t price_cluster_get_current_price_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint uVar1;
  ezb_zcl_status_t eVar2;
  uint16_t uVar3;
  undefined2 extraout_var;
  uint16_t uStack_26;
  undefined4 uStack_24;
  uint16_t offset;
  ezb_zcl_price_get_current_price_message_t message;
  
  uStack_24 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.cmd_opts = '\0';
  message.in._5_3_ = 0;
  uStack_26 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0x5b,
                  "price_cluster_get_current_price_cmd_handler","packet && rsp");
  }
  else {
    uVar3 = af_read_le8(packet->payload,&uStack_26,(uint8_t *)&message.in);
    if (CONCAT22(extraout_var,uVar3) == 0) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  uVar1 = zcl_packet_to_message(&stack0xffffffdc,packet);
  if (uVar1 == 0) {
    message.in.cmd_opts = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x4a,&stack0xffffffdc);
    uVar1 = message.in._4_4_ & 0xff;
    if (uVar1 == 0xfe) {
      uVar1 = 0x8b;
    }
    else if (uVar1 == 0) {
      return (ezb_zcl_status_t)message.in._4_4_;
    }
  }
_L0:
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar1);
  return eVar2;
}

