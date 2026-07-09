/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ezb_zcl_ias_ace_bypass_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_ias_ace_bypass_cmd_req(int param_1)

{
  int iVar1;
  char cStack_39;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_38,0);
    if ((iVar1 == 0) &&
       (iVar1 = zcl_cmd_to_packet(&uStack_38,0,0,*(undefined1 *)(param_1 + 0xc),0,1,0x501),
       iVar1 == 0)) {
      if (*(char *)(param_1 + 0x18) == '\0') {
        iVar1 = 2;
      }
      else if (*(byte *)(param_1 + 0x20) < 9) {
        cStack_39 = *(char *)(param_1 + 0x18);
        iVar1 = zmsg_append_bytes(uStack_14,1,&cStack_39);
        if (((iVar1 == 0) &&
            (iVar1 = zmsg_append_bytes(uStack_14,*(undefined1 *)(param_1 + 0x18),
                                       *(undefined4 *)(param_1 + 0x1c)), iVar1 == 0)) &&
           (iVar1 = zmsg_append_bytes(uStack_14,*(byte *)(param_1 + 0x20) + 1,param_1 + 0x20),
           iVar1 == 0)) {
          zcl_packet_send(&uStack_38,param_1 + 0x10);
          iVar1 = zcl_status_to_err();
          if (iVar1 == 0) {
            return 0;
          }
        }
      }
      else {
        iVar1 = 2;
      }
    }
  }
  zcl_packet_free(&uStack_38);
  return iVar1;
}

