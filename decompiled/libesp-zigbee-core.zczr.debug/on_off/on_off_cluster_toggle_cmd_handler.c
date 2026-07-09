/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_toggle_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_cluster_toggle_cmd_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  short *psVar3;
  char *pcVar4;
  short sVar5;
  
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x176,
                  "on_off_cluster_toggle_cmd_handler","packet && rsp");
  }
  else {
    iVar2 = on_off_srv_get_attr_desc(uVar1,0);
    if (iVar2 != 0) {
      on_off_process_transition(uVar1,**(char **)(iVar2 + 8) == '\0',0,0);
      zcl_packet_setup_default_response(param_2,param_1,0);
      return;
    }
  }
  pcVar4 = "on_off_cluster_toggle_cmd_handler";
  psVar3 = (short *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c"
                                  ,0x178,"on_off_cluster_toggle_cmd_handler","attr_desc");
  iVar2 = zmsg_read_bytes(*psVar3,1,pcVar4);
  if (iVar2 == 0) {
    sVar5 = -1;
  }
  else {
    sVar5 = *psVar3 + (short)iVar2;
  }
  *psVar3 = sVar5;
  return;
}

