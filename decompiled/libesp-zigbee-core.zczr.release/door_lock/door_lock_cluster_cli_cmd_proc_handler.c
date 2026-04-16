/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> door_lock_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t door_lock_cluster_cli_cmd_proc_handler(void *arg)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_4c;
  ezb_zcl_door_lock_lock_door_rsp_message_t message;
  zcl_packet_t rsp;
  
  iVar1 = 1;
  memset(&message.out,0,0x28);
  if (arg != (void *)0x0) {
    iVar1 = 1;
    if (((*(byte *)((int)arg + 0x1a) & 8) != 0) &&
       (iVar1 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar1 == 0)) {
      if (*(char *)((int)arg + 0x20) == '\0') {
        uStack_4c = 0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        message.in.req_status = '\0';
        message.in._5_3_ = 0;
        iVar1 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        uVar2 = 0x80;
        if (iVar1 != 0) {
          zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,1,&message.in);
          uVar2 = zcl_packet_to_message(&uStack_4c,arg);
          if (uVar2 == 0) {
            message.in.req_status = 0xfe;
            message._4_4_ = arg;
            zcl_core_action_schedule(0x18,&uStack_4c,0);
            if ((message.in._4_4_ & 0xff) != 0xfe) {
              uVar2 = message.in._4_4_ & 0xff;
            }
          }
        }
      }
      else if (*(char *)((int)arg + 0x20) == '\x01') {
        uStack_4c = 0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        message.in.req_status = '\0';
        message.in._5_3_ = 0;
        iVar1 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        uVar2 = 0x80;
        if (iVar1 != 0) {
          zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,1,&message.in);
          uVar2 = zcl_packet_to_message(&uStack_4c,arg);
          if (uVar2 == 0) {
            message.in.req_status = 0xfe;
            message._4_4_ = arg;
            zcl_core_action_schedule(0x19,&uStack_4c);
            if ((message.in._4_4_ & 0xff) != 0xfe) {
              uVar2 = message.in._4_4_ & 0xff;
            }
          }
        }
      }
      else {
        uVar2 = 0x81;
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

