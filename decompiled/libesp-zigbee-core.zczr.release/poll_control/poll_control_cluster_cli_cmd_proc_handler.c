/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t poll_control_cluster_cli_cmd_proc_handler(void *arg)

{
  int iVar1;
  void *__dest;
  void *pvVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  uint uStack_48;
  ezb_zcl_poll_control_check_in_message_t message;
  zcl_packet_t rsp;
  
  memset(&message.out,0,0x28);
  if ((arg != (void *)0x0) && ((*(byte *)((int)arg + 0x1a) & 8) != 0)) {
    iVar1 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1);
    if (iVar1 != 0) goto _L0;
    if (*(char *)((int)arg + 0x20) == '\0') {
      uStack_48 = 0;
      message.info.status = '\0';
      message.info.dst_ep = '\0';
      message.info.cluster_id = 0;
      message.info.cluster_role = '\0';
      message.info._5_1_ = 0;
      message._6_2_ = 0;
      message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
      iVar1 = zcl_packet_to_message(&uStack_48,arg);
      if (iVar1 == 0) {
        message.in.header._0_1_ = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x3d,&uStack_48);
        uVar4 = 1;
        if ((((uint)message.in.header & 0xff) != 0xfe) &&
           (uVar4 = 1, ((uint)message.in.header & 0xff) != 0)) goto _L0;
      }
      else {
_L0:
        uVar4 = 0;
      }
      uStack_48 = CONCAT31(uStack_48._1_3_,uVar4);
      iVar1 = zmsg_append_bytes(rsp._32_4_,1,&uStack_48);
      if (iVar1 != 0) {
_L0:
        uVar3 = 0x89;
        goto _L0;
      }
      uStack_48 = uStack_48 & 0xffff0000;
      iVar1 = zmsg_append_bytes(rsp._32_4_,2,&uStack_48);
      if (iVar1 != 0) goto _L0;
      __dest = calloc(1,0x28);
      pvVar2 = calloc(1,0x10);
      memcpy(__dest,arg,0x22);
      *(void **)((int)__dest + 0x24) = pvVar2;
      milli_timer_init(pvVar2,poll_control_cli_stop_fast_poll,__dest);
      milli_timer_start(pvVar2,0);
      iVar1 = zcl_packet_setup_response(&message.out,arg,0);
    }
    else {
      uVar3 = 0x81;
_L0:
      iVar1 = zcl_packet_setup_default_response(&message.out,arg,uVar3);
    }
    if (iVar1 != 0) {
      zcl_packet_free(&message.out);
      goto _L0;
    }
    zcl_packet_send(&message.out,0);
  }
  iVar1 = 0;
_L0:
  return (ezb_zcl_status_t)iVar1;
}

