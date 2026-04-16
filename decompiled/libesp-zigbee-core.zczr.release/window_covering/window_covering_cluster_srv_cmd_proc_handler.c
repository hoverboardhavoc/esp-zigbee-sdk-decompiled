/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> window_covering.o -> window_covering_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t window_covering_cluster_srv_cmd_proc_handler(void *arg)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_4c;
  ezb_zcl_window_covering_movement_message_t message;
  zcl_packet_t rsp;
  
  iVar1 = 1;
  memset(&message.out,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar1 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar1 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar1 != 0))
  goto _L0;
  uVar4 = (uint)*(byte *)((int)arg + 0x20);
  iVar1 = 8;
  if ((uVar4 < 9) && ((0x1b7U >> (uVar4 & 0x1f) & 1) != 0)) {
    uStack_4c = 0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    message.in.payload = (ezb_zcl_window_covering_cmd_payload_t)0x0;
    message.in._6_2_ = 0;
    message._4_4_ = arg;
    if (uVar4 == 5) {
      uVar4 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,1,&message.in);
_L0:
      if (uVar4 == 0) {
        uVar4 = 0xffff;
      }
_L0:
      uVar2 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uVar3 = 0x80;
      if (uVar4 <= uVar2) {
        if (((0x318U >> iVar1 & 1) == 0) ||
           (iVar1 = ezb_zcl_set_attr_value
                              (*(undefined1 *)((int)arg + 0x15),0x102,1,iVar1,0,&message.in,0),
           iVar1 != 0)) {
          uVar3 = zcl_packet_to_message(&uStack_4c,arg);
          if (uVar3 == 0) {
            message.in.payload.lift_percentage = 0xfe;
            zcl_core_action_schedule(0x1a,&uStack_4c,0);
            if ((message.in._4_4_ & 0xff) == 0xfe) goto _L0;
            uVar3 = (uint)((message.in._4_4_ & 0xff) != 0);
          }
        }
        else {
_L0:
          uVar3 = 0;
        }
      }
    }
    else {
      if (5 < uVar4) {
        if (uVar4 == 7) {
          uVar4 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,2,&message.in);
          iVar1 = 4;
        }
        else {
          if (uVar4 != 8) goto _L88;
          uVar4 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,1,&message.in);
          iVar1 = 9;
        }
        goto _L0;
      }
      if (uVar4 < 3) {
        uVar4 = 0;
        iVar1 = 0;
        goto _L0;
      }
      if (uVar4 == 4) {
        uVar4 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,&message.in);
        iVar1 = 3;
        goto _L0;
      }
_L88:
      uVar3 = 0x81;
    }
    iVar1 = zcl_packet_setup_default_response(&message.out,arg,uVar3);
  }
  else {
    iVar1 = zcl_packet_send_default_response(arg,0x81);
  }
  if (iVar1 == 0) {
    zcl_packet_send(&message.out,0);
  }
  else {
    zcl_packet_free(&message.out);
  }
_L0:
  return (ezb_zcl_status_t)iVar1;
}

