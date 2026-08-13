/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int poll_control_cluster_cli_cmd_proc_handler(void *param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  void *__dest;
  void *pvVar5;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if (param_1 == (void *)0x0) {
    return 0;
  }
  if ((*(byte *)((int)param_1 + 0x1a) & 8) == 0) {
    return 0;
  }
  iVar3 = zcl_packet_init(auStack_48,*(byte *)((int)param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (*(char *)((int)param_1 + 0x20) == '\0') {
    uStack_58 = 0;
    uStack_54 = 0;
    pvStack_50 = (void *)0x0;
    uStack_4c = 0;
    uVar4 = zcl_packet_to_message(&uStack_58,param_1);
    if (uVar4 == 0) {
      uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
      pvStack_50 = param_1;
      zcl_core_action_schedule(0x3e,&uStack_58,0);
      uVar4 = uStack_4c & 0xff;
      if ((uVar4 == 0xfe) || (uVar4 == 0)) {
        cVar1 = uStack_4c._1_1_;
        uVar2 = uStack_4c._2_2_;
        uVar4 = (uint)uStack_4c._2_2_;
        uStack_58 = CONCAT31(uStack_58._1_3_,uStack_4c._1_1_);
        iVar3 = zmsg_append_bytes(uStack_24,1,&uStack_58);
        if (iVar3 == 0) {
          uStack_58 = CONCAT22(uStack_58._2_2_,uVar2);
          iVar3 = zmsg_append_bytes(uStack_24,2,&uStack_58);
          if (iVar3 == 0) {
            if ((cVar1 != '\0') && (uVar4 != 0)) {
              __dest = calloc(1,0x28);
              pvVar5 = calloc(1,0x10);
              memcpy(__dest,param_1,0x22);
              *(void **)((int)__dest + 0x24) = pvVar5;
              milli_timer_init(pvVar5,poll_control_cli_stop_fast_poll,__dest);
              milli_timer_start(pvVar5,uVar4 * 0xfa);
            }
            iVar3 = zcl_packet_setup_response(auStack_48,param_1,0);
            goto _L0;
          }
        }
        uVar4 = 0x89;
      }
    }
  }
  else {
    uVar4 = 0x81;
  }
  iVar3 = zcl_packet_setup_default_response(auStack_48,param_1,uVar4);
_L0:
  if (iVar3 == 0) {
    zcl_packet_send(auStack_48,0);
    return 0;
  }
  zcl_packet_free(auStack_48);
  return iVar3;
}

