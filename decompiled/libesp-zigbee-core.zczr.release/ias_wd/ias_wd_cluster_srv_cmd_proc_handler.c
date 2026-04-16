/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_wd.o -> ias_wd_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_wd_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  uint16_t uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bStack_53;
  uint16_t uStack_52;
  uint8_t warning_byte;
  undefined4 uStack_50;
  uint16_t offset;
  ezb_zcl_ias_wd_start_warning_message_t message;
  zcl_packet_t rsp;
  
  iVar3 = 1;
  memset(&message.out,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar3 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar3 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar3 != 0))
  goto _L0;
  if (*(char *)((int)arg + 0x20) == '\0') {
    uStack_52 = 0;
    bStack_53 = 0;
    memset(&stack0xffffffb0,0,0x18);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,&bStack_53);
    uVar2 = uStack_52;
    iVar3 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uStack_52,2,
                            (undefined1 *)((int)&message.in.header + 2));
    if (iVar3 == 0) {
      uStack_52 = 0xffff;
    }
    else {
      uStack_52 = uVar2 + (short)iVar3;
    }
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,(uint8_t *)&message.in.payload);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,&message.in.payload.field_0x1);
    uVar4 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uVar5 = 0x80;
    if (uStack_52 <= uVar4) {
      message.in.header =
           (ezb_zcl_cmd_hdr_t *)
           CONCAT31(message.in.header._1_3_,
                    (byte)((bStack_53 & 0xc) << 2) | bStack_53 >> 4 | bStack_53 << 6);
      uVar5 = zcl_packet_to_message(&stack0xffffffb0,arg,0x80);
      if (uVar5 == 0) {
        message.in.payload.strobe_duty_cycle = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x2c,&stack0xffffffb0,0);
        bVar1 = message.in.payload.strobe_duty_cycle;
_L0:
        uVar5 = (uint)bVar1;
        if (uVar5 == 0xfe) {
          uVar5 = 1;
        }
      }
    }
  }
  else if (*(char *)((int)arg + 0x20) == '\x01') {
    uStack_52 = 0;
    bStack_53 = 0;
    uStack_50 = 0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message.info.cluster_role = '\0';
    message.info._5_1_ = 0;
    message._6_2_ = 0;
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    message.in.payload._0_2_ = 0;
    message.in.payload.duration = 0;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,&bStack_53);
    uVar4 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uVar5 = 0x80;
    if (uStack_52 <= uVar4) {
      message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,bStack_53);
      uVar5 = zcl_packet_to_message(&stack0xffffffb0,arg,0x80);
      if (uVar5 == 0) {
        message.in.payload._0_1_ = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x2d,&stack0xffffffb0,0);
        bVar1 = message.in.payload._0_1_;
        goto _L0;
      }
    }
  }
  else {
    uVar5 = 0x81;
  }
  iVar3 = zcl_packet_setup_default_response(&message.out,arg,uVar5);
  if (iVar3 == 0) {
    zcl_packet_send(&message.out,0);
  }
  else {
    zcl_packet_free(&message.out);
  }
_L0:
  return (ezb_zcl_status_t)iVar3;
}

