/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_zone_cluster_cli_cmd_proc_handler(void *arg)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint16_t uStack_52;
  undefined4 uStack_50;
  uint16_t offset;
  ezb_zcl_ias_zone_enroll_req_message_t message;
  undefined1 auStack_38 [4];
  zcl_packet_t rsp;
  
  memset(auStack_38,0,0x28);
  iVar3 = 1;
  if (arg == (void *)0x0) goto _L0;
  iVar3 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar1 = zcl_packet_init(auStack_38,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar3 = iVar1,
     iVar1 != 0)) goto _L0;
  if (*(char *)((int)arg + 0x20) == '\0') {
    uStack_52 = 0;
    memset(&stack0xffffffb0,0,0x18);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_52,(uint16_t *)&message.in);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,(uint8_t *)((int)&message.in.header + 2));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_52,(uint8_t *)((int)&message.in.header + 3));
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_52,&message.in.payload.zone_type);
    uVar2 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uVar4 = 0x80;
    if ((uStack_52 <= uVar2) &&
       (uVar4 = zcl_packet_to_message(&stack0xffffffb0,arg,0x80), uVar4 == 0)) {
      message.out.result = 0xfe;
      message._4_4_ = arg;
      zcl_core_action_schedule(0x32,&stack0xffffffb0,0);
      uVar4 = (uint)message.out.result;
      if (uVar4 == 0xfe) {
_L0:
        uVar4 = 1;
      }
    }
_L0:
    iVar3 = zcl_packet_setup_default_response(auStack_38,arg,uVar4);
    if (iVar3 != 0) {
      zcl_packet_free(auStack_38);
      goto _L0;
    }
  }
  else {
    if (*(char *)((int)arg + 0x20) != '\x01') {
      uVar4 = 0x81;
      goto _L0;
    }
    uStack_52 = 0;
    uStack_50 = 0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message.info.cluster_role = '\0';
    message.info._5_1_ = 0;
    message._6_2_ = 0;
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    message.in.payload.zone_type = 0;
    message.in.payload.manuf_code = 0;
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_52,(uint16_t *)&message.in);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_52,(uint16_t *)((int)&message.in.header + 2))
    ;
    uVar2 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uVar4 = 0x80;
    if ((uVar2 < uStack_52) ||
       (uVar4 = zcl_packet_to_message(&stack0xffffffb0,arg,0x80), uVar4 != 0)) goto _L0;
    message.in.payload.zone_type._0_1_ = 0xfe;
    message._4_4_ = arg;
    zcl_core_action_schedule(0x30,&stack0xffffffb0,0);
    uVar4 = (uint)message.in.payload & 0xff;
    if (uVar4 == 0xfe) goto _L0;
    if (uVar4 != 0) goto _L0;
  }
  zcl_packet_send(auStack_38,0);
  iVar3 = iVar1;
_L0:
  return (ezb_zcl_status_t)iVar3;
}

