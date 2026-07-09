/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int poll_control_cluster_cli_cmd_proc_handler(void *param_1)

{
  int iVar1;
  void *__dest;
  void *pvVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  uint auStack_48 [2];
  void *pvStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if (param_1 == (void *)0x0) {
    return 0;
  }
  if ((*(byte *)((int)param_1 + 0x1a) & 8) == 0) {
    return 0;
  }
  iVar1 = zcl_packet_init(auStack_38,*(byte *)((int)param_1 + 0x1a) >> 2 & 1);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(char *)((int)param_1 + 0x20) == '\0') {
    auStack_48[0] = 0;
    auStack_48[1] = 0;
    pvStack_40 = (void *)0x0;
    uStack_3c = 0;
    iVar1 = zcl_packet_to_message(auStack_48,param_1);
    if (iVar1 == 0) {
      uStack_3c = CONCAT31(uStack_3c._1_3_,0xfe);
      pvStack_40 = param_1;
      zcl_core_action_schedule(0x3e,auStack_48);
      uVar4 = 1;
      if (((uStack_3c & 0xff) != 0xfe) && (uVar4 = 1, (uStack_3c & 0xff) != 0)) goto _L0;
    }
    else {
_L0:
      uVar4 = 0;
    }
    auStack_48[0] = CONCAT31(auStack_48[0]._1_3_,uVar4);
    iVar1 = zmsg_append_bytes(uStack_14,1,auStack_48);
    if (iVar1 == 0) {
      auStack_48[0] = auStack_48[0] & 0xffff0000;
      iVar1 = zmsg_append_bytes(uStack_14,2,auStack_48);
      if (iVar1 == 0) {
        __dest = calloc(1,0x28);
        pvVar2 = calloc(1,0x10);
        memcpy(__dest,param_1,0x22);
        *(void **)((int)__dest + 0x24) = pvVar2;
        milli_timer_init(pvVar2,poll_control_cli_stop_fast_poll,__dest);
        milli_timer_start(pvVar2,0);
        iVar1 = zcl_packet_setup_response(auStack_38,param_1,0);
        goto _L0;
      }
    }
    uVar3 = 0x89;
  }
  else {
    uVar3 = 0x81;
  }
  iVar1 = zcl_packet_setup_default_response(auStack_38,param_1,uVar3);
_L0:
  if (iVar1 == 0) {
    zcl_packet_send(auStack_38,0);
    return 0;
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}

