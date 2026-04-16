/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> basic.o -> basic_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t basic_cluster_srv_cmd_proc_handler(void *arg)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_48;
  ezb_zcl_basic_reset_factory_default_message_t message;
  zcl_packet_t rsp;
  
  iVar1 = 0xfe;
  memset(&message.out,0,0x28);
  if (arg != (void *)0x0) {
    iVar1 = 0xfe;
    if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) == 0) &&
       (iVar1 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar1 == 0)) {
      uVar2 = 0x81;
      if (*(char *)((int)arg + 0x20) == '\0') {
        uStack_48 = 0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        zcl_packet_to_message(&uStack_48,arg,0x81);
        message.in.header._0_1_ = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0xb,&uStack_48);
        uVar2 = (uint)message.in.header & 0xff;
        if (uVar2 == 0xfe) {
          uVar2 = 0;
        }
      }
      iVar1 = zcl_packet_setup_default_response(&message.out,arg,uVar2);
      if (iVar1 == 0) {
        zcl_packet_send(&message.out,0);
      }
      else {
        zcl_packet_free(&message.out);
      }
    }
  }
  return (ezb_zcl_status_t)iVar1;
}

