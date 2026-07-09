/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> basic.o -> basic_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int basic_cluster_srv_cmd_proc_handler(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [44];
  
  iVar1 = 0xfe;
  memset(auStack_38,0,0x28);
  if (param_1 != 0) {
    iVar1 = 0xfe;
    if (((*(byte *)(param_1 + 0x1a) >> 3 & 1) == 0) &&
       (iVar1 = zcl_packet_init(auStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1), iVar1 == 0)) {
      uVar2 = 0x81;
      if (*(char *)(param_1 + 0x20) == '\0') {
        uStack_48 = 0;
        uStack_44 = 0;
        iStack_40 = 0;
        uStack_3c = 0;
        zcl_packet_to_message(&uStack_48,param_1,0x81);
        uStack_3c = CONCAT31(uStack_3c._1_3_,0xfe);
        iStack_40 = param_1;
        zcl_core_action_schedule(0xc,&uStack_48);
        uVar2 = uStack_3c & 0xff;
        if (uVar2 == 0xfe) {
          uVar2 = 0;
        }
      }
      iVar1 = zcl_packet_setup_default_response(auStack_38,param_1,uVar2);
      if (iVar1 == 0) {
        zcl_packet_send(auStack_38,0);
      }
      else {
        zcl_packet_free(auStack_38);
      }
    }
  }
  return iVar1;
}

