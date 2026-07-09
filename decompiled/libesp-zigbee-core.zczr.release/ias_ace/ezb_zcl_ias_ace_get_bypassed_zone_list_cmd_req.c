/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ezb_zcl_ias_ace_get_bypassed_zone_list_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_ias_ace_get_bypassed_zone_list_cmd_req(void *param_1)

{
  int iVar1;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [40];
  
  memset(auStack_38,0,0x28);
  if (param_1 == (void *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_38,0);
    if (iVar1 == 0) {
      memcpy(auStack_50,param_1,10);
      iVar1 = zcl_cmd_to_packet(auStack_38,0,0,*(undefined1 *)((int)param_1 + 0xc),0,8,0x501);
      if (iVar1 == 0) {
        zcl_packet_send(auStack_38,(int)param_1 + 0x10);
        iVar1 = zcl_status_to_err();
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}

