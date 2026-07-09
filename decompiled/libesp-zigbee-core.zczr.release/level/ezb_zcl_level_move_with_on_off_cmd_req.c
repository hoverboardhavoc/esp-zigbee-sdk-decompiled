/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> ezb_zcl_level_move_with_on_off_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_level_move_with_on_off_cmd_req(void *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if (param_1 == (void *)0x0) {
    iVar2 = 2;
  }
  else {
    iVar2 = zcl_packet_init(auStack_38,0);
    if (iVar2 == 0) {
      uVar1 = *(undefined1 *)((int)param_1 + 0xc);
      memcpy(auStack_50,param_1,10);
      iVar2 = zcl_cmd_to_packet(auStack_38,0,0,uVar1,0,5,8);
      if ((((iVar2 == 0) &&
           (iVar2 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x18)), iVar2 == 0)) &&
          (iVar2 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x19)), iVar2 == 0)) &&
         ((iVar2 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x1a)), iVar2 == 0 &&
          (iVar2 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x1b)), iVar2 == 0)))) {
        zcl_packet_send(auStack_38,(int)param_1 + 0x10);
        iVar2 = zcl_status_to_err();
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
    else {
      iVar2 = -1;
    }
  }
  zcl_packet_free(auStack_38);
  return iVar2;
}

