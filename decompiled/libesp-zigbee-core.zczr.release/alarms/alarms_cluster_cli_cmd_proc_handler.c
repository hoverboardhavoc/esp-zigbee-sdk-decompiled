/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarms_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t alarms_cluster_cli_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uStack_64;
  uint16_t uStack_52;
  undefined4 uStack_50;
  uint16_t offset;
  ezb_zcl_alarms_get_alarm_rsp_message_t message;
  zcl_packet_t rsp;
  
  iVar2 = 1;
  memset(&message.out,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar2 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar2 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar2 != 0))
  goto _L0;
  if (*(char *)((int)arg + 0x20) == '\0') {
    uStack_50 = 0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message.info.cluster_role = '\0';
    message.info._5_1_ = 0;
    message._6_2_ = 0;
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    message.in.payload.status = '\0';
    message.in.payload.alarm_code = '\0';
    message.in.payload.cluster_id = 0;
    uStack_52 = 0;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,(uint8_t *)&message.in);
    uVar3 = (uint)uStack_52;
    iVar2 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar3,2,
                            (undefined1 *)((int)&message.in.header + 2));
    if (iVar2 == 0) {
      uVar3 = 0xffff;
    }
    else {
      uVar3 = uVar3 + iVar2 & 0xffff;
    }
    uStack_52 = (uint16_t)uVar3;
    uVar4 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uStack_64 = 0x80;
    if ((uVar3 <= uVar4) &&
       (uStack_64 = zcl_packet_to_message(&stack0xffffffb0,arg,0x80), uStack_64 == 0)) {
      message.in.payload.status = 0xfe;
      message._4_4_ = arg;
      zcl_core_action_schedule(0x33,&stack0xffffffb0,0);
      bVar1 = message.in.payload.status;
_L0:
      if (bVar1 != 0xfe) {
        uStack_64 = (uint)bVar1;
      }
    }
  }
  else {
    uStack_64 = 0x81;
    if (*(char *)((int)arg + 0x20) == '\x01') {
      memset(&stack0xffffffb0,0,0x18);
      uStack_52 = 0;
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,(uint8_t *)&message.in);
      if ((char)message.in.header == '\0') {
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,
                    (uint8_t *)((int)&message.in.header + 1));
        uVar3 = (uint)uStack_52;
        iVar2 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar3,2,
                                (undefined1 *)((int)&message.in.header + 2));
        if (iVar2 == 0) {
          uVar3 = 0xffff;
        }
        else {
          uVar3 = uVar3 + iVar2 & 0xffff;
        }
        iVar2 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar3,4,&message.in.payload);
        if (iVar2 == 0) {
          uStack_52 = 0xffff;
        }
        else {
          uStack_52 = (short)uVar3 + (short)iVar2;
        }
      }
      uVar3 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uStack_64 = 0x80;
      if ((uStack_52 <= uVar3) &&
         (uStack_64 = zcl_packet_to_message(&stack0xffffffb0,arg,0x80), uStack_64 == 0)) {
        message.in.payload.timestamp._0_1_ = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x34,&stack0xffffffb0,0);
        bVar1 = (byte)message.in.payload.timestamp;
        goto _L0;
      }
    }
  }
  iVar2 = zcl_packet_setup_default_response(&message.out,arg,uStack_64);
  if (iVar2 == 0) {
    zcl_packet_send(&message.out,0);
  }
  else {
    zcl_packet_free(&message.out);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

