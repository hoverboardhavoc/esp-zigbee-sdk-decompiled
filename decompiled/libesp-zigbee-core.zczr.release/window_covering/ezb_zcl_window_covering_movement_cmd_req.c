/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> window_covering.o -> ezb_zcl_window_covering_movement_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_window_covering_movement_cmd_req(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_50 [22];
  undefined2 uStack_3a;
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if (param_1 == (void *)0x0) {
    iVar1 = -1;
    goto _L0;
  }
  iVar1 = zcl_packet_init(auStack_38,0);
  if (iVar1 != 0) goto _L0;
  memcpy(auStack_50,param_1,10);
  iVar1 = zcl_cmd_to_packet(auStack_38,0,0,*(undefined1 *)((int)param_1 + 0xc),0,
                            *(undefined1 *)((int)param_1 + 0x18),0x102);
  if (iVar1 != 0) goto _L0;
  uVar3 = *(uint *)((int)param_1 + 0x18);
  uVar2 = 1;
  if (uVar3 == 5) {
_L0:
    uStack_3a = CONCAT11(uStack_3a._1_1_,*(undefined1 *)((int)param_1 + 0x1c));
_L0:
    iVar1 = zmsg_append_bytes(uStack_14,uVar2,&uStack_3a);
    if (iVar1 != 0) goto _L0;
  }
  else {
    if (5 < uVar3) {
      if (uVar3 != 7) {
        if (uVar3 != 8) goto _L114;
        goto _L0;
      }
      uStack_3a = *(undefined2 *)((int)param_1 + 0x1c);
      uVar2 = 2;
      goto _L0;
    }
    uVar2 = 2;
    if (2 < uVar3) {
      if (uVar3 != 4) {
_L114:
        iVar1 = 2;
        goto _L0;
      }
      uStack_3a = *(undefined2 *)((int)param_1 + 0x1c);
      goto _L0;
    }
  }
  zcl_packet_send(auStack_38,(int)param_1 + 0x10);
  iVar1 = zcl_status_to_err();
  if (iVar1 == 0) {
    return 0;
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar1;
}

