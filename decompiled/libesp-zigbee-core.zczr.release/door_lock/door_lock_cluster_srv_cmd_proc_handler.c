/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> door_lock_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t door_lock_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  bool bVar7;
  byte abStack_5c [3];
  undefined1 uStack_59;
  zcl_packet_tx_option_t tx_option;
  ezb_zcl_door_lock_lock_door_message_t message;
  zcl_packet_t rsp;
  
  memset(&message.out,0,0x28);
  abStack_5c[0] = 0;
  if (arg == (void *)0x0) {
    iVar2 = 1;
    goto _L0;
  }
  bVar1 = *(byte *)((int)arg + 0x1a) >> 3;
  bVar7 = (bool)(bVar1 & 1);
  iVar2 = 1;
  if (((bVar1 & 1) != 0) ||
     (iVar2 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar2 != 0))
  goto _L0;
  iVar3 = ezb_zcl_get_attr_desc(*(undefined1 *)((int)arg + 0x15),0x101,1,0x34,0);
  if (iVar3 == 0) {
_L0:
    iVar6 = 0;
  }
  else {
    iVar6 = 1;
    if ((**(char **)(iVar3 + 8) != '\0') && (iVar6 = 2, **(char **)(iVar3 + 8) != '\x01')) {
      __assert_func(0,0,0,0);
      goto _L0;
    }
  }
  iVar3 = zcl_packet_get_security(arg);
  if (iVar3 < iVar6) {
    iVar2 = 0xfe;
    goto _L0;
  }
  if (*(char *)((int)arg + 0x20) == '\0') {
    _tx_option = 0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message.info.cluster_role = '\0';
    message.info._5_1_ = 0;
    message._6_2_ = 0;
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    uVar4 = zcl_packet_to_message(&tx_option,arg);
    if (uVar4 != 0) goto _L0;
    message.in.header._0_1_ = 0xfe;
    message._4_4_ = arg;
    zcl_core_action_schedule(0x16,&tx_option);
    uStack_59 = (char)message.in.header != '\0';
    uVar4 = zmsg_append_bytes(rsp._32_4_,1,&uStack_59);
    uVar4 = uVar4 & 0xff;
    uVar5 = 0;
    if (uVar4 != 0) goto _L0;
_L70:
    uVar4 = zcl_packet_setup_response(&message.out,arg,uVar5);
    if (uVar4 != 0) goto _L0;
  }
  else {
    if (*(char *)((int)arg + 0x20) == '\x01') {
      _tx_option = 0;
      message.info.status = '\0';
      message.info.dst_ep = '\0';
      message.info.cluster_id = 0;
      message.info.cluster_role = '\0';
      message.info._5_1_ = 0;
      message._6_2_ = 0;
      message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
      uVar4 = zcl_packet_to_message(&tx_option,arg);
      if (uVar4 == 0) {
        message.in.header._0_1_ = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x17,&tx_option);
        uStack_59 = (char)message.in.header != '\0';
        uVar4 = zmsg_append_bytes(rsp._32_4_,1,&uStack_59);
        uVar4 = uVar4 & 0xff;
        if (uVar4 == 0) {
          uVar5 = 1;
          goto _L70;
        }
      }
    }
    else {
      uVar4 = 0x81;
    }
_L0:
    iVar3 = zcl_packet_setup_default_response(&message.out,arg,uVar4);
    if (iVar3 != 0) {
      zcl_packet_free(&message.out);
      iVar2 = iVar3;
      goto _L0;
    }
  }
  if ((char)rsp.header.manuf_code != '\v') {
    iVar3 = zcl_packet_get_security(arg);
    bVar7 = iVar3 == 2;
  }
  abStack_5c[0] = abStack_5c[0] & 0xfe | bVar7;
  zcl_packet_send_with_ext(&message.out,0,abStack_5c);
_L0:
  return (ezb_zcl_status_t)iVar2;
}

